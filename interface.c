#include "header.h"




void affiche_mode_achat(){
    
    int choix, choix1;
    float prix_total = 0 ;
    int numero_client = 2;
    printf("\nAvez vous un compte client ? \n1 pour oui \n2 pour non \n \n");
    scanf("%d", &choix);
    switch (choix)
    {
    case 1:
    {
        int var;
        char nom[50];
        char prenom[50];
        printf("\nEntrez votre nom, puis votre prenom. Attention ne mettez pas d'accent. Et respectez les majuscules en debut de nom/prenom. \n");
        scanf("%s", nom);
        scanf("%s", prenom);
        var = rechercher_client(user, nom, prenom);
        if(var!=-1){
        afficher3DerniersAchats(user);
        }
        else if(var == -1){
            return;
        }

        break;
    }
    case 2:
        printf("\n\nNous allons vous creer un compte client \n\n");
        user[numero_client] = ajouter_client(user[numero_client]);
        printf("Bienvenue %s %s \n \n", user[numero_client].nom, user[numero_client].prenom);
        ecrire_client(user[numero_client].nom, user[numero_client].prenom);
        numero_client ++;
        break;

    default:
        printf("\nVous n'avez pas rentre de chiffre correct \n");
        return;
        break;
    }
    choix1 = 0;

    do
    {
        printf("\nTapez 1 pour rechercher un produit et l'acheter \n");
        printf("Tapez 2 pour afficher le prix total \n");
        printf("Tapez 3 pour basculer vers le mode gestion \n");
        printf("Tapez 4 pour ajouter un client à la liste \n");
        printf("Tapez 5 pour afficher la liste complete de produit \n");
        printf("Tapez 6 si vous souhaitez vous desinscrire de notre magasin \n");
        printf("Tapez 7 pour quitter l'interface \n \n");
        scanf("%d", &choix1);
        switch (choix1)
        {
        case 1:
        {
            int choix_achat = 0;
            produit p1;
            p1 = trouver_produit(object, NOMBRE_MAX_OBJET);
            if(p1.quantite == -4){
                exit(1);
            }
            if(p1.quantite == 0){
                printf("Nous sommes desole mais ce produit est en rupture se stock \n");
                exit(1);
            }

            printf("\nVoulez vous acheter le produit suivant : %s ?\n", p1.nom);
            printf("Tapez 1 pour oui, 2 pour non \n");
            scanf("%d", &choix_achat);
            switch (choix_achat)
            {
            case 1:       
                p1.quantite -= 1;
                prix_total += p1.prix;
                printf("\nVous avez achete le produit avec succes \n");
                for(int i = 0; i < NOMBRE_MAX_OBJET ; i++){
                    if(strcmp(object[i].nom,p1.nom)  == 0){
                        object[i].quantite = p1.quantite;
                        break;
                    }
                }
                break;
            case 2:  
                break;
            default:
                printf("Vous n'avez ni rentrer 1 ni 2 \n");
                break;
            }
            
            break;
        }
        case 2:
        {
            printf("\nVoici le prix total de vos achats pour l'instant : %.2f € \n", prix_total);

            break;
        
        }
        case 3:
        
            afficheModeGestion();
            break;
        
        case 4: 
            if(numero_client > NOMBRE_MAX_CLIENT){
                printf("Vous avez depasse la limite maximal d'utilisateur \n");
                return;
            }
            else{
                user[numero_client] = ajouter_client(user[numero_client]);
                printf("Bienvenue %s %s \n \n", user[numero_client].nom, user[numero_client].prenom);
                ecrire_client(user[numero_client].nom, user[numero_client].prenom);
                numero_client ++;

            }
            break;
        case 5:
            for(int i = 0 ; i < NOMBRE_MAX_OBJET ; i++){
                printf("Nom du produit : %s / Stock restant : %d / Prix : %.2f euros / Numero de reference : %lu\n",object[i].nom,object[i].quantite,object[i].prix,object[i].reference);
            }
            break;
        case 6:
        {
            char nom_supp[25];
            char prenom_supp [25];

            printf("Entrez votre Nom : \n");
            scanf("%s", nom_supp);
            printf("Entrez maintenant votre prenom \n");
            scanf("%s", prenom_supp);
            
            int client_a_supp = supprimer_client(user, &numero_client ,nom_supp, prenom_supp);

            supprimer_ligne_fichier(client_a_supp);

            break;
        }
        case 7:
            break;
        default:
            printf("Vous n'avez pas rentré de nombre correct \n");
            break;
        }
    } while (choix1 != 6);
}

void afficheModeGestion(){
    int choix = 0;
    printf("\n \nBienvenue à vous dans le mode gesition, tout d'abord voici la liste de nos produits avec les stocks les + bas : \n \n ");
    affiche_stock_bas(object,NOMBRE_MAX_OBJET);
    afficher_place_restante(object, NOMBRE_MAX_OBJET);
    do
    {
    printf("\n \nA vous s'offre maintenant plusieurs choix \n");
    printf("Tappez 1 pour connaitre le stock du produit que vous desirez \n");
    printf("Tappez 2 pour augmenter le stock d'un produit que vous desirez \n");
    printf("Tappez 3  pour basculer vers le mode achat \n");
    printf("Tappez 4 pour quitter l'interface \n");
    scanf("%d", &choix);

    switch (choix)
    {
    case 1:
        recherche_stock_produit(object, NOMBRE_MAX_OBJET);
        break;
    case 2:
        {
        unsigned long reference;
        printf("Entrez la reference du produit dont vous souhaitez augmenter le stock \n");
        scanf("%lu", &reference);
        produit px = augmenter_stock(object,NOMBRE_MAX_OBJET,reference);
        if(px.reference==-5){
            exit(1);
        }
        for(int i = 0; i < NOMBRE_MAX_CLIENT ; i++){
            if(strcmp(object[i].nom,px.nom)  == 0){
                object[i].quantite = px.quantite;
                break;
            }
        }
        ecrire_caracteristiques_produits(object);
        break;
        }
    case 3:
            affiche_mode_achat();
        break;
    case 4:
        break;
    default:
        printf("Vous n'avez pas saisi un nombre correct \n");
        break;
}

    } while (choix != 4);
    
}

void affiche_default(){
    printf("Vous n'avez pas entrer un chiffre correct \n.");
}

void affiche_message_entre(){
    printf("\n \nBienvenue dans notre magasin CY shop, souhaitez vous allez dans le mode achat ou le mode gestion ? \nTapez 1 pour le mode achat, et 2 pour le mode gestion \n\n");
}