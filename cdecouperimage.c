#include <stdio.h>
#include <stdlib.h>
#include <graph.h>

int main(int argc, char const *argv[]) {
  InitialiserGraphique();
  CreerFenetre(10,10,1600,900);
  EcrireTexte(800,30,"Taquin",2);
  int i;
  int i2;
  int bx=585;
  int by=577;
  int decoupagex=3;
  int decoupagey=3;
  int posx=100;
  int posy=100;
  int tab[decoupagex-1][decoupagey-1];
  int valtab=0;
  for(i=0;i<decoupagey;i++){
    for(i2=0;i2<decoupagex;i2++){
      ChargerImage("catmeme.xpm",posx+bx/decoupagex*i2,posy+by/decoupagey*i,0+bx/decoupagex*i2,0+by/decoupagey*i,(bx-10)/decoupagex,(by-10)/decoupagey);
      tab[i][i2]=valtab+1;
    }
  }
  Touche(XK_Escape);
  FermerGraphique();
  return 0;
}
