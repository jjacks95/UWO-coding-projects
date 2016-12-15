/*Program name - Triangle.java
 * 
 * This program takes the given numbers from the question, and calculates if it is a right triangle
 * using the Pythagorean theorem. It also outputs different messages based on the answers.
 * It also calculates the side unknown based on two sides given.
 * 
 * Athabasca University ID - 3181465
 * Author- Joshua Samuel Jackson
 * Date - July 25, 2014
 */
package assignment1;

public class Triangle {
	private boolean rightTriangle;
	private double a;
	private double b;
	private double c;
	
	public boolean isRightTriangle(){return rightTriangle;}
	public double getA(){ return a; }
	public double getB(){ return b; }
	public double getC(){ return c; }
	public Triangle(double a, double b, double c){
		this.a = a;
		this.b = b;
		this.c = c;
		rightTriangle = Math.pow(a,2) + Math.pow(b,2) == Math.pow(c,2) ? true : false;
	}
	
	public static void main(String args[]){
		Triangle t2a = new Triangle(45,55,75);
		Triangle t2b = new Triangle(28,45,53);
		String isRightTriangle = "False";
		
		// Problem 6 part 1
		//defining two sides of the triangle
		double a=45, c=80;
		
		//the formula to calculate b if the triangle is a right triangle using the Pythag theorem
		double b = Math.sqrt( Math.pow(c, 2) - Math.pow(a, 2) );
		
		//the output expressing the value of b if the triangle is a right triangle
		System.out.format("a=%.0f, c=%.0f is a right triangle. Then b=%.0f\n", a,c,b);
		//same process for another triangle
		a=84; 
		c=91;
		b = Math.sqrt( Math.pow(c, 2) - Math.pow(a, 2) );
		//the output expressing the value of b if the triangle is a right triangle
		System.out.format("a=%.0f, c=%.0f is a right triangle. Then b=%.0f\n", a,c,b);
		
		// Problem 6 part 2
		//part 2 of the question is assessing a triangle given all three sides, 
		//and based on the Pythag formula expressing if it is a right triangle or not
		if( t2a.isRightTriangle() ){
			isRightTriangle = "True";
		}
		//output of the first triangle given
		System.out.format("is a=%.0f, b=%.0f, c=%.0f a right triangle? %s\n", t2a.getA(), t2a.getB(), t2a.getC(), isRightTriangle);
		
		isRightTriangle = "False";
		if( t2b.isRightTriangle() ){
			isRightTriangle = "True";
		}
		//output of the second triangle given
		System.out.format("is a=%.0f, b=%.0f, c=%.0f a right triangle? %s\n",t2b.getA(), t2b.getB(), t2b.getC(), isRightTriangle);
	}
}
