public class MapException extends Exception{
	//exceptions class
	private String msg;
	
	public MapException(String msg) {
		super(msg);
		this.msg = msg;
	}
	
	public String getMessage(){
		return msg;
	}
}
