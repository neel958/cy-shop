#include "header.h"


void affiche_produit(produit* p1){
    printf("Voici les caracteristiques du produit : \n");
    printf("Nom : %s \n", p1->nom);
    printf("Numero de reference : %lu \n", p1->reference);
    printf("Quantite : %d \n", p1->quantite);
    printf("Prix : %.2f \n", p1->prix);
    printf("Taille : %c \n", p1->taille);
}


produit ajouterproduit(produit p1, int num_produit) {

    printf("Quel est le nom du produit numero %d ?\n", num_produit + 1);
    scanf("%s", p1.nom);
    
    printf("Quel est le numero de reference du produit numero %d ? \n", num_produit + 1);
    scanf("%lu", &p1.reference);

    printf("Quelle quantite du produit numero %d  vous-voulez ajouter ?\n", num_produit + 1);
    scanf("%d", &p1.quantite);

    printf("Quel est le prix du produit %d que vous souhaitez ajouter ?\n", num_produit + 1);
    scanf("%f", &p1.prix);

    do {
        printf("Quelle est la taille du produit ? Il en existe uniquement 3 : Tapez 'P' pour petite, 'M' pour moyenne ou 'G' pour grande.\n");
        scanf(" %c", &p1.taille);
    } while ((p1.taille != 'P') && (p1.taille != 'M') && (p1.taille != 'G'));
    return p1;
}

void modifier_produit(produit produits[], int nombre_produits, unsigned long reference) {
    int index_produit = -1;


    for (int i = 0; i < nombre_produits; i++) {
        if (produits[i].reference == reference) {
            index_produit = i;
            break;
        }
    }


    if (index_produit == -1) {
        printf("Le produit avec la référence %lu n'a pas été trouvé.\n", reference);
        return;
    }


    int choix;
    printf("Que voulez-vous changer dans le produit ? Tapez 1 pour le nom, 2 pour le numero de reference, 3 pour la quantité du produit, 4 pour le prix du produit et 5 pour modifier la taille du produit\n");
    scanf("%d", &choix);
    switch (choix) {
        case 1:

            printf("Indiquez le nouveau nom du produit uniquement en lettre : \n");
            scanf("%s", produits[index_produit].nom);
            
            break;
        case 2:
            printf("Indiquez le nouveau numero de reference : \n");
            scanf("%lu", &produits[index_produit].reference);
            break;
        case 3:
            printf("Indiquez la nouvelle quantite du produit : \n");
            scanf("%d", &produits[index_produit].quantite);
            break;
        case 4:
            printf("Indiquez le nouveau prix du produit : \n");
            scanf("%f", &produits[index_produit].prix);
            break;
        case 5:
            printf("Indiquez la nouvelle taille du produit : \n");
            scanf(" %c", &produits[index_produit].taille);
            break;
        default:
            printf("Entrez un chiffre correcte. \n");
            break;
    }
}

int supprimer_produit(produit *produits, int *nombre_produits, unsigned long reference) {
    int index_produit = -1;
    char t;

    for (int i = 0; i < *nombre_produits; i++) {
        if (produits[i].reference == reference) {
            index_produit = i;
            t = produits[i].taille;
            break;
        }
    }


    if (index_produit == -1) {
        printf("Le produit avec la référence %lu n'a pas été trouvé.\n", reference);
        return 0;
    }

    // Supprimer le produit en décalant les éléments vers la gauche
    for (int i = index_produit; i < *nombre_produits - 1; i++) {
        produits[i] = produits[i + 1];
    }

    // Diminuer le nombre de produits
    (*nombre_produits)--;

    printf("Le produit avec la référence %lu a été supprimé avec succès.\n", reference);
    return t;
}


produit trouver_produit(produit *p1, int nbr_produit){
    produit produit_poubelle;
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
                if (p1[i].reference == ref) {
                    valeur = i;
                    return p1[i];
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
                    valeur = i;
                    return p1[i];
                }
            }
            if (valeur == -1) {
                printf("Aucun produit n'a été trouvé avec le nom %s \n", nom);
            }
        }
            break;
        default:
            printf("Entrez un chiffre correcte \n");
            break;
    }
}

void afficher_tout_produits(produit *p1, int nombre_produit) {
    for (int i = 0; i < nombre_produit; i++) {
        printf("Voici les caracteristiques du produit numero %d : \n", i + 1);
        printf("Nom : %s \n", p1[i].nom);
        printf("Numero de reference : %lu \n", p1[i].reference);
        printf("Quantite : %d \n", p1[i].quantite);
        printf("Prix : %.2f \n", p1[i].prix);
        printf("Taille : %c \n", p1[i].taille);
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
                if (p1[i].reference == ref) {
                    printf("%d \n", p1[i].quantite);
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
                    printf("%d \n", p1[i].quantite);
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
            printf("Entrez un chiffre correcte \n");
            break;
    }
}


void affiche_stock_bas(produit * p1, int nombre_produit){
    for(int i = 0 ; i < nombre_produit ; i ++){
        if(p1[i].quantite == 0){
            printf("Nous ne possedons plus de %s \n",p1[i].nom);
        }
    }
    printf("\n \n");


    printf("Voici les 5 produits avec le stock le plus bas : \n \n");
    for(int i = 0; i < 5 ; i ++){
        int min = i;
        for(int j = i + 1 ; j < nombre_produit ; j++){
            if (p1[j].quantite < p1[i].quantite){
                min = j;               
            }
        }
        printf("Il ne reste que %d du produit suivant : %s \n",p1[min].quantite,p1[min].nom);
        produit temporaire = p1[i];
        p1[i] = p1[min];
        p1[min] = temporaire;
    }
}


void afficher_place_restante(produit produits[], int nombre_produits) {
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
}

void augmenter_stock(produit *produits, int nombre_produits, unsigned long reference){
    int index_produit = -1;
    for (int i = 0; i < nombre_produits; i++) {
        if (produits[i].reference == reference) {
            index_produit = i;
            break;
        }
    }

    if (index_produit == -1) {
        printf("Le produit avec la référence %lu n'a pas été trouvé.\n", reference);
        return;
    }

    int quantite_ajoutee;
    printf("Combien d'unités voulez-vous ajouter pour le produit %s ?\n", produits[index_produit].nom);
    scanf("%d", &quantite_ajoutee);

    int taille_produit = 0;
    if (produits[index_produit].taille == 'P') {
        taille_produit = 1;
    } else if (produits[index_produit].taille == 'M') {
        taille_produit = 2;
    } else if (produits[index_produit].taille == 'G') {
        taille_produit = 4;
    }

    int stock_actuel = quantite_ajoutee + produits[index_produit].quantite;
    int taille_stock_actuel = stock_actuel * taille_produit;

    if (taille_stock_actuel > TAILLE_MAX) {
        printf("Impossible d'ajouter cette quantité de produit, le stock est plein.\n");
        return;
    }

    produits[index_produit].quantite += quantite_ajoutee;
    printf("Le stock pour le produit %s a été augmenté de %d unité(s). Nouvelle quantité : %d\n", produits[index_produit].nom, quantite_ajoutee, produits[index_produit].quantite);
}