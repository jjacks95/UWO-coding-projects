package testing;
import java.util.Scanner;
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Josh Jackson
 */
public class Practice3_Euclid {
    
    // recursive implementation
    public static int gcd(int p, int q) {
        if (q == 0) return p;
        else return gcd(q, p % q);
    }
    
    public static void main(String[] args) {   
        Scanner s = new Scanner(System.in);
        System.out.println("Enter Larger number (P): ");
        int p = s.nextInt();
        System.out.println("Enter Smaller number (Q): ");
        int q = s.nextInt();
        //int p = Integer.parseInt(args[0]);
        //int q = Integer.parseInt(args[1]);
        int d  = gcd(p, q);
        System.out.println("Greatest Common Divisor (GCD) (" + p + ", " + q + ") = " + d);
       
    }
}
    

