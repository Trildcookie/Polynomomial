#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "polynome.h"
// polynome (int* coef, int rang) //

/* Fonction puissance :| */
////////////////////////////////////////////////
int power(int x, int n){
    int X = 1;
    if( n == 0 ){return 1;}
    for(int i = 0; i<n; i++){
        X = X*x;
    }
    return X;
}
////////////////////////////////////////////////

/* Creer un polynome a partir d'un tableau*/
////////////////////////////////////////////////
polynome* creer_poly(int tab[], int degre){
    
    int* tableau = (int*)malloc((degre+1)*sizeof(int));
    for(int i =0; i<degre+1;i++){
      tableau[i] = tab[i] ;
    }
    
    polynome* p = (polynome*)malloc(sizeof(polynome));
    
    p -> coef = tableau;
    p -> rang = degre;

    return p;
}
////////////////////////////////////////////////

/* Creer un polynome aleatoire avec une borne*/
////////////////////////////////////////////////
polynome* creer_poly_aleatoire(int degre, int borne){

    int tab[degre+1];
    for(int i=0; i<= degre; i++){
        tab[i] =  rand()%(2*borne) - borne;
    }
    return creer_poly(tab, degre);

}
////////////////////////////////////////////////

/*Free le tableau et la struct*/
////////////////////////////////////////////////
void supprimer_polynome(polynome* poly){
    free(poly->coef);
    free(poly);
}
////////////////////////////////////////////////

/* Print le polynome */
////////////////////////////////////////////////
void afficher(polynome poly){

    int acc = poly.rang;

    for(int i=0; i<poly.rang + 1; i++ ){

        // On gere les signes d'abord
        if (poly.coef[i] == 0){ // Permet de savoir le plus grand terme non nul

                if ( acc == poly.rang-i ){
                    acc--;
                }
        
        }else if(poly.coef[i] > 0 && acc != poly.rang-i ){
            printf(" + ");
        } else if (poly.coef[i] < 0){
            printf(" - ");
        }

        // Puis les coefs ! :) 

        if(poly.coef[i] != 1 && poly.coef[i] != 0){
            printf("%d", abs(poly.coef[i]));
        }
        if (poly.coef[i] == 1 && i == poly.rang){
            printf("%d", abs(poly.coef[i]));
        }

        //Enfin les puissances ....
        if( i == poly.rang - 1 && poly.coef[i] != 0){
            printf("x");
        } else if ( i != poly.rang && poly.coef[i] != 0){
            printf("x^%d", poly.rang - i);
        }
    }
    printf("\n");
}
////////////////////////////////////////////////

/* Evalue la fonction a x */
////////////////////////////////////////////////
int evaluation(polynome* poly, int x){
    int acc = 0;
    for(int i = 0; i <= poly->rang ; i++){
        acc += poly->coef[i]*power(x, poly->rang - i);
    }
    return acc;
}
////////////////////////////////////////////////

/* Verifie si les polynomes sont les memes*/
////////////////////////////////////////////////
bool test_egalite(polynome* poly1, polynome* poly2){
    if(poly1->rang != poly2->rang){return false;}
    for(int i = 0; i <= poly1->rang;i++){
        if(poly1->coef[i] != poly2->coef[i]){return false;}
    }
    return true;
}
////////////////////////////////////////////////

/*Derive le polynome*/
////////////////////////////////////////////////
polynome* derivee(polynome* poly){
    int tab[poly->rang];
    for (int i = 0; i < poly->rang;i++){
        tab[i] = poly->coef[i] * (poly->rang - i);
    }

    return creer_poly(tab, (poly->rang)-1);
}
////////////////////////////////////////////////

