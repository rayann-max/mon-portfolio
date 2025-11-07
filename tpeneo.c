#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAXIS 100
#define MAX_CLIENTS 5

typedef struct {
    char marque[30];
    char imma[30];
    char couleur[20];
    char point[20];
    char statut[10];
    int itineraire ;
    int place;
} taxi;
typedef struct {
    char départ[20];
    char arrive [20];
} trajet;
typedef struct {
    char nom[30];
    char id[20];
    char depart[20];
    char desti[20];
    char heure[10];
    int place ;
    trajet trajet[];
} client;

// Fonctions d'enregistrement
void afficher_itineraire() {
    printf("ITINÉRAIRE 1 : NKOLBISSON--->CARREFOUR MEQUE--->MOKOLO--->MELEN--->CHATEAU\n");
    printf("ITINÉRAIRE 2 : MOLOKO---->CARREFOUR MEQUE--->MARCHE OYOM-ABANG--->NKOLBISSON\n");
    printf("ITINÉRAIRE 3 : NKOABANG--->ESSOS--->POSTE CENTRAE--->CHATEAU\n");
    printf("ITINÉRAIRE 4 : NKOABANG--->TERMINUS MIMBOMAN--->POSTE CENTRAE--->MOKOLO\n");
    printf("ITINÉRAIRE 5 : CHÂTEAU--->POSTE CENTRAE--->NOUVELLE ROUTE BASTOS--->MESSASSI\n");
}
void enregistrer_taxi(taxi *tab, int *nb_taxi) {
    if (*nb_taxi >= MAX_TAXIS) {
        printf("Limite de taxis atteinte.\n");
        return;
    }
    printf("\n===== ENREGISTRER UN TAXI =====\n");
    printf("MARQUE : ");
    scanf("%s", tab[*nb_taxi].marque);
    printf("IMMATRICULATION : ");
    scanf("%s", tab[*nb_taxi].imma);
    printf("COULEUR : ");
    scanf("%s", tab[*nb_taxi].couleur);
    printf("CARPOINT : ");
    scanf("%s", tab[*nb_taxi].point);
    printf("NOMBRE DE PLACES RESTANTES :");
    scanf("%d",&tab[*nb_taxi].place);
    printf("STATUT (libre/occuper) : ");
    scanf("%s", tab[*nb_taxi].statut);
    printf("Voici une liste d'itinéraire veuillez en choisir celui que vous allez emprunter\n");
    afficher_itineraire();
    printf("Entrer l'itinéraire \n");
    scanf("%d",&tab[*nb_taxi].itineraire);
    (*nb_taxi)++;
    printf("Taxi enregistré avec succès !\n");
}

void enregistrer_client(client *tab, int *nb_client) {
    if (*nb_client >= MAX_CLIENTS) {
        printf("Limite de clients atteinte.\n");
        return;
    }
    printf("\n===== ENREGISTRER UN CLIENT =====\n");
    printf("NOM : ");
    scanf("%s", tab[*nb_client].nom);
    printf("IDENTIFIANT : ");
    scanf("%s", tab[*nb_client].id);
    printf("LIEU DE DEPART :");
    scanf("%s", tab[*nb_client].trajet[*nb_client].départ);
    printf("LIEU D'ARRIVER  :");
    scanf("%s", tab[*nb_client].trajet[*nb_client]. arrive);
    printf("HEURE DE DEPART : ");
    scanf("%s", tab[*nb_client].heure);
    printf("NOMBRE DE PLACE :");
    scanf("%d",&tab[*nb_client].place);
    (*nb_client)++;
    printf("Client enregistré avec succès !\n");
}

// Fonctions d'affichage
void afficher_taxis(taxi *tab, int nb_taxi) {
    if (nb_taxi == 0) {
        printf("Aucun taxi enregistré.\n");
        return;
    }
    printf("\n===== LISTE DES TAXIS =====\n");
    for (int i = 0; i < nb_taxi; i++) {
        printf("TAXI %d:\n", i + 1);
        printf("  MARQUE : %s\n", tab[i].marque);
        printf("  IMMATRICULATION : %s\n", tab[i].imma);
        printf("  COULEUR : %s\n", tab[i].couleur);
        printf("  CARPOINT : %s\n", tab[i].point);
        printf(" PLACES RESTANTES :%d\n",tab[i].place);
        printf("  STATUT : %s\n=", tab[i].statut);
        printf(" ITINÉRAIRE :%s\n",tab[i].itineraire);
    }
}

