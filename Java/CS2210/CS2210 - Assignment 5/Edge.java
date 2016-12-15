 public class Edge{
	//class variables
	private String busLine;
	private Node u;
	private Node v;
	
	//class constructor
	public Edge(Node u, Node v, String busLine){
		//defines start node, and end node, connected by bus line
		//u and v are not always start and end this just defines the edge connecting the two nodes
		//and which nodes are connected
		this.u = u;
		this.v = v;
		this.busLine = busLine;
		
	}
	//return u as the firstEndpoint
	public Node firstEndpoint(){
		return this.u;
	}
	//return v as secondEndpoint
	public Node secondEndpoint(){
		return this.v;
	}
	//return busLine for get method
	public String getBusLine(){
		return busLine;
	}
}