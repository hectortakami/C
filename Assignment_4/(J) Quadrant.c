//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.4)

#include <stdio.h>

int quadrant(float x, float y) {
    
    if(x>0){
        if(y>0){
            return 1;  
        }else if (y==0){
            return 0;
        }
        else{
            return 4;
        }
    }else if(x<0){
        if(y>0){
            return 2;  
        }else if (y==0){
            return 0;
        }else{
            return 3;
        }
    }else{
        return 0;
    }
}

int main()
{
    float x;
    scanf("%f", &x);
    float y;
    scanf("%f", &y);
    printf("%d",quadrant(x,y));
  
}