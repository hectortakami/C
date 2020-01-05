//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.2)

#include <stdio.h>

int main()
{
    int diagInv = 0;
    int sig = 11;
    int cAst = 7;
    
    for(int h=1;h<=6;h++){
        for(int a=0;a<diagInv;a++){
            printf("%c",92);
        }
        for(int a=0;a<sig*2;a++){
            printf("!");
        }
        for(int a=0;a<diagInv;a++){
            printf("/");
        }
        
        printf("\n");
        diagInv = diagInv+2;
        sig = sig-2;
        
    }

    return 0;
}