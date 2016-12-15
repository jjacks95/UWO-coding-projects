/**Program name - ReversedSentence.java
 * 
 * This program asks the user to input a string then outputs it backwards
 * specifically designed for sentences
 * 
 * Athabasca University ID - 3181465
 * Author- Joshua Samuel Jackson
 * Date - August 19, 2014.
 */
package assignment2;

import java.util.Arrays;
import java.util.Scanner;
import java.util.Stack;

public class ReversedSentence {

    public static String change5thPosition(String s){
        //for each character at 5th postition to be changed to a 'z'
        char[] str = s.toCharArray();
        for( int i = 5 ; i < str.length ; i++)
            if( i%5 == 0){ str[i] = 'z';}
         
        return new String(str);
    }
 
    public static String printChar2DArray(char[][] arr){
        //initializing array for the three strings to be processed
        String s = "";
        s = s.concat((new String(arr[0])+"\n"));
        s = s.concat((new String(arr[1])+"\n"));
        s = s.concat((new String(arr[2])+"\n"));
        return s;
    }
 
    public static String reverseByCharacter(String s){
        //method to reverse string characters
        char str[] = s.toCharArray();
        for(int i = 0; i < s.length() ; i++){
            //System.out.println(i);
            char temp = s.charAt(i);
            str[i] = s.charAt(s.length()-i-1);
            str[s.length()-i-1] = temp;
        }
        //returns reversed by character string
        return new String(str);
    }
 
    public static String reverseByWord(String s){
        //method to re-order sentence by words rather then letters
        String[] words;
        words = s.split(" ", 0);
        String reversed = "";
        //using a stack to add the words then re-order them
        Stack<String> wordStack = new Stack<String>();
        wordStack.addAll(Arrays.asList(words));
  
        while( !wordStack.isEmpty() ) {
            reversed = reversed.concat( wordStack.pop() );
            reversed = reversed.concat(" ");
        }
        //returns reversed order sentence 
        return reversed.trim();
    }
 
    public static String truncateSentence(String s){
        return s.substring(0, s.length() < 80 ? s.length() : 79);
    }
 
 
    public static void main(String []args){
        //main method
        Scanner sc = new Scanner(System.in);
        //scanner initizliazed 
        //strings defined to take in user input then output based on different methods
        String s1, s2, s3;
        System.out.println("Enter Sentence to be spelt backwards: ");
        s1 = truncateSentence(sc.nextLine());
        //s1 = truncateSentence(s1);
        System.out.println("Enter Sentence to have words re-ordered backwards: ");
        s2 = truncateSentence(sc.nextLine());
        //s2 = truncateSentence(s2);
        System.out.println("Enter Sentence to be combined with every fifth character to be replaced by a 'z': ");
        s3 = truncateSentence(sc.nextLine());
        //s3 = truncateSentence(s3);
 
        char[][] arr = new char[3][80];
         
        String s = reverseByCharacter(s1);
        int j;
        for( j = 0; j < s.length(); j++ )
            arr[0][j] = s.charAt(j);
        arr[0][j] = '\0';
         
        s = reverseByWord(s2);
        for( j = 0; j < s.length(); j++ )
            arr[1][j] = s.charAt(j);
        arr[1][j] = '\0';
         
        s = change5thPosition(s3);
        for( j = 0; j < s.length(); j++ )
            arr[2][j] = s.charAt(j);
        arr[2][j] = '\0';
        
        System.out.println(printChar2DArray(arr));
    }
}

/**
 * Program Output:
 * 1 - Program compiles correctly using jGRASP IDE and J2SDK
 * 
 * 2 - Test Runs:
 * 
 * --Test Run 1(Normal Data Entered):
 * 
 * Program Input:
 * 
 * Enter Sentence to be spelt backwards: 
 * John Doe Was Here
 * Enter Sentence to have words re-ordered backwards: 
 * John Doe Was Here
 * Enter Sentence to be combined with every fifth character to be replaced by a 'z':
 * John Doe Was Here
 * 
 * Expected Program Output:
 * ereH saW eoD nhoJ
 * Here Was Doe John
 * John zoe Wzs Heze
 * 
 * Actual Program Output: as expected
 * 
 * --Test Run 2(no data entered):
 * 
 * Program Input:
 * 
 * Enter Sentence to be spelt backwards: 
 * <Enter>
 * Enter Sentence to have words re-ordered backwards: 
 * <Enter>
 * Enter Sentence to be combined with every fifth character to be replaced by a 'z':
 * <Enter>
 * 
 * Expected Program Output: (nothing)
 * 
 * 
 * Actual Program Output: as expected
 *
 * 
 * 3 - Abnormal Data
 * Not applicable program will generate program 
 * regardless of user input
 * 
 * 4 - Limiting Conditions
 *Not applicable no limitations for input.
 * 
 */