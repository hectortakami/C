//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.3)
#include <stdio.h>

int printPowersOfN(int base, int power){
    if(power>=0){
        printf("%d ", 1);
        for(int x=1;x<=power;x++){
            int ac = 1;
            for(int y=1;y<=x;y++){
                ac = ac*base;  
            }
            printf("%d ", ac);
            ac = 0;
        }
    }
    
}

int main()
{
    int base;
    scanf("%d", &base);
    int power;
    scanf("%d", &power);
    printPowersOfN(base,power);


    return 0;
}