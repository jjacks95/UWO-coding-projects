#include <iostream>
#include <stdio.h>
#include <QApplication>
#include <QTreeView>

#include <qtestcase.h>
#include "gui/mainwindow.h"
#include "test/testingcsvreader.h"
#include "test/testqsortlist.h"
#include "test/recordmanagertest.h"
#include "test/serializationtest.h"
#include <stdexcept>

using namespace std;

int main(int argc, char *argv[]) {
    int test = 0;

    if (test) {
        //Run Qt Unit Tests for TestingCSVReader file
        TestingCSVReader *testingCSVReader = new TestingCSVReader();
        QTest::qExec(testingCSVReader);

        //Run Qt Unit Tests for TestQSortList file
        TestQSortList *testQSortList = new TestQSortList();
        QTest::qExec(testQSortList);

        //Run Qt Unit Tests for RecordManagerTest file
        RecordManagerTest *tester = new RecordManagerTest();
        QTest::qExec(tester);

        SerializationTest *testSerial = new SerializationTest();
        QTest::qExec(testSerial);
    }

    QApplication app(argc, argv);
    MainWindow w;
    w.show();

    return app.exec();
}
