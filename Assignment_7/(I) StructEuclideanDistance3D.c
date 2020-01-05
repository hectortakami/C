//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.7)


#include <stdio.h>
#include <math.h>

struct Point3D{
    int x;
    int y;
    int z;
};
 
double structEuclideanDistance3D (struct Point3D point1, struct Point3D point2 )
{
    int x1 = point1.x;
    int y1 = point1.y;
    int z1 = point1.z;
    
    int x2 = point2.x;
    int y2 = point2.y;
    int z2 = point2.z;
    
    double xSqr = (double) (x1 - x2) * (x1 - x2);
    double ySqr = (double) (y1 - y2) * (y1 - y2);
    double zSqr = (double) (z1 - z2) * (z1 - z2);

    double mySqr = xSqr + ySqr + zSqr;

    double myDistance = sqrt(mySqr);
    
    return myDistance;
    
        
}
 
int main()
{
    struct Point3D point1;
    int x1,y1,z1;
    scanf("%d",&x1);
    scanf("%d",&y1);
    scanf("%d",&z1);
    point1.x = x1;
    point1.y = y1;
    point1.z = z1;
    
    struct Point3D point2;
    int x2,y2,z2;
    scanf("%d",&x2);
    scanf("%d",&y2);
    scanf("%d",&z2);
    point2.x = x2;
    point2.y = y2;
    point2.z = z2;
    
    
    printf("%.2f",structEuclideanDistance3D(point1,point2));
    return 0;
}