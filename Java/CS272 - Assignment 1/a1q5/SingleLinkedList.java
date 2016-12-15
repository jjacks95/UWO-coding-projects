/**
 * Program name - SingLinkedList.java
 * 
 *This program defines the methods used to output 
 *the Sing Linked List of friends
 * 
 * Athabasca University ID - 3181465
 * Author- Joshua Samuel Jackson
 * Date - August 16, 2014.
 */
package a1q5;

import java.util.Iterator;

public class SingleLinkedList<E>{
    //defining single linked list pointers
    private Link head;
    private Link tail;
    //next() must be issued prior to invoking remove    
    private boolean removeAllowed;     
    
    public SingleLinkedList(){
        //pointers defined 
        head = null;
        tail = head;
        removeAllowed = false;
    }
    
    public boolean empty(){
        return head==null;
    }
    
    public void insertFront(E data){
        //method to insert new entry at head linking the tail to head
        //linking the two allows the list to be dynamic
        head = new Link(data,head);
        if(null == tail) {
            tail = head;
        }
    }
    
    public void insertBack(E data){
        //method to insert entry at the end of the current list
        Link newLink = new Link(data,null);
        if( null == head) {
            head = newLink;
        }
        if( null != tail) {
            tail.next = newLink;
        }
        tail = newLink;
    }
    
    public Iterator<E> iterator(){
        return new SingleLinkedListIterator();
    }
    
    private class SingleLinkedListIterator implements Iterator<E>{
        //implementing linking from current and previous
        private Link<E> currentLink;
        private Link<E> prevLink;
        public SingleLinkedListIterator(){
            currentLink = head;
            prevLink = null;
        }
 
        @Override
        public boolean hasNext() {
            return currentLink != null;
        }
        
        @Override
        public E next() {
            assert(hasNext());
            E data = currentLink.data;
            prevLink = currentLink;
            currentLink = currentLink.next;
            removeAllowed = true;
            return data;
        }
        
        @Override
        public void remove() {
            //remove method
            assert(removeAllowed);
            if( null != prevLink){
                prevLink.next = currentLink.next;
            }
            if( null != currentLink.next ){
                currentLink.next.prev = prevLink;
            }
            currentLink = currentLink.next;
            removeAllowed = false;
        }
    }
}
