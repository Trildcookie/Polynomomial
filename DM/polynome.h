#ifndef COMPLEX
#define COMPLEX

typedef struct Polynome {int* coef; int rang;} polynome;

int power(int x, int n); // Fonction puissance c'est pratique mon reuf

polynome* creer_poly(int tab[], int degre); //Renvoie un polynôme dont les coefficients sont les entiers de tab.
polynome* creer_poly_aleatoire(int degre, int borne); // Renvoie un polynôme d'entiers entre -borne et borne définis de façons aléatoire.
void afficher(polynome poly); // Affiche le polynôme
int evaluation(polynome* poly, int x); //Renvoie poly(x) ou poly est le polynôme. Par exemple si poly(x) = 2x + 1 alors poly(2)=5
bool test_egalite(polynome* poly1, polynome* poly2);// Test sur l'égalité entre les deux polynômes.
polynome* derivee(polynome* poly); //Renvoie le polynôme dérivé de poly
polynome* addition(polynome* poly1, polynome* poly2); //Renvoie la somme des deux polynômes
polynome* produit_par_scalaire(polynome* poly, int a); //Renvoie a * poly
polynome* produit(polynome* poly1, polynome* poly2);//Renvoie le produit des deux polynômes
polynome* creer_a_la_main(void); //À l'aide de la fonction scanf de stdio, la fonction demande à l'utilisateur les coefficients du polynôme et renvoie un type polynome avec ces coefficients.

#endif
