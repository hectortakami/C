//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.8)


#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct Point{
    int x;
    int y;
} Point;
 
double ptrComputeSlope (struct Point *point1, struct Point *point2)
{
    int x1 = (*point1).x;
    int y1 = (*point1).y;
    int x2 = (*point2).x;
    int y2 = (*point2).y;
    return ((float)(y2-y1)/(float)(x2-x1));
}
 
int main()
{
    Point *ptrPoint1 = malloc(sizeof(Point));
    Point *ptrPoint2 = malloc(sizeof(Point));
    
    scanf("%i %i", &ptrPoint1->x, &ptrPoint1->y);
    scanf("%i %i", &ptrPoint2->x, &ptrPoint2->y);
    
    printf("%.1f",ptrComputeSlope(ptrPoint1,ptrPoint2));
    
    free(ptrPoint1);
    free(ptrPoint2);
    
    return 0;
}