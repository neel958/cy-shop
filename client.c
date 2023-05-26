#include "header.h"

client ajouter_client(client c1){
    
    printf("Quel est votre nom ? \n");
    scanf("%s", c1.nom);

    printf("Quel est votre prénom ? \n");
    scanf("%s", c1.prenom);

    return c1;
}


void afficher3DerniersAchats(client c1) {
    int nbAchats = 0;

    for (int i = 0; i < sizeof(c1.historique_achats) / sizeof(c1.historique_achats[0]); i++) {
        if (strcmp(c1.historique_achats[i].nom, "") != 0) {         //compte le nombre d'achat de l'utilisateur
            nbAchats++;
        }
    }

    if (nbAchats == 0) {
        printf("Vous n'avez pas encore effectué d'achat.\n");
    } else if (nbAchats == 1) {
        printf("Voici votre seul achat :\nNom : %s\n", c1.historique_achats[0].nom);
    } else {
        int start = nbAchats - 3;
        if (start < 0) {
            start = 0;
        }
        for (int i = nbAchats - 1, j = 1; i >= start; i--, j++) {
            printf("Achat numéro %d :\nNom : %s\n", i+1 , c1.historique_achats[i].nom);     //affiche les 3 derniers achats
        }
    }
}


int supprimer_client(client * c1, int *nombre_clients, char nom[], char prenom[]){
    int index_client = -1;

    for (int i = 0; i < *nombre_clients; i++) {
        if (strcmp(c1[i].nom, nom) == 0 && strcmp(c1[i].prenom, prenom) == 0){
            index_client = i;
            break;
        }
    }


    if (index_client == -1) {
        printf("Monsieur %s %s n'a pas été trouvé dans notre base de données.\n", nom, prenom);
        return -1;
    }

    for (int i = index_client; i < *nombre_clients - 1; i++) {
        c1[i] = c1[i + 1];                          //supprime pas vraiment le client, il le decale juste vers la droite
    }

    (*nombre_clients)--;                            //decremente la variable nombre_client de 1

    printf("Monsieur %s %s a été supprimé de la base de données avec succès.\n", nom, prenom);
    return index_client+1;
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
        printf("Nous n'avons pas trouvé de %s %s.\n", nom, prenom);
        exit (1);
    }
}

int trouver_position_client(char nom[], char prenom[]) {
    FILE* fichier = fopen("client.txt", "r");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return -1;
    }

    char ligne[256];                                            //utilise un tableau de caractères ligne pour stocker chaque ligne du fichier. La taille du tableau est fixée à 256 caractères.
    int position = 0;

    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {      //lit chaque ligne du fichier à l'aide de la fonction fgets. Si la fin du fichier est atteinte, la boucle s'arrête.
        char* nom_client = strtok(ligne, " \n");                //extrait les noms et prenoms du fihcier avec la fonction strtok à l'aide ds delimiteur comme le saut a la ligne ou l'espace
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
    printf("Nous n'avons pas trouvé vos identifiants dans la base de données \n");
    return -1;
}