/*Program name - CartesianCoordinateSystem.java
 * 
 * This program calculates the distance between two points (x1, y1), (x2, y2), given by the user.
 * Using java.util.Scanner in order to allow for user interaction in the program
 *  
 * Author- Joshua Jackson
 * Date - July 20, 2014
 */

package assignment1;

import java.util.Scanner;

public class CartesianCoordinateSystem {

//defining each part necessary to perform the task of finding the distance
public static void main(String[] args){
	
		double x1; 
		double x2; 
		double y1; 
		double y2;
		double distance;
/*
 * using the imported java utility Scanner to enable the user to input each coordinate
 * using scanner each coordinate is entered and then used to define x1,x2,y1, and y2
 * then put in the distance formula to give the answer
 */
Scanner scan = new Scanner(System.in);
	System.out.println("Enter x1: ");
		 x1 = scan.nextDouble();

	System.out.println("Enter y1: ");
		 y1 = scan.nextDouble();
	
	System.out.println("Enter x2: ");
		 x2 = scan.nextDouble();
	
	System.out.println("Enter y2: ");
		 y2 = scan.nextDouble();
	scan.close();	 
	
//the formula used to calculate the distance between the two points enter by the user	
	distance = Math.sqrt(Math.pow(x2 - x1, 2) + Math.pow(y2 - y1, 2));
	
//output console will give if all entries are acceptable
	System.out.println("This is the distance between the two points entered:"+ distance );
	
	}	
}
