//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.4)

#include <stdio.h>

void hopScotch(int n) {
    int num = 1;
    for(int i=1; i<=n; i++){
        printf("   %d\n",num);
        num++;
        printf("%d",num);
        num++;
        printf("     %d\n",num);
        num++;
    }
    printf("   %d\n",num++);
}

int main()
{
    int n;
    scanf("%d", &n);
    hopScotch(n);
    
}