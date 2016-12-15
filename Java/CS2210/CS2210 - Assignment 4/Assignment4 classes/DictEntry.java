public class DictEntry{
	//Initializing variables
	Position p;
	int color;
	DictEntry left;
	DictEntry parent;
	DictEntry right;
	
	//defines a DictEntry object
	public DictEntry(Position p, int color){
		this.p = p;
		this.color = color;
		this.left = null;
		this.right = null;
		this.parent = null;
	}
	
	//get position method
	public Position getPosition(){
		return p;
	}
	
	//get color method
	public int getColor(){
		return color;
	}
}