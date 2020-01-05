//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.4)

#include <stdio.h>

void perfectNumbers(int max) {
    printf("Perfect numbers up to %d: ",max);
    for (int i = 1; i <= max; i++) {
        int sum = 0;
        for (int j = 1; j < i; j++) {
            if (i % j == 0) {
                sum += j;
            }
        }
        if (sum == i) {
            printf("%d ",i);
        }
    }
}

int main()
{
    int num;
    scanf("%d", &num);
    perfectNumbers(num);
  
}