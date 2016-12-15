import java.io.*;
import java.util.*;

public class Map{
	//Intializing variables for the class
    private Graph graph; 
	private String[][] matrix;
    private int size = -1;
    private int row = 0;
    private String numberFormat;
	private int startNode = 0;
    private int endNode = 0;
    
	public Map(String inputFile) throws MapException{
		//public method for reading the input file
		//which then calls the private method to read through
		//and determine the map from the file
        try {
            readFile(inputFile);
			
        } catch (MapException e){
			e.getMessage();
		}
        
	}
	
	//get graph method returns graph if it is defiend 
	//else it throws new map exception
	public Graph getGraph() throws MapException{
        if(graph == null){
            throw new MapException("Graph is undefined");
        }
        return graph;
	}
	
	

	public Iterator findPath(){
		
		//initialize variables
		ArrayList<Node> list = new ArrayList<Node>();
		Iterator neighbours;
		Edge uv;
		Node u, node1, node2;
		boolean foundnode = false;

		// use a stack to help depth-first traversal
		Stack<Node> stack = new Stack<Node>();
		try{
			//set u as the start node and mark it as true for visited
			//push u onto stack for path
			u = graph.getNode(startNode);
			u.setMark(true);
			stack.push(u);

			//while stack is not empty
			while (!stack.isEmpty()) {
				//pop node off stack and set as current node
				//add the node to the iterator for path
				Node curr = stack.pop();
				list.add(curr);
				
				//set neighbours to incident edges to build path
				neighbours = graph.incidentEdges(curr);
				
				// current node is equal to the end node
				//indicating end of path
				if (curr.getName() == endNode) {
					foundnode = true;
					Iterator itr = list.iterator();
					return itr;
				}
				//while the node has incidents check both u and v node values
				while (neighbours.hasNext()) {
					uv = (Edge)neighbours.next();
					node1 = uv.firstEndpoint();
					node2 = uv.secondEndpoint();
					
					//check if not equal to current and not visited
					if((node2.getName() != curr.getName())&&(node2.getMark() == false)){
						//mark as visited and push to stack
						node2.setMark(true);
						stack.push(node2);
						
					//check the second node as well
					}else if((node1.getName() != curr.getName())&&(node1.getMark() == false)){
						node1.setMark(true);
						stack.push(node1);
					}
				}
			}
			//catch graph exceptions
		}catch(GraphException e){
			e.getMessage();
		}
		return null;
	}
	

	
	private void readFile(String inputFile) throws MapException{      
		try{
			//buffer and stream are for reading the file and computing the data
			InputStream stream = ClassLoader.getSystemResourceAsStream(inputFile);
			BufferedReader buffer = new BufferedReader(new InputStreamReader(stream));

			//buffer1 and stream1 are for checking the file can be opened
			InputStream stream1 = ClassLoader.getSystemResourceAsStream(inputFile);
			BufferedReader buffer1 = new BufferedReader(new InputStreamReader(stream1));
				
			//Check to see file can be opened if not throw exception
			if(buffer1.readLine() == null){
				throw new MapException("File Cannot Be Read");
			}
			//Initializing String variables to read from buffer
			String line;	//for reading each line of buffer
			String C;		//scale factor for map size
			String W;		//width of graph
			String H;		//height of graph
			String K;		//number of bus line changes allowed
			
			//integer variables
			int width;
			int height;
			int graphsize;

			//reading first four lines for
			//scale, width, height, and number of busline changes allowed
			C = buffer.readLine();
			W = buffer.readLine();
			H = buffer.readLine();
			K = buffer.readLine();
			
			//change the string representation to integer
			width = Integer.parseInt(W);
			height = Integer.parseInt(H);
			//graph size is equal to the width multiplied by height
			graphsize = width * height;
			
			//while buffer isnt empty read each line one at a time
			while ((line = buffer.readLine()) != null) {
				
				//check if matrix is null
				//if it is set size of matrix
				if (matrix == null) {
					size = line.length();
					matrix = new String[size][size];
				}
				
				//for loop starting at zero checks the line that has been read
				//initialized the values for the matrix
				for (int col = 0; col < size; col++) {
					matrix[row][col] = String.valueOf(line.charAt(col));
				
				//if the character is equal to 0 set to start node
				//if character is equal to 1 set to end node for path finding
				if(line.charAt(col) == '0')
					startNode = (row)*(size +1)/4 + col/2;
				if(line.charAt(col) == '1')
					endNode = (row)*(size +1)/4 + col/2;
				}
				row++;
			}
			
			
			//create the new graph to hold the nodes inputfile gives
			graph = new Graph(graphsize);
			//printMatrix();
			//printEdges();
		}catch(IOException e){
			e.printStackTrace();
		}
	}
	
}