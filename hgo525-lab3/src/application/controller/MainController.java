package application.controller;

import application.model.Avenger;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.scene.control.Label;

/**
 * MainController class handles ActionEvents for the Main FMXL view
 * It uses buttons and labels
 * @author Thomas Herron hgo525
 *
 */

public class MainController implements EventHandler<ActionEvent> {

	@FXML
	private Label labelBP;
	@FXML
	private Label labelBW;
	@FXML
	private Label labelIM;
	@FXML
	private Label labelThor;
	@FXML
	private Label labelHulk;
	@FXML
	private Label labelCap;
	@FXML
	private Label labelHawkEye;
	@FXML
	private Label labelSHIELD;
	
	/**
	 * clearAll method resets all labels to either be empty or a collapsed acronym.
	 * It is intended to be called at the beginning of all other methods prior to 
	 * displaying new text in a label.
	 */
	
	public void clearAll () {
		labelBP.setText("");
		labelBW.setText("");
		labelIM.setText("");
		labelThor.setText("");
		labelHulk.setText("");
		labelCap.setText("");
		labelHawkEye.setText("");
		labelSHIELD.setText("S.H.I.E.L.D.");
		
	} // end of ClearAll method
	
	/**
	 * handle method activates when the SHIELD logo is clicked and 
	 * expands the acronym to its full name
	 * @param event a button click
	 * 
	 */
	public void handle (ActionEvent event) {
		clearAll();
		labelSHIELD.setText("Strategic Homeland Intervention Enforcement and Logistics Division");
		
			
		
	} // end of handle method
	
	/**
	 * handleBP method activates when Black Panther
	 * is clicked and display's the avenger's information
	 * in their associated label
	 * @param event a button click
	 * 
	 */
	public void handleBP (ActionEvent event) {
		clearAll();
		String searchName = "T'Challa";
		Avenger curAvenger = Avenger.findAvenger(searchName);
		String disp = curAvenger.getName() +"\n" + curAvenger.getAlias() + "\nCurrently in " + curAvenger.getCurLoc();
		labelBP.setText(disp);
		
	} // end of handleBP method
	
	/**
	 * handleBW method activates when Black Widow
	 * is clicked and display's the avenger's information
	 * in their associated label
	 * @param event a button click
	 * 
	 */
	public void handleBW (ActionEvent event) {
		clearAll();
		String searchName = "Natasha Romanoff";
		Avenger curAvenger = Avenger.findAvenger(searchName);
		String disp = curAvenger.getName() +"\n" + curAvenger.getAlias() + "\nCurrently in " + curAvenger.getCurLoc();
		labelBW.setText(disp);
		
	} // end of handleBW method
	
	/**
	 * handleCap method activates when Captain America
	 * is clicked and display's the avenger's information
	 * in their associated label
	 * @param event a button click
	 * 
	 */
	public void handleCap (ActionEvent event) {
		clearAll();
		String searchName = "Steve Rogers";
		Avenger curAvenger = Avenger.findAvenger(searchName);
		String disp = curAvenger.getName() +"\n" + curAvenger.getAlias() + "\nCurrently in " + curAvenger.getCurLoc();
		labelCap.setText(disp);
		
	} // end of handleCap method
	
	/**
	 * handleHulk method activates when Hulk
	 * is clicked and display's the avenger's information
	 * in their associated label
	 * @param event a button click
	 * 
	 */
	public void handleHulk (ActionEvent event) {
		clearAll();
		String searchName = "Bruce Banner";
		Avenger curAvenger = Avenger.findAvenger(searchName);
		String disp = curAvenger.getName() +"\n" + curAvenger.getAlias() + "\nCurrently in " + curAvenger.getCurLoc();
		labelHulk.setText(disp);
		
	} // end of handleHulk method
	
	/**
	 * handleThor method activates when Thor
	 * is clicked and display's the avenger's information
	 * in their associated label
	 * @param event a button click
	 * 
	 */
	public void handleThor (ActionEvent event) {
		clearAll();
		String searchName = "Thor Odinson";
		Avenger curAvenger = Avenger.findAvenger(searchName);
		String disp = curAvenger.getName() +"\n" + curAvenger.getAlias() + "\nCurrently in " + curAvenger.getCurLoc();
		labelThor.setText(disp);
		
	} // end of handleThor method
	
	/**
	 * handleHawkEye method activates when Hawk Eye
	 * is clicked and display's the avenger's information
	 * in their associated label
	 * @param event a button click
	 * 
	 */
	public void handleHawkEye (ActionEvent event) {
		clearAll();
		String searchName = "Clint Barton";
		Avenger curAvenger = Avenger.findAvenger(searchName);
		String disp = curAvenger.getName() +"\n" + curAvenger.getAlias() + "\nCurrently in " + curAvenger.getCurLoc();
		labelHawkEye.setText(disp);
		
	} // end of handleHawkEye method
	
	/**
	 * handleIM method activates when Iron Man
	 * is clicked and display's the avenger's information
	 * in their associated label
	 * @param event a button click
	 * 
	 */
	public void handleIM (ActionEvent event) {
		clearAll();
		String searchName = "Tony Stark";
		Avenger curAvenger = Avenger.findAvenger(searchName);
		String disp = curAvenger.getName() +"\n" + curAvenger.getAlias() + "\nCurrently in " + curAvenger.getCurLoc();
		labelIM.setText(disp);
		
	} // end of handleIM method
	
} // end of class
