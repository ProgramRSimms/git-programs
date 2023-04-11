/*AvengerTask.java is a Java class containing:
*
	 * a timer to countdown 10 seconds per thread
	 * updates date/time stamp
	 * randomly decides which avenger will change location using 1 in 10 chance: 1 = randomly select location
	 * seed = id of ea avenger
	 * updates location (lat/long)
	 * updates icon on map
 *  
 * @author Roderick Simms (aak759)
 * UTSA CS 3443 - Lab 6
 * Fall 2021
 * */

package application.model;

import java.net.URL;
import java.util.ArrayList;
import java.util.ResourceBundle;
import java.util.Timer;
import java.util.TimerTask;

import javax.swing.JLabel;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import javafx.animation.Animation;
import javafx.animation.Timeline;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.text.Text;



public class AvengerTask extends Thread{
	@FXML
    private Text Date;
	
	double lng, lat;
	String date;
	public ArrayList<Person> avengers = new ArrayList<Person>();
	AvengerDot marker = new AvengerDot();
	//File filename;
	//AvengerTask runnable = new AvengerTask();
	Thread thread = new Thread();
	//thread.setDaemon(true);
	//thread.start();
	
	/* public class Date implements Initializable{
	    int i = 0;
	
	    @Override
	    public void initialize (URL url, ResourceBundle resourceBundle) {
		    Date.setText(String.valueOf(i));
		    Timeline timeline = new Timeline(new KeyFrame (Duration.seconds(1), e ->{
		    	i++;
		    	text.setText(String.value0f(i));
		    }));
		    timeline.setCycleCount(Animation.INDEFINITE);
		    timeline.play();
	    }

    }*/
	
	/*
	 * Thread run1 to change random positions on map and run2 to change date and time
	 */
    @Override    
    public void run(){

			for (int i = 1; i <= 5; i++ ) {
				
				//System.out.println(i);//****TEST IF WORKING
				lng = (Math.random() * 360.0) - 180.0;
                lat = (Math.random() * 180.0) - 90.0;
                marker.setPosition(lat, lng);
              
				//System.out.printf("%f ,%f\n",lat, lng);//*****TEST IF RANDOM POSITIONS CHANGE
		
				try {
					Thread.sleep(1000);
				}catch (InterruptedException e) {
				}
			}
			thread.start();
    }
    public void run2() {
    	
		//JLabel lblThetime = new JLabel();
	    Timer timer = new Timer();
	    
	    timer.scheduleAtFixedRate(new TimerTask() {
	    	
	        @Override
	        public void run() {
	           
	           SimpleDateFormat timeDate = new SimpleDateFormat("MM-dd-yyyy HH:mm:ss");
	           try {
				java.util.Date temp = timeDate.parse("Oct 11, 2021 15:23:00");
			} catch (ParseException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
	           Date.setText(date);
	           //lblThetime.setText(date);
	        }
	    }, 1000, 1000);
	    //System.out.println(date);//*****TEST DATE OUTPUT
	    thread.start();
    }

	public class AvengerDot {

		public void setPosition(double lat, double lng) {
			// TODO Auto-generated method stub
			
		}
		
    }
	
	
	

}

/*
 package application.model;

import java.util.Timer;
import java.util.TimerTask;

import javax.swing.JLabel;

import application.controller.MainController;

public class AvengerTask extends MainController implements Runnable{
	/*
ThreadHelper threadHelper = new ThreadHelper(holder, puzzleSurface);
Thread thread = new Thread(threadHelper);
thread.start();
	 */
/*
	double lng, lat;
	AvengerDot marker = new AvengerDot();
	AvengerTask runnable = new AvengerTask();
	Thread thread = new Thread(runnable);
	//thread.start();
    
	  
    @Override    
    public void run(){

			for (int i = 1; i <= 5; i++ ) {
				
				//System.out.println(i);//****TEST IF WORKING
				lng = (Math.random() * 360.0) - 180.0;
                lat = (Math.random() * 180.0) - 90.0;
                marker.setPosition(lat, lng);
              
				//System.out.printf("%f ,%f\n",lat, lng);//*****TEST IF RANDOM POSITIONS CHANGE
		
				try {
					Thread.sleep(10000);
				}catch (InterruptedException e) {
				}
			}
			thread.start();
    }
    public void run2() {
	    String date = null;
		JLabel lblThetime = new JLabel(date);
	    Timer timer = new Timer();
	    
	    timer.scheduleAtFixedRate(new TimerTask() {
	        @Override
	        public void run() {
	           String date = new java.text.SimpleDateFormat("HH:mm:ss").format(new java.util.Date() );
	
	           lblThetime.setText(date);
	        }
	    }, 1000, 1000);
	    //System.out.println(date);//*****TEST DATE OUTPUT
	    thread.start();
    }

	public class AvengerDot {

		public void setPosition(double lat, double lng) {
			// TODO Auto-generated method stub
			
		}
		
    }



}
 */

