package application.controller;

import java.net.URL;
import java.util.ResourceBundle;

import application.Main;
import application.model.Classifieds;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;

/**
 * ClassifiedsController handles interaction with the Classifieds.fxml view.
 * @author Thomas Herron hgo525
 *
 */

public class ClassifiedsController implements EventHandler<ActionEvent>, Initializable {

    @FXML
    private Label a2Poster;

    @FXML
    private Label a1Position;

    @FXML
    private Label a3Time;

    @FXML
    private Label a1Poster;

    @FXML
    private Label a2Position;

    @FXML
    private Label a3Phone;

    @FXML
    private Label a4Time;

    @FXML
    private Label a4Phone;

    @FXML
    private Label a4Poster;

    @FXML
    private Label a1Phone;

    @FXML
    private Button homeButton;

    @FXML
    private Label a2Time;

    @FXML
    private Label a3Position;

    @FXML
    private Label a2Phone;

    @FXML
    private Label a3Poster;

    @FXML
    private Label a4Position;

    @FXML
    private Label a1Time;
    
    private Classifieds ads;

    /**
     * Initialize method loads ad data from the ads.csv file, stores it in a Classifieds object,
     * and loads that data in to the 4 ad blocks provided by the Classifieds view.
     * It uses several arrays to truncate coding at the possible expense of 
     * memory use and runtime.
     * 
     * @param location  variable auto-generated from Initializable interface
     * @param resources variable auto-generated from Initializable interface
     */
    
	@Override
	public void initialize(URL location, ResourceBundle resources) {
		ads = new Classifieds();
		ads.loadAds("data/ads.csv");
		
		a1Position.setWrapText(true);
		a2Position.setWrapText(true);
		a3Position.setWrapText(true);
		a4Position.setWrapText(true);
		a1Position.setPrefWidth(200);
		a2Position.setPrefWidth(200);
		a3Position.setPrefWidth(200);
		a4Position.setPrefWidth(200);
		
		Label[] ad1 = {a1Position, a1Time, a1Phone, a1Poster};
		Label[] ad2 = {a2Position, a2Time, a2Phone, a2Poster};
		Label[] ad3 = {a3Position, a3Time, a3Phone, a3Poster};
		Label[] ad4 = {a4Position, a4Time, a4Phone, a4Poster};
		
		Label[][] adAll = {ad1, ad2, ad3, ad4};
		
		for (int i = 0; i < adAll.length; i++) {
			if (i >= ads.getAds().size()) {
				break;
			}
			adAll[i][0].setText(ads.getAds().get(i).getTitle());
			adAll[i][1].setText(ads.getAds().get(i).getTimeFormatted());
			adAll[i][2].setText(ads.getAds().get(i).getPhoneFormatted());
			String poster = ads.getAds().get(i).getPoster() + ", " + ads.getAds().get(i).getDateFormatted();
			adAll[i][3].setText(poster);
		}
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
    	
    	
    } // end of handle method
 

}
