public class Node{
	
	//class variables
    private int name;
	private boolean mark;
	 
	//constructor to set value for node
	public Node(int name){
		this.name = name;
	}
	//sets mark for node
	public void setMark(boolean mark){
		this.mark = mark;
	}
	//returns mark for get method
	public boolean getMark(){
		return mark;
		
	}
	//return value of node
	public int getName(){
		return name;
	}
}