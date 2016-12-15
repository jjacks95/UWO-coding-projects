/*Program name - BonusOnSavings.java
 * 
 * The purpose of this program was to compile different committed amounts to save per quarter
 * and calculate the employee's bonus based on meeting the quota, and exceeding the quota. 
 * As well if they did not reach quota.
 *  
 * Athabasca University ID - 3181465
 * Author- Joshua Samuel Jackson
 * Date - July 15, 2014
 */
package assignment1;

public class BonusOnSavings {
	public double computeBonus(double commitment, double q1, double q2, double q3, double q4){
		double qcommitment = commitment*3;
		double acommitment = commitment*12;
		double bonus = 0;
		
		//if method running the quarterly commitments through the different criteria to see how much should be counted towards the bonus if any
		if(q1 > qcommitment)
		{
			bonus+=(q1-qcommitment)*0.03;
		}
		if(q2 > qcommitment)
		{
			bonus+=(q2-qcommitment)*0.03;
		}
		if(q3 > qcommitment)
		{
			bonus+=(q3-qcommitment)*0.03;
		}
		if(q4 > qcommitment)
		{
			bonus+=(q4-qcommitment)*0.03;
		}

		if(q1+q2+q3+q4 > acommitment)
		{
			bonus+=(q1+q2+q3+q4-acommitment)*0.05;
		}
		
		if( (q1+q2+q3+q4) > acommitment*1.25 )
		{
			bonus += q1+q2+q3+q4 - acommitment;
		}

	//the bonus returned has been run through all criteria, marking how much based on each quarter the deserve to get
		return bonus;
	}
	//the main method to output the total bonus acquired by both Employee 1 and Employee 2
	public static void main(String[] args){
		BonusOnSavings E1 = new BonusOnSavings();
		System.out.println("E1 total bonus: " + E1.computeBonus(2000, 5000, 7000, 4000, 8000) );
		
		BonusOnSavings E2 = new BonusOnSavings();
		System.out.println("E2 total bonus: " + E2.computeBonus(3000, 6000, 9000, 10000, 17000));
	}
}