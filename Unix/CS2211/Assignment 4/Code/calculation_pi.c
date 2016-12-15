#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define TRUE 0
#define FALSE 1

int main(){
    //declare variables
    int n;
    int flag;
    //total x,y values and amount of x,y values in shaded region
    float total = 0.0;
    float shade = 0.0;
    
   //do-while statment to check if user input is a positive integer
    do {
        printf("Enter N: \n");
        scanf("%d", &n);
        if (n < 0) {
            printf("Invalid Entry, Try Again..\n");
            flag = 1;
        }else flag = 0;
        
    } while (flag == 1);
    /*
     using time to create constant to define srand() function which will 
     initialize rand() function and create different numbers each time
     */
    time_t t;
    srand((unsigned) (time(&t)));
    
    float x = 0.0, y = 0.0;
    float pi = 0.0;
    float ratio = 0.0;
    float mean = 0.0;
    float std_dev = 0.0;
    //X and Y value loop which will calculate ratio and mean 10 times
    for (int i = 0; i < 10; i++) {
        //inner loops will calculate the x and y values based on input from user
        for (int i = 0; i < n; i++) {
            float k = (rand() % 100);
            k = k/100;
            x = k;
    
            for (int i = 0; i < n; i++) {
                float k = (rand() % 100);
                k = k/100;
                y = k;
            }
            //if statement to count the valid values in shaded region and total values
            if ((x*x)+(y*y) <= 1) {
                shade++;
                total++;
            }else
                total ++;
        }
        ratio = (shade / total);
        printf("Values: %.2f\n", ratio);
        mean += ratio;
    
    }
    //Standard Deviation For-Loop
    for (int i = 1; i <= n; i++) {
        int s = n;
        std_dev = ((i - mean)/s);
    }
    //standard deviation square root
    std_dev = sqrtf(std_dev);
    //mean calculation
    mean /= 10;
    //ration calculation
    ratio = (shade / total);
    //most accurate pi calculation within in 1 quadrant
    pi = mean*4.0;
    
    //printing values for mean, standard dev, and pi
    printf("Mean = %.2f\n", mean);
    printf("Standard Deviation = %.2f\n", std_dev);
    printf("Pi = %f\n", pi);
    
    //printf("Ratio = %f\n", ratio);
    
    
}