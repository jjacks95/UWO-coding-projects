import java.util.*;
public class Position{
	//Initializing Variables
	int x;
	int y;
	
	//defines Position parameters and sets points x and y
	public Position(int x, int y){
		this.x = x;
		this.y = y;
	}
	//public method to return x coordinate
	public int getX(){
		return x;
	}
	//public method to return y coordinate
	public int getY(){
		return y;
	}

	//compares this position with p using row order
	public int compareTo(Position p){
		//if node compared to passed key is
		if(this.getY() < p.getY()){
			//less than return -1
			return -1;
		}
		else if((this.getY() == p.getY()) && (this.getX() < p.getX())){
			//y is equal but x is less than return -1
			return -1;
		}
		else if((this.getY() == p.getY()) && (this.getX() == p.getX())){	
			//if both y and x are equal return 0
			return 0;
		
		}else{
			//anything else return 1
			return 1;
		}
	}
}
