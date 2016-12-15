/**
 * Program name - Cards.java
 * 
 * This program uses recursion to fill Y envelopes with X different cards
 * The program will display all possible ways to fill Y envelopes with X cards
 * when order is not important and repetition is not allowed,
 * when order is important and repetition is not allowed,
 * when order is not important and repetition is allowed,
 * when order is important and repetition is allowed
 *  
 * Author- Joshua Jackson
 * Date - September 5, 2014.
 */

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;

public class Cards {
    //method uses if statement to calculate permutation w/o repetition
    public static ArrayList<String> permutationsWithoutRepetition(String[] deck, int envelopes){
        if( envelopes > 1){
            //new array list
            ArrayList<String> rval = permutationsWithoutRepetition(deck, envelopes-1);
            //building array list for cards/deck
            ArrayList<String> hands = new ArrayList<String>();
            for(String card: deck){
                for(String h: rval)
                    //if statement to prevent repetition
                    if( !h.contains(card) ) {
                        hands.add(h.concat(card));
                    }
                }
            return hands;
        }
        // base case
        return new ArrayList<String>(Arrays.asList(deck));
    }
    
    public static ArrayList<String> permutationsWithRepetition(String[] cards, int envelopes){
        //method for permutation with repetition
        if( envelopes > 1){
            //new array list
            ArrayList<String> rval = permutationsWithRepetition(cards, envelopes-1);
            ArrayList<String> hands = new ArrayList<String>();
            for(String c: cards)
                for(String h: rval)
                    //for statement adds card regardless of what in the deck
                    hands.add(h.concat(c));
            return hands;
        }
        return new ArrayList<String>(Arrays.asList(cards));
    }
    
    public static ArrayList<String> combinationsWithRepetition(String[] deck, int envelopes){
        //method for combination of cards with repetition 
        //using base case of permutation with repetition to build array
        ArrayList<String> permutations = permutationsWithRepetition(deck, envelopes);
        HashSet<String> combinations = new HashSet();
        for(String s: permutations){
            char[]ar = s.toCharArray();
            java.util.Arrays.sort(ar);
            combinations.add(new String(ar));
        }
        return new ArrayList(combinations);
    }
    
    public static ArrayList<String> combinationsWithoutRepetition(String[] deck, int envelopes){
        //uses permutationsWithoutRepetition as base case to build array 
        //to repeat with combinations without repetition
        ArrayList<String> permutations = permutationsWithoutRepetition(deck, envelopes);
        HashSet<String> combinations = new HashSet();
        for(String s: permutations){
            char[]ar = s.toCharArray();
            java.util.Arrays.sort(ar);
            combinations.add(new String(ar));
        }
        return new ArrayList(combinations);
    }
    
    public static void main(String[] args){
        // user input
        Scanner in = new Scanner(System.in);
        System.out.print("Enter space separated set of cards: ");
        final String[] cards = in.nextLine().split(" ");
        System.out.print("Enter number of envelopes: ");
        final int numOfEnvelopes = in.nextInt();

        // part(a) order is not important and repetition is not allowed
        ArrayList<String>arr = combinationsWithoutRepetition(cards, numOfEnvelopes);
        java.util.Collections.sort(arr);
        System.out.println("Combinations w/o repetition (" + arr.size()+")");
        for(String h: arr){
            System.out.println(h);
        } 

        // part (b) order is important and repetition is allowed
        arr = permutationsWithRepetition(cards, numOfEnvelopes);
        java.util.Collections.sort(arr);
        System.out.println("Permutations w/ repetition (" + arr.size()+")");
        for(String h: arr){
            System.out.println(h);
        }

        // part (c) order is important and repetition is not allowed
        arr = permutationsWithoutRepetition(cards, numOfEnvelopes);
        java.util.Collections.sort(arr);
        System.out.println("Permutations w/o repetition (" + arr.size()+")");
        for(String s: arr){
            System.out.println(s);
        }

        // part(d) order is not important and repetition is allowed
        arr =  combinationsWithRepetition(cards, numOfEnvelopes);
        java.util.Collections.sort(arr);
        System.out.println("Combinations w/ repetition (" + arr.size()+")");
        for(String h: arr){
            System.out.println(h);
        } 
    }
}
/**
 * Test Case can be found in .txt file in question folder.
 */