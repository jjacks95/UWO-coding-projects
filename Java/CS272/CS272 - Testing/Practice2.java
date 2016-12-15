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
public class Practice2 {
    public static void main(String[] args){
        int N;
        int dozen;
        int eggs;
        int gross;
        Scanner scan = new Scanner(System.in);
        System.out.println("How many eggs do you have? ");
        N = scan.nextInt();
        dozen = N%144/12;
        eggs = N%12;
        gross = N/144;
        System.out.println("Your number of eggs is "+gross+ " gross, " + dozen+" dozen, "+ "and "+eggs);
    }
}
