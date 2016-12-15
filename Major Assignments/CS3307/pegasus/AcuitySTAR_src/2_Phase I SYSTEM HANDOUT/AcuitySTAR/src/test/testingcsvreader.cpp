/**
  * Author: Andy Lac
  * A .cpp file that contains the implementations declared in its respective header file.
  * Each implementation will test the CSVReader class' functions for parsing through a CSV file through its
  * loadCSV file, converting strings into year integer values, and returning the correct number of headers.
  */

#include "testingcsvreader.h"
#include <vector>

/**
 * @brief TestingCSVReader::LoadCSVFileType
 * Testing to see if the CSVReader can properly read/load a CSV file
 */
void TestingCSVReader::LoadEmptyCSVFileType(){
    CSVReader testReader;
    testReader.loadCSV("../TestCase_Files/TestCSVReader.csv");
    int actualCSVReaderLength = testReader.getHeaders().size();
    int expectedTestCSVReaderLength = 0;
    QCOMPARE(actualCSVReaderLength, expectedTestCSVReaderLength);
}

/**
 * @brief LoadTeachingCSVFile
 * Testing to see if the CSVReader instance loads a Teaching CSV file properly.
 */
void TestingCSVReader::LoadTeachingCSVFile(){
    CSVReader testReader;
    testReader.loadCSV("../Project Information/Sample Data/Teaching_sample.csv");
    int actualCSVReaderLength = testReader.getHeaders().size();
    int TestCSVReaderLength = 0;
    bool expectedResult = true;
    bool actualResult = false;
    if(actualCSVReaderLength != TestCSVReaderLength){
        actualResult = true;
    }
    QCOMPARE(actualResult, expectedResult);
}

/**
 * @brief LoadPublicationCSVFile
 * Testing to see if the CSVReader instance loads a Publication CSV file properly.
 */
void TestingCSVReader::LoadPublicationCSVFile(){
    CSVReader testReader;
    testReader.loadCSV("../Project Information/Sample Data/Publications_sample.csv");
    int actualCSVReaderLength = testReader.getHeaders().size();
    int TestCSVReaderLength = 0;
    bool expectedResult = true;
    bool actualResult = false;
    if(actualCSVReaderLength != TestCSVReaderLength){
        actualResult = true;
    }
    QCOMPARE(actualResult, expectedResult);
}

/**
 * @brief LoadPresentationCSVFile
 * Testing to see if the CSVReader instance loads a Presentation CSV file properly.
 */
void TestingCSVReader::LoadPresentationCSVFile(){
    CSVReader testReader;
    testReader.loadCSV("../Project Information/Sample Data/Presentations_sample.csv");
    int actualCSVReaderLength = testReader.getHeaders().size();
    int TestCSVReaderLength = 0;
    bool expectedResult = true;
    bool actualResult = false;
    if(actualCSVReaderLength != TestCSVReaderLength){
        actualResult = true;
    }
    QCOMPARE(actualResult, expectedResult);
}

/**
 * @brief LoadGrantsCSVFile
 * Testing to see if the CSVReader instance loads a Grants CSV file properly
 */
void TestingCSVReader::LoadGrantsCSVFile(){
    CSVReader testReader;
    testReader.loadCSV("../Project Information/Sample Data/GrantsClinicalFunding_sample.csv");
    int actualCSVReaderLength = testReader.getHeaders().size();
    int TestCSVReaderLength = 0;
    bool expectedResult = true;
    bool actualResult = false;
    if(actualCSVReaderLength != TestCSVReaderLength){
        actualResult = true;
    }
    QCOMPARE(actualResult, expectedResult);
}


/**
 * @brief TestingCSVReader::TestParseDateString_intString
 * Test to see if it correctly parses a string and converts it to an integer.
 */
void TestingCSVReader::TestParseDateString_intString(){
    CSVReader testReader;
    testReader.loadCSV("../Project Information/Sample Data/Grants_expanded.csv");
    std::string testString = "1950";
    int expectedResult = 1950;
    int actualResult = testReader.parseDateString(testString);
    QCOMPARE(actualResult, expectedResult);
}
/**
 * @brief TestingCSVReader::TestParseDateString_charString
 * Test to see if this method does not parse a string of characters into an integer
 */
void TestingCSVReader::TestParseDateString_charString(){
    CSVReader testReader;
    testReader.loadCSV("../Project Information/Sample Data/Grants_expanded.csv");
    std::string testString = "////////";
    int expectedResult = 1950;
    int actualResult = testReader.parseDateString(testString);
    QCOMPARE(actualResult, expectedResult);
}

/**
 * @brief TestingCSVReader::TestGetNumberHeaders
 * Test to see if the CSVReader returns the exact number of headers/attributes as stored in the CSV file.
 */
void TestingCSVReader::TestGetNumberHeaders(){
    CSVReader testReader;
    testReader.loadCSV("../Project Information/Sample Data/Grants_expanded.csv");
    int actualNumHeaders = testReader.getHeaders().size();
    int expectedNumHeaders = 37;
    QCOMPARE(actualNumHeaders, expectedNumHeaders);
}
