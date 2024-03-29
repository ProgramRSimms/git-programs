package application;
	
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;


public class Main extends Application {
	public static Stage stage;
    @Override
	 public void start(Stage primaryStage) {
		 try {
		 Parent root = FXMLLoader.load(getClass().getResource("view/Main.fxml"));
		 		primaryStage.setScene(new Scene(root, 500, 575));
		 		primaryStage.show();
		     } catch(Exception e) {
		         e.printStackTrace();
		 }
    }

	
	public static void main(String[] args) {
		launch(args);
	}
}