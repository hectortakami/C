//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.7)

#include "stdio.h"

#include "stdio.h"

struct rectangle{
    int x;
    int y;
    int width;
    int height;
};

int StructRectangleUnion(struct rectangle recA, struct rectangle recB);

int main(){
    struct rectangle recA;
    struct rectangle recB;
    scanf("%d%d%d%d", &recA.x, &recA.y, &recA.width, &recA.height);
    scanf("%d%d%d%d", &recB.x, &recB.y, &recB.width, &recB.height);
    StructRectangleUnion(recA, recB);
    return 0;
}

int StructRectangleUnion(struct rectangle recA, struct rectangle recB){
    int arrX[4] = {recA.x, recB.x, recA.x+recA.width, recB.x+recB.width};
    int arrY[4] = {recA.y, recB.y, recA.y+recA.height, recB.y+recB.height};
    int i, j, tempX, tempY;
    for (i = 4-2; i >= 0; i--) {
        for(j=0;j<=i;j++){
            if(arrX[j]>arrX[j+1]){
                tempX = arrX[j];
                arrX[j] = arrX[j+1];
                arrX[j+1] = tempX;
            }
            if(arrY[j]>arrY[j+1]){
                tempY = arrY[j];
                arrY[j] = arrY[j+1];
                arrY[j+1] = tempY;
            }
        }
    }
    struct rectangle recC = {
        .x = recA.x>recB.x? recB.x: recA.x,
        .y = recA.y>recB.y? recB.y: recA.y,
        .width = arrX[3]-arrX[0],
        .height = arrY[3]-arrY[0]
    };
    printf("%d\n%d\n%d\n%d\n", recC.x, recC.y, recC.width, recC.height);
    return 0;
}