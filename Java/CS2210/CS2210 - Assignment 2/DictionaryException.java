public class DictionaryException extends Exception {

	//initialize string message
	private String message;
	
	//constructor method
	public DictionaryException(String message) {
		super(message);
		this.message=message;
	}
		
		//Returns the string message which we gave to the constructor
		public String getMessage(){
		return message;
	}
}