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

int compareBits(unsigned int a,unsigned int b){
    unsigned int setBitsOnA = countSetBits(a);
    unsigned int setBitsOnB = countSetBits(b);
    return (setBitsOnA==setBitsOnB?0:(setBitsOnA>setBitsOnB?1:-1));
}
 

int main()
{
    unsigned int n1;
    scanf("%d", &n1);
    unsigned int n2;
    scanf("%d", &n2);
    printf("%d",compareBits(n1,n2));
}