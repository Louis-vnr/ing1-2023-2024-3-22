#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <stdbool.h>
#include <unistd.h>
#define LONGUEUR 10
#define LARGEUR 20
void AfficherMenu();
void Color(int couleurDuTexte, int couleurDeFond);
void gotoligcol( int lig, int col );
typedef struct Snoopy{
    int x,y;
    int vie;
    int score;
    int oiseaux;
    int mort;
    int force;
}Snoopy;
struct Balle{
    int x,y,directionX,directionY;
};
void AfficherNiveau1();
void AfficherNiveau2();
void AfficherNiveau3();
void gameover();
bool pause();
bool collisionBalle(struct Snoopy snoopy,struct Balle balle);
void effacerBalle(struct Balle balle);
void affichageBalle(struct Balle *balle, char matrice [LONGUEUR][LARGEUR]);
void deplacementBalle(struct Balle *balle,char matrice[LONGUEUR][LARGEUR]);
bool deplacementSnoopy(struct Snoopy *snoopy,char matrice[LONGUEUR][LARGEUR]);
void affichageSnoopy(struct Snoopy snoopy);


void niveau1(Snoopy *a);
void niveau2(Snoopy *a);
void niveau3();

void sauvegarderPartie(char* nomSauvegarde,Snoopy *snoopy,char matrice [LONGUEUR][LARGEUR]);
float chrono(float secondes);
bool checkBlocCassable(Snoopy *snoopy,char matrice[LONGUEUR][LARGEUR]);