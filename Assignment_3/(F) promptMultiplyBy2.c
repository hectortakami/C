//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.3)
#include <stdio.h>


void promptMultiplyBy2(int n) {
   printf("%d times 2 = %d",n, n+n);
}

int main () {
    
    int n;
    scanf("%d", &n);
    promptMultiplyBy2(n);
    
    
    return 0;
}