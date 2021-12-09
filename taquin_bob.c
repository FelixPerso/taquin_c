#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <graph.h>



int li_trou=0;
int col_trou=0;
int nb_coups=0;
int li_max =0;
int col_max=0;
int taquin[8][8];

int bx=281;
int by=377;
char* nom_image="bob.xpm";

int Affichage(){
    for(int i=0 ; i < li_max ; i++){
      for(int j=0; j < col_max ; j++){
          printf("%3d",taquin[i][j]);
      }
      printf("\n");
    }
    return EXIT_SUCCESS;
}

int AffichageG(int bx, int by, char* nom_image) {
  const int departx=100, departy=200;
  int hauteur_fenetre=200+by+departy;
  int largeur_fenetre=20+2*bx+3*departx;
  int hauteur_case=by/li_max;
  int largeur_case=bx/col_max;

  int x,y;
  char temp[50];
  int i_candidat, j_candidat;



  InitialiserGraphique();
  CreerFenetre(10,10,largeur_fenetre,hauteur_fenetre);
  EcrireTexte(largeur_fenetre/2,30,"Taquin",2);
  sprintf(temp,"nombre de coups : %3d",nb_coups);
  EcrireTexte(largeur_fenetre/2,hauteur_fenetre-30,temp,2);


  ChargerImage(nom_image,departx,departy,0,0,bx,by);
  for(int i=0 ; i < li_max ; i++){
      for(int j=0; j < col_max ; j++){
          if (taquin[i][j]!=0){
            CopierZone(0,0,departx+taquin[i][j]%col_max*largeur_case,departy+taquin[i][j]/col_max*hauteur_case,largeur_case,hauteur_case,bx+2*departx+j*largeur_case,departy+i*hauteur_case);
          }

      }
  }

  //case que l'on retire
  CopierZone(0,0,departx,departy,largeur_case,hauteur_case,departx,departy-hauteur_case-20);
  ChoisirCouleurDessin(CouleurParNom("white"));
  RemplirRectangle(departx,departy,largeur_case,hauteur_case);


  //tracer les colonnes
  DessinerSegment(departx, departy, departx, departy+by);
  DessinerSegment(2*departx+bx, departy, 2*departx+bx, departy+by);
  for(int i=0 ; i < col_max ; i++){
      DessinerSegment(departx+(i+1)*largeur_case, departy, departx+(i+1)*largeur_case, departy+by);
      DessinerSegment(2*departx+(i+1)*largeur_case+bx, departy, 2*departx+(i+1)*largeur_case+bx, departy+by);
  }
  //tracer les lignes
  DessinerSegment(departx, departy, departx+bx, departy);
  DessinerSegment(2*departx+bx, departy, 2*departx+2*bx, departy);
  for(int i=0 ; i < li_max ; i++){
      DessinerSegment(departx, departy+(i+1)*hauteur_case, departx+bx, departy+(i+1)*hauteur_case);
      DessinerSegment(2*departx+bx, departy+(i+1)*hauteur_case, 2*departx+2*bx, departy+(i+1)*hauteur_case);
  }

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

  //Souris
  //On detecte si la case est a cote de la blanche
  if (i_candidat==li_trou+1 && j_candidat==col_trou)
        Haut();
    else if (i_candidat==li_trou && j_candidat==col_trou+1)
        Gauche();
    else if (i_candidat==li_trou && j_candidat==col_trou-1)
        Droite();
    else if (i_candidat==li_trou-1 && j_candidat==col_trou)
        Bas();

  //Touche(XK_Escape);
  FermerGraphique();
  return 0;
}

void Haut(void){
    if (li_trou<li_max-1)
        {
            taquin[li_trou][col_trou]=taquin[li_trou+1][col_trou];
            taquin[li_trou+1][col_trou]=0;
            li_trou++;
            nb_coups++;
        }
}

void Bas(void){
    if (li_trou>0)
        {
            taquin[li_trou][col_trou]=taquin[li_trou-1][col_trou];
            taquin[li_trou-1][col_trou]=0;
            li_trou--;
            nb_coups++;
        }
}

void Gauche(void){
    if (col_trou<col_max-1)
        {
            taquin[li_trou][col_trou]=taquin[li_trou][col_trou+1];
            taquin[li_trou][col_trou+1]=0;
            col_trou++;
            nb_coups++;
        }
}

void Droite(void){
    if (col_trou>0)
        {
            taquin[li_trou][col_trou]=taquin[li_trou][col_trou-1];
            taquin[li_trou][col_trou-1]=0;
            col_trou--;
            nb_coups++;
        }
}

int Test_Victoire(void){
    int temp=1;

    for(int i=0 ; i<li_max;i++){
        for(int j=0 ; j <col_max ; j++){
            if (taquin[i][j]!=li_max*i+j)
                temp=0;
        }
    }
    return temp;
}


void Initialiser(void){
    for(int i=0 ; i<li_max;i++){
        for(int j=0 ; j <col_max ; j++){
          taquin[i][j]=col_max*i+j;
        }
  }

  srand(time(NULL));

  int j;
  for(int i=0 ; i<2*li_max*li_max*col_max*col_max;i++){
        j=rand()%4;
        if (j==0)
            Haut();
        else if (j==1)
            Bas();
        else if (j==2)
            Droite();
        else
            Gauche();
  }
  nb_coups=0;
  AffichageG(bx,by,nom_image);
}




int main(void){
    char coup;



    system("clear");
    //choisir lignes et colonnes
    while((li_max<3)||(li_max>8))
        {
            printf("Choisissez le nombre de lignes : 3 à 8\n");
            scanf("%d",&li_max);
            printf("\n");
        }

    while((col_max<3)||(col_max>8))
        {
            printf("Choisissez le nombre de colonnes : 3 à 8\n");
            scanf("%d",&col_max);
            printf("\n");
        }


    //resize de l'image
    int bx2=bx/col_max;
    bx=bx2*col_max;
    int by2=by/li_max;
    by=by2*li_max;

    Initialiser();

    //boucle principale
    while(Test_Victoire()==0)
    {
            AffichageG(bx,by,nom_image);

           /* printf("Choisissez votre coup : z - q - s - d\n");
            scanf("%c",&coup);
            if (coup=='z')
                Haut();
            else if (coup=='q')
                Gauche();
            else if (coup=='d')
                Droite();
            else if (coup=='s')
                Bas();*/
        }
    printf("\nLe taquin est gagné");
    return 0;
}
