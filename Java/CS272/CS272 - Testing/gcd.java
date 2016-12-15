package testing;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Josh Jackson
 */
import java.util.*;
public class gcd {
    public static int gcd(int p, int q){
        if(q == 0){
            return p;
    }else
            return gcd(q, p % q);
    
    }
public static void main(String[] args){
    Scanner s = new Scanner(System.in);
    System.out.println("Enter Value of P: ");
    int p = s.nextInt();
    System.out.println("Enter Value of Q: ");
    int q = s.nextInt();
    System.out.println("The Greatest Common Divisor for "+ p +"/"+ q +" is equal to "+ gcd(p, q));
}
}
