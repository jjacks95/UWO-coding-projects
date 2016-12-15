/**
  * Author: Andy Lac
  * A header file to test functions implemented in the QSortListIO class.
  * This file contains function declarations for testing QSortListIO class' saveList function (creating a .dat file
  * given a QList<QStringList> of acceptable headers, making sure it was saved correctly in the .dat file by
  * iterating through a dummy QSortListIO and the QSortListIO from the .dat file)and readList function (1 test case
  * for each subject area).
  */

#ifndef TESTQSORTLIST_H
#define TESTQSORTLIST_H

#include <QAbstractItemModel>
#include <QtTest/QtTest>
#include <QDataStream>
#include <QFile>
#include <QStringList>


class TestQSortList : public QObject
{
    Q_OBJECT
private slots:
    //Test QSortListIO function for saving QList<QStringList> objects into .dat files
    void TestSaveList();

    //Test QSortListIO function for saving the correct values in the .dat file
    void TestSaveListContent();

    //Test QSortListIO function for reading one of each subject area .dat files.
    void TestReadTeachingList();
    void TestReadPresentationList();
    void TestReadPublicationsList();
    void TestReadGrantFundList();
};

#endif // TESTQSORTLIST_H
