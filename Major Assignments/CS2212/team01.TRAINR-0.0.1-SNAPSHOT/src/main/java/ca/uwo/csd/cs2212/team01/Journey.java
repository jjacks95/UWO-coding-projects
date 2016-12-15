package ca.uwo.csd.cs2212.team01;

import java.util.Stack;
import java.util.LinkedList;

/**
 * @author team01
 *
 */
public class Journey {

	//Attributes
	public String name;
	public LinkedList<Float> userWeightDecline;
	public Stack<Goal> trophyCase;
	public int sizeOfCase;
	
	//Constructor
	/**
	 * 
	 * @param name
	 * @param trophies
	 * @param userWeightDecline
	 */
	/**
	 * @param name
	 * @param trophies
	 * @param userWeightDecline
	 */
	public Journey(String name, Stack<Goal> trophies, LinkedList<Float> userWeightDecline)
	{
		this.name = name;
		this.trophyCase = trophies;
		this.sizeOfCase = trophies.size();
	}
	
	//Methods
	/**
	 * @return
	 */
	public  int getSize() {return sizeOfCase;}
}
