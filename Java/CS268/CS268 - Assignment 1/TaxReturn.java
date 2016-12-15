/*Program name - TaxReturn.java
 * 
 * This program is given by the assignment and the task was to edit the code, and add the additional requested items.
 * The program compiles the tax of the user, and based on their criteria outputs the amount of the tax, based on given rates
 *  
 * Author- Joshua Jackson
 * Date - July 30, 2014
 */

package assignment1;
import java.util.Scanner;

public class TaxReturn
{
	//this class was written for the assignment additions have been made to the given program
	//the defining of each variable of the program
    public static final int SINGLE = 1;
    public static final int MARRIED = 2;
    public static final int SINGLE_PARENT = 3;
    public static final int UNKNOWN = 4;
    private static final double SINGLE_PARENT_PER_CHILD_DEDUCTION = 5000;
    
    private static final double RATE1 = 0.15;
    private static final double RATE2 = 0.28;
    private static final double RATE3 = 0.31;
    private static final double RATE4 = 0.25;
    private static final double RATE5 = 0.35;
    private static final double RATE4_THRESHOLD = 150000;
    private static final double RATE5_THRESHOLD = 200000;
    
    private static final double SINGLE_BRACKET1 = 21450;
    private static final double SINGLE_BRACKET2 = 51900;
    private static final double SINGLE_BRACKET3 = 249999;
    
    private static final double MARRIED_BRACKET1 = 35800;
    private static final double MARRIED_BRACKET2 = 86500;
    private static final double MARRIED_BRACKET3 = 349999;
    
    private final double income;
    private final int status;
    private final int numOfChildren;
    
    /**
    *Constructs a TaxReturn object for a given income and 
    *Martial status, and computes the tax. 
    *@param anIncome the taxpayer income 
    *@param aStatus either SINGLE or MARRIED
    *@param children is the number of children
    */
   
    public TaxReturn(double anIncome, int aStatus, int children)
    {
        income = anIncome;
        status = aStatus;
        numOfChildren = children;
    }
    //get method with a if and else method in order to figure out what rate to give to each user
    public double getTax()
    {
        double tax;
        if (status == SINGLE)
        {
            if (income <= SINGLE_BRACKET1)
                tax = RATE1 * income;
            else if (income <= SINGLE_BRACKET2)
                tax = RATE1 * SINGLE_BRACKET1
                    + RATE2 * (income - SINGLE_BRACKET1);
            else
                tax = RATE1 * SINGLE_BRACKET1
                    + RATE2 * (SINGLE_BRACKET2 - SINGLE_BRACKET1)
                    + RATE3 * (income - SINGLE_BRACKET2);
            if( income > SINGLE_BRACKET3 ){
                tax += RATE4 * (income - RATE4_THRESHOLD);
            }
        }
        else if (status == SINGLE_PARENT)
        {
            if (income <= SINGLE_BRACKET1)
                tax = RATE1 * income;
            else if (income <= SINGLE_BRACKET2)
                tax = RATE1 * SINGLE_BRACKET1 + RATE2 * (income - SINGLE_BRACKET1);
            else
                tax = RATE1 * SINGLE_BRACKET1 + RATE2 * (SINGLE_BRACKET2 - SINGLE_BRACKET1)
                    + RATE3 * (income - SINGLE_BRACKET2);
            // per child deduction
            tax -= SINGLE_PARENT_PER_CHILD_DEDUCTION * numOfChildren;
        }
        else
        {
            if (income <= MARRIED_BRACKET1)
                tax = RATE1 * income;
            else if (income <= MARRIED_BRACKET2 )
                tax = RATE1 * MARRIED_BRACKET1 + RATE2 * (income - MARRIED_BRACKET1);
            else
                tax = RATE1 * MARRIED_BRACKET1 + RATE2 * (MARRIED_BRACKET2 - MARRIED_BRACKET1) 
                    + RATE3 * (income - MARRIED_BRACKET2);
            if( income > MARRIED_BRACKET3 ){
                tax += RATE5 * (income - RATE5_THRESHOLD);
            }
        }
        return tax;
    }
    //main method using the java.util.scanner to create the user interaction with the program, 
    //and allow for the questions needed to evaluate tax for each person 
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        System.out.print("Please enter your income: ");
        double income = in.nextDouble();
        System.out.print("Enter S (single) or M (married): ");

        String input = in.next();
        //if and else methods to tell the program which place to go for the evaluation of the income 
        //based on the answers provided to the questions above
        int status;
        int numOfChildren = 0;
        if (input.equalsIgnoreCase("S"))
            status = TaxReturn.SINGLE;
        else if (input.equalsIgnoreCase("M"))
            status = TaxReturn.MARRIED;
        else if (input.equalsIgnoreCase("SP")){
            status = TaxReturn.SINGLE_PARENT;
            System.out.print("Enter number of children: ");
            numOfChildren = in.nextInt();
        }
        else
            status = TaxReturn.UNKNOWN;
        TaxReturn aTaxReturn = new TaxReturn(income, status, numOfChildren);
       //output of the tax for the person 
        System.out.println("The tax is " + aTaxReturn.getTax());
        in.close();
    }
}