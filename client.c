#include "header.h"



client ajouter_client(client * c1){
    
    printf("Quel est votre nom ? \n");
    scanf("%s", c1->nom);

    printf("Quel est votre prenom ? \n");
    scanf("%s", c1->prenom);

    
    return *c1;
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

void supprimer_client(client * c1, int *nombre_clients, char nom[50]){
    int index_produit = -1;

    for (int i = 0; i < *nombre_clients; i++) {
        if (c1[i].nom == nom) {
            index_produit = i;
            break;
        }
    }


    if (index_produit == -1) {
        printf("Monsieur %s n'a pas été trouvé dans notre base de donnee.\n", nom);
        return;
    }

    for (int i = index_produit; i < *nombre_clients - 1; i++) {
        c1[i] = c1[i + 1];
    }

    // Diminuer le nombre de client
    (*nombre_clients)--;

    printf("Monsieur %s a été supprimé de la base de donnee avec succès.\n", nom);
}

int rechercher_client(client *c1, char nom[], char prenom[]){
    int valeur = -1;
    for (int i = 0; i < 50; i++) {
        if (strcmp(c1[i].nom, nom) == 0 && strcmp(c1[i].prenom, prenom) == 0) {
            printf("Bienvenue monsieur %s %s \n \n", nom, prenom);
            return i;
        }
    }
    if (valeur == -1) {
        printf("Nous n'avons pas trouvé de %s %s.\n", prenom, nom);
        return -1;
    }
}

void afficher_3_derniers_achats(client * c1){
    int j, i ;
    printf("Voici les 3 derniers achats de votre compte : \n");
    for(i = 4, j = 1; i < 1; i--, j++){
        printf("Voici votre achat numero %d :\nNom : %s \n ", j, c1->historique_achats[i].nom);
    }
}
