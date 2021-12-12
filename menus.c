#include <stdio.h>
#include <stdlib.h>
#include <graph.h>

char* menu1(void) {
  int x=0;
  int y=0;
  char* nom_image;
  InitialiserGraphique();
  CreerFenetre(10,10,1600,900);
  ChargerImage("taquin_menu_.xpm",10,10,0,0,1600,900);

  //detection souris et choix image
    while(!((y>309) && (y<675) && ((x>109 && x<465) || (x>624 && x<980) || (x>1129 && x<1485) ))){
        while(!SourisCliquee())
            {
                SourisPosition();
                if (_X!=x||_Y!=y){
                    x=_X;
                    y=_Y;
                } 
            }
    }
    FermerGraphique();
    if(x<465){
        nom_image="catmeme.xpm";
        return nom_image;
      }
    else if(x>1129){
        nom_image="dogmeme.xpm";
        return nom_image;
      }
    else{
        nom_image="bob.xpm";
        return nom_image;
      }

}

int menu2(void){
  int x=0;
  int y=0;
  int li_max=0;
  int col_max=0;
  
  InitialiserGraphique();
  CreerFenetre(10,10,1600,900);
  ChargerImage("taquin_page_settings.xpm",10,10,0,0,1600,900);

    while(li_max==0 || col_max==0){

        //enregistrement des lignes et colonnes avec la souris
        while(!(((y>400 && y<470) || (y>639 && y<705)) && (x>530 && x<600) || (x>620 && x<690) || (x>710 && x<780) || (x>800 && x<870) || (x>890 && x<960) || (x>980 && x< 1050))){
            while(!SourisCliquee()){
        
                SourisPosition();
                if (_X!=x||_Y!=y){
                    x=_X;
                    y=_Y;
                } 
            }
        }
        
	//On détermine si c'est le nombre de lignes ou de colonnes qui est choisi
        if(y<520)
            li_max=(x-530)/90+3; 
        else
            col_max=(x-530)/90+3;    
       x=0;
       y=0; 
    }
    FermerGraphique();
    return 9*li_max+col_max;
    
    
}
int menu3(void){
  int x=0;
  int y=100;
  InitialiserGraphique();
  CreerFenetre(10,10,1600,900);
  ChargerImage("taquin_page_victoire.xpm",10,10,0,0,1600,900);
   while(!((x<177 || x>1415)&& y<60)){
        while(!SourisCliquee()){
    
            SourisPosition();
            if (_X!=x||_Y!=y){
                x=_X;
                y=_Y;
            } 
        }
    }
    FermerGraphique();
        if(x<177){
            return 0;
        }
        else if(x>1415){
            return 1;
        }
}

int dimensionbx(char* nom_image){
    
    if(nom_image=="catmeme.xpm"){
        return 585;
    }
    else if(nom_image=="dogmeme.xpm"){
        return 403;
    }
    else{
        return 381;
    }
}
int dimensionby(char* nom_image){
    
    if(nom_image=="catmeme.xpm"){
        return 577;
    }
    else if(nom_image=="dogmeme.xpm"){
        return 430;
    }
    else{
        return 377;
    }
}

