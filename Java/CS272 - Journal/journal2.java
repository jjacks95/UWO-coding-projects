/**
 * Journal Entry #2
 * journal2.java 
 * 
 * In this journal entry I am using another for-each method, but instead of a 
 * int array being printing I am able to use a split method to separate a String
 * by a character within an Array
 * 
 * Athabasca University ID - 3181465
 * Author- Joshua Samuel Jackson
 * Date - August 18, 2014.
 *
 */

package journal;

public class journal2 {

	public static void main(String []args) {
                //string definined
		String alpha;
                //string array defined
		alpha =" A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, "
                        + "T, U, V, W, X, Y, Z, Now I know my ABC's next time won't you sing with me!";
                            
	      for (String Strsplit: alpha.split(" , ")){
                //for-each loop used to split list by character "," then printed on different lines
                    
		         System.out.println(Strsplit);
                         //output to be shown printed on separate lines
		      }
    }	
}
/**
 * Program testing:
 * Test Case 1:
 * Input: 
 * String array
 * 
 * Output: 
 * not as expected entire array printed as one group rather then being separated
 * 
 * Test Case 2:
 * 
 * Input: 
 * String Array
 * 
 * Output: 
 * As expected
 * 
 * No unknowns or partial or incorrect inputs everything is hard coded 
 * anything put in the String would be processed and compiled and split based 
 * on a character of my choice if no character was present in the String 
 * it would print entire string in one line
 * 
 * check self reflection gives details on unexpected output 
 * although not incorrect,not as expected.
 */