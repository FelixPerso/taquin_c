#include <stdio.h>
#include <stdlib.h>
#include <graph.h>


void alderiate(int var){
ChargerImage("alderiate.xpm",100,150,0,0,900,500);
ChargerImage("alderiate.xpm",900,150,0,0,900,1200);
}
void cat(int var){
ChargerImage("catmeme.xpm",100,150,0,0,585,577);
ChargerImage("catmeme.xpm",900,150,0,0,585,577);
}

int main(void){
  int var ;
  InitialiserGraphique();
  CreerFenetre(10,10,1600,900);
  EcrireTexte(800,30,"Taquin",2);
  alderiate(var);
  Touche();
  FermerGraphique();
}
