/**
 * Journal Entry #3
 * journal3.java
 * 
 * Using sort algorithms posted in Week 5 and 6 
 * I will implement insertion sort
 * 
 * Athabasca University ID - 3181465
 * Author- Joshua Samuel Jackson
 * Date - August 20, 2014.
 */

package journal;


public class journal3 {
    
   public static void InsertionSort( int [ ] num){
       //insertion sort algorithm
     int j;                     // the number of items sorted so far
     int key;                // the item to be inserted
     int i;  

     for (j = 1; j < num.length; j++)    // Start with 1 (not 0)
    {
           key = num[ j ];
           for(i = j - 1; (i >= 0) && (num[ i ] < key); i--)   // Smaller values are moving up
          {
                 num[ i+1 ] = num[ i ];
          }
         num[ i+1 ] = key;    // Put the key in its proper location
     }
   }
  public static void printValues(int[ ] num) {  
      //loop for ordered array largest to smallest
    for (int k = 0; k < num.length; k++) {  
    System.out.print(num[k] + " ");  
        }  
    System.out.println();  
        }  
  public static void printSmallValues(int[ ] num) { 
      //loop for reverse order of array
    for (int k = num.length - 1; k >= 0; k--) {  
    System.out.print(num[k] + " ");  
        }  
    System.out.println();  
        }  
    

  public static void main(String[] args) {  
      //defined array
    int num[] = { 2, 4, 9, 6, 23, 12, 34, 0, 1 };  
  
    System.out.print("Array values Before Sorting: ");  
    printValues(num); // array before sort  
  
    InsertionSort(num); // sorting array using 'Insertion Sort Algorithm'  
  
    System.out.print("Array values After Sorting Largest to Smallest: ");  
        printValues(num); // array after sort  
    
    System.out.print("Array values After Sorting Smallest to Largest: ");
        printSmallValues(num);
    }  
}
/**
 * Program Testing
 * 
 * Test Case 1:
 * 
 * Input: hard coded array
 * Output:
 * Array values Before Sorting: 2 4 9 6 23 12 34 0 1 
 * Array values After Sorting Lasrgest to Smallest: 34 23 12 9 6 4 2 1 0 
 * Array values After Sorting Smallest to Largest: 0 1 2 4 6 9 12 23 34 
 * 
 * Output as Expected
 * 
 * Errors are documented in self-reflection journal entry
 * No vairation in input as it uses what ever is given in the int array.
 */