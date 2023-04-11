package application.model;
import java.util.*;
/**
 * @author Roderick Simms (aak759)
 * UTSA CS 3443 - Lab 3
 * Fall 2021
 */
public class Avenger extends Person {
	public ArrayList<Person> getAvengers() {
		return avengers;
	}

	public void setAvengers(ArrayList<Person> avengers) {
		this.avengers = avengers;
	}

	public String alias;
	public String currLocation;
	public ArrayList<Person> avengers = new ArrayList<Person>();
	
	public Avenger(String name, String alias, String currLocation) {
		super(name);
		this.alias = alias;
		this.currLocation = currLocation;
	}

	
  
   @Override
	public String toString() {
		return "Avenger [alias=" + alias + ", currLocation=" + currLocation + ", name=" + name + ", toString()="
				+ super.toString() + ", getName()=" + getName() + ", getClass()=" + getClass() + ", hashCode()="
				+ hashCode() + "]";
	}        
	
	@Override
	public String getName() {
		// TODO Auto-generated method stub
		return super.getName();
	}

	@Override
	public void setName(String name) {
		// TODO Auto-generated method stub
		super.setName(name);
	}
	public String getAlias() {
		return alias;
	}

	public void setAlias(String alias) {
		this.alias = alias;
	}

	public String getCurrLocation() {
		return currLocation;
	}

	public void setCurrLocation(String currLocation) {
		this.currLocation = currLocation;
	}
	

	


	

	
	

}
