#include "header.h"

// Fonctions pour les produits
void ecrire_produits(produit produits[], int nombre_produits, char* nom_fichier) {
    FILE* fichier = fopen(nom_fichier, "wb");
    if (fichier == NULL) {
        printf("Erreur d'ouverture du fichier %s\n", nom_fichier);
        return;
    }
    fwrite(&nombre_produits, sizeof(int), 1, fichier);
    for (int i = 0; i < nombre_produits; i++) {
        fwrite(&produits[i], sizeof(produit), 1, fichier);
    }
    fclose(fichier);
}

int lire_produits(produit produits[], char* nom_fichier) {
    FILE* fichier = fopen(nom_fichier, "rb");
    if (fichier == NULL) {
        printf("Erreur d'ouverture du fichier %s\n", nom_fichier);
        return 0;
    }
    int nombre_produits;
    fread(&nombre_produits, sizeof(int), 1, fichier);
    for (int i = 0; i < nombre_produits; i++) {
        fread(&produits[i], sizeof(produit), 1, fichier);
    }
    fclose(fichier);
    return nombre_produits;
}


// Fonctions pour les clients
void ecrire_client(const char *fichier, client *Client) {
    FILE *f = fopen(fichier, "wb");
    if (f == NULL) {
        printf("Erreur lors de l'ouverture du fichier %s\n", fichier);
        return;
    }

    fwrite(Client, sizeof(Client), 1, f);
    fclose(f);
}

int lire_client(const char *fichier, client *Client) {
    FILE *f = fopen(fichier, "rb");
    if (f == NULL) {
        printf("Erreur lors de l'ouverture du fichier %s\n", fichier);
        return 0;
    }

    fread(Client, sizeof(Client), 1, f);
    fclose(f);

    return 1;
}