//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.2)

#include "stdio.h"

int main(void) {
    
    printf("Write nested for loops that produce the following output:\n\n\n");
  
    for(int i=0;i<3;i++){
        for(int j=0;j<=9;j++){
            printf("%d%d%d",j,j,j);
        }
        printf("\n");
    }

    return 0;
}