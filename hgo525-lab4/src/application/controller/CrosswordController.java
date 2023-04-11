package application.controller;

import java.net.URL;
import java.util.ResourceBundle;

import application.Main;
import application.model.Crossword;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.ListView;
import javafx.scene.control.TextField;

/**
 * CrosswordController handles user interaction with the Crossword view.
 * @author Thomas Herron hgo525
 *
 */

public class CrosswordController implements EventHandler<ActionEvent>, Initializable {

	
	private Crossword cross;
	
	@FXML
    private Button showButton;

    @FXML
    private ListView<String> listAcross;

    @FXML
    private Button checkButton;

    @FXML
    private ListView<String> listDown;

    @FXML
    private Button homeButton;
    
    @FXML
    private TextField tf26;

    @FXML
    private TextField tf46;

    @FXML
    private TextField tf22;

    @FXML
    private TextField tf45;

    @FXML
    private TextField tf64;

    @FXML
    private TextField tf65;

    @FXML
    private TextField tf21;
    
    @FXML
    private TextField tf62;

    @FXML
    private TextField tf85;

    @FXML
    private TextField tf41;

    @FXML
    private TextField tf63;

    @FXML
    private TextField tf61;

    @FXML
    private TextField tf16;

    @FXML
    private TextField tf35;

    @FXML
    private TextField tf36;

    @FXML
    private TextField tf55;

    @FXML
    private TextField tf34;

    @FXML
    private TextField tf31;

    @FXML
    private TextField tf53;

    @FXML
    private TextField tf75;
    
    @FXML
    private TextField tf95;

    @FXML
    private TextField tf51;

    @FXML
    private TextField tf73;

    @FXML
    private TextField tf96;

    @FXML
    private TextField tf93;

    @FXML
    private TextField tf94;
    
    private TextField[] across1;
    private TextField[] across2;
    private TextField[] across3;
    private TextField[] across4;
    private TextField[] down1;
    private TextField[] down5;
    private TextField[] down6;
    private TextField[] down7;
    private TextField[] down8;
    private TextField[][] allAcross;
    private TextField[][] allDown;
    
    
    
    /**
     * Initialize method loads ad data from the down.csv and across.csv file and stores it in a 
     * Crossword object. Several arrays are built to truncate coding later at the possible
     * expense of memory use and runtime.
     * 
     * @param location  variable auto-generated from Initializable interface
     * @param resources variable auto-generated from Initializable interface
     */
    
    @Override
	public void initialize(URL location, ResourceBundle resources) {
		cross = Crossword.loadData("data/down.csv", "data/across.csv");
    	
    	ObservableList<String> acrossClues = cross.getCluesAsList(cross.getAcrossQ());
    	ObservableList<String> downClues = cross.getCluesAsList(cross.getDownQ());
    	
    	this.listAcross.getItems().addAll(acrossClues);
    	
    	
    	this.listDown.getItems().addAll(downClues);
    	
    	
    	across1 = new TextField[] {tf21, tf31, tf41, tf51, tf61};
        across2 = new TextField[] {tf53, tf63, tf73};
        across3 = new TextField[] {tf35, tf45, tf55, tf65, tf75, tf85, tf95};
        across4 = new TextField[] {tf16, tf26, tf36, tf46};
        down1 = new TextField[] {tf21, tf22};
        down5 = new TextField[] {tf34, tf35, tf36};
        down6 = new TextField[] {tf45, tf46};
        down7 = new TextField[] {tf61, tf62, tf63, tf64, tf65};
        down8 = new TextField[] {tf93, tf94, tf95, tf96};
        allAcross = new TextField[][] {across1, across2, across3, across4};
        allDown = new TextField[][] {down1, down5, down6, down7, down8};
    
    } // end of initialize method
    
    /**
	 * handle method returns the user to the Main view
	 * @param event clicking the HOME button
	 */
    
    @FXML
    public void handle(ActionEvent event) {

    	try {
    		
    		Parent root = FXMLLoader.load(getClass().getResource("../view/Main.fxml"));
			Main.stage.setScene(new Scene(root, 800, 600));
			Main.stage.show();

    	} catch(Exception e) {
			e.printStackTrace();
		}
    	
    	
    }

    /**
     * handleCheck method handles clicks of the CHECK button. It compared text in
     * the text fields to data in the Crossword object
     * @param event click of the CHECK button
     */
    
    @FXML
    public void handleCheck(ActionEvent event) {
    	int k = 0;
    	for (int i=0; i < allAcross.length; i++) {
    		while (cross.getAcrossA()[k] == null) {
    			k++;
    		}
   
    		for (int j = 0; j < cross.getAcrossA()[k].length(); j++) {
    			if ( allAcross[i][j].getText() != null && ! allAcross[i][j].getText().isEmpty()) {
    				boolean correct = cross.checkAcrossLetter(k, j, allAcross[i][j].getText().charAt(0));
    				if (!correct) {
    					allAcross[i][j].setStyle("-fx-text-fill: red;");
    				} else {
    					allAcross[i][j].setStyle("-fx-text-fill: black;");
    				}
    			}
    		}
    		k++;
    		
    	} // end of allAcross loop
    	
    	k=0;
    	for (int i=0; i < allDown.length; i++) {
    		
    		while (cross.getDownA()[k] == null) {
    			k++;
    		}
    		for (int j = 0; j < cross.getDownA()[k].length(); j++) {
    			if ( allDown[i][j].getText() != null && ! allDown[i][j].getText().isEmpty()) {
    				boolean correct = cross.checkDownLetter(k, j, allDown[i][j].getText().charAt(0));
    				if (!correct) {
    					allDown[i][j].setStyle("-fx-text-fill: red;");
    				} else {
    					allDown[i][j].setStyle("-fx-text-fill: black;");
    				}
    			}
    		}
    		k++;
    		
    	} // end of allDown loop
    	
    	
    } // end of handleCheck method

    /**
     * handleShow button handles clicks of the SHOW ANSWERS button.
     * It populated all text fields with correct answers from the Crossword
     * object.
     * @param event click of the SHOW ANSWERS button
     */
    
    @FXML
    public void handleShow(ActionEvent event) {
    	int k = 0;
    	for (int i=0; i < allAcross.length; i++) {
    		while (cross.getAcrossA()[k] == null) {
    			k++;
    		}
   
    		for (int j = 0; j < cross.getAcrossA()[k].length(); j++) {
    			allAcross[i][j].setText(Character.toString(cross.getAcrossLetter(k, j)));
    			allAcross[i][j].setStyle("-fx-text-fill: black;");
    		}
    		k++;
    		
    	} // end of allAcross loop
    	
    	k = 0;
    	for (int i=0; i < allDown.length; i++) {
    		while (cross.getDownA()[k] == null) {
    			k++;
    		}
   
    		for (int j = 0; j < cross.getDownA()[k].length(); j++) {
    			allDown[i][j].setText(Character.toString(cross.getDownLetter(k, j)));
    			allDown[i][j].setStyle("-fx-text-fill: black;");
    		}
    		k++;
    		
    	} // end of allDown loop
    }

	
	
}
