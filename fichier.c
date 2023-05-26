#include "header.h"

void lire_produits() {
    FILE *f = fopen("produit.txt", "r");
    if (f == NULL) {
        printf("Erreur lors de l'ouverture du fichier produit.txt.\n");
        return; 
    }
    
    int nbrl = nbrL(f);

    for (int i = 0; i < nbrl; i++) {    
        if(fscanf(f, "%s %lu %d %c %f", object[i].nom, &object[i].reference, &object[i].quantite, &object[i].taille, &object[i].prix) != 5){    //lecture des donners du fichier, les stock dans le tableau
            printf("Erreur de lecture des données du fichier <<produit.txt>> a la ligne %d\n", i+1);
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
        if (fscanf(f, "%s %s", user[i].nom, user[i].prenom) != 2) {                 //lecture des donners du fichier, les stock dans le tableau
            printf("Erreur de lecture des données du fichier <<client.txt>> à la ligne %d\n", i+1);

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

        if (c=='\n'){           //compte le nombre de ligne dans un fichier
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




void ecrireadmins(){
    FILE *f = fopen("client.txt", "wb");
    if (f == NULL) {
        printf("Erreur lors de l'ouverture du fichier \n");
        return;
    }

    char admin[20] = "Ahmed Nael";
    char admin1[20] = "Khalfane Selim";
    fputs(admin, f);
    fputs("\n", f);
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



void ecrire_caracteristiques_produits(produit * p1){
    FILE* fichier = fopen("produit.txt", "w");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    for (int i = 0; i < NOMBRE_MAX_OBJET-1; i++) {
        fprintf(fichier, "%s %lu %d %c %.2f\n", p1[i].nom, p1[i].reference, p1[i].quantite, p1[i].taille, p1[i].prix);
    }
    fprintf(fichier, "%s ", p1[49].nom);
    fprintf(fichier, "%lu ", p1[49].reference);
    fprintf(fichier, "%d ", p1[49].quantite);
    fprintf(fichier, "%c ", p1[49].taille);
    fprintf(fichier, "%.2f", p1[49].prix);          //ecris sans saut a la ligne, sinon ca comptera comme 51 produit


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
    char ligne[100];

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


void copier_contenu_fichier() {

    FILE* source = fopen("liste_produit.txt", "r");
    if (source == NULL) {
        printf("Erreur lors de l'ouverture du fichier source.\n");
        return;
    }

    FILE* destination = fopen("produit.txt", "w");
    if (destination == NULL) {
        printf("Erreur lors de l'ouverture du fichier destination.\n");
        fclose(source);
        return;
    }

    char ligne[50];
    while (fgets(ligne, sizeof(ligne), source) != NULL) {
        fputs(ligne, destination);
    }

    fclose(source);
    fclose(destination);
}