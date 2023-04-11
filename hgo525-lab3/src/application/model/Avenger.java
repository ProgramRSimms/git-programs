package application.model;

import java.io.File;
import java.io.IOException;
import java.util.Scanner;

/** 
 * The Avenger class represents an ficitonal Avenger hero from comics or movies.
 *  It extends the Person class, and stores biographical information including
 *  alias, gender, height, weight, powered status, and current location.
 * @author Thomas Herron hgo525
 *
 */
public class Avenger extends Person {

	private String alias;
	private String gender;
	private String height;
	private double weight;
	private boolean powered;
	private String curLoc;
	
	
	
	/**
	 * Avenger constructor, requiring name, alias, gender, height (feet and inches), weight, current location, and powered status of the person.
	 * Calls the Person super constructor. No overloaded constructors are provided
	 * because they will not be used by the code in Lab2.java.
	 * 
	 * @param name the name of the Avenger
	 * @param alias the alias of the Avenger
	 * @param gender the gender of the Avenger
	 * @param foot the foot component of the Avenger's height
	 * @param inch the inch component of the Avenger's height
	 * @param weight the weight of the Avenger as a double
	 * @param powered the powered status of the Avenger as a boolean
	 * @param curLoc the current location of the Avenger
	 * 
	 */
	
	public Avenger ( String name, String alias, String gender,  int foot, int inch, double weight, boolean powered, String curLoc) {
		super(name);
		this.alias=alias;
		this.gender=gender;
		this.height=foot+"'"+inch+"\"";
		this.weight=weight;
		this.powered=powered;
		this.curLoc=curLoc;

		
	} // end of constructor
	
	/**
	 * Overloaded Avenger constructor, requiring name, alias, and current location only.
	 * This version exists because these are the bare minimums in Lab3.
	 * Calls the Person super constructor. No overloaded constructors are provided
	 * because they will not be used by the code in Lab2.java.
	 * 
	 * @param name the name of the Avenger
	 * @param alias the alias of the Avenger
	 * @param curLoc the current location of the Avenger
	 * 
	 */
	
	
	public Avenger ( String name, String alias, String curLoc) {
		super(name);
		this.alias=alias;
		this.gender="Unknown";
		this.height="Unknown";
		this.weight=0.0;
		this.powered=false;
		this.curLoc=curLoc;
		
	} // end of overloaded constructor

	/**
	 * toString method which returns a String representation of the contents of the object
	 * and their values
	 * 
	 * @return ret the String representation of the Avenger
	 */
	
	public String toString() {
		String pow;
		if (this.isPowered()) {
			pow="Yes";			
		} else {
			pow="No";
		}
		
		String ret = " - " + super.toString() + " (" + this.getAlias() + ")\n";
		ret += "   Special abilities: " + pow + "\n";
		ret += "   " + this.getGender() + ", " + this.getHeight() + ", " + this.getWeight() + "lbs\n";
		ret += "   Current location: " + this.getCurLoc() + "\n\n";
		
		return ret;
	} // end of toString method
	
	/**
	 * findAvenger method which searches the data.csv file for a line matching the provided
	 * name and loads that line into an Avenger object and returns it.
	 * 
	 * 
	 * @param name the name of the Avenger to search for
	 * @return ret the matching Avenger from the data file
	 */
	
	public static Avenger findAvenger (String name) {
		
		Avenger ret = new Avenger("Unknown", "Unknown", "Unknown");;
		try {
			File inFile = new File( "data/data.csv" );
			Scanner sc = new Scanner ( inFile );
			
			while (sc.hasNextLine()) {

				String inLine = sc.nextLine();
			
				String[] tokens = inLine.split( "," );

				if (tokens != null && tokens.length == 8) {
					if (name.equals(tokens[0])) {
										
						boolean pow;
						if ( tokens[6].equals("T")) {
							pow = true;
						} else {
							pow = false;
						}
						ret = new Avenger(tokens[0], tokens[1], tokens[2], Integer.parseInt(tokens[3]), Integer.parseInt(tokens[4]), Double.parseDouble(tokens[5]), pow, tokens[7]);
					} // end of name.equals if
				} // end of tokens == 8 if
			} // end while loop
			
			sc.close();
		} catch( IOException e ) {
			e.printStackTrace();
		}
		

		return ret;
	} // end of findAvenger method
	
	
	
	
	// Auto-generated getters and setters beyond this point

	/**
	 * "Getter" method which returns the object's variable Alias
	 * @return the alias of the Avenger
	 */
	public String getAlias() {
		return alias;
	}


	/**
	 * "Setter" method which assigns the provided parameter alias to the object's
	 * own alias variable
	 * @param alias the alias to set
	 */
	public void setAlias(String alias) {
		this.alias = alias;
	}


	/**
	 * "Getter" method which returns the object's variable gender
	 * @return the gender of the Avenger
	 */
	public String getGender() {
		return gender;
	}


	/**
	 * "Setter" method which assigns the provided parameter gender to the object's
	 * own gender variable
	 * @param gender the gender to set
	 */
	public void setGender(String gender) {
		this.gender = gender;
	}


	/**
	 * "Getter" method which returns the object's variable height
	 * @return the height of the Avenger as a string X'Y"
	 */
	public String getHeight() {
		return height;
	}


	/**
	 * "Setter" method which assigns the provided parameter height to the object's
	 * own height variable
	 * @param height the height to set as a string formatted X'Y"
	 */
	public void setHeight(String height) {
		this.height = height;
	}


	/**
	 * "Getter" method which returns the object's variable weight
	 * @return the weight of the Avenger in lbs
	 */
	public double getWeight() {
		return weight;
	}


	/**
	 * "Setter" method which assigns the provided parameter weight to the object's
	 * own weight variable
	 * @param weight the weight to set in lbs
	 */
	public void setWeight(double weight) {
		this.weight = weight;
	}


	/**
	 * "Getter" method which returns the object's variable curLoc
	 * @return the current location of the Avenger
	 */
	public String getCurLoc() {
		return curLoc;
	}


	/**
	 * "Setter" method which assigns the provided parameter curLoc to the object's
	 * own curLoc variable
	 * @param curLoc the current location to set
	 */
	public void setCurLoc(String curLoc) {
		this.curLoc = curLoc;
	}


	/**
	 * "Getter" method which returns the object's variable powered status
	 * @return the powered status of the Avenger as a boolean (true = powered, false = no superhuman powers)
	 */
	public boolean isPowered() {
		return powered;
	}


	/**
	 * "Setter" method which assigns the provided parameter powered to the object's
	 * own powered boolean
	 * @param powered the powered status to set
	 */
	public void setPowered(boolean powered) {
		this.powered = powered;
	}
	
		
} // end of class
