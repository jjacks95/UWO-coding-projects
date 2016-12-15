package ca.uwo.csd.cs2212.team01;

import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.*;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.LinkedList;
import java.util.ListIterator;

import javax.imageio.ImageIO;
import javax.swing.*;

/**
 * @author team01
 *
 */
public class LoadingScreen extends JPanel {
	private static final long serialVersionUID = 1L;
	private MainWindow mainWindow;
	
	//Time & Date Formats:
	private SimpleDateFormat fmDate = new SimpleDateFormat("yyyy-MM-dd"); 		//date format: 2016-02-18
	private SimpleDateFormat fmTime = new SimpleDateFormat ("H:mm");				//time format 07:15 (or 13:00 for 1pm)
	
	private JPanel titlePanel, devicesPanel;
	
	/**
	 * Class Constructor
	 * @param mainWindow
	 */
	public LoadingScreen(MainWindow mainWindow) {
		this.mainWindow = mainWindow;
		
    	//this.setLayout(null);
		this.setOpaque(false);
    	this.setLocation(0, 0);
    	this.setSize(1480, 800);
    	
		this.initUI();
	}
	
	/**
	 * Sets up the Virtual Trainer in "normal" mode.
	 */
	public void initSetup() {
		if(mainWindow.isFirstCall())
		{
			Date[] dateArray = new Date[7]; int dayNumber;
			for (int i = 0; i<6; i++)
			{ dayNumber = (5 - i); dateArray[dayNumber] = new Date(System.currentTimeMillis() - (i+1)*24*60*60*1000); }
			
			//Add 6 previous empty days: [TEST: PASSED]
			
			for(int i = 0; i<6; i++)
			{ Day day = new Day(dateArray[i]); mainWindow.getDays().add(day); }
			
			//Add empty "today": [TEST: PASSED]
			
			Date todayDate = new Date();
			//calculate number of elapsed minutes for current day:
			int hours = todayDate.getHours(); int minutes=0;
			if(hours == 0)
				{ minutes = todayDate.getMinutes(); }
			else
				{ minutes = hours*60 + todayDate.getMinutes(); }
			
			Day day = new Day(todayDate); mainWindow.getDays().add(day); day.setDayProgress(minutes);
			
			//Create 7 more empty day objects. Add to "futureDays" LinkedList: [TEST: PASSED]
			for (int i = 0; i<7; i++)
			{ dateArray[i] = new Date(System.currentTimeMillis() + (i+1)*24*60*60*1000); }
			
			for(int i = 0; i<6; i++)
			{ day = new Day(dateArray[i]); day.setDayProgress(0); mainWindow.getFutureDays().add(day); }
			
			//Fill the past 7 empty days ("days" LinkedList) with data by using APICall(): [TEST: 			]			
			
			ListIterator<Day> previousDays = mainWindow.getDays().listIterator(); 
			mainWindow.setLastCall(new Date()); 
			while(previousDays.hasNext())
			{
				day = previousDays.next();
				
				if(day.getDate().getDay() == new Date().getDay()) //if day == "current day"
				{  mainWindow.APICall(fmDate.format(day.getDate()),"00:00",fmTime.format(day.getDate()),day); day.processNewData();  }
				
				else 
				{  mainWindow.APICall(fmDate.format(day.getDate()),"00:00","23:59",day); day.processNewData();  }
			}
			
			mainWindow.setFirstCall(false);
			
			//Create new user and new virtual trainer
			mainWindow.setUser(new User("Beth Locke"));
			//vt = new VirtualTrainer();
		}
		
		//this.mainWindow.setVisible(false);
		this.mainWindow.getContentPane().removeAll();
		this.mainWindow.add(this.mainWindow.getSplashScreen());
		//this.mainWindow.setVisible(true);
	}
	
