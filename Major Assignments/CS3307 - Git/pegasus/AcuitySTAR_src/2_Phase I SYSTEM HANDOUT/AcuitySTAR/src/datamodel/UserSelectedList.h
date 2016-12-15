#ifndef USERSELECTEDLIST_H
#define USERSELECTEDLIST_H
#include <QModelIndex>
#include <QVector>
#include <string>
#include <QAbstractItemModel>


class UserSelectedList
{
    public:
        UserSelectedList();
        void insertIndex(const QModelIndex index);
        void deleteIndex(QModelIndex index);
        int searchSelectedList(const QModelIndex index);
        void clearSelectedList();
        void undoLastAddedIndex();
        QVector<QModelIndex> getUserSelectedList();
        void setUserSelectedList(QVector<QModelIndex> newList);
    private:
        QVector<QModelIndex> userSelectedList;
        bool assertNotEmpty(QVector<QModelIndex> inputList);
};

#endif // USERSELECTEDLIST_H
