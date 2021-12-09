#include<graph.h>
#include<stdio.h>

int main(int argc, char const *argv[]) {
  InitialiserGraphique();
	CreerFenetre(10,10,1600,900);
  //AFFICHER IMAGE SETTINGS
	ChargerImage("taquin_page_settings.xpm",0,0,0,0,1600,900);
  int stop = 1; //VARIABLE STOP DE LA PAGE//
  int decoupagex;//LIGNE TAQUIN//
  int decoupagey;//COLONNE TAQUIN//
  int i;
  int i2;
  int bx=381;
  int by=375;
  int posx=400;
  int posy=100;
  int tab[decoupagex-1][decoupagey-1];
  int valtab=0;
  while(stop) {
		if(SourisCliquee())
		{
			SourisPosition();
      //LIGNE//
			if((_X>=530 && _X<=600)&&(_Y>=430 && _Y<=470)) {
				  decoupagex=3;
      }
      if((_X>=620 && _X<=690)&&(_Y>=430 && _Y<=470)) {
				  decoupagex=4;
      }
      if((_X>=710 && _X<=780)&&(_Y>=430 && _Y<=470)) {
				  decoupagex=5;
      }
      if((_X>=800 && _X<=870)&&(_Y>=430 && _Y<=470)) {
				  decoupagex=6;
      }
      if((_X>=890 && _X<=960)&&(_Y>=430 && _Y<=470)) {
				  decoupagex=7;
      }
      if((_X>=980 && _X<=1050)&&(_Y>=430 && _Y<=470)) {
				  decoupagex=8;
      }
      //COLONNE//
      if((_X>=530 && _X<=600)&&(_Y>=630 && _Y<=700)) {
				  decoupagey=3;
      }
      if((_X>=620 && _X<=690)&&(_Y>=630 && _Y<=700)) {
				  decoupagey=4;
      }
      if((_X>=710 && _X<=780)&&(_Y>=630 && _Y<=700)) {
				  decoupagey=5;
      }
      if((_X>=800 && _X<=870)&&(_Y>=630 && _Y<=700)) {
				  decoupagey=6;
      }
      if((_X>=890 && _X<=960)&&(_Y>=630 && _Y<=700)) {
				  decoupagey=7;
      }
      if((_X>=980 && _X<=1050)&&(_Y>=630 && _Y<=700)) {
				  decoupagey=8;
      }
      //ARRETER LE PROGRAMME//
      if((_X>=1422 && _X<=1600)&&(_Y>=0 && _Y<=50)) {
          stop=0;
        }

}
for(i2=0;i2<decoupagey;i2++) {
  for(i=0;i<decoupagex;i++) {
    //ChargerImage("bob.xpm",posx+bx/decoupagex*i2,posy+by/decoupagey*i,0+bx/decoupagex*i2,0+by/decoupagey*i,(bx-10)/decoupagex,(by-10)/decoupagey);//
    ChargerImage("bob.xpm",posx+bx/decoupagex*i+2,posy+by/decoupagey*i2+2,bx/decoupagex*i,by/decoupagey*i2,bx/decoupagex-4,by/decoupagey-4);
    tab[i][i2]=valtab+1;
  }
}
}
}
