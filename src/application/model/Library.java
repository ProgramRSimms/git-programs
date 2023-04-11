package application.model;

import java.io.File;
import java.util.ArrayList;

public class Library {

	private static String directory;
	private static ArrayList<EBook> books = new ArrayList<EBook>();
	
//	public Library( String dir ) {
//		this.directory = dir;
//	}
	
	public static void loadBooks( File directory ) {
		
		// Save the String representation of the fully qualified path
		String path = directory.getAbsolutePath();
		Library.directory = path;
		
		// Loop through all files and add books to the library
		// REMINDER: title and author is the name of the file
		File[] files = directory.listFiles();
		
		if( files!=null ) {
			for( File book : files ) {
				// create a book object
				EBook temp = new TxtFileBook( book.getName() );
				
				// add that book object to this library
				books.add( temp );
			}
		}
	}
	
	
	public static ArrayList<EBook> getBooks() {
		
		return books;
	}
}
