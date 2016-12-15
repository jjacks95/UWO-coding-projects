/**
 * Journal Entry #4
 * Using Recursive Programming
 * This simple program question was found from CodingBat.com
 * 
 * We have bunnies standing in a line, numbered 1, 2, ... The odd bunnies (1, 3, ..)
 * have the normal 2 ears. The even bunnies (2, 4, ..) we'll say have 3 ears, because 
 * they each have a raised foot. Recursively return the number of "ears" in the bunny 
 * line 1, 2, ... n (without loops or multiplication)
 * 
 * Author- Joshua Jackson
 * Date - August 28, 2014.
 */

package journal;
import java.util.*;

public class journal4 {
  
   public int bunnyEars2(int bunnies) {
       //if statement using recursion to continously 
       //count the number of bunny ears 
    if(bunnies == 0){
        return 0;
    }
    if(bunnies % 2 != 0){
        return 2 + bunnyEars2(bunnies -1);
    }
    if(bunnies % 2 == 0){
        return 3 + bunnyEars2(bunnies - 1);
    }
    else{
        return bunnies;
    }
  }  
   public static void main(String[] args){
       //scanner for user input
       journal4 tt = new journal4();
       Scanner scan = new Scanner(System.in);
       System.out.println("How many bunnies are in line? ");
       int bunnies = scan.nextInt();
       //tt.bunnyEars2 gives access to the method to count the ears
       System.out.println("The amount of bunny ears are " + tt.bunnyEars2(bunnies));
   }
}
/**
 * Program Testing
 * 
 * Test Case 1
 * 
 * Input:
 * How many bunnies are in line?
 * 10
 * Output:
 * The amount of bunny ears are 25
 * Output as Expected
 * 
 * Test Case 2
 * 
 * Input:
 * How many bunnies are in line?
 * ten
 * Output:
 * Exception thrown InputMismatchException
 * Output as expected
 * 
 * Program is not capable of handling anything 
 * but integers to calculate expected.
 * 
 */