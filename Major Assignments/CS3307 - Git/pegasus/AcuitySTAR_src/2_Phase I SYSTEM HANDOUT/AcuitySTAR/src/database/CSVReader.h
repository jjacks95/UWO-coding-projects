/**
  * A header file with function declarations to load a CSV file and parse through the file into strings, which will be
  * stored into the class instance's attributes.
  */

#ifndef CSVREADER_H
#define CSVREADER_H

#include <string>
#include <vector>

class CSVReader {
    //string vector to store the parsed headers of a CSV file
    std::vector<std::string> headers;
    //a vector of string vectors to store the parsed data values of a CSV file
    std::vector<std::vector<std::string>> all_data;
public:
    //Declaration of a constructor to create an empty CSVReader object.
    CSVReader();

    //Declaration of a constructor that will instantiate a CSVReader object, given a filepath name in the form
    //of a string.
    CSVReader(std::string);

    //Parses through a provided CSV file (its filepath represented by a string), storing its headers into
    //the header class attribute, and the rest of the data values into the all_data class attribute.
    void loadCSV(std::string);

    //Converts parsed strings into an integer that represents a year value.
    int parseDateString(std::string dateString);

    //Gets the headers of the loaded CSV file
    std::vector<std::string> getHeaders();

    //Gets the data values stored in the loaded CSV file
    std::vector<std::vector<std::string>> getData();
};

#endif // CSVREADER_H
