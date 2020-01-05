//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.8)


#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct Point{
    int x;
    int y;
} Point;
 
int ptrAreCollinear (struct Point *point1, struct Point *point2, struct Point *point3)
{
    int x1 = (*point1).x;
    int y1 = (*point1).y;
    int x2 = (*point2).x;
    int y2 = (*point2).y;
    int x3 = (*point3).x;
    int y3 = (*point3).y;
    if ((y3 - y2)*(x2 - x1) == (y2 - y1)*(x3 - x2)){
        return 1;
    }else{
        return 0;
    }

}
 
int main()
{
    Point *ptrPoint1 = malloc(sizeof(Point));
    Point *ptrPoint2 = malloc(sizeof(Point));
    Point *ptrPoint3 = malloc(sizeof(Point));
    
    scanf("%d%d%d%d%d%d", &ptrPoint1->x, &ptrPoint1->y, &ptrPoint2->x, &ptrPoint2->y, &ptrPoint3->x, &ptrPoint3->y );
    printf("%d",ptrAreCollinear(ptrPoint1,ptrPoint2,ptrPoint3));
    
    free(ptrPoint1);
    free(ptrPoint2);
    free(ptrPoint3);
    
    return 0;
}