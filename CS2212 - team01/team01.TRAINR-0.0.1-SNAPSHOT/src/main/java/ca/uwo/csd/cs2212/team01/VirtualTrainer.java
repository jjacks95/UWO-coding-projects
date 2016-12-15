package ca.uwo.csd.cs2212.team01;

import java.util.LinkedList;
import java.util.ListIterator;
import java.util.Stack;

/**
 * @author team01
 *
 */
public class VirtualTrainer {

	//Attributes
	public LinkedList<Float> userWeight;
	public float targetWeight;
	public boolean achievementStatus;
	
	public Stack<Goal> remainingMileStones;
	public Goal currentMileStone;
	public Stack<Goal> completedMileStones;
	
	private Feedback milestoneFeedback;
	
	//Constructor
	/**
	 * VirtualTrainer Constructor
	 */
	public VirtualTrainer()
	{
			this.userWeight = new LinkedList<Float>();
			this.remainingMileStones = new Stack<Goal>(); 
			this.completedMileStones = new Stack<Goal>(); 
			achievementStatus = false; 
	}
	
	//Getters & Setters
	/**
	 * Add a new weight measurement for the user. Returns false if incorrect input has been passed.
	 * @param user
	 * @param weight
	 * @return
	 */
	public boolean addNewWeightMeasurement(User user, float weight)
	{
		if(weight > 0 && weight<999) { userWeight.add(weight); milestoneFeedback = updateMileStoneProgress(user) ; return true; }
		else { return false; }
	}
	/**
	 * Set the target weight for the user. Returns false if incorrect input has been passed.
	 * @param weight
	 * @return
	 */
	public boolean setTargetWeight(float weight)
	{
		if(weight > 0 && weight<999) { targetWeight = weight; return true; }
		else { return false; }
	}

	/**
	 * Get user's target weight.
	 * @return
	 */
	public float getTargetWeight()
	{ return targetWeight; }
	/**
	 * Get user's starting weight.
	 * @return
	 */
	public float getStartingWeight()
	{ return userWeight.getFirst();}
	/**
	 * Get user's current weight
	 * @return
	 */
	public float getCurrentWeight()
	{ return userWeight.getLast(); }
	
	//Methods
	//Milestone Setup
	/**
	 * Set a weight loss goal for user. Returns false if incorrect input has been passed.
	 * @param user
	 * @param startingWeight
	 * @param targetWeight
	 * @return
	 */
	public boolean setWeightLossGoal(User user ,float startingWeight, float targetWeight)
	{
		if(startingWeight-targetWeight<2){ return false; }//User must specify a weight loss goal larger than 2 lbs }
		
		//user is specifying a NEW weight loss goal - transfer old Milestones to User's trophy case
		else if(achievementStatus)
		{
			completedMileStones = new Stack<Goal>(); remainingMileStones = new Stack<Goal>(); userWeight = new LinkedList<Float>();
			achievementStatus = false;
			addNewWeightMeasurement(user, startingWeight); setTargetWeight(targetWeight); return true;
		}
		//user has not completed current target weight/journey but user wants to start a new weight loss journey / delete current progress. Must warn user this action will delete current progress.
		else if(userWeight.size() != 0)
		{
			completedMileStones = new Stack<Goal>(); remainingMileStones = new Stack<Goal>(); userWeight = new LinkedList<Float>();
			addNewWeightMeasurement(user, startingWeight); setTargetWeight(targetWeight); return true;

		}
		//user is starting a new weight loss journey for the first time
		else
		{ addNewWeightMeasurement(user, startingWeight); setTargetWeight(targetWeight); return true; } //System.out.println("user is starting a weight loss journey for the first time"); 
	}

