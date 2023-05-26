#include "header.h"


void affiche_produit(produit* p1){
    printf("Voici les caractèristiques du produit : \n");
    printf("Nom : %s \n", p1->nom);
    printf("Numero de référence : %lu \n", p1->reference);
    printf("Quantité : %d \n", p1->quantite);
    printf("Prix : %.2f \n", p1->prix);
    printf("Taille : %c \n", p1->taille);
}



produit trouver_produit(produit *p1, int nbr_produit){
    produit produit_poubelle;
    produit_poubelle.quantite = -5;
    int choix;
    printf("Comment voulez-vous rechercher le produit ?\nTapez 1 pour rechercher le produit par la référence \nTapez 2 pour le chercher par le nom\n\n");
    scanf("%d", &choix);
    switch (choix) {
        case 1: {
            int valeur = -1;
            unsigned long ref;
            printf("Indiquez la référence du produit que vous recherchez : ");
            scanf("%lu", &ref);
            for (int i = 0; i < nbr_produit; i++) {
                if (p1[i].reference == ref) {  //recherche du produit à travers le tableaux
                    valeur = i;
                    return p1[i];
                }
            }
            if (valeur == -1) {
                printf("Aucun produit n'a été trouvé avec la référence que vous avez entré \n");
                return produit_poubelle;
            }
        }
        break;
        case 2: {
            char nom[50];
            int valeur = -1;
            printf("Indiquez le nom du produit que vous recherchez : ");
            scanf("%s", nom);
            for (int i = 0; i < nbr_produit; i++) {
                if (strcmp(p1[i].nom, nom) == 0) {
                    valeur = i;
                    return p1[i];
                }
            }
            if (valeur == -1) {
                printf("Aucun produit n'a été trouvé avec le nom %s \n", nom);
                return produit_poubelle;
            }
        }
            break;
        default:
            affiche_default();
            return produit_poubelle;
    }
}


void recherche_stock_produit(produit *p1, int nbr_produit){
    int choix;
    printf("Comment voulez-vous rechercher le produit ?\nTapez 1 pour rechercher le produit par la référence \nTapez 2 pour le chercher par le nom\n\n");
    scanf("%d", &choix);
    switch (choix) {
        case 1: {
            int valeur = -1;
            unsigned long ref;
            printf("Indiquez la référence du produit dont vous souhaitez connaitre le stock : ");
            scanf("%lu", &ref);
            for (int i = 0; i < nbr_produit; i++) {
                if (p1[i].reference == ref) {                                                //recherche du produit à travers le tableaux
                    printf("Il reste la quantité suivante : %d \n", p1[i].quantite);
                    valeur = i;
                    break;
                }
            }
            if (valeur == -1) {
                printf("Aucun produit n'a été trouvé avec la référence %lu \n", ref);
            }
        }
        break;
        case 2: {
            char nom[50];
            int valeur = -1;
            printf("Indiquez le nom du produit que vous recherchez : ");
            scanf("%s", nom);
            for (int i = 0; i < nbr_produit; i++) {
                if (strcmp(p1[i].nom, nom) == 0) {
                    printf("Il reste la quantité suivante : %d \n", p1[i].quantite);
                    valeur = i;
                    break;
                }
            }
            if (valeur == -1) {
                printf("Aucun produit n'a été trouvé avec le nom %s \n", nom);
            }
        }
            break;
        default:
            affiche_default();
            exit(1);
    }
}


void affiche_stock_bas(produit * p1, int nombre_produit){
    for(int i = 0 ; i < nombre_produit ; i ++){
        if(p1[i].quantite == 0){
            printf("Nous ne possédons plus de %s \n",p1[i].nom);
        }
    }
    printf("\n \n");


    printf("Voici les 5 produits avec le stock le plus bas : \n \n");
    for(int i = 0; i < 5 ; i ++){
        int min = i;
        for(int j = i + 1 ; j < nombre_produit ; j++){
            if (p1[j].quantite < p1[min].quantite){             //recherche des elements avec le stock le + faible
                min = j;               
            }
        }
        printf("Il ne reste que %d du produit suivant : %s \n",p1[min].quantite,p1[min].nom);
        produit temporaire = p1[i];
        p1[i] = p1[min];
        p1[min] = temporaire;
    }
}


int afficher_place_restante(produit produits[], int nombre_produits) {
    int place_totale = 300;
    int place_occupee = 0;

    for (int i = 0; i < nombre_produits; i++) {
        if (produits[i].taille == 'P') {
            place_occupee += produits[i].quantite;
        }
        else if (produits[i].taille == 'M') {
            place_occupee += 2 * produits[i].quantite;
        }
        else if (produits[i].taille == 'G') {
            place_occupee += 4 * produits[i].quantite;
        }
    }

    int place_restante = place_totale - place_occupee;
    printf("Il reste %d places disponibles.\n", place_restante);
    return place_restante;
}

produit augmenter_stock(produit *p1, int nombre_produits, unsigned long reference, int place_restante){
    int index_produit = -1;
    produit p_poubelle;
    p_poubelle.reference = -5;
    for (int i = 0; i < nombre_produits; i++) {
        if (p1[i].reference == reference) {
            index_produit = i;
            break;
        }
    }

    if (index_produit == -1) {
        printf("Le produit avec la référence que vous avez rentré n'a pas été trouvé.\n");
        return p_poubelle;
    }

    int quantite_ajoutee;
    printf("Combien d'unité voulez-vous ajouter pour le produit %s ?\n", p1[index_produit].nom);
    scanf("%d", &quantite_ajoutee);

    int taille_produit = 0;
    if (p1[index_produit].taille == 'P') {
        taille_produit = 1;
    } else if (p1[index_produit].taille == 'M') {
        taille_produit = 2;
    } else if (p1[index_produit].taille == 'G') {
        taille_produit = 4;
    }

    int taille_stock_actuel = quantite_ajoutee * taille_produit;

    if (taille_stock_actuel + (300-place_restante) >= TAILLE_MAX){                 //verifie si ca depasse pas le stock maximal
        printf("Impossible d'ajouter cette quantité de produit, le stock est plein.\n");
        return p_poubelle;
    }

    p1[index_produit].quantite += quantite_ajoutee;
    ecrire_caracteristiques_produits(object);
    printf("Le stock pour le produit %s a ete augmenté de %d unité. Nouvelle quantite : %d\n", p1[index_produit].nom, quantite_ajoutee, p1[index_produit].quantite);
    return p1[index_produit];
}