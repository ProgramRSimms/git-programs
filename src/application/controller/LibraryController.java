package application.controller;

import java.net.URL;
import java.util.ArrayList;
import java.util.ResourceBundle;

import application.Main;
import application.model.EBook;
import application.model.Library;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Label;

public class LibraryController implements EventHandler<ActionEvent>, Initializable{

	@FXML
	private Label testLabel;
	
	@Override
	public void initialize(URL location, ResourceBundle resources) {
		
		// show the user their library (from chosen directory)
		ArrayList<EBook> books = Library.getBooks();
		
		// TODO: Make the data more clean for the user to see!
		
//		for( EBook book : books ) {
//			
//		}
		
		testLabel.setText( books.toString() );
		
		
		// TODO: Allow user to click a GUI component (add to the view!) for each book
		//     -- this means adding GUI components to the fxml, connect them to handle method below
		
	}
	
	
	@Override
	public void handle(ActionEvent event) {
		// TODO: what GUI components do we need to add, and should they do?
		
		
	
		// Move the user to the next view (should show book - page by page - to them)
		try {
			Parent root = FXMLLoader.load(getClass().getResource("../view/Page.fxml"));
			Main.stage.setScene(new Scene(root, 500, 800));
			Main.stage.show();
			
		} catch(Exception e) {
			e.printStackTrace();
		}
		
	}
}
