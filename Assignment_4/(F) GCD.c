//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.4)

#include <stdio.h>

int gcd(int n1, int n2) {
    if (n1==1||n2==1){
        return 1;
    }
    if(n1==0){
       return n2; 
    }
    if(n2==0){
        return n1;
    }
    return abs(gcd(n2,n1%n2));
}

int main()
{
    int n1;
    scanf("%d", &n1);
    int n2;
    scanf("%d", &n2);
    int value = gcd(n1,n2);
    printf("%d",value);
    
}