package application.model;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

/**
 * The Classifieds class stores an ArrayList of Advertisement objects
 * and loads Advertisement objects from a file.
 * @author Thomas Herron hgo525
 *
 */

public class Classifieds {

	private ArrayList<Advertisement> ads;
	
	/**
	 * Classifieds no arg constructor initializes
	 * the ArrayList
	 */
	
	public Classifieds() {
		this.ads = new ArrayList<Advertisement>();
		
	} // end of constructor method
	
	
	/**
	 * loadAds method loads ads found at the adLink
	 * parameter file into the Classifieds object's
	 * ads ArrayList
	 * @param adLink the path to the ads csv file
	 * 
	 */
	
	public void loadAds(String adLink) {
		
		try {
			File adFile = new File(adLink);
			Scanner sc = new Scanner ( adFile );
			
			while (sc.hasNextLine()) {
				String inLine = sc.nextLine();
				String[] tokens = inLine.split( "," );	
				if (tokens != null && tokens.length == 5) {
					boolean full = false;
					if (tokens[1].equalsIgnoreCase("Full")) {
						full = true;
					}
					Advertisement temp = new Advertisement(tokens[0], full, tokens[2], tokens[3], tokens[4]);
					this.ads.add(temp);
				} else {
					System.out.println("Error: Unexpected number of tokens in " + adLink);
				}
			}
			sc.close();
		} catch( IOException e ) {
			e.printStackTrace();
		}
		
	} // end of loadAds method

	// Auto-generated getters and setters beyond this point
	
	/**
	 * getAds method returns the specified ArrayList variable
	 * @return the ads Advertisement ArrayList
	 */
	public ArrayList<Advertisement> getAds() {
		return ads;
	}


	/**
	 * setAds method sets the specified ArrayList variable
	 * @param ads the Advertisement ArrayList to set
	 */
	public void setAds(ArrayList<Advertisement> ads) {
		this.ads = ads;
	}
	
	
	
	
}
