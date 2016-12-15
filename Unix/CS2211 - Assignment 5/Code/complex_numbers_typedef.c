#include <stdio.h>
#include <stdlib.h>

//structure complex_t
typedef struct
{
    double real;
    double imaginary;
} complex_t;

//void declaration of functions
complex_t multiply(complex_t x, complex_t y);
complex_t divide(complex_t *x, complex_t *y);

//main function
int main(void){
    
    //declaring variables of structure type
     complex_t input_one, input_two, output_one, output_two;
    
    //asking for user input for imaginary and real numbers
    printf("Enter Real Number and Imaginary Number (ex. 4 + i3 enter 4 3): \n");
    scanf("%lf", &input_one.real);
    scanf("%lf", &input_one.imaginary);
    
    printf("Enter Real Number and Imaginary Number: \n");
    scanf("%lf", &input_two.real);
    scanf("%lf", &input_two.imaginary);

   
    //testing print functions
    //printf("Complex #1 is: %.2lf + i%.2lf\n", input_one.real, input_one.imaginary);
    //printf("Complex #2 is: %.2lf + i%.2lf\n", input_two.real, input_two.imaginary);
    
        output_one = multiply(input_one, input_two);
        output_two = divide(&input_one, &input_two);
    
    //printing multiplication
    printf("Multiplication: (%.2lf + i%.2lf) x (%.2lf + i%.2lf) = %.2lf + i(%.2lf)\n", input_one.real, input_one.imaginary, input_two.real, input_two.imaginary, output_one.real, output_one.imaginary);
    
    //printing division
    printf("Division: (%.2lf + i%.2lf) / (%.2lf + i%.2lf) = %.2lf + i(%.2lf)\n", input_one.real, input_one.imaginary, input_two.real, input_two.imaginary, output_two.real, output_two.imaginary);

    
}

//mutiply function two parameters
complex_t multiply(complex_t x, complex_t y)
{
    //declaring structure variable for fuction
    complex_t sum;
        //multiplication calc work
        sum.real = ((x.real * y.real)-(x.imaginary * y.imaginary));
        sum.imaginary = ((y.real * x.imaginary)+(x.real * y.imaginary));
    
    return sum;
}

//divide function two pointer parameters
complex_t divide(complex_t *x, complex_t *y)
{
    //defining variable pointer
    complex_t *sum;
    //allocating space with check to ensure enough space
    sum = (complex_t *)malloc(sizeof(complex_t));
    if (!sum) {
        exit(0);
    }
    //checking that denominator does not equal zero
    if ((y->imaginary*y->imaginary)+(y->real*y->real) == 0){
        printf("Invalid Numbers\n");
        exit(0);
    }
    //division calc work
    sum->real = ((x->real*y->real)+(y->imaginary*x->imaginary))/((y->imaginary*y->imaginary)+(y->real*y->real));
    sum->imaginary = ((y->real*x->imaginary)-(x->real*y->imaginary))/((y->real*y->real)+(y->imaginary*y->imaginary));
   
    //returning pointer
    return *sum;
}
