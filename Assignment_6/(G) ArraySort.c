//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.6)

#include "stdio.h"

void bubbleSort(int x[],int n){
    int i, j;
    int temp;
    /*Sort the Data*/
    for(i = 1; i <= n; ++i){
        for(j = i + 1; j <= n; ++j){
            if(x[i] > x[j]){
                temp = x[i];
                x[i] = x[j];
                x[j] = temp;
            }
        }
    }
    
    /*Sorted Data*/
    for(i = 1; i <= n; ++i){
        printf("%d\n", x[i]);
    }
}

int main() {
    int i, j, n;

    scanf("%d", &n);

    int x[n];
    for(i = 1; i <= n; ++i){
        scanf("%d", &x[i]);
    }
    bubbleSort(x, n);

    

    return 0;
}