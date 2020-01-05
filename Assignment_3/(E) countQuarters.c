//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.3)
#include <stdio.h>


int countQuarters(int cents) {
   return (cents%100)/25;
}

int main () {
    
    int cents;
    scanf("%d", &cents);
    
    int quarters = countQuarters(cents);
    printf("%d",quarters);
    
    return 0;
}