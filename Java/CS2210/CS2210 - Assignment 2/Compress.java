import java.io.*;

public class Compress {
	public static void main(String[] args) throws Exception{
	
	//initializing variables
	BufferedInputStream in;
	BufferedOutputStream out;
	
	//collision set to 0 to be updated as entries are inputted
	int collision = 0;
	
	//new string input to read characters from Buffer
	String input = new String();
	
	//setting up file extension output and reading file from input
	in = new BufferedInputStream(new FileInputStream(args[0]));
	out = new BufferedOutputStream(new FileOutputStream(args[0] + ".zzz"));
	
	
	//checking that arguments made are correct number
	if (args.length <= 1){
		//try and catch for file not found exception
		try{
			for (int i = 0; i < in.available();){
				input += (char) in.read();
			}
		}
		catch (FileNotFoundException ee){
			System.out.println("File Not Found");
			
		}
	}else{
		System.out.println("Too Many Arguments");
	
	}
	//new dictionary
	Dictionary Dict = new Dictionary(8999);
	
	//new DictEntry for using all methods to add, remove, and find entries
	DictEntry new_input = new DictEntry(null, 0);
	
	//for loop to initialize ASCII codes
	for (int i = 0; i < 256; i++){
		//string variable to insert each ASCII code
		String code = new String();
		code += (char) i;
		DictEntry ASCII = new DictEntry(code, i);
		//inserting ASCII into collision to check later on
		collision += Dict.insert(ASCII);
		
	}
	
	for (int i = 0; i <= input.length() - 1;){
		//reading file for string
		//creating string for matching entries
		String match = new String();
		//current char read from input file
		String current = new String();
		//initializing current with position i
		current += input.charAt(i);
		
		/**increment begins at one because all first 
		char have been inserted through ASCII**/
		int increment = 1;
		boolean exit = false;
		
		//do-while to read through characters in file.
		do{
            //do-while statement to read through dictionary entries
			//if i is equal to total string length set match to current
			if (i == input.length() - 1){
				match = current;
			}
			else{
			//if it is not full length of string increment i to next char
			current += input.charAt(i + increment);
			}
			//if current is not at the end of file 
			//and is still not full length of string after incrementing plus 1
			if (Dict.find(current) != null && input.length() > (i + increment + 1)){
				//increment until current is full length of string
				increment++; 
			}else
				exit = true;
                
		}while(exit == false);
			
			
		//restricting dictionary number of entries
		if (Dict.numElements() < 4096){
			new_input = new DictEntry(current, Dict.numElements());
			collision += Dict.insert(new_input);
		}
		//checking if longest string is in dictionary
		for (int j = 0; j < current.length() - 1; j++){
			match += current.charAt(j);
		}
		//output code once match is the longest possible string 
		//using the get code method given
		MyOutput output = new MyOutput();
		output.output(Dict.find(match).getCode(), out);
		
		//incrementing i to next character for next string
		i += match.length();
	}
	
	MyOutput output = new MyOutput();
	output.flush(out);
	in.close();
	out.close();
	System.out.println("Collisions: " + collision);	

	}
}