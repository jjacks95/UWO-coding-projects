/********************************************************************************
** Form generated from reading UI file 'selectedlistdisplay.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTEDLISTDISPLAY_H
#define UI_SELECTEDLISTDISPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListView>

QT_BEGIN_NAMESPACE

class Ui_selectedListDisplay
{
public:
    QListView *listView;

    void setupUi(QDialog *selectedListDisplay)
    {
        if (selectedListDisplay->objectName().isEmpty())
            selectedListDisplay->setObjectName(QStringLiteral("selectedListDisplay"));
        selectedListDisplay->resize(240, 320);
        listView = new QListView(selectedListDisplay);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setGeometry(QRect(10, 10, 221, 301));

        retranslateUi(selectedListDisplay);

        QMetaObject::connectSlotsByName(selectedListDisplay);
    } // setupUi

    void retranslateUi(QDialog *selectedListDisplay)
    {
        selectedListDisplay->setWindowTitle(QApplication::translate("selectedListDisplay", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class selectedListDisplay: public Ui_selectedListDisplay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTEDLISTDISPLAY_H
