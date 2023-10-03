#include <stdio.h>
#include <string.h>


struct Building{
    int isbuilt;
    char buildingType[20];
    int buildingid[];
};

struct Building grid[10][10];

void buildBuilding(int x, int y, char buildingType[]){
    if (x>=0 && x< 10 && y>=0 && y< 10 ){
        grid[x][y].isbuilt = 1;
        strcpy(grid[x][y].buildingType, buildingType);
        printf(" A type '%s' Buidling was built at (%d, %d).\n", grid[x][y].buildingType, x, y);
    }else{
        printf("Position was not found.\n");
    }

}
void displayGrid() {
    printf("\nGrid:\n");
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (grid[i][j].isbuilt) {
                printf("[%s] ", grid[i][j].buildingType);
            } else {
                printf("[ ] ");
            }
        }
        printf("\n");
    }}
void displaySteps(int maxId) {
    printf("\n Every steps of your Buildings :%d :\n", maxId);
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (grid[i][j].isbuilt && grid[i][j].buildingid <= maxId) {
                printf("[%s:%d] ", grid[i][j].buildingType, grid[i][j].buildingid);
            } else {
                printf("[ ] ");
            }
        }
        printf("\n");
    }

}
void getBuildingInfo(int x, int y) {
    if (x >= 0 && x < 10 && y >= 0 && y < 10) {
        if (grid[x][y].isbuilt) {
            printf("A Building from type '%s' was Built at: (%d, %d).\n", grid[x][y].buildingType, x, y);
        } else {
            printf("Theres not any Building at (%d, %d).\n", x, y);
        }
    } else {
        printf("Invalidated position.\n");
    }
}


int main(){
    int choice, x, y, maxid;
    char buildingType[20];
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            grid[i][j].isbuilt = 0;
        }
        printf("\nMenu:\n");
        printf("1. Build something\n");
        printf("2. Show Grid\n");
        printf("3. Show more informations\n");
        printf("0. Leave\n");
        printf("Choice : ");
        scanf("%d", &choice);

        if (choice == 1) {

            printf("Enter a position (x y) : ");
            if (scanf("%d %d", &x, &y) != 2) {

                printf("Error, Try again\n");
            }

            printf("Enter Building type : ");
            scanf("%s", buildingType);
            buildBuilding(x, y, buildingType);

        } else if (choice == 2) {
            displayGrid();
        }else if (choice == 3){

            printf("Enter the position (x y) for more informations : ");
            if(scanf("%d %d", &x, &y) != 2) {
                printf("Invalidated position\n");
            }

    }else if(choice == 0){
                printf("Ciao !\n");
            break;
        }else{
            printf("Invalidated Choice try again !\n");
        }




    }while(choice != 0);


    return 0;
}
