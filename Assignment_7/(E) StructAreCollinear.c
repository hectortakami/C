//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.7)


// Slope based solution to check if three
// points are collinear. 
#include <stdio.h>
#include <math.h>
 
int areCollinear(int x1, int y1, int x2, int y2, 
                              int x3, int y3)
{
    if ((y3 - y2)*(x2 - x1) == (y2 - y1)*(x3 - x2)){
        return 1;
    }else{
        return 0;
    }
        
}
 
int main()
{
    int x1,y1,x2,y2,x3,y3;
    scanf("%d",&x1);
    scanf("%d",&y1);
    scanf("%d",&x2);
    scanf("%d",&y2);
    scanf("%d",&x3);
    scanf("%d",&y3);
    printf("%d",areCollinear(x1,y1,x2,y2,x3,y3));
    return 0;
}