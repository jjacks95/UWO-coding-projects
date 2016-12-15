/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package testing;

/**
 *
 * @author Josh Jackson
 */
import java.util.*;
public class StringArray {
    
    public static void main(String[] args){
        Scanner s = new Scanner(System.in);
        String list[] = new String[1000];
        
        System.out.println("Enter String: ");
        for (int i = 0; i < list.length; i++){
            list[i] = s.next();
        }
   
    }
   
}
