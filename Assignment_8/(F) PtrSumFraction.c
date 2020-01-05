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

void structSumFraction (struct Fraction *f1, struct Fraction *f2 )
{
    int n1,n2,d1,d2, num, den;
    
    n1 = (*f1).numerator;
    d1 = (*f1).denominator;
    
    n2 = (*f2).numerator;
    d2 = (*f2).denominator;
    
    den = d1*d2;
    num = (n1*d2)+(n2*d1);
    
    struct Fraction fraction;
    fraction.numerator = num;
    fraction.denominator = den;
    
    ptrSimplifyFraction(&fraction);
        
}

 
int main()
{
    Fraction *ptrFraction1 = malloc(sizeof(Fraction));
    Fraction *ptrFraction2 = malloc(sizeof(Fraction));
    
    scanf("%d",&ptrFraction1->numerator);
    scanf("%d",&ptrFraction1->denominator);
    scanf("%d",&ptrFraction2->numerator);
    scanf("%d",&ptrFraction2->denominator);
    
    structSumFraction(ptrFraction1, ptrFraction2);
    
    free(ptrFraction1);
    free(ptrFraction2);
    
    return 0;
}