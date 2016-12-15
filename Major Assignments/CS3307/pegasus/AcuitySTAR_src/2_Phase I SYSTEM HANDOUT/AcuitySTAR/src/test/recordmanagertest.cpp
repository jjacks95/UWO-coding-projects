#include "recordmanagertest.h"
#include "database/RecordsManager.h"
#include "database/CSVReader.h"
#include <vector>
#include <iostream>
#include <string>
#include <utility>

void RecordManagerTest::buildARecord()
{
    CSVReader reader("../Project Information/Sample Data/Presentations_sample.csv");
    std::vector<std::string> vStr = reader.getHeaders();
    BasicRecord *record = &vStr;
    RecordsManager* recman = new RecordsManager(record);
    bool check = false;
    if(!recman->getHeaders().empty()){
        check = true;
    }
    QCOMPARE(check, true);
}

void RecordManagerTest::checkHeaders()
{
    CSVReader reader("../Project Information/Sample Data/Presentations_sample.csv");
    std::vector<std::string> vStr = reader.getHeaders();
    BasicRecord *record = &vStr;
    RecordsManager* recman = new RecordsManager(record);
    std::vector<std::string> retVStr = recman->getHeaders();
    QCOMPARE(vStr,retVStr);
}

void RecordManagerTest::addFindRecord()
{
    CSVReader reader("../Project Information/Sample Data/Presentations_sample.csv");
    std::vector<std::string> vStr = reader.getHeaders();
    BasicRecord *record = &vStr;
    RecordsManager* recman = new RecordsManager(record);
    BasicRecord rec;
    rec.push_back("Test");
    recman->addRecord(2020,&rec);
    std::vector<BasicRecord*> vBasicR = recman->findRecord(2020);
    BasicRecord* retRec = vBasicR.at(0);
    QCOMPARE(rec,*retRec);
}

void RecordManagerTest::HeaderIndexCheck(){
    BasicRecord r1;
    r1.push_back("hello");
    r1.push_back("yo");
    r1.push_back("howdy");
    r1.push_back("hiya");
    RecordsManager* recman = new RecordsManager(&r1);
    QCOMPARE(recman->getHeaderIndex("hello"),0);
    QCOMPARE(recman->getHeaderIndex("yo"),1);
    QCOMPARE(recman->getHeaderIndex("howdy"),2);
    QCOMPARE(recman->getHeaderIndex("hiya"),3);
}

void RecordManagerTest::RangeRecords(){
    BasicRecord r1,r2,r3,r4;
    r1.push_back("hello");
    r2.push_back("yo");
    r3.push_back("howdy");
    r4.push_back("hiya");
    RecordsManager* recman = new RecordsManager(&r1);
    recman->addRecord(1,&r2);
    recman->addRecord(5,&r3);
    recman->addRecord(7,&r4);
    bool check = false;
    if (!recman->findRecordsInRange(1,6).empty()){
        check=true;
    }
    QCOMPARE(check,true);
}

void RecordManagerTest::ListTest(){
    int count = 4;
    std::string s1,s2,s3,s4;
    s1 = "hey";
    s2 = "hi";
    s3 = "hello";
    s4 = "howdy";
    BasicRecord record = {s1,s2,s3,s4};
    RecordsManager* recman = new RecordsManager(&record);
    std::vector<std::string> vStr = recman->list(count,s1.c_str(),s2.c_str(),s3.c_str(),s4.c_str());
    QCOMPARE(vStr.at(0),s1);
    QCOMPARE(vStr.at(1),s2);
    QCOMPARE(vStr.at(2),s3);
    QCOMPARE(vStr.at(3),s4);
}
