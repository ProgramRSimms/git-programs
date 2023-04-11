package application.model;

/**
 * The Person class represents a person, real or fictitious.
 * The Person class stores the name of the person, and is 
 * used modularly in multiple sub-classes
 * 
 * @author Thomas Herron hgo525
 *
 */
public abstract class Person {

	private String name;

	
	/**
	 * Person constructor, requiring name of the person. No overloaded constructors are provided
	 * because they will not be used by the code in Lab2.java.
	 * 
	 * @param name the name of the person
	 */
	
	public Person(String name) {
		this.name = name;
		
		
	} // end of constructor
	
	/**
	 * toString method which returns a String representation of the contents of the object
	 * and their values
	 * 
	 * @return ret the String representation of the Person
	 */
	
	public String toString() {
		String ret = this.getName();
		return ret;
	} // end of toString

	// auto-generated getters and setters beyond this point
	
	/**
	 * "Getter" method which returns the object's variable name
	 * 
	 * @return name the name of the person
	 */
	public String getName() {
		return name;
	}

	/**
	 * "Setter" method which assigns the provided parameter name to the object's
	 * own name variable
	 * 
	 * @param name the name to set
	 */
	public void setName(String name) {
		this.name = name;
	}


} // end of class
