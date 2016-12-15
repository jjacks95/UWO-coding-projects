#include "statesaver.h"
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <QDate>
#include <QDebug>

StateSaver::StateSaver()
{
    teachFile = "";
    pubFile  = "";
    presFile  = "";
    grantFile  = "";
    startYear  = 1950;
    endYear = QDate::currentDate().year();
}


int StateSaver::loadState(){
    std::ifstream file("savestate.txt");
    if (file){
    std::string line;
    getline(file, line);
    startYear  = stoi(line);
    getline(file, line);
    endYear = stoi(line);
    getline(file, line);
    teachFile = line;
    getline(file, line);
    pubFile  = line;
    getline(file, line);
    presFile  = line;
    getline(file, line);
    grantFile  = line;
    return 0;
    }
    else return 1;
}

int StateSaver::saveState(){
    std::ifstream f("savestate.txt");
    if (f.good()){
    std::ofstream file("savestate.txt");
    if(file){
        file << startYear << "\n";
        file << endYear << "\n";
        file << teachFile << "\n";
        file << pubFile << "\n";
        file << presFile << "\n";
        file << grantFile << "\n";
        return 0;
    }
    }
    return 1;
}

int StateSaver::clearState(){
    int ret = remove("savestate.txt");
    return ret;
}

int StateSaver::getStartYear(){
    return startYear;
}

int StateSaver::getEndYear(){
    return endYear;
}

void StateSaver::setStartYear(int year){
    startYear = year;
    return;
}

void StateSaver::setEndYear(int year){
    endYear = year;
    return;
}

void StateSaver::setPubFile(std::string path){
    pubFile = path;
    return;
}

void StateSaver::setPresFile(std::string path){
    presFile = path;
    return;
}

void StateSaver::setTeachFile(std::string path){
    teachFile = path;
    return;
}

void StateSaver::setGrantFile(std::string path){
    grantFile = path;
    return;
}

std::string StateSaver::getPubFile(){
    return pubFile;
}

std::string StateSaver::getPresFile(){
    return presFile;
}

std::string StateSaver::getTeachFile(){
    return teachFile;
}

std::string StateSaver::getGrantFile(){
    return grantFile;
}
