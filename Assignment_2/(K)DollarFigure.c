//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.2)

#include <stdio.h>

int main()
{
    int ast = 0;
    int dol = 7;
    int cAst = 7;
    
    for(int h=1;h<=7;h++){
        for(int a=0;a<ast;a++){
            printf("*");
        }
        for(int d=0;d<dol;d++){
            printf("$");
        }
        for(int a=0;a<cAst*2;a++){
            printf("*");
        }
        for(int d=0;d<dol;d++){
            printf("$");
        }
        for(int a=0;a<ast;a++){
            printf("*");
        }
        
        printf("\n");
        ast = ast+2;
        cAst--;
        dol--;
    }

    return 0;
}