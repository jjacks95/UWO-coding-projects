/**
 * Program name - Link.java
 * 
 * This program defines the link from one data entry to the next
 * 
 * Athabasca University ID - 3181465
 * Author- Joshua Samuel Jackson
 * Date - August 16, 2014.
 */
package a1q5;

public class Link<E> {
    //defined variables for Link
    public E data;
    public Link<E> next;
    public Link<E> prev;
    Link(E data){ this(data,null); }
    Link(E data, Link n){
        this.data = data; 
        next = n;
    }
    Link(E data, Link n, Link p){
        this.data = data; 
        next = n;
        prev = p;
    }
}
