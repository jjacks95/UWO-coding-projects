package ca.uwo.csd.cs2212.team01;

import java.util.LinkedList;

/**
 * @author team01
 *
 */
public class User {

	//Attributes
	public String name;
	public int age;
	public char gender;
	public float[] height;
	public LinkedList<Journey> myJourneys = new LinkedList<Journey>();
	
	//Constructor
	/**
	 * @param name
	 */
	public User(String name) {this.name = name;}
	
	//Methods
	/**
	 * @param journey
	 */
	public void addJourney(Journey journey)
	{
		myJourneys.add(journey);
	}
	/**
	 * @return
	 */
	public int numberOfJourneys()
	{
		return myJourneys.size();
	}
}
