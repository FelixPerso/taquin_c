#ifndef _MENUS_H
#define _MENUS_H

char* menu1(void);
//affichage et choix de l'image pour jouer

int menu2(void);
//affichage et choix du nombre de lignes et colonnes

int menu3(void);
//affichage ecran victoire avec les boutons menus et quitter

int dimensionbx(char* nom_image);
//recuperation de la dimension bx de l'image choisie

int dimensionby(char* nom_image);
//recuperation de la dimension by de l'image choisie

#endif