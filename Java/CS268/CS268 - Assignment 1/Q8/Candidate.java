/*Program name - Candidate.java
 * 
 *  This program uses a list of candidates for a job oppurtunity and runs them 
 *  through different criteria
 *  to output the eligible candidates that the company should consider
 * 
 * Author- Joshua Jackson
 * Date - July 30, 2014
 */

package assignment1;
import java.util.*;//importing all java utilities to use in program

public class Candidate extends AddressBook{
    //defining each attribute given for assignment
    private boolean innovation;
    private double grade;
    private double regulation;
    private String communication;

    public boolean isInnovative(){return innovation;}
    //set methods
    public Candidate(String fn, String ln, double grade, String comm, boolean innov, double reg){
        this.setFirstName(fn);
        this.setLastName(ln);
        this.grade=grade;
        communication=comm;
        innovation=innov;
        regulation=reg;
    }
    //get methods
    public double getGrade(){return grade;}
    public double getRegulation(){return regulation;}
    //defining array list to be later accessed
    public static ArrayList<Candidate>getEligibleCandidates(Candidate[] cands){
        ArrayList<Candidate> ec = new ArrayList<Candidate>();
        for( Candidate c: cands ){
            if( c.isEligible() )
                ec.add(c);
        }
        return ec;//returned array list
    }
  //get and set methods
    public String getCommunication(){
        return communication;
    }
    public void setCommunication(String comm){
        communication = comm;
    }
    public void setGrade(double grade){
        this.grade = grade;}
    
    public void setInnovation(boolean innov){
        innovation=innov;
    }
    public void setRegulation(double reg){
        regulation = reg;
    }
    //boolean method to determine if candidate is eligible based on criteria
    public boolean isEligible(){
        if( getGrade() < 85 )
            if( getRegulation() < .5 || getCommunication().equals("poor") )
                return false;
        return !getCommunication().equals("poor") || isInnovative();
    }

    public static void main(String[] args) {//main method
        //canditates names to be entered into the array list
        Candidate EB = new Candidate("Elena","Brandon",82.3,"poor",true,.5);
        Candidate TM = new Candidate("Thomas","Molson",85.1,"poor",false,1);
        Candidate HW = new Candidate("Hamilton","Winn",77.77,"average",false,.8);
        
        Candidate SS = new Candidate("Suzie","Saranding",69.93,"average",false,0);
        Candidate PW = new Candidate("Philip","Winne",93.03,"average",true,1);
        Candidate AT = new Candidate("Alex","Trebok",88.61,"poor",true,.7);
        
        Candidate EP = new Candidate("Emma","Pivoto",55.99,"excellent",false,.8);
        Candidate JL = new Candidate("John","Lenthen",87.49,"excellent",true,.9);
        Candidate JA = new Candidate("James","Lean",88,"excellent",false,.5);
        
        Candidate JO = new Candidate("Jane","Ostin",91.2,"average",true,.6);
        Candidate EC = new Candidate("Emily","Car",66.79,"excellent",false,.3);
        Candidate DH = new Candidate("Daniel","Hamshire",76.65,"average",true,.2);
        
        Candidate NB = new Candidate("Neda","Bazdar",55.89,"excellent",true,.5);
        Candidate AS = new Candidate("Aaron","Smith",90.01,"excellent",false,.3);
        Candidate KH = new Candidate("Kate","Hen",87.9,"poor",false,.8);
        
        Candidate[] candidates = {EB,TM,HW,SS,PW,AT,EP,JL,JA,JO,EC,DH,NB,AS,KH};
        ArrayList<Candidate>el;
        el = Candidate.getEligibleCandidates(candidates);
        Iterator itr = el.iterator();
        //output of eligible candidates based on criteria 
        System.out.println("List of Eligible Candidates");
        System.out.println("---------------------------");
        for( Candidate c: el)
            System.out.format("%s %s\n", c.getFirstName(), c.getLastName());
    }
}
