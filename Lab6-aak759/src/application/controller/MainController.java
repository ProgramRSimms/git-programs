/*MainController.java is a Java class containing:
file io element as well as builds the avenger from the csv
 *  
 * @author Roderick Simms (aak759)
 * UTSA CS 3443 - Lab 6
 * Fall 2021
 * */
package application.controller;
/**
 * @author Roderick Simms (aak759)
 * UTSA CS 3443 - Lab 6
 * Fall 2021
 */

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import application.model.Avenger;
import application.model.AvengerTask;
import application.model.Person;


public class MainController extends AvengerTask{

	/*
	 * Class Variables
	 */
	String name, alias, gender, height;
	double weight;
	boolean offPlanet;
	int latitude, longitude;
	public ArrayList<Person> avengers = new ArrayList<Person>();
	
	public void setList(ArrayList<Person> avenger) {
		this.avengers = new ArrayList<Person>(avenger);
	}
	public void add(Person avenger) {
		avengers.add(avenger);
	}
	public void loadAvenger(String filename){
		/**
		 * use setList method to pull members from array list
		 */
	
    	setList(this.avengers);
		try{  
		    //input file
			
			//File file = new File ("./data/data.csv");
			//Scanner inputFile = new Scanner (file);
			BufferedReader file = new BufferedReader(new FileReader(filename));
		    //while (inputFile.hasNextLine()){ 
			while (file.readLine() != null){
				String line = file.readLine();
				
		    	/*System.out.print("--\n");//test scanner***********/
		    	System.out.println(line);//*****TEST IO
		    	////		tokens		0				1		    2  3 4	5  6  7  8
		    	////String test = "Steve Rogers,Captain America,male,6,2,240,F,140,98";
		    	/*/String [] tokens = inputFile.nextLine().split(",");*/
		    	String tokens[] = line.split(",");
				
		    	//(tokens);
		    	//if(tokens != null && tokens.length == 8) {
		    		/**
		    		 * assign variables to csv input
		    		 */
		    		name = tokens[0];
		    		alias = tokens[1];
		    		gender = tokens[2];
		    		height = Integer.parseInt(tokens[3]) + "'" + Integer.parseInt(tokens[4]) + "\"";
		    		weight = Double.parseDouble(tokens[5]);
		    		offPlanet = false;//initialize default value
		    		if (tokens[6] == "F"){
		    			 offPlanet = false;
		    		}
		    		else{
		    			offPlanet = true;
		    		}
		    		latitude = Integer.parseInt(tokens[7]);
		    		longitude = Integer.parseInt(tokens[8]);
		    		Avenger avenger = new Avenger(name, alias, gender, height, weight, offPlanet, latitude, longitude); // passing values of name,alias,gender,height,weight,specialAbilities and current location to create an object of Avenger class.  
		            add(avenger);// adding avenger to the list

		    	}
		   //}
			file.close();
		    //inputFile.close();
		 }catch(IOException e) {  //handling the exception 
        System.out.println(e);
        System.out.print("******Check for error in File IO******\n");
		 }
	}
	
}