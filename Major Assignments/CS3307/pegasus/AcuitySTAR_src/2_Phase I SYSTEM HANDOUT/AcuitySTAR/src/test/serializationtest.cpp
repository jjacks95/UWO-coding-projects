#include "serializationtest.h"
#include "savestate/statesaver.h"
#include <vector>
#include <iostream>
#include <string>
#include <utility>

void SerializationTest::testSaveState(){
    StateSaver sState;
    sState.setStartYear(1999);
    sState.setEndYear(2005);
    sState.setPubFile("PubFile");
    sState.setPresFile("PresFile");
    sState.setTeachFile("TeachFile");
    sState.setGrantFile("GrantFile");
    if ("PubFile" == sState.getPubFile()){
        QCOMPARE(1,1);
    }else{
        QCOMPARE(1,0);
    }
    if ("PresFile" == sState.getPresFile()){
        QCOMPARE(1,1);
    }else{
        QCOMPARE(1,0);
    }
    if ("TeachFile" == sState.getTeachFile()){
        QCOMPARE(1,1);
    }else{
        QCOMPARE(1,0);
    }
    if ("GrantFile" == sState.getGrantFile()){
        QCOMPARE(1,1);
    }else{
        QCOMPARE(1,0);
    }
    sState.saveState();
}

void SerializationTest::testLoadState(){
    StateSaver sState;
    sState.loadState();
    QCOMPARE(1999,sState.getStartYear());
    QCOMPARE(2005,sState.getEndYear());
    if ("PubFile" == sState.getPubFile()){
        QCOMPARE(1,1);
    }else{
        QCOMPARE(1,0);
    }
    if ("PresFile" == sState.getPresFile()){
        QCOMPARE(1,1);
    }else{
        QCOMPARE(1,0);
    }
    if ("TeachFile" == sState.getTeachFile()){
        QCOMPARE(1,1);
    }else{
        QCOMPARE(1,0);
    }
    if ("GrantFile" == sState.getGrantFile()){
        QCOMPARE(1,1);
    }else{
        QCOMPARE(1,0);
    }
}
