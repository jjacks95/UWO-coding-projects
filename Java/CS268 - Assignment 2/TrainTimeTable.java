/**
 * Program name - TrainTimeTable.java
 * 
 * This program sorts and builds a list of the Train Schedule
 * (Arrival, Departure, and Day) It also uses scanner utility to allow the user
 * to chose if they wish to see the Schedule
 * 
 * Athabasca University ID - 3181465
 * Author- Joshua Samuel Jackson
 * Date - August 20, 2014.
 */

package assignment2;
//imported utilities
import java.util.ArrayList;
import java.util.Date;
import java.util.LinkedList;
import java.util.Scanner;
 
public class TrainTimeTable {
 
    LinkedList<Station> schedule;
    static final int MINUTES_PER_HOUR = 60;
 
    public TrainTimeTable(ArrayList<Station> schedule) {
        //this.schedule.addAll(schedule);
        this.schedule = new LinkedList<Station>();
        for (Station s : schedule) {
            this.schedule.add(s);
        }
    }
 
    void delayArrival(Station s, int minute) {
        Date d = s.getArrivalDate();
        if (null != d) {
            int hrsBeforeDelay = d.getHours();
            if ((d.getMinutes() + minute) >= MINUTES_PER_HOUR) {
                //System.out.format("%d\n", d.getHours() + (int)(d.getMinutes() + minute)/MINUTES_PER_HOUR);
                d.setHours(d.getHours() + (d.getMinutes() + minute)/MINUTES_PER_HOUR);
                System.out.format("Hours before: %d Hours after: %d\n",hrsBeforeDelay, d.getHours());
                d.setMinutes(d.getMinutes() + minute % MINUTES_PER_HOUR);
            } else {
                d.setMinutes(d.getMinutes() + minute);
            }
            s.setArrivalDate(d);
        }
    }
 
    void delayDeparture(Station s, int minute) {
        Date d = s.getDepartureDate();
        if (null != d) {
            if ((d.getMinutes() + minute) > MINUTES_PER_HOUR) {
                d.setHours(d.getHours() + (d.getMinutes() + minute)/MINUTES_PER_HOUR);
                d.setMinutes(d.getMinutes() + minute % MINUTES_PER_HOUR);
            } else {
                d.setMinutes(d.getMinutes() + minute);
            }
            s.setDepartureDate(d);
        }
    }
 
    public void delay(String station, int minute) {
        boolean found = false;
        for (Station s : schedule) {
            if (s.getCity().equalsIgnoreCase(station)) {
                found = true;
            }
            if (found) {
                if (s.getArrivalDate() != null) {
                    delayArrival(s, minute);
                }
                if (s.getDepartureDate() != null) {
                    delayDeparture(s, minute);
                }
            }
        }
    }
 
    public void displaySchedule() {
        System.out.format("\n%-15s%-10s%-10s%-10s\n", "Station", "Arrival", "Departure", "Day");
 
        for (Station s : schedule) {
            System.out.format("%-15s%-10s%-10s%-10s\n",
                s.getCity(),
                s.getArrival(),
                s.getDeparture(),
                s.getDay());
        }
    }
 
    public static void main(String args[]) {
 
        ArrayList<Station> sc = new ArrayList<Station>();
 
        Station V = new Station("Vancouver",
            null, //starting point - no arrival
            new Date(0, 0, 1, 20, 30),
            1);
 
        Station K = new Station("Kamploops",
            new Date(0, 0, 2, 06, 0),
            new Date(0, 0, 2, 06, 35),
            2);
 
        Station J = new Station("Jasper",
            new Date(0, 0, 2, 16, 0),
            new Date(0, 0, 2, 17, 30),
            2);
 
        Station E = new Station("Edmonton",
            new Date(0, 0, 2, 23, 0),
            new Date(0, 0, 2, 23, 59),
            2);
 
        Station S = new Station("Saskatoon",
            new Date(0, 0, 3, 8, 0),
            new Date(0, 0, 3, 8, 25),
            3);
 
        Station W = new Station("Winnipeg",
            new Date(0, 0, 3, 20, 45),
            new Date(0, 0, 3, 22, 30),
            3);
 
        Station SL = new Station("Saskatoon",
            new Date(0, 0, 4, 5, 2),
            new Date(0, 0, 4, 5, 42),
            4);
 
        Station H = new Station("Hornepayne",
            new Date(0, 0, 4, 15, 35),
            new Date(0, 0, 4, 16, 10),
            4);
 
        Station C = new Station("Capreol",
            new Date(0, 0, 5, 0, 18),
            new Date(0, 0, 5, 0, 48),
            5);
 
        Station T = new Station("Toronto",
            new Date(0, 0, 5, 9, 30),
            null, //destination - no departure
            5);
 
        // Train time table
        sc.add(V);
        sc.add(K);
        sc.add(J);
        sc.add(E);
        sc.add(S);
        sc.add(W);
        sc.add(SL);
        sc.add(H);
        sc.add(C);
        sc.add(T);
 
 
        TrainTimeTable tt = new TrainTimeTable(sc);
 
        // consume user input
        Scanner s = new Scanner(System.in);
        System.out.println("Type 'Show' to see Train Schedule\n or 'Quit' to close schedule:");
        String input = s.nextLine();
        while (!input.equalsIgnoreCase("Quit")) {
            if (input.equalsIgnoreCase("Show")) {
                tt.displaySchedule();
                System.out.println("\nIf delay please enter 'delay' followed by station name\nfollowed by number of minutes:");
                
            } else if (input.split(" ")[0].equalsIgnoreCase("delay")) {
                
                String[] ss = input.split(" ");
                System.out.format("Delay: %s hours %s minutes",ss[1], ss[2]);
                tt.delay(ss[1], Integer.valueOf(ss[2]));
                tt.displaySchedule();
            }
            System.out.println();
            input = s.nextLine();
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
 * Enter 'Show' to see Train Schedule or 'Quit' to close Schedule:
 * 
 * Show
 * If delay please enter 'delay' followed by station name followed by number of minutes:
 * 
 * delay Vancouver 10
 * 
 * Expected Output:
 * Delay: Vancouver 0 hours 10 minutes
 * Station        Arrival   Departure Day
 * Vancouver                20:40     1         
 * Kamploops      06:10     06:45     2         
 * Jasper         16:10     17:40     2         
 * Edmonton       23:10     01:09     2        
 * Saskatoon      08:10     08:35     3         
 * Winnipeg       20:55     22:40     3         
 * Saskatoon      05:12     05:52     4         
 * Hornepayne     15:45     16:20     4         
 * Capreol        00:28     00:58     5         
 * Toronto        09:40               5    
 *
 * Actual Program Output: as expected
 * 
 * --Test Run 2(no data entered):
 * 
 * Program Input:
 *
 * Enter 'Show' to see Train Schedule or 'Quit' to close Schedule:
 * <Enter> 
 * 
 * Expected Program Output: 
 * Display first prompt again
 * 
 * 
 * Actual Program Output: as expected
 *
 * --Test Run 3(entering Quit)
 * 
 * Type 'Show' to see Train Schedule or 'Quit' to close schedule:
 * Quit
 * 
 * Expected Output:
 * close program
 * 
 * Actual Output: as expected
 * 
 * 
 * 3 - Abnormal Data
 * Entering anything but specified words will result in exceptions
 * 
 * 4 - Limiting Conditions
 * can only do what is capable of doing. 
 * Can only enter words established in the program
 * 
 */