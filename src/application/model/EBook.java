package application.model;

public abstract class EBook {

	private String author;
	private String title;
	
	public EBook( String filename ) {
		parseInfo( filename );
	}
	
	public EBook( String title, String author ) {
		this.author = author;
		this.title = title;
	}

	public abstract void loadBookData();
	
	
	private void parseInfo( String filename ) {
		// split the given file name into title and author
		
		String[] tokens = filename.split(" - ");
		this.title = tokens[0];
		this.author = tokens[1].substring(0, tokens[1].length() - 4 ); // the last 4 characters are ".txt", for example
	}
	
	public String toString() {
		return this.title + " - " + this.author;
	}
	
	
	/**
	 * @return the author
	 */
	public String getAuthor() {
		return author;
	}

	/**
	 * @param author the author to set
	 */
	public void setAuthor(String author) {
		this.author = author;
	}

	/**
	 * @return the title
	 */
	public String getTitle() {
		return title;
	}

	/**
	 * @param title the title to set
	 */
	public void setTitle(String title) {
		this.title = title;
	}
	
}
