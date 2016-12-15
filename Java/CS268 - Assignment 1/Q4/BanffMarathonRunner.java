/*Program name - BanffMarathonRunner.java
 * 
 * This program takes the array of runners, storing their names, time registered from the run, and years participated in the run, 
 * using the first program created AddressBook.java. It then outputs, the fastest, and second fastest runners. 
 * As well giving average time of all runners, and listing which runners are above average
 * 
 * Author- Joshua Jackson
 * Date - July 21, 2014
 */
package assignment1;


public class BanffMarathonRunner extends AddressBook{
    int time;
    int years;
    public BanffMarathonRunner(String fn, String ln, int min, int yr){
        time = min;
        years = yr;
        setFirstName(fn);
        setLastName(ln);
    }
    // setters
    void setTime(int time){ this.time = time; }
    void setYears(int years){ this.years = years; }
   
    // getters
   public int getTime(){ return time; }
   public int getYears(){ return years; }
    
    //Fastest Runner
    static BanffMarathonRunner getFastestRunner(BanffMarathonRunner[] runners){
        BanffMarathonRunner fastest = runners[0];
        for( BanffMarathonRunner runner : runners ){
            if( runner.getTime() < fastest.getTime() )
                fastest = runner;
        }
        return fastest; 
    }
    //Second Fastest Runner
    static BanffMarathonRunner getSecondFastestRunner(BanffMarathonRunner[] runners){ 
        BanffMarathonRunner fastest = runners[0].getTime() < runners[1].getTime() ? runners[0] : runners[1]; 
        BanffMarathonRunner secondfastest = runners[0].getTime() < runners[1].getTime() ? runners[1] : runners[0]; 
        for( int i = 2; i < runners.length ; i++ ) 
            if( runners[i].getTime() < fastest.getTime() ) 
                fastest = runners[i]; 
            else if( runners[i].getTime() < secondfastest.getTime() ) 
                secondfastest = runners[i]; 
                  
        return secondfastest; 
    }
    //Average Time of all 15 Runners
    static double getAverageTime(BanffMarathonRunner[] runners){
    	double totalTime = 0;
    	for( int i = 0; i < runners.length ; i++ )
    	    totalTime += runners[i].getTime();
    	return totalTime/runners.length;
    }
    
    //The Above Average Runners
    public static String getAboveAverageRunners(BanffMarathonRunner[] runners){
    	double avgTime = getAverageTime(runners);
    	String aboveAvgRunners="";
    	for( int i = 0; i < runners.length ; i++ )
    	    if( runners[i].getTime() <= avgTime)
    	    	aboveAvgRunners = aboveAvgRunners + runners[i].getFirstName() + ' ' + runners[i].getLastName() + ' ' + runners[i].getTime() + "\n";
    	return aboveAvgRunners;
    }
  
 //the 15 runners defined by the name, time, and years
    public static void main(String[] args){
        BanffMarathonRunner EB = new BanffMarathonRunner("Elena","Brandon",341,1);
        BanffMarathonRunner TM = new BanffMarathonRunner("Thomas","Molson",273,2);
        BanffMarathonRunner HW = new BanffMarathonRunner("Hamilton","Winn",278,5);
        BanffMarathonRunner SS = new BanffMarathonRunner("Suzie","Sarandin",329,7);
        BanffMarathonRunner PW = new BanffMarathonRunner("Philip","Winne",445,9);
        BanffMarathonRunner AT = new BanffMarathonRunner("Alex","Trebok",275,3);
        BanffMarathonRunner EP = new BanffMarathonRunner("Emma","Pivoto",275,4);
        BanffMarathonRunner JLen = new BanffMarathonRunner("John","Lenthen",243,1);
        BanffMarathonRunner JLea = new BanffMarathonRunner("James","Lean",334,1);
        BanffMarathonRunner JO = new BanffMarathonRunner("Jane","Ostrin",412,1);
        BanffMarathonRunner EC = new BanffMarathonRunner("Emily","Car",393,4);
        BanffMarathonRunner DH = new BanffMarathonRunner("Daniel","Hamshire",299,4);
        BanffMarathonRunner NB = new BanffMarathonRunner("Neda","Bazdar",343,3);
        BanffMarathonRunner AS = new BanffMarathonRunner("Aaron","Smith",317,6);
        BanffMarathonRunner KH = new BanffMarathonRunner("Kate","Hen",265,8);
        BanffMarathonRunner[] runners = {EB,TM, HW, SS, PW, AT, EP, JLen, JLea, JO, EC, DH, NB, AS, KH};
        BanffMarathonRunner fastest = BanffMarathonRunner.getFastestRunner(runners);
        BanffMarathonRunner secondfastest = BanffMarathonRunner.getSecondFastestRunner(runners);
        
   //output of for the fastest runner
        System.out.println( "Fastest Runner: " + fastest.getFirstName() + " " + fastest.getLastName() + "\n" +
        				    "Address: " + fastest.getHomeAddress() + "\n" +
        				    "Time (minutes): " + fastest.getTime() + "\n" +
        				    "Years Participated: "+ fastest.getYears() );
   
   //output for the second fastest runner     
        System.out.println( "\n"+ 
                            "Second Fastest Runner: " + secondfastest.getFirstName() + " " + secondfastest.getLastName() + "\n" +
                            "Address: " + fastest.getHomeAddress() + "\n" +
                            "Time (minutes): " + secondfastest.getTime() + "\n" +
                            "Time Difference: "+ (secondfastest.getTime() - fastest.getTime()) );
        
   //output for the average of all 15 runners that participated 
        System.out.println("\n"+ "Average Time of all Runners in the Event (minutes): \n" + BanffMarathonRunner.getAverageTime(runners) );
  
   //output for the above average runners 
        System.out.println("\n"+ "Runners that finished with an above average time: \n" + getAboveAverageRunners(runners));

    }   
}
 