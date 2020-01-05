//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.6)

#include "stdio.h"
#define SIZE 10

int main(void) {
  unsigned int h[SIZE] = {0};
  scanf("%u%u%u%u%u%u%u%u%u%u", &h[0], &h[1], &h[2], &h[3], &h[4], &h[5], &h[6], &h[7], &h[8], &h[9]);
  
  for(int i = 0; i<SIZE; i++){
      int num = h[i];
      for(int i = 0; i<num; i++){
        printf("b");
      }
      printf("\n");
  }

  return 0;
}