//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.2)

#include "stdio.h"

int main(void) {
  for(int i=0;i<40;i++){
      printf("-");
  }
  printf("\n");
  
  for(int i=0;i<10;i++){
      printf("_-^-");
  }
  printf("\n");
  
  for(int i=0;i<2;i++){
      for(int i=1;i<=10;i++){
        if(i==10){
            printf("00");
      }else{
        printf("%d%d",i,i);
      }
  }
      
  }
 
  printf("\n");
  
  for(int i=0;i<40;i++){
      printf("-");
  }
  printf("\n");

  return 0;
}