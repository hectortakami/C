//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.8)

#include "stdio.h"

typedef struct rectangle{
    int x;
    int y;
    int width;
    int height;
}rectangle;

int IntersectRectangles(struct rectangle *recA, struct rectangle *recB);

int main(){
    rectangle *recA = malloc(sizeof(rectangle));
    rectangle *recB = malloc(sizeof(rectangle));
    scanf("%d%d%d%d", &recA->x, &recA->y, &recA->width, &recA->height);
    scanf("%d%d%d%d", &recB->x, &recB->y, &recB->width, &recB->height);
    IntersectRectangles(recA, recB);
    free(recA);
    free(recB);
    return 0;
}

int IntersectRectangles(struct rectangle *recA, struct rectangle *recB){
    int arrX[4] = {(*recA).x, (*recB).x, (*recA).x+(*recA).width, (*recB).x+(*recB).width};
    int arrY[4] = {(*recA).y, (*recB).y, (*recA).y+(*recA).height, (*recB).y+(*recB).height};
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
        .x = (*recA).x>(*recB).x? (*recA).x: (*recB).x,
        .y = (*recA).y>(*recB).y? (*recA).y: (*recB).y,
        .width = arrX[2]-arrX[1],
        .height = arrY[2]-arrY[1]
    };
    printf("%d\n%d\n%d\n%d\n", recC.x, recC.y, recC.width, recC.height);
    return 0;
}