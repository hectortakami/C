//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.4)
#include <stdio.h>


int evenOdd(int n) {
   if(n%2==0){
      printf("even"); 
   }else{
       printf("odd");
   }
}

int main () {
    
    int n;
    scanf("%d", &n);
    evenOdd(n);
    
    return 0;
}