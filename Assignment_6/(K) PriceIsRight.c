//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.6)

#include "stdio.h"

int priceIsRight(int price, int bids[], int n) {
    int max = -1;
    for(int i = 0; i < n; i++) {
        if(max < bids[i] && bids[i] <= price) {
            max = bids[i];
        }
    }
    return max;
}


int main(void) {
  int price = 0;
  scanf("%d", &price);
  int n = 0;
  scanf("%d", &n);
  int h[n];
  for(int i=0;i<n;i++){
    scanf("%d", &h[i]);
  }
  
  printf("%d",priceIsRight(price,h,n));
  

  return 0;
}