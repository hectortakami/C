//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.7)


#include <stdio.h>
#include <math.h>

struct Point{
    int x;
    int y;
};
 
int structQuadrant (struct Point point)
{
    int coorX = point.x;
    int coorY = point.y;
    
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
    int x1,y1;
    scanf("%d",&x1);
    scanf("%d",&y1);
    struct Point point;
    point.x = x1;
    point.y = y1;
    printf("%d",structQuadrant(point));
    return 0;
}