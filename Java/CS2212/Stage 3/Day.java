import java.util.ListIterator;


public class Day {

	//Attributes
	//Metric Data Storage
	
	private float[] calArray = new float[1140];
	private float[] floorsArray = new float[1140];
	private float[] stepsArray = new float[1140];
	private float[] distArray = new float[1140];
	private boolean[] actTimeArray = new boolean[1140];
	private float[] HeartRateArray = new float[1140];
	
	
	private int[] totals = new int[6]; //references below:
	//[0] = calorie totals
	//[1] = floor totals
	//[2] = steps totals
	//[3] = distance totals
	//[4] = active time totals
	//[5] = sed time totals
	private float dailyCalDiff;						//needs to be calculated and stored at end of the day
	private Plan plan;
	//FLAG: needs updating after each refresh:
	private int dayProgress = 1140;					//out of 1140
	private int dayNumber;
	
	//Constructor
	public Day() {}
	
	//FLAG: needs updating after each refresh
	//calculating totals
	public void sumPerMin(int dayProgress)
	{
		 float calArraySum = 0, floorsArraySum = 0, stepsArraySum = 0, distanceArraySum = 0;
		
		  for(int i = 0; i < dayProgress; i++){
		    calArraySum += calArray[i];
		  } totals[0] = (int)calArraySum; 
		  //System.out.println("Actual Calories Burned today: "+totals[0]);
		
		  for(int i = 0; i < dayProgress; i++){
		    floorsArraySum += floorsArray[i];
		  } totals[1] = (int)floorsArraySum;
		
		  for(int i = 0; i < dayProgress; i++){
		    stepsArraySum += stepsArray[i];
		  } totals[2] = (int)stepsArraySum;
		  
		  for(int i = 0; i < dayProgress; i++){
		    distanceArraySum += distArray[i];
		  } totals[3] = (int)distanceArraySum;
	}
	public void sumBoolean()
	{
		int actTimeSum = 0, sedTimeSum = 0;
		for(int i = 0; i < dayProgress; i++){
			if(actTimeArray[i]==true) actTimeSum++;
			 else sedTimeSum++;
		  }
		  totals[4] = actTimeSum;
		  totals[5] = sedTimeSum;
	}
	
	public int[] HeartRateZone(int[] HeartRateArray){
		int i = 0, heartrate = 0, zone1 = 0, zone2 = 0, zone3 = 0, zone4 = 0, zone5 = 0;
		int[] zone = new int[5];
		
		for(i = 0; i < 1440; i++){
			heartrate = HeartRateArray[i];
			if(heartrate < 104){
				//Under Zones
				//System.out.println("ERROR");
			
			}else if(heartrate >= 104 && heartrate < 114){
				//Zone 1
				zone1++;
			
			}else if(heartrate >= 114 && heartrate < 133){
				//Zone 2
				zone2++;
			
			}else if(heartrate >= 133 && heartrate < 152){
				//Zone 3
				zone3++;
			
			}else if(heartrate >= 152 && heartrate < 171){
				//Zone 4
				zone4++;
	
			}else if(heartrate >= 171 && heartrate < 190){
				//Zone 5
				zone5++;
			
			}else if(heartrate > 190){
				//Above Zones
				System.out.println("Error Heart Rate too high");
			}
			
		}
			zone[0] = zone1;
			zone[1] = zone2;
			zone[2] = zone3;
			zone[3] = zone4;
			zone[4] = zone5;
			/*
			System.out.println("Zone 1: " + zone1);
			System.out.println("Zone 2: " + zone2);
			System.out.println("Zone 3: " + zone3);
			System.out.println("Zone 4: " + zone4);
			System.out.println("Zone 5: " + zone5);
			*/
			return zone;
	}
	
	//FLAG: needs updating after each refresh
	public void calcDailyCalDiff()
	{
		sumPerMin(dayProgress); 
		int calBurned = totals[0]; 
		//System.out.println("total calories burned: "+totals[0]);
		int calConsumed = (int)plan.getCaloriesConsumed();
		//System.out.println("total calories consumed: "+calConsumed);
		dailyCalDiff = (int)(calConsumed - calBurned);
	}
	
	//Today's Plan (2 methods)
	public Feedback todaysMeals()
	{
		Feedback feedback = new Feedback();
		 
		if(plan.getMeals().size() != 0)
		{
			ListIterator<Meal> meals = plan.getMeals().listIterator();
			while(meals.hasNext())
			{
				Meal meal = meals.next();
				feedback.addTXTone(  meal.getName()  );
				feedback.addTXTone( meal.getCalorieString() );
			}
		}
	
		return feedback;
	}
	public Feedback todaysWorkouts()
	{
		Feedback feedback = new Feedback();
		
		if(plan.getWorkouts().size() != 0)
		{
			if(plan.getWorkouts().size() == 1)
			{ 
				feedback.addTXTone( "Workout "); 																			//different font colour
				feedback.addTXTone( "(- " + plan.getWorkouts().getFirst().getGoalString() +" Cal)" );						//different font colour
			}
			else
			{
				ListIterator<Workout> workouts = plan.getWorkouts().listIterator();
				int counter = 1;
				while(workouts.hasNext())
				{
					feedback.addTXTone( "Workout " + counter ); 										//different font colour
					feedback.addTXTone( " (- " + workouts.next().getGoalString() +" Cal)" );			//different font colour
					counter++;
				}
			}
		}
		
		return feedback;
	}
	
	
	//FLAG: needs updating after each refresh
	//Today's Progress
	public Feedback todaysProgess() // Cal eaten, Cal burned --> to be graphed by Kamal
	{
		Feedback feedback = new Feedback();
		feedback.addFeedbackValue(plan.getCaloriesConsumed());
		feedback.addFeedbackValue(plan.getCaloriesBurned());
		return feedback;
	}
	
	public void generateFakeData()
	{
		for (int i = 0; i < 1140; i++)
		{
			calArray[i] 	= (float)0.5;							//user is burning 0.5 cal each minute for whole day
			floorsArray[i] 	= (float)1.0;							//user climbs 1 floor per minute whole day
			stepsArray[i] 	= (float)10.0;							//user takes 10 steps each minute for whole day
			distArray[i] 	= (float)2.0;							//user travels a distance of 2 meters each minute for whole day
			
			if (i < 60) 	actTimeArray[i] = true; 				//user is active for 60 minutes
			else	 		actTimeArray[i] = false; 				//user is sedentary for rest of day //sedentary minutes = complement of active minutes	
		}
	}
	
	//Setters & Getters
		public void setDailyCalDiff(float dailyCalDiff) {this.dailyCalDiff = dailyCalDiff;}
		public float getDailyCalDiff() {return dailyCalDiff; }
		public void setPlan(Plan plan) {this.plan = plan;}
		public Plan getPlan() {return this.plan;}
		public void setDayNumber(int number) { this.dayNumber = number; }
		public int getDayNumber() {return this.dayNumber; }
		
		
}
