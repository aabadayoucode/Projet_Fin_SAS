#include <stdio.h>

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




int main () {
    int choix;

    do
    {
        choix=Menu();
        switch (choix)
        {
        case 1:
            printf("Hello !! \n");
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
