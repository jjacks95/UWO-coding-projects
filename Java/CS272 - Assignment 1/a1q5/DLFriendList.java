/**
 * Program name - DLFriendList.java
 * 
 * This program allows for you to enter up to 10 friends names then shows the
 * list of all the friends last name, first name unsorted, then sorts the names
 * by last name, then checks for people's first name in the list giving true 
 * or false for if they are there or not
 *  
 * Athabasca University ID - 3181465
 * Author- Joshua Samuel Jackson
 * Date - August 20, 2014.
 */
package a1q5;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Scanner;

public class DLFriendList {
    //defining List
    DoubleLinkedList<Friend> friendList;

    public DLFriendList(){
        //building empty list
        friendList = new DoubleLinkedList();
    }

    public void addFriend(String fn, String ln){
        //implementing adding to list from back
        friendList.insertBack(new Friend(fn,ln));
    }
    public void displayFriends(){
        //method to display friends list
        Iterator<Friend> it = friendList.iterator();
        while( it.hasNext() ){
            Friend f = it.next();
            //printing of last name, first name
            System.out.println(f.ln+", "+f.fn);            
        }
        System.out.println();
    }
    
    public DLFriendList sortByLastName(){
        //sorting method by last name using HashMap
        //hashing each name into a spot with a designated key of first name to search
        HashMap<String,String> map = new HashMap<String,String>();
        ArrayList<String>al=new ArrayList<String>();
        Iterator<Friend> it = friendList.iterator();
        //while statement to orgranize alphabetically by last name
        while(it.hasNext()){
            Friend f = it.next();
            //key=lastname, value=firstname
            map.put(f.ln, f.fn); 
            //add lastname
            al.add(f.ln); 
        }
        //building collection of last names to sort and return
        java.util.Collections.sort(al);
        Iterator<String> il = al.iterator();
        DLFriendList f = new DLFriendList();
        while( il.hasNext()){
            String ln = il.next();
            f.addFriend(map.get(ln),ln);
        }
        return f;
    }
    // returns firstname if lastname in list, otherwise returns null
    public boolean findFriendsByFirstName(String fn){
        Iterator<Friend> it = friendList.iterator();
        //this method allows for searching by first name
        while(it.hasNext()){
            Friend f = it.next();
            if( f.fn.equals(fn))
                return true;
        }
        return false;
    }
    public static void main(String[] args){
        //main method
        //asking for user input to build list
        DLFriendList friends = new DLFriendList();
        Scanner sc = new Scanner(System.in);
        String[] names = new String[10];
        for( int i = 0; i < names.length; i++ ){
            System.out.print("Enter <first name> <last name>: ");
            names[i] = sc.nextLine();
            friends.addFriend(names[i].split(" ")[0], names[i].split(" ")[1]);
        }
        System.out.println();
        System.out.println("\n\nOriginal Friend List:");
        System.out.println("--------------------------");
        friends.displayFriends();
        DLFriendList f = friends.sortByLastName();
        System.out.println();
        System.out.println("Sorted Friend List:");
        System.out.println("--------------------------");
        f.displayFriends();

        String[] firstNames = new String[names.length];
        //loop to split first name and last name based on space
        for(int i = 0 ; i < names.length; i++)
            firstNames[i]=names[i].split(" ")[0];
        //printing first names and true or false if they are in the list
        System.out.println("Find friend in the list by first name:");
        System.out.println("--------------------------------------");
        
        for(String s: firstNames)
            System.out.println(s+" is in the list: " + f.findFriendsByFirstName(s) );
        // test to see that strangers are not reported as being in the list
        System.out.println("Joe is in the list: " + f.findFriendsByFirstName("Joe") );        
    } 
}
/**
 * Test Cases found in .txt file in the question folder.
 */