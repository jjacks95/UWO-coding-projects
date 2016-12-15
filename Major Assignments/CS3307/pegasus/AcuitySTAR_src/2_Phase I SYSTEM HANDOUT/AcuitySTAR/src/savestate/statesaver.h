#ifndef STATESAVER_H
#define STATESAVER_H

#include <string>
#include <fstream>
#include <stdio.h>

class StateSaver
{
    std::string pubFile, presFile, teachFile, grantFile;
    int startYear;
    int endYear;

public:
    StateSaver();
    int loadState();
    int saveState();
    int clearState();
    int getStartYear();
    int getEndYear();
    void setStartYear(int year);
    void setEndYear(int year);
    void setPubFile(std::string path);
    void setPresFile(std::string path);
    void setTeachFile(std::string path);
    void setGrantFile(std::string path);
    std::string getPubFile();
    std::string getPresFile();
    std::string getTeachFile();
    std::string getGrantFile();
};

#endif // STATESAVER_H