	/**
	 * Sets up the Virtual Trainer in "test" mode.
	 */
	public void initTestMode() {
		/*int x = 0;
		while(x == 0) {
		}*/
		
		Date today = new Date();
		
		mainWindow.setLastCall(today);
		//Random macro information - Constructor: public Macro(float calories, float proteins, float carbs, float fats):
		Macro macro1 = new Macro((float)100, (float)20, (float)50, (float)5 );
		Macro macro2 = new Macro((float)200, (float)10, (float)25, (float)4 );
		Macro macro3 = new Macro((float)200, (float)5, (float)15, (float)3 );

		//Food items and their nutritional info built with the previous macro information:
		Food food1 = new Food("food item",1,(float)1,"cup",macro1);
		Food food2 = new Food("food item",1,(float)1,"cup",macro2);
		Food food3 = new Food("food item",1,(float)1,"cup",macro3);
	
		//User builds their meals by specifying servings of food and adding them to meals:
		//Meal 1
		Meal meal1 = new Meal(); 
		FoodServing foodServing1 = new FoodServing(food1,(float)1,"cup"); // 100 calories
		FoodServing foodServing2 = new FoodServing(food2,(float)1,"cup"); // 200 calories
		FoodServing foodServing3 = new FoodServing(food3,(float)1,"cup"); // 200 calories
		meal1.addFoodServing(foodServing1); // 100 calories
		meal1.addFoodServing(foodServing2); // 200 calories
		meal1.addFoodServing(foodServing3); // 200 calories // total: 500 calories
		
		//Meal 2
		Meal meal2 = new Meal(); 
		meal2.addFoodServing(foodServing1); // 100 calories
		meal2.addFoodServing(foodServing2); // 200 calories
		meal2.addFoodServing(foodServing3); // 200 calories // total: 500 calories
		
		//Meal 3
		Meal meal3 = new Meal(); 
		meal3.addFoodServing(foodServing1); // 100 calories
		meal3.addFoodServing(foodServing2); // 200 calories
		meal3.addFoodServing(foodServing3); // 200 calories // total: 500 calories
		
		//Total Calories In for the day: 500 + 500 + 500 = 1500 Calories

		//Workouts created by user
		Workout workout1 = new Workout(200); //Scheduled Workout has a Calorie Burn Goal of 200 Calories 
		Workout workout2 = new Workout(200); //Scheduled Workout has a Calorie Burn Goal of 200 Calories
		Workout workout3 = new Workout(200); //Scheduled Workout has a Calorie Burn Goal of 200 Calories
		Workout workout4 = new Workout(200); //Scheduled Workout has a Calorie Burn Goal of 200 Calories
		Workout workout5 = new Workout(200); //Scheduled Workout has a Calorie Burn Goal of 200 Calories
		Workout workout6 = new Workout(200); //Scheduled Workout has a Calorie Burn Goal of 200 Calories
		Workout workout7 = new Workout(200); //Scheduled Workout has a Calorie Burn Goal of 200 Calories

		//Adding the meals and workouts that the user built to the user's daily plans. BMR = Basal Metabolic Rate = 1600 Calories burned passively by user.
		Plan[] planArray = new Plan[7];
		Plan plan1 = new Plan(); plan1.addMeal(meal1); plan1.addMeal(meal2); plan1.addMeal(meal3); plan1.addWorkout(workout1); planArray[0] = plan1; // Cal In = 1500 Calories | Cal Out = BMR + 200 Calories
		Plan plan2 = new Plan(); plan2.addMeal(meal1); plan2.addMeal(meal2); plan2.addMeal(meal3); plan2.addWorkout(workout2); planArray[1] = plan2; // Cal In = 1500 Calories | Cal Out = BMR + 200 Calories
		Plan plan3 = new Plan(); plan3.addMeal(meal1); plan3.addMeal(meal2); plan3.addMeal(meal3); plan3.addWorkout(workout3); planArray[2] = plan3; // Cal In = 1500 Calories | Cal Out = BMR + 200 Calories
		Plan plan4 = new Plan(); plan4.addMeal(meal1); plan4.addMeal(meal2); plan4.addMeal(meal3); plan4.addWorkout(workout4); planArray[3] = plan4; // Cal In = 1500 Calories | Cal Out = BMR + 200 Calories
		Plan plan5 = new Plan(); plan5.addMeal(meal1); plan5.addMeal(meal2); plan5.addMeal(meal3); plan5.addWorkout(workout5); planArray[4] = plan5; // Cal In = 1500 Calories | Cal Out = BMR + 200 Calories
		Plan plan6 = new Plan(); plan6.addMeal(meal1); plan6.addMeal(meal2); plan6.addMeal(meal3); plan6.addWorkout(workout6); planArray[5] = plan6; // Cal In = 1500 Calories | Cal Out = BMR + 200 Calories
		Plan plan7 = new Plan(); plan7.addMeal(meal1); plan7.addMeal(meal2); plan7.addMeal(meal3); plan7.addWorkout(workout7); planArray[6] = plan7; // Cal In = 1500 Calories | Cal Out = BMR + 200 Calories
		
		//Each plan has a planned calorie difference of 1500 cal -1800 cal = 
		// -300 calories deficit
		
	//			for(int i = 0;i<7;i++) 
	//			{
	//				System.out.println("Cal burned: "+ planArray[i].getCaloriesBurned()); 
	//				System.out.println("Cal consumed: " +planArray[i].getCaloriesConsumed());
	//			}
		
		//TEST: PASSED	
		//Generating fake plans is done.
		
		//Test Mode assumes user will update app "today @ 6pm (current time)" where app determines it needs to download 7 days worth of raw data --> 6 previous days and today.
		//In other words, the app has not been refreshed for the past 7 days - or - it has been 7 days since the app has made any API calls to download new data from Fitbit servers.
		//The 6 previous days gets filled with fake raw data from 8am till 11:59pm each day. All other elements in arrays will be empty.
		//"Today" gets filled with fake raw data from 8am till 5pm. Thus, Test Mode simulates the user refreshing the app at 5pm "today"
				
		
		/////////////////////////////////////////////////////////////////////////////////
			int updateDays = 7;		//Simulated refresh assumes 7 new incoming day's worth of data is downloaded which = 6 Previous Days and Today.
		////////////////////////////////////////////////////////////////////////////////
		
		for(int i = 0;i<updateDays-1;i++)
		{ Day day = new Day(); day.setDate(new Date(today.getTime()-1440*60*1000*(updateDays-1-i))); day.setDayProgress(1440); day.setPlan(planArray[i]); day.generateFakeData(1); mainWindow.getDays().add(day); } //add 6 "previous days" worth of fake raw data & fake plans.
		Day day = new Day(); day.setDate(today);day.setDayProgress(1020); day.setPlan(planArray[6]); day.generateFakeData(3); mainWindow.getDays().add(day); //add "todays" data which includes fake raw data until 5pm and fake plan.
		//carry out calculations and call methods --> display everything on UI. Done.
		
		//all 7 days have raw data that needs processing // ie. updateDays = number of days that need updating in the LinkedList. the last "updateDays" worth of days
		//need to process new raw data :
		for(int i = 0; i < updateDays; i++)
			mainWindow.getDays().get(mainWindow.getDays().size()-1-i).processNewData();
		 
		this.mainWindow.getContentPane().removeAll();
		this.mainWindow.add(this.mainWindow.getSplashScreen());
	}
	
