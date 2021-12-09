#include <stdio.h>
#include <stdlib.h>
#include <graph.h>

int adecouper(void) {
  InitialiserGraphique();
  int i;
  int i2;
  int bx=675;
  int by=900;
  int decoupagex=3;
  int decoupagey=3;
  int posx=10;
  int posy=10;
  int tab[decoupagex-1][decoupagey-1];
  int valtab=0;
  for(i=0;i<decoupagey;i++){
    for(i2=0;i2<decoupagex;i2++){
      ChargerImage("alderiate.xpm",posx+bx/decoupagex*i2,posy+by/decoupagey*i,0+bx/decoupagex*i2,0+by/decoupagey*i,(bx-10)/decoupagex,(by-10)/decoupagey);
      tab[i][i2]=valtab+1;
    }
  }
}
