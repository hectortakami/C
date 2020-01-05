//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.6)

#include "stdio.h"

int computeMax(int array[], int size){
    int max = array[0];
        for(int i = 1; i<size; i++){
            if(array[i]>=max){
            max = array[i]; 
        }
    }
    return max;
}

int main(void) {
  int n = 0;
  scanf("%d", &n);
  int h[n];
  for(int i=0;i<n;i++){
    scanf("%d", &h[i]);
  }
  
  printf("%d",computeMax(h,n));
  

  return 0;
}