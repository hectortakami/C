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

int swapBits(unsigned int x, unsigned int p1, unsigned int p2, unsigned int n)
{
    /* Move all bits of first set to rightmost side */
    unsigned int set1 =  (x >> p1) & ((1U << n) - 1);
 
    /* Moce all bits of second set to rightmost side */
    unsigned int set2 =  (x >> p2) & ((1U << n) - 1);
 
    /* XOR the two sets */
    unsigned int xor = (set1 ^ set2);
 
    /* Put the xor bits back to their original positions */
    xor = (xor << p1) | (xor << p2);
 
    /* XOR the 'xor' with the original number so that the 
       two sets are swapped */
    unsigned int result = x ^ xor;
 
    return result;
}


int main () {
  int n;
  scanf ("%d", &n);
  int p1;
  scanf ("%d", &p1);
  int p2;
  scanf ("%d", &p2);
  printf("%u",swapBits (n,p1,p2,1));
}