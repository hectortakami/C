//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.7)


#include <stdio.h>
#include <math.h>

struct Point{
    int x;
    int y;
};
 
void swapAndNegate (struct Point point)
{
    int coorX = point.x;
    int coorY = point.y;
    
    coorX = coorX*-1;
    coorY = coorY*-1;
    int temp = coorX;
    coorX = coorY;
    coorY = temp;
    
    printf("%d\n%d", coorX, coorY);
    
        
}
 
int main()
{
    int x1,y1;
    scanf("%d",&x1);
    scanf("%d",&y1);
    struct Point point;
    point.x = x1;
    point.y = y1;
    swapAndNegate(point);
    return 0;
}