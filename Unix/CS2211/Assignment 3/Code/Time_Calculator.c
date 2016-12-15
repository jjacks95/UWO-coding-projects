#include <stdio.h>
#include <stdlib.h>

#define FALSE 1
#define TRUE 0
#define Subtract 1
#define Add 0


int main(void){
    //defining variables
    
    //time of day
    int tod;
    //time duration
    int td;
    //boolean operators for loops and switch statement
    int flag, operation;
    //minutes and hours separated for TOD and TD
    int part1_tod, part2_tod, part1_td, part2_td;
    //minutes and hours for printing end values
    int minutes, hours;
    //temp hours for adjusting time, carry over effect
    int temphours;

    //do-while to take input of Time of Day and separate into two parts
    do {
        printf("Enter a Time of Day based on 24 hour clock: \n");
        fflush(stdout);
        scanf("%d", &tod);
    
        
        //operation to separate the minutes and hours of TOD
        part1_tod = tod / 100;
        part2_tod = tod % 100;
        
        //Error Checking
        if (part1_tod < 00 || part1_tod > 23) {
            printf("Input Invalid.\n");
            fflush(stdout);
            flag = FALSE;
        }
        else if (part2_tod < 00 || part2_tod >= 60){
            printf("Input Invalid. \n");
            fflush(stdout);
            flag = FALSE;
        }
        else{
            flag = TRUE;
        }
    }while (flag == FALSE);
    
    
    
    //do-while loop to get user input for Time Duration and separate minutes and hours
    do {
        printf("Enter a Time Duration to adjust 24 hour clock by: \n");
        fflush(stdout);
        scanf("%d", &td);
        
        //assigning operation value for switch statement
        if (td < 0) {
            operation = Subtract;
        }
        else{
            operation = Add;
        }
        
        //absolute value operation to make everything positive after assigning which method to follow (add, or sub)
        td = abs(td);
        
        //operation to separate into two parts minutes and hours
        part1_td = td / 100;
        part2_td = td % 100; //CHANGED THIS
        
        //Error Checking
        if (part1_td > 99) {
            printf("Input Invalid. \n");
            fflush(stdout);
            flag = FALSE;
        }
        else if (part2_td < 0 || part2_td >= 60){
            printf("Invalid Input. \n");
            fflush(stdout);
            flag = FALSE;
        }
        else{
            flag = TRUE;
        }
    } while(flag == FALSE);
    
    
    
    //switch operation to determine how to adjust time
    switch(operation){
            
        //if time duration is negative
        case Subtract:
            if (part2_td > part2_tod) {
                part1_tod = part1_tod - 1;
                part2_tod = 60 + part2_tod;
                minutes = part2_tod - part2_td;
                //temphours = part1_tod + 1;
                hours = abs(part1_tod - part1_td);
                //hours = hours + temphours;
                
            }
            else if (part2_td <= part2_tod) {
                minutes = part2_tod - part2_td;
                hours = part1_tod - abs(part1_td);
            }
            
            if (minutes >= 60) {
                minutes = minutes - 60;
                temphours = part1_tod + 1;
                hours= abs(part1_tod - part1_td);
                hours = hours + temphours;
            }
            
            //if minutes is less the 10 it will print with a 0 in front avoidin time such 10:1
            //if hours are greater then 24 it will wrap around to 00:00
            if(minutes < 10 && hours <=23){
                if (hours >= 10) {
                    printf("The time after adjustment is %d:0%d\n", hours, minutes);
                    fflush(stdout);
                }
                else{
                    printf("The time after adjustment is 0%d:0%d\n", hours, minutes);
                    fflush(stdout);
                }
                break;
            }
            if (minutes < 10 && hours > 23){
                hours = hours - (hours / 24)*24;
                if (hours >= 10) {
                    printf("The time after adjustment is %d:0%d\n", hours, minutes);
                }
                else{
                    printf("The time after adjustment is 0%d:0%d\n", hours, minutes);
                    fflush(stdout);
                }
                break;
            }
            if (minutes >= 10 && hours > 23) {
                hours = hours - (hours / 24)*24;
                if (hours >= 10) {
                    printf("The time after adjustment is %d:%d\n", hours, minutes);
                    fflush(stdout);
                }
                else{
                    printf("The time after adjustment is 0%d:%d\n", hours, minutes);
                    fflush(stdout);
                }
                break;
            }
            
            if (minutes >= 10 && hours <= 23) {
                //hours = hours - (hours / 24)*24;
                if (hours >= 10) {
                    printf("The time after adjustment is %d:%d\n", hours, minutes);
                    fflush(stdout);
                }
                else{
                    printf("The time after adjustment is 0%d:%d\n", hours, minutes);
                    fflush(stdout);
                }
                break;
            }
            break;

            //if time duration is positive
        case Add:
            minutes = part2_tod + part2_td;
            if (minutes >= 60){
                minutes = minutes - 60;
                temphours = 1;
                hours = part1_tod + part1_td + temphours;
            }
            else if (minutes <60){
                minutes = part2_tod + part2_td;
                hours = part1_tod + part1_td;
            }
           
            if(minutes < 10 && hours <=23){
                if (hours < 10) {
                    printf("The time after adjustment is 0%d:0%d\n", hours, minutes);
                    fflush(stdout);
                }
                else{
                    printf("The time after adjustment is %d:0%d\n", hours, minutes);
                    fflush(stdout);
                }
                break;
            }
            
            if (minutes < 10 && hours > 23) {
                hours = hours - (hours / 24)*24;
                if (hours < 10) {
                    printf("The time after adjustment is 0%d:0%d\n", hours, minutes);
                    fflush(stdout);
                }
                else{
                    printf("The time after adjustment is %d:0%d\n", hours, minutes);
                    fflush(stdout);
                }
                break;
            }
            
            if (minutes >= 10 && hours <= 23) {
                hours = hours - (hours / 24)*24;
                if (hours < 10) {
                    printf("The time after adjustment is 0%d:%d\n", hours, minutes);
                    fflush(stdout);
                }
                else{
                    printf("The time after adjustment is %d:%d\n", hours, minutes);
                    fflush(stdout);
                }
                break;
            }
            
            if(minutes >= 10 && hours > 23){
                hours = hours - (hours / 24)*24;
                if (hours < 10) {
                    printf("The time after adjustment is 0%d:%d\n", hours, minutes);
                    fflush(stdout);
                }
                else{
                    printf("The time after adjustment is %d:%d\n", hours, minutes);
                    fflush(stdout);
                }
                break;
            }
            break;
    }
}
