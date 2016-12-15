public class Figure implements FigureADT{
	
	//Initializing Variables
	private int width;
	private int height;
	private int type;
	private int id;
	Position pos;
	DictEntry addpix;
	private BinarySearchTree tree;
	
	//Figure constructur
	public Figure(int id, int width, int height, int type, Position pos){
		this.width = width;
		this.height = height;
		this.type = type;
		this.id = id;
		this.pos = pos;
	}
	//public method to set type
	public void setType (int type){
		this.type = type;
	}
	
	//public method to get width
    public int getWidth (){
		return width;
	}
	
	//public method to get height
    public int getHeight(){
		return height;
	}
	
	//public method to get Type
    public int getType (){
		return type;
	}
	
	//public method to get ID
    public int getId(){
		return id;
	}
	
	//public method to set offset
    public Position getOffset(){
		return pos;
	}
    public void setOffset(Position value){
		this.pos = value;
	}
	
	//adds pixels and color to new node to be inserted unless already exists
    public void addPixel(int x, int y, int rgb) throws BSTException{
		DictEntry err;
		Position temp; 
		this.pos.x = x;
		this.pos.y = y;
		this.addpix.color = rgb;
		//temp will hold x and y
		temp = new Position(x, y);
		//addpix will hold the x and y as a position and color
		addpix = new DictEntry(temp, rgb);
		
		//checking for error if object already exists
		//if it exists throw exception else insert node
		err = tree.find(temp);
		if(err != null){
			throw new BSTException("Insert Failed");
		}else{
			tree.insert(addpix);
		}
	}

        public boolean intersects(Figure fig){
		//intersect function will see if the offset is still 
		//less than the offset and width
		//or offset and height
		if((fig.getOffset().getX() < (this.getOffset().getX() + getWidth())) &&
		   (fig.getOffset().getY() < (this.getOffset().getY() + getHeight()))){
				return true;
		   }
			return false;
		}
}