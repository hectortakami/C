//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.3)
#include <stdio.h>

static double bubble = 867.5309;

void printer(double x, double y) {
    
   int z = 5;
   printf("x = %.2f and y = %.1f\n", x, y);
   printf("x = %.2f and y = %.4f\n", x, bubble);
   printf("The value from main is: %.4f\n",bubble);
   printf("z = %d",z);
   
}

int main () {
    
    double y = 8.0;
    double x = 10.01;
    printer(x,y);
    
    return 0;
}