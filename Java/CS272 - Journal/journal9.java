/**
 * This is Journal Entry #9
 * journal9.java
 * 
 * This Journal Entry is a practice exam question:
 * 
 * Using recursion, write a program to compute 
 * the Least Common Multiple (LCM) of two numbers
 * 
 * Author- Joshua Jackson
 * Date - September 5, 2014.
 *.
 */

package journal;
import java.util.Scanner;

public class journal9 {
    
    public static int gcd(int a, int b){
        //greatest commond divisor recursive implementation
       if (b == 0) return a;
        else return gcd(b, a % b);
    }
    
    public static int lcm(int a, int b){
        //lowest common multiple method uses gcd to return lcm
        return ((a*b)/gcd(a,b));
        } 
    
    public static void main(String[] args){
        //main method using scanner method for user input
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Larger Integer: ");
        int a = sc.nextInt();
        System.out.println("Enter Smaller Integer: ");
        int b = sc.nextInt();
        //implementing lowest common multiple method
        int c = lcm(a, b);
        System.out.println("The Lowest Common Multiple of "+ a + " and "+ b +" is " + c);
    }
}
/**
 * Program Testing
 * 
 * Test Case #1
 * //correct data
 * 
 * Input:
 * Enter Larger Integer: 1200
 * Enter Smaller Integer: 1000
 * 
 * Output:
 * The Lowest Common Multiple of 1200 and 1000 is 6000
 * 
 * 
 * Test Case #2
 * //partial data
 * 
 * Input:
 * Enter Larger Integer: 10
 * Enter Smaller Integer: <Enter>
 * 
 * Output:
 * Wont run until data is entered, will repeat question till something entered
 * 
 * 
 * Test Case #3
 * //no data
 * 
 * Input:
 * Enter Larger Integer:<Enter>
 * 
 * Output:
 * Repeats Question till answered with a character regarding which exception 
 * is thrown will depend on character, otherwise an integer is entered and the 
 * program runs correctly.
 */