package application.model;


import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Locale;


/**
 * Advertisement class stores data for Advertisement objects, including a 
 * job title, phoneNumber, date, poster's name, and full time status boolean.
 * It also includes methods for returning phone number, date, and full time
 * status as Strings with alternative formats.
 * @author Thomas Herron hgo525
 *
 */

public class Advertisement {

	
	private String title;
	private String phoneNumber;
	private String date;
	private String poster;
	private boolean fullTime;
	
	/**
	 * Advertisement constructor requiring title, fulltime status, phoneNumber, poster name, and date.
	 * 
	 * @param title title of the job position
	 * @param fullTime full time status as a boolean
	 * @param phoneNumber phoneNumber String given as 10 digits only
	 * @param poster name of ad poster
	 * @param date date of ad placement in MM-DD-YYYY format
	 */
	public Advertisement(String title, boolean fullTime, String phoneNumber, String poster, String date) {
		this.title = title;
		this.phoneNumber = phoneNumber;
		this.date = date;
		this.poster = poster;
		this.fullTime = fullTime;
		
	} // end of constructor method
	
	/**
	 * getPhoneFormatted returns the phoneNumber String in
	 * (XXX) XXX-XXXX format
	 * @return String with the phone number in (XXX) XXX-XXXX format
	 */
	public String getPhoneFormatted() {
		if ( this.phoneNumber.length() != 10 ) {
			return this.phoneNumber;
		}
		String ret = "(" + this.phoneNumber.substring(0,3) + ") " + this.phoneNumber.substring(3,6) + "-" + this.phoneNumber.substring(6);
		
		return ret;
	} // end of getPhoneFormatted method
	
	/**
	 * getDateFormatted returns the date in MMM. dd, yyyy format.
	 * @return String with the date in MMM. dd, yyyy format
	 */
	public String getDateFormatted() {
		String ret;
		DateFormat formatIn = new SimpleDateFormat("MM-dd-yyyy", Locale.ENGLISH);
		DateFormat formatOut = new SimpleDateFormat("MMM. dd, yyyy");
		
		Date date;
		try {
			date = formatIn.parse(this.getDate());
			ret = formatOut.format(date);
			
		} catch (ParseException e) {
			e.printStackTrace();
			return this.date;
		}
				
		return ret;
		
	} // end of getDateFormatted method
	
	/**
	 * getTimeFormatted converts the fullTime boolean into a String
	 * representing Full time or Part time
	 * @return String with Full time or Part Time
	 */
	public String getTimeFormatted() {
		String ret;
		if (this.fullTime) {
			ret = "(Full time)";
		} else {
			ret = "(Part time)";
		}
		
		return ret;
	}

	// Auto-generated getters and setters beyond this point
	
	/**
	 * getTitle method returns the specified String variable
	 * @return the title
	 */
	public String getTitle() {
		return title;
	}


	/**
	 * setTitle method sets the specified String variable
	 * @param title the title to set
	 */
	public void setTitle(String title) {
		this.title = title;
	}


	/**
	 * getPhoneNumber method returns the specified String variable
	 * @return the phoneNumber as a string of 10 digits
	 */
	public String getPhoneNumber() {
		return phoneNumber;
	}


	/**
	 * setPhoneNumber method sets the specified String variable
	 * @param phoneNumber the phoneNumber to set as a String of 10 digits
	 */
	public void setPhoneNumber(String phoneNumber) {
		this.phoneNumber = phoneNumber;
	}


	/**
	 * getDate method returns the specified String variable
	 * @return the date String in MM-DD-YYYY format
	 */
	public String getDate() {
		return date;
	}


	/**
	 * setDate method sets the specified String variable
	 * @param date the date to set in MM-DD-YYYY format
	 */
	public void setDate(String date) {
		this.date = date;
	}


	/**
	 * getPoster method returns the specified String variable
	 * @return the poster's name
	 */
	public String getPoster() {
		return poster;
	}


	/**
	 * setPoster method returns the specified String variable
	 * @param poster the poster's name to set
	 */
	public void setPoster(String poster) {
		this.poster = poster;
	}


	/**
	 * isFullTime method returns a boolean indicating if the position
	 * is Full Time
	 * @return the fullTime status as a boolean
	 */
	public boolean isFullTime() {
		return fullTime;
	}


	/**
	 * setFullTime method sets the boolean indicating if the position
	 * is Full Time
	 * @param fullTime the fullTime boolean to set
	 */
	public void setFullTime(boolean fullTime) {
		this.fullTime = fullTime;
	}
	
	
	
}
