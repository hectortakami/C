//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.4)

#include <stdio.h>

int medianOf3(int n1, int n2, int n3) {
    if (n1 < n2 && n1 < n3) {
        if (n2 < n3) {
            return n2;
        } else {
            return n3;
        }
    } else if (n2 < n1 && n2 < n3) {
        if (n1 < n3) {
            return n1;
        } else {
            return n3;
        }
    } else { 
        if (n1 < n2) {
            return n1;
        } else {
            return n2;
        }
    }
}


int main()
{
    int n1;
    scanf("%d", &n1);
    int n2;
    scanf("%d", &n2);
    int n3;
    scanf("%d", &n3);
    int medValue = medianOf3(n1,n2,n3);
    printf("%d",medValue);
  
}