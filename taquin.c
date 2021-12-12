#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <graph.h>

int AffichageG(int li_max, int col_max, char* nom_image, int bx, int by) {
  const int departx=100, departy=200;
  int hauteur_fenetre=200+by+departy;
  int largeur_fenetre=20+2*bx+3*departx;
  int hauteur_case=by/li_max;
  int largeur_case=bx/col_max;
  
  //creation fenetre et affichage du fond
  InitialiserGraphique();
  CreerFenetre(10,10,largeur_fenetre,hauteur_fenetre);
  ChargerImageFond("taquin_page_fond.xpm");
  
  //affichage du nombre de coups
  ChargerImage(nom_image,departx,departy,0,0,bx,by);
  ChoisirCouleurDessin(CouleurParNom("black"));
  EcrireTexte(largeur_fenetre/2,hauteur_fenetre-30,"Nombre de coups : 0 ",2);
  
  //case que l'on retire
  CopierZone(0,0,departx,departy,largeur_case,hauteur_case,departx,departy-hauteur_case-20);
  ChoisirCouleurDessin(CouleurParNom("white"));
  RemplirRectangle(departx,departy,largeur_case,hauteur_case);


  //tracer les colonnes
  DessinerSegment(departx, departy, departx, departy+by);
  for(int i=0 ; i < col_max ; i++){
      DessinerSegment(departx+(i+1)*largeur_case, departy, departx+(i+1)*largeur_case, departy+by);
  }
  //tracer les lignes
  DessinerSegment(departx, departy, departx+bx, departy);
  for(int i=0 ; i < li_max ; i++){
      DessinerSegment(departx, departy+(i+1)*hauteur_case, departx+bx, departy+(i+1)*hauteur_case);
  }

  return 0;
}
