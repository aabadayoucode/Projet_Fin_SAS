#include <stdio.h>
#include <string.h>
#define MAX_T_CHAR 50

struct Joueur
{
    int id;
    char nom[MAX_T_CHAR], prenom[MAX_T_CHAR], poste[MAX_T_CHAR];
    int age,buts,numeroMaillot;

};

int Menu(){ 

    int choix;

    printf("\n========Menu=======\n");
    printf("1. Ajouter un joueur \n");
    printf("2. Afficher la liste des joueurs \n");
    printf("3. Modifier un joueur \n");
    printf("4. Supprimer un joueur \n");
    printf("5. Rechercher un joueur \n");
    printf("6. Statistiques \n");
    printf("7. Quitez le progremme \n");
    printf("\n=====Fin Menu======\n");
    printf("Donner votre choix: ");
    scanf("%d",&choix);
    getchar();

    return choix;
}

int ajouterJoueur(struct Joueur Joueurs[],int nbrJoueur){

    for (int i = 0; i < 5; i++)
    {   
        Joueurs[i].id = i+1;

        printf("Donner le nom: ");
        fgets(Joueurs[i].nom,MAX_T_CHAR,stdin);
        Joueurs[i].nom[strcspn(Joueurs[i].nom,"\n")]='\0';

        printf("Donner le prenom: ");
        fgets(Joueurs[i].prenom,MAX_T_CHAR,stdin);
        Joueurs[i].prenom[strcspn(Joueurs[i].prenom,"\n")]='\0';

        printf("Donner le numero Maillot: ");
        scanf("%d",Joueurs[i].numeroMaillot);
        getchar();

        printf("Donner le poste: ");
        fgets(Joueurs[i].poste,MAX_T_CHAR,stdin);
        Joueurs[i].poste[strcspn(Joueurs[i].poste,"\n")]='\0';

        printf("Donner l'age: ");
        scanf("%d",Joueurs[i].age);
        getchar();

        printf("Donner le nombre de buts: ");
        scanf("%d",Joueurs[i].buts);
        getchar();

    }
    


    return nbrJoueur;
}



int main () {
    int choix,nbrJoueur = 0;
    struct Joueur Joueurs[5];

    do
    {
        choix=Menu();
        switch (choix)
        {
        case 1:
            nbrJoueur = ajouterJoueur(Joueurs, nbrJoueur);

            break;
        case 7:
            printf("Au revoir !");
            break;
        default:
            printf("Il faut donner un choix entre 1 et 7 !! \n");
            break;
        }
        
    } while (choix != 7);
    


    return 0;
}
