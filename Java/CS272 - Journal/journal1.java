/**
 * Journal Entry #1
 * journal1.java
 * 
 * This is my first Journal entry, using a for-each loop to display elements of
 * an array
 * 
 * Author- Joshua Jackson
 * Date - August 15, 2014.
 */

package journal;

public class journal1 {
   
     public static void main(String[] args) {
      //the array
      int[] list = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
   
      //the definithion of the for-each loop
      foreachEntry(list);
   }
   public static void foreachEntry(int[] data){
      /**
       * the for-each loop will call each entry of the array and display it
       * much simpler and quicker then a regular for loop
       */
      System.out.println("Display the content of array:");
      for (int a  : data) {
         System.out.print( a + " ");
      }
   }
}
/**
 * Program Test Cases/ Output
 * 
 * Test Case 1:
 * 
 * program compiles correctly
 * 
 * input: int[] list = 10, 20, 30, 40, 50, 60, 70, 80, 90, 100
 * 
 * Output: Display content of array: 
 * 10, 20, 30, 40, 50, 60, 70, 80, 90, 100
 * 
 * Output as expected
 * 
 * The program did not have alternative test cases, no matter the entry in the
 * array the program will print assuming it follows the usual restrictions of 
 * java language
 * 
 * check self reflections for errors in first journal entry.
 */
    

