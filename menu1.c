#include<graph.h>
#include<stdio.h>

int main(int argc, char const *argv[]) {
	InitialiserGraphique();
	CreerFenetre(10,10,1600,900);
	ChargerImage("taquin_menu2.xpm",0,0,0,0,1600,900);
	int stop = 1;
  while(stop){
		if(SourisCliquee())
		{
			SourisPosition();
			if((_X>=1423 && _X<=1600)&&(_Y>=0 && _Y<=48)) {
          stop=0;
        }
			if((_X>=113 && _X<=459)&&(_Y>=315 && _Y<=660)) {
				  ChargerImage("catmeme.xpm",100,100,0,0,585,577);//Ouverture premier niveau
		}
		if((_X>=633 && _X<=974)&&(_Y>=315 && _Y<=660)) {
				ChargerImage("bob.xpm",100,100,0,0,381,377);//Ouverture deuxième niveau
	}
	if((_X>=1131 && _X<=1475)&&(_Y>=315 && _Y<=660)) {
			ChargerImage("dogmeme.xpm",100,100,0,0,403,430);//Ouverture troisième niveau
}
	}
}
	FermerGraphique();
}
