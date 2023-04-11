package application.controller;

import application.Main;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;

/**
 * MainController handles user interaction with the Main view.
 * @author Thomas Herron hgo525
 *
 */

public class MainController implements EventHandler<ActionEvent> {

	
	@FXML
    private Button classifiedsButton;

    @FXML
    private Button crosswordButton;

    
    /**
     * handle method handles clicks of the CLASSIFIEDS button and switches
     * to the Classifieds view.
     * @param event click of the CLASSIFIEDS button
     */
    @FXML
    public void handle(ActionEvent event) {

    	try {
    		
    		Parent root = FXMLLoader.load(getClass().getResource("../view/Classifieds.fxml"));
			Main.stage.setScene(new Scene(root, 800, 600));
			Main.stage.show();

    	} catch(Exception e) {
			e.printStackTrace();
		}
    	
    } // end of handle method

    
    /**
     * handle method handles clicks of the CROSSWORD button and switches
     * to the Crossword view.
     * @param event click of the CROSSWORD button
     */
    @FXML
    public void handleCrossword(ActionEvent event) {

    	try {
    		
    		Parent root = FXMLLoader.load(getClass().getResource("../view/Crossword.fxml"));
			Main.stage.setScene(new Scene(root, 800, 600));
			Main.stage.show();
    		
    	} catch(Exception e) {
			e.printStackTrace();
		}
    	
    } // end of handleCrossword method
	

	
}
