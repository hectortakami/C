//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.3)
#include <stdio.h>


void printGrid(int r, int c) {
   int n = r*c;
   
   for(int l=1; l<=r; l++){
       int p = l;
       for(int j=1; j<=c; j++){
           
           if(j==c){
              printf("%d", p);
           }else{
              printf("%d, ", p);
              p = p+r; 
           }
           
       }
       printf("\n");
   }
   
}

int main () {
    
    int rows;
    scanf("%d", &rows);
    int columns;
    scanf("%d", &columns);
    printGrid(rows,columns);
    
    
    return 0;
}