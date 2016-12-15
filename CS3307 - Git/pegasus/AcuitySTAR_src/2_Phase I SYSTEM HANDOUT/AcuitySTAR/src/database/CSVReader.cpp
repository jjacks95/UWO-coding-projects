/**
  * The CSVReader.cpp file implements the function declarations of its respective header file.
  * This file allows the User to load CSV files with a function that parses through the CSV File
  * and converts its headers and data values into strings which will be stored within an instance
  * of a CSVReader object.
  *
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <stdexcept>
#include "database/CSVReader.h"


/**
 * @brief CSVReader::CSVReader
 * Constructor to build a blank CSVReader
 */
CSVReader::CSVReader() {

}

/**
 * @brief CSVReader::CSVReader
 * @param file - the file path to a CSV file
 * Constructor to build a CSVReader with a provided CSV file.
 */
CSVReader::CSVReader(std::string file) {
    loadCSV(file);
}

/**
 * @brief CSVReader::loadCSV
 * @param file_name contains the file path to a CSV file
 * Loads a CSV file given an existing filepath to a CSV file is provided.
 * Parses the CSV file into strings to separate headers/attributes with the actual data values.
 */
void CSVReader::loadCSV(std::string file_name) {
    //Storing the contents of the CSV file into an input file stream.
     std::ifstream myfile(file_name.c_str());

    //Check to see file is not a CSV file/cannot be opened
    if (myfile.fail()) {
        std::cout << "Couldn't open file \"" << file_name << "\"." << std::endl;
        return;
    }

    //Check to see if the file is able to open properly
    if (myfile.is_open()) {

        //Loading the CSV file data and buffering it into a string variable
        std::stringstream CSVFileStringStream;
        //Writing the data in the CSV file into strings
        CSVFileStringStream << myfile.rdbuf();

        //Reference to the string converted data from the CSV file
        std::string CSVFileStringData = CSVFileStringStream.str();

		myfile.close();

        //Get the length of the StringData to parse through and set headers for the GUI.
        size_t stringDataLength = CSVFileStringData.length();
		
        //Boolean variable that represents when the CSV file's headers have been parsed
		bool setHeaders = false;
		
        //Initial index to read the first character of the string converted data.
        size_t stringDataPosition = 0;

        // While loop to parse through the CSVFileStringData
        while( stringDataPosition< stringDataLength ) {
            std::vector<std::string> line;
            //Loop that stops when the index has reached the last character in the line
            while( CSVFileStringData.at( stringDataPosition) != '\n' && stringDataPosition < stringDataLength ) {
				std::string element = "";
                //Check to see if the character at the index is not a comma, reads through to a new line, or is a carriage return to point to the next line.
                while( CSVFileStringData.at( stringDataPosition ) != ',' && stringDataPosition < stringDataLength && CSVFileStringData.at( stringDataPosition ) != '\n' && CSVFileStringData.at( stringDataPosition ) != '\r' ) { // For each element

                    //If the index begins to read a quote, it will continue to do so until the next quote has been reached
                    if( CSVFileStringData.at( stringDataPosition ) == '"' ) {
                        stringDataPosition++;
                        //While the index does not reach the end of the quote
                        while( CSVFileStringData[stringDataPosition] != '"' && stringDataPosition < stringDataLength ) {

                            //Store the characters until the end of the quote has been reached
                            element += CSVFileStringData.at( stringDataPosition );
                            stringDataPosition++;
						}
                        stringDataPosition++; // Last quote
                    }
                    //If the index does read the beginning of a quote
                    else {
                        //Store the character at the index and continue on.
                        element += CSVFileStringData.at( stringDataPosition );
                        stringDataPosition++;
					}
				}
                //Store the characters stored in element into the string vector
                line.push_back( element );

                //Once the end of the line has been reached, stop reading characters.
                if ( CSVFileStringData.at( stringDataPosition ) == '\n') {
                    break;
                }
                //Increment the index to reach the next character
                stringDataPosition++;
			}
            //Reading and storing the characters will produce strings of headers
            //Conditional for the software to not set all of the characters as a header of the CSV file.
			if( !setHeaders ) {
				setHeaders = true;
				headers = line;
            }
            //If the headers are already set, then the software will store the rest of the data into a 2D string vector
            //Which will represent the rest of the data in the CSV file.
            else {
				all_data.push_back( line );
            }
            stringDataPosition++;
		}
    }
}

// Returns the year in a date string.
/**
 * @brief CSVReader::parseDateString
 * @param dateString - string representation of an integer
 * @return an integer value, converted from the string parameter.
 */
int CSVReader::parseDateString(std::string dateString) {
    int year;
    sscanf(dateString.c_str(), "%4d", &year); // The only 4-digit number in a date field is a year, period
    //Checks to see if the result is -2 --> the parameter string does not translate to an integer
    if(year < 1950){
            //Sets the year to the default start year
           year = 1950;
           return year;
    }
    else{
        return year;
    }
}

// Returns the header vector for a CSV
/**
 * @brief CSVReader::getHeaders
 * @return returns a vector of strings that represent the header names in the CSV file
 */
std::vector<std::string> CSVReader::getHeaders() {
    return headers;
}

// Returns all data from a CSV
/**
 * @brief CSVReader::getData
 * @return The data values stored in a CSV file, in string format.
 */
std::vector<std::vector<std::string>> CSVReader::getData() {
    return all_data;
}
