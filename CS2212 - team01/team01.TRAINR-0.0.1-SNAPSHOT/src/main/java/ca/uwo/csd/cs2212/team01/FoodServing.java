package ca.uwo.csd.cs2212.team01;

/**
 * @author team01
 *
 */
public class FoodServing {

	private Food food; //the food that this foodServing's nutritional info is derived from
	private Macro macros = new Macro(); //derived nutritional info is stored here
	private float servingSize;
	private String servingUnit;

	/**
	 * Class Constructor
	 * @param food
	 * @param servingSize
	 * @param servingUnit
	 */
	public FoodServing(Food food, float servingSize, String servingUnit) {
		this.food = food;
		this.servingSize = servingSize;
		this.servingUnit = servingUnit;
		this.calcMacros(food, servingSize);
	}

	//public float unitConverter() {}
	
	//recieves Food object, servingSize and servingUnit
	//use formula to calculate macros for this serving of food
	/**
	 * Calculates the calories, proteins, carbs, & fats for the food item.
	 * @param food
	 * @param servingSize
	 */
	public void calcMacros(Food food, float servingSize) 
	{
		macros.setCalories( ( servingSize / food.getServingInfo() ) * food.getMacroInfo().getCalories() ); // (input serving size / ref serving size) * ref calories
		macros.setProteins( ( servingSize / food.getServingInfo() ) * food.getMacroInfo().getProteins() );
		macros.setCarbs( ( servingSize / food.getServingInfo() ) * food.getMacroInfo().getCarbs() );
		macros.setFats( ( servingSize / food.getServingInfo() ) * food.getMacroInfo().getFats() );
	}
	
	/**
	 * An object holding the calories, proteins, carbs, & fats for the food item.
	 * @return
	 */
	public Macro getMacros() { return macros; }
	
	/**
	 * The food item.
	 * @return
	 */
	public Food getFood() { return food; }
	/**
	 * Sets the food item.
	 * @param food
	 */
	public void setFood(Food food) { this.food = food; }
	/**
	 * @return
	 */
	public float getServingSize() { return servingSize; }
	/**
	 * Sets the food serving size.
	 * @param servingSize
	 */
	public void setServingSize(float servingSize) { this.servingSize = servingSize; }
	/**
	 * Gets the serving unit.
	 * @return
	 */
	public String getServingUnit() { return servingUnit; }
	/**
	 * Sets the type of serving.
	 * @param ServingUnit
	 */
	public void setServingType(String ServingUnit) { this.servingUnit = ServingUnit; }

}
