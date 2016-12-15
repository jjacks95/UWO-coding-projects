/**
 * Journal Entry #5
 * journal5.java
 * 
 * Recursion Program given in Unit 7 for Hashing
 * 
 * Athabasca University ID - 3181465
 * Author- Joshua Samuel Jackson
 * Date - August 29, 2014.
 */

package journal;
import java.util.*;
public class journal5 {
    /*thre following methods mystery1,2,3 and 4 are all different methods
      to hash a integer entered. I added the scanner utility to allow for 
      user input.
    */
    public static void mystery1(int a, int b) {
        if (a <= b) {
            int m = (a + b) / 2;
            System.out.print(m + " ");
            mystery1(a, m-1);
            mystery1(m+1, b);
        }
    }

    public static void mystery2(int n) {
        if (n > 0) {
            System.out.print(n + " ");
            mystery2(n-2);
            mystery2(n-3);
            //System.out.print(n + " ");
        }
    }

    public static void mystery3(int n) {
        if (n == 0 || n == 1) return;
        mystery3(n-2);
        System.out.print(n + " ");
        mystery3(n-1);
    }

    public static String mystery4(int n) {
        if (n <= 0) return "";
        return mystery4(n-3) + n + " " + mystery4(n-2) + n + " ";
    }



    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        //int N = Integer.parseInt(args[0]);
        System.out.println("Enter Number: ");
        //allows for user to enter the Int they desire to break down and hash 
        int N = scan.nextInt();
        mystery1(0, N);
        System.out.println();
        mystery2(N);
        System.out.println();
        mystery3(N);
        System.out.println();
        System.out.println(mystery4(N));

    }


}
/**
 * Program Testing
 * 
 * Test Case #1
 * for Mystery1 only
 * 
 * Input: 3
 * Output: 1 0 2 3
 * Output as Expected
 * 
 * This program is a recursive program for hashing values
 * The entered number is run through the program until reaching a>b and exits
 * it stores each value of m as the Key for the broken down digit entered
 * It successfully stores m = 1 for (0, 3) m = 0 for (0, 0) m = 2 for (1,3) 
 * and m = 3 for (3,3)
 * This program uses recursion, avoids duplicates and stores each value in 
 * a empty space
 * 
 * Test Case #2
 * for Mystery2
 * 
 * Input: 3
 * Output: 3 1 1 3
 * Output not as expected should have been 3 1
 * the program gave wrong output because there was a extra print line repeating
 * output
 * 
 * The method uses recursion to stores each value of n as long as n is greater 
 * then 0, it prints n when greater then zero then continues with the new n to 
 * n-2 once the new n is calculated to be below zero it will return to the original
 * n and calculate with n-3 and so on until there is no number greater then zero
 * exiting the program
 * 
 * Test Case #3
 * for Mystery3
 * 
 * Input:3
 * Output:3 2
 * Output as expected
 * 
 * This method uses the algorithm of if n is equal to 0 or 1 it returns to the 
 * original number, the orignal number is first calculated at n-2 until it reaches 
 * the restriction which then sends it back to the original number calculated 
 * n-1 until all variations are accounted for giving every combanation a key for
 * hashing
 * 
 * Test Case #4
 * for Mystery4
 * 
 * Input: 5
 * Output: 2 2 5 3 1 1 3 5
 * Output as expect
 * 
 * This method will run the input through calculation of n-3 and n-2 printing n
 * along the way, its restrictions are n has to be greater then zero or it will
 * exit, just as the previous methods it assigns a value to all the processed 
 * variations for n, but prints n after the calculation as well.
 * 
 */

