#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int li_trou=0;
int col_trou=0;
int nb_coups=0;
int li_max =0;
int col_max=0;
int taquin[8][8];

void Affichage(void){
    system("clear");
    for(int i=0 ; i<li_max;i++){
        for(int j=0 ; j <col_max ; j++){
            printf("%3d",taquin[i][j]);

        }
        printf("\n");
    }
    printf("\nNombre de coups : %d\n", nb_coups);
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
    int j;
    for(int i=0 ; i<li_max;i++){
        for(int j=0 ; j <col_max ; j++){
          taquin[i][j]=li_max*i+j;
        }
  }

  srand(time(NULL));


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
  Affichage();
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
            Affichage();
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
