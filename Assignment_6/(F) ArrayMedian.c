//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.6)

#include "stdio.h"

float computeMedian(float x[],int n){
    int i, j;
    float temp, median;
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
    /*
    for(i = 1; i <= n; ++i){
        printf("%2.2f ", x[i]);
    }
    printf("\n");
    */

    /*Compute the Median*/
    if(n % 2 == 0){
        median = (x[n / 2] + x[n / 2 + 1]) / 2;
    }
    else{
        median = x[n / 2 + 1];
    }
    return median;
}

int main() {
    int i, j, n;
    float temp, median;

    scanf("%d", &n);

    float x[n];
    for(i = 1; i <= n; ++i){
        scanf("%f", &x[i]);
    }
    printf("%.1f",computeMedian(x, n));

    

    return 0;
}