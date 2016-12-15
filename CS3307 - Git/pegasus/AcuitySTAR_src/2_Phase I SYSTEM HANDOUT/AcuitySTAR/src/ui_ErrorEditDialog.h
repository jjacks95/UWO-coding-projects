/********************************************************************************
** Form generated from reading UI file 'ErrorEditDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ERROREDITDIALOG_H
#define UI_ERROREDITDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_ErrorEditDialog
{
public:
    QGridLayout *gridLayout;
    QPushButton *NextError;
    QPushButton *PreviousError;
    QLabel *ErrorCounterDescription;
    QPushButton *cancel;
    QLCDNumber *ErrorCounter;
    QPushButton *save;
    QTableWidget *tableWidget;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *ErrorEditDialog)
    {
        if (ErrorEditDialog->objectName().isEmpty())
            ErrorEditDialog->setObjectName(QStringLiteral("ErrorEditDialog"));
        ErrorEditDialog->resize(810, 483);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icon32.ico"), QSize(), QIcon::Normal, QIcon::Off);
        ErrorEditDialog->setWindowIcon(icon);
        gridLayout = new QGridLayout(ErrorEditDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        NextError = new QPushButton(ErrorEditDialog);
        NextError->setObjectName(QStringLiteral("NextError"));

        gridLayout->addWidget(NextError, 4, 2, 1, 1);

        PreviousError = new QPushButton(ErrorEditDialog);
        PreviousError->setObjectName(QStringLiteral("PreviousError"));

        gridLayout->addWidget(PreviousError, 4, 1, 1, 1);

        ErrorCounterDescription = new QLabel(ErrorEditDialog);
        ErrorCounterDescription->setObjectName(QStringLiteral("ErrorCounterDescription"));
        ErrorCounterDescription->setFrameShape(QFrame::NoFrame);

        gridLayout->addWidget(ErrorCounterDescription, 3, 2, 1, 1);

        cancel = new QPushButton(ErrorEditDialog);
        cancel->setObjectName(QStringLiteral("cancel"));

        gridLayout->addWidget(cancel, 4, 7, 1, 1);

        ErrorCounter = new QLCDNumber(ErrorEditDialog);
        ErrorCounter->setObjectName(QStringLiteral("ErrorCounter"));
        QPalette palette;
        QBrush brush(QColor(255, 102, 102, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        QBrush brush2(QColor(127, 127, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        ErrorCounter->setPalette(palette);
        ErrorCounter->setFrameShape(QFrame::Box);
        ErrorCounter->setFrameShadow(QFrame::Plain);
        ErrorCounter->setLineWidth(2);
        ErrorCounter->setMidLineWidth(0);
        ErrorCounter->setSmallDecimalPoint(false);
        ErrorCounter->setDigitCount(7);
        ErrorCounter->setSegmentStyle(QLCDNumber::Flat);

        gridLayout->addWidget(ErrorCounter, 3, 1, 1, 1);

        save = new QPushButton(ErrorEditDialog);
        save->setObjectName(QStringLiteral("save"));
        save->setMaximumSize(QSize(798, 16777215));

        gridLayout->addWidget(save, 4, 6, 1, 1);

        tableWidget = new QTableWidget(ErrorEditDialog);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setAutoFillBackground(false);

        gridLayout->addWidget(tableWidget, 0, 0, 1, 9);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 4, 5, 1, 1);


        retranslateUi(ErrorEditDialog);

        QMetaObject::connectSlotsByName(ErrorEditDialog);
    } // setupUi

    void retranslateUi(QDialog *ErrorEditDialog)
    {
        ErrorEditDialog->setWindowTitle(QApplication::translate("ErrorEditDialog", "Edit Erroneous Fields", 0));
        NextError->setText(QApplication::translate("ErrorEditDialog", "Next Error", 0));
        PreviousError->setText(QApplication::translate("ErrorEditDialog", "Previous Error", 0));
        ErrorCounterDescription->setText(QApplication::translate("ErrorEditDialog", "Remaining Errors", 0));
        cancel->setText(QApplication::translate("ErrorEditDialog", "Cancel", 0));
        save->setText(QApplication::translate("ErrorEditDialog", "Save", 0));
    } // retranslateUi

};

namespace Ui {
    class ErrorEditDialog: public Ui_ErrorEditDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ERROREDITDIALOG_H
