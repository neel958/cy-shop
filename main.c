#include "header.h"


int main(){
    int choix;
    int p = sizeof(client);
    printf("%d", p);
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