    /**
     * Renders the Loading Screen.
     */
    private void initUI() {
    	this.titlePanel = new JPanel() {
    		@Override
    		protected void paintComponent(Graphics g) {
    			super.paintComponent(g);
    			
    			this.setLayout(null);
    			this.setOpaque(false);
    			
    			Graphics2D g2 = (Graphics2D) g;
    			g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
    			
    			JLabel title = new JLabel("Trainr", JLabel.LEFT);
    			title.setFont(mainWindow.FONT_HELVETICA_NEUE_THIN.deriveFont(120.0f));
    			Dimension sizeTitle = title.getPreferredSize();
    			title.setBounds(0, 0, sizeTitle.width, sizeTitle.height);
    			title.setForeground(new Color(255,255,255,150));
    			
    			JLabel version = new JLabel("Beta Version 1.0", JLabel.LEFT);
    			version.setFont(mainWindow.FONT_HELVETICA_NEUE_THIN.deriveFont(25.0f));
    			Dimension sizeVersion = version.getPreferredSize();
    			version.setBounds((sizeTitle.width-sizeVersion.width)/2, sizeTitle.height, sizeVersion.width, sizeVersion.height);
    			version.setForeground(new Color(255,255,255,128));

    			this.setSize(sizeTitle.width, sizeTitle.height+sizeVersion.height);
    			this.setLocation((1480/2-getWidth())/2, (800-getHeight())/2);
    			
    			this.add(title);
    			this.add(version);
    		}
    	};
    	this.add(titlePanel);

    	devicesPanel = new JPanel() {
    		@Override
    		protected void paintComponent(Graphics g) {
    			super.paintComponent(g);
    			
    			this.setLayout(null);
    			this.setOpaque(false);
    			
    			Graphics2D g2 = (Graphics2D) g;
    			g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
    			
    			BufferedImage image = null;
				try {
					image = ImageIO.read(new File("UI/devices.png"));
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
    			this.setSize(image.getWidth(), image.getHeight());
    	    	this.setLocation((1480-getWidth())/2,(800-getHeight())/2);
    			g2.drawImage(image, 0, 0, image.getWidth(), image.getHeight(), null);
    		}
    	};
    	this.add(devicesPanel);
    	
    	JPanel loggingInPanel = new JPanel() {
    		@Override
    		protected void paintComponent(Graphics g) {
    			super.paintComponent(g);
    			
    			this.setLayout(null);
    			this.setOpaque(false);
    			
    			Graphics2D g2 = (Graphics2D) g;
    			g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
    			
    			JLabel label = new JLabel("Logging In...", JLabel.LEFT);
    			label.setFont(mainWindow.FONT_HELVETICA_NEUE_THIN.deriveFont(45.0f));
    			Dimension size = label.getPreferredSize();
    			label.setBounds(0, 0, size.width, size.height);
    			label.setForeground(new Color(255,255,255,150));

    			this.setSize(size.width, size.height);
    			this.setLocation(1480/2 + (1480/2-getWidth())/2, (800-getHeight())/2);
    			
    			this.add(label);
    		}
    	};
    	this.add(loggingInPanel);
	}
    
    /**
     * Gets the devices' images JPanel object.
     * @return
     */
    public JPanel getDevicesPanel() { return this.devicesPanel; }
    
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