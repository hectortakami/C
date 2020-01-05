//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.3)
#include <stdio.h>

static double bubble = 867.5309;

void printStrings(char string [], int times) {
   for(int i=0;i<times;i++){
       printf("%s",string);
   }
   
}

int main () {
    
    int times;
    scanf("%d", &times);
    
    char string [100];
    scanf(" %[^\n]s", string);
    
    printStrings(string,times);
    return 0;
}