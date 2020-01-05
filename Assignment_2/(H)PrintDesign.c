//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.2)

#include <stdio.h>

int main()
{
    int j= 5;
    
    for(int i=1;i<10;i=i+2){
        for(int v=1;v<=j;v++){
            printf("-");
        }
        
        for(int k=0;k<i;k++){
            
            printf("%d",i);
            
        }
        for(int v=1;v<=j;v++){
            printf("-");
        }
        
        printf("\n");
        j--;
    }
    
    
    
    

    return 0;
}