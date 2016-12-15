public class GraphException extends Exception{
	//exception class
	private String msg;
	
	public GraphException(String msg) {
		super(msg);
		this.msg = msg;
	}
	public String getMessage(){
		return msg;
	}

}