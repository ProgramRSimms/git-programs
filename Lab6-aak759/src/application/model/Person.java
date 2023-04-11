/*Person.java is a Java class containing:
 *  
 * @author Roderick Simms (aak759)
 * UTSA CS 3443 - Lab 6
 * Fall 2021
 * */

package application.model;

//import java.io.File;
//import java.io.IOException;
//import java.util.Scanner;

public abstract class Person {   // creating abstract class

    public String name;

    Person(String name){  // constructor of Person class
        this.name = name;
    }
    /**
	 * getters/setters
	 */
    public void setName(String name) { // setter for name
        this.name = name;
    }

    public  String getName(){ // getter for name
        return this.name;
    }
    @Override
    public  String toString(){  //toString method it will return name of the person.
        return getName() ;
    }
    
}