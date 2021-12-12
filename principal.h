#ifndef _PRINCIPAL_H
#define _PRINCIPAL_H


void Haut(int li_max);
//fonction pour decaler la tuile vers le haut

void Bas(int li_max);
//fonction pour decaler la tuile vers le bas

void Gauche(int col_max);
//fonction pour decaler la tuile vers la gauche


void Droite(int col_max);
//fonction pour decaler la tuile vers la droite

void RaffraichissementG(int li_max, int col_max, int bx, int by);
//fonction qui actualise le taquin a chaque coups et dessine les segments

void Initialiser(int li_max, int col_max);
//initialisation du taquin avec le melange

#endif
