package ca.uwo.csd.cs2212.team01;

import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.awt.Label;
import java.awt.Point;
import java.awt.Rectangle;
import java.awt.RenderingHints;

import javax.swing.JLabel;
import javax.swing.JPanel;

/**
 * @author team01
 *
 */
public class LineAxisGraph extends JPanel {
	private int numTicks;
	private int x, y, width, height, textHeight = 0;
	private boolean flip;
	
	/**
	 * Class Constructor
	 * @param data
	 * @param x
	 * @param y
	 * @param width
	 * @param height
	 * @param numTicks
	 * @param flip
	 */
	public LineAxisGraph(String[] data, int x, int y, int width, int height, int numTicks, boolean flip) {
		this.x = x;
		this.y = y;
		this.width = width;
		this.height = height;
		this.numTicks = numTicks;
		this.flip = flip;

		this.setLayout(null);
		this.setOpaque(false);

		this.setSize(this.width, this.height);
    	this.setLocation(this.x, this.y);
		
		int i;
		JLabel label;
		//Insets insets = this.getInsets();
		Dimension size = null;

		y = 0;
		for(i = 0; i < numTicks; i++) {
			x = (this.width/numTicks)/2 + (this.width/numTicks)*i;
			label = new JLabel(data[i], JLabel.LEFT);
			//label.setFont(FONT_HELVETICA_NEUE_THIN.deriveFont(12.0f));
			size = label.getPreferredSize();
			if (this.textHeight < size.height) this.textHeight = size.height;
			if (flip) label.setBounds(x - size.width/2, y, size.width, size.height);
			else label.setBounds(x - size.width/2, y+this.height-this.textHeight + 2, size.width, size.height);
			label.setForeground(Color.WHITE);
			this.add(label);
		}
	}
	
	/* (non-Javadoc)
	 * @see javax.swing.JComponent#paintComponent(java.awt.Graphics)
	 */
	@Override
	protected void paintComponent(Graphics g) {
		super.paintComponent(g);

		Graphics2D g2 = (Graphics2D) g;
		g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
		
		int i, x, y;
		//Line line;

		g2.setColor(Color.WHITE);
		g2.setStroke(new BasicStroke(1.0f));
		
		if (flip) y = this.textHeight+2;
		else y = 0;
		for(i = 0; i < this.numTicks; i++) {
			x = (this.width/this.numTicks)/2 + (this.width/this.numTicks)*i;
			g.drawLine(x, y, x, y+this.height-this.textHeight-2);
		}
	}
}
