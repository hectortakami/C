//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.6)

#include "stdio.h"

int searchValue (int x[],int n, int num){
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
        if(x[i]==num){
            return i-1;
        }
    }
}

int main() {
    int i, j, n, num;

    scanf("%d", &n);
    scanf("%d", &num);

    int x[n];
    for(i = 1; i <= n; ++i){
        scanf("%d", &x[i]);
    }
    printf("%d",searchValue (x, n, num));

    

    return 0;
}