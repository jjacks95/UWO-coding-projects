package ca.uwo.csd.cs2212.team01;

import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.LinkedList;

/**
 * @author team01
 *
 */
public class Feedback {

	//Attributes
	public int textCode;
	public int fontSize = 24;
	public int buttonCode = 0;
	public LinkedList<String> feedbackText = new  LinkedList<String>();
	public LinkedList<String> feedbackTextTwo = new  LinkedList<String>();
	public LinkedList<Float> feedbackValue = new LinkedList<Float>();
	//date & time attribute
	
	/**
	 * 
	 */
	public Feedback() {}
	
	/**
	 * @param code
	 */
	public void setTXTCode(int code) { this.textCode = code; }
	/**
	 * @param size
	 */
	public void setFontSize(int size) { this.fontSize = size; }
	/**
	 * @param code
	 */
	public void setButtonCode(int code) { this.buttonCode = code; }
	
	/**
	 * @return
	 */
	public int getTextCode() { return this.textCode; }
	/**
	 * @return
	 */
	public int getFontSize() {return this.fontSize; }
	/**
	 * @return
	 */
	public int getButtonCode() { return this.buttonCode; }
	
	/**
	 * @param text
	 */
	public void addTXTone(String text) { this.feedbackText.add(text); }
	/**
	 * @param text
	 */
	public void addTXTtwo(String text) { this.feedbackTextTwo.add(text); }
	/**
	 * @param value
	 */
	public void addFeedbackValue(Float value) { this.feedbackValue.add(value); }
	
	/**
	 * @return
	 */
	public LinkedList<String> getTXTone() { return feedbackText; }
	/**
	 * @return
	 */
	public LinkedList<String> getTXTtwo() { return feedbackTextTwo; }
	/**
	 * @return
	 */
	public LinkedList<Float> getFirstValues() { return feedbackValue; }
}
