package application.model;

import java.io.File;
import java.io.IOException;
import java.util.Scanner;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;

/**
 * Crossword class loads and stores crossword data. It uses basic String arrays
 * for both across and down clues, indexed by clue number. It provides methods for 
 * checking answers by letter or returning answers by letter.
 * @author Thomas Herron hgo525
 *
 */

public class Crossword {
	
	// MAX-SIZE sets the maximum clue count for EACH down and across list for a Crossword
	public static final int MAX_SIZE = 60;
	
	private int size;
	private String[] downQ;
	private String[] acrossQ;
	private String[] downA;
	private String[] acrossA;
	
	
	/**
	 * Crossword no arg constructor that defaults to MAX_SIZE. No overloaded constuctors
	 * are given because the Classifieds view and controller do not require different
	 * crossword sizes and this class will not be shared with other programs.
	 */
	public Crossword() {
		this.size=MAX_SIZE;
		this.downQ = new String[size];
		this.acrossQ = new String[size];
		this.acrossA = new String[size];
		this.downA = new String[size];
		
		
	} // end of constructor
	
	
	
	/**
	 * loadData class method creates and returns a new Crossword object using
	 * two csv files for its down and across questions. 
	 * @param downLink the file path for the down csv file
	 * @param acrossLink the file path for the across csv file
	 * @return the initialized Crossword object
	 */
	
	public static Crossword loadData(String downLink, String acrossLink) {
		Crossword ret = new Crossword();
		try {
			File acrossFile = new File(acrossLink);
			Scanner sc = new Scanner ( acrossFile );
			
			while (sc.hasNextLine()) {
				String inLine = sc.nextLine();
				String[] tokens = inLine.split( "," );	
				if (tokens != null && tokens.length == 3) {
					int i = Integer.parseInt(tokens[0]);
					ret.acrossQ[i] = tokens[1];
					ret.acrossA[i] = tokens[2];
				} else {
					System.out.println("Error: Unexpected number of tokens in " + acrossLink);
				}
			}
			sc.close();
		} catch( IOException e ) {
			e.printStackTrace();
		}
		
		try {
			File downFile = new File(downLink);
			Scanner sc = new Scanner ( downFile );
			
			while (sc.hasNextLine()) {
				String inLine = sc.nextLine();
				String[] tokens = inLine.split( "," );	
				if (tokens != null && tokens.length == 3) {
					int i = Integer.parseInt(tokens[0]);
					ret.downQ[i] = tokens[1];
					ret.downA[i] = tokens[2];
				} else {
					System.out.println("Error: Unexpected number of tokens in " + acrossLink);
				}
			}
			sc.close();
		} catch( IOException e ) {
			e.printStackTrace();
		}
				
		return ret;
	} // end of loadData method
	
	
	
	/**
	 * checkAcrossLetter method looks up the given clue and letter number and compares it to the letter 
	 * parameter, returning a boolean
	 * @param clue Across clue number
	 * @param num the index of the letter being checked, starting at 0
	 * @param letter user input letter to compare against
	 * @return boolean of the comparison
	 */
	
	public boolean checkAcrossLetter(int clue, int num, char letter) {
		boolean ret = false;
		if (Character.toLowerCase(this.acrossA[clue].charAt(num)) == Character.toLowerCase(letter)) {
			ret = true;
		}
		return ret;
	} // end of checkAcrossLetter method
	
	
	
	/**
	 * checkDownLetter method looks up the given clue and letter number and compares it to the letter 
	 * parameter, returning a boolean
	 * @param clue Down clue number
	 * @param num the index of the letter being checked, starting at 0
	 * @param letter user input letter to compare against
	 * @return boolean of the comparison
	 */
	
	public boolean checkDownLetter(int clue, int num, char letter) {
		boolean ret = false;
		if (Character.toLowerCase(this.downA[clue].charAt(num)) == Character.toLowerCase(letter)) {
			ret = true;
		}
		return ret;
	} // end of checkDownLetter method

	
	/**
	 * getAcrossLetter looks up the correct answer letter by Across
	 * clue number and letter number
	 * @param clue Across clue number
	 * @param num the index of the letter being returned, starting at 0
	 * @return the correct letter
	 */
	
	public char getAcrossLetter(int clue, int num) {
		char ret = Character.toUpperCase(this.acrossA[clue].charAt(num));
		return ret;
	}
	
	
	/**
	 * getDownLetter looks up the correct answer letter by Down
	 * clue number and letter number
	 * @param clue Down clue number
	 * @param num the index of the letter being returned, starting at 0
	 * @return the correct letter
	 */
	
	public char getDownLetter(int clue, int num) {
		char ret = Character.toUpperCase(this.downA[clue].charAt(num));
		return ret;
	}
	
	/**
	 * getCluesAsList method converts a clue-indexed String Array into an
	 * ObservableList object for use in ListViews
	 * @param clues the clue-indexed String array of clues
	 * @return the clues as a numbered ObservableList
	 */
	public ObservableList<String> getCluesAsList(String[] clues) {
		ObservableList<String> ret = FXCollections.observableArrayList();
		ret.removeAll(ret);
		for (int i = 0; i < MAX_SIZE; i++) {
			if (clues[i] != null) {
				String clue = (i) + " - " + clues[i];
				ret.add(clue);
			}
			
		} // end of for loop
		
		
		return ret;
	} // end of getCluesAsList method
	
		
	// Auto-generated getters and setters beyond this point
	
	/**
	 * getSize method returns the specified int variable
	 * @return the size of the Crossword's maximum clue capacity
	 */
	public int getSize() {
		return size;
	}

	/**
	 * setSize method sets the specified int variable. This is being included
	 * due to lab requirements, but using this on an intialized Crossword object could
	 * cause errors and is not recommended.
	 * @param size the size to set as the Crossword's maximum clue capacity
	 */
	public void setSize(int size) {
		this.size = size;
	}

	/**
	 * getDownQ method returns the specified String array
	 * @return the downQ String array of Down Questions
	 */
	public String[] getDownQ() {
		return downQ;
	}

	/**
	 * setDownQ method sets the specified String array
	 * @param downQ the String array of Down Questions to set
	 */
	public void setDownQ(String[] downQ) {
		this.downQ = downQ;
	}

	/**
	 * getAcrossQ method returns the specified String array
	 * @return the acrossQ String array of Across Questions
	 */
	public String[] getAcrossQ() {
		return acrossQ;
	}

	/**
	 * setAcrossQ method sets the specified String array
	 * @param acrossQ the String array of Across Questions to set
	 */
	public void setAcrossQ(String[] acrossQ) {
		this.acrossQ = acrossQ;
	}

	/**
	 * getDownA method returns the specified String array
	 * @return the downA String array of Down Answers
	 */
	public String[] getDownA() {
		return downA;
	}

	/**
	 * setDownA method sets the specified String array
	 * @param downA the String array of Down Answers to set
	 */
	public void setDownA(String[] downA) {
		this.downA = downA;
	}

	/**
	 * getAcrossA method returns the specified String array
	 * @return the acrossA String array of Across Answers
	 */
	public String[] getAcrossA() {
		return acrossA;
	}

	/**
	 * setAcrossA method sets the specified String array
	 * @param acrossA the String array of Across Answers to set
	 */
	public void setAcrossA(String[] acrossA) {
		this.acrossA = acrossA;
	}

	/**
	 * getMazSize returns the specified integer constant
	 * @return the maxSize the maximum question capacity
	 */
	public static int getMaxSize() {
		return MAX_SIZE;
	}
	
	
	
}
