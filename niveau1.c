#include "header.h"
#define LONGUEUR 10
#define LARGEUR 20

void niveau1(Snoopy *a) {
    struct Snoopy snoopy = {4, 8, a->vie, 0, 0, 0,1};
    struct Balle balle = {3, 3, 1, 1};
    float secondes=120;
    char matrice[LONGUEUR][LARGEUR];
    FILE *fichier = NULL;
    int x, y;
    char carac;
    fichier = fopen("test.txt", "r"); //On lit le fichier "test.txt"
    if (fichier == NULL) { //Si on ne trouve pas de fichier correspondant
        printf("Impossible d'ouvrir le fichier");
    } else {
        for (y = 0; y < 10; y++) { //Boucle allant de 0 à 9
            for (x = 0; x <= 20; x++) { //Boucle allant de 0 à 20
                carac = fgetc(fichier); //Le caractère lu dans le fichier .txt est stocké dans la variable carac
                matrice[y][x] = carac; //On met la variable carac dans le tableau matrice
                printf("%c", matrice[y][x]);  //On affiche ce qui est contenu dans la case visée du tableau matrice
            }
        }
        fclose(fichier); //On ferme le fichier txt
        printf("\nVie: %d",a->vie);
    }

    affichageSnoopy(snoopy); //On affiche Snoopy à sa position initale
    while (snoopy.mort != 1) { //TANT QUE snoopy n'est pas mort
        Sleep(200);//On met un temps de pause de 0.2 secondes
        secondes = chrono(secondes);
        gotoligcol(15,0);
        Color(15,0);
        printf("Temps restant: %f",secondes);
        effacerBalle(balle); //On efface la balle
        deplacementBalle(&balle, matrice); //On deplace la position de la balle
        affichageBalle(&balle, matrice); //On affiche la balle à sa nouvelle position
        if (collisionBalle(snoopy, balle)) {  //Si il y a une collision entre Snoopy et la balle
            snoopy.vie--;  //On enlève une vie à Snoopy
            snoopy.mort++;  // On passe la variable mort à 1
        }
        if(kbhit()){
            if(getch()=='q'){
                system("cls");
                AfficherMenu();
            }
        }
        if (deplacementSnoopy(&snoopy, matrice)) {  //Si on detecte une commande de deplacement
            affichageSnoopy(snoopy); //On affiche Snoopy à la nouvelle position
        }

        if (matrice[snoopy.y][snoopy.x] == 'X') {  //Si snoopy est positionné sur un piège
            snoopy.vie--;  //On enlève une vie à Snoopy
            system("cls"); //On efface l'ecran
            snoopy.mort++;  //On passe la variable mort de laa structure snoopy à 1
        }
        if(secondes<=0){

        }
        if (matrice[snoopy.y][snoopy.x] == 'F') {  //Si snoopy est positioné sur un F
            matrice[snoopy.y][snoopy.x] = ' ';  //On efface le f dans le tableau matrice en le remplacant par un espace.
            snoopy.oiseaux++;  //On rajoute un oiseau à snoopy
        }
        if (snoopy.oiseaux == 4) { //Si snoopy a ramassé 4 oiseaux
            system("cls");  //On efface l'ecran
            Color(15, 0);
            niveau2(&snoopy);
        }}
        if (snoopy.vie==0){
            system("cls");
            gameover();
        }
        if(snoopy.mort==1){
            system("cls");
            Color(15,0);
            printf(" Vous etes morts: -1 vie\n");
            printf("Voulez vous:\n1.Retourner au menu?\n2.Retenter le niveau 1");
            while(getch()!='1' || getch()!='2')
                switch (getch()) {
                    case '1':
                        system("cls");
                        AfficherMenu();
                        break;
                    case '2':
                        system("cls");
                        niveau1(&snoopy);
                        break;
            }
        }
    }
