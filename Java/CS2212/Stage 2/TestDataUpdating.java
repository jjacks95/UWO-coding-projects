
public class TestDataUpdating {
	//GENERATING DUMMY DATA

	public static void main(String[] args) {

		//create the 7 arrays arrays for each category of data
		float[] calArray = new float[1140];				//each element contains #of calories burned during that minute where each element represents a minute
		float[] floorsArray = new float[1140];			// " but for floors climbed, etc
		float[] stepsArray = new float[1140];
		float[] distanceArray = new float[1140];		// in meters
		boolean[] actTimeArray = new boolean[1140];
		boolean[] sedTimeArray = new boolean[1140];
		float[] heartRateArray = new float[1140];


		//create method to generate dummy data
		for (int i=0; i<1140; i++)
		{
			calArray[i] = (float)0.52;					//user is burning 0.5 cal each minute for whole day
			floorsArray[i] = (float)1.1;				//user climbs 1 floor per minute whole day
			stepsArray[i] = (float)10.4;				//user takes 10 steps each minute for whole day
			distanceArray[i] = (float)2.3;				//user travels a distance of 2 meters each minute for whole day

			//Active minutes and Sedentary minutes
			if (i<60 )
				actTimeArray[i] = true; 				//user is active for 60 minutes
			else
				actTimeArray[i] = false; 				//user is sedentary for rest of day
			sedTimeArray[i] = !actTimeArray[i]; 		//sed minutes is complement of active minutes

			//Heart Rate Zones:
			if(i<500) 									//first 500 minutes, user is not in a heart rate zone
				heartRateArray[i] = 80; 				//80BPM = resting HR. Heart rate zone 1 starts at 101 BPM - 114 BPM so user is not in a heart rate zone yet
			else if(i>=500 && i<560) 					//for 60 minutes, user is in heart rate zone 3 ie. 133-152 BPM (a workout)
				heartRateArray[i] = 135;
			else
				heartRateArray[i] = 80; 				//user has resting HR of 80 BPM rest of day

		}//done generating dummy data

		//creating DataUpdating objects to display data
		DataUpdating temp = new DataUpdating();

		DataUpdating result1 = temp.SumPerMin(calArray, floorsArray, stepsArray, distanceArray);
		DataUpdating result2 = temp.SumBoolean(actTimeArray, sedTimeArray);

		System.out.println("Calories: "+ result1.calArraySum);
		System.out.println("Floors: "+ result1.floorsArraySum);
		System.out.println("Steps: "+ result1.stepsArraySum);
		System.out.println("Distance: "+ result1.distanceArraySum);
		System.out.println("Active Time: "+ result2.actTimeArraySum);
		System.out.println("Sedentary Time: "+ result2.sedTimeArraySum);

	}

}
