#ifndef RECORDMANAGERTEST_H
#define RECORDMANAGERTEST_H

#include <QtTest/QtTest>

class RecordManagerTest: public QObject
{
    Q_OBJECT
private slots:
    void buildARecord();
    void checkHeaders();
    void addFindRecord();
    void HeaderIndexCheck();
    void RangeRecords();
    void ListTest();
};

#endif // RECORDMANAGERTEST_H
