//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.3)
#include <stdio.h>


void printNumbers(int n) {
   for(int i = 1;i<=n;i++){
      printf("[%d] ",i); 
   }
}

int main () {
    
    int n;
    scanf("%d", &n);
    printNumbers(n);
    
    
    return 0;
}