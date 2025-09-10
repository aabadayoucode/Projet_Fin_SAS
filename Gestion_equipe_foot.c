#include <stdio.h>
#include <string.h>

#define MAX_N_J 5
#define MAX_CH 50

int Menu()
{

    int choix;

    printf("\n========Menu========\n");
    printf("1. Ajouter un joueur \n");
    printf("2. Afficher la liste des joueurs \n");
    printf("3. Modifier un joueur \n");
    printf("4. Supprimer un joueur \n");
    printf("5. Rechercher un joueur \n");
    printf("6. Statistiques \n");
    printf("7. Quitez \n");
    printf("======Fin Menu========\n");
    printf("Donner voitre Choix: ");
    scanf("%d", &choix);
    getchar();

    return choix;
}

int MenuAjouter()
{
    int choixAjouter;

    printf("1. Ajouter un nouveau joueur \n");
    printf("2. Ajouter plusieurs joueurs \n");

    printf("Donner voitre Choix: ");
    scanf("%d", &choixAjouter);
    getchar();

    return choixAjouter;
}

int MenuAfficher()
{
    int choixAfficher;

    printf("1. Affichier les Trier joueurs par ordre alphabetique \n");
    printf("2. Affichier  les joueurs Trier par âge. \n");
    printf("2. Affichier Afficher les joueurs Trier par poste. \n");
    printf("Donner voitre Choix: ");
    scanf("%d", &choixAfficher);
    getchar();

    return choixAfficher;
}

struct Joueur
{
    int id, numeroMaillot, age, buts;
    char nom[MAX_CH], prenom[MAX_CH], poste[MAX_CH];
};

int ajouterJoueur(struct Joueur J[], int nbrJoueur)
{

    if (nbrJoueur == MAX_N_J)
    {
        printf("L'equipe est complet !\n");
        return nbrJoueur;
    }
    else
    {

        J[nbrJoueur].id = nbrJoueur + 1;

        printf("Donner le nom: ");
        fgets(J[nbrJoueur].nom, MAX_CH, stdin);
        J[nbrJoueur].nom[strcspn(J[nbrJoueur].nom, "\n")] = '\0';

        printf("Donner le prenom: ");
        fgets(J[nbrJoueur].prenom, MAX_CH, stdin);
        J[nbrJoueur].prenom[strcspn(J[nbrJoueur].prenom, "\n")] = '\0';

        printf("Donner le post: ");
        fgets(J[nbrJoueur].poste, MAX_CH, stdin);
        J[nbrJoueur].poste[strcspn(J[nbrJoueur].poste, "\n")] = '\0';

        printf("Donner l'age: ");
        scanf("%d", &J[nbrJoueur].age);
        getchar();

        printf("Donner nombre buts: ");
        scanf("%d", &J[nbrJoueur].buts);
        getchar();

        printf("Donner le numero Maillot: ");
        scanf("%d", &J[nbrJoueur].numeroMaillot);
        getchar();

        printf("Le joueur a ete ajouter avec succes ! \n");
        nbrJoueur += 1;
    }
    return nbrJoueur;
}

int ajouterPlusieursJoueur(struct Joueur J[], int nbrJoueur)
{

    int nbrJ;
    printf("Donner le nombre des joueur que vous voulez ajouter: ");
    scanf("%d", &nbrJ);
    getchar();

    if (nbrJ >= MAX_N_J)
    {
        printf("L'equipe est complet !! \n");
        return nbrJoueur;
    }
    else
    {
        for (int i = 0; i < nbrJ; i++)
        {
           nbrJoueur = ajouterJoueur(J, nbrJoueur);
            
        }
        return nbrJoueur;
    }
}

void afficherListeJoueur(struct Joueur J[], int nbrJoueur)
{
    printf("\n=======Liste des joueur ======\n");
    if (nbrJoueur != 0)
    {
        for (int i = 0; i < nbrJoueur; i++)
        {
            printf("Id:%d  -le nom: %s-le prenom: %s -le poste: %s-age: %d ans -Numero Maillot: %d -Buts: %d \n", J[i].id, J[i].nom, J[i].prenom, J[i].poste, J[i].age, J[i].numeroMaillot, J[i].buts);
        }
    }
    else
    {
        printf("Aucun Joueur a ete ajouter !!\n");
    }

    printf("==========Fin Liste==========\n");
}

int main()
{
    int choix, nbrJoueur = 0;
    struct Joueur Joueurs[5];

    do
    {
        choix = Menu();
        int choixAjouter;
        int choixAfficher;

        switch (choix)
        {
        case 1:

            choixAjouter = MenuAjouter();

            switch (choixAjouter)
            {
            case 1:
                nbrJoueur = ajouterJoueur(Joueurs, nbrJoueur);
                break;
            case 2:
                nbrJoueur = ajouterPlusieursJoueur(Joueurs, nbrJoueur);
                break;
            default:
                printf("Donner soit 1 soit 2 !! \n");
                break;
            }

            break;
        case 2:
            choixAfficher = MenuAfficher();

            switch (choixAfficher)
            {
            case 1:
                afficherListeJoueur(Joueurs, nbrJoueur);
                break;
            case 2:
                printf("le tri par age \n");
                break;
            case 3:
                printf("le tri par poste \n");
                break;
            
            default:
                printf("Donner un choix entre 1 et 3 !! \n");
                break;
            }


            break;
        case 7:
            printf("Au revoir!");
            break;
        default:
            printf("Il faut donner un choix entre 1 et 7 !!!\n");
            break;
        }

    } while (choix != 7);

    return 0;
}