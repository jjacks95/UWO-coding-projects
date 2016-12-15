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

public class Practice{
    
    public static void main(String[] args){
    
    Scanner s = new Scanner(System.in);
    
    System.out.println("Enter Name: ");
    String input = s.nextLine();
    System.out.println("Hello, " + input.toUpperCase() + ", nice to meet you!");
     
    }
 }