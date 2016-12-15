/**
  * A header file with function declarations for reading a .dat file and storing its contents within a
  * more readily usable QList<QStringList> as well as a function for storing the contents within a QList<QSortList>
  * into a .dat fileS
  */


#ifndef QSORTLISTIO_H
#define QSORTLISTIO_H

#include <string>

class QSortListIO
{
public:
    //Constructor declaration
    QSortListIO(std::string _filename);

    //Function declaration for taking a QList<QStringList> and storing it within a .dat file
    void saveList(QList<QStringList> sortFields);

    //Function declaration for reading through a .dat file and storing its contents into a
    //QList<QStringList>
    QList<QStringList> readList();
private:
    std::string filename;
};

#endif // QSORTLISTIO_H
