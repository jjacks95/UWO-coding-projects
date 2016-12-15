#include <stdio.h>
#define FALSE 1
#define TRUE 0

int main() {
    int flag;//for true or false to be checked when number is entered
    int n;
    flag = 1;//setting to false to enter do-while
    do {
        printf("Enter size of magic square: \n");
        scanf("%d", &n);
        //if number is even it will repeat loop else exits
        if (n % 2 == 0) {
            printf("Invalid size, try again...\n");
            flag = 1;
        }else flag = 0;
        
    } while (flag == 1);
    // Get the users magic number and allocate to int n

    
    int magic[99][99];// Create the array size of 99 rows and 99 columns

    int start = (n / 2); // The middle column
    
    int max = n * n; // The final number to be computed
    
    magic[0][start] = 1; // Place the number one in the middle of row 0
    
    // Loop to start placing numbers in the magic square
    int row;
    int column;
    int next_row;
    int next_column;
    int i;
    for (i = 2, row = 0, column = start; i < max + 1; i++) {
        
        if ((row - 1) < 0) { // If going up one will leave the top level of square
            next_row = n - 1; // enter number in bottom row
        }
        else { next_row = row - 1; } //if not go up one row

        
        if ((column + 1) > (n - 1)) { // If column will leave the farthest side of square
            next_column = 0; // Wrap back to first column

        }
        else { next_column = column + 1; } // Otherwise go over one column

        
        if (magic[next_row][next_column] > 0) { // If next number to be entered's position is full
            if (row > (n - 1)) { // If going to row below leaves bottom
                next_row = 0; // Go back to the top
            }
            else {
                next_row = row + 1; // allocates number to next row
                next_column = column; // But stay in same column
            }
        }
        row = next_row;
        column = next_column;
        magic[row][column] = i; // Put the current value in that position
        //continue this process tille i reaches max-1 = n*n
        //then exit into next loop where it builds and prints the size of the array with computed values
    }
    
    // Now let's print the array
    int j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%4d", magic[i][j]);
        }
        printf("\n");
    }
    return 0;
}
