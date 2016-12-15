package ca.uwo.csd.cs2212.team01;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextArea;

/**
 * @author team01
 *
 */
public class ButtonActionListener implements ActionListener {
	private int btnMode, value;
	private MainWindow mainWindow;
	
	/**
	 * Class Constructor
	 * @param btnMode
	 * @param value
	 * @param mainWindow
	 */
	public ButtonActionListener(int btnMode, int value, MainWindow mainWindow) {
		this.mainWindow = mainWindow;
		this.btnMode = btnMode;
		this.value = value;
	}
	
	/* (non-Javadoc)
	 * @see java.awt.event.ActionListener#actionPerformed(java.awt.event.ActionEvent)
	 */
	public void actionPerformed(ActionEvent e) {
		String value;
		JLabel label;
		Dimension size;
		float currentWeight, targetWeight;
		
		// TODO Auto-generated method stub
		switch(this.btnMode) {
		case 0: // Submit Current/Target Weights
			switch(this.value) {
			case 1: // Dashboard Screen
				label = this.mainWindow.getSplashScreen().getSetGoalPanel().getDesc();
				
				try {
					value = this.mainWindow.getSplashScreen().getSetGoalPanel().getCurrentWeight();
					currentWeight = Float.parseFloat(value);
					
					value = this.mainWindow.getSplashScreen().getSetGoalPanel().getTargetWeight();
					targetWeight = Float.parseFloat(value);
					
					if (currentWeight-targetWeight < 2) {
						label.setText("Try to lose at least 2 lbs!");
						size = label.getPreferredSize();
						label.setBounds((503-size.width)/2, label.getY(), size.width, size.height);
						break;
					}else if (currentWeight <= 0 || targetWeight <= 0) throw new NumberFormatException("Negative number!");

					this.mainWindow.setupVirtualTrainer(currentWeight, targetWeight);

					this.mainWindow.setVisible(false);
					this.mainWindow.getContentPane().removeAll();
					this.mainWindow.add(this.mainWindow.getDashboardScreen());
					this.mainWindow.setVisible(true);
				}catch (NumberFormatException ex) {
					label.setText("Invalid format! Enter a positive number.");
					size = label.getPreferredSize();
					label.setBounds((503-size.width)/2, label.getY(), size.width, size.height);
				}finally {
				}
				break;
				
			case 2: // Weigh Screen - Submit New Weight
				label = this.mainWindow.getWeighScreen().getSetWeighPanel().getDesc();
				
				try {
					value = this.mainWindow.getWeighScreen().getSetWeighPanel().getCurrentWeight();
					currentWeight = Float.parseFloat(value);
					
					if (currentWeight <= 0) throw new NumberFormatException("Negative number!");
					
					this.mainWindow.getVirtualTrainer().addNewWeightMeasurement(mainWindow.getUser(), currentWeight);
					
					this.mainWindow.updateDashboardScreen();
					
					this.mainWindow.setVisible(false);
					this.mainWindow.getContentPane().removeAll();
					this.mainWindow.add(this.mainWindow.getDashboardScreen());
					this.mainWindow.setVisible(true);
				}catch (NumberFormatException ex) {
					label.setText("Invalid format! Enter a positive number.");
					size = label.getPreferredSize();
					label.setBounds((503-size.width)/2, label.getY(), size.width, size.height);
				}finally {
				}
				break;
			}
			break;
			
		case 1: // Refresh Button
			this.mainWindow.updateLastRefreshed();
			
			this.mainWindow.updateDashboardScreen();
			
			//label = mainWindow.getDashboardScreen().getRefreshDesc();
			//label.setText("<html>Last Refreshed:<br>" + mainWindow.lastRefreshed().getTXTone().get(0) + "</html>");
			
			this.mainWindow.setVisible(false);
			this.mainWindow.getContentPane().removeAll();
			this.mainWindow.add(this.mainWindow.getDashboardScreen());
			this.mainWindow.setVisible(true);
			break;
			
		case 2: // Exit Button
				
			try{
			   FileOutputStream fout = new FileOutputStream("dashboardpreferences.dat");
			   ObjectOutputStream out = new ObjectOutputStream(fout);
			   out.writeObject(mainWindow.getUserDashboardPreferences());	//(over)writes dashboard preferences file
			   out.close();
			}catch(FileNotFoundException exception){
			   System.out.println(exception.getMessage());
			}catch(IOException exception){
			   System.out.println(exception.getMessage());
			}
			System.exit(0);
			break;
			
		case 3: // Weigh Screen
			this.mainWindow.setVisible(false);
			this.mainWindow.getContentPane().removeAll();
			this.mainWindow.add(this.mainWindow.getWeighScreen());
			this.mainWindow.setVisible(true);
			break;
		}
	}
}
