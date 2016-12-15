/**
 * Program name - HashTable.java
 *
 * This program uses hashing to store a list of elements from an array with a key
 * the Key is designed using K mod 13, and all slots start at -1
 * The program will output a Table without growing size with 20 positions
 * and a table with growing that will bend to the input of the program
 * 
 *  
 * Athabasca University ID - 3181465
 * Author- Joshua Samuel Jackson
 * Date - September 10, 2014.
 */

public class HashTable{
    //define hastable and vairable
    int []hashTable;
    int size;
   
    public HashTable(int tableSize){
        //build new hash table
        hashTable = new int[tableSize];
        
        //initialize slots to -1
        for(int i = 0 ; i < hashTable.length ; i++)
            hashTable[i] = -1;
    }
    
    private int hashFunction(int rawval){
        //K mod 13
        return rawval % 13;
    }
    
    public void insert(int val){
        // is table full?
        if( hashTable.length == size ){ 
            int[] newHashTable = new int[hashTable.length * 2];
            for(int i = 0 ; i < newHashTable.length ; i++)
                newHashTable[i] = -1;
            for(int i = 0 ; i < hashTable.length ; i++){
                // old table should be full
                assert(hashTable[i]!=-1); 
                int key = hashFunction(hashTable[i]);
                while( newHashTable[key] != -1){
                    //linear probing
                    ++key; 
                }
                // hash value into new table
                newHashTable[key] = hashTable[i]; 
            }
            // hash table now has room for new entries
            hashTable = newHashTable; 
        }
        int key = hashFunction(val);
        while( hashTable[key] != -1){
            //linear probing
             ++key; 
        }
        hashTable[key] = val;
        size++;
    }
    
    public int getByIndex(int index){
        //get method
        return hashTable[index];
    }
    
    public int capacity(){
        return hashTable.length;
    }
    
    public static void main(String[] args){
        //main method
        //building list of given entries for hashing
        int[] elements = {  1,  5,  21, 26,  39,  14, 15, 16,
                           17,  18, 19, 20, 111, 145, 146   };
        //hashtable of size 20
        HashTable T = new HashTable(20);
        //printing hashtable without growing size
        System.out.println("Test HashTable without growing table size:");
        //insert elements into hash table
        for(int i = 0 ; i < elements.length ; i++){
            T.insert(elements[i]);
        }

        //display results of hashing
        System.out.println("key value");
        for(int i = 0; i < T.capacity(); i++)
            System.out.format("%-4d%d\n",i,T.getByIndex(i));
        
        System.out.println("\nTest HashTable with growing table size:");
        //insert elements into hash table
        for(int i = 0 ; i < elements.length ; i++){
            T.insert(elements[i]);
        }

        System.out.println("key value");
        //display results of hashing
        for(int i = 0; i < T.capacity(); i++)
            System.out.format("%-4d%d\n",i,T.getByIndex(i));
    }
}
/**
 * Test cases are in .txt file within question folder.
 */