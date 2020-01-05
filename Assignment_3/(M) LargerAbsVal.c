//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.3)
#include <stdio.h>
#include <math.h>

int largerAbsVal(int a, int b){
    int x = abs(a);
    int y = abs(b);
    return (x>y)?x:y;
    
}

int main()
{
    int a;
    scanf("%d", &a);
    int b;
    scanf("%d", &b);
    
    int r = largerAbsVal(a,b);
    printf("%d",r);


    return 0;
}