/*Program name - EmployeeSaving.java
 * 
 *This program uses the list of runners from BanffMarathonRunner.java and assigns them random values as initial deposits using java.util.random,
 *it then calculates different interests using the given rates from the question, outputting the report of each runners total accumulated savings
 *based on their different deposits given by the random number generator.
 *  
 * Athabasca University ID - 3181465
 * Author- Joshua Samuel Jackson
 * Date - July 25, 2014
 */

package assignment1;

import java.util.Random;



public class EmployeeSavings extends AddressBook {
	//defining each category necessary to store all needed information for program
	public static final double ANNUAL_INTEREST_RATE = .05;
	private double accountValue;
	public double[] monthlyInterests;
	private double[] monthlySavings;
	//initialzing the extension of AddressBook.java to store the first and last names of the employees
	public EmployeeSavings(String fn, String ln){
		setFirstName(fn);
		setLastName(ln);
	}
	
	public EmployeeSavings(String fn, String ln, double[] d1, double[] d2){
		setFirstName(fn);
		setLastName(ln);
		monthlySavings = d1;
		monthlyInterests = d2;
	}
	//get methods
	public double getAccountValue() {
		accountValue = 0;
		int currentMonthIndex=0;
		for( double p: monthlySavings){
			accountValue += p * Math.pow( (1+ANNUAL_INTEREST_RATE/12), monthlySavings.length-currentMonthIndex);
			currentMonthIndex+=1;
		}
		return accountValue;
	 }
	
	public double[] getMonthlyInterests() {
		return monthlyInterests;
	}
	
	public double[] getMonthlySavings() {
		return monthlySavings;
	}
	//method introduced to generate random deposit amounts for each employee using java.util.random
	//defining the upperbound and lowerbound so the random numbers are always between a certain range asked for by the assignment
	//returned as savings to be accesed later for output
	static double [] generateMonthlySavingsAmounts(int numberOfMonths, double lowerBound, double upperBound){
		Random rand = new Random();
		double[] savings = new double[numberOfMonths];
		double localUpperBound = upperBound - lowerBound;
		for( int i = 0; i < savings.length; i++)
			savings[i] = (rand.nextDouble()*localUpperBound) + lowerBound;
		return savings;
	}
	
	static double [] generateMonthlyInterestAmounts(int numberOfMonths, double lowerBound, double upperBound){
		Random rand = new Random();
		double[] savings = new double[numberOfMonths];
		for( int i = 0; i < savings.length; i++)
			savings[i] = (rand.nextDouble()*upperBound - lowerBound) + lowerBound;
		return savings;
	}
	//method to build the report of total savings/ accumulated account balance for the report that the console outputs at the end
	public static String getReport(EmployeeSavings[] arr){
		String report = "";
		for( EmployeeSavings p : arr ){
			report = report.concat( p.getFirstName() + ' ' + p.getLastName() + ": " + p.getAccountValue() + '\n');
			
                }
		return report;
	}
            
	//formating of the interest and savings accumulated and a check of the 
	//entire program seeing all aspects can be called on not just the report
	void printf(){
		System.out.format("%s %s: %.2f\n",getFirstName(), getLastName(),getAccountValue());
		for( double val: monthlySavings)
			System.out.format("%.2f\n", val);
		System.out.format("Interest:\n");
		for( double val: monthlyInterests)
			System.out.format("%.2f\n", val);
		System.out.println('\n');
	}
	//the array of runners from Banff Marathon Runners used as employees for this class
	public static void main(String args[]){
		EmployeeSavings EB = new EmployeeSavings("Elena","Brandon", generateMonthlySavingsAmounts(12,100,800), generateMonthlyInterestAmounts(12,0.01,.1) );
	    EmployeeSavings TM = new EmployeeSavings("Thomas","Molson", generateMonthlySavingsAmounts(12,100,800), generateMonthlyInterestAmounts(12,0.01,.1) );
	    EmployeeSavings HW = new EmployeeSavings("Hamilton","Winn", generateMonthlySavingsAmounts(12,100,800), generateMonthlyInterestAmounts(12,0.01,.1) );
	    EmployeeSavings SS = new EmployeeSavings("Suzie","Sarandin", generateMonthlySavingsAmounts(12,100,800), generateMonthlyInterestAmounts(12,0.01,.1) );
	    EmployeeSavings PW = new EmployeeSavings("Philip","Winne", generateMonthlySavingsAmounts(12,100,800), generateMonthlyInterestAmounts(12,0.01,.1) );
	    EmployeeSavings AT = new EmployeeSavings("Alex","Trebok", generateMonthlySavingsAmounts(12,100,800), generateMonthlyInterestAmounts(12,0.01,.1) );
	    EmployeeSavings EP = new EmployeeSavings("Emma","Pivoto", generateMonthlySavingsAmounts(12,100,800), generateMonthlyInterestAmounts(12,0.01,.1) );
	    EmployeeSavings JLen = new EmployeeSavings("John","Lenthen", generateMonthlySavingsAmounts(12,100,800), generateMonthlyInterestAmounts(12,0.01,.1) );
	    EmployeeSavings JLea = new EmployeeSavings("James","Lean", generateMonthlySavingsAmounts(12,100,800), generateMonthlyInterestAmounts(12,0.01,.1) );
	    EmployeeSavings JO = new EmployeeSavings("Jane","Ostrin", generateMonthlySavingsAmounts(12,100,800), generateMonthlyInterestAmounts(12,0.01,.1) );
	    EmployeeSavings EC = new EmployeeSavings("Emily","Car", generateMonthlySavingsAmounts(12,100,800), generateMonthlyInterestAmounts(12,0.01,.1) );
	    EmployeeSavings DH = new EmployeeSavings("Daniel","Hamshire", generateMonthlySavingsAmounts(12,100,800), generateMonthlyInterestAmounts(12,0.01,.1) );
	    EmployeeSavings NB = new EmployeeSavings("Neda","Bazdar", generateMonthlySavingsAmounts(12,100,800), generateMonthlyInterestAmounts(12,0.01,.1) );
	    EmployeeSavings AS = new EmployeeSavings("Aaron","Smith", generateMonthlySavingsAmounts(12,100,800), generateMonthlyInterestAmounts(12,0.01,.1) );
	    EmployeeSavings KH = new EmployeeSavings("Kate","Hen", generateMonthlySavingsAmounts(12,100,800), generateMonthlyInterestAmounts(12,0.01,.1) );
	    EmployeeSavings[] employees = {EB,TM, HW, SS, PW, AT, EP, JLen, JLea, JO, EC, DH, NB, AS, KH};
	    
	    //initializing a simple method to output the entire array of runners, and their savings report
	    String str = EmployeeSavings.getReport(employees);
            System.out.print(str);
	    
	 
	}	
}