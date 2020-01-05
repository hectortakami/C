//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.7)

#include <stdio.h>

struct Fraction{
    int numerator;
    int denominator;
};

void simplifyFraction (struct Fraction fractionInput){
    
    int frac1 = fractionInput.numerator;
    int frac2 = fractionInput.denominator;
    int gcd;

    int a;
    int b;
    int c;

    a = frac1;
    b = frac2;

    //Calculate GCD
    c = a % b;

    while(c > 0)
    {
        a = b;
        b = c;
        c = a % b;
    }

    gcd = b;


    //Divide the numerator and denominator with the GCD
    frac1 /= gcd;
    frac2 /= gcd;

    printf("%d\n%d", frac1, frac2);

}



int main()
{
    struct Fraction fractionInput;
    
    int num;
    int den;
    scanf("%d", &num);
    scanf("%d", &den);
    
    fractionInput.numerator = num;
    fractionInput.denominator = den;
    
    simplifyFraction(fractionInput);
    
    return 0;
     
}