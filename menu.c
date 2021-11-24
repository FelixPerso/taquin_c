#include <stdio.h>
#include <stdlib.h>
#include <graph.h>

int main(int argc, char const *argv[]) {
  InitialiserGraphique();
  CreerFenetre(10,10,1600,900);
  EcrireTexte(800,30,"Taquin",2);
  ChargerImage("catmeme.xpm",10,200,0,0,585,577);
  Touche();
  FermerGraphique();
  return EXIT_SUCCESS;
}
