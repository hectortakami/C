//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.5)

#include <stdio.h>

void tobinstr (int value, int bitsCount, char *output) {
  int i;
  output[bitsCount] = '\0';
  for (i = bitsCount - 1; i >= 0; --i, value >>= 1)
    {
      output[i] = (value & 1) + '0';
    }
}




unsigned int circularLeftShift (int number, int shifts) {
    char str[32];
    tobinstr(number,32,str);

    for(int i=0; i<shifts; i++){
        int mostSB = str[0]-'0';
        number = number<<1;
        number = number^mostSB;
        tobinstr(number,32,str);
    }
    int index = 0;
    unsigned int totalVal = 0;
    for(int i=31;i>=0;i--){
        char bit = str[i];
        int valPow = 1;
        if(bit=='1'){
            if(index<=29){
                for(int i = 0; i<index; i++){
                    valPow*=2;
                }
                totalVal+=valPow;
            }
            if(index==30){
                valPow = 1073741824;
                totalVal+= valPow;
            }
            if(index==31){
                valPow = 2147483648;
                totalVal+= valPow;
            }
            
        }
        index++;
    }
    return totalVal;
    
    
}


int main () {
  int n;
  scanf ("%d", &n);
  int s;
  scanf ("%d", &s);
  printf("%u",circularLeftShift (n,s));
}