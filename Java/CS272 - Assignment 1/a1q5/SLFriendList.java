/**
 * Program name - SLFriendList.java
 * 
 *This program prompts the user to input 10 friends names, 
 *then sorts the names alphabetically based on last name
 *  
 * Author- Joshua Jackson
 * Date - August 16, 2014.
 */
package a1q5;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Scanner;

public class SLFriendList {
    //building list
    SingleLinkedList<Friend> friendList;

    public SLFriendList(){
        friendList = new SingleLinkedList();
    }

    public void addFriend(String fn, String ln){
        //inserting entry in list method
        friendList.insertBack(new Friend(fn,ln));
    }
    public void displayFriends(){
        //display method
        Iterator<Friend> it = friendList.iterator();
        while( it.hasNext() ){
            Friend f = it.next();
            System.out.println(f.fn+" "+f.ln);            
        }
    }
    
    public SLFriendList sortByLastName(){
        //sorting by last name using hashmap
        //assinging keys after hashing for sorting 
        HashMap<String,String> map = new HashMap<String,String>();
        ArrayList<String>al=new ArrayList<String>();
        Iterator<Friend> it = friendList.iterator();
        while(it.hasNext()){
            Friend f = it.next();
            //key=lastname, value=firstname
            map.put(f.ln, f.fn); 
            //add lastname
            al.add(f.ln); 
        }
        //sorting collection of last names
        java.util.Collections.sort(al);
        Iterator<String> il = al.iterator();
        SLFriendList f = new SLFriendList();
        while( il.hasNext()){
            String ln = il.next();
            f.addFriend(map.get(ln),ln);
        }
        return f;
    }
    
    public static void main(String[] args){
        //main method
        //user input needed implemented with Scanner
        SLFriendList friends = new SLFriendList();
        Scanner sc = new Scanner(System.in);
        //allowing for ten names to be entered
        String[] names = new String[10];
        for( int i = 0; i < names.length; i++ ){
            System.out.print("Enter <first name> <last name>: ");
            names[i] = sc.nextLine();
            //split name based on space and putting it in the first and secon spot
            friends.addFriend(names[i].split(" ")[0], names[i].split(" ")[1]);
        }
        //displaying list
        friends.displayFriends();
        //displaying sorted list by last name
        SLFriendList f = friends.sortByLastName();
        //printing sorted list
        System.out.println("Order Names By Last Name: ");
        System.out.println("--------------------------");
        f.displayFriends();
    } 
}
/**
 * Test cases found in .txt file in question folder.
 */