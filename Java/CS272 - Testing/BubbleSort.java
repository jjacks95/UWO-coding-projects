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
public class BubbleSort {

  public static void main(String []args) {
    Random r = new Random();
    int c, d, swap;
    int array[] = new int[10];
 
    System.out.println("Integers to sort");
    for (c = 0; c < array.length; c++) 
      array[c] = r.nextInt(100);
    System.out.println(Arrays.toString(array));

    
    for (c = 0; c < ( array.length - 1 ); c++) {
      for (d = 0; d < array.length - c - 1; d++) {
        if (array[d] > array[d+1]) /* For descending order use < */
        {
          swap       = array[d];
          array[d]   = array[d+1];
          array[d+1] = swap;
        }
      }
    }
 
    System.out.println("Sorted list of numbers");
 
    for (c = 0; c < array.length; c++) 
      System.out.print(array[c]+", ");
    
    }
}
