//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Exam 1)

#include <stdio.h>

unsigned int encodeMinutia(unsigned int x,unsigned int y,unsigned int d,unsigned int t);

int main()
{
    unsigned int x;
    scanf ("%d", &x);
    unsigned int y;
    scanf ("%d", &y);
    unsigned int d;
    scanf ("%d", &d);
    unsigned int t;
    scanf ("%d", &t);
    printf("%u",encodeMinutia(x,y,d,t));
    return 0;
}

unsigned int encodeMinutia(unsigned int x,unsigned int y,unsigned int d,unsigned int t){
    t<<=30;
    t >>=1;
    d<<=20;
    y<<=10;
    unsigned int valueMinutiae = 0;
    valueMinutiae = t+d+y+x;
    return valueMinutiae;
}