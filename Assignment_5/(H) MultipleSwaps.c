#include "stdio.h"

unsigned int swapOnce(unsigned int n, unsigned int a, unsigned int b){
  if(((n>>a)&1) == ((n>>b)&1)){ //If bits are equal
    return n;
  }
  unsigned int mask = (1<<a)|(1<<b);
  return n^mask;
}

unsigned int multipleSwaps(unsigned int n, unsigned int a, unsigned int b){
  for(a; a<b; a++, b--){
    n = swapOnce(n, a, b);
  }
  return n;
}

int main(void){
  unsigned int n, a, b;
  scanf("%i%i%i", &n, &a, &b);
  printf("%u", multipleSwaps(n, a, b));
}