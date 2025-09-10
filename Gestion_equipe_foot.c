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
    printf("2. Ajouter plusieur joueurs \n");
    printf("0. Quitez \n");
    printf("Donner voitre Choix: ");
    scanf("%d", &choixAjouter);
    getchar();

    return choixAjouter;
}

int MenuAfficher()
{
    int choixAfficher;

    printf("1. Affichier les joueurs par ordre alphabetique \n");
    printf("2. Affichier  les joueurs par age. \n");
    printf("3. Affichier les joueurs par poste. \n");
    printf("4. Affichier les joueurs par ID. \n");
    printf("0. Quitez \n");
    printf("Donner voitre Choix: ");
    scanf("%d", &choixAfficher);
    getchar();

    return choixAfficher;
}

int MenuRecherche()
{
    int choixRecherche;
    printf("1. Rechercher un joueur par Identifiant \n");
    printf("2. Rechercher un joueur par Nom \n");
    printf("0. Quitez \n");
    printf("Donner voitre Choix: ");
    scanf("%d", &choixRecherche);
    getchar();

    return choixRecherche;
}
struct Joueur
{
    int id, numeroMaillot, age, buts;
    char nom[MAX_CH], prenom[MAX_CH], poste[MAX_CH];
};

int idJ = 1;

int ajouterJoueur(struct Joueur J[], int nbrJoueur)
{

    if (nbrJoueur == MAX_N_J)
    {
        printf("L'equipe est complet !\n");
        return nbrJoueur;
    }
    else
    {

        J[nbrJoueur].id = idJ++;

        printf("Donner le nom: ");
        fgets(J[nbrJoueur].nom, MAX_CH, stdin);
        J[nbrJoueur].nom[strcspn(J[nbrJoueur].nom, "\n")] = '\0';

        printf("Donner le prenom: ");
        fgets(J[nbrJoueur].prenom, MAX_CH, stdin);
        J[nbrJoueur].prenom[strcspn(J[nbrJoueur].prenom, "\n")] = '\0';

        printf("Donner le poste: ");
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

void afficherJoueurRecherche(struct Joueur J[], int position, int nbrJoueur)
{
    if (position >= 0 && idJ <= nbrJoueur)
    {
        printf("Le Joueur rechercher est:\n");
        printf("Id:%d -le nom: %s-le prenom: %s -le poste: %s-age: %d ans -Numero Maillot: %d -Buts: %d \n",
        J[position].id, J[position].nom, J[position].prenom, J[position].poste, J[position].age, J[position].numeroMaillot, J[position].buts);
    }
    else
    {
        printf("Aucun Joueur avce ce id!!\n");
    }
}

struct Joueur *triParNom(struct Joueur J[], int nbrJoueur)
{

    struct Joueur Vtemp;
    if (nbrJoueur == 0)
    {
        printf("Aucun Joueur");
        return J;
    }
    else
    {
        for (int i = 0; i < nbrJoueur - 1; i++)
        {
            for (int k = i + 1; k < nbrJoueur; k++)
            {
                if (strcmp(J[i].nom, J[k].nom) > 0) // 97 - 98 = -1
                {
                    Vtemp = J[k];
                    J[k] = J[i];
                    J[i] = Vtemp;
                }
            }
        }
    }
    return J;
}

struct Joueur *triParAge(struct Joueur J[], int nbrJoueur)
{

    struct Joueur Vtemp;
    if (nbrJoueur == 0)
    {
        printf("Aucun Joueur");
        return J;
    }
    else
    {
        for (int i = 0; i < nbrJoueur - 1; i++)
        {
            for (int k = i + 1; k < nbrJoueur; k++)
            {
                if (J[i].age > J[k].age) // j[0]=17 > j[1]=15
                {
                    Vtemp = J[k]; // 15
                    J[k] = J[i];  // 17
                    J[i] = Vtemp; // 15
                }
            }
        }
    }
    return J;
}

struct Joueur *triParPoste(struct Joueur J[], int nbrJoueur)
{

    struct Joueur Vtemp;

    if (nbrJoueur == 0)
    {
        printf("Aucune Joueur dans cette equipe !!");
        return J;
    }
    else
    {

        for (int i = 0; i < nbrJoueur - 1; i++)
        {
            for (int z = i + 1; z < nbrJoueur; z++)
            {
                if (strcmp(J[i].poste, J[z].poste) > 0) // 97 98
                {
                    Vtemp = J[z];
                    J[z] = J[i];
                    J[i] = Vtemp;
                }
            }
        }
    }
    return J;
}

int rechercherParId(struct Joueur J[], int nbrJoueur)
{
    int idR;
    int existe = 0;
    printf("Donner l'id de Joueur: ");
    scanf("%d", &idR);
    getchar();

    for (int i = 0; i < nbrJoueur; i++)
    {

        if (idR == J[i].id)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int choix;
    //  int nbrJoueur = 0;
    //  struct Joueur Equipe[MAX_N_J];

    int nbrJoueur = 5;
    struct Joueur Equipe[MAX_N_J] = {
        {1, 10, 22, 575, "ABADA", "AZIZ", "Attaquant"},
        {2, 3, 25, 412, "ELKANDALI", "HAMZA", "Defenseur doit"},
        {3, 8, 20, 657, "ELIDLI", "YOUNES", "Milieu"},
        {4, 1, 28, 140, "CHERFOUNE", "MOHAMMED", "BGardien"},
        {5, 7, 23, 335, "JAMIA", "ISMAI", "Defenseur gouche"}};

    do
    {
        choix = Menu();
        int choixAjouter;
        int choixAfficher;
        int choixRecherche;
        int position;

        switch (choix)
        {
        case 1:
            do
            {
            choixAjouter = MenuAjouter();

            switch (choixAjouter)
            {
            case 1:
                nbrJoueur = ajouterJoueur(Equipe, nbrJoueur);
                break;
            case 2:
                nbrJoueur = ajouterPlusieursJoueur(Equipe, nbrJoueur);
                break;
            case 0:
                break;
            default:
                printf("Donner soit 1 soit 2 !! \n");
                break;
            }
            } while (choixAjouter != 0);

            break;
        case 2:
            do
            {
                choixAfficher = MenuAfficher();

            switch (choixAfficher)
            {
            case 1:
                printf("La liste des joueur trie par nom: ");
                afficherListeJoueur(triParNom(Equipe, nbrJoueur), nbrJoueur);
                break;
            case 2:
                printf("La liste des joueur trie par Age: ");
                afficherListeJoueur(triParAge(Equipe, nbrJoueur), nbrJoueur);
                break;
            case 3:
                printf("La liste des joueur trie par poste: ");
                afficherListeJoueur(triParPoste(Equipe, nbrJoueur), nbrJoueur);
                break;
            case 4:
                printf("La liste des joueur trie par id: ");
                afficherListeJoueur(Equipe, nbrJoueur);
                break;
            case 0:
                break;
            default:
                printf("Donner un choix entre 1 et 3 !! \n");
                break;
            }
            } while (choixAfficher != 0);
            
            break;
        case 3:
            printf("Modification!");
            break;
        case 4:
            printf("Supprition!");
            break;
        case 5:
            do
            {
                choixRecherche = MenuRecherche();

                switch (choixRecherche)
                {
                case 1:
                    position = rechercherParId(Equipe, nbrJoueur);
                    afficherJoueurRecherche(Equipe, position, nbrJoueur);
                    break;
                case 2:

                    break;
                case 0:
                    printf("0. Quitez \n");
                    break;
                default:
                    printf("Donner un choix entre 1 et 2 ou 0!! \n");
                    break;
                }

            } while (choixRecherche != 0);

            break;
        case 6:
            printf("Statistique!");
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