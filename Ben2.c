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

int bx=381;
int by=377;
char* nom_image="bob.xpm";


int AffichageG(int bx, int by, char* nom_image) {
  InitialiserGraphique();
  CreerFenetre(10,10,1600,900);
  EcrireTexte(800,30,"Taquin",2);
  ChargerImage(nom_image,100,400,0,0,bx,by);
  for(int i=0 ; i < li_max ; i++){
      for(int j=0; j < col_max ; j++){
          if (taquin[i][j]!=0){
            CopierZone(0,0,100+taquin[i][j]%3*bx/col_max,400+taquin[i][j]/3*by/li_max,bx/col_max,by/li_max,bx+200+j*bx/col_max,400+i*by/li_max);
          }
          
      }
  }
  Touche(XK_Escape);
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
          taquin[i][j]=li_max*i+j;
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
    
    Initialiser();
    
    while(Test_Victoire()==0)
        {
            AffichageG(bx,by,nom_image);
            printf("Choisissez votre coup : z - q - s - d\n");
            scanf("%c",&coup);
            if (coup=='z')
                Haut();
            else if (coup=='q')
                Gauche();
            else if (coup=='d')
                Droite();
            else if (coup=='s')
                Bas();
        }
    printf("\nLe taquin est gagné");
    return 0;
}