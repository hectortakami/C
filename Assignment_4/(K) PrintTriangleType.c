//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.4)

#include <stdio.h>

void printTriangleType(int a, int b, int c) {
    if(a==b&&a==c&&b==c){
        printf("equilateral");
    }
    else if(a!=b&&a!=c&&b!=c){
        printf("scalene");
    }
    else{
        printf("isosceles");
    }
}

int main()
{
    int x;
    scanf("%d", &x);
    int y;
    scanf("%d", &y);
    int z;
    scanf("%d", &z);
    printTriangleType(x,y,z);
  
}