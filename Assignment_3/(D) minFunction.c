//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.3)
#include <stdio.h>


int minFunction(int a,int b,int c) {
   return a<b ? (a<c?a:c) : (b<c?b:c);
}

int main () {
    
    int a;
    scanf("%d", &a);
    int b;
    scanf("%d", &b);
    int c;
    scanf("%d", &c);
    
    
    int min = minFunction(a,b,c);
    printf("%d\n",min);
    
    return 0;
}