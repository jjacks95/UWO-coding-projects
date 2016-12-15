/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>
#include <gui/qcustomplot.h>
#include "gui/piechartwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLoad_file;
    QAction *actionClear_Session_for_Next_Run;
    QAction *actionClear_All_Sort_Orders;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QFrame *frame;
    QGridLayout *gridLayout_4;
    QLabel *logo_label;
    QFrame *date_filter_frame;
    QGridLayout *gridLayout_5;
    QLabel *start_label;
    QLabel *end_label;
    QDateEdit *FromDate;
    QSpacerItem *horizontalSpacer_3;
    QDateEdit *ToDate;
    QSpacerItem *verticalSpacer;
    QTabWidget *categoryTab;
    QWidget *tabTeach;
    QGridLayout *gridLayout_7;
    QPushButton *teachGraphList;
    QFrame *teachChartFrame;
    QGridLayout *gridLayout_21;
    QStackedWidget *teach_graph_stackedWidget;
    QWidget *teach_pie_page;
    QGridLayout *gridLayout_10;
    PieChartWidget *teachPieChart;
    QGridLayout *_5;
    QListWidget *teachPieList;
    QWidget *teach_bar_page;
    QGridLayout *gridLayout_13;
    QCustomPlot *teachBarChart;
    QGridLayout *_9;
    QWidget *teach_line_page;
    QGridLayout *gridLayout_22;
    QCustomPlot *teachLineChart;
    QWidget *teach_scatter_page;
    QGridLayout *gridLayout_24;
    QCustomPlot *teachScatterChart;
    QLabel *teachGraphTitle;
    QSpacerItem *horizontalSpacer_26;
    QLineEdit *teach_filter_from;
    QLineEdit *teach_filter_to;
    QFrame *line_7;
    QLabel *teach_to_label;
    QPushButton *teachingClearList;
    QLCDNumber *teachingListCounter;
    QPushButton *teachingUndoIndex;
    QPushButton *teachingAddIndex;
    QSpacerItem *horizontalSpacer_27;
    QSpacerItem *horizontalSpacer_19;
    QTreeView *teachTreeView;
    QRadioButton *teach_scatter_button;
    QPushButton *teach_delete_sort;
    QLabel *teach_file_label;
    QRadioButton *teach_bar_button;
    QLabel *teach_sort_label;
    QLabel *teach_filter_label;
    QSpacerItem *horizontalSpacer_8;
    QComboBox *teach_sort;
    QRadioButton *teach_pie_button;
    QPushButton *teach_new_sort;
    QLabel *teach_filter;
    QPushButton *teach_load_file;
    QToolButton *teachPrintButton;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_21;
    QFrame *line_8;
    QToolButton *teachExportButton;
    QRadioButton *teach_line_button;
    QPushButton *teachListContentView;
    QWidget *tabPub;
    QGridLayout *gridLayout_3;
    QFrame *pubChartFrame;
    QGridLayout *gridLayout_20;
    QLabel *pubGraphTitle;
    QStackedWidget *pub_graph_stackedWidget;
    QWidget *pub_pie_page;
    QGridLayout *gridLayout_18;
    PieChartWidget *pubPieChart;
    QGridLayout *_12;
    QListWidget *pubPieList;
    QWidget *pub_bar_page;
    QGridLayout *gridLayout_19;
    QCustomPlot *pubBarChart;
    QGridLayout *_13;
    QWidget *pub_line_page;
    QGridLayout *gridLayout_23;
    QCustomPlot *pubLineChart;
    QWidget *pub_scatter_page;
    QGridLayout *gridLayout_25;
    QCustomPlot *pubScatterChart;
    QPushButton *pubClearList;
    QSpacerItem *horizontalSpacer_35;
    QTreeView *pubTreeView;
    QPushButton *pub_new_sort;
    QLabel *pub_filter_label;
    QToolButton *pubPrintButton;
    QPushButton *pub_delete_sort;
    QLabel *pub_filter;
    QComboBox *pub_sort;
    QSpacerItem *horizontalSpacer_29;
    QLabel *pub_file_label;
    QSpacerItem *horizontalSpacer_4;
    QRadioButton *pub_pie_button;
    QSpacerItem *horizontalSpacer_7;
    QLabel *pub_sort_label;
    QFrame *line_5;
    QSpacerItem *horizontalSpacer_22;
    QLabel *pub_to_label;
    QLineEdit *pub_filter_from;
    QPushButton *pub_load_file;
    QLineEdit *pub_filter_to;
    QFrame *line_6;
    QRadioButton *pub_line_button;
    QToolButton *pubExportButton;
    QRadioButton *pub_bar_button;
    QSpacerItem *horizontalSpacer_28;
    QLCDNumber *pubListCounter;
    QPushButton *pubAddIndex;
    QPushButton *pubUndoIndex;
    QRadioButton *pub_scatter_button;
    QPushButton *pubGraphList;
    QPushButton *pubListContentView;
    QWidget *tabPres;
    QGridLayout *gridLayout_2;
    QFrame *presChartFrame;
    QGridLayout *gridLayout_17;
    QLabel *presGraphTitle;
    QStackedWidget *pres_graph_stackedWidget;
    QWidget *pres_pie_page;
    QGridLayout *gridLayout_11;
    PieChartWidget *presPieChart;
    QGridLayout *_6;
    QListWidget *presPieList;
    QWidget *pres_bar_page;
    QGridLayout *gridLayout_8;
    QCustomPlot *presBarChart;
    QGridLayout *_8;
    QWidget *pres_line_page;
    QGridLayout *gridLayout_14;
    QCustomPlot *presLineChart;
    QWidget *pres_scatter_page;
    QGridLayout *gridLayout_26;
    QCustomPlot *presScatterChart;
    QSpacerItem *horizontalSpacer_23;
    QPushButton *pres_delete_sort;
    QPushButton *pres_load_file;
    QTreeView *presTreeView;
    QSpacerItem *horizontalSpacer_31;
    QFrame *line_4;
    QSpacerItem *horizontalSpacer_25;
    QLabel *pres_filter;
    QToolButton *presPrintButton;
    QLabel *pres_filter_label;
    QFrame *line_3;
    QComboBox *pres_sort;
    QSpacerItem *horizontalSpacer_16;
    QLabel *pres_sort_label;
    QLabel *pres_to_label;
    QSpacerItem *horizontalSpacer_30;
    QRadioButton *pres_pie_button;
    QPushButton *pres_new_sort;
    QLabel *pres_file_label;
    QLineEdit *pres_filter_from;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *pres_filter_to;
    QRadioButton *pres_bar_button;
    QRadioButton *pres_line_button;
    QToolButton *presExportButton;
    QPushButton *presUndoIndex;
    QPushButton *presAddIndex;
    QPushButton *presClearList;
    QLCDNumber *presListCounter;
    QRadioButton *pres_scatter_button;
    QPushButton *presGraphList;
    QPushButton *presListContentView;
    QWidget *tabFund;
    QGridLayout *gridLayout_6;
    QFrame *fundChartFrame;
    QGridLayout *gridLayout_16;
    QStackedWidget *fund_graph_stackedWidget;
    QWidget *fund_pie_page;
    QGridLayout *gridLayout_9;
    PieChartWidget *fundPieChart;
    QGridLayout *_4;
    QListWidget *fundPieList;
    QWidget *fund_bar_page;
    QGridLayout *gridLayout_15;
    QCustomPlot *fundBarChart;
    QGridLayout *_11;
    QWidget *fund_line_page;
    QGridLayout *gridLayout_12;
    QCustomPlot *fundLineChart;
    QWidget *fund_scatter_page;
    QGridLayout *gridLayout_27;
    QCustomPlot *fundScatterChart;
    QLabel *fundGraphTitle;
    QPushButton *fundsClearList;
    QLCDNumber *fundsListCounter;
    QPushButton *fundsUndoIndex;
    QPushButton *fundsAddIndex;
    QTreeView *fundTreeView;
    QPushButton *fund_new_sort;
    QLineEdit *fund_filter_from;
    QLabel *fund_filter_label;
    QFrame *line_2;
    QPushButton *fund_delete_sort;
    QLineEdit *fund_filter_to;
    QSpacerItem *horizontalSpacer_24;
    QRadioButton *fund_bar_button;
    QRadioButton *fund_line_button;
    QPushButton *fund_load_file;
    QSpacerItem *horizontalSpacer_5;
    QLabel *fund_sort_label;
    QFrame *line;
    QRadioButton *fund_pie_button;
    QLabel *fund_file_label;
    QSpacerItem *horizontalSpacer_33;
    QToolButton *fundPrintButton;
    QComboBox *fund_sort;
    QSpacerItem *horizontalSpacer_32;
    QLabel *fund_to_label;
    QLabel *fund_filter;
    QSpacerItem *horizontalSpacer_15;
    QToolButton *fundExportButton;
    QRadioButton *fund_scatter_button;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *fundGraphList;
    QPushButton *fundListContentView;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuFile;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1200, 1200);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(0, 0));
        MainWindow->setBaseSize(QSize(0, 0));
        MainWindow->setStyleSheet(QStringLiteral(""));
        actionLoad_file = new QAction(MainWindow);
        actionLoad_file->setObjectName(QStringLiteral("actionLoad_file"));
        actionLoad_file->setCheckable(false);
        actionClear_Session_for_Next_Run = new QAction(MainWindow);
        actionClear_Session_for_Next_Run->setObjectName(QStringLiteral("actionClear_Session_for_Next_Run"));
        actionClear_All_Sort_Orders = new QAction(MainWindow);
        actionClear_All_Sort_Orders->setObjectName(QStringLiteral("actionClear_All_Sort_Orders"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMinimumSize(QSize(1000, 650));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setMinimumSize(QSize(0, 0));
        frame->setAutoFillBackground(false);
        frame->setStyleSheet(QStringLiteral(""));
        gridLayout_4 = new QGridLayout(frame);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(12, 12, 12, 12);
        logo_label = new QLabel(frame);
        logo_label->setObjectName(QStringLiteral("logo_label"));
        logo_label->setStyleSheet(QStringLiteral("background: transparent"));
        logo_label->setPixmap(QPixmap(QString::fromUtf8("../logo.png")));
        logo_label->setAlignment(Qt::AlignCenter);
        logo_label->setMargin(5);

        gridLayout_4->addWidget(logo_label, 1, 1, 1, 1, Qt::AlignHCenter);

        date_filter_frame = new QFrame(frame);
        date_filter_frame->setObjectName(QStringLiteral("date_filter_frame"));
        date_filter_frame->setMaximumSize(QSize(16777215, 16777215));
        date_filter_frame->setStyleSheet(QStringLiteral("background-color: transparent"));
        gridLayout_5 = new QGridLayout(date_filter_frame);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(-1, 5, -1, 5);
        start_label = new QLabel(date_filter_frame);
        start_label->setObjectName(QStringLiteral("start_label"));
        start_label->setMinimumSize(QSize(70, 20));
        start_label->setStyleSheet(QStringLiteral("background-color:white"));
        start_label->setFrameShape(QFrame::Box);
        start_label->setFrameShadow(QFrame::Raised);
        start_label->setAlignment(Qt::AlignCenter);
        start_label->setMargin(0);

        gridLayout_5->addWidget(start_label, 1, 0, 1, 1);

        end_label = new QLabel(date_filter_frame);
        end_label->setObjectName(QStringLiteral("end_label"));
        end_label->setMinimumSize(QSize(70, 20));
        end_label->setStyleSheet(QStringLiteral("background-color: white"));
        end_label->setFrameShape(QFrame::Box);
        end_label->setFrameShadow(QFrame::Raised);
        end_label->setAlignment(Qt::AlignCenter);
        end_label->setMargin(0);

        gridLayout_5->addWidget(end_label, 1, 3, 1, 1);

        FromDate = new QDateEdit(date_filter_frame);
        FromDate->setObjectName(QStringLiteral("FromDate"));
        FromDate->setMinimumSize(QSize(100, 20));
        FromDate->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        FromDate->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(FromDate, 1, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(30, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_3, 1, 2, 1, 1);

        ToDate = new QDateEdit(date_filter_frame);
        ToDate->setObjectName(QStringLiteral("ToDate"));
        ToDate->setMinimumSize(QSize(100, 20));
        ToDate->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        ToDate->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(ToDate, 1, 4, 1, 1);


        gridLayout_4->addWidget(date_filter_frame, 3, 1, 1, 1, Qt::AlignHCenter);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_4->addItem(verticalSpacer, 6, 1, 1, 1);

        categoryTab = new QTabWidget(frame);
        categoryTab->setObjectName(QStringLiteral("categoryTab"));
        categoryTab->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Ignored, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(categoryTab->sizePolicy().hasHeightForWidth());
        categoryTab->setSizePolicy(sizePolicy2);
        categoryTab->setCursor(QCursor(Qt::ArrowCursor));
        categoryTab->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        categoryTab->setTabShape(QTabWidget::Rounded);
        categoryTab->setUsesScrollButtons(false);
        tabTeach = new QWidget();
        tabTeach->setObjectName(QStringLiteral("tabTeach"));
        tabTeach->setStyleSheet(QStringLiteral(""));
        gridLayout_7 = new QGridLayout(tabTeach);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        teachGraphList = new QPushButton(tabTeach);
        teachGraphList->setObjectName(QStringLiteral("teachGraphList"));
        teachGraphList->setEnabled(true);
        teachGraphList->setStyleSheet(QStringLiteral("background-color: rgb(204, 204, 204);"));

        gridLayout_7->addWidget(teachGraphList, 8, 7, 1, 1);

        teachChartFrame = new QFrame(tabTeach);
        teachChartFrame->setObjectName(QStringLiteral("teachChartFrame"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(teachChartFrame->sizePolicy().hasHeightForWidth());
        teachChartFrame->setSizePolicy(sizePolicy3);
        teachChartFrame->setFrameShape(QFrame::Box);
        teachChartFrame->setFrameShadow(QFrame::Sunken);
        teachChartFrame->setLineWidth(3);
        gridLayout_21 = new QGridLayout(teachChartFrame);
        gridLayout_21->setSpacing(6);
        gridLayout_21->setContentsMargins(11, 11, 11, 11);
        gridLayout_21->setObjectName(QStringLiteral("gridLayout_21"));
        teach_graph_stackedWidget = new QStackedWidget(teachChartFrame);
        teach_graph_stackedWidget->setObjectName(QStringLiteral("teach_graph_stackedWidget"));
        teach_graph_stackedWidget->setEnabled(true);
        sizePolicy3.setHeightForWidth(teach_graph_stackedWidget->sizePolicy().hasHeightForWidth());
        teach_graph_stackedWidget->setSizePolicy(sizePolicy3);
        teach_graph_stackedWidget->setMidLineWidth(0);
        teach_pie_page = new QWidget();
        teach_pie_page->setObjectName(QStringLiteral("teach_pie_page"));
        gridLayout_10 = new QGridLayout(teach_pie_page);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        teachPieChart = new PieChartWidget(teach_pie_page);
        teachPieChart->setObjectName(QStringLiteral("teachPieChart"));
        teachPieChart->setEnabled(true);
        sizePolicy3.setHeightForWidth(teachPieChart->sizePolicy().hasHeightForWidth());
        teachPieChart->setSizePolicy(sizePolicy3);
        teachPieChart->setMinimumSize(QSize(250, 0));
        teachPieChart->setMaximumSize(QSize(16777215, 16777215));
        teachPieChart->setFocusPolicy(Qt::TabFocus);
        teachPieChart->setLayoutDirection(Qt::LeftToRight);
        teachPieChart->setStyleSheet(QStringLiteral(""));
        _5 = new QGridLayout(teachPieChart);
        _5->setSpacing(0);
        _5->setContentsMargins(11, 11, 11, 11);
        _5->setObjectName(QStringLiteral("_5"));

        gridLayout_10->addWidget(teachPieChart, 0, 0, 1, 1);

        teachPieList = new QListWidget(teach_pie_page);
        teachPieList->setObjectName(QStringLiteral("teachPieList"));
        teachPieList->setMinimumSize(QSize(0, 0));
        teachPieList->setMaximumSize(QSize(16777215, 16777215));
        teachPieList->setBaseSize(QSize(0, 0));
        teachPieList->setFocusPolicy(Qt::NoFocus);
        teachPieList->setLayoutDirection(Qt::LeftToRight);
        teachPieList->setFrameShape(QFrame::NoFrame);
        teachPieList->setSelectionMode(QAbstractItemView::NoSelection);

        gridLayout_10->addWidget(teachPieList, 0, 1, 1, 1);

        teach_graph_stackedWidget->addWidget(teach_pie_page);
        teach_bar_page = new QWidget();
        teach_bar_page->setObjectName(QStringLiteral("teach_bar_page"));
        sizePolicy3.setHeightForWidth(teach_bar_page->sizePolicy().hasHeightForWidth());
        teach_bar_page->setSizePolicy(sizePolicy3);
        gridLayout_13 = new QGridLayout(teach_bar_page);
        gridLayout_13->setSpacing(6);
        gridLayout_13->setContentsMargins(11, 11, 11, 11);
        gridLayout_13->setObjectName(QStringLiteral("gridLayout_13"));
        teachBarChart = new QCustomPlot(teach_bar_page);
        teachBarChart->setObjectName(QStringLiteral("teachBarChart"));
        teachBarChart->setEnabled(true);
        sizePolicy3.setHeightForWidth(teachBarChart->sizePolicy().hasHeightForWidth());
        teachBarChart->setSizePolicy(sizePolicy3);
        teachBarChart->setMinimumSize(QSize(250, 0));
        teachBarChart->setMaximumSize(QSize(16777215, 16777215));
        teachBarChart->setFocusPolicy(Qt::TabFocus);
        teachBarChart->setLayoutDirection(Qt::LeftToRight);
        teachBarChart->setStyleSheet(QStringLiteral(""));
        _9 = new QGridLayout(teachBarChart);
        _9->setSpacing(0);
        _9->setContentsMargins(11, 11, 11, 11);
        _9->setObjectName(QStringLiteral("_9"));

        gridLayout_13->addWidget(teachBarChart, 1, 0, 1, 1);

        teach_graph_stackedWidget->addWidget(teach_bar_page);
        teach_line_page = new QWidget();
        teach_line_page->setObjectName(QStringLiteral("teach_line_page"));
        gridLayout_22 = new QGridLayout(teach_line_page);
        gridLayout_22->setSpacing(6);
        gridLayout_22->setContentsMargins(11, 11, 11, 11);
        gridLayout_22->setObjectName(QStringLiteral("gridLayout_22"));
        teachLineChart = new QCustomPlot(teach_line_page);
        teachLineChart->setObjectName(QStringLiteral("teachLineChart"));
        sizePolicy3.setHeightForWidth(teachLineChart->sizePolicy().hasHeightForWidth());
        teachLineChart->setSizePolicy(sizePolicy3);

        gridLayout_22->addWidget(teachLineChart, 0, 0, 1, 1);

        teach_graph_stackedWidget->addWidget(teach_line_page);
        teach_scatter_page = new QWidget();
        teach_scatter_page->setObjectName(QStringLiteral("teach_scatter_page"));
        gridLayout_24 = new QGridLayout(teach_scatter_page);
        gridLayout_24->setSpacing(6);
        gridLayout_24->setContentsMargins(11, 11, 11, 11);
        gridLayout_24->setObjectName(QStringLiteral("gridLayout_24"));
        teachScatterChart = new QCustomPlot(teach_scatter_page);
        teachScatterChart->setObjectName(QStringLiteral("teachScatterChart"));

        gridLayout_24->addWidget(teachScatterChart, 0, 0, 1, 1);

        teach_graph_stackedWidget->addWidget(teach_scatter_page);

        gridLayout_21->addWidget(teach_graph_stackedWidget, 1, 0, 1, 1);

        teachGraphTitle = new QLabel(teachChartFrame);
        teachGraphTitle->setObjectName(QStringLiteral("teachGraphTitle"));
        teachGraphTitle->setStyleSheet(QStringLiteral("font: bold 12px;"));
        teachGraphTitle->setAlignment(Qt::AlignCenter);

        gridLayout_21->addWidget(teachGraphTitle, 0, 0, 1, 1);


        gridLayout_7->addWidget(teachChartFrame, 7, 7, 1, 7);

        horizontalSpacer_26 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_26, 3, 9, 1, 1);

        teach_filter_from = new QLineEdit(tabTeach);
        teach_filter_from->setObjectName(QStringLiteral("teach_filter_from"));
        teach_filter_from->setEnabled(false);
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(teach_filter_from->sizePolicy().hasHeightForWidth());
        teach_filter_from->setSizePolicy(sizePolicy4);
        teach_filter_from->setMaximumSize(QSize(60, 16777215));
        teach_filter_from->setMaxLength(1);
        teach_filter_from->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(teach_filter_from, 5, 3, 1, 1);

        teach_filter_to = new QLineEdit(tabTeach);
        teach_filter_to->setObjectName(QStringLiteral("teach_filter_to"));
        teach_filter_to->setEnabled(false);
        sizePolicy4.setHeightForWidth(teach_filter_to->sizePolicy().hasHeightForWidth());
        teach_filter_to->setSizePolicy(sizePolicy4);
        teach_filter_to->setMaximumSize(QSize(60, 16777215));
        teach_filter_to->setMaxLength(1);
        teach_filter_to->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(teach_filter_to, 5, 5, 1, 1);

        line_7 = new QFrame(tabTeach);
        line_7->setObjectName(QStringLiteral("line_7"));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);

        gridLayout_7->addWidget(line_7, 4, 0, 1, 14);

        teach_to_label = new QLabel(tabTeach);
        teach_to_label->setObjectName(QStringLiteral("teach_to_label"));
        teach_to_label->setEnabled(false);

        gridLayout_7->addWidget(teach_to_label, 5, 4, 1, 1);

        teachingClearList = new QPushButton(tabTeach);
        teachingClearList->setObjectName(QStringLiteral("teachingClearList"));
        teachingClearList->setStyleSheet(QStringLiteral("background-color: rgb(204, 204, 204);"));

        gridLayout_7->addWidget(teachingClearList, 8, 1, 1, 1);

        teachingListCounter = new QLCDNumber(tabTeach);
        teachingListCounter->setObjectName(QStringLiteral("teachingListCounter"));

        gridLayout_7->addWidget(teachingListCounter, 8, 0, 1, 1);

        teachingUndoIndex = new QPushButton(tabTeach);
        teachingUndoIndex->setObjectName(QStringLiteral("teachingUndoIndex"));
        teachingUndoIndex->setStyleSheet(QStringLiteral("background-color: rgb(204, 204, 204);"));

        gridLayout_7->addWidget(teachingUndoIndex, 8, 5, 1, 1);

        teachingAddIndex = new QPushButton(tabTeach);
        teachingAddIndex->setObjectName(QStringLiteral("teachingAddIndex"));
        teachingAddIndex->setStyleSheet(QStringLiteral("background-color: rgb(204, 204, 204);"));

        gridLayout_7->addWidget(teachingAddIndex, 8, 6, 1, 1);

        horizontalSpacer_27 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_27, 3, 11, 1, 1);

        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_19, 3, 10, 1, 1);

        teachTreeView = new QTreeView(tabTeach);
        teachTreeView->setObjectName(QStringLiteral("teachTreeView"));
        sizePolicy3.setHeightForWidth(teachTreeView->sizePolicy().hasHeightForWidth());
        teachTreeView->setSizePolicy(sizePolicy3);
        teachTreeView->setStyleSheet(QStringLiteral(""));
        teachTreeView->setFrameShape(QFrame::NoFrame);
        teachTreeView->setFrameShadow(QFrame::Sunken);

        gridLayout_7->addWidget(teachTreeView, 7, 0, 1, 7);

        teach_scatter_button = new QRadioButton(tabTeach);
        teach_scatter_button->setObjectName(QStringLiteral("teach_scatter_button"));
        teach_scatter_button->setEnabled(false);

        gridLayout_7->addWidget(teach_scatter_button, 5, 10, 1, 1);

        teach_delete_sort = new QPushButton(tabTeach);
        teach_delete_sort->setObjectName(QStringLiteral("teach_delete_sort"));
        teach_delete_sort->setEnabled(false);
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(teach_delete_sort->sizePolicy().hasHeightForWidth());
        teach_delete_sort->setSizePolicy(sizePolicy5);
        teach_delete_sort->setStyleSheet(QStringLiteral("background-color: rgb(204, 204, 204);"));

        gridLayout_7->addWidget(teach_delete_sort, 3, 2, 1, 1);

        teach_file_label = new QLabel(tabTeach);
        teach_file_label->setObjectName(QStringLiteral("teach_file_label"));
        QSizePolicy sizePolicy6(QSizePolicy::Ignored, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(teach_file_label->sizePolicy().hasHeightForWidth());
        teach_file_label->setSizePolicy(sizePolicy6);

        gridLayout_7->addWidget(teach_file_label, 0, 1, 1, 11);

        teach_bar_button = new QRadioButton(tabTeach);
        teach_bar_button->setObjectName(QStringLiteral("teach_bar_button"));
        teach_bar_button->setEnabled(false);

        gridLayout_7->addWidget(teach_bar_button, 5, 8, 1, 1);

        teach_sort_label = new QLabel(tabTeach);
        teach_sort_label->setObjectName(QStringLiteral("teach_sort_label"));
        teach_sort_label->setEnabled(false);

        gridLayout_7->addWidget(teach_sort_label, 3, 0, 1, 1);

        teach_filter_label = new QLabel(tabTeach);
        teach_filter_label->setObjectName(QStringLiteral("teach_filter_label"));
        teach_filter_label->setEnabled(false);

        gridLayout_7->addWidget(teach_filter_label, 5, 0, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_8, 3, 7, 1, 1);

        teach_sort = new QComboBox(tabTeach);
        teach_sort->setObjectName(QStringLiteral("teach_sort"));
        teach_sort->setEnabled(false);
        sizePolicy4.setHeightForWidth(teach_sort->sizePolicy().hasHeightForWidth());
        teach_sort->setSizePolicy(sizePolicy4);
        teach_sort->setMinimumSize(QSize(120, 0));

        gridLayout_7->addWidget(teach_sort, 3, 1, 1, 1);

        teach_pie_button = new QRadioButton(tabTeach);
        teach_pie_button->setObjectName(QStringLiteral("teach_pie_button"));
        teach_pie_button->setEnabled(false);

        gridLayout_7->addWidget(teach_pie_button, 5, 7, 1, 1);

        teach_new_sort = new QPushButton(tabTeach);
        teach_new_sort->setObjectName(QStringLiteral("teach_new_sort"));
        teach_new_sort->setEnabled(false);
        sizePolicy4.setHeightForWidth(teach_new_sort->sizePolicy().hasHeightForWidth());
        teach_new_sort->setSizePolicy(sizePolicy4);
        teach_new_sort->setMinimumSize(QSize(150, 0));
        teach_new_sort->setStyleSheet(QStringLiteral("background-color: rgb(204, 204, 204);"));
        teach_new_sort->setCheckable(false);
        teach_new_sort->setChecked(false);
        teach_new_sort->setAutoDefault(false);

        gridLayout_7->addWidget(teach_new_sort, 3, 3, 1, 3);

        teach_filter = new QLabel(tabTeach);
        teach_filter->setObjectName(QStringLiteral("teach_filter"));
        teach_filter->setEnabled(false);

        gridLayout_7->addWidget(teach_filter, 5, 1, 1, 2);

        teach_load_file = new QPushButton(tabTeach);
        teach_load_file->setObjectName(QStringLiteral("teach_load_file"));
        teach_load_file->setMinimumSize(QSize(100, 0));
        teach_load_file->setAutoFillBackground(false);
        teach_load_file->setStyleSheet(QStringLiteral("background-color: rgb(204, 204, 204);"));

        gridLayout_7->addWidget(teach_load_file, 0, 0, 1, 1);

        teachPrintButton = new QToolButton(tabTeach);
        teachPrintButton->setObjectName(QStringLiteral("teachPrintButton"));
        sizePolicy5.setHeightForWidth(teachPrintButton->sizePolicy().hasHeightForWidth());
        teachPrintButton->setSizePolicy(sizePolicy5);
        teachPrintButton->setLayoutDirection(Qt::LeftToRight);
        teachPrintButton->setStyleSheet(QStringLiteral("background-color: rgb(204, 204, 204);"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/printer.png"), QSize(), QIcon::Normal, QIcon::On);
        teachPrintButton->setIcon(icon);
        teachPrintButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        gridLayout_7->addWidget(teachPrintButton, 0, 13, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer, 3, 6, 1, 1);

        horizontalSpacer_21 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_21, 3, 8, 1, 1);

        line_8 = new QFrame(tabTeach);
        line_8->setObjectName(QStringLiteral("line_8"));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);

        gridLayout_7->addWidget(line_8, 1, 0, 1, 14);

        teachExportButton = new QToolButton(tabTeach);
        teachExportButton->setObjectName(QStringLiteral("teachExportButton"));
        sizePolicy5.setHeightForWidth(teachExportButton->sizePolicy().hasHeightForWidth());
        teachExportButton->setSizePolicy(sizePolicy5);
        teachExportButton->setLayoutDirection(Qt::LeftToRight);
        teachExportButton->setStyleSheet(QStringLiteral("background-color: rgb(204, 204, 204);"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Pdf.svg"), QSize(), QIcon::Normal, QIcon::Off);
        teachExportButton->setIcon(icon1);
        teachExportButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        gridLayout_7->addWidget(teachExportButton, 0, 12, 1, 1);

        teach_line_button = new QRadioButton(tabTeach);
        teach_line_button->setObjectName(QStringLiteral("teach_line_button"));
        teach_line_button->setEnabled(false);

        gridLayout_7->addWidget(teach_line_button, 5, 9, 1, 1);

        teachListContentView = new QPushButton(tabTeach);
        teachListContentView->setObjectName(QStringLiteral("teachListContentView"));
        teachListContentView->setStyleSheet(QStringLiteral("background-color: rgb(204, 204, 204);"));

        gridLayout_7->addWidget(teachListContentView, 8, 2, 1, 2);

        categoryTab->addTab(tabTeach, QString());
        tabPub = new QWidget();
        tabPub->setObjectName(QStringLiteral("tabPub"));
        gridLayout_3 = new QGridLayout(tabPub);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        pubChartFrame = new QFrame(tabPub);
        pubChartFrame->setObjectName(QStringLiteral("pubChartFrame"));
        sizePolicy3.setHeightForWidth(pubChartFrame->sizePolicy().hasHeightForWidth());
        pubChartFrame->setSizePolicy(sizePolicy3);
        pubChartFrame->setFrameShape(QFrame::Box);
        pubChartFrame->setFrameShadow(QFrame::Sunken);
        pubChartFrame->setLineWidth(3);
        gridLayout_20 = new QGridLayout(pubChartFrame);
        gridLayout_20->setSpacing(6);
        gridLayout_20->setContentsMargins(11, 11, 11, 11);
        gridLayout_20->setObjectName(QStringLiteral("gridLayout_20"));
        pubGraphTitle = new QLabel(pubChartFrame);
        pubGraphTitle->setObjectName(QStringLiteral("pubGraphTitle"));
        pubGraphTitle->setStyleSheet(QStringLiteral("font: bold 12px;"));
        pubGraphTitle->setAlignment(Qt::AlignCenter);

        gridLayout_20->addWidget(pubGraphTitle, 0, 0, 1, 1);

        pub_graph_stackedWidget = new QStackedWidget(pubChartFrame);
        pub_graph_stackedWidget->setObjectName(QStringLiteral("pub_graph_stackedWidget"));
        pub_graph_stackedWidget->setEnabled(true);
        sizePolicy3.setHeightForWidth(pub_graph_stackedWidget->sizePolicy().hasHeightForWidth());
        pub_graph_stackedWidget->setSizePolicy(sizePolicy3);
        pub_graph_stackedWidget->setMidLineWidth(0);
        pub_pie_page = new QWidget();
        pub_pie_page->setObjectName(QStringLiteral("pub_pie_page"));
        gridLayout_18 = new QGridLayout(pub_pie_page);
        gridLayout_18->setSpacing(6);
        gridLayout_18->setContentsMargins(11, 11, 11, 11);
        gridLayout_18->setObjectName(QStringLiteral("gridLayout_18"));
        pubPieChart = new PieChartWidget(pub_pie_page);
        pubPieChart->setObjectName(QStringLiteral("pubPieChart"));
        pubPieChart->setEnabled(true);
        sizePolicy3.setHeightForWidth(pubPieChart->sizePolicy().hasHeightForWidth());
        pubPieChart->setSizePolicy(sizePolicy3);
        pubPieChart->setMinimumSize(QSize(250, 0));
        pubPieChart->setMaximumSize(QSize(16777215, 16777215));
        pubPieChart->setFocusPolicy(Qt::TabFocus);
        pubPieChart->setLayoutDirection(Qt::LeftToRight);
        pubPieChart->setStyleSheet(QStringLiteral(""));
        _12 = new QGridLayout(pubPieChart);
        _12->setSpacing(0);
        _12->setContentsMargins(11, 11, 11, 11);
        _12->setObjectName(QStringLiteral("_12"));

        gridLayout_18->addWidget(pubPieChart, 1, 0, 1, 1);

        pubPieList = new QListWidget(pub_pie_page);
        pubPieList->setObjectName(QStringLiteral("pubPieList"));
        pubPieList->setMinimumSize(QSize(0, 0));
        pubPieList->setMaximumSize(QSize(16777215, 16777215));
        pubPieList->setBaseSize(QSize(0, 0));
        pubPieList->setFocusPolicy(Qt::NoFocus);
        pubPieList->setLayoutDirection(Qt::LeftToRight);
        pubPieList->setFrameShape(QFrame::NoFrame);
        pubPieList->setSelectionMode(QAbstractItemView::NoSelection);

        gridLayout_18->addWidget(pubPieList, 1, 1, 1, 1);

        pub_graph_stackedWidget->addWidget(pub_pie_page);
        pub_bar_page = new QWidget();
        pub_bar_page->setObjectName(QStringLiteral("pub_bar_page"));
        gridLayout_19 = new QGridLayout(pub_bar_page);
        gridLayout_19->setSpacing(6);
        gridLayout_19->setContentsMargins(11, 11, 11, 11);
        gridLayout_19->setObjectName(QStringLiteral("gridLayout_19"));
        pubBarChart = new QCustomPlot(pub_bar_page);
        pubBarChart->setObjectName(QStringLiteral("pubBarChart"));
        pubBarChart->setEnabled(true);
        sizePolicy3.setHeightForWidth(pubBarChart->sizePolicy().hasHeightForWidth());
        pubBarChart->setSizePolicy(sizePolicy3);
        pubBarChart->setMinimumSize(QSize(250, 0));
        pubBarChart->setMaximumSize(QSize(16777215, 16777215));
        pubBarChart->setFocusPolicy(Qt::TabFocus);
        pubBarChart->setLayoutDirection(Qt::LeftToRight);
        pubBarChart->setStyleSheet(QStringLiteral(""));
        _13 = new QGridLayout(pubBarChart);
        _13->setSpacing(0);
        _13->setContentsMargins(11, 11, 11, 11);
        _13->setObjectName(QStringLiteral("_13"));

        gridLayout_19->addWidget(pubBarChart, 1, 0, 1, 1);

        pub_graph_stackedWidget->addWidget(pub_bar_page);
        pub_line_page = new QWidget();
        pub_line_page->setObjectName(QStringLiteral("pub_line_page"));
        gridLayout_23 = new QGridLayout(pub_line_page);
        gridLayout_23->setSpacing(6);
        gridLayout_23->setContentsMargins(11, 11, 11, 11);
        gridLayout_23->setObjectName(QStringLiteral("gridLayout_23"));
        pubLineChart = new QCustomPlot(pub_line_page);
        pubLineChart->setObjectName(QStringLiteral("pubLineChart"));
        sizePolicy3.setHeightForWidth(pubLineChart->sizePolicy().hasHeightForWidth());
        pubLineChart->setSizePolicy(sizePolicy3);

        gridLayout_23->addWidget(pubLineChart, 0, 0, 1, 1);

        pub_graph_stackedWidget->addWidget(pub_line_page);
        pub_scatter_page = new QWidget();
        pub_scatter_page->setObjectName(QStringLiteral("pub_scatter_page"));
        gridLayout_25 = new QGridLayout(pub_scatter_page);
        gridLayout_25->setSpacing(6);
        gridLayout_25->setContentsMargins(11, 11, 11, 11);
        gridLayout_25->setObjectName(QStringLiteral("gridLayout_25"));
        pubScatterChart = new QCustomPlot(pub_scatter_page);
        pubScatterChart->setObjectName(QStringLiteral("pubScatterChart"));

        gridLayout_25->addWidget(pubScatterChart, 0, 0, 1, 1);

        pub_graph_stackedWidget->addWidget(pub_scatter_page);

        gridLayout_20->addWidget(pub_graph_stackedWidget, 2, 0, 1, 1);


        gridLayout_3->addWidget(pubChartFrame, 5, 7, 1, 8);

        pubClearList = new QPushButton(tabPub);
        pubClearList->setObjectName(QStringLiteral("pubClearList"));
        pubClearList->setCursor(QCursor(Qt::PointingHandCursor));
        pubClearList->setStyleSheet(QStringLiteral("background-color: rgb(204, 204, 204);"));

        gridLayout_3->addWidget(pubClearList, 6, 1, 1, 1);

        horizontalSpacer_35 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_35, 2, 8, 1, 1);

        pubTreeView = new QTreeView(tabPub);
        pubTreeView->setObjectName(QStringLiteral("pubTreeView"));
        sizePolicy3.setHeightForWidth(pubTreeView->sizePolicy().hasHeightForWidth());
        pubTreeView->setSizePolicy(sizePolicy3);
        pubTreeView->setFrameShape(QFrame::NoFrame);
        pubTreeView->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(pubTreeView, 5, 0, 1, 7);

        pub_new_sort = new QPushButton(tabPub);
        pub_new_sort->setObjectName(QStringLiteral("pub_new_sort"));
        pub_new_sort->setEnabled(false);
        sizePolicy5.setHeightForWidth(pub_new_sort->sizePolicy().hasHeightForWidth());
        pub_new_sort->setSizePolicy(sizePolicy5);
        pub_new_sort->setMinimumSize(QSize(150, 0));
        pub_new_sort->setCursor(QCursor(Qt::PointingHandCursor));
        pub_new_sort->setStyleSheet(QStringLiteral("background-color: rgb(204, 204, 204);"));
        pub_new_sort->setCheckable(false);
        pub_new_sort->setChecked(false);
        pub_new_sort->setAutoDefault(false);

        gridLayout_3->addWidget(pub_new_sort, 2, 3, 1, 3);

        pub_filter_label = new QLabel(tabPub);
        pub_filter_label->setObjectName(QStringLiteral("pub_filter_label"));
        pub_filter_label->setEnabled(false);

        gridLayout_3->addWidget(pub_filter_label, 4, 0, 1, 1);

        pubPrintButton = new QToolButton(tabPub);
        pubPrintButton->setObjectName(QStringLiteral("pubPrintButton"));
        pubPrintButton->setCursor(QCursor(Qt::PointingHandCursor));
        pubPrintButton->setStyleSheet(QStringLiteral("background-color: rgb(204, 204, 204);"));
        pubPrintButton->setIcon(icon);
        pubPrintButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        gridLayout_3->addWidget(pubPrintButton, 0, 14, 1, 1, Qt::AlignRight);

        pub_delete_sort = new QPushButton(tabPub);
        pub_delete_sort->setObjectName(QStringLiteral("pub_delete_sort"));
        pub_delete_sort->setEnabled(false);
        sizePolicy5.setHeightForWidth(pub_delete_sort->sizePolicy().hasHeightForWidth());
        pub_delete_sort->setSizePolicy(sizePolicy5);
        pub_delete_sort->setCursor(QCursor(Qt::PointingHandCursor));
        pub_delete_sort->setStyleSheet(QStringLiteral("background-color: rgb(204, 204, 204);"));

        gridLayout_3->addWidget(pub_delete_sort, 2, 2, 1, 1);

        pub_filter = new QLabel(tabPub);
        pub_filter->setObjectName(QStringLiteral("pub_filter"));
        pub_filter->setEnabled(false);

        gridLayout_3->addWidget(pub_filter, 4, 1, 1, 2);

        pub_sort = new QComboBox(tabPub);
        pub_sort->setObjectName(QStringLiteral("pub_sort"));
        pub_sort->setEnabled(false);
        sizePolicy4.setHeightForWidth(pub_sort->sizePolicy().hasHeightForWidth());
        pub_sort->setSizePolicy(sizePolicy4);
        pub_sort->setMinimumSize(QSize(120, 0));

        gridLayout_3->addWidget(pub_sort, 2, 1, 1, 1);

        horizontalSpacer_29 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_29, 2, 9, 1, 1);

        pub_file_label = new QLabel(tabPub);
        pub_file_label->setObjectName(QStringLiteral("pub_file_label"));
        sizePolicy6.setHeightForWidth(pub_file_label->sizePolicy().hasHeightForWidth());
        pub_file_label->setSizePolicy(sizePolicy6);

        gridLayout_3->addWidget(pub_file_label, 0, 1, 1, 12);

        horizontalSpacer_4 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_4, 2, 11, 1, 1);

        pub_pie_button = new QRadioButton(tabPub);
        pub_pie_button->setObjectName(QStringLiteral("pub_pie_button"));
        pub_pie_button->setEnabled(false);
        pub_pie_button->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout_3->addWidget(pub_pie_button, 4, 7, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_7, 2, 7, 1, 1);

        pub_sort_label = new QLabel(tabPub);
        pub_sort_label->setObjectName(QStringLiteral("pub_sort_label"));
        pub_sort_label->setEnabled(false);

        gridLayout_3->addWidget(pub_sort_label, 2, 0, 1, 1);

        line_5 = new QFrame(tabPub);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_5, 3, 0, 1, 15);

        horizontalSpacer_22 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_22, 2, 6, 1, 1);

        pub_to_label = new QLabel(tabPub);
        pub_to_label->setObjectName(QStringLiteral("pub_to_label"));
        pub_to_label->setEnabled(false);

        gridLayout_3->addWidget(pub_to_label, 4, 4, 1, 1);

        pub_filter_from = new QLineEdit(tabPub);
        pub_filter_from->setObjectName(QStringLiteral("pub_filter_from"));
        pub_filter_from->setEnabled(false);
        pub_filter_from->setMaximumSize(QSize(60, 16777215));
        pub_filter_from->setMaxLength(1);
        pub_filter_from->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(pub_filter_from, 4, 3, 1, 1);

        pub_load_file = new QPushButton(tabPub);
        pub_load_file->setObjectName(QStringLiteral("pub_load_file"));
        pub_load_file->setMinimumSize(QSize(100, 0));
        pub_load_file->setCursor(QCursor(Qt::PointingHandCursor));
        pub_load_file->setAutoFillBackground(false);
        pub_load_file->setStyleSheet(QStringLiteral("background-color: rgb(204, 204, 204);"));

        gridLayout_3->addWidget(pub_load_file, 0, 0, 1, 1);

        pub_filter_to = new QLineEdit(tabPub);
        pub_filter_to->setObjectName(QStringLiteral("pub_filter_to"));
        pub_filter_to->setEnabled(false);
        pub_filter_to->setMaximumSize(QSize(60, 16777215));
        pub_filter_to->setMaxLength(1);
        pub_filter_to->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(pub_filter_to, 4, 5, 1, 1);

        line_6 = new QFrame(tabPub);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_6, 1, 0, 1, 15);

        pub_line_button = new QRadioButton(tabPub);
        pub_line_button->setObjectName(QStringLiteral("pub_line_button"));
        pub_line_button->setEnabled(false);
        pub_line_button->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout_3->addWidget(pub_line_button, 4, 9, 1, 1);

        pubExportButton = new QToolButton(tabPub);
        pubExportButton->setObjectName(QStringLiteral("pubExportButton"));
        pubExportButton->setCursor(QCursor(Qt::PointingHandCursor));
        pubExportButton->setStyleSheet(QStringLiteral("background-color: rgb(204, 204, 204);"));
        pubExportButton->setIcon(icon1);
        pubExportButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        gridLayout_3->addWidget(pubExportButton, 0, 13, 1, 1);

        pub_bar_button = new QRadioButton(tabPub);
        pub_bar_button->setObjectName(QStringLiteral("pub_bar_button"));
        pub_bar_button->setEnabled(false);
        pub_bar_button->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout_3->addWidget(pub_bar_button, 4, 8, 1, 1);

        horizontalSpacer_28 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_28, 2, 10, 1, 1);

        pubListCounter = new QLCDNumber(tabPub);
        pubListCounter->setObjectName(QStringLiteral("pubListCounter"));

        gridLayout_3->addWidget(pubListCounter, 6, 0, 1, 1);

        pubAddIndex = new QPushButton(tabPub);
        pubAddIndex->setObjectName(QStringLiteral("pubAddIndex"));
        pubAddIndex->setCursor(QCursor(Qt::PointingHandCursor));
        pubAddIndex->setStyleSheet(QStringLiteral("background-color: rgb(204, 204, 204);"));

        gridLayout_3->addWidget(pubAddIndex, 6, 6, 1, 1);

        pubUndoIndex = new QPushButton(tabPub);
        pubUndoIndex->setObjectName(QStringLiteral("pubUndoIndex"));
        pubUndoIndex->setCursor(QCursor(Qt::PointingHandCursor));
        pubUndoIndex->setStyleSheet(QStringLiteral("background-color: rgb(204, 204, 204);"));

        gridLayout_3->addWidget(pubUndoIndex, 6, 5, 1, 1);

        pub_scatter_button = new QRadioButton(tabPub);
        pub_scatter_button->setObjectName(QStringLiteral("pub_scatter_button"));
        pub_scatter_button->setEnabled(false);
        pub_scatter_button->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout_3->addWidget(pub_scatter_button, 4, 10, 1, 2);

        pubGraphList = new QPushButton(tabPub);
        pubGraphList->setObjectName(QStringLiteral("pubGraphList"));
        pubGraphList->setEnabled(true);
        pubGraphList->setStyleSheet(QStringLiteral("background-color: rgb(204, 204, 204);"));

        gridLayout_3->addWidget(pubGraphList, 6, 7, 1, 1);

        pubListContentView = new QPushButton(tabPub);
        pubListContentView->setObjectName(QStringLiteral("pubListContentView"));
        pubListContentView->setStyleSheet(QStringLiteral("background-color: rgb(204, 204, 204);"));

        gridLayout_3->addWidget(pubListContentView, 6, 2, 1, 2);

        categoryTab->addTab(tabPub, QString());
        tabPres = new QWidget();
        tabPres->setObjectName(QStringLiteral("tabPres"));
        gridLayout_2 = new QGridLayout(tabPres);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        presChartFrame = new QFrame(tabPres);
        presChartFrame->setObjectName(QStringLiteral("presChartFrame"));
        sizePolicy3.setHeightForWidth(presChartFrame->sizePolicy().hasHeightForWidth());
        presChartFrame->setSizePolicy(sizePolicy3);
        presChartFrame->setFrameShape(QFrame::Box);
        presChartFrame->setFrameShadow(QFrame::Sunken);
        presChartFrame->setLineWidth(3);
        gridLayout_17 = new QGridLayout(presChartFrame);
        gridLayout_17->setSpacing(6);
        gridLayout_17->setContentsMargins(11, 11, 11, 11);
        gridLayout_17->setObjectName(QStringLiteral("gridLayout_17"));
        presGraphTitle = new QLabel(presChartFrame);
        presGraphTitle->setObjectName(QStringLiteral("presGraphTitle"));
        presGraphTitle->setStyleSheet(QStringLiteral("font: bold 12px;"));
        presGraphTitle->setAlignment(Qt::AlignCenter);

        gridLayout_17->addWidget(presGraphTitle, 0, 0, 1, 1);

        pres_graph_stackedWidget = new QStackedWidget(presChartFrame);
        pres_graph_stackedWidget->setObjectName(QStringLiteral("pres_graph_stackedWidget"));
        pres_graph_stackedWidget->setEnabled(true);
        sizePolicy3.setHeightForWidth(pres_graph_stackedWidget->sizePolicy().hasHeightForWidth());
        pres_graph_stackedWidget->setSizePolicy(sizePolicy3);
        pres_graph_stackedWidget->setMidLineWidth(0);
        pres_pie_page = new QWidget();
        pres_pie_page->setObjectName(QStringLiteral("pres_pie_page"));
        gridLayout_11 = new QGridLayout(pres_pie_page);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        presPieChart = new PieChartWidget(pres_pie_page);
        presPieChart->setObjectName(QStringLiteral("presPieChart"));
        presPieChart->setEnabled(true);
        sizePolicy3.setHeightForWidth(presPieChart->sizePolicy().hasHeightForWidth());
        presPieChart->setSizePolicy(sizePolicy3);
        presPieChart->setMinimumSize(QSize(250, 0));
        presPieChart->setMaximumSize(QSize(16777215, 16777215));
        presPieChart->setFocusPolicy(Qt::TabFocus);
        presPieChart->setLayoutDirection(Qt::LeftToRight);
        presPieChart->setStyleSheet(QStringLiteral(""));
        _6 = new QGridLayout(presPieChart);
        _6->setSpacing(0);
        _6->setContentsMargins(11, 11, 11, 11);
        _6->setObjectName(QStringLiteral("_6"));

        gridLayout_11->addWidget(presPieChart, 0, 0, 1, 1);

        presPieList = new QListWidget(pres_pie_page);
        presPieList->setObjectName(QStringLiteral("presPieList"));
        presPieList->setMinimumSize(QSize(0, 0));
        presPieList->setMaximumSize(QSize(16777215, 16777215));
        presPieList->setBaseSize(QSize(0, 0));
        presPieList->setFocusPolicy(Qt::NoFocus);
        presPieList->setLayoutDirection(Qt::LeftToRight);
        presPieList->setFrameShape(QFrame::NoFrame);
        presPieList->setSelectionMode(QAbstractItemView::NoSelection);

        gridLayout_11->addWidget(presPieList, 0, 1, 1, 1);

        pres_graph_stackedWidget->addWidget(pres_pie_page);
        pres_bar_page = new QWidget();
        pres_bar_page->setObjectName(QStringLiteral("pres_bar_page"));
        gridLayout_8 = new QGridLayout(pres_bar_page);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        presBarChart = new QCustomPlot(pres_bar_page);
        presBarChart->setObjectName(QStringLiteral("presBarChart"));
        presBarChart->setEnabled(true);
        sizePolicy3.setHeightForWidth(presBarChart->sizePolicy().hasHeightForWidth());
        presBarChart->setSizePolicy(sizePolicy3);
        presBarChart->setMinimumSize(QSize(250, 0));
        presBarChart->setMaximumSize(QSize(16777215, 16777215));
        presBarChart->setFocusPolicy(Qt::TabFocus);
        presBarChart->setLayoutDirection(Qt::LeftToRight);
        presBarChart->setStyleSheet(QStringLiteral(""));
        _8 = new QGridLayout(presBarChart);
        _8->setSpacing(0);
        _8->setContentsMargins(11, 11, 11, 11);
        _8->setObjectName(QStringLiteral("_8"));

        gridLayout_8->addWidget(presBarChart, 1, 0, 1, 1);

        pres_graph_stackedWidget->addWidget(pres_bar_page);
        pres_line_page = new QWidget();
        pres_line_page->setObjectName(QStringLiteral("pres_line_page"));
        gridLayout_14 = new QGridLayout(pres_line_page);
        gridLayout_14->setSpacing(6);
        gridLayout_14->setContentsMargins(11, 11, 11, 11);
        gridLayout_14->setObjectName(QStringLiteral("gridLayout_14"));
        presLineChart = new QCustomPlot(pres_line_page);
        presLineChart->setObjectName(QStringLiteral("presLineChart"));
        sizePolicy3.setHeightForWidth(presLineChart->sizePolicy().hasHeightForWidth());
        presLineChart->setSizePolicy(sizePolicy3);

        gridLayout_14->addWidget(presLineChart, 0, 0, 1, 1);

        pres_graph_stackedWidget->addWidget(pres_line_page);
        pres_scatter_page = new QWidget();
        pres_scatter_page->setObjectName(QStringLiteral("pres_scatter_page"));
        gridLayout_26 = new QGridLayout(pres_scatter_page);
        gridLayout_26->setSpacing(6);
        gridLayout_26->setContentsMargins(11, 11, 11, 11);
        gridLayout_26->setObjectName(QStringLiteral("gridLayout_26"));
        presScatterChart = new QCustomPlot(pres_scatter_page);
        presScatterChart->setObjectName(QStringLiteral("presScatterChart"));

        gridLayout_26->addWidget(presScatterChart, 0, 0, 1, 1);

        pres_graph_stackedWidget->addWidget(pres_scatter_page);

        gridLayout_17->addWidget(pres_graph_stackedWidget, 3, 0, 1, 1);


        gridLayout_2->addWidget(presChartFrame, 5, 7, 1, 8);

        horizontalSpacer_23 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_23, 2, 6, 1, 1);

        pres_delete_sort = new QPushButton(tabPres);
        pres_delete_sort->setObjectName(QStringLiteral("pres_delete_sort"));
        pres_delete_sort->setEnabled(false);
        pres_delete_sort->setCursor(QCursor(Qt::PointingHandCursor));
        pres_delete_sort->setStyleSheet(QStringLiteral("background-color: rgb(204, 204, 204);"));

        gridLayout_2->addWidget(pres_delete_sort, 2, 2, 1, 1);

        pres_load_file = new QPushButton(tabPres);
        pres_load_file->setObjectName(QStringLiteral("pres_load_file"));
        pres_load_file->setMinimumSize(QSize(100, 0));
        pres_load_file->setCursor(QCursor(Qt::PointingHandCursor));
        pres_load_file->setAutoFillBackground(false);
        pres_load_file->setStyleSheet(QStringLiteral("background-color: rgb(204, 204, 204);"));

        gridLayout_2->addWidget(pres_load_file, 0, 0, 1, 1);

        presTreeView = new QTreeView(tabPres);
        presTreeView->setObjectName(QStringLiteral("presTreeView"));
        sizePolicy3.setHeightForWidth(presTreeView->sizePolicy().hasHeightForWidth());
        presTreeView->setSizePolicy(sizePolicy3);
        presTreeView->setStyleSheet(QStringLiteral(""));
        presTreeView->setFrameShape(QFrame::NoFrame);
        presTreeView->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(presTreeView, 5, 0, 1, 7);

        horizontalSpacer_31 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_31, 2, 10, 1, 1);

        line_4 = new QFrame(tabPres);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_4, 1, 0, 1, 15);

        horizontalSpacer_25 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_25, 2, 9, 1, 1);

        pres_filter = new QLabel(tabPres);
        pres_filter->setObjectName(QStringLiteral("pres_filter"));
        pres_filter->setEnabled(false);

        gridLayout_2->addWidget(pres_filter, 4, 1, 1, 2);

        presPrintButton = new QToolButton(tabPres);
        presPrintButton->setObjectName(QStringLiteral("presPrintButton"));
        presPrintButton->setCursor(QCursor(Qt::PointingHandCursor));
        presPrintButton->setStyleSheet(QStringLiteral("background-color: rgb(204, 204, 204);"));
        presPrintButton->setIcon(icon);
        presPrintButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        gridLayout_2->addWidget(presPrintButton, 0, 14, 1, 1, Qt::AlignRight);

        pres_filter_label = new QLabel(tabPres);
        pres_filter_label->setObjectName(QStringLiteral("pres_filter_label"));
        pres_filter_label->setEnabled(false);

        gridLayout_2->addWidget(pres_filter_label, 4, 0, 1, 1);

        line_3 = new QFrame(tabPres);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_3, 3, 0, 1, 15);

        pres_sort = new QComboBox(tabPres);
        pres_sort->setObjectName(QStringLiteral("pres_sort"));
        pres_sort->setEnabled(false);
        sizePolicy4.setHeightForWidth(pres_sort->sizePolicy().hasHeightForWidth());
        pres_sort->setSizePolicy(sizePolicy4);
        pres_sort->setMinimumSize(QSize(120, 0));

        gridLayout_2->addWidget(pres_sort, 2, 1, 1, 1);

        horizontalSpacer_16 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_16, 2, 11, 1, 1);

        pres_sort_label = new QLabel(tabPres);
        pres_sort_label->setObjectName(QStringLiteral("pres_sort_label"));
        pres_sort_label->setEnabled(false);

        gridLayout_2->addWidget(pres_sort_label, 2, 0, 1, 1);

        pres_to_label = new QLabel(tabPres);
        pres_to_label->setObjectName(QStringLiteral("pres_to_label"));
        pres_to_label->setEnabled(false);

        gridLayout_2->addWidget(pres_to_label, 4, 4, 1, 1);

        horizontalSpacer_30 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_30, 2, 8, 1, 1);

        pres_pie_button = new QRadioButton(tabPres);
        pres_pie_button->setObjectName(QStringLiteral("pres_pie_button"));
        pres_pie_button->setEnabled(false);
        pres_pie_button->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout_2->addWidget(pres_pie_button, 4, 7, 1, 1);

        pres_new_sort = new QPushButton(tabPres);
        pres_new_sort->setObjectName(QStringLiteral("pres_new_sort"));
        pres_new_sort->setEnabled(false);
        sizePolicy4.setHeightForWidth(pres_new_sort->sizePolicy().hasHeightForWidth());
        pres_new_sort->setSizePolicy(sizePolicy4);
        pres_new_sort->setMinimumSize(QSize(150, 0));
        pres_new_sort->setCursor(QCursor(Qt::PointingHandCursor));
        pres_new_sort->setStyleSheet(QStringLiteral("background-color: rgb(204, 204, 204);"));
        pres_new_sort->setCheckable(false);
        pres_new_sort->setChecked(false);
        pres_new_sort->setAutoDefault(false);

        gridLayout_2->addWidget(pres_new_sort, 2, 3, 1, 3);

        pres_file_label = new QLabel(tabPres);
        pres_file_label->setObjectName(QStringLiteral("pres_file_label"));
        sizePolicy6.setHeightForWidth(pres_file_label->sizePolicy().hasHeightForWidth());
        pres_file_label->setSizePolicy(sizePolicy6);

        gridLayout_2->addWidget(pres_file_label, 0, 1, 1, 12);

        pres_filter_from = new QLineEdit(tabPres);
        pres_filter_from->setObjectName(QStringLiteral("pres_filter_from"));
        pres_filter_from->setEnabled(false);
        pres_filter_from->setMaximumSize(QSize(60, 16777215));
        pres_filter_from->setMaxLength(1);
        pres_filter_from->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(pres_filter_from, 4, 3, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 2, 7, 1, 1);

        pres_filter_to = new QLineEdit(tabPres);
        pres_filter_to->setObjectName(QStringLiteral("pres_filter_to"));
        pres_filter_to->setEnabled(false);
        pres_filter_to->setMaximumSize(QSize(60, 16777215));
        pres_filter_to->setMaxLength(1);
        pres_filter_to->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(pres_filter_to, 4, 5, 1, 1);

        pres_bar_button = new QRadioButton(tabPres);
        pres_bar_button->setObjectName(QStringLiteral("pres_bar_button"));
        pres_bar_button->setEnabled(false);
        pres_bar_button->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout_2->addWidget(pres_bar_button, 4, 8, 1, 1);

        pres_line_button = new QRadioButton(tabPres);
        pres_line_button->setObjectName(QStringLiteral("pres_line_button"));
        pres_line_button->setEnabled(false);
        pres_line_button->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout_2->addWidget(pres_line_button, 4, 9, 1, 1);

        presExportButton = new QToolButton(tabPres);
        presExportButton->setObjectName(QStringLiteral("presExportButton"));
        presExportButton->setCursor(QCursor(Qt::PointingHandCursor));
        presExportButton->setStyleSheet(QStringLiteral("background-color: rgb(204, 204, 204);"));
        presExportButton->setIcon(icon1);
        presExportButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        gridLayout_2->addWidget(presExportButton, 0, 13, 1, 1);

        presUndoIndex = new QPushButton(tabPres);
        presUndoIndex->setObjectName(QStringLiteral("presUndoIndex"));
        presUndoIndex->setCursor(QCursor(Qt::PointingHandCursor));
        presUndoIndex->setStyleSheet(QStringLiteral("background-color: rgb(204, 204, 204);"));

        gridLayout_2->addWidget(presUndoIndex, 6, 5, 1, 1);

        presAddIndex = new QPushButton(tabPres);
        presAddIndex->setObjectName(QStringLiteral("presAddIndex"));
        presAddIndex->setCursor(QCursor(Qt::PointingHandCursor));
        presAddIndex->setStyleSheet(QStringLiteral("background-color: rgb(204, 204, 204);"));

        gridLayout_2->addWidget(presAddIndex, 6, 6, 1, 1);

        presClearList = new QPushButton(tabPres);
        presClearList->setObjectName(QStringLiteral("presClearList"));
        presClearList->setCursor(QCursor(Qt::PointingHandCursor));
        presClearList->setStyleSheet(QStringLiteral("background-color: rgb(204, 204, 204);"));

        gridLayout_2->addWidget(presClearList, 6, 1, 1, 1);

        presListCounter = new QLCDNumber(tabPres);
        presListCounter->setObjectName(QStringLiteral("presListCounter"));

        gridLayout_2->addWidget(presListCounter, 6, 0, 1, 1);

        pres_scatter_button = new QRadioButton(tabPres);
        pres_scatter_button->setObjectName(QStringLiteral("pres_scatter_button"));
        pres_scatter_button->setEnabled(false);
        pres_scatter_button->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout_2->addWidget(pres_scatter_button, 4, 10, 1, 2);

        presGraphList = new QPushButton(tabPres);
        presGraphList->setObjectName(QStringLiteral("presGraphList"));
        presGraphList->setEnabled(true);
        presGraphList->setStyleSheet(QStringLiteral("background-color: rgb(204, 204, 204);"));

        gridLayout_2->addWidget(presGraphList, 6, 7, 1, 1);

        presListContentView = new QPushButton(tabPres);
        presListContentView->setObjectName(QStringLiteral("presListContentView"));
        presListContentView->setStyleSheet(QStringLiteral("background-color: rgb(204, 204, 204);"));

        gridLayout_2->addWidget(presListContentView, 6, 2, 1, 2);

        categoryTab->addTab(tabPres, QString());
        tabFund = new QWidget();
        tabFund->setObjectName(QStringLiteral("tabFund"));
        gridLayout_6 = new QGridLayout(tabFund);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        fundChartFrame = new QFrame(tabFund);
        fundChartFrame->setObjectName(QStringLiteral("fundChartFrame"));
        sizePolicy3.setHeightForWidth(fundChartFrame->sizePolicy().hasHeightForWidth());
        fundChartFrame->setSizePolicy(sizePolicy3);
        fundChartFrame->setFrameShape(QFrame::Box);
        fundChartFrame->setFrameShadow(QFrame::Sunken);
        fundChartFrame->setLineWidth(3);
        gridLayout_16 = new QGridLayout(fundChartFrame);
        gridLayout_16->setSpacing(6);
        gridLayout_16->setContentsMargins(11, 11, 11, 11);
        gridLayout_16->setObjectName(QStringLiteral("gridLayout_16"));
        fund_graph_stackedWidget = new QStackedWidget(fundChartFrame);
        fund_graph_stackedWidget->setObjectName(QStringLiteral("fund_graph_stackedWidget"));
        fund_graph_stackedWidget->setEnabled(true);
        sizePolicy3.setHeightForWidth(fund_graph_stackedWidget->sizePolicy().hasHeightForWidth());
        fund_graph_stackedWidget->setSizePolicy(sizePolicy3);
        fund_graph_stackedWidget->setFrameShape(QFrame::NoFrame);
        fund_graph_stackedWidget->setFrameShadow(QFrame::Sunken);
        fund_graph_stackedWidget->setMidLineWidth(0);
        fund_pie_page = new QWidget();
        fund_pie_page->setObjectName(QStringLiteral("fund_pie_page"));
        gridLayout_9 = new QGridLayout(fund_pie_page);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        fundPieChart = new PieChartWidget(fund_pie_page);
        fundPieChart->setObjectName(QStringLiteral("fundPieChart"));
        fundPieChart->setEnabled(true);
        sizePolicy3.setHeightForWidth(fundPieChart->sizePolicy().hasHeightForWidth());
        fundPieChart->setSizePolicy(sizePolicy3);
        fundPieChart->setMinimumSize(QSize(250, 0));
        fundPieChart->setMaximumSize(QSize(16777215, 16777215));
        fundPieChart->setFocusPolicy(Qt::TabFocus);
        fundPieChart->setLayoutDirection(Qt::LeftToRight);
        fundPieChart->setStyleSheet(QStringLiteral(""));
        _4 = new QGridLayout(fundPieChart);
        _4->setSpacing(0);
        _4->setContentsMargins(11, 11, 11, 11);
        _4->setObjectName(QStringLiteral("_4"));

        gridLayout_9->addWidget(fundPieChart, 0, 0, 1, 1);

        fundPieList = new QListWidget(fund_pie_page);
        fundPieList->setObjectName(QStringLiteral("fundPieList"));
        fundPieList->setMinimumSize(QSize(0, 0));
        fundPieList->setMaximumSize(QSize(16777215, 16777215));
        fundPieList->setBaseSize(QSize(0, 0));
        fundPieList->setFocusPolicy(Qt::NoFocus);
        fundPieList->setLayoutDirection(Qt::LeftToRight);
        fundPieList->setFrameShape(QFrame::NoFrame);
        fundPieList->setSelectionMode(QAbstractItemView::NoSelection);

        gridLayout_9->addWidget(fundPieList, 0, 1, 1, 1);

        fund_graph_stackedWidget->addWidget(fund_pie_page);
        fund_bar_page = new QWidget();
        fund_bar_page->setObjectName(QStringLiteral("fund_bar_page"));
        gridLayout_15 = new QGridLayout(fund_bar_page);
        gridLayout_15->setSpacing(6);
        gridLayout_15->setContentsMargins(11, 11, 11, 11);
        gridLayout_15->setObjectName(QStringLiteral("gridLayout_15"));
        fundBarChart = new QCustomPlot(fund_bar_page);
        fundBarChart->setObjectName(QStringLiteral("fundBarChart"));
        fundBarChart->setEnabled(true);
        sizePolicy3.setHeightForWidth(fundBarChart->sizePolicy().hasHeightForWidth());
        fundBarChart->setSizePolicy(sizePolicy3);
        fundBarChart->setMinimumSize(QSize(250, 0));
        fundBarChart->setMaximumSize(QSize(16777215, 16777215));
        fundBarChart->setFocusPolicy(Qt::TabFocus);
        fundBarChart->setLayoutDirection(Qt::LeftToRight);
        fundBarChart->setStyleSheet(QStringLiteral(""));
        _11 = new QGridLayout(fundBarChart);
        _11->setSpacing(0);
        _11->setContentsMargins(11, 11, 11, 11);
        _11->setObjectName(QStringLiteral("_11"));

        gridLayout_15->addWidget(fundBarChart, 1, 0, 1, 1);

        fund_graph_stackedWidget->addWidget(fund_bar_page);
        fund_line_page = new QWidget();
        fund_line_page->setObjectName(QStringLiteral("fund_line_page"));
        gridLayout_12 = new QGridLayout(fund_line_page);
        gridLayout_12->setSpacing(6);
        gridLayout_12->setContentsMargins(11, 11, 11, 11);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        gridLayout_12->setContentsMargins(12, 12, -1, -1);
        fundLineChart = new QCustomPlot(fund_line_page);
        fundLineChart->setObjectName(QStringLiteral("fundLineChart"));
        sizePolicy3.setHeightForWidth(fundLineChart->sizePolicy().hasHeightForWidth());
        fundLineChart->setSizePolicy(sizePolicy3);
        fundLineChart->setFocusPolicy(Qt::TabFocus);

        gridLayout_12->addWidget(fundLineChart, 0, 0, 1, 1);

        fund_graph_stackedWidget->addWidget(fund_line_page);
        fund_scatter_page = new QWidget();
        fund_scatter_page->setObjectName(QStringLiteral("fund_scatter_page"));
        gridLayout_27 = new QGridLayout(fund_scatter_page);
        gridLayout_27->setSpacing(6);
        gridLayout_27->setContentsMargins(11, 11, 11, 11);
        gridLayout_27->setObjectName(QStringLiteral("gridLayout_27"));
        fundScatterChart = new QCustomPlot(fund_scatter_page);
        fundScatterChart->setObjectName(QStringLiteral("fundScatterChart"));

        gridLayout_27->addWidget(fundScatterChart, 0, 0, 1, 1);

        fund_graph_stackedWidget->addWidget(fund_scatter_page);

        gridLayout_16->addWidget(fund_graph_stackedWidget, 1, 0, 1, 1);

        fundGraphTitle = new QLabel(fundChartFrame);
        fundGraphTitle->setObjectName(QStringLiteral("fundGraphTitle"));
        sizePolicy.setHeightForWidth(fundGraphTitle->sizePolicy().hasHeightForWidth());
        fundGraphTitle->setSizePolicy(sizePolicy);
        fundGraphTitle->setMinimumSize(QSize(0, 0));
        fundGraphTitle->setMaximumSize(QSize(16777215, 16777215));
        fundGraphTitle->setStyleSheet(QStringLiteral("font: bold 12px;"));
        fundGraphTitle->setAlignment(Qt::AlignCenter);

        gridLayout_16->addWidget(fundGraphTitle, 0, 0, 1, 1);


        gridLayout_6->addWidget(fundChartFrame, 5, 7, 1, 8);

        fundsClearList = new QPushButton(tabFund);
        fundsClearList->setObjectName(QStringLiteral("fundsClearList"));
        fundsClearList->setCursor(QCursor(Qt::PointingHandCursor));
        fundsClearList->setStyleSheet(QStringLiteral("background-color: rgb(204, 204, 204);"));

        gridLayout_6->addWidget(fundsClearList, 6, 1, 1, 1);

        fundsListCounter = new QLCDNumber(tabFund);
        fundsListCounter->setObjectName(QStringLiteral("fundsListCounter"));

        gridLayout_6->addWidget(fundsListCounter, 6, 0, 1, 1);

        fundsUndoIndex = new QPushButton(tabFund);
        fundsUndoIndex->setObjectName(QStringLiteral("fundsUndoIndex"));
        fundsUndoIndex->setCursor(QCursor(Qt::PointingHandCursor));
        fundsUndoIndex->setStyleSheet(QStringLiteral("background-color: rgb(204, 204, 204);"));

        gridLayout_6->addWidget(fundsUndoIndex, 6, 5, 1, 1);

        fundsAddIndex = new QPushButton(tabFund);
        fundsAddIndex->setObjectName(QStringLiteral("fundsAddIndex"));
        fundsAddIndex->setCursor(QCursor(Qt::PointingHandCursor));
        fundsAddIndex->setStyleSheet(QStringLiteral("background-color: rgb(204, 204, 204);"));

        gridLayout_6->addWidget(fundsAddIndex, 6, 6, 1, 1);

        fundTreeView = new QTreeView(tabFund);
        fundTreeView->setObjectName(QStringLiteral("fundTreeView"));
        sizePolicy3.setHeightForWidth(fundTreeView->sizePolicy().hasHeightForWidth());
        fundTreeView->setSizePolicy(sizePolicy3);
        fundTreeView->setStyleSheet(QStringLiteral(""));
        fundTreeView->setFrameShape(QFrame::NoFrame);
        fundTreeView->setFrameShadow(QFrame::Sunken);

        gridLayout_6->addWidget(fundTreeView, 5, 0, 1, 7);

        fund_new_sort = new QPushButton(tabFund);
        fund_new_sort->setObjectName(QStringLiteral("fund_new_sort"));
        fund_new_sort->setEnabled(false);
        sizePolicy4.setHeightForWidth(fund_new_sort->sizePolicy().hasHeightForWidth());
        fund_new_sort->setSizePolicy(sizePolicy4);
        fund_new_sort->setMinimumSize(QSize(150, 0));
        fund_new_sort->setCursor(QCursor(Qt::PointingHandCursor));
        fund_new_sort->setStyleSheet(QStringLiteral("background-color: rgb(204, 204, 204);"));
        fund_new_sort->setCheckable(false);
        fund_new_sort->setChecked(false);
        fund_new_sort->setAutoDefault(false);

        gridLayout_6->addWidget(fund_new_sort, 2, 3, 1, 3);

        fund_filter_from = new QLineEdit(tabFund);
        fund_filter_from->setObjectName(QStringLiteral("fund_filter_from"));
        fund_filter_from->setEnabled(false);
        fund_filter_from->setMaximumSize(QSize(60, 16777215));
        fund_filter_from->setMaxLength(1);
        fund_filter_from->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(fund_filter_from, 4, 3, 1, 1);

        fund_filter_label = new QLabel(tabFund);
        fund_filter_label->setObjectName(QStringLiteral("fund_filter_label"));
        fund_filter_label->setEnabled(false);

        gridLayout_6->addWidget(fund_filter_label, 4, 0, 1, 1);

        line_2 = new QFrame(tabFund);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_6->addWidget(line_2, 1, 0, 1, 15);

        fund_delete_sort = new QPushButton(tabFund);
        fund_delete_sort->setObjectName(QStringLiteral("fund_delete_sort"));
        fund_delete_sort->setEnabled(false);
        fund_delete_sort->setCursor(QCursor(Qt::PointingHandCursor));
        fund_delete_sort->setStyleSheet(QStringLiteral("background-color: rgb(204, 204, 204);"));

        gridLayout_6->addWidget(fund_delete_sort, 2, 2, 1, 1);

        fund_filter_to = new QLineEdit(tabFund);
        fund_filter_to->setObjectName(QStringLiteral("fund_filter_to"));
        fund_filter_to->setEnabled(false);
        fund_filter_to->setMaximumSize(QSize(60, 16777215));
        fund_filter_to->setMaxLength(1);
        fund_filter_to->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(fund_filter_to, 4, 5, 1, 1);

        horizontalSpacer_24 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_24, 2, 6, 1, 1);

        fund_bar_button = new QRadioButton(tabFund);
        fund_bar_button->setObjectName(QStringLiteral("fund_bar_button"));
        fund_bar_button->setEnabled(false);
        fund_bar_button->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout_6->addWidget(fund_bar_button, 4, 8, 1, 1);

        fund_line_button = new QRadioButton(tabFund);
        fund_line_button->setObjectName(QStringLiteral("fund_line_button"));
        fund_line_button->setEnabled(false);
        fund_line_button->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout_6->addWidget(fund_line_button, 4, 9, 1, 1);

        fund_load_file = new QPushButton(tabFund);
        fund_load_file->setObjectName(QStringLiteral("fund_load_file"));
        fund_load_file->setMinimumSize(QSize(100, 0));
        fund_load_file->setCursor(QCursor(Qt::PointingHandCursor));
        fund_load_file->setAutoFillBackground(false);
        fund_load_file->setStyleSheet(QStringLiteral("background-color: rgb(204, 204, 204);"));

        gridLayout_6->addWidget(fund_load_file, 0, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_5, 2, 7, 1, 1);

        fund_sort_label = new QLabel(tabFund);
        fund_sort_label->setObjectName(QStringLiteral("fund_sort_label"));
        fund_sort_label->setEnabled(false);

        gridLayout_6->addWidget(fund_sort_label, 2, 0, 1, 1);

        line = new QFrame(tabFund);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_6->addWidget(line, 3, 0, 1, 15);

        fund_pie_button = new QRadioButton(tabFund);
        fund_pie_button->setObjectName(QStringLiteral("fund_pie_button"));
        fund_pie_button->setEnabled(false);
        fund_pie_button->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout_6->addWidget(fund_pie_button, 4, 7, 1, 1);

        fund_file_label = new QLabel(tabFund);
        fund_file_label->setObjectName(QStringLiteral("fund_file_label"));

        gridLayout_6->addWidget(fund_file_label, 0, 1, 1, 12);

        horizontalSpacer_33 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_33, 2, 10, 1, 1);

        fundPrintButton = new QToolButton(tabFund);
        fundPrintButton->setObjectName(QStringLiteral("fundPrintButton"));
        fundPrintButton->setCursor(QCursor(Qt::PointingHandCursor));
        fundPrintButton->setStyleSheet(QStringLiteral("background-color: rgb(204, 204, 204);"));
        fundPrintButton->setIcon(icon);
        fundPrintButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        gridLayout_6->addWidget(fundPrintButton, 0, 14, 1, 1, Qt::AlignRight);

        fund_sort = new QComboBox(tabFund);
        fund_sort->setObjectName(QStringLiteral("fund_sort"));
        fund_sort->setEnabled(false);
        sizePolicy4.setHeightForWidth(fund_sort->sizePolicy().hasHeightForWidth());
        fund_sort->setSizePolicy(sizePolicy4);
        fund_sort->setMinimumSize(QSize(120, 0));

        gridLayout_6->addWidget(fund_sort, 2, 1, 1, 1);

        horizontalSpacer_32 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_32, 2, 8, 1, 1);

        fund_to_label = new QLabel(tabFund);
        fund_to_label->setObjectName(QStringLiteral("fund_to_label"));
        fund_to_label->setEnabled(false);

        gridLayout_6->addWidget(fund_to_label, 4, 4, 1, 1);

        fund_filter = new QLabel(tabFund);
        fund_filter->setObjectName(QStringLiteral("fund_filter"));
        fund_filter->setEnabled(false);

        gridLayout_6->addWidget(fund_filter, 4, 1, 1, 2);

        horizontalSpacer_15 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_15, 2, 11, 1, 1);

        fundExportButton = new QToolButton(tabFund);
        fundExportButton->setObjectName(QStringLiteral("fundExportButton"));
        fundExportButton->setCursor(QCursor(Qt::PointingHandCursor));
        fundExportButton->setStyleSheet(QStringLiteral("background-color: rgb(204, 204, 204);"));
        fundExportButton->setIcon(icon1);
        fundExportButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        gridLayout_6->addWidget(fundExportButton, 0, 13, 1, 1);

        fund_scatter_button = new QRadioButton(tabFund);
        fund_scatter_button->setObjectName(QStringLiteral("fund_scatter_button"));
        fund_scatter_button->setEnabled(false);
        fund_scatter_button->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout_6->addWidget(fund_scatter_button, 4, 10, 1, 2);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_6, 2, 9, 1, 1);

        fundGraphList = new QPushButton(tabFund);
        fundGraphList->setObjectName(QStringLiteral("fundGraphList"));
        fundGraphList->setEnabled(true);
        sizePolicy4.setHeightForWidth(fundGraphList->sizePolicy().hasHeightForWidth());
        fundGraphList->setSizePolicy(sizePolicy4);
        fundGraphList->setStyleSheet(QStringLiteral("background-color: rgb(204, 204, 204);"));

        gridLayout_6->addWidget(fundGraphList, 6, 7, 1, 1);

        fundListContentView = new QPushButton(tabFund);
        fundListContentView->setObjectName(QStringLiteral("fundListContentView"));
        fundListContentView->setStyleSheet(QStringLiteral("background-color: rgb(204, 204, 204);"));

        gridLayout_6->addWidget(fundListContentView, 6, 2, 1, 2);

        categoryTab->addTab(tabFund, QString());

        gridLayout_4->addWidget(categoryTab, 4, 1, 1, 1);


        gridLayout->addWidget(frame, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1200, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionLoad_file);
        menuFile->addAction(actionClear_Session_for_Next_Run);
        menuFile->addAction(actionClear_All_Sort_Orders);

        retranslateUi(MainWindow);

        categoryTab->setCurrentIndex(0);
        teach_graph_stackedWidget->setCurrentIndex(3);
        teach_new_sort->setDefault(false);
        pub_graph_stackedWidget->setCurrentIndex(3);
        pub_new_sort->setDefault(false);
        pres_graph_stackedWidget->setCurrentIndex(3);
        pres_new_sort->setDefault(false);
        fund_graph_stackedWidget->setCurrentIndex(3);
        fund_new_sort->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Pegasus Galaxy", 0));
        actionLoad_file->setText(QApplication::translate("MainWindow", "Load file...", 0));
