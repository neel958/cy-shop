#include "header.h"

int nbrL(FILE *file){

    int i = 0 ;
    char c;

    while ((c=getc(file))!=EOF){

        if (c=='\n'){
            i++;
        }
    }

    rewind(file);
    return i+1;
}

void erreur_fichier(){
    printf("Erreur lors de l'ouverture du fichier \n");
}

int stockAccount(client * c1){

    FILE *acc = fopen("client.txt","r");
    if(acc == NULL){
    acc = fopen("./Data/Account-save.txt","r");
    }

    int nbrl =nbrL(acc);

    for(int i=0;i<nbrl;i++){

        fscanf(acc,"%s %s",c1[i].nom,c1[i].prenom);
    }

    fclose(acc);
    return nbrl;
}

int lire_produits(produit produits[], char* nom_fichier) {
    FILE* fichier = fopen(nom_fichier, "wr");
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


void ecrireadmins(){
    FILE *f = fopen("client.txt", "wb");
    if (f == NULL) {
        printf("Erreur lors de l'ouverture du fichier \n");
        return;
    }

    char admin[20] = "Ahmed Naël \n";
    char admin1[20] = "Khalfane Sélim \n";
    fputs(admin, f);
    fputs(admin1, f);
    fclose(f);
}

void ecrire_client(const char* nom, const char* prenom){
    FILE *f = fopen("client.txt", "wr");
    if (f == NULL) {
        printf("Erreur lors de l'ouverture du fichier \n");
        return;
    }
    fprintf(f, "%s %s\n", nom, prenom);
    fclose(f);
}
int lire_client(const char *fichier, client *Client) {
    FILE *f = fopen(fichier, "wr");
    if (f == NULL) {
        printf("Erreur lors de l'ouverture du fichier %s\n", fichier);
        return 0;
    }

    fread(Client, sizeof(Client), 1, f);
    fclose(f);

    return 1;
}