	/**
	 * Calculates the number of Milestones the user can achieve given their weight loss goal. 
	 */
	public void setMileStones() 
	{
		//calculate total weight loss
		float totalWeightLoss = this.getStartingWeight() - this.getTargetWeight();
		
		//total weight loss is even
		if(totalWeightLoss%2 == 0) 
		{
			int totalMileStones = (int)totalWeightLoss / 2;							
			remainingMileStones.push(new Goal("Last Milestone (#"+totalMileStones+")",false,7000));
			for(int i = totalMileStones-1; i > 0; i--)
			{ remainingMileStones.push(new Goal("Milestone #"+i,false,7000)); }
			this.currentMileStone = remainingMileStones.pop();						
		}
		//total weight loss is odd
		else 
		{
			float lastWeight = totalWeightLoss%2;
			float allWeightminusLast = totalWeightLoss-lastWeight;
			int allMSminusLast = (int)allWeightminusLast / 2;
			remainingMileStones.push(new Goal("Last Milestone (#"+(allMSminusLast+1)+")",false,lastWeight*3500));
			for(int i = allMSminusLast; i > 0; i--) { remainingMileStones.push(new Goal("Milestone #"+i,false,7000)); }
			this.currentMileStone = remainingMileStones.pop();		
		}
	}
	
	//DASHBOARD - TRAINR FEEDBACK PANEL:
	
	// still have to write up "feedback format" for each of the feedback algorithms
	
