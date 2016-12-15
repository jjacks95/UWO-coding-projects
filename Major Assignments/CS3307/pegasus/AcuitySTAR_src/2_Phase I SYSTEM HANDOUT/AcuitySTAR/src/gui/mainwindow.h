#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <string>
#include <QMainWindow>
#include <vector>
#include "datamodel/UserSelectedList.h"

class RecordsManager;
class CSVReader;
class TreeModel;
class CustomSort;
class PieChartWidget;
class QListWidget;
class QTreeView;
class QCustomPlot;
class QPrinter;
class QPainter;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    QString load_file();

    void on_pres_load_file_clicked();
    void on_pub_load_file_clicked();
    void on_fund_load_file_clicked();
    void on_teach_load_file_clicked();

    void on_teach_new_sort_clicked();
    void on_pub_new_sort_clicked();
    void on_pres_new_sort_clicked();
    void on_fund_new_sort_clicked();

    void on_actionLoad_file_triggered();
    void on_actionClear_Session_for_Next_Run_triggered();
    void on_actionClear_All_Sort_Orders_triggered();

    void on_FromDate_dateChanged(const QDate &date);
    void on_ToDate_dateChanged(const QDate &date);

    void refresh(int tabIndex);

    void on_teach_sort_currentIndexChanged(int index);
    void on_pub_sort_currentIndexChanged(int index);
    void on_pres_sort_currentIndexChanged(int index);
    void on_fund_sort_currentIndexChanged(int index);

    void on_teach_delete_sort_clicked();
    void on_pub_delete_sort_clicked();
    void on_pres_delete_sort_clicked();
    void on_fund_delete_sort_clicked();

    void on_teach_pie_button_toggled();
    void on_teach_bar_button_toggled();
    void on_pub_pie_button_toggled();
    void on_pub_bar_button_toggled();
    void on_pres_pie_button_toggled();
    void on_pres_bar_button_toggled();
    void on_fund_pie_button_toggled();
    void on_fund_bar_button_toggled();

    void on_teachTreeView_clicked(const QModelIndex &index);
    void on_pubTreeView_clicked(const QModelIndex &index);
    void on_presTreeView_clicked(const QModelIndex &index);
    void on_fundTreeView_clicked(const QModelIndex &index);

    void on_categoryTab_currentChanged();

    void on_teach_filter_from_textChanged();
    void on_teach_filter_to_textChanged();
    void on_pub_filter_from_textChanged();
    void on_pub_filter_to_textChanged();
    void on_pres_filter_from_textChanged();
    void on_pres_filter_to_textChanged();
    void on_fund_filter_from_textChanged();
    void on_fund_filter_to_textChanged();

    void on_teachPrintButton_clicked();

    void on_fundPrintButton_clicked();

    void on_presPrintButton_clicked();

    void on_pubPrintButton_clicked();

    void on_teachExportButton_clicked();

    void on_fundExportButton_clicked();

    void on_presExportButton_clicked();

    void on_pubExportButton_clicked();
    void on_teach_line_button_toggled();
    void on_pub_line_button_toggled();
    void on_pres_line_button_toggled();
    void on_fund_line_button_toggled();

    void on_fund_scatter_button_toggled();

    void on_pres_scatter_button_toggled();

    void on_pub_scatter_button_toggled();

    void on_teach_scatter_button_toggled();

    void on_teachingAddIndex_clicked();

    void on_teachingUndoIndex_clicked();

    void on_teachingClearList_clicked();

    void on_pubAddIndex_clicked();

    void on_pubUndoIndex_clicked();

    void on_pubClearList_clicked();

    void on_presAddIndex_clicked();

    void on_presUndoIndex_clicked();

    void on_presClearList_clicked();

    void on_fundsAddIndex_clicked();

    void on_fundsUndoIndex_clicked();

    void on_fundsClearList_clicked();

    void on_teachGraphList_clicked();

    void on_pubGraphList_clicked();

    void on_presGraphList_clicked();

    void on_fundGraphList_clicked();

    void on_teachListContentView_clicked();

    void on_pubListContentView_clicked();

    void on_presListContentView_clicked();

    void on_fundListContentView_clicked();

private:
    static std::vector<std::string> GRANTS_MANFIELDS, PRES_MANFIELDS, PUBS_MANFIELDS, TEACH_MANFIELDS;

    enum TABS {
        TEACH, PUBLICATIONS, PRESENTATIONS, FUNDING
    };

    struct field_error;

    Ui::MainWindow* ui;
    QPrinter* printer;

    QList<QStringList> allTeachOrders, allPubOrders, allPresOrders, allFundOrders;
    QString teachPath, pubPath, presPath, fundPath;
    TreeModel *fundTree, *presTree, *pubTree, *teachTree;
    RecordsManager *funddb, *presdb, *pubdb, *teachdb;
    std::vector<std::vector<std::string>> fundData, presData, pubData, teachData;
    UserSelectedList userTeachList, userPresList, userPubList, userFundList;

    std::vector<std::string> teachSortOrder, pubSortOrder, presSortOrder, fundSortOrder;
    TreeModel* currentTree;
    RecordsManager* currentdb;
    QTreeView* currentView;
    QString teachClickedName, pubClickedName, presClickedName, fundClickedName;

    QList<bool> dateChanged;

    std::vector<std::string> getParentsList(QModelIndex &index);
    char getFilterStartChar(int type);
    char getFilterEndChar(int type);

    int yearStart, yearEnd;

    int checkFile(int index, QString filePath);
    int verifyFile(int index, QString filePath);
    //std::vector<std::string> getSelectedSortOrder(int tabIndex);
    void createDefaultSortOrder(int tabIndex);
    void makeTree(int tabIndex);

    void setupPieChart(PieChartWidget *pieChart, QListWidget *pieListWidget, std::vector<std::pair<std::string, double> > pieChartList);
    void setupBarChart(QCustomPlot *barChart, std::vector<std::pair<std::string, double> > barChartList);
    void setupLineGraph(QCustomPlot *lineChart, std::vector<std::pair <std::string, double>> lineChartList);
    void setupScatterGraph(QCustomPlot *scatterChart, std::vector<std::pair <std::string, double>> scatterChartList);

    bool handle_field_errors(std::vector<std::vector<std::string>*>& errors,
                             std::vector<std::string>& headers,
                             std::vector<std::string>& mandatory,
                             QString filePath);
    void load_fund(QString path);
    void load_pub(QString path);
    void load_teach(QString path);
    void load_pres(QString path);

    QModelIndex currentTeach, currentPub, currentPres, currentFund;
};

#endif // MAINWINDOW_H
