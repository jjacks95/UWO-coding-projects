/**
 * Program name - RandomSumGame.java
 * 
 * This program is designed to output the simulation game of craps, using random
 * number generator, it rolls the dice accroding the rules of the game for the
 * user 3 times
 * 
 * Author- Joshua Jackson
 * Date - August 17, 2014.
 **/
package assignment2;
import java.util.Random;
import java.util.Scanner;


public class RandomSumGame {
    //definition of each variable used in the program
    int d1;
    int d2;
    int sum;
    int valuePoint;
    String status;
    boolean start;
  



public void rollDice(){
    //random number generator specific to dice rolling
    Random rand = new Random();
    d1 = (rand.nextInt(6) + 1);
    d2 = (rand.nextInt(6) + 1);
    sum = d1 + d2;
    
} 
public void play(){
    //in this method the rules of the game are defined and system output is defined
    //as well as if the roll were to reach a valuePoint rather then a conclusion
    //the next steps are defined
    
    status = "playing";
    rollDice();
    valuePoint = sum;
    
    if(sum < 4 || sum == 12){
    System.out.println("You rolled " + d1 +"+"+ d2 +"="+ sum +";"+ "You Lose.");
    status = "Lose";
    }  
    else if(sum == 7 || sum == 11){
    System.out.println("You rolled " + d1 +"+"+ d2 +"="+ sum +";"+ "You Win.");
    status = "Win";
    }
    else {
    System.out.println("You rolled " + d1 +"+"+ d2 +"="+ sum +";"+ 
                       "you establish the value point "+ valuePoint +" roll again.");
    }
    while(status.equals("playing") ){
       rollDice();
       play(d1, d2);
    }
}
public void play(int d1, int d2){  
    //the next steps defined if valuePoint is reached and the player must roll again
    sum = d1 + d2;
    if(valuePoint == sum){
    System.out.println("You rolled " + d1 +"+"+ d2 +"="+ sum +";"+ "You Win.");
    status = "Win";
    }
    else if(sum == 7){
    System.out.println("You rolled " + d1 +"+"+ d2 +"="+ sum +";"+ "You Lose.");
    status = "Lose";
    }
    else {
    System.out.println("You rolled " + d1 +"+"+ d2 +"="+ sum +";"+ "roll again.");   
    }
}

public static void main(String[] args){
    //main method starting the game and calling methods to run
    //initiating the game 3 times total then exiting
    Scanner s = new Scanner(System.in);
    System.out.println("Press Anything to Begin: ");
    s.nextLine();
    RandomSumGame crp = new RandomSumGame();
    int numOfPlays = 3;
        while(numOfPlays-- > 0){
            crp.play();
            
        }
    }
}  
/**
 * Program Output:
 * 1 - Program compiles correctly using jGRASP IDE and J2SDK
 * 
 * 2 - Test Runs:
 * 
 * --Test Run 1(Normal Data Entered):
 * 
 * Program Input:
 * 
 * Press Anything to Begin:<Enter>
 *
 * 
 * Expected Program Output:
 * Program runs three times and outputs the rolls, wins, and losses
 * 
 * Actual Program Output: as expected
 *
 * 
 * 3 - Abnormal Data
 *  Not applicable program will generate program 
 *  three times regardless of user input
 * 
 * 4 - Limiting Conditions
 *  Not applicable no limitations for input.
 * 
 */