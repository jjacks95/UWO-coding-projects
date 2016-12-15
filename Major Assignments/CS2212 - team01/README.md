# Welcome to CS 2212 - Winter 2016

To setup the program, you will need to configure these paths to the corresponding credentials & token files.
The path variables are located in the MainWindow.java file as class variables.

```
	static final String CREDENTIALS_FILE_PATH = "/PATH/Team1Credentials.txt";
	static final String TOKENS_FILE_PATH = "/PATH/Team1Tokens.txt";
```

To start the program, you will need to run these commands in your terminal to run the program.

```
mvn clean
mvn package
java -jar target/team01-TRAINR-0.0.1-SNAPSHOT-jar-with-dependencies.jar
```

