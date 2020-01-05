//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.5)

#include <stdio.h>
#include <math.h>

void
tobinstr (int value, int bitsCount, char *output)
{
  int i;
  output[bitsCount] = '\0';
  for (i = bitsCount - 1; i >= 0; --i, value >>= 1)
    {
      output[i] = (value & 1) + '0';
    }
}




int
inverted (unsigned int x, int p, int n)
{
  int dataTypeSize = sizeof (x) * 8;
  char numStr[dataTypeSize];
  tobinstr (x, dataTypeSize, numStr);
  //printf ("%s\n", numStr);

  //Invert value and change by the position many times
  int j = 0;
  char numStrInv[dataTypeSize];
  for (int i = dataTypeSize - 1; i >= 0; i--)
    {
        numStrInv[j] = numStr[i];
        j++;
    }
    for (int i = 0; i <dataTypeSize; i++)
    {
        if (i>=p&&i<p+n){
            if(numStrInv[i]=='1'){
                numStrInv[i] = '0';
            }else{
                numStrInv[i] = '1';
            }
            
        }
    }
    int totValue = 0;
    for(int i=0;i<dataTypeSize;i++){
        char bit = numStrInv[i];
        if(bit=='1'){
            totValue += pow(2,i);
        }
    }
    return totValue;


}


int
main ()
{
  unsigned int x;
  scanf ("%d", &x);
  int p;
  scanf ("%d", &p);
  int n;
  scanf ("%d", &n);
  printf("%d",inverted (x, p, n));
}