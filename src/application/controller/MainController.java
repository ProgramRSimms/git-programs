package application.controller;

import java.io.File;

import application.Main;
import application.model.Library;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.DirectoryChooser;
import javafx.stage.Stage;

public class MainController implements EventHandler<ActionEvent>{

	@Override
	public void handle(ActionEvent event) {
		
		// Ask the user to choose the location of their books
		DirectoryChooser d = new DirectoryChooser();
		File dir = d.showDialog( new Stage() );
		
//		System.out.println( dir );
		
		// loop over all files (books) in the user's library & create a Library
		Library.loadBooks( dir );
		
		
		// Move the user to the next view (should show library to them)
		try {
			Parent root = FXMLLoader.load(getClass().getResource("../view/Library.fxml"));
			Main.stage.setScene(new Scene(root, 500, 800));
			Main.stage.show();
			
		} catch(Exception e) {
			e.printStackTrace();
		}
	}
	
}