//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.5)

#include <stdio.h>


void rtobinst (int value, int bitsCount, char *output) {
  int i;
  output[bitsCount] = '\0';
  for (i = bitsCount - 1; i >= 0; --i, value >>= 1)
    {
      output[i] = (value & 1) + '0';
    }
}

unsigned int circularRightShift (unsigned int number, int shifts) {
    /*char str[32];
    rtobinst(number,32,str);
    printf("%s\n",str);*/
    unsigned int savedNumber = number;
    savedNumber<<=32-shifts;
    /*rtobinst(savedNumber,32,str);
    printf("%s\n",str);*/
    number>>=shifts;
    /*rtobinst(number,32,str);
    printf("%s\n",str);*/
    unsigned int resultNumber = number+savedNumber;
    /*rtobinst(resultNumber,32,str);
    printf("%s\n",str);*/
    return resultNumber;

}


int main () {
  int n;
  scanf ("%d", &n);
  int s;
  scanf ("%d", &s);
  printf("%u",circularRightShift (n,s));
}