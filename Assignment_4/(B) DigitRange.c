//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.4)
#include <stdio.h>


int digitRange(int n) {
    int num = abs(n);
    int max = num % 10;
    int min = num % 10;
    
    while(num > 0) {
        int digit = num % 10;
        
        if(digit > max) {
            max = digit;
        } else if(digit < min) {
            min = digit;
        }
        
        num = num/10;
    }
    
    return (max - min) + 1;
}

int main () {
    
    int n;
    scanf("%d", &n);
    int r = digitRange(n);
    printf("%d",r);
    
    return 0;
}