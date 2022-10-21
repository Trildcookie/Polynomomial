#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "polynome.h"


int main(void){
  
  srand(time(NULL));

  //Création et affichage de deux polynômes
  int tab1[7] = {5, 6, 2, 3, 7, 1, 1};
  polynome* poly1 = creer_poly(tab1, 6);
  printf("Affichage poly1 : ");
  afficher(*poly1);
  polynome* poly2 = creer_poly_aleatoire(3, 4);  
  printf("Affichage poly2 : ");
  afficher(*poly2);
  printf("\n");

  //Affichage évaluation
  int a = evaluation(poly2, 2);
  printf("Résultat evaluation à x = 2 de poly2 : %d\n", a);
  printf("\n");

  printf("Derivée de poly 1 : ");
  afficher(*derivee(poly1));
  printf("Derivee de poly 2 : ");
  afficher(*derivee(poly2));
  printf("\n");

  printf("Somme des polynomes : ");
  afficher(*addition(poly1,poly2));
  printf("Produit des polynomes : ");
  afficher(*produit(poly1,poly2));
  printf("\n");
  afficher(*creer_a_la_main());
}