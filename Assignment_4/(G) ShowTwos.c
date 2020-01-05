//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.4)

#include <stdio.h>

int showTwos(int num) {
    printf("%d = ",num);
	while (num % 2 == 0) {
		printf("2 * ");
		num = num / 2;
	}
	printf("%d",num);
}

int main()
{
    int num;
    scanf("%d", &num);
    showTwos(num);
  
    
}