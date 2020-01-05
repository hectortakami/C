//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.4)

#include <stdio.h>

void season(int month, int day) {
    //Spring
    if(month>3&&month<6){
        printf("Spring"); 
    }
    //Summer
    if(month>6&&month<9){
        printf("Summer");   
    }
    //Fall
    if(month>9&&month<12){
        printf("Fall");   
    }
    //Winter
    if(month==1||month==2){
        printf("Winter");   
    }
    
    if(month==3){
        if(day<=15){
            printf("Winter");
        }else{
            printf("Spring");
        }
    }
    if(month==6){
        if(day<=15){
            printf("Spring");
        }else{
            printf("Summer");
        }
    }
    if(month==9){
        if(day<=15){
            printf("Summer");
        }else{
            printf("Fall");
        }
    }
    if(month==12){
        if(day<=15){
            printf("Fall");
        }else{
            printf("Winter");
        }
    }
    //3,6,9,12
    
    
}

int main()
{
    int month;
    scanf("%d", &month);
    int day;
    scanf("%d", &day);
    season(month,day);
  
}