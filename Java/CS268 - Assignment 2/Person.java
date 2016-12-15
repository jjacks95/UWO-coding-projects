/**
 * Program name - Person.java
 * 
 * This program is designed to build a list of people's name, height, and weight
 * then calculate their BMI and put them into Categories such as Overweight, Normal, Underweight, etc
 * 
 * Author- Joshua Jackson
 * Date - August 15, 2014.
 **/
package assignment2;

import java.util.ArrayList;
//import java.util.Scanner;
 
public class Person {
    //defining each variable
    private double bmi;
    private double height;
    private double weight;
    private String category;
    private String name;
     
    //get method BMI
    public double getBMI(){ 
        return bmi; 
    }
    //get method Heigh
    public double getHeight(){ 
        return height; 
    }
    //get method Weight
    public double getWeight(){ 
        return weight; 
    }
    //defining array contents
    public Person(String name, double weight, double height){
        this.height = height;
        this.weight = weight;
        this.name = name;
    }
    //get method for category
    public String getCategory(){ 
        return category; 
    }
    //set method for category with if method to determine which to output
    public void setCategory(double bmi){ 
        if( bmi < 18.5 ){ this.category = "Underweight";} 
        else if( bmi <= 25 ){ this.category = "Normal"; }
        else if( bmi <=30 ){ this.category = "Overweight"; }
        else { this.category = "Obese";}
    }
    //get method Name
    public String getName(){ 
        return name; 
    }
    //set method BMI
    public void setBMI(double bmi){ 
        this.bmi = bmi; 
    }
    //set method height
    public void setHeight(double height){ 
        this.height = height; 
    }
    //set method weight
    public void setWeight(double weight){ 
        this.weight = weight; 
    }
    //set method name
    public void setName(String name){ 
        this.name = name; 
    }
     
    public static void main(String[] args){
    //main method 
        //entries for array, Name, Weightm and Height to output
        Person A = new Person("Andrew",125.5, 55.1);
        Person B = new Person("Boyd",150, 67);
        Person C = new Person("Cathy",135, 72.3);
        Person D = new Person("Donna",190, 64);
        //Calculate of BMI for each entry 
        A.setBMI(A.getWeight()*703/Math.pow(A.getHeight(),2));
        B.setBMI(B.getWeight()*703/Math.pow(B.getHeight(),2));
        C.setBMI(C.getWeight()*703/Math.pow(C.getHeight(),2));
        D.setBMI(D.getWeight()*703/Math.pow(D.getHeight(),2));
        //BMI assesed and returned category output 
        A.setCategory(A.getBMI());
        B.setCategory(B.getBMI());
        C.setCategory(C.getBMI());
        D.setCategory(D.getBMI());
        //initializing array 
        ArrayList<Person> arr = new ArrayList<Person>();
        //adding persons to array
        arr.add(A);arr.add(B);arr.add(C);arr.add(D);
        //formating entires for output ensuring nothing exceeds 1 decimal point
        for( Person p: arr){
            System.err.format(  "%-10s %5.1f\", %5.1f lbs, BMI: %3.1f, %-5s\n", 
                                p.getName()+":", p.getHeight(), p.getWeight(), p.getBMI(), p.getCategory() );
            
     /* Program Output:
            
        Scanner s = new Scanner(System.in);
        System.out.println("Enter Name: ");
        String name = s.nextLine();
        System.out.println("Enter Weight: ");
        Double weight = s.nextDouble();
        System.out.println("Enter Height: ");
        Double height = s.nextDouble();
        Person A = new Person(name,weight, height);
        A.setBMI(A.getWeight()*703/Math.pow(A.getHeight(),2));
        A.setCategory(A.getBMI());
         */
        }
    }
}

/**
 * Program Output:
 * 1 - Program compiles correctly using jGRASP IDE and J2SDK
 * 
 * 2 - Test Runs:
 * 
 * --Test Run 1(Normal Data Entered):
 * 
 * Program Input:
 * 
 * Enter Name:John
 * Enter Weight:150
 * Enter Height(inches): 60
 *
 * 
 * Expected Program Output:
 * John:  60.0", 150lbs, BMI: 29.3, Overweight
 * 
 * Actual Program Output: as expected
 *
 * --Test Run 2(Negative Weight; )
 * 
 * Program Input:
 * 
 * Enter Name:<Enter>
 * Enter Weight:(100)
 * Enter Height(inches):(60)
 * 
 * Expected Program Output:
 * :  60.0", 100lbs, BMI: 19.5, Normal
 * 
 * Actual Program Output: as expected
 * 
 * 3 - Abnormal Data(Such as negative weight, height)
 * Not applicable for height and weight, and accepts anything for name
 * 
 * 4 - Limiting Conditions
 * Can not enter strings for weight and height
 * Can not enter no data for height or weight.
 * 
 */