#include "header.h"


produit * object = NULL;
client * user = NULL;

int main(){
    FILE* f_produit = fopen("produit.txt", "r");
        if (f_produit == NULL) {
            erreur_fichier();
            return 0;
        }

    FILE* f_client = fopen("client.txt", "wb");
    if (f_client == NULL) {
        erreur_fichier();
        return 0;
    }

    ecrireadmins();

    malloc(sizeof(produit) * nbrL(f_produit));
    malloc(sizeof(client) * nbrL(f_client));

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
    return 0;
}
