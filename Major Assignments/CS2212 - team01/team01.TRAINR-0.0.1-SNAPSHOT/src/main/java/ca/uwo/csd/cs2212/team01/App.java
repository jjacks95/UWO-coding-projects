/**
 * 
 */
package ca.uwo.csd.cs2212.team01;

// Log4J logging - Josh
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import javax.swing.SwingUtilities;

/**
 * @author team01
 *
 */
public class App {
	static Logger logger = LogManager.getLogger (App.class.getName());
	private static boolean testMode;
	private static MainWindow window;
	
    /**
     * Runs the TRAINR program
     * @param args
     */
    public static void main(String[] args) {
		logger.trace("Entering main");
		logger.warn("Hello Maven/log4j World");
		logger.info("My username is team01");
		
		if (args.length > 0 && args[0].equals("test")) testMode = true;
		else testMode = false;
		
		SwingUtilities.invokeLater(new Runnable() {
        	//@Override
        	public void run() {
        		window = new MainWindow(testMode);
        		window.setVisible(true);
        	}
		});
		
		logger.trace("Exiting main");
	}
}
