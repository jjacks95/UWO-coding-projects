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
public class Counter {

   private int value = 0;  // Current value of the counter.

   /**
    * Add one to the value of the counter.
    */
   public void increment() {  
      value++;
   }

   /**
    * Returns the current value of the counter.
    */
   public int getValue() {    
      return value;
   }

   public static void main(String[] args){
       Counter headCount, tailCount;
tailCount = new Counter();
headCount = new Counter();
for ( int flip = 0;  flip < 100;  flip++ ) {
   if (Math.random() < 0.5)    // There's a 50/50 chance that this is true.
       headCount.increment();// Count a "head", using headCount
   else
       tailCount.increment() ;   // Count a "tail", using tailCount
}
System.out.println(("There were " + headCount.getValue() + " heads."));
System.out.println(("There were " + tailCount.getValue() + " tails."));
   }
} // end of class Counter