 import java.util.*;
 public class HeartRateZone{

	public static int[] HeartRateZone(int[] HeartRateArray){
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

	
public static void main(String[] args){
		int[] rate = new int[1440];
		int[] check = new int[5];
		int i = 0;
		
		for(i = 0; i < 1440; i++){
			if(i < 480){
				rate[i] = 70;
			}else if(i > 480 && i < 960){
				rate[i] = 80;
			}else if(i > 960 && i < 980){
				rate[i] = 110;
			}else if(i > 980 && i < 1000){
				rate[i] = 120;
			}else if(i > 1000 && i < 1020){
				rate[i] = 140;
			}else if(i > 1020 && i < 1025){
				rate[i] = 155;
			}else if(i > 1040 && i < 1075){
				rate[i] = 175;
			}else{
				rate[i] = 60;
			}			
			//System.out.println("Rate = "+ rate[i]);

			}
			
			check = HeartRateZone(rate);
			for(i = 0; i < 5; i++){
			System.out.println("Check["+i+"]: " + check[i]);
			}
			
		}
	}
 