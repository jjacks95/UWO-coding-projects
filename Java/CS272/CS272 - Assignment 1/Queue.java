public class Queue {
    private int[] queue;
    private int front; //points to first element of queue
    private int back; // points one beyond last element of queue
    private int size; // number of elements in queue
    
    public Queue(int n){
        queue = new int[n];
        front = 0;
        back = 0;
        size = 0;
    }
    public boolean full(){return size==queue.length;}
    public boolean empty(){return size==0;}
    public int size(){return size;}
    public void insert(int x){
        assert(!full());
        queue[back] = x;
        back = (back+1)%queue.length;
        size++;
    }
    public int remove(){
        assert(!empty());
        int retval = queue[front];
        front=(front+1)%queue.length;
        --size;
        return retval;
    }
    public int peek(){
        assert(!empty());
        return queue[front];
    }
    
    public static void main(String[] args){
        // insert ints onto queue until it's full
        Queue queue_ = new Queue(10);
        for(int i = 0; !queue_.full(); ++i) {

          queue_.insert(i);

          System.out.print(i + " inserted\n");

         } // end of for
        System.out.print("\n");

        // remove and print all of the stack
        while (!queue_.empty()) {

          int front = queue_.remove();

          System.out.print(front + " removed\n");

        } // end of while
    }
}
