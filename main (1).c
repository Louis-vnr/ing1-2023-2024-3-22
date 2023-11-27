#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
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
int main() {
    printf("Snoopy's Magic Show\n");
    Color(12, 0);
    return 0;
}