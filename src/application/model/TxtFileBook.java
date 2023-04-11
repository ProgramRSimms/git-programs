package application.model;

public class TxtFileBook extends EBook {

	private String fileName;
	
	public TxtFileBook( String filename ) {
		super( filename );
	}
	
	public TxtFileBook( String title, String author, String fileName ) {
		super(title, author);
		this.fileName = fileName;
	}

	@Override
	public void loadBookData() {
		// TODO: read in txt file EBooks
		
	}

	
	
	
}
