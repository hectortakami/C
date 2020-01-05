//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.4)
#include <stdio.h>


int digitSum(int n) {
    n = abs(n);
    int sum = 0;
    
    while(n > 0) {
        sum += n % 10;
        n /= 10;
    }
    
    return sum;
}

int main () {
    
    int n;
    scanf("%d", &n);
    int r = digitSum(n);
    printf("%d",r);
    
    return 0;
}