//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.7)


#include <stdio.h>
#include <math.h>

typedef struct Point{
    int x;
    int y;
}Point;
 
void swapAndNegate (struct Point *point)
{
    int coorX = (*point).x;
    int coorY = (*point).y;
    
    coorX = coorX*-1;
    coorY = coorY*-1;
    int temp = coorX;
    coorX = coorY;
    coorY = temp;
    
    printf("%d\n%d", coorX, coorY);
    
        
}
 
int main()
{
    Point *ptrPoint = malloc(sizeof(Point));
    
    scanf("%d%d",&ptrPoint->x, &ptrPoint->y);
    
    swapAndNegate(ptrPoint);
    
    free(ptrPoint);
    
    return 0;
}