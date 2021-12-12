#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <graph.h>
#include "menus.h"
#include "taquin.h"

//Desole des variables globales :(
int li_trou=0;
int col_trou=0;
int nb_coups=0;
int taquin[8][8];

void Haut(int li_max){
    if (li_trou<li_max-1)
        {
            taquin[li_trou][col_trou]=taquin[li_trou+1][col_trou];
            taquin[li_trou+1][col_trou]=0;
            li_trou++;
            nb_coups++;
        }
}

void Bas(int li_max){
    if (li_trou>0)
        {
            taquin[li_trou][col_trou]=taquin[li_trou-1][col_trou];
            taquin[li_trou-1][col_trou]=0;
            li_trou--;
            nb_coups++;
        }
}

void Gauche(int col_max){
    if (col_trou<col_max-1)
        {
            taquin[li_trou][col_trou]=taquin[li_trou][col_trou+1];
            taquin[li_trou][col_trou+1]=0;
            col_trou++;
            nb_coups++;
        }
}

void Droite(int col_max){
    if (col_trou>0)
        {
            taquin[li_trou][col_trou]=taquin[li_trou][col_trou-1];
            taquin[li_trou][col_trou-1]=0;
            col_trou--;
            nb_coups++;
        }
}

//actualisation nombre de coup et de l'affichage du taquin
void RaffraichissementG(int li_max, int col_max, int bx, int by){
  const int departx=100, departy=200;
  int hauteur_fenetre=200+by+departy;
  int largeur_fenetre=20+2*bx+3*departx;
  int hauteur_case=by/li_max;
  int largeur_case=bx/col_max;

  int x,y;
  char temp[50];
  int temporaire;
  int continuer=1;
  long suivant;
  int i_candidat, j_candidat;
  
  //Raffraichissement nb de coups
  ChoisirCouleurDessin(CouleurParNom("white"));
  RemplirRectangle(0,hauteur_fenetre-40,largeur_fenetre,40);
  ChoisirCouleurDessin(CouleurParNom("black"));
  sprintf(temp,"nombre de coups : %3d",nb_coups);
  EcrireTexte(largeur_fenetre/2,hauteur_fenetre-30,temp,2);
  ChoisirCouleurDessin(CouleurParNom("white"));
  
  //decoupage taquin
  RemplirRectangle(2*departx+bx-1, departy-1,bx+2,by+2);
  for(int i=0 ; i < li_max ; i++){
      for(int j=0; j < col_max ; j++){
          if (taquin[i][j]!=0){
            CopierZone(0,0,departx+taquin[i][j]%col_max*largeur_case,departy+taquin[i][j]/col_max*hauteur_case,largeur_case,hauteur_case,bx+2*departx+j*largeur_case,departy+i*hauteur_case);
          }
          
      }
  }
  //tracer les colonnes
  DessinerSegment(2*departx+bx, departy, 2*departx+bx, departy+by);
  for(int i=0 ; i < col_max ; i++){
      DessinerSegment(2*departx+(i+1)*largeur_case+bx, departy, 2*departx+(i+1)*largeur_case+bx, departy+by);
  }
  //tracer les lignes
  DessinerSegment(2*departx+bx, departy, 2*departx+2*bx, departy);
  for(int i=0 ; i < li_max ; i++){
      DessinerSegment(2*departx+bx, departy+(i+1)*hauteur_case, 2*departx+2*bx, departy+(i+1)*hauteur_case);
  }
    /*TENTATIVE DE FAIRE FONCTIONNER CLAVIER MAIS ECHEC
    suivant=Microsecondes()+CYCLE;
    while(continuer==1){
        if(Microsecondes()>suivant){
            x=0;
            y=0;
            while(!(SourisCliquee()) || ToucheEnAttente()==0){

                /*if(ToucheEnAttente()==1){
                    //gestion touche clavier
                    temporaire=Touche();
                    if(temporaire==XK_Up){
                        Haut(li_max);
                        continuer=0;
                    }
                    else if(temporaire==XK_Down){
                        Bas(li_max);
                        continuer=0;
                    }
                    else if(temporaire==XK_Left){
                        Gauche(col_max);
                        continuer=0;
                    }
                    else if(temporaire==XK_Right){
                        Droite(col_max);
                        continuer=0;
                    }
                }
                else{
                    SourisPosition();
                    if((_X>2*departx+bx) && (_X<2*departx+2*bx) && (_Y>departy) && (_Y<departy+by)){           
                        i_candidat=(y-departy)/hauteur_case;
                        j_candidat=(x-2*departx-bx)/largeur_case;
                        
                        //On detecte si la case est a cote de la blanche
                        if (i_candidat==li_trou+1 && j_candidat==col_trou)
                                Haut(li_max);
                            else if (i_candidat==li_trou && j_candidat==col_trou+1)
                                Gauche(col_max);
                            else if (i_candidat==li_trou && j_candidat==col_trou-1)
                                Droite(col_max);
                            else if (i_candidat==li_trou-1 && j_candidat==col_trou)
                                Bas(li_max);
                        continuer=0;               
                    }

                }
            }
        suivant=Microsecondes()+CYCLE;
        }
    }*/

    //attente clic correct de la souris et detection du i et j pour les cases
    x=0;
    y=0;

    while(!((x>2*departx+bx) && (x<2*departx+2*bx) && (y>departy) && (y<departy+by))){
        while(!SourisCliquee())
            {
                SourisPosition();
                if (_X!=x||_Y!=y){
                    x=_X;
                    y=_Y;
                } 
            }
    }
    
 
  i_candidat=(y-departy)/hauteur_case;
  j_candidat=(x-2*departx-bx)/largeur_case;
  
  //On detecte si la case est a cote de la blanche
  if (i_candidat==li_trou+1 && j_candidat==col_trou)
        Haut(li_max);
    else if (i_candidat==li_trou && j_candidat==col_trou+1)
        Gauche(col_max);
    else if (i_candidat==li_trou && j_candidat==col_trou-1)
        Droite(col_max);
    else if (i_candidat==li_trou-1 && j_candidat==col_trou)
        Bas(li_max);
}

