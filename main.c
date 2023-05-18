#include "header.h"
#define NOMBRE_MAX_OBJET 175
#define NOMBRE_MAX_CLIENT 10


int main(){
    produit * object = malloc(sizeof(produit) * NOMBRE_MAX_OBJET);
    client * user = malloc(sizeof(client) * NOMBRE_MAX_CLIENT);

    int choix;
    printf("Bienvenue dans notre magasin CY shop, souhaitez vous allez dans le mode achat ou le mode gestion ? \nTapez 1 pour le mode achat, et 2 pour le mode gestion \n\n");
    scanf("%d",&choix);
    switch (choix)
    {
    case 1:
        affiche_mode_achat();
        break;
    case 2:
        affiche_mode_gestion();
        break;
    default:
    printf("Vous n'avez pas entrer un chiffre correct \n.");
        break;
    }

    return 0;
}
