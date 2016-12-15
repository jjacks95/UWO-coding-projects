package ca.uwo.csd.cs2212.team01;

/**
 * @author team01
 *
 */
public class Goal {

	//Attributes
	public String goalName;
	public Boolean achievementStatus;
	public float targetValue;
	public float progress;
	//Date + Time Completed Attribute
	
	//Constructor
	/**
	 * @param goalName
	 * @param status
	 * @param targetValue
	 */
	public Goal(String goalName, Boolean status, float targetValue)
	{ 
		this.goalName=goalName; 
		this.achievementStatus=status; 
		this.targetValue=targetValue; 
		this.progress=0; 
	}
	
	//Methods
	/**
	 * @return
	 */
	public float calcRemaining() { return this.targetValue - this.progress; }
	
	/**
	 * @param status
	 */
	public void setStatus(boolean status) { this.achievementStatus = status; }
	
	/**
	 * @return
	 */
	public boolean getStatus() { return achievementStatus; }
	
	/**
	 * Method will update Goal's progress. Will set achievementStatus to True if progess equals or is greater than targetValue. Will return excess progress if targetValue is reached and there is excess progess left over.
	 * @param progress: must be in calories if Goal is Milestone.
	 * @return returns excess progress if user has excess progress after completing current Goal. Returns 0 if Goal was not completed.
	 */
	/**
	 * @param progress
	 * @return
	 */
	public float updateProgress(float progress) 
	{ 
		if(progress < 0) {System.out.println("Cannot be negative."); return 0;}
		
		if(this.calcRemaining() > progress)
		{
			this.progress += progress;
			if(this.progress == this.targetValue) { this.setStatus(true); }
			return 0;
		}
		else
		{
			float overflow = progress - this.calcRemaining();
			this.progress = this.targetValue; this.setStatus(true);
			return overflow;
		}
	}//updateProgress method


}//Goal Class
