/**
 * 
 */
package ca.uwo.csd.cs2212.team01;

import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.image.BufferedImage;
import java.io.*;

import javax.imageio.ImageIO;
import javax.swing.*;


import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.MalformedURLException;
import java.net.URL;

import com.github.scribejava.apis.FitbitApi20;
import com.github.scribejava.core.builder.ServiceBuilder;
import com.github.scribejava.core.oauth.OAuthService;
import com.github.scribejava.core.model.*; //Request Verb
import com.github.scribejava.core.oauth.OAuth20Service;
import com.github.scribejava.apis.service.FitbitOAuth20ServiceImpl;

import java.awt.Desktop;
import java.net.URI;
import java.util.Iterator;

import org.json.JSONException;
import org.json.JSONObject;
import org.json.JSONArray;

/*import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;

import java.awt.Dimension;
import javax.swing.JPanel;
import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.JButton;
import javax.swing.ButtonGroup;
import javax.swing.JRadioButton;

import java.awt.Color;
import javax.swing.GroupLayout;

import java.awt.BorderLayout;*/

/**
 * @author Kamal
 *
 */
public class MainWindow extends JFrame {
    /**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	int posX = 0, posY = 0;
    
	public MainWindow() {
		this.initUI();
	}
    
    private void initUI() {
    	this.setTitle("TRAINR");
    	this.setSize(1480, 800);
    	this.setUndecorated(true);
    	this.setLocationRelativeTo(null);

    	this.addMouseListener(new MouseAdapter()
    	{
    	   public void mousePressed(MouseEvent e)
    	   {
    	      posX = e.getX();
    	      posY = e.getY();
    	   }
    	});
    	
    	this.addMouseMotionListener(new MouseAdapter()
    	{
    	     public void mouseDragged(MouseEvent evt)
    	     {
    			//sets frame position when mouse dragged			
    			setLocation(evt.getXOnScreen()-posX,evt.getYOnScreen()-posY);
    						
    	     }
    	});
    	
    	// changed EXIT_ON_CLOSE to DISPOSE_ON_CLOSE, prevents errors when using JFrame
    	this.setDefaultCloseOperation(DISPOSE_ON_CLOSE);
    	
    	JPanel mainPanel = new JPanel() {
    		@Override
    		protected void paintComponent(Graphics g) {
    			super.paintComponent(g);
    			BufferedImage bgImage = null;
				try {
					bgImage = ImageIO.read(new File("01.png"));
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
    			g.drawImage(bgImage, 0, 0, getWidth() - 1, getHeight() - 1, 0, 0, bgImage.getWidth() - 1, bgImage.getHeight() - 1, null);
    		}
    	};
    	
    	this.add(mainPanel);
	}
    
    public reFreshData(String date){
    	
    	private static String CALL_BACK_URI="http://localhost:8080";
        private static int CALL_BACK_PORT=8080;

        	String nameOfActivity = "floors";
        	
        	
            //read credentials from a file
            BufferedReader bufferedReader=null;
            // This will reference one line at a time
            String line = null;
             
            //Need to save service credentials for Fitbit
            String apiKey = null;      
            String apiSecret = null;
            String clientID = null;
             
            //holder for all the elements we will need to make an access token ( information about an authenticated session )
            String accessTokenItself =  null;
            String tokenType = null;
            String refreshToken = null;
            Long expiresIn = null;
            String rawResponse = null;
             
            //This is the only scope you have access to currently
            String scope = "activity%20heartrate";
            try {
                // File with service credentials.
                 
                FileReader fileReader =
                        new FileReader("/Users/MARIO/Downloads/Team1Credentials.txt");       
                bufferedReader = new BufferedReader(fileReader);
                clientID= bufferedReader.readLine();
                apiKey= bufferedReader.readLine();
                apiSecret = bufferedReader.readLine();
                bufferedReader.close();
                fileReader = new FileReader("/Users/MARIO/Downloads/Team1Tokens.txt");
                bufferedReader = new BufferedReader(fileReader);
                         
                accessTokenItself = bufferedReader.readLine();
                tokenType = bufferedReader.readLine();
                refreshToken = bufferedReader.readLine();
                expiresIn = Long.parseLong(bufferedReader.readLine());
                rawResponse = bufferedReader.readLine();
         
            }
            catch(FileNotFoundException ex) {
                System.out.println(
                        "Unable to open file\n"+ex.getMessage());
                System.exit(1);
            }
            catch(IOException ex) {
                System.out.println(
                        "Error reading/write file\n"+ex.getMessage());  
                System.exit(1);
            }
            finally{
                try{
                    if (bufferedReader!=null)
                        // Always close files.
                        bufferedReader.close(); 
                }
                catch(Exception e){
                    System.out.println(
                            "Error closing file\n"+e.getMessage()); 
                }
            }
            //  Create the Fitbit service - you will ask this to ask for access/refresh pairs
            //     and to add authorization information to the requests to the API
            FitbitOAuth20ServiceImpl service = (FitbitOAuth20ServiceImpl) new ServiceBuilder()
                    .apiKey(clientID)       //fitbit uses the clientID here
                    .apiSecret(apiSecret)
                    .callback("http://localhost:8080")
                    .scope(scope)
                    .grantType("authorization_code")
                    .build(FitbitApi20.instance());
             
            //  The access token contains everything you will need to authenticate your requests
            //  It can expire - at which point you will use the refresh token to refresh it
            //  See: https://dev.fitbit.com/docs/oauth2/#refreshing-tokens
            //    I have authenticated and given you the contents of the response to use
            OAuth2AccessToken accessToken = new OAuth2AccessToken(
                    accessTokenItself,
                    tokenType,
                    refreshToken,
                    expiresIn,
                    rawResponse);
            // Now let's go and ask for a protected resource!
            System.out.println("Now we're going to access a protected resource...");
            System.out.println();
            //Example request:
            //    This is always the prefix (for my account)
            String requestUrlPrefix = "https://api.fitbit.com/1/user/3WGW2P/";
            String requestUrl;
            
            //    The URL from this point is how you ask for different information
            //"activities/steps/date/2016-02-18/1d/1min/time/07:15/19:30.json";
            requestUrl = requestUrlPrefix + "activities/" + nameOfActivity + "/date/2016-02-18/1d/1min/time/07:15/19:30.json";
            		//"activities/calories/date/2016-02-18/1d/1min/time/07:15/19:30.json";
            //"activities/floors/date/2016-02-18/1d/1min/time/07:15/19:30.json";
            
            // This actually generates an HTTP request from the URL
            //    -it has a header, body ect.
            OAuthRequest request = new OAuthRequest(Verb.GET, requestUrl, service);
             
            // This adds the information required by Fitbit to add the authorization information to the HTTP request
            // You must do this before the request will work
            // See: https://dev.fitbit.com/docs/oauth2/#making-requests
            service.signRequest(accessToken, request);
            //  If you are curious
            System.out.println(request.toString());
            System.out.println(request.getHeaders());
            System.out.println(request.getBodyContents());
             
             
            //  This actually sends the request:
            Response response = request.send();
             
            //  The HTTP response from fitbit will be in HTTP format, meaning that it has a numeric code indicating
            //     whether is was successful (200) or not (400's or 500's), each code has a different meaning
            System.out.println();
            System.out.println("HTTP response code: "+response.getCode());
            int statusCode = response.getCode();
             
            switch(statusCode){
                case 200:
                    System.out.println("Success!");
                    System.out.println("HTTP response body:\n"+response.getBody());
                    
                    StoreDataFromAPI(response.getBody(), nameOfActivity);
                    break;
                case 400:
                    System.out.println("Bad Request - may have to talk to Beth");
                    System.out.println("HTTP response body:\n"+response.getBody());
                    break;
                case 401:
                    System.out.println("Likely Expired Token");
                    System.out.println("HTTP response body:\n"+response.getBody()); 
                    System.out.println("Try to refresh");
                     
                    // This uses the refresh token to get a completely new accessToken object
                    //   See:  https://dev.fitbit.com/docs/oauth2/#refreshing-tokens           
                    // This accessToken is now the current one, and the old ones will not work
                    //   again.  You should save the contents of accessToken.
                    accessToken = service.refreshOAuth2AccessToken(accessToken);
                     
                    // Now we can try to access the service again
                    // Make sure you create a new OAuthRequest object each time!
                    request = new OAuthRequest(Verb.GET, requestUrl, service);
                    service.signRequest(accessToken, request);
                    response = request.send();
                     
                    // Hopefully got a response this time:
                    System.out.println("HTTP response code: "+response.getCode());
                    System.out.println("HTTP response body:\n"+response.getBody());
                    break;
                case 429:
                    System.out.println("Rate limit exceeded");
                    System.out.println("HTTP response body:\n"+response.getBody());
                    break;
                default:
                    System.out.println("HTTP response code: "+response.getCode());
                    System.out.println("HTTP response body:\n"+response.getBody());
            }
             
            BufferedWriter bufferedWriter=null;
            //  Save the current accessToken information for next time
             
            // IF YOU DO NOT SAVE THE CURRENTLY ACTIVE TOKEN INFO YOU WILL NOT BE ABLE TO REFRESH
            //   - contact Beth if this happens and she can reissue you a fresh set
             
            try {
                FileWriter fileWriter; 
                fileWriter =
                        new FileWriter("/Users/MARIO/Downloads/Team1Tokens.txt");
                bufferedWriter = new BufferedWriter(fileWriter);
                bufferedWriter.write(accessToken.getToken());
                bufferedWriter.newLine();
                bufferedWriter.write(accessToken.getTokenType());
                bufferedWriter.newLine();
                bufferedWriter.write(accessToken.getRefreshToken());
                bufferedWriter.newLine();
                bufferedWriter.write(accessToken.getExpiresIn().toString() );
                bufferedWriter.newLine();
                bufferedWriter.write(accessToken.getRawResponse());
                bufferedWriter.newLine();
                bufferedWriter.close();
            }
            catch(FileNotFoundException ex) {
                System.out.println(
                        "Unable to open file\n"+ex.getMessage());               
            }
            catch(IOException ex) {
                System.out.println(
                        "Error reading/write file\n"+ex.getMessage());                 
            }
            finally{
                try{
                    if (bufferedWriter!=null)
                        bufferedWriter.close(); 
                }
                catch(Exception e){
                    System.out.println(
                            "Error closing file\n"+e.getMessage()); 
                }
            }//end try
        }//end main
        
        private static void StoreDataFromAPI(String responseBody, String name){

        	try {
    			JSONObject jsonObj =  new JSONObject(responseBody);
    			JSONArray dataType = (JSONArray) jsonObj.get("activities-" + name);
    			JSONObject dataTypeOverTime = (JSONObject) jsonObj.get("activities-" + name + "-intraday");
    			JSONArray dataSet = (JSONArray) dataTypeOverTime.get("dataset");

    			 System.out.println("\nactivities-steps-intraday:");
    			 System.out.println("\n" + dataSet.length());
    			 
    	         for(int i = 0; i < dataSet.length(); i++){
    	        	 JSONObject jsonDataObj = dataSet.getJSONObject(i);
    	        	System.out.println(jsonDataObj.toString());

    	        	int value;
    	    		if(name == "calories"){
    	    			
    	        		 Double calorieValue = (Double) jsonDataObj.get("value");
    	 	    		
    	 	        	System.out.println(calorieValue); 
    	        		 //store in array 
    	    		}
    	    		else {

    	    			//for other values 
    	    			value = (int) jsonDataObj.get("value");
    		    		
    		        	System.out.println(value); 
    		        	//store in array 
    	    		}
    	        }      
    		} catch (JSONException e) {
    			// TODO Auto-generated catch block
    			e.printStackTrace();
    		}
        
    }
}