#include "header.h"
#define NOMBRE_MAX_OBJET 175
#define NOMBRE_MAX_CLIENT 30


void affiche_mode_achat(void){

}

void affiche_mode_gestion(void){
    int choix;
    int nb_obj_actuelle = 0;
    printf("\n \n \n Bienvenue à vous dans le mode gesition, tout d'abord voici la liste de nos produits avec les stocks les + bas : \n \n ");
    affiche_stock_bas(object,nb_obj_actuelle);
    afficher_place_restante(object, nb_obj_actuelle);
    do
    {
    printf("\n \n A vous s'offre maintenant plusieurs choix \n");
    printf("Tappez 1 pour connaître le stock du produit que vous désirez \n");
    printf("Tappez 2 pour augmenter le stock d'un produit que vous desirez \n");
    printf("Tappez 3  pour basculer vers le mode achat \n");
    printf("Tappez 4 pour quitter l'interface \n");
    scanf("%d", &choix);

    switch (choix)
    {
    case 1:
        recherche_stock_produit(object, nb_obj_actuelle);
        break;
    case 2:
        {
        unsigned long reference;
        printf("Entrez la reference du produit dont vous souhaitez augmenter le stock \n");
        scanf("%lu", &reference);
        augmenter_stock(object,NOMBRE_MAX_OBJET,reference);
        break;
        }
    case 3:
            affiche_mode_achat();
        break;
    default:
        printf("Vous n'avez pas saisi un nombre correct \n");
        break;
}

    } while (choix != 4);
    
}

