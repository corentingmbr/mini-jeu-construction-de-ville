#include <stdio.h>
#include <string.h>

const int GRID_SIZE = 10;

struct Building {
    int isBuilt;
    char buildingType[20];
};

struct Building grid[10][10];

void buildBuilding(int x, int y, const char* buildingType) {
    if (x >= 0 && x < GRID_SIZE && y >= 0 && y < GRID_SIZE) {
        grid[x][y].isBuilt = 1;
        strcpy(grid[x][y].buildingType, buildingType);
        printf("Bâtiment de type '%s' construit à la position (%d, %d).\n", grid[x][y].buildingType, x, y);
    } else {
        printf("Position invalide.\n");
    }
}

// Fonction pour afficher la grille complète
void displayGrid() {
    printf("\nGrille :\n");
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            if (grid[i][j].isBuilt) {
                printf("[%s] ", grid[i][j].buildingType);
            } else {
                printf("[ ] ");
            }
        }
        printf("\n");
    }
}

int main() {
    int choice, x, y;
    char buildingType[20];

    // Initialiser la grille avec des bâtiments non construits
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            grid[i][j].isBuilt = 0;
        }
    }

    // Menu pour permettre à l'utilisateur de jouer
    do {
        printf("\nMenu:\n");
        printf("1. Construire un bâtiment\n");
        printf("2. Afficher la grille complète\n");
        printf("0. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Entrez la position (x y) : ");
                if(scanf("%d %d", &x, &y) != 2) {
                    printf("Entrée invalide. Veuillez réessayer.\n");
                    break;
                }

                printf("Entrez le type de bâtiment : ");
                scanf("%s", buildingType);
                buildBuilding(x, y, buildingType);
                break;

            case 2:
                displayGrid();
                break;

            case 0:
                printf("Au revoir !\n");
                break;

            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choice != 0);

    return 0;
}
