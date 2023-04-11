import java.util.ArrayList;
/**
 * @author Roderick Simms (aak759)
 * UTSA CS 3443 - Lab 3
 * Fall 2021
 */
public class Avenger extends Person {
	public String alias;
	public String gender;
	public String height;
	public double weight;
	public String currLocation;
	public boolean powers;
	
	public Avenger(String name, String alias, String gender, String height, String weight, String powers, String currLocation) {
		super(name);
		this.alias = alias;
		this.gender = gender;
		this.height = height;
		/**
		 * parse double to be used as a string parameter for loadAvenger
		 */
		this.weight = Double.parseDouble(weight);
		this.currLocation = currLocation;
		/**
		 * set F = false, N = false, T = true
		 */
		this.powers = Boolean.parseBoolean(powers);
	}

	@Override
	public String toString() {
		return "- " + name + " (" + alias + ") \nSpecial Abilities: " + powers + "\n" + gender + ", " + height + ", " + weight
				+ "\nCurrent Location: " + currLocation +"\n\n";
	}
	/**
	 * getters/setters
	 */
	public String getAlias() {
		return alias;
	}
	public void setAlias(String alias) {
		this.alias = alias;
	}
	public String getGender() {
		return gender;
	}
	public void setGender(String gender) {
		this.gender = gender;
	}
	public String getHeight() {
		return height;
	}
	public void setHeight(String height) {
		this.height = height;
	}
	public double getWeight() {
		return weight;
	}
	public void setWeight(double weight) {
		this.weight = weight;
	}
	public String getCurrLocation() {
		return currLocation;
	}
	public void setCurrLocation(String currLocation) {
		this.currLocation = currLocation;
	}
	public boolean isPowers() {
		return powers;
	}
	public void setPowers(boolean powers) {
		this.powers = powers;
	}
	/**
	 * methods to pull members from array list and add to Team
	 * @param avengers
	 */
	public void setList(ArrayList<Person> avengers) {
		// TODO Auto-generated method stub
		
	}

	
	

}
