#include <stdio.h>
#include <string.h>


struct Building{
    int isbuilt;
    char buildingType[20];
    int buildingid[];
};

struct Building grid[10][10];

void buildBuilding(int x, int y, char buildingType[]){
    if (x>=0 && x=< 10 && y>=0 && y=< 10 ){
        grid[x][y].isbuilt = 1;
        strcpy(grid[x][y].buildingType, buildingType);
        printf(" A type '%s' Buidling was built at (%d, %d).\n", grid[x][y].buildingType, x, y);
    }else{
        printf("Position was not found.\n");
    }

}


int main() {



    printf("Hello, World!\n");
    return 0;
}
