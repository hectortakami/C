//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.4)

#include <stdio.h>

void printRange(int a, int b) {
    if(b>=a){
        for(int i=a; i<=b; i++){
            printf("%d ",i);
        }
    }else{
        for(int i=a; i>=b; i--){
            printf("%d ",i);
        }
    }
    
}

int main()
{
    int x;
    scanf("%d", &x);
    int y;
    scanf("%d", &y);
    printRange(x,y);
  
}