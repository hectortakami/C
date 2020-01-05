//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.4)

#include <stdio.h>

void xo(int size) {
    int front = 0;
    int back = size - 1;
    
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if(j == front || j == back)
                printf("x");
            else
                printf("o");
        }
        printf("\n");
        front++;
        back--;
    }
}

int main()
{
    int size;
    scanf("%d", &size);
    xo(size); 
  
}