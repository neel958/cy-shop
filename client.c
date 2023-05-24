#include "header.h"

client ajouter_client(client c1){
    
    printf("Quel est votre nom ? \n");
    scanf("%s", c1.nom);

    printf("Quel est votre prenom ? \n");
    scanf("%s", c1.prenom);

    return c1;
}

void modifier_client(client *c1, int nbr_client, char nom[50]){
    int index_client = -1;
    

    for (int i = 0; i < nbr_client; i++) {
        if (c1[i].nom == nom) {
            index_client = i;
            break;
        }
    }


    if (index_client == -1) {
        printf("Monsieur %s n'a pas été trouvé dans notre base de donnee \n", nom);
        return;
    }

    int choix;
    printf("Que voulez vous changez dans la fiche client de monsieur %s ? \n Tapez 1 pour changer son nom, \n Tapez 2 pour changer son prenom \n", nom);
    scanf("%d", &choix);
    switch (choix)
    {
    case 1:
        printf("Tapez le nouveau nom du clien : \n");
        scanf("%s", c1[index_client].nom);
        break;
    
    case 2:
        printf("Tapez le nouveau prenom du client : \n");
        scanf("%s", c1[index_client].prenom);
        break;

    default:
        printf("Vous n'avez ni rentré 1 ni 2 \n");
        break;
    }
}


void afficher3DerniersAchats(client c1) {
    int nbAchats = 0;

    for (int i = 0; i < sizeof(c1.historique_achats) / sizeof(c1.historique_achats[0]); i++) {
        if (strcmp(c1.historique_achats[i].nom, "") != 0) {
            nbAchats++;
        }
    }

    if (nbAchats == 0) {
        printf("Vous n'avez pas encore effectue d'achat.\n");
    } else if (nbAchats == 1) {
        printf("Voici votre seul achat :\nNom : %s\n", c1.historique_achats[0].nom);
    } else {
        int start = nbAchats - 3;
        if (start < 0) {
            start = 0;
        }
        for (int i = nbAchats - 1, j = 1; i >= start; i--, j++) {
            printf("Achat numero %d :\nNom : %s\n", i, c1.historique_achats[i].nom);
        }
    }
}


int supprimer_client(client * c1, int *nombre_clients, char nom[], char prenom[]){
    int index_produit = -1;

    for (int i = 0; i < *nombre_clients; i++) {
        if (strcmp(c1[i].nom, nom) == 0 && strcmp(c1[i].prenom, prenom) == 0){
            index_produit = i;
            break;
        }
    }


    if (index_produit == -1) {
        printf("Monsieur %s %s n'a pas ete trouve dans notre base de donnee.\n", nom, prenom);
        return -1;
    }

    for (int i = index_produit; i < *nombre_clients - 1; i++) {
        c1[i] = c1[i + 1];
    }

    (*nombre_clients)--;

    printf("Monsieur %s %s a ete supprime de la base de donnee avec succes.\n", nom, prenom);
    return index_produit+1;
}

void rechercher_client(client *c1, char nom[], char prenom[]){
    FILE* f_client = fopen("client.txt", "rb");
    if (f_client == NULL) {
        printf("Erreur d'ouverture du fichier \n");
        return;
    }

    int valeur = -1;
    for (int i = 0; i < nbrL(f_client); i++) {
        if (strcmp(c1[i].nom, nom) == 0 && strcmp(c1[i].prenom, prenom) == 0) {
            printf("Bienvenue monsieur %s %s \n \n", nom, prenom);
            valeur = i;
            return;
        }
    }
    if (valeur == -1) {
        printf("Nous n'avons pas trouve de %s %s.\n", nom, prenom);
        exit (1);
    }
}

int trouver_position_client(char nom[], char prenom[]) {
    FILE* fichier = fopen("client.txt", "r");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return -1;
    }

    char ligne[256];
    int position = 0;

    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        char* nom_client = strtok(ligne, " \n");
        char* prenom_client = strtok(NULL, " \n");

        if (nom_client != NULL && prenom_client != NULL) {
            if (strcmp(nom_client, nom) == 0 && strcmp(prenom_client, prenom) == 0) {
                fclose(fichier);
                return position;
            }
        }

        position++;
    }

    fclose(fichier);
    printf("Nous n'avons pas trouve vos identifiants dans la base de donnee \n");
    return -1;
}