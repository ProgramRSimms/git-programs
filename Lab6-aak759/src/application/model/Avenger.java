/*Avenger.java is a Java class containing:
 *  
 * @author Roderick Simms (aak759)
 * UTSA CS 3443 - Lab 6
 * Fall 2021
 * */

package application.model;


/*
 *  class Avenger extending class Person 
 * @author Roderick Simms (aak759)
 * UTSA CS 3443 - Lab 6
 * Fall 2021
 */
public class Avenger extends Person { 
    // declaring variables as instructed in question
    private String alias,gender,height;
    double weight;
    boolean offPlanet;
    int latitude, longitude;

    // constructor of Avenger class 
   /* public Avenger(String name,String alias,String gender,String height,String weight,String offPlanet,String latitude, String longitude) {
        super(name);
        this.alias = alias;
        this.gender = gender;
        this.height = height;
        this.weight = Double.parseDouble(weight);
        this.offPlanet = offPlanet.equals("F")?false:true;
        //this.currentLocation = currentLocation;
        this.latitude = Integer.parseInt(latitude);
        this.longitude = Integer.parseInt(longitude);

    }*/
	public Avenger(String name, String alias, String gender, String height, double weight, boolean offPlanet, int latitude, int longitude) {
		super(name);
		this.alias = alias;
		this.gender = gender;
		this.height = height;
		this.weight = weight;
		this.offPlanet = offPlanet;
		this.latitude = latitude;
		this.longitude = longitude;
	}
  
   

	@Override
	public String toString() {
		return "Avenger [alias=" + alias + ", gender=" + gender + ", height=" + height + ", weight=" + weight
				+ ", offPlanet=" + offPlanet + ", latitude=" + latitude + ", longitude=" + longitude + "]";
	}

	/**
	 * @return the alias
	 */
	public String getAlias() {
		return alias;
	}

	/**
	 * @param alias the alias to set
	 */
	public void setAlias(String alias) {
		this.alias = alias;
	}

	/**
	 * @return the gender
	 */
	public String getGender() {
		return gender;
	}

	/**
	 * @param gender the gender to set
	 */
	public void setGender(String gender) {
		this.gender = gender;
	}

	/**
	 * @return the height
	 */
	public String getHeight() {
		return height;
	}

	/**
	 * @param height the height to set
	 */
	public void setHeight(String height) {
		this.height = height;
	}

	/**
	 * @return the weight
	 */
	public double getWeight() {
		return weight;
	}

	/**
	 * @param weight the weight to set
	 */
	public void setWeight(double weight) {
		this.weight = weight;
	}

	/**
	 * @return the offPlanet
	 */
	public boolean isOffPlanet() {
		return offPlanet;
	}

	/**
	 * @param offPlanet the offPlanet to set
	 */
	public void setOffPlanet(boolean offPlanet) {
		this.offPlanet = offPlanet;
	}

	/**
	 * @return the latitude
	 */
	public int getLatitude() {
		return latitude;
	}

	/**
	 * @param latitude the latitude to set
	 */
	public void setLatitude(int latitude) {
		this.latitude = latitude;
	}

	/**
	 * @return the longitude
	 */
	public int getLongitude() {
		return longitude;
	}

	/**
	 * @param longitude the longitude to set
	 */
	public void setLongitude(int longitude) {
		this.longitude = longitude;
	}
	
}