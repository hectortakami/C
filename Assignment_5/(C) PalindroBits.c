//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.5)

#include <stdio.h>

void tobinstr(int value, int bitsCount, char* output)
{
    int i;
    output[bitsCount] = '\0';
    for (i = bitsCount - 1; i >= 0; --i, value >>= 1)
    {
        output[i] = (value & 1) + '0';
    }
}

unsigned int palindroBits(unsigned int n)
{
    int dataTypeSize = sizeof(n)*8;
    char numStr[dataTypeSize];
    tobinstr(n,dataTypeSize,numStr);
    //printf("%s\n",numStr);
    
    int mSbIndex = 0; //Most Significance Bit Index
    for(int i=0;i<dataTypeSize;i++){
        char bit = numStr[i];
        if(bit=='1'){
            break;
        }else{
            mSbIndex++;
        }
    }
    int lsBI = dataTypeSize-1; //Less Significance Bit Index
    for(int i=mSbIndex;i<dataTypeSize;i++){
        char topBit = numStr[i];
        char bottomBit = numStr[lsBI];
        if(topBit!=bottomBit){
            //printf("%c - %c\n",topBit,bottomBit);
            return 0;
        }
        //printf("%c - %c\n",topBit,bottomBit);
        lsBI--;
    }
    
    return 1;
}
 

int main()
{
    unsigned int n;
    scanf("%d", &n);
    printf("%d",palindroBits(n));
}