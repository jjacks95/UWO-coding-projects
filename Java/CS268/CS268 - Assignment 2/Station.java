/**Program name - Station.java
 * 
 * This class is used to define the different variables and methods necessary
 * for TrainTimeTable.java to function
 * 
 * Author- Joshua Jackson
 * Date - August 20, 2014.
 */
package assignment2;

import java.util.Date;
 
public class Station{
        //defining public variables
        private Date arrival;
        private Date departure;
        private int day;
        private String city;
     
    public Station(String city, Date arrival, Date departure, int day){
        //building the Station content    
        this.city = city;
        this.arrival = arrival;
        this.departure = departure;
        this.day = day;
    }
     
    public Date getArrivalDate(){
        //get method for Arrival Date
        return arrival;
    }
     
    public Date getDepartureDate(){
        //get method Departure Date
        return departure;
    }
     
    public int getDay(){
        //get method Day
        return day;
    }
     
    public String getArrival(){
        //method to define Arrival returned in hours and minutes
        if( null != arrival){
            String hrs = Integer.toString(arrival.getHours());
            String minutes = Integer.toString(arrival.getMinutes());        
            if( arrival.getHours() < 10 ){
                hrs = "0" + hrs;
            }
             
            if( arrival.getMinutes() < 10 ){
                minutes = "0" + minutes;
            }
             
            return hrs + ":" + minutes;
        }
        return "";
    }
     
    public String getCity(){
        //get method for City
        return city;
    }
     
    public String getDeparture(){
        //get method for Departure returned in hours and minutes
        if( null != departure){
            String hrs = Integer.toString(departure.getHours());
            String minutes = Integer.toString(departure.getMinutes());        
            if( departure.getHours() < 10 ){
                hrs = "0" + hrs;
            }
             
            if( departure.getMinutes() < 10 ){
                minutes = "0" + minutes;
            }
             
            return hrs + ":" + minutes;
        }
        return "";
 
    }
     
    public void setArrivalDate(Date arrival){
        //set method for Arrival Date
        this.arrival = arrival;
    }
     
    public void setCity(String city){
        //set method for City
        this.city = city;
    }
     
    public void setDay(int day){
        //set method for Day
        this.day = day;
    }
     
    public void setDepartureDate(Date departure){
        //set method for Departure Date
        this.departure = departure;
    }
}
/**
 * 1 - Program compiles correctly using jGRASP IDE and J2SDK
 * 
 * 2 - Test Runs
 * Not Applicable
 * 
 * 3 - Abnormal Data
 * Not Applicable
 * 
 * 4 - Limiting Conditions
 * Not Applicable
 */