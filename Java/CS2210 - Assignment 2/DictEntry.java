import java.util.*;
import java.io.*;
public class DictEntry {
    
    //initializing variables
	private String key;
	private int code;

    //given public methods for getting code and key from dictionary
	public DictEntry(String key, int code) {
		this.key = key;
		this.code = code;
	}

	public String getKey() {

		return key;
	}

	public int getCode() {
		return code;
	}

}