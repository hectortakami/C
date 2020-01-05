//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Exam 1)

#include <stdio.h>

void decodeMinutia(unsigned int valueMinutiae);

int main()
{
    unsigned int valueMinutiae;
    scanf ("%d", &valueMinutiae);
    decodeMinutia(valueMinutiae);
    return 0;
}

void decodeMinutia(unsigned int valueMinutiae){
    unsigned int x = valueMinutiae;
    unsigned int y = valueMinutiae;
    unsigned int d = valueMinutiae;
    unsigned int t = valueMinutiae;
    x<<=22;
    x>>=22;
    y>>=10;
    y<<=22;
    y>>=22;
    d<<=3;
    d>>=23;
    t>>=29;
    t<<=30;
    t>>=30;
    //1343750913
    //537920513
    printf("%u\n%u\n%u\n%u\n",x,y,d,t);
    
}