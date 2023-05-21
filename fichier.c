#include "header.h"

void lire_produits() {
    FILE *f = fopen("produit.txt", "r");
    if (f == NULL) {
        printf("Erreur lors de l'ouverture du fichier produit.txt.\n");
        return; 
    }
    
    int nbrl = nbrL(f);
    char ligne[100];

    for (int i = 0; i < nbrl; i++) {    
        if(fscanf(f, "%s %lu %d %c %f", object[i].nom, &object[i].reference, &object[i].quantite, &object[i].taille, &object[i].prix) != 5){
            printf("Erreur de lecture des donnees du fichier <<client.txt>> a la ligne %d\n", i+1);
        }
    }

    fclose(f);
}

void lire_client() {

    FILE *f = fopen("client.txt","r");
    if (f == NULL) {
        printf("Erreur lors de l'ouverture du fichier client.txt.\n");
        return;
    }
    int nbrl =nbrL(f);

    for (int i = 0; i < nbrl; i++) {
        if (fscanf(f, "%s %s", user[i].nom, user[i].prenom) != 2) {
            printf("Erreur de lecture des donnees du fichier <<client.txt>> a la ligne %d\n", i+1);
            fclose(f);
            return;
        }
    }

    fclose(f);
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
    fputs("\n",f);
    fputs(nom, f);
    fputs(" ", f);
    fputs(prenom, f);

    fclose(f);
}



void ecrire_caracteristiques_produits(produit * p1, int taille){
    FILE* fichier = fopen("produit.txt", "w");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    for (int i = 0; i < taille; i++) {
        fprintf(fichier, "%s ", p1[i].nom);
        fprintf(fichier, "%lu ", p1[i].reference);
        fprintf(fichier, "%d ", p1[i].quantite);
        fprintf(fichier, "%c ", p1[i].taille);
        fprintf(fichier, "%.2f\n", p1[i].prix);
    }

    fclose(fichier);
}


void supprimer_ligne_fichier(int numero_ligne) {
    FILE *fichier = fopen("client.txt", "r");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    FILE *nouveau_fichier = fopen("client2.txt", "w");
    if (nouveau_fichier == NULL) {
        printf("Erreur lors de la création du nouveau fichier.\n");
        fclose(fichier);
        exit(1);
    }

    int compteur_ligne = 1;
    char ligne[1000];

    while (fgets(ligne, sizeof(ligne), fichier)){
        if (compteur_ligne != numero_ligne) {
            fputs(ligne, nouveau_fichier);
        }
        compteur_ligne++;
    }
    
    fclose(fichier);
    fclose(nouveau_fichier);


    char commande_suppression[100];
    sprintf(commande_suppression, "rm client.txt"); // ATTENTION sur unix remplacer 'rm' au lieu de del, sur window mettre del
    system(commande_suppression);


    char commande_renommage[100];
    sprintf(commande_renommage, "mv client2.txt client.txt"); // ATTENTION sur unix remplacer 'mv' au lieu de ren, sur windos mettre ren
    system(commande_renommage);
}