	//FLAG - TIME-DEPENDENT
	/**
	 * Once the user has weighed themselves after a weight loss goal has been achieved,
	 * the virtual trainer will calculate progress made on any milestones.
	 * Feedback Format:
	 * TEXTCODE 2 = DISPLAY TEXT & PROGRESS
	 * TEXTCODE 1 = DISPLAY TEXT ONLY
	 * TEXTCODE 0 = DO NOT DISPLAY TEXT
	 * BUTTONCODE 1  = DISPLAY "CUSTOMIZE MY PLAN" BUTTON
	 * BUTTONCODE 0  = DO NOT DISPLAY BUTTONS
	 * 
	 * feedbackValues:
	 * [0] = current MileStone number
	 * [1] = current MileStone progress, out of 7000
	 * [2] = X pounds to go"
	 * @param user
	 * @return Feedback
	 */
	public Feedback updateMileStoneProgress(User user) //to be called once a week (every sunday) by Main? // return feedback?
	{
		
		//TEXTCODE 2 = DISPLAY TEXT & PROGRESS
		//TEXTCODE 1 = DISPLAY TEXT ONLY
		//TEXTCODE 0 = DO NOT DISPLAY TEXT
		//BUTTONCODE 1  = DISPLAY "CUSTOMIZE MY PLAN" BUTTON
		//BUTTONCODE 0  = DO NOT DISPLAY BUTTONS
		
		//feedbackValues:
		//[0] = current MileStone number
		//[1] = current MileStone progress, out of 7000
		//[2] = X pounds to go"
		
		Feedback msUpdateFeedback = new Feedback();
		
		if(userWeight.size() == 1) 
		{ 
			//User has not weighed themselves yet after entering in their Starting Weight. 
			msUpdateFeedback.setTXTCode(2);
			msUpdateFeedback.addTXTone
			(
					"Progress towards your first Milestone:"
			);
			msUpdateFeedback.addFeedbackValue((float)0); 			//current MileStone number
			msUpdateFeedback.addFeedbackValue((float)0);				//current MileStone progress, out of 7000
			msUpdateFeedback.addFeedbackValue((float)2);		//"X pounds to go"
			return msUpdateFeedback; 
		}
		
		else if(currentMileStone == null) 
		{ 
			msUpdateFeedback.setTXTCode(1); //DISPLAY 1 SENTENCE 
			msUpdateFeedback.addTXTone
			(
					"Warning: User has completed all Milestones and is continuing to use the TRAINR without a new Target Weight goal.\n"
					+ "No new Milestones can be achieved until a new Target Weight Goal has been set."
			);
			return msUpdateFeedback; 
		} 
		
		else //Calculate change in weight
		{
			float weightDiff =  userWeight.getLast() - userWeight.get((userWeight.size()-2));
			//System.out.println("weightDiff: "+weightDiff);
			if(weightDiff > 0) //User has gained weight
			{ 
				
				//<Write code to decrease Milestone Progress>//
				
				msUpdateFeedback.setTXTCode(1);  //DISPLAY 1 SENTENCE
				msUpdateFeedback.setButtonCode(1); //DISPLAY "CUSTOMIZE MY PLAN" BUTTON
				msUpdateFeedback.addTXTone
				(
						"You have gained " +  String.format("%.1f", weightDiff) + " lbs!<br>"
						+ "You should reduce your calorie intake or<br>"
						+ "set a higher calorie burn goal for workouts:"
				); 
				return msUpdateFeedback; 
			} 
			
			else if(weightDiff == 0) //User's weight has not changed
			{
				msUpdateFeedback.setTXTCode(1);  //DISPLAY 1 SENTENCE
				msUpdateFeedback.setButtonCode(1); //DISPLAY "CUSTOMIZE MY PLAN" BUTTON
				msUpdateFeedback.addTXTone
				(
						"You have not lost any weight!<br>"
						+ "You should reduce your calorie intake or<br>"
						+ "set a higher calorie burn goal for workouts:"
				); 
				return msUpdateFeedback; 
			}
			
			else //User has lost weight
			{
				float usersProgress = 3500*(Math.abs(weightDiff));
				//System.out.println("usersProgress: "+usersProgress);
				int counter = 0; //counts the number of Milestones achieved within this update
				while(usersProgress > 0 )
				{
					if(remainingMileStones.size()==0 && currentMileStone == null) //user is done all MS but has also lost further weight. Warn user further weight loss isn't being used towards any Milestone progression.
					{ 
						msUpdateFeedback.setTXTCode(1) ;
						msUpdateFeedback.setFontSize(20);
						msUpdateFeedback.addTXTone
						(
								"Warning: You have completed all Milestones and have lost more weight than specified target weight.<br>"
								+ "TRAINR is not tracking any new Milestone progress with weight that has been lost beyond the Target Weight of: " + this.targetWeight +  " lbs.<br>"
								+ "Please specify a new Target Weight goal if you wish to achieve more Milestone Rewards!"
						);
						return msUpdateFeedback;
					} 
					
					usersProgress = currentMileStone.updateProgress(usersProgress);
					//System.out.println("usersProgress: "+usersProgress);System.out.println(currentMileStone.getStatus());System.out.println("current ms progress: "+currentMileStone.progress);
					if(currentMileStone.getStatus()) 
					 { 
						 completedMileStones.push(currentMileStone); currentMileStone=null; counter++;
						 if (remainingMileStones.size() != 0) currentMileStone = remainingMileStones.pop(); 
						 
						 else //User has completed all Milestones
						 { 
							 achievementStatus = true; 
							 user.addJourney(new Journey("Journey #"+user.numberOfJourneys()+1,completedMileStones,userWeight));  
							 msUpdateFeedback.setTXTCode(1);
							 msUpdateFeedback.addTXTone
							 (
									 "Congratulations!<br>You have completed all your Milestones!<br>You successfully achieved your weight loss goal!"
							);
							 return msUpdateFeedback; 
						 } 
					}
				}
				
				if(counter == 1) //You’ve lost X lbs and achieved a MileStone! You have achieved X Milestones so far! Progress towards your next MileStone:
				{
					msUpdateFeedback.setTXTCode(2);
					msUpdateFeedback.addTXTone
					(
							"You've lost " + String.format("%.1f", Math.abs(weightDiff)) + " lbs and achieved a Milestone!<br>"
							+ "You have achieved " + completedMileStones.size() + feedbackHelper() + "so far!<br>"
							+ "Progress towards your next Milestone:"
					);
					msUpdateFeedback.addFeedbackValue((float)completedMileStones.size()+1); 			//current MileStone number
					msUpdateFeedback.addFeedbackValue((currentMileStone.progress)/7000);				//current MileStone progress, out of 7000
					msUpdateFeedback.addFeedbackValue(2-(currentMileStone.progress / 3500)); 			//"X pounds to go"
				}
				
				else if(counter > 1) //You’ve lost X lbs and achieved X MileStones! You have achieved X Milestones so far! Progress towards your next MileStone:
				{
					msUpdateFeedback.setTXTCode(2);
					msUpdateFeedback.addTXTone
					(
							"You've lost " + String.format("%.1f", Math.abs(weightDiff)) + " lbs and achieved " + counter + " Milestones!<br>"
							+ "You have achieved " + completedMileStones.size() + feedbackHelper() + "so far!<br>"
							+ "Progress towards your next Milestone:"
					);
					msUpdateFeedback.addFeedbackValue((float)completedMileStones.size()+1); 			//current MileStone number
					msUpdateFeedback.addFeedbackValue((currentMileStone.progress)/7000);				//current MileStone progress, out of 7000
					msUpdateFeedback.addFeedbackValue(2-(currentMileStone.progress / 3500)); 			//"X pounds to go"
				}
				else //You’ve lost X lbs! You have achieved X Milestones so far! Progress towards your next MileStone:
				{
					msUpdateFeedback.setTXTCode(2);
					if(completedMileStones.size() > 0)
					{
						msUpdateFeedback.addTXTone
						(
								"You've lost " + String.format("%.1f", Math.abs(weightDiff)) + " lbs!<br>"
								+ "You have achieved " + completedMileStones.size() + " Milestones so far!<br>"
								+ "Progress towards your next Milestone:"
						);
					}
					else // User is working towards achieving their first Milestone
					{
						msUpdateFeedback.addTXTone
						(
								"You've lost " + String.format("%.1f", Math.abs(weightDiff)) + " lbs!<br>"
								+ "Progress towards your first Milestone:"
						);
					}
					msUpdateFeedback.addFeedbackValue((float)completedMileStones.size()+1); 			//current MileStone number
					msUpdateFeedback.addFeedbackValue((currentMileStone.progress)/7000);				//current MileStone progress, out of 7000
					msUpdateFeedback.addFeedbackValue(2-(currentMileStone.progress / 3500)); 			//"X pounds to go"
				}
			
				return msUpdateFeedback;
			}//second else - User has lost weight
		}//first else - calcualte weight change and update MS progress accordingly
	}//public void msUpdateProgress()
	//FLAG - CALLED BY UI
	/**
	 * Gets Milestone feedback
	 * @return
	 */
	public Feedback getmsFeedback() 
	{ return milestoneFeedback; }
	//FLAG - REFRESH-DEPENDENT - CALLED BY UI
	/**
	 * Updates today's progress
	 * @param today
	 * @return
	 */
	public Feedback updateTodaysProgress(Day today)
	{
		Float calDiff = today.getDailyCalDiff();
		Feedback todayFeedback = new Feedback();
		//System.out.println(calDiff);
	
		if(calDiff <= -500) 
		{
			todayFeedback.setTXTCode(1);
			todayFeedback.addTXTone
			(
					"You're currently in a " + calDiff + " calorie deficit :)<br>"
					+ "Stick to your plan and you'll hit today's calorie goal!"
			);
			todayFeedback.addFeedbackValue(calDiff);
			return todayFeedback;
		}
		
		else if(calDiff < -1 && calDiff > -500) 
		{
			todayFeedback.setTXTCode(1);
			todayFeedback.addTXTone
			(
					"You're currently in a " + calDiff + " calorie deficit.<br>"
					+ "Stick to your planned meals & burn enough calories<br>"
					+ "to make sure you hit today's calorie deficit goal."
			);
			todayFeedback.addFeedbackValue(calDiff);
			return todayFeedback;
		}
		
		else if(calDiff >= 0) 
		{
			todayFeedback.setTXTCode(1);
			todayFeedback.addTXTone
			(
					"You’re curently in a " + calDiff + " calorie surplus.<br>"
					+ "Stick to your planned meals and burn enough<br>"
					+ "calories to make sure you hit today's<br>"
					+ "calorie deficit goal."
			);
			todayFeedback.addFeedbackValue(calDiff);
			return todayFeedback;
		}
		else { todayFeedback.addTXTone("error"); return todayFeedback; }
	}
	//FLAG - TIME-DEPENDENT - CALLED BY UI
	/**
	 * Updates weekly progress
	 * @param pastWeek
	 * @return
	 */
	public Feedback updateWeeklyProgress(LinkedList<Day> pastWeek) //to be called once everyday, every morning?
	{
		ListIterator<Day> pastWeekIter = pastWeek.listIterator();
		int successDays = 0, missedDay = 0;
		while(pastWeekIter.hasNext()) 
		{
			if(pastWeekIter.next().getDailyCalDiff()<=-490) { successDays++;}
			else missedDay = successDays + 1;
		}
		//System.out.println("successDays: "+successDays);
		Feedback weekFeedback = new Feedback();
		
		if(successDays == 6) 
		{ 
			weekFeedback.setTXTCode(1); 
			weekFeedback.addTXTone ( "You’ve had 6 successful days in a row!" );
		}
		
		else if(successDays == 5 && missedDay == 1)
		{
			weekFeedback.setTXTCode(1);
			 weekFeedback.addTXTone
			 (
					 "You missed your calorie goal yesterday but you’ve had 5 successful days before that! Good job!"
			 );
			 return weekFeedback;
		}
		
		else if(successDays == 5 && missedDay > 1)
		{
			weekFeedback.setTXTCode(1);
			 weekFeedback.addTXTone
			 (
					 "You missed your calorie goal " + missedDay + " days ago<br>but you’ve had 5 successful days! Great job!"
			 );
			 return weekFeedback;
		}
		
		else if(successDays == 4)
		{
			weekFeedback.setTXTCode(1);
			 weekFeedback.addTXTone
			 (
					 "You missed your calorie goal twice in the past 6 days<br>but you’ve had " + successDays +" successful days.<br>"
			 		+ "Make sure you stick to your daily plans!"
			 );
			 return weekFeedback;
		}
		
		else if(successDays == 3)
		{
			weekFeedback.setTXTCode(1);
			 weekFeedback.addTXTone
			 (
					 "You missed your calorie goal 3 times in the past 6 days<br>but you’ve had " + successDays +" successful days.<br>"
			 		+ "You're missing your daily calorie goal too many times.<br>"
			 		+ "Take action by reducing your calorie intake or setting a higher<br>calorie burn goal during your workouts: "
			 );
			 weekFeedback.setButtonCode(1); // display customize meal plan button.
		}
		
		else if(successDays == 2)
		{
			weekFeedback.setTXTCode(1);
			weekFeedback.addTXTone
			(
					 "You missed your calorie goal 4 times in the past 6 days<br>but you’ve had " + successDays +" successful days.<br>"
					 + "You're missing your daily calorie goal too many times. "
			 		 + "You must take action by reducing your calorie intake or setting a higher calorie burn goal during your workouts: "					 
			);
			weekFeedback.setButtonCode(1); // display customize meal plan button.
			return weekFeedback;
		}
		
		else if(successDays == 1)
		{
			weekFeedback.setTXTCode(1);
			 weekFeedback.addTXTone
			 (
					 "You missed your calorie goal 5 times in the past 6 days but you’ve had " + successDays +" successful days.<br>"
					 + "If you keep this up, you will not achieve your weight loss goal. "
			 		 + "You must take action by reducing your calorie intake or setting a higher calorie burn goal during your workouts: "					 
			 );
			 weekFeedback.setButtonCode(1); // display customize meal plan button.
			 return weekFeedback;
		}
		
		else if(successDays == 0)
		{
			weekFeedback.setTXTCode(1);
			 weekFeedback.addTXTone
			 (
					 "You missed your calorie goal every single day in the past 6 days."
					 + "If you keep this up, you will not achieve your weight loss goal. "
					 + "You must take action by reducing your calorie intake or setting a higher calorie burn goal during your workouts: "	
			 );
			 weekFeedback.setButtonCode(1); // display customize meal plan button.
			 return weekFeedback;
		}
		  weekFeedback.addTXTone("Error"); return weekFeedback; 
		
	}
	