void Initialiser(int li_max, int col_max){
    int j=0;

    for(int i=0 ; i<li_max;i++){
        for(int j=0 ; j <col_max ; j++){
          taquin[i][j]=col_max*i+j;
        }
  }
  
  srand(time(NULL));

    for(int i=0 ; i<2*li_max*li_max*col_max*col_max;i++){
    //for(int i=0 ; i<1 ; i++){ pour tester l'ecran de victoire sans passer par faire tout le taquin en entier(1 coup ou 0) il faut la decommenter et recommenter celle au dessus
        j=rand()%4;
        if (j==0)
            Haut(li_max);
        else if (j==1)
            Bas(li_max);
        else if (j==2)
            Droite(col_max);
        else
            Gauche(col_max);
  }
  nb_coups=0;
}

//Test de victoire pour savoir si le taquin est resolu ou non
int Test_Victoire(int li_max, int col_max){
    int temp=1;
    
    for(int i=0 ; i<li_max;i++){
        for(int j=0 ; j <col_max ; j++){
            if (taquin[i][j]!=li_max*i+j)
                temp=0;
        }
    }
    return temp;
}

int main(void){
  int quitter=0;
  int li_max =0, col_max=0;
  int temp=0;
  char* nom_image;
  int bx, by;

  while (quitter==0){    
    nom_image=menu1();
    bx=dimensionbx(nom_image);
    by=dimensionby(nom_image);

    temp=menu2();
    li_max=temp/9;
    col_max=temp%9;
    
    //resize de l'image
    int bx2=bx/col_max;
    bx=bx2*col_max;
    int by2=by/li_max;
    by=by2*li_max;

    Initialiser(li_max, col_max); 
    AffichageG(li_max, col_max, nom_image,bx, by);

    //boucle principale
    while(Test_Victoire(li_max, col_max)==0)
    {
     RaffraichissementG(li_max, col_max, bx, by);
    }
    FermerGraphique();
    quitter=menu3();
    
  }
  return 0;
}