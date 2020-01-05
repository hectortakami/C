//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.7)

#include "stdio.h"

#include "stdio.h"

#include "stdio.h"

struct rectangle{
    int x;
    int y;
    int width;
    int height;
};

int StructRectangleContainsPoint(struct rectangle recA, int x, int y);

int main(){
    struct rectangle recA;
    scanf("%d%d%d%d", &recA.x, &recA.y, &recA.width, &recA.height);
    int x, y;
    scanf("%d%d", &x, &y);
    StructRectangleContainsPoint(recA, x, y);
    return 0;
}

int StructRectangleContainsPoint(struct rectangle recA, int x, int y){
    int flag = 1;
    if(x<recA.x || x>(recA.x+recA.width)){
        flag = 0;
    }
    if(y<recA.y || y>(recA.y+recA.height)){
        flag = 0;
    }
    printf("%d\n", flag);
    return 0;
}