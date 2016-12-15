#define FALSE 1
#define TRUE 0

#include <stdio.h>

int main(void){
    //defining variables
    double number;
    double e = 1;
    double temp;
    int i, j;
    int flag;
    //char term;
    
    flag = FALSE;
    while (flag == FALSE) {
    printf("Enter a floating number (anything with lots of decimal places)\n");
        if(scanf("%lf", &number) != 1 || number <= 0){
            printf("Input is Invalid\n");
            flag = FALSE;
        }
        else{
            flag = TRUE;
        }
        
    }
    
    //outer loop calculating how many terms for factorial
    for (i = 1; i < 20; i++) {
            //defining i as temp to be used in next loop for factorial
            temp = i;
        //loop uses i-1 time temp to process factorial continuously
        for (j = i-1; j > 0; j--){
            temp = temp * j;
        }
            //e is equal to e + 1/factorial
            e = e + (1/temp);
        //if statement to end loop when factorial is less then inputted number from user
        if((1/temp) < number){
            printf("e is equal to %.15lf, it took %d terms to reach a number less than inputted value.\n", e, i);
            break;
        }
    }
}

