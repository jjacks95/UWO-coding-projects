/**
  * Author: Andy Lac
  * A .cpp file that contains the implementations declared in its respective header file.
  * Each implementation will test the QSortListIO class' functions for saving a .dat file and
  * reading from one.
  */

#include "testqsortlist.h"
#include <database/QSortListIO.h>
#include <QFile>

#define TEST_READ_FUND_LIST "fundsortorder.dat"
#define TEST_READ_PRESENTATION_LIST "pressortorder.dat"
#define TEST_READ_PUBLICATION_LIST "pubsortorder.dat"
#define TEST_READ_TEACHING_LIST "teachsortorder.dat"

/**
 * @brief TestQSortList::TestSaveList
 * Test to see if the software saves a dummy .dat file
 */
void TestQSortList::TestSaveList(){
    //Declare the dummy QStringList to assign random fields.
    //This emulates the situation where a User chooses fields in the New Sort Order to sort the data.
    QStringList testStringList;
    testStringList <<"Animal";
    testStringList << "Name" << "Behaviour" << "Diet";

    //Declare a QList<QStringList> to store the dummy QStringList object to store within a .dat file
    QList<QStringList> testQList;
    testQList << testStringList;
    QSortListIO saveAnimalList("animalList.dat");
    saveAnimalList.saveList(testQList);

    //Checking to see if the saveList function was able to create a dummy .dat file
    QString datFile("animalList.dat");
    QFile testFile(datFile);

    //Bool value that contains the result of checking if the dummy .dat file was able to save correctly.
    bool actualResult = testFile.exists();
    bool expectedResult = true;
    QCOMPARE(actualResult, expectedResult);
}

/**
 * @brief TestQSortList::TestSaveListContent
 * Test to see if the dummy .dat file was able to save properly. Compare its contents with a dummy QStringList.
 */
void TestQSortList::TestSaveListContent(){
    //Load the .dat file and store its content within a QList<QStringList> object
    QSortListIO testAnimalLoadList("animalList.dat");
    QList<QStringList> testReadAnimalList = testAnimalLoadList.readList();

    //Reference the QStringList from the QList.
    QStringList animalList = testReadAnimalList[0];

    //Assigning values to the QStringList for comparison with the .dat file.
    QStringList stringCheckList;
    stringCheckList << "Animal" << "Name" << "Behaviour" << "Diet";

    //Test values
    bool actualResult = false;
    bool expectedResult = true;

    //Loop to iterate through each QStringList's contents to see if the values match.
    for(int i = 0; i < animalList.size(); i++){
        if(stringCheckList[i] == animalList[i]){

            //If all the values match and both lists are reaching the end, then all values have matched.
            if(i == animalList.size() - 1){
                //Set the test value to pass the test.
                actualResult = true;
            }
        }
        //When a failed match occurs, leave the loop and fail the test.
        else{
            break;
        }
    }
    //Compare test values
    QCOMPARE(actualResult, expectedResult);
}

//ReadList function tests.

/**
 * @brief TestQSortList::TestReadTeachingList
 * Testing to see if the QSortListIO class can read a teaching .dat file correctly
 * Test to see if the length of the default teaching .dat file exists (greater than 0).
 */
void TestQSortList::TestReadTeachingList(){
    //Loading the teachsortorder.dat file into a QSortListIO object
    QSortListIO testTeachingLoadList(TEST_READ_TEACHING_LIST);
    QList<QStringList> testReadTeachingList = testTeachingLoadList.readList();

    //Test variables to see if the default Sort Order for is saved and read correctly.
    //Tested by using the length of the QList<QStringList> stored in the .dat file
    int actualLength = testReadTeachingList.size();
    int failLength = 0;

    bool actualResult = false;
    bool expectedResult = true;

    //If the QSortListIO class is not able to save correctly, then the .dat file will store a
    //QList<QStringList> with a length of 0 (failure).
    if(actualLength != failLength){
         //Set the expected test variable to true to pass the Test.
        actualResult = true;
    }

    QCOMPARE(actualResult, expectedResult);
}

/**
 * @brief TestQSortList::TestReadPresentationList
 * Testing to see if the QSortListIO class can read a presentation .dat file correctly
 * Test to see if the length of the default presentation .dat file exists (greater than 0).
 */
void TestQSortList::TestReadPresentationList(){
    //Loading the pressortorder.dat file into a QSortListIO object
    QSortListIO testLoadPresentationList(TEST_READ_PRESENTATION_LIST);
    QList<QStringList> testReadPresentationList = testLoadPresentationList.readList();

    //Test variables to see if the default Sort Order for is saved and read correctly.
    //Tested by using the length of the QList<QStringList> stored in the .dat file
    int actualLength = testReadPresentationList.size();
    int failLength = 0;

    bool actualResult = false;
    bool expectedResult = true;

    //If the QSortListIO class is not able to save correctly, then the .dat file will store a
    //QList<QStringList> with a length of 0 (failure).
    if(actualLength != failLength){
        //Set the expected test variable to true to pass the Test.
        actualResult = true;
    }

    QCOMPARE(actualResult, expectedResult);
}

/**
 * @brief TestQSortList::TestReadPublicationsList
 * Testing to see if the QSortListIO class can read a publications .dat file correctly
 * Test to see if the length of the default publications .dat file exists (greater than 0).
 */
void TestQSortList::TestReadPublicationsList(){
    //Loading the pubsortorder.dat file into a QSortListIO object
    QSortListIO testLoadPublicationsList(TEST_READ_PUBLICATION_LIST);
    QList<QStringList> testReadPublicationsList = testLoadPublicationsList.readList();

    //Test variables to see if the default Sort Order for is saved and read correctly.
    //Tested by using the length of the QList<QStringList> stored in the .dat file
    int actualLength = testReadPublicationsList.size();
    int failLength = 0;

    bool actualResult = false;
    bool expectedResult = true;

    //If the QSortListIO class is not able to save correctly, then the .dat file will store a
    //QList<QStringList> with a length of 0 (failure).
    if(actualLength != failLength){
         //Set the expected test variable to true to pass the Test.
        actualResult = true;
    }

    QCOMPARE(actualResult, expectedResult);
}

/**
 * @brief TestQSortList::TestReadGrantFundList
 * Testing to see if the QSortListIO class can read a Grant Fund .dat file correctly
 * Test to see if the length of the default Grant Fund .dat file exists (greater than 0).
 */
void TestQSortList::TestReadGrantFundList(){
    //Loading the fundsortorder.dat file into a QSortListIO object
    QSortListIO testLoadGrantFundList(TEST_READ_FUND_LIST);
    QList<QStringList> testReadGrantFundList = testLoadGrantFundList.readList();
    int actualLength = testReadGrantFundList.size();

    //Test variables to see if the default Sort Order for is saved and read correctly.
    //Tested by using the length of the QList<QStringList> stored in the .dat file
    int failLength = 0;
    bool actualResult = false;
    bool expectedResult = true;

    //If the QSortListIO class is not able to save correctly, then the .dat file will store a
    //QList<QStringList> with a length of 0 (failure).
    if(actualLength != failLength){
        //Set the expected test variable to true to pass the Test.
        actualResult = true;
    }

    QCOMPARE(actualResult, expectedResult);
}




