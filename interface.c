#include "header.h"

float prix_total = 0 ;
int numero_client = 2;
int numero_achat = 0;

void affiche_mode_achat(){
    int numero_actuelle_client = 0;
    int choix, choix1;
    
    
    int verif = 0;
   
    printf("\nAvez vous un compte client ? \n1 pour oui \n2 pour non \n \n");
    scanf("%d", &choix);
    switch (choix)
    {
    case 1:                 //verification de si l'utilisateur a un compte client, si non alors on en crée un, si oui on verifie et on affiche ses 3 derniers achats
    {
        char nom[50];
        char prenom[50];
        printf("\nEntrez votre nom, puis votre prénom. Attention ne mettez pas d'accent. Et respectez les majuscules en debut de nom/prénom. \n");
        scanf("%s", nom);
        scanf("%s", prenom);
        rechercher_client(user, nom, prenom);
        int var = trouver_position_client(nom, prenom);
        afficher3DerniersAchats(user[var]);
        break;
    }
    case 2:
        printf("\nNous allons vous créer un compte client \n\n");
        user[numero_client] = ajouter_client(user[numero_client]);
        printf("Bienvenue %s %s \n\n", user[numero_client].nom, user[numero_client].prenom);
        ecrire_client(user[numero_client].nom, user[numero_client].prenom);
        numero_client ++;
        break;

    default:
        affiche_default();
        return;
    }
    choix1 = 0;

    do
    {
        printf("\nTapez 1 pour rechercher un produit et l'acheter \n");
        printf("Tapez 2 pour afficher le prix total \n");
        printf("Tapez 3 pour basculer vers le mode gestion \n");
        printf("Tapez 4 pour ajouter un client à la liste \n");
        printf("Tapez 5 pour afficher la liste complète de produit \n");
        printf("Tapez 6 si vous souhaitez vous désinscrire de notre magasin \n");
        printf("Tapez 7 pour finaliser l'achat \n");
        printf("Tapez 8 pour afficher vos 3 derniers achats \n");
        printf("Tapez 9 pour quitter l'interface \n \n");

        scanf("%d", &choix1);
        switch (choix1)
        {
        case 1:
        {
            int choix_achat = 0;
            produit p1 = trouver_produit(object, NOMBRE_MAX_OBJET);
            if(p1.quantite == -5){                              //verifie si le produit retourné est le produit poubelle, si c'est le cas alors on quitte le code
                exit(1);
            }
            if(p1.quantite == 0){
                printf("Nous sommes desolé mais ce produit est en rupture de stock \n");
                exit(1);
            }

            printf("\nVoulez vous acheter le produit suivant : %s ?\n", p1.nom);
            printf("Tapez 1 pour oui, 2 pour non \n");
            scanf("%d", &choix_achat);
            switch (choix_achat)
            {
            case 1:       
                p1.quantite -= 1;           //achat du produit, diminue la quantité de 1 et augmente le prix du prix total, affecte ensuite la valeurs du produit acheté au produit dans le tableau
                prix_total += p1.prix;
                for(int i = 0; i < NOMBRE_MAX_OBJET ; i++){
                    if(strcmp(object[i].nom,p1.nom)  == 0){
                        object[i].quantite = p1.quantite;
                        break;
                    }
                }
                char nom[50];
                char prenom[50];
                printf("\nEntrez votre nom, puis votre prénom. Attention ne mettez pas d'accent. Et respectez les majuscules en début de nom/prénom. \n");
                scanf("%s", nom);
                scanf("%s", prenom);
                numero_actuelle_client = trouver_position_client(nom, prenom);
                strcpy(user[numero_actuelle_client].historique_achats[numero_achat].nom, p1.nom);   //rempli l'historique d'achat
                ecrire_caracteristiques_produits(object);                                           //modifie le fichier produit.txt en fonction des achats
                numero_achat ++;
                printf("\nVous avez acheté le produit avec succès \n");
                break;
            case 2:  
                break;
            default:
                affiche_default();
                exit(1);
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
                printf("Vous avez depassé la limite maximale d'utilisateur \n");
                return;
            }
            else{
                user[numero_client] = ajouter_client(user[numero_client]);                              //ajoute le client numero 'numero_client'
                printf("Bienvenue %s %s \n \n", user[numero_client].nom, user[numero_client].prenom);
                ecrire_client(user[numero_client].nom, user[numero_client].prenom);
                numero_client ++;

            }
            break;
        case 5:
            for(int i = 0 ; i < NOMBRE_MAX_OBJET ; i++){
                printf("Nom : %s / Stock restant : %d / Prix : %.2f euros / Numéro de référence : %lu\n",object[i].nom,object[i].quantite,object[i].prix,object[i].reference);
            }
            break;
        case 6:
        {
            char nom_supp[25];
            char prenom_supp [25];

            printf("Entrez votre Nom : \n");
            scanf("%s", nom_supp);
            printf("Entrez maintenant votre prénom \n");
            scanf("%s", prenom_supp);
            int client_a_supp = supprimer_client(user, &numero_client ,nom_supp, prenom_supp);
            supprimer_ligne_fichier(client_a_supp);     //supprime le client du fichier (marche que sur linux)
            lire_client();                              //stock les informations du fichier dans le tableau de client, car la fonction 'supprimer_client' 
                                                        //ne supprime ,pas reellement un client, elle les decales vers la droite

            break;

        }
        case 7:
            printf("Vous avez payé %.2f € \n", prix_total);
            prix_total=0;
            break;
        case 8:
        {
        char nom[50];
        char prenom[50];
        printf("\nEntrez votre nom, puis votre prénom. Attention ne mettez pas d'accent. Et respectez les majuscules en debut de nom/prénom. \n");
        scanf("%s", nom);
        scanf("%s", prenom);
        rechercher_client(user, nom, prenom);
        int var = trouver_position_client(nom, prenom);         //cherche la position du client dans le fichier et renvoie cette position
        afficher3DerniersAchats(user[var]);                     //affiche l'historique d'achat du client numero 'var' (var= position)
            break;
        }
        case 9:
            break;
        default:
            affiche_default();
            return;
        }
    } while (choix1 != 9);
}

void afficheModeGestion(){
    int choix = 0;
    printf("\n \nBienvenue à vous dans le mode gestion \n \n");
    affiche_stock_bas(object,NOMBRE_MAX_OBJET);
    int place_actuelle = afficher_place_restante(object, NOMBRE_MAX_OBJET);
    do
    {
    printf("\n \nA vous s'offre maintenant plusieurs choix \n");
    printf("Tappez 1 pour connaître le stock du produit que vous désirez \n");
    printf("Tappez 2 pour augmenter le stock d'un produit que vous désirez \n");
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
            printf("Entrez la référence du produit dont vous souhaitez augmenter le stock \n");
            scanf("%lu", &reference);
            produit px = augmenter_stock(object,NOMBRE_MAX_OBJET,reference, place_actuelle);
            if(px.reference==-5){       //verifie si le produit retourné est le produit poubelle, si c'est le cas alors on quitte le programme
                exit(1);
            }
            for(int i = 0; i < NOMBRE_MAX_CLIENT ; i++){
                if(strcmp(object[i].nom,px.nom)  == 0){
                    object[i].quantite = px.quantite;               //met a jour le tableau avec la nouvelle quantité de stock
                    break;
                }
            }
            ecrire_caracteristiques_produits(object);               //met a jour le fichier produit.txt
            break;
            }
        case 3:
                affiche_mode_achat();
            break;
        case 4:
            break;
        default:
            affiche_default();
            return;
        }

    } while (choix != 4);
    
}

void affiche_default(){
    printf("Vous n'avez pas entrer un chiffre correct \n.");
}

void affiche_message_entre(){
    printf("\n \nBienvenue dans notre magasin CY shop, souhaitez vous allez dans le mode achat ou le mode gestion ? \nTapez 1 pour le mode achat, et 2 pour le mode gestion \n\n");
}