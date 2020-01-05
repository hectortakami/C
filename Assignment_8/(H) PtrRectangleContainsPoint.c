//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.8)

#include "stdio.h"

#include "stdio.h"

#include "stdio.h"

typedef struct rectangle{
    int x;
    int y;
    int width;
    int height;
}rectangle;

int StructRectangleContainsPoint(struct rectangle *recA, int x, int y);

int main(){
    rectangle *ptrRectangle = malloc(sizeof(rectangle));
    
    scanf("%d%d%d%d",&ptrRectangle->x, &ptrRectangle->y, &ptrRectangle->width, &ptrRectangle->height);
    
    int x, y;
    scanf("%d%d", &x, &y);
    StructRectangleContainsPoint(ptrRectangle, x, y);
    
    free(ptrRectangle);
    return 0;
}

int StructRectangleContainsPoint(struct rectangle *recA, int x, int y){
    
    int flag = 1;
    if(x<(*recA).x || x>((*recA).x+(*recA).width)){
        flag = 0;
    }
    if(y<(*recA).y || y>((*recA).y+(*recA).height)){
        flag = 0;
    }
    printf("%d\n", flag);
    return 0;
}