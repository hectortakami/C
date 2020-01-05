#include <stdio.h>

unsigned int fourIntOne(unsigned char a, unsigned char b, unsigned char c, unsigned char d){
  unsigned int res = 0;
  unsigned char n[] = {a,b,c,d};
  for(int i=3; i>-1; i--){
    res <<= 8;
    res |= n[i];
  }
  return res;
}

int main(void){
  unsigned char a,b,c,d;
  scanf("%hhu%hhu%hhu%hhu",&a,&b,&c,&d);
  printf("%u",fourIntOne(a,b,c,d));
  return 0;
}