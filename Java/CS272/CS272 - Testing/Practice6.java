/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package testing;
import java.util.*;

/**
 *
 * @author Josh Jackson
 */
public class Practice6 {

   
    
    public static void main(String[] args){
   
    int d1;
    int d2;
    int countRolls;
    
    countRolls = 0;
    
    do{
        Random rand = new Random();
        d1 = (rand.nextInt(6) + 1);
        d2 = (rand.nextInt(6) + 1); 
       countRolls++;
              
    }while( d1 != 1 || d2 != 1 );
     
       System.out.println("It took " + countRolls + " rolls to get snake eyes.");
       
    }
   
}
        
    
    
    

