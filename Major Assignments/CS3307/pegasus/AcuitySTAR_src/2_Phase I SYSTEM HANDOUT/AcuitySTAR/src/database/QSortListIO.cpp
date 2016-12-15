/**
  * The .cpp file for the QSortListIO header file.
  * This file contains the implementation of the funcion declarations found in QSortListIO.h
  * The functionality of this class is to save the user's New Sort Order by storing the user's Sort Order into a
  * .dat file. If the user were to load a subject area CSV file, then the appropriate .dat file will be loaded
  * so that the user can use the Sort Orders they previously created.
  */

#include <QDataStream>
#include <QFile>
#include <QStringList>

#include "QSortListIO.h"

/**
 * @brief QSortListIO::QSortListIO
 * @param _filename
 * Constructor to read/write sort lists into a file
 */
QSortListIO::QSortListIO(std::string _filename)
{
    filename = _filename;
}

/**
 * @brief QSortListIO::saveList
 * @param sortFields
 * Takes in an input of acceptable headers in the New Sort Order and stores the order they come in, into a .dat file
 * Allows the user to save New Sort Orders that will load when the user has loaded a CSV file
 */
void QSortListIO::saveList(QList<QStringList> sortFields)
{
    // open the file for writing
    QFile file(filename.c_str());
    file.open(QIODevice::WriteOnly);

    // we will serialize the data into the file
    QDataStream out(&file);

    // serialize the sort fields
    out << sortFields;

    // close the file
    file.close();
}

/**
 * @brief QSortListIO::readList
 * @return QList<QStringList>
 * Allows the QSortListIO instance to read through a .dat file and store all of its contents in the form
 * of a QList<QStringList>.
 * This function allows the serialized New Sort Orders to be loaded into the software.
 */
QList<QStringList> QSortListIO::readList()
{
    // open the file for reading
    QFile file(filename.c_str());
    file.open(QIODevice::ReadOnly);

    // read the data serialized from the file
    QDataStream in(&file);

    // extract sort fields
    QList<QStringList> sortFields;
    in >> sortFields;

    // close the file, we're done
    file.close();

    return sortFields;
}
