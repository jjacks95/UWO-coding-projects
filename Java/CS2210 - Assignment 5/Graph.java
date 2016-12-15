import java.util.*;
public class Graph implements GraphADT{
	//Initializing graph class variables
	private String[][] adjacency_matrix;
	private int graph_size;
	
	//graph constructor dictates size of adjacency_matrix
	public Graph(int n){
		this.graph_size = n;
		adjacency_matrix = new String[graph_size][graph_size];
        }
    
	//insert edge function will store busLine as th connection between u and v nodes (star finish)
    public void insertEdge(Node u, Node v, String busLine) throws GraphException{
        
		//checks if either node is negative value
		//throws error if it is
        if(u.getName() < 0  || v.getName() < 0){
            throw new GraphException("Node Does Not Exist");
        }
		
		//check if nodes value is greater then graph size if it is throw exception
		if(u.getName() > this.graph_size-1 || v.getName() > this.graph_size-1){
			throw new GraphException("Node Does Not Exist");
        }
        
		//check that the edge being created does not already exist
		//if it does throw exception
        if(adjacency_matrix[u.getName()][v.getName()] != null){
			throw new GraphException("Edge Does Exist");
		}
        
		//otherwise create the new edge between node u and v 
		adjacency_matrix[u.getName()][v.getName()] = busLine;
	}
    
	//public method to return the node represented by the given value
    public Node getNode(int name) throws GraphException{
        
		//check that the node value is not greater then graph size or less then 0
		//else throw exception
        if(name < 0  || name > this.graph_size-1){
            throw new GraphException("Node Does Not Exist");
        }
        //if it passes the tests create the node and return it
        Node node = new Node(name);
        
        return node;
	}
	
	//iterator to count incident edges
	//mutliple edges connecting to one node
    public Iterator incidentEdges(Node u) throws GraphException{
		
		//variables
		int i;
		boolean flag = false;
		//create array list to store incidents
		ArrayList list = new ArrayList();
		
		//check that node passed is not greater then graph size
		//throws ane exception  otherwise
		if(u.getName() >= graph_size){
			throw new GraphException("Out of Bounds");
		}
		
		//iterate over entire graph seeing if edges exist with specified node
		 for(i = 0; i < graph_size; i++){
			 
			 //every edge that exists is added to array
			 //checks if it is not null to add also checks both directions 
			 //u and v and rows and col and then v and u and rows and col
			 //representing the undirected graph 
			 if(adjacency_matrix[u.getName()][i] != null){
				 Node n2 = new Node(i);
				 Edge edge = new Edge(u,n2,adjacency_matrix[u.getName()][i]);
				 list.add(edge);
				 flag = true;
			 }
			if(adjacency_matrix[i][u.getName()] != null){
				Node n2 = new Node(i);
				 Edge edge = new Edge(u,n2,adjacency_matrix[i][u.getName()]);
				 list.add(edge);
				 flag = true;
			}
		}
		//check if any incidents existed if not return null
		 if(flag == false){
			 return null;
		 }
		//otherwise return iterator containing list of incidents
		Iterator itr = list.iterator();
		 return itr;
	}
	
	//getEdge method returns the bus line representing the edge between two given nodes
    public Edge getEdge(Node u, Node v) throws GraphException{
		//try and catch for exceptions
		try{
			//check to see nodes can exist in graph
			//otherwise throw exception
			if(u.getName() > graph_size-1 || v.getName() > graph_size-1){
				throw new GraphException("Node Does Not Exist");
			}else if(u.getName() < 0 || v.getName() < 0){
				throw new GraphException("Node Does Not Exist");
			}
			
			//if adjacency_matrix equals null then edge does not exist return null
			if(adjacency_matrix[u.getName()][v.getName()] == null){
				return null;
			}
			//else create the edge to return
			Edge edge = new Edge(u, v, adjacency_matrix[u.getName()][v.getName()]);
			return edge;
			
		}catch(GraphException e){
			e.getMessage();
			throw new GraphException("Edge Does Not Exist");
		}
	}
	
	//adjacent method returns nodes that are connected which would be adjacent
	public boolean areAdjacent(Node u, Node v) throws GraphException{
		//checks both directions of node for connection
		//if not found returns false if found returns true
		//exceptions are handled by getEdge when calling
		if(getEdge(u,v) == null && getEdge(v,u) == null){
			return false;
		}
		
		if(getEdge(v,u) != null || getEdge(u,v) != null){
			return true;
		}
			return false;
	}
}