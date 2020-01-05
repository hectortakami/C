//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.4)

#include <stdio.h>

int countFactors(int n) {
    int count =0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) { 
            count++;
        }
    }
    return count;

}

int main()
{
    int n;
    scanf("%d", &n);
    int noFactors = countFactors(n); 
    printf("%d",noFactors);
  
}