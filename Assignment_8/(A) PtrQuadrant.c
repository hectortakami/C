//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.8)


#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct Point{
    int x;
    int y;
} Point;
 
int structQuadrant (struct Point *point)
{
    int coorX = (*point).x;
    int coorY = (*point).y;
    
    
    
    if(coorX==0||coorY==0){
        return 0; 
    }
    else if (coorX>0&&coorY>0){
        return 1;
    }
    else if (coorX<0&&coorY>0){
        return 2;
    }
    else if (coorX<0&&coorY<0){
        return 3;
    }else{
        return 4;
    }
        
}
 
int main()
{
    Point *ptrPoint = malloc(sizeof(Point));
    scanf("%i %i", &ptrPoint->x, &ptrPoint->y);
    printf("%d",structQuadrant(ptrPoint));
    free(ptrPoint);
    
    return 0;
}