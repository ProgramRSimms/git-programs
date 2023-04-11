package application;
	
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.layout.AnchorPane;

/**
 * Main launches the application and pulls up the Main view.
 * This program will display a number of Avenger images and 
 * give biographic information, loaded from data.csv, when
 * each is clicked.
 * @author Thomas Herron hgo525
 *
 */

public class Main extends Application {
	@Override
	public void start(Stage primaryStage) {
		try {
			
			AnchorPane root = new AnchorPane();
			FXMLLoader loader = new FXMLLoader();
			loader.setLocation( Main.class.getResource("view/Main.fxml") );
			root = (AnchorPane) loader.load();
			Scene scene = new Scene( root );
			primaryStage.setScene( scene );
			primaryStage.show();
			
			/*
			BorderPane root = new BorderPane();
			Scene scene = new Scene(root,400,400);
			scene.getStylesheets().add(getClass().getResource("application.css").toExternalForm());
			primaryStage.setScene(scene);
			primaryStage.show();
			
			*/
		} catch(Exception e) {
			e.printStackTrace();
		}
	}
	
	public static void main(String[] args) {
		launch(args);
	}
}
