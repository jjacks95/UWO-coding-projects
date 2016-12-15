
public class Stack {
    private int[] stack;
    private int top;
 // PRE: size > 0
 // POST: creates an empty stack that can contain at
 // most size ints
    public Stack(int size) {
        stack = new int[size];
        top = 0;
    // what goes here?
    }
    //returns total # of items on stack
    public int size(){
        return top;
    }

    public boolean empty()  {
        return size() == 0;
    }
    // PRE:
    // POST: returns true iff this stack is full
    public boolean full(){
        return size() == stack.length;
    }

    // PRE: stack is not full
    // POST: x is put onto the top of the stack
    public void push(int x) {
        assert(!full());
        stack[top++] = x;
    }
    // PRE: stack is not empty
    // POST: removes the top element of the stack
    // and returns it
    public int pop(){
        assert(!empty());
        return stack[--top];
    }

    // PRE: stack is not empty
    // POST: returns the top element of the stack
    // but does not delete it
    public int peek()  {
        assert(!empty());
        return stack[top-1];
    }
    public static void main(String[] args){
        // insert ints onto queue until it's full
        Stack stack = new Stack(10);
        for(int i = 0; !stack.full(); ++i) {

          stack.push(i);

          System.out.print(i + " inserted\n");

         } // end of for



        System.out.print("\n");



        // remove and print all of the stack

        while (!stack.empty()) {

          int front = stack.pop();

          System.out.print(front + " removed\n");

        } // end of while
    }    
} // class Stack

