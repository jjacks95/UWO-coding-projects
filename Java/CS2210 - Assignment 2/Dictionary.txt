import java.util.LinkedList;

public class Dictionary implements DictionaryADT{
	
	//initializing private variables
	//T is the linked list created to hold entires
	private LinkedList<DictEntry>[] T;
	private int size;
	//counting how many elements have been inserted into the dictionary
	private int elements;
	//used to store the pair before inserted into dictionary
	private DictEntry node;
	//value of the string hashed
	private int h;
	private boolean removed = false;
	
	//public method to define size of dictionary
	public Dictionary(int size){
		this.size = size;
		//creating table for linked list 
		T = (LinkedList<DictEntry>[]) new LinkedList[size];
		
		//initializing linked list for every position of dictionary size
		for(int i = 0; i <= size - 1; i++){
			T[i] = new LinkedList<DictEntry>();
		}
		
	}
	//public method to define inserting new entry into dictionary
	public int insert(DictEntry pair) throws DictionaryException {
		if (T[h(pair.getKey())].size() != 0) 
			// if item present in linked list
		{
			for (int i = 0; i < T[h(pair.getKey())].size(); i++) 
			//reading linked list
			{
				node = T[h(pair.getKey())].get(i); 
				// set node to current linked list node
				if (node.getKey() == pair.getKey()) 
					//if entry produces a collision
					throw new DictionaryException("Found in Dicitonary");
			}
			/**if pair is added and a collision occurs to dictionary using 
			seperate chainingupdate number of elements return 1 **/
			T[h(pair.getKey())].add(pair);
			elements++;
			return 1;
		} else{
			//if pair.getKey is not in the dictionary, add pair update elements
			//return 0
			T[h(pair.getKey())].add(pair);
			elements++;
		return 0;
		}
	}
	//public method for removing node from linked list
	public void remove(String key) throws DictionaryException{
		//for loop reads through linked list looking for hash value key
		for (int i = 0; i <= T[h(key)].size() - 1; i++){
			if (T[h(key)].get(i).getKey().compareTo(key) == 0){
			//if key is found remove node update elements
				T[h(key)].remove(i);
				elements--;
				removed = true;
			}
		}
		//if key is not found throw exception
		if (removed == false){
			throw new DictionaryException("Key not available to be Removed");
		}
		
	}
	//public method to find key in linked list
	public DictEntry find(String key) {
		//reading through linked list for key
		for (int i = 0; i <= T[h(key)].size() - 1; i++){
			if (T[h(key)].get(i).getKey().compareTo(key) == 0){
				
				//if key is found return key 
				return T[h(key)].get(i); 
			}
		}
		return null;
	}
	
	//public method to return number of entries in dictionary
	public int numElements(){
		return elements;
	}

	
	//private method for hashing value for compressed file
	//to be stored using seperate chaining method
	private int h(String str){
		h = str.charAt(0);
		int R = 31;
		for (int i = 0; i < str.length(); i++){
			//for loop creates compressed hash values
			h = (R * h + str.charAt(i)) % size;
		}
		return h;
	}
}