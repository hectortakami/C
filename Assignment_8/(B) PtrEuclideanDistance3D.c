//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.8)


#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct Point3D{
    int x;
    int y;
    int z;
} Point3D;
 
double structEuclideanDistance3D (struct Point3D *point1, struct Point3D *point2 )
{
    int x1 = (*point1).x;
    int y1 = (*point1).y;
    int z1 = (*point1).z;
    
    int x2 = (*point2).x;
    int y2 = (*point2).y;
    int z2 = (*point2).z;
    
    double xSqr = (double) (x1 - x2) * (x1 - x2);
    double ySqr = (double) (y1 - y2) * (y1 - y2);
    double zSqr = (double) (z1 - z2) * (z1 - z2);

    double mySqr = xSqr + ySqr + zSqr;

    double myDistance = sqrt(mySqr);
    
    return myDistance;
    
        
}
 
int main()
{
    Point3D *ptrPoint1 = malloc(sizeof(Point3D));
    Point3D *ptrPoint2 = malloc(sizeof(Point3D));
    
    scanf("%i %i %i", &ptrPoint1->x, &ptrPoint1->y, &ptrPoint1->z);
    scanf("%i %i %i", &ptrPoint2->x, &ptrPoint2->y, &ptrPoint2->z);
    
    printf("%.2f",structEuclideanDistance3D(ptrPoint1,ptrPoint2));
    
    free(ptrPoint1);
    free(ptrPoint2);
    
    return 0;
}