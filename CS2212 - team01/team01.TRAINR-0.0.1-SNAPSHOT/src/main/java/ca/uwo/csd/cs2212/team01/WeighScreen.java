package ca.uwo.csd.cs2212.team01;

import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.*;

import javax.imageio.ImageIO;
import javax.swing.*;

/**
 * @author team01
 */
public class WeighScreen extends JPanel {
	private static final long serialVersionUID = 1L;
	private MainWindow mainWindow;

	private WeighPanel setWeighPanel;
	
	/**
	 * Class Constructor
	 * @param mainWindow
	 */
	public WeighScreen(MainWindow mainWindow) {
		this.mainWindow = mainWindow;
		
    	//this.setLayout(null);
		this.setOpaque(false);
    	this.setLocation(0, 0);
    	this.setSize(1480, 800);
    	
		this.initUI();
	}
	
    /**
     * Renders the Weigh Screen.
     */
    private void initUI() {
    	this.setWeighPanel = new WeighPanel(mainWindow);
    	
    	this.add(setWeighPanel);
	}
    
    /**
     * Gets the Weigh Panel which holds the user input objects.
     * @return
     */
    public WeighPanel getSetWeighPanel() { return this.setWeighPanel; }
    
    /* (non-Javadoc)
     * @see javax.swing.JComponent#paintComponent(java.awt.Graphics)
     */
    @Override
	protected void paintComponent(Graphics g) {
		super.paintComponent(g);
		
		this.setLayout(null);
		this.setSize(1480,800);
    	this.setLocation(0,0);
		
		Graphics2D g2 = (Graphics2D) g;
		g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
		
		BufferedImage image = null;
		try {
			image = ImageIO.read(new File("UI/bg.jpg"));
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		g2.drawImage(image, 0, 0, getWidth(), getHeight(), 0, 0, image.getWidth(), image.getHeight(), null);
		
		image = null;
		try {
			image = ImageIO.read(new File("UI/fitbit-logo.png"));
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		g2.drawImage(image, 13, getHeight()-image.getHeight()-13, null);

		JLabel label = new JLabel("<html>Fitbit Privacy Statement<br>Copy Rights & Endorsements</html>", JLabel.LEFT);
		label.setFont(mainWindow.FONT_HELVETICA_NEUE_THIN.deriveFont(20.0f));
		Dimension size = label.getPreferredSize();
		label.setBounds(13+image.getWidth()+13, getHeight()-13-50, size.width, size.height);
		label.setForeground(Color.WHITE);
		this.add(label);
		
		image = null;
		try {
			image = ImageIO.read(new File("UI/logo-s.png"));
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		g2.drawImage(image, getWidth()-image.getWidth()-13, getHeight()-13-image.getHeight(), null);
				
		image = null;
		try {
			image = ImageIO.read(new File("UI/exit-icon.png"));
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		JButton exitBtn = new JButton();
		exitBtn.setBackground(null);
		exitBtn.setBorder(null);
		exitBtn.setFocusPainted(false);
		exitBtn.setMargin(new Insets(0, 0, 0, 0));
		exitBtn.setContentAreaFilled(false);
		exitBtn.setBorderPainted(false);
		exitBtn.setOpaque(false);
		exitBtn.setFocusable(false);
		exitBtn.setSize(image.getWidth(), image.getHeight());
		exitBtn.setLocation(getWidth()-image.getWidth()-13, 13);
		exitBtn.addActionListener(new ButtonActionListener(2, 0, mainWindow));
		this.add(exitBtn);
		
		g2.drawImage(image, getWidth()-image.getWidth()-13, 13, null);
	}
}