#ifndef QT_NO_TOOLTIP
        actionLoad_file->setToolTip(QApplication::translate("MainWindow", "Load file or multiple files", 0));
#endif // QT_NO_TOOLTIP
        actionClear_Session_for_Next_Run->setText(QApplication::translate("MainWindow", "Clear Session for Next Run", 0));
        actionClear_All_Sort_Orders->setText(QApplication::translate("MainWindow", "Clear All Sort Orders", 0));
        logo_label->setText(QString());
        start_label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:8pt;\">Start Date</span></p></body></html>", 0));
        end_label->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:10px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; color:#000000;\">End Date</span></p></body></html>", 0));
#ifndef QT_NO_TOOLTIP
        FromDate->setToolTip(QApplication::translate("MainWindow", "Start Date Selector", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        ToDate->setToolTip(QApplication::translate("MainWindow", "End Date Selector", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        categoryTab->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        tabTeach->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        teachGraphList->setText(QApplication::translate("MainWindow", "Graph List", 0));
#ifndef QT_NO_TOOLTIP
        teachChartFrame->setToolTip(QApplication::translate("MainWindow", "Graph Display", 0));
#endif // QT_NO_TOOLTIP
        teachGraphTitle->setText(QString());
        teach_filter_from->setText(QApplication::translate("MainWindow", "*", 0));
        teach_filter_to->setText(QApplication::translate("MainWindow", "Z", 0));
        teach_to_label->setText(QApplication::translate("MainWindow", "to", 0));
        teachingClearList->setText(QApplication::translate("MainWindow", "Clear List", 0));
        teachingUndoIndex->setText(QApplication::translate("MainWindow", "Undo", 0));
        teachingAddIndex->setText(QApplication::translate("MainWindow", "Add to List", 0));
#ifndef QT_NO_TOOLTIP
        teachTreeView->setToolTip(QApplication::translate("MainWindow", "Data Display", 0));
#endif // QT_NO_TOOLTIP
        teach_scatter_button->setText(QApplication::translate("MainWindow", "Scatter Chart", 0));
#ifndef QT_NO_TOOLTIP
        teach_delete_sort->setToolTip(QApplication::translate("MainWindow", "Delete Button", 0));
#endif // QT_NO_TOOLTIP
        teach_delete_sort->setText(QApplication::translate("MainWindow", "Delete", 0));
#ifndef QT_NO_TOOLTIP
        teach_file_label->setToolTip(QApplication::translate("MainWindow", "File Location", 0));
#endif // QT_NO_TOOLTIP
        teach_file_label->setText(QApplication::translate("MainWindow", "No file chosen.", 0));
        teach_bar_button->setText(QApplication::translate("MainWindow", "Bar Chart", 0));
        teach_sort_label->setText(QApplication::translate("MainWindow", "Select Sort Order:", 0));
        teach_filter_label->setText(QApplication::translate("MainWindow", "Filter by:", 0));
#ifndef QT_NO_TOOLTIP
        teach_sort->setToolTip(QApplication::translate("MainWindow", "Sort Order Select", 0));
#endif // QT_NO_TOOLTIP
        teach_pie_button->setText(QApplication::translate("MainWindow", "Pie Chart", 0));
#ifndef QT_NO_TOOLTIP
        teach_new_sort->setToolTip(QApplication::translate("MainWindow", "Create a Custom Sort Order", 0));
#endif // QT_NO_TOOLTIP
        teach_new_sort->setText(QApplication::translate("MainWindow", "Create New Sort Order", 0));
        teach_filter->setText(QString());
#ifndef QT_NO_TOOLTIP
        teach_load_file->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Load Presentation CSV File</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        teach_load_file->setText(QApplication::translate("MainWindow", "Load file...", 0));
#ifndef QT_NO_TOOLTIP
        teachPrintButton->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Print</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        teachPrintButton->setText(QApplication::translate("MainWindow", "Print", 0));
#ifndef QT_NO_TOOLTIP
        teachExportButton->setToolTip(QApplication::translate("MainWindow", "Export to pdf", 0));
#endif // QT_NO_TOOLTIP
        teachExportButton->setText(QApplication::translate("MainWindow", "Export", 0));
        teach_line_button->setText(QApplication::translate("MainWindow", "Line Chart", 0));
        teachListContentView->setText(QApplication::translate("MainWindow", "View Contents of List", 0));
        categoryTab->setTabText(categoryTab->indexOf(tabTeach), QApplication::translate("MainWindow", "Teaching", 0));
#ifndef QT_NO_TOOLTIP
        tabPub->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        pubChartFrame->setToolTip(QApplication::translate("MainWindow", "Graph Display", 0));
#endif // QT_NO_TOOLTIP
        pubGraphTitle->setText(QString());
        pubClearList->setText(QApplication::translate("MainWindow", "Clear List", 0));
#ifndef QT_NO_TOOLTIP
        pubTreeView->setToolTip(QApplication::translate("MainWindow", "Data Display", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        pub_new_sort->setToolTip(QApplication::translate("MainWindow", "Create a Custom Sort Order", 0));
#endif // QT_NO_TOOLTIP
        pub_new_sort->setText(QApplication::translate("MainWindow", "Create New Sort Order", 0));
        pub_filter_label->setText(QApplication::translate("MainWindow", "Filter by:", 0));
#ifndef QT_NO_TOOLTIP
        pubPrintButton->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Print</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pubPrintButton->setText(QApplication::translate("MainWindow", "Print", 0));
#ifndef QT_NO_TOOLTIP
        pub_delete_sort->setToolTip(QApplication::translate("MainWindow", "Delete", 0));
#endif // QT_NO_TOOLTIP
        pub_delete_sort->setText(QApplication::translate("MainWindow", "Delete", 0));
        pub_filter->setText(QString());
#ifndef QT_NO_TOOLTIP
        pub_sort->setToolTip(QApplication::translate("MainWindow", "Select Sort Order", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        pub_file_label->setToolTip(QApplication::translate("MainWindow", "File Location", 0));
#endif // QT_NO_TOOLTIP
        pub_file_label->setText(QApplication::translate("MainWindow", "No file chosen.", 0));
#ifndef QT_NO_TOOLTIP
        pub_pie_button->setToolTip(QApplication::translate("MainWindow", "Pie Chart View", 0));
#endif // QT_NO_TOOLTIP
        pub_pie_button->setText(QApplication::translate("MainWindow", "Pie Chart", 0));
        pub_sort_label->setText(QApplication::translate("MainWindow", "Select Sort Order:", 0));
        pub_to_label->setText(QApplication::translate("MainWindow", "to", 0));
        pub_filter_from->setText(QApplication::translate("MainWindow", "*", 0));
#ifndef QT_NO_TOOLTIP
        pub_load_file->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Load Presentation CSV File</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pub_load_file->setText(QApplication::translate("MainWindow", "Load file...", 0));
        pub_filter_to->setText(QApplication::translate("MainWindow", "Z", 0));
        pub_line_button->setText(QApplication::translate("MainWindow", "Line Chart", 0));
#ifndef QT_NO_TOOLTIP
        pubExportButton->setToolTip(QApplication::translate("MainWindow", "Export to pdf", 0));
#endif // QT_NO_TOOLTIP
        pubExportButton->setText(QApplication::translate("MainWindow", "Export", 0));
#ifndef QT_NO_TOOLTIP
        pub_bar_button->setToolTip(QApplication::translate("MainWindow", "Bar Chart View", 0));
#endif // QT_NO_TOOLTIP
        pub_bar_button->setText(QApplication::translate("MainWindow", "Bar Chart", 0));
        pubAddIndex->setText(QApplication::translate("MainWindow", "Add to List", 0));
        pubUndoIndex->setText(QApplication::translate("MainWindow", "Undo", 0));
        pub_scatter_button->setText(QApplication::translate("MainWindow", "Scatter Chart", 0));
        pubGraphList->setText(QApplication::translate("MainWindow", "Graph List", 0));
        pubListContentView->setText(QApplication::translate("MainWindow", "View Contents of List", 0));
        categoryTab->setTabText(categoryTab->indexOf(tabPub), QApplication::translate("MainWindow", "Publications", 0));
#ifndef QT_NO_TOOLTIP
        tabPres->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        presChartFrame->setToolTip(QApplication::translate("MainWindow", "Graph Display", 0));
#endif // QT_NO_TOOLTIP
        presGraphTitle->setText(QString());
#ifndef QT_NO_TOOLTIP
        pres_delete_sort->setToolTip(QApplication::translate("MainWindow", "Delete Button", 0));
#endif // QT_NO_TOOLTIP
        pres_delete_sort->setText(QApplication::translate("MainWindow", "Delete", 0));
#ifndef QT_NO_TOOLTIP
        pres_load_file->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Load Presentation CSV File</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pres_load_file->setText(QApplication::translate("MainWindow", "Load file...", 0));
#ifndef QT_NO_TOOLTIP
        presTreeView->setToolTip(QApplication::translate("MainWindow", "Data Display", 0));
#endif // QT_NO_TOOLTIP
        pres_filter->setText(QString());
#ifndef QT_NO_TOOLTIP
        presPrintButton->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Print</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        presPrintButton->setText(QApplication::translate("MainWindow", "Print", 0));
        pres_filter_label->setText(QApplication::translate("MainWindow", "Filter by:", 0));
#ifndef QT_NO_TOOLTIP
        pres_sort->setToolTip(QApplication::translate("MainWindow", "Sort Order Select", 0));
#endif // QT_NO_TOOLTIP
        pres_sort_label->setText(QApplication::translate("MainWindow", "Select Sort Order:", 0));
        pres_to_label->setText(QApplication::translate("MainWindow", "to", 0));
        pres_pie_button->setText(QApplication::translate("MainWindow", "Pie Chart", 0));
#ifndef QT_NO_TOOLTIP
        pres_new_sort->setToolTip(QApplication::translate("MainWindow", "Create a Custom Sort Order", 0));
#endif // QT_NO_TOOLTIP
        pres_new_sort->setText(QApplication::translate("MainWindow", "Create New Sort Order", 0));
#ifndef QT_NO_TOOLTIP
        pres_file_label->setToolTip(QApplication::translate("MainWindow", "File Location", 0));
#endif // QT_NO_TOOLTIP
        pres_file_label->setText(QApplication::translate("MainWindow", "No file chosen.", 0));
        pres_filter_from->setText(QApplication::translate("MainWindow", "*", 0));
        pres_filter_to->setText(QApplication::translate("MainWindow", "Z", 0));
        pres_bar_button->setText(QApplication::translate("MainWindow", "Bar Chart", 0));
        pres_line_button->setText(QApplication::translate("MainWindow", "Line Chart", 0));
#ifndef QT_NO_TOOLTIP
        presExportButton->setToolTip(QApplication::translate("MainWindow", "Export to pdf", 0));
#endif // QT_NO_TOOLTIP
        presExportButton->setText(QApplication::translate("MainWindow", "Export", 0));
        presUndoIndex->setText(QApplication::translate("MainWindow", "Undo", 0));
        presAddIndex->setText(QApplication::translate("MainWindow", "Add to List", 0));
        presClearList->setText(QApplication::translate("MainWindow", "Clear List", 0));
        pres_scatter_button->setText(QApplication::translate("MainWindow", "Scatter Chart", 0));
        presGraphList->setText(QApplication::translate("MainWindow", "Graph List", 0));
        presListContentView->setText(QApplication::translate("MainWindow", "View Contents of List", 0));
        categoryTab->setTabText(categoryTab->indexOf(tabPres), QApplication::translate("MainWindow", "Presentations", 0));
#ifndef QT_NO_TOOLTIP
        tabFund->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        fundChartFrame->setToolTip(QApplication::translate("MainWindow", "Graph Display", 0));
#endif // QT_NO_TOOLTIP
        fundGraphTitle->setText(QString());
        fundsClearList->setText(QApplication::translate("MainWindow", "Clear List", 0));
        fundsUndoIndex->setText(QApplication::translate("MainWindow", "Undo", 0));
        fundsAddIndex->setText(QApplication::translate("MainWindow", "Add to List", 0));
#ifndef QT_NO_TOOLTIP
        fundTreeView->setToolTip(QApplication::translate("MainWindow", "Data Display", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        fund_new_sort->setToolTip(QApplication::translate("MainWindow", "Create a Custom Sort Order", 0));
#endif // QT_NO_TOOLTIP
        fund_new_sort->setText(QApplication::translate("MainWindow", "Create New Sort Order", 0));
        fund_filter_from->setText(QApplication::translate("MainWindow", "*", 0));
        fund_filter_label->setText(QApplication::translate("MainWindow", "Filter by:", 0));
#ifndef QT_NO_TOOLTIP
        fund_delete_sort->setToolTip(QApplication::translate("MainWindow", "Delete Button", 0));
#endif // QT_NO_TOOLTIP
        fund_delete_sort->setText(QApplication::translate("MainWindow", "Delete", 0));
        fund_filter_to->setText(QApplication::translate("MainWindow", "Z", 0));
        fund_bar_button->setText(QApplication::translate("MainWindow", "Bar Chart", 0));
        fund_line_button->setText(QApplication::translate("MainWindow", "Line Chart", 0));
#ifndef QT_NO_TOOLTIP
        fund_load_file->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Load Presentation CSV File</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        fund_load_file->setText(QApplication::translate("MainWindow", "Load file...", 0));
        fund_sort_label->setText(QApplication::translate("MainWindow", "Select Sort Order:", 0));
        fund_pie_button->setText(QApplication::translate("MainWindow", "Pie Chart", 0));
#ifndef QT_NO_TOOLTIP
        fund_file_label->setToolTip(QApplication::translate("MainWindow", "File Location", 0));
#endif // QT_NO_TOOLTIP
        fund_file_label->setText(QApplication::translate("MainWindow", "No file chosen.", 0));
#ifndef QT_NO_TOOLTIP
        fundPrintButton->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Print</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        fundPrintButton->setText(QApplication::translate("MainWindow", "Print", 0));
#ifndef QT_NO_TOOLTIP
        fund_sort->setToolTip(QApplication::translate("MainWindow", "Sort Order Select", 0));
#endif // QT_NO_TOOLTIP
        fund_to_label->setText(QApplication::translate("MainWindow", "to", 0));
        fund_filter->setText(QString());
#ifndef QT_NO_TOOLTIP
        fundExportButton->setToolTip(QApplication::translate("MainWindow", "Export to pdf", 0));
#endif // QT_NO_TOOLTIP
        fundExportButton->setText(QApplication::translate("MainWindow", "Export", 0));
        fund_scatter_button->setText(QApplication::translate("MainWindow", "Scatter Chart", 0));
        fundGraphList->setText(QApplication::translate("MainWindow", "Graph List", 0));
        fundListContentView->setText(QApplication::translate("MainWindow", "View Contents of List", 0));
        categoryTab->setTabText(categoryTab->indexOf(tabFund), QApplication::translate("MainWindow", "Grants and Clinical Funding", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
