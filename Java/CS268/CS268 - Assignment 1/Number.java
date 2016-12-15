/*Program name - Number.java
 * 
 * The purpose of this program is to run a loop of numbers from 1-113 through criteria 
 * Outputting different words if the number corresponds with given criteria.
 * 
 * Author- Joshua Jackson
 * Date - July 30, 2014
 */

package assignment1;
import java.util.*;
public class Number {
	//the methods and math functions being used to check each number in the loop and see if it fits any of these categories
	public static boolean isDivisibleBy5(int n){ return n%5 == 0; }
	public static boolean isDivisibleBy7(int n){ return (2*n+1) % 7 == 0; }
	public static boolean isOdd(int n){ return n%2 != 0; }
	public static boolean isPrime(int n){
		for( int i = 2 ; i <= n/2 ; i++ )
			if( n%i == 0) return false; 
		return true;
	}

	public static ArrayList<String>Iterate(){
		//defining each string with the words that will be displayed if the number fits the criteria
		String div5 = ", hi five";
		String div7 = ", wow";
		String isodd = " is odd";
		String isprime = ", prime";
		ArrayList<String> arr = new ArrayList<String>();
		System.out.println("0");
		for( int n = 1 ; n <= 113 ; n++ ){
			String temp = Integer.toString(n);
			if( isOdd(n) ) temp = temp.concat(isodd);
			if( isDivisibleBy5(n) ) temp = temp.concat(div5);
			if( isDivisibleBy7(n) ) temp = temp.concat(div7);
			if( isPrime(n) ) temp = temp.concat(isprime);
			arr.add(temp);	
		}
		return arr;
	}
	//the method to output the numbers and the words they are associated with by fitting the criteria
	public static void main(String args[]){
		ArrayList<String> ar = Number.Iterate();
		for( String str: ar)
			System.out.format("%s\n\n", str);
	}
}
