//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.5)

#include <stdio.h>

unsigned int countSetBits(unsigned int n)
{
  unsigned int count = 0;
  while (n)
  {
    count += n & 1;
    n >>= 1;
  }
  return count;
}
 

int main()
{
    unsigned int n;
    scanf("%d", &n);
    unsigned int countedBits = countSetBits(n);
    printf("%d",countedBits);
}