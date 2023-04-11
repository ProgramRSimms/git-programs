
public abstract class Person {
	public String name;
/**
 * 
 * @author Roderick Simms (aak759)
 * UTSA CS 3443 - Lab 2
 * Fall 2021
 */
	public Person(String name) {
		// TODO Auto-generated constructor stub
		this.name = name;
	}
	public String toString() {
		return name;//reformat
	}

	/**
	 * getters/setters
	 */
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	

}
