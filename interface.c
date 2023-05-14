#include "header.h"



void afficher_interface(){
    int nombre_produit, numero_produit;
    int rep;
    int rep1;
    int nbr_rajt;
    int nb_c = 0;
    int taille_produit = 0;
    int nbr_client_max = 50;

    
    printf("\n \n Bienvenue dans notre interface de gestion de produits : \n \n Notre liste de client a une capacité maximal de 50 clients. Nous pouvons stocker au sein du magasin un maximum de 300 taille. \n Pour rappel, un produit de taille grande a une taille de 4, \n un produit de taille moyenne a un etaille de 2 \n un produit de taille petite a une taille de 1 \n \n ");
    printf("Avez vous un compte client ? \n Tapez 1 si vous en avez deja un, sinon tapez 2 pour en creer un \n");
    scanf("%d", &rep1);
    switch (rep1)
    {
    case 1:
        {   
        char nom[50];
        char prenom[50];
        printf("Quelle sont vos nom et prenom ? \n");
        /// fonction recherchez client, si valeur retourné = 1, alors ecrire bienvenue [nom,prenom], sinon dire desolé on vous a pas trouvé dans notre base de donnée

        }
        break;
    case 2 :
        user[nb_c] = ajouter_client(user[nb_c]);
        break;
    default:
        break;

    printf("\n Avant toute chose, creons une liste de produits : \n \n \n");
    printf("Combien de produit voulez vous ajoutez ? \n");
    scanf("%d", &nombre_produit);
    }   

    for (int i = 0; i < nombre_produit; i++) {
        object[i] = ajouterproduit(object[i], i);
        switch (object[i].taille)
        {
        case 'P':
            taille_produit += 1;
            break;

        case 'M':
            taille_produit += 2;
            break;

        case 'G':
            taille_produit += 4;
            break;
        }
    }



    do
    {
        printf("A vous s'offre plusieurs choix \n \n \n");
        printf("Pour ajouter des produits, tapez 1 \n");
        printf("Pour modifier un produit tapez 2  \n");
        printf("Pour supprimer un produit, tapez 3\n");
        printf("Pour afficher la liste de produit, tapez 4 \n");
        printf("Pour afficher les stocks les plus bas, tapez 5 \n");
        printf("Pour recherchez un produit par sa reference ou son nom tapez 6 \n");
        printf("Pour ajouter un client, tapez 7 \n");
        printf("Pour modifier la fiche d'un client, tapez 8 \n");
        printf("Pour supprimer un client de la liste tapez 9 \n");
        printf("Pour quitter cet interface, tapez 10 \n \n \n");
        scanf("%d", &rep);

        switch (rep) {
            case 1:
                printf("Combien de produits voulez-vous rajoutez a la liste existante ? \n");
                scanf("%d", &nbr_rajt);
                for (int i = nombre_produit ; i < nbr_rajt + nombre_produit ; i++) {
                    object[i] = ajouterproduit(object[i], i);
                }
                nombre_produit+=nbr_rajt;
                break;
            
            case 2:
                {
                    unsigned long reference;
                    printf("Entrez la référence du produit que vous souhaitez modifier : \n");
                    scanf("%lu", &reference);
                    modifier_produit(object, nombre_produit, reference);
                }
                break;
            
            case 3:
                {
                    unsigned long reference;
                    printf("Entrez la référence du produit que vous souhaitez supprimer : \n");
                    scanf("%lu", &reference);
                    char t = supprimer_produit(object, &nombre_produit, reference);
                    
                    switch (t)
                        {
                        case 'P':
                            taille_produit -= 1;
                            break;

                        case 'M':
                            taille_produit -= 2;
                            break;

                        case 'G':
                            taille_produit -= 4;
                            break;
                        
                        default :
                            break;
                        }

                }
                break;
            
            case 4:
                afficher_tout_produits(object, nombre_produit);
                break;
            
            case 5:
                affiche_stock_bas(object,nombre_produit);
                break;
            
            case 6:
                recherche_produit(object,nombre_produit);
                break;
            
            case 7:
            nb_c ++;
            user[nb_c] = ajouter_client(user[nb_c]);
                break;

            case 8:
            {
                char nom[50];
                printf("Entrez le nom de la fiche client que vous souhaitez modifier : \n");
                scanf("%s", &nom);
                modifier_client(user, nbr_client_max, nom);
            }
                break;

            case 9:
            {
                char nom[50];
                printf("Entrez le nom de la fiche client que vous souhaitez supprimer : \n");
                scanf("%s", &nom);
                supprimer_client(user, &nbr_client_max, nom);
            }
                break;

            case 10:
                break;
    
            default:
                printf("Votre choix n'est pas correcte. \n");
                break;
            
        }

    } while (rep!=10);
    
}