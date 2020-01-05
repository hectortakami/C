//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.4)
#include <stdio.h>
#include <stdbool.h>

bool hasMidPoint(int a,int b,int c) {
    bool aIsMidpoint = (2 * a == b + c); 
    bool bIsMidpoint = (2 * b == a + c);
    bool cIsMidpoint = (2 * c == a + b);
    return aIsMidpoint || bIsMidpoint || cIsMidpoint;
}

int main () {
    
    int n1;
    scanf("%d", &n1);
    int n2;
    scanf("%d", &n2);
    int n3;
    scanf("%d", &n3);
    bool h = hasMidPoint(n1,n2,n3);
    
    printf(h ? "true" : "false");
    
    
    return 0;
}