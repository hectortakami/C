//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.8)


#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct Fraction{
    int numerator;
    int denominator;
} Fraction;

 
void ptrSimplifyFraction (struct Fraction *fractionInput)
{
    int frac1 = (*fractionInput).numerator;
    int frac2 = (*fractionInput).denominator;
    int gcd;

    int a;
    int b;
    int c;

    a = frac1;
    b = frac2;
    c = a % b;

    while(c > 0)
    {
        a = b;
        b = c;
        c = a % b;
    }

    gcd = b;

    frac1 /= gcd;
    frac2 /= gcd;

    printf("%d\n%d", frac1, frac2);


}
 
int main()
{
    Fraction *ptrFraction = malloc(sizeof(Fraction));
    
    scanf("%d",&ptrFraction->numerator);
    scanf("%d",&ptrFraction->denominator);
    
    ptrSimplifyFraction(ptrFraction);
    
    free(ptrFraction);
    
    return 0;
}