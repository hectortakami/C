//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.3)
#include <stdio.h>

int sumNumbers(int a, int b){
    int sum = 0;
    for(int i = a; i<=b; i++){
        sum+=i;
    }
    printf("low? high? sum = %d",sum);
    
}

int main()
{
    int a;
    scanf("%d", &a);
    int b;
    scanf("%d", &b);
    sumNumbers(a,b);

    return 0;
}