//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.6)

#include <stdio.h>
#include <stdlib.h>

void arraySieveOfEratosthenes(int limit){
    unsigned long long int i,j;
    int *primes;
    int z = 1;

    primes = malloc(sizeof(int)*limit);
    

    for (i=2;i<limit;i++)
        primes[i]=1;

    for (i=2;i<limit;i++)
        if (primes[i])
            for (j=i;i*j<limit;j++)
                primes[i*j]=0;

    for (i=2;i<limit;i++)
        if (primes[i])
            printf("%d\n",i);
}

int main(){
    int limit;
    scanf("%d", &limit);
    arraySieveOfEratosthenes(limit);
    

return 0;
}