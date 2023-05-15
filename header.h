#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAILLE_MAX 300
#define NOMBRE_MAX_OBJET 175
#define NOMBRE_MAX_CLIENT 10

typedef struct {
    char nom[50];
    unsigned long reference;
    int quantite;
    float prix;
    char taille; // 'P' pour petit 'M' pour moyen et 'G' pour grand
} produit;

typedef struct {
    char nom[50];
    char prenom[50];
    produit historique_achats[sizeof(produit)*10];
} client;


// declaration des tableaux :

produit object[sizeof(produit) * NOMBRE_MAX_OBJET];
client user[sizeof(client)*5];


// fonction produit :

void affiche_produit(produit* p1);
produit ajouterproduit(produit p1, int num_produit);
void modifier_produit(produit produits[], int nombre_produits, unsigned long reference);
int supprimer_produit(produit *produits, int *nombre_produits, unsigned long reference);
void recherche_stock_produit(produit * p1, int nbr_produit);
void affiche_stock_bas(produit * p1, int nombre_produit);
void afficher_tout_produits(produit *p1, int nombre_produit);
void afficher_place_restante(produit produits[], int nombre_produits);
void augmenter_stock(produit *produits, int nombre_produits, unsigned long reference);



// fonction client :

client ajouter_client(client c1);
void modifier_client(client *c1, int nbr_client, char nom[50]);
void supprimer_client(client * c1, int *nombre_clients, char nom[50]);
int rechercher_client(client *c1, char nom[], char prenom[]);



// fonction fichier :

void ecrire_produits(produit produits[], int nombre_produits, char* nom_fichier);
int lire_produits(produit produits[], char* nom_fichier);
void ecrire_client(const char *fichier, client *Client);
int lire_client(const char *fichier, client *Client);


//fonction interface :

void affiche_mode_gestion();
void affiche_mode_achat();



#endif