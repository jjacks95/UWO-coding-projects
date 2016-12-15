/**
 * Program name - Age.java
 * 
 *This program prompts the user to input 12 ages and then calculates the average
 * age entered and the difference between the oldest and the youngest age
 *  
 * Athabasca University ID - 3181465
 * Author- Joshua Samuel Jackson
 * Date - August 1, 2014.
 */
package a1q1;
import java.util.Scanner;

public class Age {
    //defining array to store entered ages
    int[] ages;
    public Age(){
        ages = new int[12];
    }
    public void setAge(int index, int age){
        //set method
        //restriction on amount of entries allowed in index
        if( index < 12 ) {
            ages[index] = age;
        }
    }
    public int getAge(int index){
        //get method 
        //restriction on amount of entries allowed in index
        if( index < 12 ) {
            return ages[index];
        }
        return -1; // return value for invalid index
    }
    
    public static void main(String[] args){
        //main method
        //Scanner for user input
        Scanner sc = new Scanner(System.in);
        //defining the user entry
        String input;
        //building array
        String[] slist;
        //do-while statement to enter each age and split based on space
        //restricting to 12 names no more no less or repeat of question
        do{ 
            System.out.print("Enter the age of 12 friends (separate ages using a space): ");
            input = sc.nextLine();
            slist = input.split(" ");
        }while(slist.length!=12);

        //counting the ages in order to calculate average 
        int count = slist.length;
        double sum = 0, min = Integer.valueOf(slist[0]), max = Integer.valueOf(slist[0]);
        //while statement to find max and min of array and figure out difference
        while(0 != count--){    
            int num = Integer.valueOf(slist[count]);
            if( num < min ){ min = num; }
            if( num > max ){ max = num; }
            sum += num;
        }
        //output of Average Age and difference between youngest and oldest
        System.out.format("Average age: %.1f\nDifference between oldest and youngest people: %.1f\n", sum/slist.length, max-min);
    }
}
/**
 * Test Cases done on .txt file in same question folder.
 */