	//DAILY PLANS FEEDBACK //MEAL ADDING FEEDBACK //WORKOUT ADDING FEEDBACK
	/**
	 * Updates feedback on daily plan progress
	 * @param plan
	 * @return
	 */
	public Feedback dailyPlanFeedback(Plan plan) //called each time a meal or a workout is added or edited by user
	{
		float caloriesConsumed = plan.getCaloriesConsumed();
		float caloriesBurned = plan.getCaloriesBurned();
		float calDiff = caloriesConsumed - caloriesBurned;
		Feedback planFeedback = new Feedback();
		System.out.println("calDiff from vt: "+calDiff);
		if(calDiff < -650)
		{
			planFeedback.setTXTCode(1);
			planFeedback.addTXTone
			(
					"Be careful not to deprive yourself of too many calories.<br>"
					+ "Losing weight too fast can be unhealthy.<br>"
					+ "Roughly a -500 calorie deficit is recommended."
			);
		}
		else if(-485 > calDiff && calDiff >= -650 )
		{
			planFeedback.setTXTCode(1);
			planFeedback.addTXTone
			(
					"Great! Your plan should result in a calorie deficit of roughly 500 calories!<br>"
					+ "Trainr will help you stick to this plan when this day starts."
			);
		}
		else if(0 >= calDiff && calDiff >- 485)
		{
			planFeedback.setTXTCode(1);
			if(plan.workoutPlanned()) //if a workout has already been planned for that day
			{
				planFeedback.addTXTone
				(
						"Action Required! Your planned calorie difference is not near -500 calories!<br>"
						+ "Either reduce your calorie intake by editing your meals or<br>"
						+ "increase the calories you’ll burn by setting a higher calorie burn goal during your scheduled workout."
				);
				return planFeedback;
			}
			else //if no workout is planned for that day yet
			{
				planFeedback.addTXTone
				(
						"Action Required! Your planned calorie difference is not near -500 calories!<br>"
						+ "Either reduce your calorie intake by editing your meals or<br>"
						+ "schedule a workout to burn more calories."
				);
				return planFeedback;
			}
		}
		else if(calDiff > 0)
		{
			planFeedback.setTXTCode(1);
			if(plan.workoutPlanned()) //if a workout has already been planned for that day
			{
				planFeedback.addTXTone
				(
						"Action Required! Your plan is resulting in a calorie surplus which will cuase you to gain weight!<br>"
						+ "You need to reduce your calorie intake by editing your meals or<br>"
						+ "increase the calories you’ll burn by setting a higher calorie burn goal during your scheduled workout."
				);
				return planFeedback;
			}
			else //if no workout is planned for that day yet
			{
				planFeedback.addTXTone
				(
						"Action Required! Your plan is resulting in a calorie surplus which will cuase you to gain weight!<br>"
						+ "You need to reduce your calorie intake by editing your meals or<br>"
						+ "schedule a workout to burn more calories."
				);
				return planFeedback;
			}
		}
		return planFeedback;
	}
	
	/**
	 * String helper for creating feedback objects containing Strings
	 * @return
	 */
	public String feedbackHelper()
	{ if(completedMileStones.size()==1) return " Milestone "; else return " Milestones "; }
	
}//Class