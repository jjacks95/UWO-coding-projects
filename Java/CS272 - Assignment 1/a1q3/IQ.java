/**
 * Program name - IQ.java
 * 
 *This program uses Cattell-Horn-Carroll's theory for calculating IQ
 * it follows the specific instructions from the assignment using user input 
 * as well as coded into the program and prints the IQ assumed based on criteria
 *  
 * Author- Joshua Jackson
 * Date - August 10, 2014.
 */
package a1q3;

import java.util.Scanner;

public class IQ {
    //definitions of variables for IQ calculation
    double Gf;
    final String Gc;
    boolean Gq;
    final String Grw;
    String Gsm;
    final double Glr;
    final double Gv;
    double Ga;
    double Gs;
    double Gt;
    
    public IQ(String Gc, String Grw, double Glr, double Gv){
        this.Gc=Gc;
        this.Grw=Grw;
        this.Glr=Glr;
        this.Gv=Gv;    
    }
    //set method
    void setGf(String gf){
        Gf = Integer.valueOf(gf);
    }
    
    void setGq(String gq){
        if( gq.equalsIgnoreCase("true") ){
            Gq = true;
        }
        else{
            Gq = false;
        }
    }
    
    void setGsm(String gsm){
        Gsm = gsm.toLowerCase();
    }
    
    void setGa(String ga){
        Ga = Double.valueOf(ga);
    }
    
    void setGs(String age){
        Gs = (100- Double.valueOf(age))/10;
        Gt = 10 - Gs;
    }
    //get methods
    double getIQ(){
        //setting base to zero
        //setting words to equal score for entering into IQ calc
        double iq = 0;
        iq += Gf; 
        iq += Gc.equals("excellent") ? 15 : Gc.equals("acceptable") ? 8 : 3;
        iq += Gq == true ? 10 : 0;
        iq += Grw.equals("brilliant") ? 15 : Grw.equals("good") ? 10 : Grw.equals("normal") ? 6 : 2;
        iq += Gsm.equals("good") ? 15 : 5;
        iq += Glr + Gv + Ga + Gs + Gt;    
        return iq;
    }
    
    static public void main(String[] args){
        //main method
        
        IQ iq = new IQ("excellent","good",15,10);
        //Scanner method for user input
        Scanner s = new Scanner(System.in);
        //do-while statement for entering the criteria needed for calc
        String in;
        do{
            System.out.print("Enter Fluid Intelligence(1-15): ");
            in = s.nextLine();
        }while(Integer.valueOf(in).intValue()>15 || Integer.valueOf(in).intValue()<1);
        iq.setGf(in);
        do{
            System.out.print("Enter Quantitative Reasoning(true, false): ");
            in = s.nextLine();
        }while(!in.equals("true") && !in.equals("false"));
        
        iq.setGq(in);
        do{
            System.out.print("Enter short-term memory(good, bad): ");
            in = s.nextLine();
        }while(!in.equals("good") && !in.equals("bad"));
        iq.setGsm(in);
        do{
            System.out.print("Enter auditory processing(1-5): ");
            in = s.nextLine();
        }while(Integer.valueOf(in).intValue()>5 || Integer.valueOf(in).intValue()<1);
        iq.setGa(in);
        do{
            System.out.print("Enter person's age(21-75): ");
            in = s.nextLine();
        }while(Integer.valueOf(in).intValue()>75 || Integer.valueOf(in).intValue()<21);
        iq.setGs(in);
        //printing the result of IQ test
        System.out.format("IQ = %.2f\n",iq.getIQ() );
        
    }    
}
/**
 * Test Cases done on .txt file in same question folder.
 */