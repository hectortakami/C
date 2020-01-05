//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.7)


// Slope based solution to check if three
// points are collinear. 
#include <stdio.h>
#include <math.h>
 
float areCollinear(int x1, int y1, int x2, int y2)
{
    return ((float)(y2-y1)/(float)(x2-x1));
        
}
 
int main()
{
    int x1,y1,x2,y2,x3,y3;
    scanf("%d",&x1);
    scanf("%d",&y1);
    scanf("%d",&x2);
    scanf("%d",&y2);
    printf("%.1f",areCollinear(x1,y1,x2,y2));
    return 0;
}