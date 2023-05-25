#ifndef HEADER_H
#define HEADER_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#endif

#define TAILLE_MAX 300
#define NOMBRE_MAX_OBJET 50
#define NOMBRE_MAX_CLIENT 10

typedef struct {
    char nom[50];
    unsigned long reference;
    int quantite;
    float prix;
    char taille; 
} produit;

typedef struct {
    char nom[50];
    char prenom[50];
    produit historique_achats[sizeof(produit) * 5];
} client;

extern produit * object;
extern client * user;

void affiche_message_entre();
void affiche_mode_achat();
void afficheModeGestion();
void affiche_default(); 


void affiche_produit(produit* p1);
produit trouver_produit(produit *p1, int nbr_produit);
void recherche_stock_produit(produit *p1, int nbr_produit);
void affiche_stock_bas(produit * p1, int nombre_produit);
int afficher_place_restante(produit produits[], int nombre_produits);
produit augmenter_stock(produit *produits, int nombre_produits, unsigned long reference, int place_restante);
void ecrire_caracteristiques_produits(produit * p1);


void lire_produits();
void ecrire_client(char nom [], char prenom[]);
void lire_client();
int nbrL(FILE * file);
void ecrireadmins();
void erreur_fichier();
FILE * fichier_client();
FILE * fichier_produit();
void supprimer_ligne_fichier(int numero_ligne);
void copier_contenu_fichier();


client ajouter_client(client c1);
int supprimer_client(client * c1, int *nombre_clients, char nom[], char prenom[]);
void rechercher_client(client *c1, char nom[], char prenom[]);
void afficher3DerniersAchats(client c1);
int trouver_position_client(char nom [], char prenom[]);

