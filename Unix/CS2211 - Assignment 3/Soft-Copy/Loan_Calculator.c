#include <stdio.h>
#include <stdlib.h>
#define TRUE 0
#define FALSE 1

int main(void){
    //define variables
    float loan = 0;
    float interest = 0.0, monthly, n;
    int flag;
    char term;
    
    //boolean value flag=true to reset when error occurs
    flag = FALSE;
    //error handling
    
    /*start boolean value = false as long as it stay false it
     *can continue through loop flag = true will reset loop to repeat question
     */
    while(flag == FALSE){
        //print question if statement to check it is an integer with no spaces
        printf("Amount of the Loan: \n$");
        if (scanf("%f%c", &loan, &term) != 2 || term != '\n' ){
            fflush(stdout);
            printf("Not Valid Input\n");
            flag = FALSE;
    }
        else{
            flag = TRUE;
        }

        //print question if statement to check it is an integer with no spaces
        printf("Yearly Interest on Loan: \n");
        if (scanf("%f%c", &interest, &term) != 2 || term != '\n' ){
            fflush(stdout);
            printf("Not Valid Input\n");
            flag = FALSE;
        }
        else{
            flag = TRUE;
        }
    }
        //print question if statement to check it is an integer with no spaces
        printf("Amount of Monthly Payment: \n$");
        if (scanf("%f%c", &monthly, &term) != 2 || term != '\n' ){
            fflush(stdout);
            printf("Not an Float\n");
            flag = FALSE;
        }
        else{
            flag = TRUE;
        }
    
        //print question if statement to check it is an integer with no spaces
        printf("How many monthly payments: \n");
        if (scanf("%f%c", &n, &term) != 2 || term != '\n' ){
            fflush(stdout);
            printf("Not an Float\n");
            flag = FALSE;
        }
        else{
            flag = TRUE;
        }

            //loop to build balance of loan amount
            for (int i = 1; i <= n; i++) {
                loan += (loan * ((interest/12)/100));
                //if statement to stop loop and print monthly payment as remainder of balnce and set balance to 0
                if (loan< monthly){
                    monthly=loan;
                    loan=0;
                    printf("The balance after month %d of the payment of $%.2f is $%.2lf\n", i, monthly, loan);
                    break;
                }
                    loan -= monthly;
                    printf("The balance after month %d of the payment of $%.2f is $%.2lf\n", i, monthly, loan);
            }
        }