void afficher_clients(client *tab, int nb_client) {
    if (nb_client == 0) {
        printf("Aucun client enregistré.\n");
        return;
    }
    printf("\n===== LISTE DES CLIENTS =====\n");
    for (int i = 0; i < nb_client; i++) {
        printf("CLIENT %d:\n", i + 1);
        printf("  NOM : %s\n", tab[i].nom);
        printf("  IDENTIFIANT : %s\n", tab[i].id);
        printf("  TRAJET : %s--->%s\n", tab[i].trajet[i].départ,tab[i].trajet[i].arrive);
        printf("  HEURE : %s\n\n", tab[i].heure);
        printf("  NOMBRE DE PLACES :%d",tab[i].place);
    }
}

void prendre_taxi(client *tab, int *nb_client,int choix,taxi *t,int *nb_taxi,int n) {
    printf("BIENVENUE 😊 VEUILLEZ ENTRER VOUS INFORMATIONS POUR PASSER UNE COMMANDE \n");
    enregistrer_client(tab,nb_client);
    printf("Voici une liste d'itinéraire veuillez en choisir 1\n");
    afficher_itineraire();
    printf("Choisissez votre itinéraire \n");
    printf("itinéraire : \t");
    scanf("%d",&choix);
    printf("vous avez choisi l'itinéraire %d\n",choix);
    if(choix==1) {
        printf("ITINÉRAIRE 1 : NKOLBISSON--->CARREFOUR MEQUE--->MOKOLO--->MELEN--->CHATEAU\n");
    } else if(choix==2) {
        printf("ITINÉRAIRE 2 : MOLOKO---->CARREFOUR MEQUE--->MARCHE OYOM-ABANG--->NKOLBISSON\n");
    } else if(choix==3){
        printf("ITINÉRAIRE 3 : NKOABANG--->ESSOS--->POSTE CENTRAE--->CHATEAU\n");
    } else if(choix==4) {
        printf("ITINÉRAIRE 4 : NKOABANG--->TERMINUS MIMBOMAN--->POSTE CENTRAE--->MOKOLO\n");
    } else if(choix==5) {
        printf("ITINÉRAIRE 5 : CHÂTEAU--->POSTE CENTRAE--->NOUVELLE ROUTE BASTOS--->MESSASSI\n");
    } else {
        printf("AUCUN ITINÉRAIRE CORRESPONDANT \n");
    }
    int trouve = 0;
    if (choix < 1 || choix > 5) {
        printf("Itinéraire invalide.\n");
        return;
    }

    printf("\nTaxis pour l'itinéraire %d :\n", choix);
    for (int i = 0; i < nb_taxi; i++) {
        if (t[i].itineraire == choix ) {
            printf("Taxi %d : %s, %s, %s, %s, %s\n", i + 1,
                   t[i].marque, t[i].imma, t[i].couleur,
                   t[i].point, t[i].statut);
            trouve = 1;
        }
    }

    if (!trouve) {
        printf("Aucun taxi trouvé pour cet itinéraire.\n");
    }
    printf("choisissez votre taxi\n");
    scanf("%d",&n);

}
// Fonction principale avec menu
int main() {
    taxi tab_taxi[MAX_TAXIS];
    client tab_client[MAX_CLIENTS];
    int nb_taxi = 0, nb_client = 0;
    int choix,a;

    do {
        printf("\n===== MENU DE GESTION =====\n");
        printf("|1. Enregistrer un taxi\n");
        printf("|2. Enregistrer un client\n");
        printf("|3. Afficher tous les taxis\n");
        printf("|4. Afficher tous les clients\n");
        printf("|5. Afficher les différents itinéraire\n");
        printf("|6. Passer une commande\n");
        printf("|0. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);

        switch (choix) {
        case 1:
            enregistrer_taxi(tab_taxi, &nb_taxi);
            break;
        case 2:
            enregistrer_client(tab_client, &nb_client);
            break;
        case 3:
            afficher_taxis(tab_taxi, nb_taxi);
            break;
        case 4:
            afficher_clients(tab_client, nb_client);
            break;
        case 5:
            afficher_itineraire();
            break;
        case 6:
            prendre_taxi(tab_client,&nb_client,choix,tab_taxi,&nb_taxi,a);
            break;
        case 0:
            printf("Fermeture du programme...\n");
            break;
        default:
            printf("Choix invalide, veuillez réessayer.\n");
        }
    } while (choix != 0);

    return 0;
}
    