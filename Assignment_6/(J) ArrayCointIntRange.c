//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.6)

#include "stdio.h"

int countInRange (int min, int max, int array[], int size){
    int count = 0;
    for(int i = 0; i<size; i++){
        if(array[i]>=min&&array[i]<=max){
            count++;
        }
    }
    return count;
    
}

int main(void) {
  int min;
  scanf("%d", &min);
  int max;
  scanf("%d", &max);
    
  int n = 0;
  scanf("%d", &n);
  int h[n];
  for(int i=0;i<n;i++){
    scanf("%d", &h[i]);
  }
  
  printf("%d",countInRange (min, max, h,n));
  

  return 0;
}