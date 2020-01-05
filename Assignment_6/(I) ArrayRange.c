//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.6)

#include "stdio.h"

int range(int array[], int size){
    int max = array[0];
        for(int i = 1; i<size; i++){
            if(array[i]>=max){
            max = array[i]; 
        }
    }
    int min = array[0];
        for(int i = 1; i<size; i++){
            if(array[i]<=min){
            min = array[i]; 
        }
    }
    if(max==min){
        return 1;
    }else{
        return (max - min)+1;
    }
}

int main(void) {
  int n = 0;
  scanf("%d", &n);
  int h[n];
  for(int i=0;i<n;i++){
    scanf("%d", &h[i]);
  }
  
  printf("%d",range(h,n));
  

  return 0;
}