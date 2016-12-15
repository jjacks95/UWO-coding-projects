/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package testing;


/**
 *
 * @author Josh Jackson
 */
public class Practice5 {
    //evaluating simple expression
    
  public static void main(String[] args){
    //defining variables
    char operator;
    double x;
    double y;
    double value = 0;
     //TextIO system output 
      TextIO.putln("Enter Equation with two numbers and one operation: ");
      TextIO.putln("only +, -, / or *");
      TextIO.putln("To end put 0");
      TextIO.putln();
      
      //while look to collect data and see if x is 0 or not
     while(true){
         
         x = TextIO.getDouble();
         if(x == 0)
             break;
         operator = TextIO.getChar();
         y = TextIO.getDouble();
         
     
      //switch method to decide which case and which operator to use
      switch (operator){
          case '+' : value = (x + y);
             break;
              
          case '-' : value = (x - y);
              break;
              
          case '/' : value = (x / y);
              break;
              
          case '*' : value = (x * y);
              break;
          
          default: TextIO.putln("Unknown operator: " + operator);
              continue;
      }
      
      TextIO.putln("Answer: " + value);
     
     }
     
      TextIO.putln("Good-Bye");
    
  }
     
      
}  
   

