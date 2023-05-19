#include "header.h"

int lire_produits() {
    FILE *f = fopen("produit.txt", "r");
    if (f == NULL) {
        printf("Erreur lors de l'ouverture du fichier produit.txt.\n");
        return 0; 
    }
    
    int nbrl = nbrL(f);
    char ligne[100];

    for (int i = 0; i < nbrl; i++) {          
        fscanf(f, "%s %lu %d %c %f", object[i].nom, &object[i].reference, &object[i].quantite, &object[i].taille, &object[i].prix);
        printf("test %d \n", i+1);

        
    }

    fclose(f);
    return nbrl;
}

int lire_client() {

    FILE *f = fopen("client.txt","r");
    if (f == NULL) {
        printf("Erreur lors de l'ouverture du fichier client.txt.\n");
        return 0;
    }
    int nbrl =nbrL(f);

    for (int i = 0; i < nbrl; i++) {
        if (fscanf(f, "%s %s", user[i].nom, user[i].prenom) != 2) {
            printf("Erreur de lecture des données du fichier <<client.txt>> a la ligne %d\n", i+1);
            fclose(f);
            return 0;
        }
    }

    fclose(f);
    return nbrl;
}


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

FILE * fichier_client(){
    FILE * f = fopen("client.txt","r");
    if(f == NULL){f = fopen("client.txt","r");}
    return f;
}

FILE * fichier_produit(){
    FILE * f = fopen("produit.txt","r");
    if(f == NULL){f = fopen("produit.txt","r");}
    return f;
}

void erreur_fichier(){
    printf("Erreur lors de l'ouverture du fichier \n");
}

int stockAccount(client * c1){

    FILE *acc = fopen("client.txt","r");
    if(acc == NULL){
    acc = fopen("client.txt","r");
    }

    int nbrl =nbrL(acc);

    for(int i=0;i<nbrl;i++){

        fscanf(acc,"%s %s",c1[i].nom,c1[i].prenom);
    }

    fclose(acc);
    return nbrl;
}



void ecrireadmins(){
    FILE *f = fopen("client.txt", "wb");
    if (f == NULL) {
        printf("Erreur lors de l'ouverture du fichier \n");
        return;
    }

    char admin[20] = "Ahmed Nael";
    char admin1[20] = "Khalfane Selim";
    char saut_ligne[2] = "\n";
    fputs(admin, f);
    fputs(saut_ligne, f);
    fputs(admin1, f);
    fclose(f);
}

void ecrire_client(char nom [], char prenom[]){

    FILE *f = fopen("client.txt", "a");
    if (f == NULL) {
        printf("Erreur lors de l'ouverture du fichier \n");
        return;
    }
    fputs("\n", f);
    fputs(nom, f);
    fputs(" ", f);
    fputs(prenom, f);

    fclose(f);
}