/* Renvoie la somme de deux polynomes */
////////////////////////////////////////////////
polynome* addition(polynome* poly1, polynome* poly2){

    if( poly1->rang > poly2->rang ){ 

        int degre = poly1->rang; //degre du polynome 

        int tab[degre +1];
        for(int i = 0; i < degre - poly2->rang; i++){ // On recopie les puissances de poly1 plus grand que poly2
            tab[i] = poly1->coef[i];
        }

        for(int i = degre - poly2->rang ; i < degre + 1; i++){ // On additione mtn les coefs des memes puissances
            tab[i] = poly1->coef[i] + poly2->coef[i - (degre - poly2->rang)];
        }
        return creer_poly(tab, degre);

    }else{ 

        int degre = poly2->rang; //degre du polynome 

        int tab[degre +1];
        for(int i = 0; i < degre - poly1->rang; i++){ // On recopie les puissances de poly1 plus grand que poly2
            tab[i] = poly2->coef[i];
        }

        for(int i = degre - poly1->rang ; i < degre + 1; i++){ // On additione mtn les coefs des memes puissances
            tab[i] = poly2->coef[i] + poly1->coef[i - (degre - poly1->rang)];
        }
        return creer_poly(tab, degre);
    }
}
////////////////////////////////////////////////

/* Multiplie le polynome par un scalaire */
////////////////////////////////////////////////
polynome* produit_par_scalaire(polynome* poly, int a){
    for(int i = 0; i<= poly->rang; i++){
        poly->coef[i] = poly->coef[i] * a;
    }
    return poly;
}
////////////////////////////////////////////////

/*Turbo produit de deux polynomes*/
////////////////////////////////////////////////
polynome* produit(polynome* poly1, polynome* poly2){
    int n = poly1->rang;
    int m = poly2->rang;

    int tab[n+m+1];

    for(int j = 0; j <= n+m ; j++ ){
        int coef = 0;
        int a,b;
        for(int k = 0; k<= n+m-j ; k++ ){
            if( k > n ){a = 0;}else{a = poly1->coef[k];}
            if( n+m-j-k > m ){b = 0;}else{b = poly2->coef[n+m-j-k];}
            coef += a*b;
        }
        tab[j] = coef;
    }
    return creer_poly(tab, n+m);
}
////////////////////////////////////////////////

/**/
////////////////////////////////////////////////
polynome* creer_a_la_main(void){
    int degre = 0;

    int res = 0;
    printf("Entrez le degré du polynome : ");

    res = scanf("%d", &degre);
    if(res != 1){
        printf("\nBah alors on s'est pas écrire un int c'est turbo relou :'( Aller mange toi ce turbo ratio moi je me tire ( comme black M ), ok non je rigole en vrai de vrai juste relance la commande mais la prochaine fois soit pas relou que je te retrouve pas a ecrire nimp quand je te demande un nombre ( cf cours de grande section mon reuf ??? ) apres si tu te demandes pk j'exit la fonction au lieu de te laisser ressayer de mettre une valeur et bah .... double ratio + j'ai pas demande + code diff + user end diff donc shhuuuuut et utilise ce jeune numpad miteux a ta droite ok ( cette remarque ne prend pas en compte les utilisateurs samsung frige )  \n ");
        exit(-1);
    }

    int tab[degre + 1];
    
    for(int i = 0; i <= degre; i++){

        int coef = 0;
        int result = 0;
        printf("Choisis le coefficient de la %d ieme puissance :", degre - i);
        result = scanf("%d", &coef);
        if (result == 1) {
            tab[i] = coef;
        } else {
            printf("\nBah alors on s'est pas écrire un int c'est turbo relou :'( Aller mange toi ce turbo ratio moi je me tire ( comme black M ), ok non je rigole en vrai de vrai juste relance la commande mais la prochaine fois soit pas relou que je te retrouve pas a ecrire nimp quand je te demande un nombre ( cf cours de grande section mon reuf ??? ) apres si tu te demandes pk j'exit la fonction au lieu de te laisser ressayer de mettre une valeur et bah .... double ratio + j'ai pas demande + code diff + user end diff donc shhuuuuut et utilise ce jeune numpad miteux a ta droite ok ( cette remarque ne prend pas en compte les utilisateurs samsung frige )  \n ");
            exit(-1);
        }

    }

    return creer_poly(tab, degre);
}
////////////////////////////////////////////////