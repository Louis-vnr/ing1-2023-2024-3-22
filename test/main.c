#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
void gotoligcol( int lig, int col ) {
    COORD mycoord;
    int x, y;
    mycoord.X = col;
    mycoord.Y = lig;
    int *plig = &y;
    int *pcol = &x;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), mycoord);
}
int main() {
    while (1) {
        FILE *fichier = NULL;
        int i, j;
        char carac;
        char carte[j][i];
        fichier = fopen("niveau.txt", "r");
        if (fichier == NULL) {
            printf("Impossible d'ouvrir le fichier");
        } else {
            for (j = 0; j < 10; j++) {
                for (i = 0; i < 20; i++) {
                    carac = fgetc(fichier);
                    carte[j][i] = carac;
                    printf("%c", carte[j][i]);
                }
            }
            fclose(fichier);
        }
        int col = 10;
        int lig= 5;
        int* plig= &lig;
        int* pcol= &col;
        char instruction;
        while(1)
        {
            gotoligcol(lig,col);
            printf("S");
            instruction = _getch();
            gotoligcol(lig,col);
            printf(" ");
            switch(instruction)
            {
                case 'H':
                    lig--;
                    break;
                case 'P':
                    lig++;
                    break;
                case 'M':
                    col++;
                    break;
                case 'K':
                    col--;
                    break;
            }

        }
    }
return 0;
}
