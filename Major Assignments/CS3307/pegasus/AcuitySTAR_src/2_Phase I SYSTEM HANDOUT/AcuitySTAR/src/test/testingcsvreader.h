/**
  * Author: Andy Lac
  * A header file to test functions implemented in the CSVReader class.
  * This file contains function declarations for testing CSVReader class' loadCSV function (a test case for
  * one of each subject area, as well as an empty file to see if it parses through a CSV file properly), the
  * parseDateString function for strings that can be converted into integers and strings that cannot, as well as returning
  * the correct number of headers.
  *
  */

#ifndef TESTCSVREADER_H
#define TESTCSVREADER_H

#include <QtTest/QtTest>
#include <database/CSVReader.h>
#include <string>


class TestingCSVReader : public QObject
{
    Q_OBJECT
private slots:
    //Testing the CSVReader's loading method
    //One test for each subject area as well as an empty CSV file
    void LoadEmptyCSVFileType();
    void LoadTeachingCSVFile();
    void LoadPublicationCSVFile();
    void LoadPresentationCSVFile();
    void LoadGrantsCSVFile();

    //Testing CSVReader's method to parse ints and char strings to integer values
    void TestParseDateString_intString();
    void TestParseDateString_charString();

    //Testing CSVReader's method to return the correct number of headers
    void TestGetNumberHeaders();

};

#endif // TESTCSVREADER_H
