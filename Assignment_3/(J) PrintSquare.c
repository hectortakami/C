//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.3)
#include <stdio.h>

int printSquare(int min, int max){
    
    int s = min;
    int times = 0;
    for(int i=min; i<=max; i++){
        for(int i=s; i<=max; i++){
        printf("%d",i);
        times++;
        }
        s++;
        if(times<=max){
           for(int i=min; i<=max-times; i++){
            printf("%d",i);
            } 
        }
        times = 0;
        printf("\n");
    }
    
}

int main()
{
    int min;
    scanf("%d", &min);
    int max;
    scanf("%d", &max);
    printSquare(min,max);

    return 0;
}