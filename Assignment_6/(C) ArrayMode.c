//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.6)

#include "stdio.h"

int computeMode(int x[],int n){
    
    int maxValue = 0, maxCount = 0, i, j;

   for (i = 0; i < n; ++i) {
      int count = 0;
      
      for (j = 0; j < n; ++j) {
         if (x[j] == x[i])
         ++count;
      }
      
      if (count > maxCount) {
         maxCount = count;
         maxValue = x[i];
      }
   }

   return maxValue;
}

int main() {
    int i, j, n;

    scanf("%d", &n);

    int x[n];
    for(i = 1; i <= n; ++i){
        scanf("%d", &x[i]);
    }
    printf("%d",computeMode(x, n));

    

    return 0;
}