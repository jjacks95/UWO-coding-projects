#include <stdio.h>
#define TRUE 0
#define FALSE 1

int dollars;
int twenties;
int tens;
int fives;
int toonies;
int loonies;
int total;

//void function declaration
void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *toonies, int *loonie);

//pay_amount function
void pay_amount(){
    
    //computing each variable according amount of bill
    twenties = dollars / 20;
    tens = (dollars - (twenties * 20)) /10;
    fives = (dollars - (twenties*20) - (tens*10)) /5;
    toonies = (dollars - (twenties*20) - (tens*10) - (fives*5)) /2;
    loonies = (dollars - (twenties*20) - (tens*10) - (fives*5) - (toonies*2)) / 1;
    total = twenties + tens + fives + toonies + loonies;
}
//main function
int main(void){
    int flag;
    //printing and scanning dollar amount to be computed from user
    do {
        printf("Enter a Dollar Amount: \n");
        scanf("%d", &dollars);
        if (dollars < 0) {
            printf("Invalid Dollar Amount.. \n");
            flag = 1;
            
        }else flag = 0;
    } while (flag == 1);
    
    //calling void function to gain access to computations
    pay_amount(dollars, &twenties, &tens, &fives, &toonies, &loonies);
    
    //printing out all values
    //total amount enters by user
    printf("Total Dollar Amount is equal to $%d\n", dollars);
    //smallest amount of bills with ability to pay amount
    printf("Smallest amount of bills to pay is %d bill(s).\n", total);
    //total twenty dollar bills needed
    printf("%d: Twenty Dollar Bill(s)\n", twenties);
    //total ten dollar bills
    printf("%d: Ten Dollar Bill(s)\n", tens);
    //total five dollar bills
    printf("%d: Five Dollar Bill(s)\n", fives);
    //total two dollar bills
    printf("%d: Two Dollar Bill(s)\n", toonies);
    //total one dollar bills
    printf("%d: One Dollar Bill(s) \n", loonies);
}