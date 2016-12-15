/**
 * Journal Entry 6
 * journal6.java
 * 
 * This program allows for a large amount of information to be stored, 
 * using hash methods to assign a key for easy retrieval
 * 
 * Author- Joshua Jackson
 * Date - September 1, 2014.
 */

package journal;


import java.util.Hashtable;
import java.util.Enumeration;
import java.util.Scanner;

public class journal6 {
     public static void main(String[] argv) {

    // Construct and load the hash. This simulates loading a
    // database or reading from a file, or wherever the data is.

    Hashtable h = new Hashtable();
    
    // The hash maps from company name to address.
    // In real life this might map to an Address object...
    h.put("Adobe", "Mountain View, CA");
    h.put("IBM", "White Plains, NY");
    h.put("Learning Tree", "Los Angeles, CA");
    h.put("Microsoft", "Redmond, WA");
    h.put("Netscape", "Mountain View, CA");
    h.put("O'Reilly", "Sebastopol, CA");
    h.put("Sun", "Mountain View, CA");

    // Two versions of the "retrieval" phase.
    // Version 1: get one pair's value given its key
    // (presumably the key would really come from user input):
    Scanner scan = new Scanner(System.in);
    System.out.println("Enter name you wish to see location for: ");
    String queryString = scan.nextLine();//"O'Reilly";
    System.out.println("You asked about " + queryString + ".");
    String resultString = (String) h.get(queryString);
    System.out.println("They are located in: " + resultString);
    System.out.println();

    // Version 2: get ALL the keys and pairs
    // (maybe to print a report, or to save to disk)
    Enumeration k = h.keys();
    System.out.println("All Keys and Pairs: ");
    while (k.hasMoreElements()) {
      String key = (String) k.nextElement();
      System.out.println("Key " + key + "; Value " + (String) h.get(key));
    }
  }
}

/**
 * Program Testing
 * 
 * Test Case #1
 * individual access to a key
 * 
 * Input:
 * Enter name you wish to see location for: Sun
 * Output:
 * You asked about Sun
 * They are located in: Mountain View, CA
 * 
 * Output as expected
 * 
 * Test Case #2
 * Showing all keys
 * 
 * Input: just compile and run
 * 
 * Output:
 * All Keys and Pairs: 
 * Key Sun; Value Mountain View, CA
 * Key IBM; Value White Plains, NY
 * Key Adobe; Value Mountain View, CA
 * Key Netscape; Value Mountain View, CA
 * Key Microsoft; Value Redmond, WA
 * Key O'Reilly; Value Sebastopol, CA
 * Key Learning Tree; Value Los Angeles, CA
 * 
 * Output as expected
 * 
 * In testing this hash function each place was separated by Name and Location
 * the Keys were the name, allowing for access
 * This program showed two possible outcomes either printing all the names with
 * a while statement or getting user input to access individual places based on 
 * name, this is a very useful tool as it allows for large amount of data to be 
 * easily accessed through the use of small amount of identifiers
 * although they use difficult names with capital and punctuation you could just 
 * as easily use numbers to be the key for the large amount of info.
 */