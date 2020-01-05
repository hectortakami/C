//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.6)

#include "stdio.h"
#include "stdbool.h"

bool isMagicSquare  (int array[], int n){
    int valueSumSquare = 0;
    for(int i =0; i<n; i++){
        valueSumSquare += array[i];
    }
    
        //printf("V: %d\n", valueSumSquare);
    
    for(int i=n ; i<n*n; i=i+n){
        int sumValues = 0;
        for(int j = i; j<i+n; j++){
            sumValues += array[j];
        }
        //printf("SV: %d\n", sumValues);
        if(sumValues!=valueSumSquare){
            return false;
        }
    }
    
    return true;
    
    
}

int main(void) {
  int n = 0;
  scanf("%d", &n);
  int h[n*n];
  for(int i=0;i<n*n;i++){
    scanf("%d", &h[i]);
  }
  
  printf(isMagicSquare(h,n) ? "true" : "false");
  

  return 0;
}