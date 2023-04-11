package application.model;

import java.io.FileNotFoundException;

import javafx.stage.Stage;

/**
 * 
 * @author Roderick Simms (aak759)
 * UTSA CS 3443 - Lab 3
 * Fall 2021
 */
public abstract class Person {
	public String name;

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
	public void start(Stage stage) throws FileNotFoundException {
		// TODO Auto-generated method stub
		
	}
	

}