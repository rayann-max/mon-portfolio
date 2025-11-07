#include <stdio.h>
typedef struct {
    int numéro ;
    char nom[30];
    char prénom[30];
    int jour;
    int mois;
    int année;
} Etudiant;
Etudiant tab[1500];
void enregistre_etu(int n,int m) {
    printf("Nombre d'étudiants a enregistré\t");
    scanf("%d",&n);
    if (n>0) {
        for (int i=0; i<n; i++) {
            printf("\tINFOS DE L'ÉTUDIANT %d:\n",i+1);
            printf("son numéro :\t");
            scanf("%d",&tab[i].numéro);
            printf("son nom :\t");
            scanf("%s",tab[i].nom);
            printf("son prénom :\t");
            scanf("%s",tab[i].prénom);
            printf("DATE DE NAISSANCE \n");
            printf("jour: \t");
            scanf("%d",&tab[i].jour);
            if(tab[i].jour<=31 && tab[i].jour>0) {
                printf("mois:\t");
                scanf("%d",&tab[i].mois);
                if(tab[i].mois<=12 && tab[i].mois>0) {
                    printf("année:\t");
                    scanf("%d",&tab[i].année);
                    if(1000<tab[i].année && tab[i].année<9999 ) {
                        printf("Entrer le nombre de notes a ajouter pour cet étudiant\t");
                        scanf("%d",&m);
                        int note[m];
                        for (int i=0; i<m; i++) {
                            printf("entrer la note %d\t",i+1);
                            scanf("%d",&note[i]);
                        }
                        printf(".....AFFICHAGE DES ÉTUDIANTS INSCRITS.......\n");
                        for (int i=0; i<n; i++) {
                            printf("ÉTUDIANT %d\n",i+1);
                            printf("NUMÉRO:%d\nNOM:%s\nPRENOM:%s\n",tab[i]. numéro,tab[i].nom,tab[i].prénom);
                            printf("DATE DE NAISSANCE\n");
                            printf("JOUR:%d\nMOIS:%d\nANNEE:%d\n",tab[i].jour,tab[i].mois,tab[i].année);
                        }
                    } else {
                        printf("ENTRER UN FORMAT D'ANNÉE CORRECT\n");
                    }
                } else {
                    printf("ENTRER UN MOIS COMPRIS ENTRE 1 ET 12 \n");
                }
            } else {
                printf("ENTRER UN JOUR COMPRIS ENTRE 1 ET 31\n");
            }
        }
    }
    else if (n<0) {
        printf("\t ERREUR ENTRER UN NOMBRE POSITIF \n");
    } else {
        printf("\tAUCUN ÉTUDIANTS A AJOUTER");
    }

}
int main() {
    int a,b;
    Etudiant t[1500];
    enregistre_etu(a,b);
    return 0;
}
    