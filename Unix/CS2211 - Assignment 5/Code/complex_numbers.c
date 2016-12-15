
#include <stdio.h>
#include <stdlib.h>

//structure complex_t
struct complex_t{
    double real;
    double imaginary;
};

//void declaration of functions
struct complex_t multiply(struct complex_t x, struct complex_t y);
struct complex_t divide(struct complex_t *x, struct complex_t *y);

//main function
int main(void){
    //main vairables from structure complex_t
    struct complex_t input_one, input_two, output_one, output_two;
    
    //asking for input of real and imaginary numbers
    printf("Enter Real Number and Imaginary Number (ex. 4 + i3 enter 4 3): \n");
    scanf("%lf", &input_one.real);
    scanf("%lf", &input_one.imaginary);
    
    printf("Enter Real Number and Imaginary Number: \n");
    scanf("%lf", &input_two.real);
    scanf("%lf", &input_two.imaginary);

    //test print functions
   // printf("Complex #1 is: %.2lf + i%.2lf\n", input_one.real, input_one.imaginary);
   // printf("Complex #2 is: %.2lf + i%.2lf\n", input_two.real, input_two.imaginary);
    
    //assigning declared variables the returns of mult and division functions
    output_one = multiply(input_one, input_two);
    output_two = divide(&input_one, &input_two);
  
    //printing multiplication
    printf("Multiplication: (%.2lf + i%.2lf) x (%.2lf + i%.2lf) = %.2lf + i(%.2lf)\n", input_one.real, input_one.imaginary, input_two.real, input_two.imaginary, output_one.real, output_one.imaginary);
    
    //printing division
    printf("Division: (%.2lf + i%.2lf) / (%.2lf + i%.2lf) = %.2lf + i(%.2lf)\n", input_one.real, input_one.imaginary, input_two.real, input_two.imaginary, output_two.real, output_two.imaginary);

    
}

//mutiply function
struct complex_t multiply(struct complex_t x, struct complex_t y)
{
    //definign structure variable
    struct complex_t sum;
    //mult equation
    sum.real = ((x.real * y.real)-(x.imaginary * y.imaginary));
    sum.imaginary = ((y.real * x.imaginary)+(x.real * y.imaginary));
    
    return sum;
}

//divide function with pointer parameters
struct complex_t divide(struct complex_t *x, struct complex_t *y)
{
    //structure variable with pointer
    struct complex_t *sum;
    
    //using malloc to assign space for sum
    sum = (struct complex_t *)malloc(sizeof(struct complex_t));
    if (!sum) {
        exit(0);
    }
    //checking to see denominator will not be equal to zero
    if ((y->imaginary*y->imaginary)+(y->real*y->real)== 0) {
        printf("Invalid Numbers\n");
        exit(0);
    }else
    //division calc work
    sum->real = ((x->real*y->real)+(y->imaginary*x->imaginary))/((y->imaginary*y->imaginary)+(y->real*y->real));
    sum->imaginary = ((y->real*x->imaginary)-(x->real*y->imaginary))/((y->real*y->real)+(y->imaginary*y->imaginary));
        
        return *sum;

}
