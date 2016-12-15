package ca.uwo.csd.cs2212.team01;

/**
 * This is a class representing a Macro
*/
/**
 * @author team01
 *
 */
public class Macro {
	
	//fields
	private float calories;
	private float proteins;
	private float carbs;
	private float fats;
	
	/**
	 * Macro constructor
	 */
	/**
	 * 
	 */
	public Macro()
	{
		this.calories = 0;
		this.proteins = 0;
		this.carbs = 0;
		this.fats = 0;
	}
	
	/**
	 * Macro constructor
	 * @param proteins float that holds the amount of protein in the Macro
	 * @param carbs float that holds the amount of carbs in the Macro
	 * @param fats float that holds the amount of fat in the Macro
	 */
	/**
	 * @param calories
	 * @param proteins
	 * @param carbs
	 * @param fats
	 */
	public Macro(float calories, float proteins, float carbs, float fats)
	{
		this.proteins = proteins;
		this.carbs = carbs;
		this.fats = fats;
		this.calories = calories;
	}
	
	/**accessor method to get amount of calories
	 * @return float calories 
	 */
	/**
	 * @return
	 */
	public float getCalories()
	{ return calories; }

	/**
	 * accessor method to get amount of proteins in the Macro
	 * @return float proteins in the Macro
	 */
	/**
	 * @return
	 */
	public float getProteins() {
		return proteins;
	}

	/**
	 * accessor method to get amount of carbs in the Macro
	 * @return float carbs in the Macro
	 */
	/**
	 * @return
	 */
	public float getCarbs() {
		return carbs;
	}

	
	/**
	 * accessor method to get amount of fat in the Macro
	 * @return float fats in the Macro
	 */
	/**
	 * @return
	 */
	public float getFats() {
		return fats;
	}

	
	/**
	 * setter method to set amount of calories
	 * @param calories flaot that holds amount of calories
	 */
	/**
	 * @param calories
	 */
	public void setCalories(float calories)
	{ this.calories = calories; }
	
	/**
	 * setter method to set amount of protein in the Macro
	 * @param proteins float that holds the amount of protein in the Macro
	 */
	/**
	 * @param proteins
	 */
	public void setProteins(float proteins) {
		this.proteins = proteins;
	}

	/**
	 * setter method to set amount of carbs in the Macro
	 * @param carbs float that holds the amount of carbs in the Macro
	 */
	/**
	 * @param carbs
	 */
	public void setCarbs(float carbs) {
		this.carbs = carbs;
	}

	/**
	 * setter method to set amount of fat in the Macro
	 * @param fatss float that holds the amount of carbs in the Macro
	 */
	/**
	 * @param fats
	 */
	public void setFats(float fats) {
		this.fats = fats;
	}
	
	

}
