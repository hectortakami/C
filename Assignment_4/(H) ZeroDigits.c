//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.4)

#include <stdio.h>

int zeroDigits(int number, int digit)
{
    
    if ( number <= 0 ) {
        
        return 0;
    }
    else {
        if ( number % 10 == digit ) {
            return 1 + zeroDigits (number / 10, digit);
        }
        else {
            return zeroDigits (number / 10, digit);
        }
    }
}

int main()
{
    int num;
    scanf("%d", &num);
    if(num==0){
        printf("%d",1);
    }
    else{
        int numOfZeros = zeroDigits(num,0);
        printf("%d",numOfZeros);
    }
}