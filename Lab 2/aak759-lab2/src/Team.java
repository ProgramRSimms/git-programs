import java.util.*;
import java.io.*;
/**
 * @author Roderick Simms (aak759)
 * UTSA CS 3443 - Lab 2
 * Fall 2021
 */

public class Team {
	public String name;
	public ArrayList<Person> avengers = new ArrayList<Person>();
	/**
	 * Constructor for Team
	 * @param name
	 */
	public Team(String teamName) {
		this.name = teamName;
		//this.avengers = avenger;
	}
	/**
	 * methods to pull members from array list and add to Team
	 * @param avengers
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
			File file = new File (filename);
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
	        		String name = tokens[0];
	        		String alias = tokens[1];
	        		String gender = tokens[2];
	        		String height = (tokens[3] + "'" + tokens[4] + "\"");
	        		String weight = tokens[5];
	        		/**
	        		 * powers yes or no
	        		 */
	        		String powers;
	        		if (tokens[6]== "N" || tokens[6] == "F") {
	        			powers = "No";
	        		}
	        		else{
	        			powers = "Yes";
	        		}
	        		String currLocation = tokens[7];
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
	        		Avenger avenger = new Avenger (name, alias, gender, height, weight, powers, currLocation);
	        	add(avenger);
        		}
	        			
        	}  
	        
	        inputFile.close();
		 }catch(IOException e) {  //handling the exception 
         System.out.println(e);
         System.out.print("******Check for error in File IO******\n");
		 }
	}
	//private void close(Scanner inputFile) {
		// TODO Auto-generated method stub
		
	//}
	
	@Override
	public String toString() {
		return "Team " + name + ":\n\n" + avengers;
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
	
	
}
	