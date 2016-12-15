#ifndef SERIALIZATIONTEST_H
#define SERIALIZATIONTEST_H

#include <QtTest/QtTest>

class SerializationTest: public QObject
{
    Q_OBJECT
private slots:
    void testSaveState();
    void testLoadState();
};

#endif // SERIALIZATIONTEST_H
