/**
  * Author: Andy Lac
  *
  *
  */

#include "UserSelectedList.h"
#include <exception>

/**
 * @brief UserSelectedList::UserSelectedList
 * @param size
 * Constructor to build a vector of an inputed size.
 */
UserSelectedList::UserSelectedList()
{

}

/**
 * @brief UserSelectedList::insertIndex
 * @param index
 * Stores the index of a selected data entry from the QTreeView.
 */
void UserSelectedList::insertIndex(const QModelIndex index){
        this->userSelectedList.push_back(index);
}

/**
 * @brief UserSelectedList::deleteIndex
 * @param index
 * Deletes the stored index from the vector, if it exists.
 */
void UserSelectedList::deleteIndex(QModelIndex index){
    //Check to see if the list has indices to remove from the list.
    if(assertNotEmpty(this->getUserSelectedList())){
        int position = this->searchSelectedList(index);
        if(position != -1){
            this->userSelectedList.remove(position);
        }
    }
}

/**
 * @brief UserSelectedList::undoLastAddedIndex
 * Removes the last QModelIndex stored in the userSelectedList
 */
void UserSelectedList::undoLastAddedIndex(){
    if(assertNotEmpty(this->getUserSelectedList())){
        this->userSelectedList.pop_back();
    }
}

/**
 * @brief UserSelectedList::searchSelectedList
 * @param index
 * Searches the list for the given index and deletes the index in the list if it is found.
 */
int UserSelectedList::searchSelectedList(const QModelIndex index){
    //If the userSelectedList is empty
    int position = -1;
    if(!assertNotEmpty(this->getUserSelectedList())){
        return position;
    }
    else{
        QString clickedName = index.data(Qt::DisplayRole).toString();
        QVector<QModelIndex> tempList = this->getUserSelectedList();
        for(int pos = 0; pos < tempList.size(); pos++){
            if(clickedName == tempList[pos].data(Qt::DisplayRole).toString()){
                position = pos;
                break;
            }
        }
        return position;
    }
}

/**
 * @brief UserSelectedList::clearSelectedList
 * Clears all indices in the list
 */
void UserSelectedList::clearSelectedList(){
    this->userSelectedList.clear();
}

/**
 * @brief UserSelectedList::getUserSelectedList
 * @return the vector that stores the user selected indices
 */
QVector<QModelIndex> UserSelectedList::getUserSelectedList(){
    return this->userSelectedList;
}

/**
 * @brief UserSelectedList::setUserSelectedList
 * @param newList
 * Sets a new vector that stores QModelIndices as the UserSelectedList
 */
void UserSelectedList::setUserSelectedList(QVector<QModelIndex> newList){
    this->userSelectedList = newList;
}


/**
 * @brief UserSelectedList::assertNotEmpty
 * @param testList
 * @return true or false - Depending on if the UserSelectedList is empty (False) or not (True)
 */
bool UserSelectedList::assertNotEmpty(QVector<QModelIndex> testList){
    if(testList.size() != 0){
        return true;
    }
    else{
        return false;
    }
}
