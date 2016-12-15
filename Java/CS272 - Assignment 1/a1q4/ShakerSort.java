/**
 * Program name - ShakerSort.java
 * 
 * This program demonstrates an alternative sorting method to bubble sort
 *  
 * Author- Joshua Jackson
 * Date - August 15, 2014.
 */
package a1q4;

public class ShakerSort{
    public static void swap(int[]a,int left,int right){
        //swap method to allow passing of array form left to right
        int temp = a[left];
        a[left]=a[right];
        a[right]=temp;
    }
    public static void bubbleSort(int[] a){
        boolean exchange;
        //after one pass largest unsorted # propagates to final position
        // no range shortening
        do{ 
            exchange = false;
            for( int i = 1 ; i < a.length ; i++ ) 
                if( a[i-1] > a[i] ){
                    swap(a,i-1,i);
                    exchange = true;
                }
        }while(exchange);
    }
    public static void bubbleSortRangeShortening(int[] a){
        boolean exchange;
        int n = a.length;
        //after one pass largest unsorted # bubbles to final position
        // no range shortening
        do{ 
            exchange = false;
            for( int i = 1 ; i < n ; i++ ) 
                if( a[i-1] > a[i] ){
                    swap(a,i-1,i);
                    exchange = true;
                }
            n--; // shorten range
        }while(exchange);
    }
    public static void shakerSort(int[] a)
    {
       // phase p of shaker sort 
       // first do left to right bubbling pass
       for( int p = 1; p <= a.length / 2; p++ ){
          for( int i = p - 1; i < a.length - p; i++ )
             if( a[i] > a[i+1] )
                swap(a, i, i + 1);

          // now do right to left bubbling pass
          for (int i = a.length - p - 1; i >= p; i--)
             if( a[i] < a[i-1] )
                swap(a, i, i - 1);
       }
    }
    private static int[][] getTestCase(){
        /**
         * test case array of numbers both sorted from largest to smallest 
         * largest to smallest, random, and then test cases of one number 
         * and no numbers.
         */
        
        int[][] a = {   {1,2,3,4,5,6,7,8,9,10},
                        {10,9,8,7,6,5,4,3,2,1},
                        {1,3,2,4,5,7,6,8,10,9},
                        {1},
                        {} 
                    };
        return a;
    }
    
    public static void main(String[] args){
        //main method
        //Printing test cases
        System.out.println("\nShaker sort test cases:");
        int[][] testCase = getTestCase();
        for(int[] t: testCase){
            //before sorting the test case
            System.out.format("%-18s","Before sorting: ");            
            for(int i: t)
                System.out.print(i+",");
            System.out.println();
            shakerSort(t);
            //after sorting test case
            System.out.format("%-18s","After sorting: ");
            for(int i: t)
                System.out.print(i+",");
            System.out.println();
        }
    }
}/**
 * Test Cases done on .txt file in same question folder.
 */