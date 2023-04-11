package application.model;

public class PDFBook extends EBook {

	public PDFBook( String filename ) {
		super( filename );
	}
	
	public PDFBook(String title, String author) {
		super(title, author);
	}

	@Override
	public void loadBookData() {
		// TODO Auto-generated method stub
		
	}

}
