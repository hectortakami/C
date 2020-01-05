//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.3)

#include "stdio.h"

double ftoc(double tempf, double tempc) {
    tempc = (tempf - 32) * 5 / 9;
    return tempc;
}

int main(void) {

double tempf = 98.6;
double tempc = 0.0;

tempc = ftoc(tempf, tempc);
printf("Body temp in C is: ");
printf("%.1f\n",tempc);

return 0;

}