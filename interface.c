#include "header.h"
#define NOMBRE_MAX_OBJET 175
#define NOMBRE_MAX_CLIENT 30


void affiche_mode_achat(){
    int choix;
    float prix_total = 0 ;
    printf("Avez vous un compte client ? \n1 pour oui \n2 pour non \n");
    scanf("%d", &choix);
    switch (choix)
    {
    case 1:
        char nom[50];
        char prenom[50];
        printf("Quelle est votre nom et prenom ? \n");
        scanf("%s", &nom);
        scanf("%s", &prenom);
        rechercher_client(&user, nom, prenom);
        afficher_3_derniers_achats(&user);
        break;
    case 2:
        int numero_client = 0;
        printf("Nous allons vous créer un compte client \n");
        user[numero_client] = ajouter_client(user);
        numero_client ++;
        break;
    default:
        break;
    }
    choix = 0;
    do
    {
        printf("Tapez 1 pour rechercher un produit et l'acheter \n");
        print("Tapez 2 pour afficher le prix total \n");
        scanf("%d", &choix);
        switch (choix)
        {
        case 1:
            int choix2 = 0 ;
            produit p1 = recherche_produit(object, NOMBRE_MAX_OBJET);
            printf("Voulez vous acheter le produit suivant : %s ?\n", p1.nom);
            printf("Tapez 1 pour oui, 2 pour non \n");
            switch (choix2)
            {
            case 1:
                p1.quantite--;
                prix_total += p1.prix;
                break;
            case 2:
                break;
            default:
                printf("Vous n'avez ni rentrer 1 ni 2 \n");
                break;
            }
            break;
        case 2:
            int oui_non;
            printf("Voici le prix total de vos achats pour l'instant : %.2f\n", prix_total);

            break;
        default:
            printf("Vous n'avez pas rentré de nombre correct \n");
            break;
        }
    } while (choix != 4);
    
}

void affiche_mode_gestion(){
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

