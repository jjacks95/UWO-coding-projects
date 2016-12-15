/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package testing;
import java.util.Scanner;
/**
 *
 * @author Josh Jackson
 */
public class Practice1{
 
     public static void main(String[] args){
    int dimes;
    int nickles;
    int quarters;
    int pennies;
    double dollars;
    
         Scanner scan = new Scanner(System.in);
         
         System.out.println("Enter Pennies:");
         pennies = scan.nextInt();
         System.out.println("Enter Nickles:");
         nickles=scan.nextInt();
         System.out.println("Enter Dimes:");
         dimes=scan.nextInt();
         System.out.println("Enter Quarters:");
         quarters=scan.nextInt();
         
         dollars = ((.25*quarters) + (.10*dimes) + (.05*nickles) + (.01*pennies));
         System.out.println("Total Change in Dollars is: $" + dollars);
        
     }
 
}
