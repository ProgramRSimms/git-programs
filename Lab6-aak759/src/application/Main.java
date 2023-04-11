/*Main.java is a Java class containing:
 *  
 * @author Roderick Simms (aak759)
 * UTSA CS 3443 - Lab 6
 * Fall 2021
 * */

package application;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.image.ImageView;
import javafx.scene.layout.Pane;
import javafx.scene.text.Text;
import application.model.AvengerTask;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.stage.Stage;
import javafx.scene.Parent;
import javafx.scene.Scene;


/**
 * JavaFX launch
 */
public class Main extends Application{
	//private static final double lng = (Math.random() * 360.0) - 180.0;
	//private static final double lat = (Math.random() * 180.0) - 90.0;

	@FXML
    private Text thor;

    @FXML
    private Text textBox;

    @FXML
    private Text hawkeye;

    @FXML
    private ImageView mapImage;

    @FXML
    private Text captainAmerica;

    @FXML
    private Text Date;

    @FXML
    private Pane shadedPane;

    @FXML
    private Text blackWidow;

    @FXML
    private ImageView logoImage;

    @FXML
    private Text ironman;

    @FXML
    private Text doctorStrange;

    @FXML
    private Text hulk;

    @FXML
    private Text blackPanther;

   
	public void start(Stage primaryStage) {
		try {
			
			Parent root = FXMLLoader.load(getClass().getResource("view/Main.fxml"));
			primaryStage.setScene(new Scene(root, 800, 800));
			primaryStage.show();
			
		} catch(Exception e) {
			e.printStackTrace();
		}
	}
	/*initialize
	(URL url, ResourceBundle rb){
		Circle hulkCircle = new Circle(lat,lng,5,Color.RED);
		PathTransition transition = new PathTransition();
		transition.setNode(hulk);
		transition.setDuration(Duration.seconds(10));
		transition.setPath(lat, lng);
		transition.setCycleCount(PathTransition.INDEFINITE);
		transition.play();
	}*/
		


/*public class Main extends Application {
	@Override
	public void start(Stage primaryStage) {
		try {
			
			AnchorPane root = new AnchorPane();
			FXMLLoader loader = new FXMLLoader();
			loader.setLocation( Main.class.getResource("/Main.fxml") );
			root = (AnchorPane) loader.load();
			Scene scene = new Scene( root );
			primaryStage.setScene( scene );
			primaryStage.show();
		} catch(Exception e) {
			e.printStackTrace();
		}
	}*/
	public static void main(String[] args) {
		AvengerTask captainAmerica = new AvengerTask();
		AvengerTask hulk = new AvengerTask();
		AvengerTask godOfThunder = new AvengerTask();
		AvengerTask blackWidow = new AvengerTask();
		AvengerTask doctorStrange = new AvengerTask();
		AvengerTask ironMan = new AvengerTask();
		AvengerTask blackPanther = new AvengerTask();
		AvengerTask hawkeye = new AvengerTask();
		AvengerTask spiderman = new AvengerTask();
		AvengerTask captainMarvel = new AvengerTask();
		
		/*
		 * start thread for each avenger
		 */
		
		captainAmerica.start();
		hulk.start();
		godOfThunder.start();
		blackWidow.start();
		doctorStrange.start();
		ironMan.start();
		blackPanther.start();
		hawkeye.start();
		spiderman.start();
		captainMarvel.start();
		
		launch(args);
	}

	

}

/*
public class Main extends Application {
	@Override
	public void start(Stage primaryStage) {
		try {
			/*BorderPane root = new BorderPane();
			AnchorPane root = (AnchorPane)FXMLLoader.load(getClass().getResource("Main.fxml"));
			Scene scene = new Scene(root,400,400);
			scene.getStylesheets().add(getClass().getResource("application.css").toExternalForm());
			primaryStage.setScene(scene);
			primaryStage.show();*//*
			AnchorPane root = new AnchorPane();
			FXMLLoader loader = new FXMLLoader();
			loader.setLocation( Main.class.getResource("/Main.fxml") );
			root = (AnchorPane) loader.load();
			Scene scene = new Scene( root );
			primaryStage.setScene( scene );
			primaryStage.show();
		} catch(Exception e) {
			e.printStackTrace();
		}
	}
	
	public static void main(String[] args) {
		launch(args);
	}
}

	
	public static void main(String[] args) {
		launch(args);
	}
}
*/

