package ca.uwo.csd.cs2212.team01;

/**
 * @author team01
 *
 */
public class Workout
{
	//Attributes
	private String type;
	private String burnGoal = "";
	private int calorieBurnGoal;
	private int[] time;
	
	//Constructor
	/**
	 * Class Constructor
	 * @param goal
	 */
	public Workout(int goal)
	{
		calorieBurnGoal = goal;
		burnGoal = ""+(int)goal;
	}
	
	//Getters & Setters
	/**
	 * Gets the type of workout.
	 * @return
	 */
	public String getType() { return type; }
	
	/**
	 * Gets the total calories burned goal.
	 * @return
	 */
	public String getGoalString() { return burnGoal; }

	/**
	 * The type of Workout to set.
	 * @param type
	 */
	public void setType(String type) { this.type = type; }

	/**
	 * @return the calorieBurnTarget
	 */
	public int getCalorieBurnGoal() { return calorieBurnGoal;  }

	/**
	 * @param calorieBurnTarget the calorieBurnTarget to set
	 */
	public void setCalorieBurnTarget(int calorieBurnTarget) { this.calorieBurnGoal = calorieBurnTarget; burnGoal =  " (- "+ (int)calorieBurnTarget + "Cal )"; }

	/**
	 * @return the time
	 */
	public int[] getTime() { return time; }

	/**
	 * @param time the time to set
	 */
	public void setTime(int[] time) { this.time = time; }
	
}
