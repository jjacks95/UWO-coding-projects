/*Program name - HailstonSequence.java
 * 
 * This program is designed to let the user enter any digit, and then run the number through the Hailstone Sequence.
 * It then will output every number calculated by the operation of the sequence, 
 * finally telling the user how many steps it took to get to the number 1
 * 
 * Author- Joshua Jackson
 * Date - July 25, 2014
 */

package assignment1;
import java.util.*;
public class HailstoneSequence {
    public static ArrayList<Integer> getHailstoneSequence(int n){
        ArrayList<Integer> ar = new ArrayList<Integer>();
        while(n > 1){
            ar.add(n);
            if( n%2 == 0){
                n = n/2;
            }
            else{
                n = n*3 + 1;
            }
        }
        ar.add(n);
        return ar;
    }

    public static void main(String[] args) {
        ArrayList<Integer> ar;
        System.out.format("Enter a number: ");            
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        in.close();
        ar = HailstoneSequence.getHailstoneSequence(n);
        System.out.format("Hailstone sequence for %d:\n",n);
        Iterator<Integer> itr = ar.iterator();
        while(itr.hasNext())
            System.out.println(itr.next());
        System.out.format("The number of steps to taken to reach 1 is %d\n", ar.size()-1);
    }
 }
