/**
 * Program name - DoubleLinkedList.java
 * 
 * This program is the definition of a Double Linked List
 * to be used in the DLFriendList.java
 * 
 * Athabasca University ID - 3181465
 * Author- Joshua Samuel Jackson
 * Date - August 20, 2014.
 */
package a1q5;
import java.util.Iterator;

public class DoubleLinkedList<E>{
    private Link head;
    private Link tail;
        
    public DoubleLinkedList(){
        head = null;
        tail = head;
    }
    
    public boolean empty(){
        return head==null;
    }
    
    public void insertFront(E data){
        //method to insert name at front of list for new link
        head = new Link(data,head,null);
        if( null != head.next)
            head.next.prev = head;
        if(null == tail) {
            tail = head;
        }
    }
    
    public void insertBack(E data){
        //method to insert name at back of list 
        Link newLink = new Link(data,null,tail);
        if( null != tail) {
            tail.next = newLink;
        }
        else{ 
            head = newLink; //only element in list
        }
        tail = newLink;
    }
    
    public Iterator<E> iterator(){
        return new DoubleLinkedListIterator();
    }
        
    private class DoubleLinkedListIterator implements Iterator<E>{
        private Link<E> currentLink;
        private Link<E> prevLink;
        //next() must be issued prior to invoking remove
        private boolean removeAllowed;
        
        public DoubleLinkedListIterator(){
            //defining links
            currentLink = head;
            prevLink = null;
            removeAllowed = false;
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
    //Test Cases main method
    /*
    public static void main(String[] args){
        DoubleLinkedList<Friend> q = new DoubleLinkedList();
        DoubleLinkedList<Friend> s = new DoubleLinkedList();
        q.insertFront(new Friend("a","b"));
        q.insertFront(new Friend("c","d"));
        s.insertFront(new Friend("a","b"));
        s.insertFront(new Friend("c","d"));
        Iterator<Friend> it = q.iterator();
        while(it.hasNext()){ 
            Friend f = it.next();
            System.out.println(f.fn+" "+f.ln);
        }
        System.out.println();
        it = s.iterator();
        while(it.hasNext()){ 
            Friend f = it.next();
            System.out.println(f.fn+" "+f.ln);
        }
    }
    */
}
