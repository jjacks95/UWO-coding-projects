/**
 * This is Journal Entry #7
 * journal7.java
 * 
 * This journal entry uses a naive string search found in Unit 8 modified to 
 * allow for user input I used  static methods and vairables just to make 
 * it easier and quicker to build, The program asks for you to enter a string 
 * and a word to search it will return word found if it there and 
 * word not found if not
 * 
 * Author- Joshua Jackson
 * Date - September 3, 2014.
 *.
 */

package journal;
import java.util.Scanner;

public class journal7 {
    //defining variables as static for easy access
    //text is the string, pattern is the word to search
    public static String text;
    public static String pattern;
    
    public static int naive_string_search() {
        //given method to find string
         int n = text.length();
         int m = pattern.length();
         int j = 0;
            for(int s = 0; s <= n-m; s++) {
                while((j < m) && (text.charAt(s+j) == pattern.charAt(j))) j++;}
                if(j == m){
                //output if found
                System.out.println("Word Found!");
                 System.exit(0);
                }
                
                 else{
                    //output if not found
                    System.out.println("Word Not Found.");  
                    System.exit(0);
                }          
        return 0;
            
        }
    
    public static void main(String[] args){
        //scanner for user input
        Scanner sc = new Scanner(System.in);
        //setting users answer to String as the text
        System.out.println("String:");
        text = sc.nextLine();
        //setting pattern to users input
        System.out.println("Word:");
        pattern = sc.nextLine();
        //running program 
        naive_string_search();
        
      
    }
        
}
/**
 * Program Testing 
 * 
 * Test Case #1 (Small String Correct Input)
 * //word found
 * Input:
 * String:
 * Hello, this world is amazing!
 * Word:
 * is
 * Output:
 * Word Found!
 * Output as expected
 * 
 * Test Case #2 (Correct Input)
 * //word not found
 * Input:
 * String:
 * Hello, this world is amazing
 * Word:
 * john
 * Output:
 * Word Not Found
 * Output as Expected
 * 
 * Test Case #3 (no data)
 * //pressing <Enter>
 * 
 * Input:
 * String:
 * <Enter>
 * Word:
 * <Enter>
 * 
 * Output:
 * Word Found!
 * Output as expected both enters match
 * 
 * .
 */

