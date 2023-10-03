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


int main(){
    int choice, x, y, maxid;
    char buildingType[20];
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            grid[i][j].isbuilt = 0;
        }
    }



    printf("Hello, World!\n");
    return 0;
}
