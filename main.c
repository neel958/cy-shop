#include "header.h"


produit * object = NULL;
client * user = NULL;

int main(){
    FILE * f_c = fichier_client();
    FILE * f_p = fichier_produit();
    ecrireadmins();
    copier_contenu_fichier();
    object =  malloc(sizeof(produit) * nbrL(f_p));
    user = malloc(sizeof(client) * NOMBRE_MAX_CLIENT);

    lire_client();
    lire_produits();
    int choix;
    affiche_message_entre();
    scanf("%d",&choix);
    switch (choix)
    {
    case 1:
        affiche_mode_achat();
        break;
    case 2:
        afficheModeGestion();
        break;
    default:
        affiche_default();
        break;
    }

    free(user);
    free(object);
    return 0;
}
