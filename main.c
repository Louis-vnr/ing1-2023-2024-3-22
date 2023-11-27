#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>
#include <conio.h>

/////////// PROTOTYPES DES SOUS-PROGRAMMES
void Color(int couleurDuTexte,int couleurDeFond);

///////////////////////////////////////
// Nom du sous-programme : COLOR
// Rôle : change la couleur du texte dans la console, ainsi que la couleur du fond pour la ligne
// Compatibilité : windows XP
///////////////////////////////////////
void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

void AfficherMenu(){
    Color(12, 0);
    printf(" ________  ________   ________  ________  ________  ___    ___      ________  ________  _____ ______   _______      \n"
           "|\\   ____\\|\\   ___  \\|\\   __  \\|\\   __  \\|\\   __  \\|\\  \\  /  /|    |\\   ____\\|\\   __  \\|\\   _ \\  _   \\|\\  ___ \\     \n"
           "\\ \\  \\___|\\ \\  \\\\ \\  \\ \\  \\|\\  \\ \\  \\|\\  \\ \\  \\|\\  \\ \\  \\/  / /    \\ \\  \\___|\\ \\  \\|\\  \\ \\  \\\\\\__\\ \\  \\ \\   __/|    \n"
           " \\ \\_____  \\ \\  \\\\ \\  \\ \\  \\\\\\  \\ \\  \\\\\\  \\ \\   ____\\ \\    / /      \\ \\  \\  __\\ \\   __  \\ \\  \\\\|__| \\  \\ \\  \\_|/__  \n"
           "  \\|____|\\  \\ \\  \\\\ \\  \\ \\  \\\\\\  \\ \\  \\\\\\  \\ \\  \\___|\\/  /  /        \\ \\  \\|\\  \\ \\  \\ \\  \\ \\  \\    \\ \\  \\ \\  \\_|\\ \\ \n"
           "    ____\\_\\  \\ \\__\\\\ \\__\\ \\_______\\ \\_______\\ \\__\\ __/  / /           \\ \\_______\\ \\__\\ \\__\\ \\__\\    \\ \\__\\ \\_______\\\n"
           "   |\\_________\\|__| \\|__|\\|_______|\\|_______|\\|__||\\___/ /             \\|_______|\\|__|\\|__|\\|__|     \\|__|\\|_______|\n"
           "   \\|_________|                                   \\|___|/                                                           \n"
           "      ");
    printf("By Alexis, Valentin, Gaspard, Louis\n\n\n");
    Color(15, 0);
    printf("1. Regles du jeu (affichees a l'ecran)\n"
           "2. Lancer un nouveau Jeu a partir du niveau 1\n"
           "3. Charger une partie\n"
           "4. Mot de passe\n"
           "5. Scores\n"
           "6. Quitter\n");
    switch(getch()){ //
        case '1' :
            system("cls");
            Color(12, 0);
            printf("Les regles du jeu sont:\n\n");
            Color(15, 0);
            printf("1- Snoopy ne se deplace que a l'horizontale ou a la verticale.\n");
            printf("2- Pour finir un niveau, Snoppy doit avoir recupere les 4 Woodstock (oiseau accompagnant snoopy) dans un temps imparti.\n");
            printf("3- Si Snoopy est touche la balle ou par les pieges/enemis, alors le niveau est perdu.\n");
            printf("4- Si vous appuyez sur la lettre q, vous revenez au menu\n");
            if(getch()== 'q'){
                system("cls");
                AfficherMenu();
            }
            break;
        case '2' :

            break;
        case'3' :

            break;
        case'4' :/*
            char MotDePasse1[10] = "motdepasse1";
            char MotDePasse2[] = "motdepasse2";
            char MotDePasse3[] = "motdepasse3";
            char saisieUtilisateur[100]; // chaine qui permet de stocker l'entrée de l'utilisateur

            printf("Veuillez entrer un mot de passe : ");
            scanf("%s", saisieUtilisateur);

            if(strcmp(saisieUtilisateur, Motdepasse1)== 0){
                printf("Acces autorise!");
                sleep(1);
                AfficherNiveau1();
            }
            else if(strcmp(saisieUtilisateur, MotDePasse2)== 0) {
                printf("Acces autorise!");
                sleep(1);
                AfficherNiveau2();
            }
            else if(strcmp(saisieUtilisateur, MotDePasse3)== 0){
                printf("Acces autorise!");
                sleep(1);
                AfficherNiveau3();
            else{
                    printf("Ce mot de passe est incorrect. Acces refuse. \n");
                }
            break;*/
        case'5' :

            break;
        case'6' :
                printf("\n\nEtes vous sur de vouloir quitter le jeu?\n 1.Oui \n 2.Non\n");
                switch(getch()){
                    case '1' :
                        exit(0);
                        break;
                    case '2' :
                        system("cls");
                        AfficherMenu();
                        break;

            }


            break;
    }

    sleep(5000000);
}
int main() {
    AfficherMenu();
    if(getch == 'q') {
        system("cls");
        AfficherMenu();

    }
    return 0;
}
