package application.controller;

import java.io.*;
import java.util.*;
import application.model.Avenger;
import application.model.Person;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;

public class MainController implements EventHandler<ActionEvent> {	
	//System.out.println("Test if getting to MainController class\n");
		@FXML Label caLabel;
		@FXML Label ironmanLabel;
		@FXML Label hulkLabel;
		@FXML Label bwLabel;
		@FXML Button captainAmerica;
		@FXML Button ironMan;
		@FXML Button blackWidow;
		@FXML Button hulk;
		/*@Override public void start(Stage stage) {
         // load the image
         Image image = new Image("flower.png");

         // simple displays ImageView the image as is
         ImageView iv1 = new ImageView();
         iv1.setImage(image);*/
		Image image = new Image("/AppView1.png");
		ImageView png = new ImageView(image);
		//png.setImage(image);

		/*public MainController (String name, String alias, String currLocation) {
		super(name, alias, currLocation);
		// TODO Auto-generated constructor stub
		}*/
		public ArrayList<Person> avengers = new ArrayList<Person>();
		/**
		 * methods to pull members from array list and add to Team
		 * @param avengers
		 * @return 
		 */
		public void setList(ArrayList<Person> avenger) {
			this.avengers = new ArrayList<Person>(avenger);
		}
		public void add(Person avenger) {
			avengers.add(avenger);
		}
		public void loadAvengers(String filename){
			/**
			 * use setList method to pull members from array list
			 */
			setList(this.avengers);
			try{  
		        //may throw exception
				File file = new File ("/data/data.csv");
				Scanner inputFile = new Scanner (file);
				/**
				 * set delimiter for csv
				*/
	        	//inputFile.useDelimiter(",");
		        while (inputFile.hasNextLine()) {
		        	//System.out.print("--\n");//test scanner***********
		        	
		        	//String test = "Steve Rogers,Captain America,male,6,2,240,N,Pentagon";
		        	String [] tokens = inputFile.nextLine().split(",");
		        	
		        	//(tokens);
		        	if(tokens != null && tokens.length == 8) {
		        		/**
		        		 * assign variables to csv input
		        		 */
		        		String name = tokens[1];
		        		String alias = tokens[2];
		        		String currLocation = tokens[8];
		        		/**
		        		 * Test IO
		        		 */
		        		/*
		        		System.out.println(test);
		        		System.out.println(name);
		        		System.out.println(alias);
		        		System.out.println(gender);
		        		System.out.println(height);
		        		System.out.println(weight);
		        		System.out.println(powers);
		        		*/
		        		/**
		        		 * add avenger member to team
		        		 */
		        		Avenger avenger = new Avenger (name, alias, currLocation);
		        	add(avenger);
	        		}
		        			
	        	}  
		        
		        inputFile.close();
			 }catch(IOException e) {  //handling the exception 
	         System.out.println(e);
	         System.out.print("******Check for error in File IO******\n");
			 }
		}


		@Override
		public String toString() {
			return "MainController [avengers=" + avengers + "]";
		}
		/**
		 * getter/setters
		 {*/

		public String getName() {
			return name;
		}
		/**
		 * @param name the name to set
		 */
		public void setName(String name) {
			this.name = name;
		}
		/**
		 * @return the avengers
		 */
		public ArrayList<Person> getAvengers() {
			return avengers;
		}
		/**
		 * @param avengers the avengers to set
		 */
		public void setAvengers(ArrayList<Person> avengers) {
			this.avengers = avengers;
		}
		@Override
		public void handle(ActionEvent event) {
			// TODO Auto-generated method stub
			
		}
	
}
/*Steve Rogers,Captain America,male,6,2,240,N,Pentagon
Bruce Banner,Hulk,male,8,2,1040,T,Argentina
Thor Odinson,God of Thunder,male,6,6,165,T,Asgard
Natasha Romanoff,Black Widow,female,5,7,130,N,Ukraine
Stephen Strange,Doctor Strange,male,6,2,180,T,Kamar-Taj
Tony Stark,Iron Man,male,6,6,220,F,Stark Tower NYC
T'Challa,Black Panther,male,6,0,200,N,Wakanda
Clint Barton,Hawkeye,male,6,3,230,N,NYC
Peter Parker,Spiderman,male,5,10,160,T,NYC
Carol Danvers,Captain Marvel,female,5,11,164.91,T,NYC*/