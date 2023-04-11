package application.controller;

import java.net.URL;
import java.util.ResourceBundle;

import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Label;

public class PageController implements EventHandler<ActionEvent>, Initializable{

	
	@Override
	public void initialize(URL location, ResourceBundle resources) {
		
		// TODO: show the user their chosen book title
		
		// TODO: read in the chosen book from file (this should be in the model)
		
		// TODO: show user 1 page at a time
		
	}
	
	
	@Override
	public void handle(ActionEvent event) {
		// TODO: connect this to the HOME button
		
	}
	
	
	public void handleNext(ActionEvent event) {
		// TODO: connect this to the NEXT button
	
	}
	
	
	public void handlePrevious(ActionEvent event) {
		// TODO: connect this to the PREVIOUS button
		
	}
}
