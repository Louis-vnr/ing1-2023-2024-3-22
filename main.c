#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>

int main() {
    int seconds = 120;

    while (seconds > 0) { // TANT QUE nombre de seconde > 0
        printf("Temps restant : %d secondes\n", seconds);// ECRIRE "Temps restant"
        sleep(1); // Ici, la fonction sleep permet d'attendre 1 seconde pour changer le timer a chaque fois
        seconds--; // Permet de descendre de 1s a chaque fois
        system("cls"); //Cette fonction permet de supprimer le temps montré par le chronometre a la seconde d'avant
    }

    printf("Temps écoulé !\n");//ECRIRE "Temps écoulé"

    return 0;
}