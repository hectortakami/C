//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.7)


#include <stdio.h>
#include <math.h>

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

 
void structSumFraction (struct Fraction f1, struct Fraction f2 )
{
    int n1,n2,d1,d2, num, den;
    
    n1 = f1.numerator;
    d1 = f1.denominator;
    
    n2 = f2.numerator;
    d2 = f2.denominator;
    
    den = d1*d2;
    num = (n1*d2)+(n2*d1);
    
    struct Fraction fraction;
    fraction.numerator = num;
    fraction.denominator = den;
    
    simplifyFraction(fraction);
        
}
 
int main()
{
    struct Fraction f1;
    int n1,d1;
    scanf("%d",&n1);
    scanf("%d",&d1);
    f1.numerator = n1;
    f1.denominator = d1;
    
    struct Fraction f2;
    int n2,d2;
    scanf("%d",&n2);
    scanf("%d",&d2);
    f2.numerator = n2;
    f2.denominator = d2;
    
    structSumFraction(f1,f2);
    return 0;
}