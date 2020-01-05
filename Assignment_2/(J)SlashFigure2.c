//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.2)

#include <stdio.h>

int main()
{
    int rows;
    scanf("%d", &rows);
  
    int diag = 0;
    int sig = (rows*2)-1;
    
    for(int r=1;r<=rows;r++){
        
        for(int i =0; i<diag; i++){
            printf("%c",92);
        }
        for(int i=0;i<sig*2;i++){
            printf("!");
        }
        for(int i =0; i<diag; i++){
            printf("/");
        }
        
        
        sig = sig-2;
        diag = diag+2;
        printf("\n");
    }

    return 0;
}