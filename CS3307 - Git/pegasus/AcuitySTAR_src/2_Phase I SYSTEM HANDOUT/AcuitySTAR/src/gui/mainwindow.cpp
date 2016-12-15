#include <QDate>
#include <QDebug>
#include <QDirModel>
#include <QFileDialog>
#include <QHeaderView>
#include <QMessageBox>
#include <QPainter>
#include <QPdfWriter>
#include <QPrintDialog>
#include <QPrinter>
#include <QString>
#include <fstream>
#include <string>
#include <iostream>
#include <QSortFilterProxyModel>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "CustomSort.h"
#include "ErrorEditDialog.h"
#include "savestate/statesaver.h"

#include "database/CSVReader.h"
#include "database/QSortListIO.h"
#include "database/RecordsManager.h"
#include "datamodel/TreeModel.h"
#include "datamodel/GrantFundingTreeModel.h"
#include "datamodel/PresentationTreeModel.h"
#include "datamodel/PublicationTreeModel.h"
#include "datamodel/TeachingTreeModel.h"

#define FUNDORDER_SAVE  "fundsortorder.dat"
#define PRESORDER_SAVE  "pressortorder.dat"
#define PUBORDER_SAVE   "pubsortorder.dat"
#define TEACHORDER_SAVE "teachsortorder.dat"

std::vector<std::string> MainWindow::GRANTS_MANFIELDS = {"Member Name", "Funding Type", "Status", "Peer Reviewed?", "Role", "Start Date" ,"Title", "Division"};
std::vector<std::string> MainWindow::PRES_MANFIELDS = {"Member Name", "Date", "Type", "Role", "Division","Title"};
std::vector<std::string> MainWindow::PUBS_MANFIELDS = {"Member Name", "Type", "Status Date", "Role", "Division", "Title"};
std::vector<std::string> MainWindow::TEACH_MANFIELDS = {"Member Name", "Start Date", "Program", "Division"};
StateSaver sState;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow),
    fundTree(NULL), presTree(NULL), pubTree(NULL), teachTree(NULL),
    funddb(NULL), presdb(NULL), pubdb(NULL), teachdb(NULL) {
    // draw GUI elements
    ui->setupUi(this);

    this->showMaximized();

    // set up the logo
    QPixmap logo(":/logo.png");
    ui->logo_label->setPixmap(logo);

    // set up application icon
    QIcon icon(":/icon32.ico");
    MainWindow::setWindowIcon(icon);

    // set the date format
    QString dFormat("yyyy");
    ui->FromDate->setDisplayFormat(dFormat);
    ui->ToDate->setDisplayFormat(dFormat);

    // set start year to be 1950
    QDate startDate(1950, 1, 1);

    // set ranges for spinbox
    ui->FromDate->setDateRange(startDate, QDate::currentDate());
    ui->ToDate->setDateRange(startDate, QDate::currentDate());

    // set some member variables to the current date values
    yearStart = 1950;
    yearEnd = QDate::currentDate().year();

    //default print is disabled
    ui->teachPrintButton->setEnabled(false);
    ui->fundPrintButton->setEnabled(false);
    ui->pubPrintButton->setEnabled(false);
    ui->presPrintButton->setEnabled(false);

    //default export is disabled
    ui->teachExportButton->setEnabled(false);
    ui->fundExportButton->setEnabled(false);
    ui->pubExportButton->setEnabled(false);
    ui->presExportButton->setEnabled(false);

    //Setup printer
    printer = new QPrinter();
    dateChanged = {false, false, false, false};

    //userSelectList buttons initial disable
    ui->teachingAddIndex->setEnabled(false);
    ui->teachingUndoIndex->setEnabled(false);
    ui->teachingClearList->setEnabled(false);
    ui->teachGraphList->setEnabled(false);
    ui->teachListContentView->setEnabled(false);

    ui->pubAddIndex->setEnabled(false);
    ui->pubUndoIndex->setEnabled(false);
    ui->pubClearList->setEnabled(false);
    ui->pubGraphList->setEnabled(false);
    ui->pubListContentView->setEnabled(false);

    ui->presAddIndex->setEnabled(false);
    ui->presUndoIndex->setEnabled(false);
    ui->presClearList->setEnabled(false);
    ui->presGraphList->setEnabled(false);
    ui->presListContentView->setEnabled(false);

    ui->fundsAddIndex->setEnabled(false);
    ui->fundsUndoIndex->setEnabled(false);
    ui->fundsClearList->setEnabled(false);
    ui->fundGraphList->setEnabled(false);
    ui->fundListContentView->setEnabled(false);

    std::ifstream line(PUBORDER_SAVE);
    if (!line.good()){
        createDefaultSortOrder(PUBLICATIONS);
    }line.close();

    std::ifstream line2(FUNDORDER_SAVE);
    if (!line.good()){
        createDefaultSortOrder(FUNDING);
    }line2.close();

    std::ifstream line3(PRESORDER_SAVE);
    if (!line.good()){
        createDefaultSortOrder(PRESENTATIONS);
    }line3.close();

    std::ifstream line4(TEACHORDER_SAVE);
    if (!line.good()){
        createDefaultSortOrder(TEACH);
    }line4.close();

    //If a save state file exists
    std::ifstream inFile("savestate.txt");
    if(inFile){
        //load the save state
        sState.loadState();
        std::string line;

        //get the dates from lines 1 and 2
        getline(inFile,line);
        QDate sdate(stoi(line),1,1);
        yearStart = stoi(line);

        getline(inFile,line);
        QDate edate(stoi(line),1,1);
        yearEnd = stoi(line);

        //set the dates on the gui window
        ui->FromDate->setDate(sdate);
        ui->FromDate->dateChanged(sdate);
        ui->ToDate->setDate(edate);
        ui->ToDate->dateChanged(edate);

        //open the files from lines 3-6
        //Teach File
        getline(inFile,line);
        if(line != ""){
            //get the teach file
            QString path = QString::fromStdString(line);
            checkFile(TEACH,path);
            //load the teach file
            load_teach(path);
        }

        //Pub File
        getline(inFile,line);
        if(line != ""){
            //get the pubfile
            QString path = QString::fromStdString(line);
            checkFile(PUBLICATIONS,path);
            //open the pubfile
            load_pub(line.c_str());
        }

        //Pres File
        getline(inFile,line);
        if(line != ""){
            //get the presfile
            QString path = QString::fromStdString(line);
            checkFile(PRESENTATIONS,path);
            //open the presfile
            load_pres(line.c_str());
        }

        //Fund/Grant File
        getline(inFile,line);
        if(line != ""){
            //get the grantfile
            QString path = QString::fromStdString(line);
            checkFile(FUNDING,path);
            //open the grant file
            load_fund(line.c_str());
        }
    } else {
        //if there is no save state file, create one by saving an empty state to be updated
        std::ofstream newFile("savestate.txt");
        sState.saveState();

        //set to the default dates for sorting
        ui->FromDate->setDate(startDate);
        ui->FromDate->dateChanged(startDate);
        ui->ToDate->setDate(QDate::currentDate());
        ui->ToDate->dateChanged(QDate::currentDate());
    }

    ui->teachingListCounter->setPalette(Qt::blue);
    ui->presListCounter->setPalette(Qt::blue);
    ui->pubListCounter->setPalette(Qt::blue);
    ui->fundsListCounter->setPalette(Qt::blue);

    //Add the divison sorts to the Combo Boxes

    QStringList teachList = QStringList();
    for (int i=0;i<(int)TEACH_MANFIELDS.size();i++){
        QString str = QString::fromStdString(TEACH_MANFIELDS.at(i));
        teachList << str;
    }
    teachList << "User Selected List";

    QStringList pubList = QStringList();
    for (int i=0;i<(int)PUBS_MANFIELDS.size();i++){
        QString str = QString::fromStdString(PUBS_MANFIELDS.at(i));
        pubList << str;
    }
    pubList << "User Selected List";

    QStringList presList = QStringList();
    for (int i=0;i<(int)PRES_MANFIELDS.size();i++){
        QString str = QString::fromStdString(PRES_MANFIELDS.at(i));
        presList << str;
    }
    presList << "User Selected List";

    QStringList fundList = QStringList();
    for (int i=0;i<(int)GRANTS_MANFIELDS.size();i++){
        QString str = QString::fromStdString(GRANTS_MANFIELDS.at(i));
        fundList << str;
    }
    fundList << "User Selected List";
}

MainWindow::~MainWindow() {
    delete ui;

    delete fundTree;
    delete presTree;
    delete pubTree;
    delete teachTree;

    delete funddb;
    delete presdb;
    delete pubdb;
    delete teachdb;
    delete printer;
}

/* This method deals with loading one or multiples CSV files possibly of
 * diffrent types (Grants & fundings, Publications, Teachings, Presentations).
 * This method checks the files correctness and type before loading them.
 * If it happens that multiples files of the same types has been selected by the
 * user, only the first on encountered of each type will be loaded. Warning pop-up
 * windows will inform the user about the files that have been discarded.
 */
void MainWindow::on_actionLoad_file_triggered() {

    // Get all the file paths
    QStringList filePaths = QFileDialog::getOpenFileNames(this,
                                                          "Select one or more files to load",
                                                          QDir::currentPath(),
                                                          tr("CSV (*.csv);; All files (*.*)"));

    // If we actually have any files paths selected
    if (filePaths.size() > 0) {

        const int NUM_TABS = 4; // We cannot load more than 4 files at a time, one for each category tab

        // alreadyLoadedType[specific_type] becomes true when we already loaded a file of that time.
        bool alreadyLoadedType[NUM_TABS] = {false, false, false, false}; // Warning: This line will break if NUM_TABS constant is changed.
        QStringList sortedPaths;

        for (int i=0;i<4;i++){
            QStringList::Iterator sort = filePaths.begin();

            while (sort != filePaths.end()) { // While there are files in the iterator
                switch (i){
                case 0:
                    if (verifyFile(PRESENTATIONS, sort[0]) == EXIT_SUCCESS){
                        sortedPaths.insert(sortedPaths.end(),sort[0]);
                        sort=filePaths.end();
                    }
                    break;
                case 1:
                    if (verifyFile(PUBLICATIONS, sort[0]) == EXIT_SUCCESS){
                        sortedPaths.insert(sortedPaths.end(),sort[0]);
                        sort=filePaths.end();
                    }

                    break;
                case 2:
                    if (verifyFile(TEACH, sort[0]) == EXIT_SUCCESS){
                        sortedPaths.insert(sortedPaths.end(),sort[0]);
                        sort=filePaths.end();
                    }
                    break;

                case 3:
                    if (verifyFile(FUNDING, sort[0]) == EXIT_SUCCESS){
                        sortedPaths.insert(sortedPaths.end(),sort[0]);
                        sort=filePaths.end();
                    }
                    break;
                }
                if (sort != filePaths.end())
                    sort++;
            }
        }

        QStringList::Iterator sort = filePaths.begin();
        while (sort != filePaths.end()) { // While there are files in the iterator
            bool found = false;
            for (int i=0; i<sortedPaths.size(); i++){
                if ((QString)sort[0] == (QString)sortedPaths.at(i)){
                    found=true;
                }
                if (found)
                    break;
            }
            if(!found){
                sortedPaths.insert(sortedPaths.end(),sort[0]);
            }
           sort++;
        }



        // Setup an iterator over the file paths
        QStringList::Iterator it = sortedPaths.begin();

        while (it != sortedPaths.end()) { // While there are files in the iterator

            // Extract the current path from the iterator
            QString path = it[0];

            /* N.B: If we are asked to load multiple CSV files of the same type,
             *      we do load only the first one ecountered of each type, and leave
             *      a warning message saying that we discard the others.
             */

            if (checkFile(FUNDING, path) == EXIT_SUCCESS) { // If it is a grants and fundings file
                if (alreadyLoadedType[FUNDING]) { // If we've opened a grants and fundings file
                    QMessageBox::critical(this, "Multiple Grants & Fundings Files",
                                          "Already loaded a Grants & Fundings file.\nDiscarded: " + path.section('/', -1, -1));
                } else { // Else we're good, we can load the file.
                    ui->categoryTab->setCurrentIndex(FUNDING);
                    load_fund(path);
                    alreadyLoadedType[FUNDING] = true;
                    //refresh(FUNDING);
                    //save the current file for the save state. Then update the state file in memory
                    sState.loadState();
                    sState.setGrantFile(path.toStdString());
                    sState.saveState();
                }
            } else if (checkFile(TEACH, path) == EXIT_SUCCESS) { // If it is a teaching file
                if (alreadyLoadedType[TEACH]) { // If we've opened a teaching file
                    QMessageBox::critical(this, "Multiple Teachings Files",
                                          "Already loaded a Teachings file.\nDiscarded: " + path.section('/', -1, -1));
                } else { // Else we're good, we can load the file.
                    ui->categoryTab->setCurrentIndex(TEACH);
                    load_teach(path);
                    alreadyLoadedType[TEACH] = true;
                    //refresh(TEACH);
                    //save the current file for the save state. Then update the state file in memory
                    sState.loadState();
                    sState.setTeachFile(path.toStdString());
                    sState.saveState();
                }
            } else if (checkFile(PUBLICATIONS, path) == EXIT_SUCCESS) { // If it is a publication file
                if (alreadyLoadedType[PUBLICATIONS]) { // If we've opened a publication file
                    QMessageBox::critical(this, "Multiple Publications Files",
                                          "Already loaded a Publication file.\nDiscarded: " + path.section('/', -1, -1));
                } else { // Else we're good, we can load the file.
                    ui->categoryTab->setCurrentIndex(PUBLICATIONS);
                    load_pub(path);
                    alreadyLoadedType[PUBLICATIONS] = true;
                    //refresh(PUBLICATIONS);
                    //save the current file for the save state. Then update the state file in memory
                    sState.loadState();
                    sState.setPubFile(path.toStdString());
                    sState.saveState();
                }
            } else if (checkFile(PRESENTATIONS, path) == EXIT_SUCCESS) { // If it is a presentation file
                if (alreadyLoadedType[PRESENTATIONS]) { // If we've opened a presentation file
                    QMessageBox::critical(this, "Multiple Presentations Files",
                                          "Already loaded a Presentation file.\nDiscarded file: " + path.section('/', -1, -1));
                } else { // Else we're good, we can load the file.
                    ui->categoryTab->setCurrentIndex(PRESENTATIONS);
                    load_pres(path);
                    alreadyLoadedType[PRESENTATIONS] = true;
                    //refresh(PRESENTATIONS);
                    //save the current file for the save state. Then update the state file in memory
                    sState.loadState();
                    sState.setPresFile(path.toStdString());
                    sState.saveState();
                }

            }
            ++it; // Continue with the next filePath in the iterator.
        }
    }
}

void MainWindow::on_actionClear_Session_for_Next_Run_triggered() {
    sState.clearState();
}

void MainWindow::on_actionClear_All_Sort_Orders_triggered() {

    for (int i= allPubOrders.size()-1;i>=0;i--){
        allPubOrders.pop_back();
        ui->pub_sort->removeItem(i);
    }
    remove(PUBORDER_SAVE);
    createDefaultSortOrder(PUBLICATIONS);

    for (int i= allFundOrders.size()-1;i>=0;i--){
        allFundOrders.pop_back();
        ui->fund_sort->removeItem(i);
    }
    remove(FUNDORDER_SAVE);
    createDefaultSortOrder(FUNDING);

    for (int i= allPresOrders.size()-1;i>=0;i--){
        allPresOrders.pop_back();
        ui->pres_sort->removeItem(i);
    }
    remove(PRESORDER_SAVE);
    createDefaultSortOrder(PRESENTATIONS);

    for (int i= allTeachOrders.size()-1;i>=0;i--){
        allTeachOrders.pop_back();
        ui->teach_sort->removeItem(i);
    }
    remove(TEACHORDER_SAVE);
    createDefaultSortOrder(TEACH);
}

/*
 * When the load file button is clicked a file open dialog box
 * is opened.  If a file name is successfully returned, makeTree()
 * is called.
 */
QString MainWindow::load_file() {
    QString filePath = QFileDialog::getOpenFileName(this, "Open File", QDir::currentPath(),
                                                    tr("CSV (*.csv);; All files (*.*)"));

    if (!filePath.isEmpty()) {
        return filePath;
    } else {
        return "";
    }
}

void MainWindow::refresh(int tabIndex) {
    // if we've loaded in a file, update that data
    switch (tabIndex) {
    case FUNDING:
        if (!fundPath.isEmpty()) {
            makeTree(FUNDING);
            ui->fund_graph_stackedWidget->hide();
            ui->fundGraphTitle->clear();
        }
        break;

    case PRESENTATIONS:
        if (!presPath.isEmpty()) {
            makeTree(PRESENTATIONS);
            ui->pres_graph_stackedWidget->hide();
            ui->presGraphTitle->clear();
        }
        break;
    case PUBLICATIONS:
        if (!pubPath.isEmpty()) {
            makeTree(PUBLICATIONS);
            ui->pub_graph_stackedWidget->hide();
            ui->pubGraphTitle->clear();
        }
        break;

    case TEACH:
        if (!teachPath.isEmpty()) {
            makeTree(TEACH);
            ui->teach_graph_stackedWidget->hide();
            ui->teachGraphTitle->clear();
        }
        break;
    }
}

int MainWindow::checkFile(int index, QString filePath) {
    CSVReader reader;
    std::vector<std::string> header;
    std::string searchstring;

    int sortHeaderIndex = 2;

    switch (index) {

    case TEACH:
        // read if first or if a new file is loaded
        if (teachPath.isEmpty() || (!teachPath.isEmpty() && filePath.compare(teachPath))) {
            // create a new reader to read in the file
            reader = CSVReader(filePath.toStdString());
            header = reader.getHeaders();

            // create a new manager for the data
            delete teachdb;
            teachdb = new RecordsManager(&header);

            // check for right file type by searching for unique header
            searchstring = "Program";
            if (std::find(header.begin(), header.end(), searchstring) != header.end()) {
                // load in data into the manager, with the date as the key
                sortHeaderIndex = teachdb->getHeaderIndex("Start Date");
                teachData = reader.getData();
                std::vector<std::vector<std::string>*> f_errs;
                unsigned int j;
                for (int i = 0; i < (int) teachData.size(); i++) {
                    for (j = 0; j < TEACH_MANFIELDS.size(); j++) {
                        int index = teachdb->getHeaderIndex(TEACH_MANFIELDS[j]);
                        if (teachData[i][index].compare("") == 0) {
                            f_errs.push_back(&teachData[i]);
                            break;
                        }
                    }

                    // if all mandatory fields are okay
                    if (j == TEACH_MANFIELDS.size()) {
                        // date interpretation
                        int yrIndex = teachdb->getHeaderIndex("Start Date");
                        int year;
                        sscanf(teachData[i][yrIndex].c_str(), "%4d", &year);
                        teachData[i][yrIndex] = std::to_string(year);

                        teachdb->addRecord(reader.parseDateString(teachData[i][sortHeaderIndex]), &teachData[i]);
                    }
                }

                if (f_errs.size() > 0) {
                    if(handle_field_errors(f_errs, header, TEACH_MANFIELDS, filePath)) {
                        for (unsigned int i = 0; i < f_errs.size(); i++) {
                            teachdb->addRecord(reader.parseDateString((*(f_errs[i]))[sortHeaderIndex]), f_errs[i]);
                        }
                    }
                }
            } else {
                return EXIT_FAILURE;
            }
        } else {
            return EXIT_SUCCESS;
        }

        //Disable - Dont need this at this point
        //   ui->teachPrintButton->setEnabled(true);
        //   ui->teachExportButton->setEnabled(true);
        break;

    case PUBLICATIONS:
        // read if first or if a new file is loaded
        if (pubPath.isEmpty() || (!pubPath.isEmpty() && filePath.compare(pubPath))) {
            // create a new reader to read in the file
            reader = CSVReader(filePath.toStdString());
            header = reader.getHeaders();

            // create a new manager for the data
            delete pubdb;
            pubdb = new RecordsManager(&header);

            // check for right file type by searching for unique header
            searchstring = "Publication Status";
            if (std::find(header.begin(), header.end(), searchstring) != header.end()) {
                // load in data into the manager, with the date as the key
                sortHeaderIndex = pubdb->getHeaderIndex("Status Date");
                pubData = reader.getData();
                std::vector<std::vector<std::string>*> f_errs;
                unsigned int j;
                for (int i = 0; i < (int) pubData.size(); i++) {
                    for (j = 0; j < PUBS_MANFIELDS.size(); j++) {
                        int index = pubdb->getHeaderIndex(PUBS_MANFIELDS[j]);
                        if (pubData[i][index].compare("") == 0) {
                            f_errs.push_back(&pubData[i]);
                            break;
                        }
                    }

                    // if all mandatory fields are okay
                    if (j == PUBS_MANFIELDS.size()) {
                        // date interpretation
                        int yrIndex = pubdb->getHeaderIndex("Status Date");
                        int year;
                        sscanf(pubData[i][yrIndex].c_str(), "%4d", &year);
                        pubData[i][yrIndex] = std::to_string(year);

                        pubdb->addRecord(reader.parseDateString(pubData[i][sortHeaderIndex]), &pubData[i]);
                    }
                }

                if (f_errs.size() > 0) {
                    if(handle_field_errors(f_errs, header, PUBS_MANFIELDS, filePath)) {
                        for (unsigned int i = 0; i < f_errs.size(); i++) {
                            pubdb->addRecord(reader.parseDateString((*(f_errs[i]))[sortHeaderIndex]), f_errs[i]);
                        }
                    }
                }
            } else {
                return EXIT_FAILURE;
            }
        } else {
            return EXIT_SUCCESS;
        }

        //Disbale
        //        ui->pubPrintButton->setEnabled(true);
        //       ui->pubExportButton->setEnabled(true);
        break;

    case PRESENTATIONS:
        // read if first or if a new file is loaded
        if (presPath.isEmpty() || (!presPath.isEmpty() && filePath.compare(presPath))) {
            // create a new reader to read in the file
            reader = CSVReader(filePath.toStdString());
            header = reader.getHeaders();

            // create a new manager for the data
            delete presdb;
            presdb = new RecordsManager(&header);

            // check for right file type by searching for unique header
            searchstring = "Activity Type";
            if (std::find(header.begin(), header.end(), searchstring) != header.end()) {
                // load in data into the manager, with the date as the key
                sortHeaderIndex = presdb->getHeaderIndex("Date");
                presData = reader.getData();
                std::vector<std::vector<std::string>*> f_errs;
                unsigned int j = 0;
                for (int i = 0; i < (int) presData.size(); i++) {
                    //check through mandatory fields for empty fields
                    for (j = 0; j < PRES_MANFIELDS.size(); j++) {
                        int index = presdb->getHeaderIndex(PRES_MANFIELDS[j]);
                        if (presData[i][index].compare("") == 0) {
                            f_errs.push_back(&presData[i]);
                            break;
                        }
                    }

                    // if all mandatory fields are okay
                    if (j == PRES_MANFIELDS.size()) {
                        // date interpretation
                        int yrIndex = presdb->getHeaderIndex("Date");
                        int year;
                        sscanf(presData[i][yrIndex].c_str(), "%4d", &year);
                        presData[i][yrIndex] = std::to_string(year);

                        presdb->addRecord(reader.parseDateString(presData[i][sortHeaderIndex]), &presData[i]);
                    }
                }

                if (f_errs.size() > 0) {
                    if(handle_field_errors(f_errs, header, PRES_MANFIELDS, filePath)) {
                        for (unsigned int i = 0; i < f_errs.size(); i++) {
                            presdb->addRecord(reader.parseDateString((*(f_errs[i]))[sortHeaderIndex]), f_errs[i]);
                        }
                    }
                }
            } else {
                return EXIT_FAILURE;
            }
        } else {
            return EXIT_SUCCESS;
        }
        //       ui->presPrintButton->setEnabled(true);
        //       ui->presExportButton->setEnabled(true);
        break;

    case FUNDING:
        // read if first or if a new file is loaded
        if (fundPath.isEmpty() || (!fundPath.isEmpty() && filePath.compare(fundPath))) {
            // create a new reader to read in the file
            reader = CSVReader(filePath.toStdString());
            header = reader.getHeaders();

            // create a new manager for the data
            delete funddb;
            funddb = new RecordsManager(&header);

            // check for right file type by searching for unique header
            searchstring = "Funding Type";

            if (std::find(header.begin(), header.end(), searchstring) != header.end()) {
                // load in data into the manager, with the date as the key
                sortHeaderIndex = funddb->getHeaderIndex("Start Date");
                fundData = reader.getData();
                std::vector<std::vector<std::string>*> f_errs;
                unsigned int j;
                for (int i = 0; i < (int) fundData.size(); i++) {
                    for (j = 0; j < GRANTS_MANFIELDS.size(); j++) {
                        int index = funddb->getHeaderIndex(GRANTS_MANFIELDS[j]);
                        if (fundData[i][index].compare("") == 0) {
                            f_errs.push_back(&fundData[i]);
                            break;
                        }
                    }

                    // if all mandatory fields are okay
                    if (j == GRANTS_MANFIELDS.size()) {
                        // date interpretation
                        int yrIndex = funddb->getHeaderIndex("Start Date");
                        int year;
                        sscanf(fundData[i][yrIndex].c_str(), "%4d", &year);
                        fundData[i][yrIndex] = std::to_string(year);

                        // boolean interpretation
                        int prIndex = funddb->getHeaderIndex("Peer Reviewed?");
                        if (fundData[i][prIndex].compare("True") == 0) {
                            fundData[i][prIndex] = "Peer Reviewed";
                        } else {
                            fundData[i][prIndex] = "Not Peer Reviewed";
                        }
                        funddb->addRecord(reader.parseDateString(fundData[i][sortHeaderIndex]), &fundData[i]);
                    }
                }
                if (f_errs.size() > 0) {
                    if(handle_field_errors(f_errs, header, GRANTS_MANFIELDS, filePath)) {
                        for (unsigned int i = 0; i < f_errs.size(); i++) {
                            funddb->addRecord(reader.parseDateString((*(f_errs[i]))[sortHeaderIndex]), f_errs[i]);
                        }
                    }
                }
            } else {
                return EXIT_FAILURE;
            }
        } else {
            return EXIT_SUCCESS;
        }

        //Disable the following
        // ui->fundPrintButton->setEnabled(true);
        // ui->fundExportButton->setEnabled(true);
        break;
    }
    return EXIT_SUCCESS;
}


int MainWindow::verifyFile(int index, QString filePath) {
    CSVReader reader;
    std::vector<std::string> header;
    std::string searchstring;

    switch (index) {

    case TEACH:
        // read if first or if a new file is loaded
        if (teachPath.isEmpty() || (!teachPath.isEmpty() && filePath.compare(teachPath))) {
            // create a new reader to read in the file
            reader = CSVReader(filePath.toStdString());
            header = reader.getHeaders();

            // check for right file type by searching for unique header
            searchstring = "Program";
            if (std::find(header.begin(), header.end(), searchstring) != header.end()) {
                return EXIT_SUCCESS;
            } else {
                return EXIT_FAILURE;
            }
        } else {
            return EXIT_SUCCESS;
        }
        break;

    case PUBLICATIONS:
        // read if first or if a new file is loaded
        if (pubPath.isEmpty() || (!pubPath.isEmpty() && filePath.compare(pubPath))) {
            // create a new reader to read in the file
            reader = CSVReader(filePath.toStdString());
            header = reader.getHeaders();


            // check for right file type by searching for unique header
            searchstring = "Publication Status";
            if (std::find(header.begin(), header.end(), searchstring) != header.end()) {
                return EXIT_SUCCESS;
            } else {
                return EXIT_FAILURE;
            }
        } else {
            return EXIT_SUCCESS;
        }
        break;

    case PRESENTATIONS:
        // read if first or if a new file is loaded
        if (presPath.isEmpty() || (!presPath.isEmpty() && filePath.compare(presPath))) {
            // create a new reader to read in the file
            reader = CSVReader(filePath.toStdString());
            header = reader.getHeaders();


            // check for right file type by searching for unique header
            searchstring = "Activity Type";
            if (std::find(header.begin(), header.end(), searchstring) != header.end()) {
                return EXIT_SUCCESS;
            } else {
                return EXIT_FAILURE;
            }
        } else {
            return EXIT_SUCCESS;
        }
        break;

    case FUNDING:
        // read if first or if a new file is loaded
        if (fundPath.isEmpty() || (!fundPath.isEmpty() && filePath.compare(fundPath))) {
            // create a new reader to read in the file
            reader = CSVReader(filePath.toStdString());
            header = reader.getHeaders();

            // check for right file type by searching for unique header
            searchstring = "Funding Type";

            if (std::find(header.begin(), header.end(), searchstring) != header.end()) {
                return EXIT_SUCCESS;
            } else {
                return EXIT_FAILURE;
            }
        } else {
            return EXIT_SUCCESS;
        }

        break;
    }
    return EXIT_SUCCESS;
}


void MainWindow::createDefaultSortOrder(int tabIndex) {
    QStringList defaultOrder;
    defaultOrder << "Default";

    switch (tabIndex) {
    case FUNDING:
        {
        // specify default sort order
        defaultOrder << "Member Name" << "Funding Type" << "Peer Reviewed?" << "Status" << "Role" << "Title";

        // add default list to member variable
        allFundOrders << defaultOrder;

        // save the default for the user
        QSortListIO saveFundSort(FUNDORDER_SAVE);
        saveFundSort.saveList(allFundOrders);
    }

        break;
    case PRESENTATIONS:
    {
        // specify default sort order
        defaultOrder << "Member Name" << "Type" << "Role" << "Title";

        // add default list to member variable
        allPresOrders << defaultOrder;

        // save the default for the user
        QSortListIO savePresSort(PRESORDER_SAVE);
        savePresSort.saveList(allPresOrders);
    }

        break;
    case PUBLICATIONS:
    {
        // specify default sort order
        defaultOrder << "Member Name" << "Type" << "Role" << "Title";

        // add default list to member variable
        allPubOrders << defaultOrder;

        // save the default for the user
        QSortListIO savePubSort(PUBORDER_SAVE);
        savePubSort.saveList(allPubOrders);
    }

        break;
    case TEACH:
    {
        // specify default sort order
        defaultOrder << "Member Name" << "Program";

        // add default list to member variable
        allTeachOrders << defaultOrder;

        // save the default for the user
        QSortListIO saveTeachSort(TEACHORDER_SAVE);
        saveTeachSort.saveList(allTeachOrders);
    }

        break;
    }
}

/*
 * err: vector of pointers to record entries.
 * headers: vector of strings containing the db headers
 * mandatory: vector of strings containing the mandatory fields in the db
 *
 * Returns true when the passed err vector contains edited fields.
 * Returns false when no fields have been edited.
 */
bool MainWindow::handle_field_errors(std::vector<std::vector<std::string>*>& err,
                                     std::vector<std::string>& headers,
                                     std::vector<std::string>& mandatory,
                                     QString filePath) {
    //Since CSVReader alldata contains completely empty records
    //remove them first.
    std::vector<std::vector<std::string>*>::iterator it;
    for (it = err.begin(); it != err.end(); it++) {
        bool allEmpty = true;
        for (int col = 0; col < (int) (*it)->size(); col++) {
            if ((*it)->at(col).compare("") != 0) {
                allEmpty = false;
            }
        }
        if (allEmpty) {
            it = err.erase(it);
            it--;
        }
    }
    //Return false; there are no errors to correct
    if (err.size() == 0) {
        return false;
    }
    QMessageBox prompt;
    QString mainText = "File: ";
    mainText.append(filePath.section('/', -1, -1)); // Get the last element of the filePath (= the file name)
    mainText.append("\ncontains ");
    mainText.append(QString::number(err.size()));
    mainText.append(" records with missing mandatory fields.");
    prompt.setText(mainText);
    prompt.setInformativeText("Do you want to edit these entries or discard?");
    prompt.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    prompt.setDefaultButton(QMessageBox::Yes);
    prompt.setButtonText(QMessageBox::Yes, "Edit");
    prompt.setButtonText(QMessageBox::No, "Discard");
    prompt.setWindowIcon(QIcon(":/icon32.ico"));
    int ret = prompt.exec();

    switch (ret) {
    case QMessageBox::Yes: {
        ErrorEditDialog diag(this, err, headers, mandatory);
        if(diag.exec()) {
            return true;
        }
        return false;
    }

    case QMessageBox::No:
    default:
        return false;
    }
}

/*
 * Builds a TreeModel for the ui's embedded treeview.
 */
void MainWindow::makeTree(int tabIndex) {
    switch (tabIndex) {
    case TEACH:

        // set up some member variables to point to the current data in use
        currentdb = teachdb;
        delete teachTree;
        teachTree = new TeachingTreeModel(currentdb);
        currentTree = teachTree;

        // get some UI elements so we can put the tree and graphs into them
        currentView = ui->teachTreeView;

        /*Created this if-else statement for checking if sorting A to Z is not inputted incorrectly */
        //if (getFilterStartChar(TEACH) > getFilterEndChar(TEACH)){
        //   QMessageBox::critical(this, "", "Must Sort from Smallest to Largest");
        //currentTree->setupModel(yearStart, yearEnd, teachSortOrder, getFilterEndChar(TEACH), getFilterStartChar(TEACH));

        //}else{
        // analyze the data into a tree

        currentTree->setupModel(yearStart, yearEnd, teachSortOrder, getFilterStartChar(TEACH), getFilterEndChar(TEACH));
        //}
        ui->teach_pie_button->toggle();

        break;

    case PUBLICATIONS:
        // set up some member variables to point to the current data in use
        currentdb = pubdb;
        delete pubTree;
        pubTree = new PublicationTreeModel(currentdb);
        currentTree = pubTree;

        // get some UI elements so we can put the tree and graphs into them
        currentView = ui->pubTreeView;

        /*Created this if-else statement for checking if sorting A to Z is not inputted incorrectly */
        //if (getFilterStartChar(PUBLICATIONS) > getFilterEndChar(PUBLICATIONS)){
        //   QMessageBox::critical(this, "", "Must Sort from Smallest to Largest");
        //currentTree->setupModel(yearStart, yearEnd, teachSortOrder, getFilterEndChar(PUBLICATIONS), getFilterStartChar(PUBLICATIONS));

        //}else{
        // analyze the data into a tree
        currentTree->setupModel(yearStart, yearEnd, pubSortOrder, getFilterStartChar(PUBLICATIONS), getFilterEndChar(PUBLICATIONS));
        //}
        ui->pub_pie_button->toggle();

        break;
    case PRESENTATIONS:
        // set up some member variables to point to the current data in use
        currentdb = presdb;
        delete presTree;

        presTree = new PresentationTreeModel(currentdb);
        currentTree = presTree;

        // get some UI elements so we can put the tree and graphs into them
        currentView = ui->presTreeView;

        /*Created this if-else statement for checking if sorting A to Z is not inputted incorrectly */
        //if (getFilterStartChar(PRESENTATIONS) > getFilterEndChar(PRESENTATIONS)){
        //  QMessageBox::critical(this, "", "Must Sort from Smallest to Largest");
        //currentTree->setupModel(yearStart, yearEnd, teachSortOrder, getFilterEndChar(PRESENTATIONS), getFilterStartChar(PRESENTATIONS));

        //}else{
        // analyze the data into a tree
        currentTree->setupModel(yearStart, yearEnd, presSortOrder, getFilterStartChar(PRESENTATIONS), getFilterEndChar(PRESENTATIONS));
        //}
        ui->pres_pie_button->toggle();

        break;

    case FUNDING:
        // set up some member variables to point to the current data in use
        currentdb = funddb;
        delete fundTree;
        fundTree = new GrantFundingTreeModel(currentdb);
        currentTree = fundTree;

        // get some UI elements so we can put the tree and graphs into them
        currentView = ui->fundTreeView;
        /*Created this if-else statement for checking if sorting A to Z is not inputted incorrectly */
        //if (getFilterStartChar(FUNDING) > getFilterEndChar(FUNDING)){
        //  QMessageBox::critical(this, "", "Must Sort from Smallest to Largest");
        //currentTree->setupModel(yearStart, yearEnd, teachSortOrder, getFilterEndChar(FUNDING), getFilterStartChar(FUNDING));

        //}else{
        // analyze the data into a tree
        currentTree->setupModel(yearStart, yearEnd, fundSortOrder, getFilterStartChar(FUNDING), getFilterEndChar(FUNDING));
        //}
        ui->fund_pie_button->toggle();

        break;
    }

    // set up the tree in our UI
    QSortFilterProxyModel *sortWrapTreeView = new QSortFilterProxyModel(currentView);
    sortWrapTreeView->setSourceModel(currentTree);
    //sets Strings to be sorted based on letter, not ASCII code of an Upper/Lower case letter
    sortWrapTreeView->setSortCaseSensitivity(Qt::CaseInsensitive);
    currentView->setModel(sortWrapTreeView);
    //Sets the default header sort to Ascending Order in the Names Column
    currentView->header()->setSortIndicator(0, Qt::AscendingOrder);
    //Set the headers to be clickable to allow ascending/descending sorting.
    currentView->setSortingEnabled(true);
    currentView->setAnimated(true);
    // set resize property to ResizeToContents to prevent shrinkage of header width's on CSV file load
    currentView->header()->resizeSections(QHeaderView::ResizeToContents);
}

void MainWindow::setupPieChart(PieChartWidget* pieChart, QListWidget *pieListWidget, std::vector<std::pair <std::string, double>> pieChartList) {
    // draws the pie graph by sending piechartwidget a vector of name, presentation count
    int pieSize = (int) pieChartList.size();
    QVector<QColor> colorList(pieSize);
    pieListWidget->clear();
    for (int i = 0; i < pieSize; i++) {
        colorList[i] = (QColor(qrand() % 256, qrand() % 256, qrand() % 256));
        pieListWidget->addItem(QString::fromStdString(pieChartList[i].first));

        // set legend colors
        QPixmap pixmap(100, 100);
        pixmap.fill(QColor(colorList[i]));
        QIcon tempIcon(pixmap);
        pieListWidget->item(i)->setIcon(tempIcon);
    }

    pieChart->setData(pieChartList, colorList); //passes vector list to piechartwidget
}

void MainWindow::setupBarChart(QCustomPlot *barChart, std::vector<std::pair <std::string, double>> barChartList) {
    // create empty bar chart objects:
    QCPBars *yLabels = new QCPBars(barChart->yAxis, barChart->xAxis);
    barChart->addPlottable(yLabels);

    // set names and colors:
    QPen pen;
    pen.setWidthF(1.2);
    yLabels->setName("Type");
    pen.setColor(QColor(255, 131, 0));
    yLabels->setPen(pen);
    yLabels->setBrush(QColor(255, 131, 0, 50));

    //get label list
    int barSize = (int) barChartList.size();
    double maxCount = 0;
    double scaledCount;
    QVector<double> ticks;
    QVector<QString> ylabels;
    QVector<double> count;

    //add label list to y axis labels
    for (int i = 0; i < barSize; i++){
        //ticks << (i+1);
        //ylabels << QString::fromStdString(lineChartList[i].first);
        if (barChartList[i].second>1000000){
            //scaledCount = lineChartList[i].second/1000000;
        } else if (barChartList[i].second>1000){
            //scaledCount = lineChartList[i].second/1000;
        } else{
            //scaledCount = lineChartList[i].second;
        }
        //count <<scaledCount;

        if (maxCount < barChartList[i].second)
            maxCount = barChartList[i].second;
    }

    //add label list to y axis labels
    for (int i = 0; i < barSize; i++){
        ticks << (i+1);
        QString label = QString::fromStdString(barChartList[i].first);
        if(label.size()>23){
            label.resize(20);
            label.resize(23,'.');
        }
        ylabels << label;
        //ylabels << QString::fromStdString(barChartList[i].first);
        if (maxCount>1000000){
            scaledCount = barChartList[i].second/1000000;
        } else if (maxCount>1000){
            scaledCount = barChartList[i].second/1000;
        } else{
            scaledCount = barChartList[i].second;
        }
        count <<scaledCount;

        if (maxCount < barChartList[i].second)
            maxCount = barChartList[i].second;
    }

    //setup Y Axis
    barChart->yAxis->setAutoTicks(false);
    barChart->yAxis->setAutoTickLabels(false);
    barChart->yAxis->setTickVector(ticks);
    barChart->yAxis->setTickVectorLabels(ylabels);
    barChart->yAxis->setTickLabelPadding(1);
    barChart->yAxis->setSubTickCount(0);
    barChart->yAxis->setTickLength(0, 1);
    barChart->yAxis->grid()->setVisible(true);
    barChart->yAxis->setRange(0, barSize+1);

    if(maxCount>1000000){
        maxCount = maxCount/1000000;
        barChart->xAxis->setLabel("Total (in Millions)");
    }else if (maxCount>1000){
        maxCount = maxCount/1000;
        barChart->xAxis->setLabel("Total (in Thousands)");
    }else{
        barChart->xAxis->setLabel("Total");
    }

    // setup X Axis
    barChart->xAxis->setAutoTicks(true);
    barChart->xAxis->setRange(0,maxCount+(maxCount*.10));
    barChart->xAxis->setAutoTickLabels(true);
    barChart->xAxis->setAutoTickStep(true);
    barChart->xAxis->grid()->setSubGridVisible(true);

    QPen gridPen;
    gridPen.setStyle(Qt::SolidLine);
    gridPen.setColor(QColor(0, 0, 0, 25));
    barChart->xAxis->grid()->setPen(gridPen);
    gridPen.setStyle(Qt::DotLine);
    barChart->xAxis->grid()->setSubGridPen(gridPen);

    yLabels->setData(ticks, count);
}

//setupLineGraph function
void MainWindow::setupLineGraph(QCustomPlot *lineChart, std::vector<std::pair <std::string, double>> lineChartList){
    // create empty bar chart objects:
    QCPGraph *yLabels = new QCPGraph(lineChart->xAxis, lineChart->yAxis);
    lineChart->addPlottable(yLabels);

    // set names and colors:
    QPen pen;
    lineChart->addGraph();
    lineChart->graph(0)->setLineStyle(QCPGraph::lsLine);
    lineChart->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 4));
    pen.setStyle(Qt::SolidLine);
    pen.setWidth(4);
    yLabels->setName("Type");
    pen.setColor(QColor(0, 0, 255));
    yLabels->setPen(pen);
    //yLabels->setBrush(QColor(255, 131, 0, 50));

    //get label list
    int lineSize = (int) lineChartList.size();
    double maxCount = 0;
    double scaledCount;
    QVector<double> ticks;
    QVector<QString> ylabels;
    QVector<double> count;

    //add label list to y axis labels
    for (int i = 0; i < lineSize; i++){
        //ticks << (i+1);
        //ylabels << QString::fromStdString(lineChartList[i].first);
        if (lineChartList[i].second>1000000){
            //scaledCount = lineChartList[i].second/1000000;
        } else if (lineChartList[i].second>1000){
            //scaledCount = lineChartList[i].second/1000;
        } else{
            //scaledCount = lineChartList[i].second;
        }
        //count <<scaledCount;

        if (maxCount < lineChartList[i].second)
            maxCount = lineChartList[i].second;
    }

    //add label list to y axis labels
    for (int i = 0; i < lineSize; i++){
        ticks << (i+1);
        QString label = QString::fromStdString(lineChartList[i].first);
        if(label.size()>23){
            label.resize(20);
            label.resize(23,'.');
        }
        ylabels << label;
        //ylabels << QString::fromStdString(lineChartList[i].first);
        if (maxCount>1000000){
            scaledCount = lineChartList[i].second/1000000;
        } else if (maxCount>1000){
            scaledCount = lineChartList[i].second/1000;
        } else{
            scaledCount = lineChartList[i].second;
        }
        count <<scaledCount;

        if (maxCount < lineChartList[i].second)
            maxCount = lineChartList[i].second;
    }

    //setup Y Axis
    lineChart->xAxis->setAutoTicks(false);
    lineChart->xAxis->setAutoTickLabels(false);
    lineChart->xAxis->setTickVector(ticks);
    lineChart->xAxis->setTickVectorLabels(ylabels);
    lineChart->xAxis->setTickLabelPadding(1);
    lineChart->xAxis->setSubTickCount(0);
    lineChart->xAxis->setTickLength(0, 1);
    lineChart->xAxis->grid()->setVisible(true);
    lineChart->xAxis->setRange(0, lineSize+1);

    // setup look of bottom tick labels:
    lineChart->xAxis->setTickLabelRotation(30);
    //lineChart->xAxis->ticker()->setTickCount(9);
    //lineChart->xAxis->setNumberPrecision(1);
    lineChart->xAxis->moveRange(0);

    if(maxCount>1000000){
        maxCount = maxCount/1000000;
        lineChart->yAxis->setLabel("Total (in Millions)");
    }else if (maxCount>1000){
        maxCount = maxCount/1000;
        lineChart->yAxis->setLabel("Total (in Thousands)");
    }else{
        lineChart->yAxis->setLabel("Total");
    }

    // setup X Axis
    lineChart->yAxis->setAutoTicks(true);
    lineChart->yAxis->setRange(0,maxCount+(maxCount*.10));
    lineChart->yAxis->setAutoTickLabels(true);
    lineChart->yAxis->setAutoTickStep(true);
    lineChart->yAxis->grid()->setSubGridVisible(true);

    QPen gridPen;
    gridPen.setStyle(Qt::SolidLine);
    gridPen.setColor(QColor(0, 0, 0, 25));
    lineChart->yAxis->grid()->setPen(gridPen);
    gridPen.setStyle(Qt::DotLine);
    lineChart->yAxis->grid()->setSubGridPen(gridPen);

    yLabels->setData(ticks, count);
}

//setupScatterGraph function
void MainWindow::setupScatterGraph(QCustomPlot *scatterChart, std::vector<std::pair <std::string, double>> scatterChartList){
    // create empty bar chart objects:
    QCPGraph *yLabels = new QCPGraph(scatterChart->xAxis, scatterChart->yAxis);
    scatterChart->addPlottable(yLabels);

    // set names and colors:
    QPen pen;
    scatterChart->addGraph();
    scatterChart->graph(0)->setLineStyle(QCPGraph::lsNone);
    scatterChart->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 8));
    pen.setStyle(Qt::SolidLine);
    pen.setWidth(4);
    yLabels->setName("Type");
    pen.setColor(QColor(255, 0, 0));
    yLabels->setPen(pen);
    //yLabels->setBrush(QColor(255, 131, 0, 50));

    //get label list
    int scatterSize = (int) scatterChartList.size();
    double maxCount = 0;
    double scaledCount;
    QVector<double> ticks;
    QVector<QString> ylabels;
    QVector<double> count;

    //add label list to y axis labels
    for (int i = 0; i < scatterSize; i++){
        //ticks << (i+1);
        //ylabels << QString::fromStdString(scatterChartList[i].first);
        if (scatterChartList[i].second>1000000){
            //scaledCount = scatterChartList[i].second/1000000;
        } else if (scatterChartList[i].second>1000){
            //scaledCount = scatterChartList[i].second/1000;
        } else{
            //scaledCount = scatterChartList[i].second;
        }
        //count <<scaledCount;

        if (maxCount < scatterChartList[i].second)
            maxCount = scatterChartList[i].second;
    }

    //add label list to y axis labels
    for (int i = 0; i < scatterSize; i++){
        ticks << (i+1);
        QString label = QString::fromStdString(scatterChartList[i].first);
        if(label.size()>23){
            label.resize(20);
            label.resize(23,'.');
        }
        ylabels << label;
        if (maxCount>1000000){
            scaledCount = scatterChartList[i].second/1000000;
        } else if (maxCount>1000){
            scaledCount = scatterChartList[i].second/1000;
        } else{
            scaledCount = scatterChartList[i].second;
        }
        count <<scaledCount;

        if (maxCount < scatterChartList[i].second)
            maxCount = scatterChartList[i].second;
    }

    //setup Y Axis
    scatterChart->xAxis->setAutoTicks(false);
    scatterChart->xAxis->setAutoTickLabels(false);
    scatterChart->xAxis->setTickVector(ticks);
    scatterChart->xAxis->setTickVectorLabels(ylabels);
    scatterChart->xAxis->setTickLabelPadding(1);
    scatterChart->xAxis->setSubTickCount(0);
    scatterChart->xAxis->setTickLength(0, 1);
    scatterChart->xAxis->grid()->setVisible(true);
    scatterChart->xAxis->setRange(0, scatterSize+1);

    // setup look of bottom tick labels:
    scatterChart->xAxis->setTickLabelRotation(30);
    //lineChart->xAxis->ticker()->setTickCount(9);
    //lineChart->xAxis->setNumberPrecision(1);
    scatterChart->xAxis->moveRange(0);

    if(maxCount>1000000){
        maxCount = maxCount/1000000;
        scatterChart->yAxis->setLabel("Total (in Millions)");
    }else if (maxCount>1000){
        maxCount = maxCount/1000;
        scatterChart->yAxis->setLabel("Total (in Thousands)");
    }else{
        scatterChart->yAxis->setLabel("Total");
    }

    // setup X Axis
    scatterChart->yAxis->setAutoTicks(true);
    scatterChart->yAxis->setRange(0,maxCount+(maxCount*.10));
    scatterChart->yAxis->setAutoTickLabels(true);
    scatterChart->yAxis->setAutoTickStep(true);
    scatterChart->yAxis->grid()->setSubGridVisible(true);

    QPen gridPen;
    gridPen.setStyle(Qt::SolidLine);
    gridPen.setColor(QColor(0, 0, 0, 25));
    scatterChart->yAxis->grid()->setPen(gridPen);
    gridPen.setStyle(Qt::DotLine);
    scatterChart->yAxis->grid()->setSubGridPen(gridPen);

    yLabels->setData(ticks, count);
}

void MainWindow::on_teach_new_sort_clicked() {
    if (teachdb != NULL) {
        CustomSort* sortdialog = new CustomSort();
        sortdialog->setFields(TEACH_MANFIELDS);
        int ret = sortdialog->exec();
        if (ret) {
            QStringList newSortOrder = sortdialog->getSortFields();
            allTeachOrders << newSortOrder;
            ui->teach_sort->addItem(newSortOrder.at(0));

            // save the sort fields to file
            QSortListIO saveTeachSort(TEACHORDER_SAVE);
            saveTeachSort.saveList(allTeachOrders);
        }
        delete sortdialog;
    } else {
        QMessageBox::critical(this, "Missing File", "Please load a file first.");
    }
}

void MainWindow::on_pub_new_sort_clicked() {
    if (pubdb != NULL) {
        CustomSort* sortdialog = new CustomSort();
        sortdialog->setFields(PUBS_MANFIELDS);
        int ret = sortdialog->exec();
        if (ret) {
            QStringList newSortOrder = sortdialog->getSortFields();
            allPubOrders << newSortOrder;
            ui->pub_sort->addItem(newSortOrder.at(0));

            // save the sort fields to file
            QSortListIO savePubSort(PUBORDER_SAVE);
            savePubSort.saveList(allPubOrders);
        }
        delete sortdialog;
    } else {
        QMessageBox::critical(this, "Missing File", "Please load a file first.");
    }
}

void MainWindow::on_pres_new_sort_clicked() {
    if (presdb != NULL) {
        CustomSort* sortdialog = new CustomSort();
        sortdialog->setFields(PRES_MANFIELDS);
        int ret = sortdialog->exec();
        if (ret) {
            QStringList newSortOrder = sortdialog->getSortFields();
            allPresOrders << newSortOrder;
            ui->pres_sort->addItem(newSortOrder.at(0));

            // save the sort fields to file
            QSortListIO savePresSort(PRESORDER_SAVE);
            savePresSort.saveList(allPresOrders);
        }
        delete sortdialog;
    } else {
        QMessageBox::critical(this, "Missing File", "Please load a file first.");
    }
}

void MainWindow::on_fund_new_sort_clicked() {
    if (funddb != NULL) {
        CustomSort* sortdialog = new CustomSort();
        sortdialog->setFields(GRANTS_MANFIELDS);
        int ret = sortdialog->exec();
        if (ret) {
            QStringList newSortOrder = sortdialog->getSortFields();
            allFundOrders << newSortOrder;
            ui->fund_sort->addItem(newSortOrder.at(0));

            // save the sort fields to file
            QSortListIO saveFundSort(FUNDORDER_SAVE);
            saveFundSort.saveList(allFundOrders);
        }
        delete sortdialog;
    } else {
        QMessageBox::critical(this, "Missing File", "Please load a file first.");
    }
}

void MainWindow::on_teach_sort_currentIndexChanged(int index) {
    if(index != -1) {
        if(this->userTeachList.getUserSelectedList().size() > 0){
            this->userTeachList.clearSelectedList();

            ui->teachingClearList->setEnabled(false);
            ui->teachingUndoIndex->setEnabled(false);
            ui->teachingAddIndex->setEnabled(false);

            ui->teachingListCounter->display(this->userTeachList.getUserSelectedList().size());
        }
        QStringList sortOrder = allTeachOrders[index];
        teachSortOrder.clear();
        for (int i = 1; i < sortOrder.size(); i++) {
            teachSortOrder.emplace_back(sortOrder[i].toStdString());
        }
        ui->teach_filter->setText(QString::fromStdString(teachSortOrder[0]));
        refresh(TEACH);
    }
}

void MainWindow::on_pub_sort_currentIndexChanged(int index) {
    if(index != -1) {
        //Makes sure that the list stores only one type of QModelIndexes
        if(this->userPubList.getUserSelectedList().size() > 0){
            this->userPubList.clearSelectedList();

            ui->pubClearList->setEnabled(false);
            ui->pubUndoIndex->setEnabled(false);
            ui->pubAddIndex->setEnabled(false);

            ui->pubListCounter->display(this->userPubList.getUserSelectedList().size());
        }
        QStringList sortOrder = allPubOrders[index];
        pubSortOrder.clear();
        for (int i = 1; i < sortOrder.size(); i++) {
            pubSortOrder.emplace_back(sortOrder[i].toStdString());
        }
        ui->pub_filter->setText(QString::fromStdString(pubSortOrder[0]));
        refresh(PUBLICATIONS);
    }
}

void MainWindow::on_pres_sort_currentIndexChanged(int index) {
    if(index != -1) {
        //Makes sure that the list stores only one type of QModelIndexes
        if(this->userPresList.getUserSelectedList().size() > 0){
            this->userPresList.clearSelectedList();

            ui->presClearList->setEnabled(false);
            ui->presUndoIndex->setEnabled(false);
            ui->presAddIndex->setEnabled(false);

            ui->presListCounter->display(this->userPresList.getUserSelectedList().size());
        }
        QStringList sortOrder = allPresOrders[index];
        presSortOrder.clear();
        for (int i = 1; i < sortOrder.size(); i++) {
            presSortOrder.emplace_back(sortOrder[i].toStdString());
        }
        ui->pres_filter->setText(QString::fromStdString(presSortOrder[0]));
        refresh(PRESENTATIONS);
    }
}

void MainWindow::on_fund_sort_currentIndexChanged(int index) {
    if(index != -1) {
        //Makes sure that the list stores only one type of QModelIndexes
        if(this->userFundList.getUserSelectedList().size() > 0){
            this->userFundList.clearSelectedList();

            ui->fundsClearList->setEnabled(false);
            ui->fundsUndoIndex->setEnabled(false);
            ui->fundsAddIndex->setEnabled(false);

            ui->fundsListCounter->display(this->userFundList.getUserSelectedList().size());
        }
        QStringList sortOrder = allFundOrders[index];
        fundSortOrder.clear();
        for (int i = 1; i < sortOrder.size(); i++) {
            fundSortOrder.emplace_back(sortOrder[i].toStdString());
        }
        ui->fund_filter->setText(QString::fromStdString(fundSortOrder[0]));
        refresh(FUNDING);
    }
}

void MainWindow::on_teach_delete_sort_clicked() {
    if (ui->teach_sort->currentIndex()!=0) {
        QMessageBox prompt;
        prompt.setText("Are you sure you want to delete " + ui->teach_sort->currentText() + "?");
        prompt.setStandardButtons(QMessageBox::Yes | QMessageBox::No);

        if (prompt.exec()==QMessageBox::Yes) {
            allTeachOrders.removeAt(ui->teach_sort->currentIndex());
            ui->teach_sort->removeItem(ui->teach_sort->currentIndex());

            QSortListIO saveTeachSort(TEACHORDER_SAVE);
            saveTeachSort.saveList(allTeachOrders);
        }
    } else {
        QMessageBox::critical(this, "", "Cannot delete Default");
    }
}

void MainWindow::on_pub_delete_sort_clicked() {
    if (ui->pub_sort->currentIndex()!=0) {
        QMessageBox prompt;
        prompt.setText("Are you sure you want to delete " + ui->pub_sort->currentText() + "?");
        prompt.setStandardButtons(QMessageBox::Yes | QMessageBox::No);

        if (prompt.exec()==QMessageBox::Yes) {
            allPubOrders.removeAt(ui->pub_sort->currentIndex());
            ui->pub_sort->removeItem(ui->pub_sort->currentIndex());

            QSortListIO savePubSort(PUBORDER_SAVE);
            savePubSort.saveList(allPubOrders);
        }
    } else {
        QMessageBox::critical(this, "", "Cannot delete Default");
    }
}

void MainWindow::on_pres_delete_sort_clicked() {
    if (ui->pres_sort->currentIndex()!=0) {
        QMessageBox prompt;
        prompt.setText("Are you sure you want to delete " + ui->pres_sort->currentText() + "?");
        prompt.setStandardButtons(QMessageBox::Yes | QMessageBox::No);

        if (prompt.exec()==QMessageBox::Yes) {
            allPresOrders.removeAt(ui->pres_sort->currentIndex());
            ui->pres_sort->removeItem(ui->pres_sort->currentIndex());

            QSortListIO savePresSort(PRESORDER_SAVE);
            savePresSort.saveList(allPresOrders);
        }
    } else {
        QMessageBox::critical(this, "", "Cannot delete Default");
    }
}

void MainWindow::on_fund_delete_sort_clicked() {
    if (ui->fund_sort->currentIndex()!=0) {
        QMessageBox prompt;
        prompt.setText("Are you sure you want to delete " + ui->fund_sort->currentText() + "?");
        prompt.setStandardButtons(QMessageBox::Yes | QMessageBox::No);

        if (prompt.exec()==QMessageBox::Yes) {
            allFundOrders.removeAt(ui->fund_sort->currentIndex());
            ui->fund_sort->removeItem(ui->fund_sort->currentIndex());

            QSortListIO saveFundSort(FUNDORDER_SAVE);
            saveFundSort.saveList(allFundOrders);
        }
    } else {
        QMessageBox::critical(this, "", "Cannot delete Default");
    }
}

void MainWindow::on_teach_bar_button_toggled() { ui->teach_graph_stackedWidget->setCurrentIndex(1);}
void MainWindow::on_teach_pie_button_toggled() { ui->teach_graph_stackedWidget->setCurrentIndex(0);}
void MainWindow::on_pub_bar_button_toggled() { ui->pub_graph_stackedWidget->setCurrentIndex(1);}
void MainWindow::on_pub_pie_button_toggled() { ui->pub_graph_stackedWidget->setCurrentIndex(0);}
void MainWindow::on_pres_bar_button_toggled() { ui->pres_graph_stackedWidget->setCurrentIndex(1);}
void MainWindow::on_pres_pie_button_toggled() { ui->pres_graph_stackedWidget->setCurrentIndex(0);}
void MainWindow::on_fund_bar_button_toggled() { ui->fund_graph_stackedWidget->setCurrentIndex(1);}
void MainWindow::on_fund_pie_button_toggled() { ui->fund_graph_stackedWidget->setCurrentIndex(0);}

void MainWindow::on_teach_load_file_clicked() {
    QString path = load_file();
    if (!path.isEmpty() && (checkFile(TEACH, path) == EXIT_SUCCESS)) {
        load_teach(path);

        //load the save state, store the teach file and save the state for next run
        sState.loadState();
        sState.setTeachFile(path.toStdString());
        sState.saveState();
    } else {
        QMessageBox::critical(this, "Invalid File", "Not a valid Teachings file.\nDiscarded:" + path.section('/', -1, -1));
    }
}

/* Loads a teachings file and generates the tree for this file.
 * This method assume the file has been preleminarily checked and is
 * a teachings file.
 */
void MainWindow::load_teach(QString path) {

    // enable gui elements
    ui->teach_sort->setEnabled(true);
    ui->teach_delete_sort->setEnabled(true);
    ui->teach_new_sort->setEnabled(true);
    ui->teach_filter_from->setEnabled(true);
    ui->teach_filter_to->setEnabled(true);
    ui->teach_pie_button->setEnabled(true);
    ui->teach_bar_button->setEnabled(true);
    ui->teach_line_button->setEnabled(true);
    ui->teach_scatter_button->setEnabled(true);
    ui->teach_to_label->setEnabled(true);
    ui->teach_sort_label->setEnabled(true);
    ui->teach_filter->setEnabled(true);
    ui->teach_filter_label->setEnabled(true);

    // load save order
    QSortListIO teachSaveOrder(TEACHORDER_SAVE);
    allTeachOrders = teachSaveOrder.readList();
    ui->teach_sort->clear();
    for (int i = 0; i < allTeachOrders.size(); i++) {
        ui->teach_sort->addItem(allTeachOrders.at(i).at(0));
    }

    // create default sort order if none are loaded
    if (ui->teach_sort->currentIndex() < 0) {
        createDefaultSortOrder(TEACH);
        ui->teach_sort->addItem(allTeachOrders[0][0]);
    }

    // create the tree
    teachPath = path;
    makeTree(TEACH);
    ui->teach_file_label->setText(teachPath);
}

void MainWindow::on_pub_load_file_clicked() {
    QString path = load_file();
    if (!path.isEmpty() && (checkFile(PUBLICATIONS, path) == EXIT_SUCCESS)) {
        load_pub(path);
        //load the save state, store the pub file and save the state for next run
        sState.loadState();
        sState.setPubFile(path.toStdString());
        sState.saveState();
    } else {
        QMessageBox::critical(this, "Invalid File", "Not a valid Publications file.\nDiscarded:" + path.section('/', -1, -1));
    }
}


/* Loads a publications file and generates the tree for this file.
 * This method assume the file has been preleminarily checked and is
 * a publications file.
 */
void MainWindow::load_pub(QString path) {

    // enable gui elements
    ui->pub_sort->setEnabled(true);
    ui->pub_delete_sort->setEnabled(true);
    ui->pub_new_sort->setEnabled(true);
    ui->pub_filter_from->setEnabled(true);
    ui->pub_filter_to->setEnabled(true);
    ui->pub_pie_button->setEnabled(true);
    ui->pub_scatter_button->setEnabled(true);
    ui->pub_bar_button->setEnabled(true);
    ui->pub_line_button->setEnabled(true);
    ui->pub_to_label->setEnabled(true);
    ui->pub_sort_label->setEnabled(true);
    ui->pub_filter->setEnabled(true);
    ui->pub_filter_label->setEnabled(true);

    // load save order
    QSortListIO pubSaveOrder(PUBORDER_SAVE);
    allPubOrders = pubSaveOrder.readList();
    ui->pub_sort->clear();
    for (int i = 0; i < allPubOrders.size(); i++) {
        ui->pub_sort->addItem(allPubOrders.at(i).at(0));
    }

    // create default sort order if none are loaded
    if (ui->pub_sort->currentIndex() < 0) {
        createDefaultSortOrder(PUBLICATIONS);
        ui->pub_sort->addItem(allPubOrders[0][0]);
    }

    // create the tree
    pubPath = path;
    makeTree(PUBLICATIONS);
    ui->pub_file_label->setText(pubPath);
}

void MainWindow::on_pres_load_file_clicked() {
    QString path = load_file();
    if (!path.isEmpty() && (checkFile(PRESENTATIONS, path) == EXIT_SUCCESS)) {
        load_pres(path);
        //load the save state, store the pres file and save the state for next run
        sState.loadState();
        sState.setPresFile(path.toStdString());
        sState.saveState();
    } else {
        QMessageBox::critical(this, "Invalid File", "Not a valid Presentations file.\nDiscarded:" + path.section('/', -1, -1));
    }
}

/* Loads a presentations file and generates the tree for this file.
 * This method assume the file has been preleminarily checked and is
 * a presentations file.
 */
void MainWindow::load_pres(QString path) {

    // enable gui elements
    ui->pres_sort->setEnabled(true);
    ui->pres_delete_sort->setEnabled(true);
    ui->pres_new_sort->setEnabled(true);
    ui->pres_filter_from->setEnabled(true);
    ui->pres_filter_to->setEnabled(true);
    ui->pres_pie_button->setEnabled(true);
    ui->pres_scatter_button->setEnabled(true);
    ui->pres_bar_button->setEnabled(true);
    ui->pres_line_button->setEnabled(true);
    ui->pres_to_label->setEnabled(true);
    ui->pres_sort_label->setEnabled(true);
    ui->pres_filter->setEnabled(true);
    ui->pres_filter_label->setEnabled(true);

    // load save order
    QSortListIO presSaveOrder(PRESORDER_SAVE);
    allPresOrders = presSaveOrder.readList();
    ui->pres_sort->clear();
    for (int i = 0; i < allPresOrders.size(); i++) {
        ui->pres_sort->addItem(allPresOrders.at(i).at(0));
    }

    // create default sort order if none are loaded
    if (ui->pres_sort->currentIndex() < 0) {
        createDefaultSortOrder(PRESENTATIONS);
        ui->pres_sort->addItem(allPresOrders[0][0]);
    }

    // create the tree
    presPath = path;
    makeTree(PRESENTATIONS);
    ui->pres_file_label->setText(presPath);
}

void MainWindow::on_fund_load_file_clicked() {
    QString path = load_file();
    if (!path.isEmpty() && (checkFile(FUNDING, path) == EXIT_SUCCESS)) { // -fill-
        load_fund(path);
        //load the save state, store the fund file and save the state for next run
        sState.loadState();
        sState.setGrantFile(path.toStdString());
        sState.saveState();
    } else {
        QMessageBox::critical(this, "Invalid File", "Not a valid Grants and Fundings file.\nDiscarded:" + path.section('/', -1, -1));
    }
}

/* Loads a grants and fundings file and generates the tree for this file.
 * This method assume the file has been preleminarily checked and is
 * a grants and fundings file.
 */
void MainWindow::load_fund(QString path) {

    // enable gui elements
    ui->fund_sort->setEnabled(true);
    ui->fund_delete_sort->setEnabled(true);
    ui->fund_new_sort->setEnabled(true);
    ui->fund_filter_from->setEnabled(true);
    ui->fund_filter_to->setEnabled(true);
    ui->fund_pie_button->setEnabled(true);
    ui->fund_scatter_button->setEnabled(true);
    ui->fund_bar_button->setEnabled(true);
    ui->fund_line_button->setEnabled(true);
    ui->fund_to_label->setEnabled(true);
    ui->fund_sort_label->setEnabled(true);
    ui->fund_filter->setEnabled(true);
    ui->fund_filter_label->setEnabled(true);

    // load save order
    QSortListIO fundSaveOrder(FUNDORDER_SAVE);
    allFundOrders = fundSaveOrder.readList();
    ui->fund_sort->clear();
    for (int i = 0; i < allFundOrders.size(); i++) {
        ui->fund_sort->addItem(allFundOrders.at(i).at(0));
    }

    // create default sort order if none are loaded
    if (ui->fund_sort->currentIndex() < 0) {
        createDefaultSortOrder(FUNDING);
        ui->fund_sort->addItem(allFundOrders[0][0]);
    }

    // create the tree
    fundPath = path;
    makeTree(FUNDING);
    ui->fund_file_label->setText(fundPath);
}

void MainWindow::on_FromDate_dateChanged(const QDate &date) {
    // set the member variable to the new date
    yearStart = date.year();

    // update end date spinbox to not fall below that year
    ui->ToDate->setMinimumDate(date);

    dateChanged = {true, true, true, true};

    //load the save state, store the year and save the state for next run
    sState.loadState();
    sState.setStartYear(date.year());
    sState.saveState();

    // refresh the GUI
    refresh(ui->categoryTab->currentIndex());
}

void MainWindow::on_ToDate_dateChanged(const QDate &date) {
    // set the member variable to the new date
    yearEnd = date.year();

    // update end date spinbox to not fall below that year
    ui->ToDate->setMinimumDate(ui->FromDate->date());

    dateChanged = {true, true, true, true};

    //load the save state, store the year and save the state for next run
    sState.loadState();
    sState.setEndYear(date.year());
    sState.saveState();

    // refresh the GUI
    refresh(ui->categoryTab->currentIndex());
}

void MainWindow::on_categoryTab_currentChanged() {
    if (dateChanged[ui->categoryTab->currentIndex()] == true) {
        refresh(ui->categoryTab->currentIndex());
        dateChanged[ui->categoryTab->currentIndex()] = false;
    }
    userFundList.clearSelectedList();
    on_fundsClearList_clicked();
    userPresList.clearSelectedList();
    on_presClearList_clicked();
    userPubList.clearSelectedList();
    on_pubClearList_clicked();
    userTeachList.clearSelectedList();
    on_teachingClearList_clicked();
}

void MainWindow::on_teachTreeView_clicked(const QModelIndex &index) {
    QString clickedName = index.data(Qt::DisplayRole).toString();

    //    if (clickedName == Totals){
    //        currentTeach=index;

    //    }

    if (clickedName==teachClickedName || index.column()!=0) { return;}
    //Enable the ability to export a PDF and Print, since a value has now been selected
    ui->teachExportButton->setEnabled(true);
    ui->teachPrintButton->setEnabled(true);

    ui->teachingAddIndex->setEnabled(true);

    std::vector<std::string> parentsList;
    QModelIndex current = index;
    currentTeach = index;
    QString name;
    while (true) {
        name = current.data(Qt::DisplayRole).toString();
        if(name!="") {
            auto it = parentsList.begin();
            it = parentsList.insert(it, name.toStdString());
        } else {
            break;
        }
        current = current.parent();
    }

    if(!(parentsList.size()==teachSortOrder.size() && teachSortOrder.at((size_t)parentsList.size()-1) == "Program")){
        //if (parentsList.size()!=teachSortOrder.size()) {
        if (clickedName != teachClickedName) {
            teachClickedName = clickedName;
            std::vector<std::string> sortOrder(teachSortOrder.begin(), teachSortOrder.begin()+parentsList.size()+1);
            std::vector<std::pair <std::string, int>> list =
                    teachdb->getCountTuple(yearStart, yearEnd, sortOrder, parentsList, getFilterStartChar(TEACH), getFilterEndChar(TEACH));
            std::vector<std::pair <std::string, double>> chartList;
            for (int i = 0; i < (int) list.size(); i++) {
                chartList.emplace_back(list[i].first, static_cast<double>(list[i].second));
            }


            //check through the tree
            if (clickedName == "Total"){
                for (int i=0; i<teachTree->rowCount(index.parent());i++){
                    QModelIndex nextline = teachTree->index(i,0,index.parent());
                    if (!(nextline.data(Qt::DisplayRole).toString() == "Total")){
                        current = nextline;
                        QString name;
                        std::vector<std::string> makeparentsList;
                        while (true) {
                            name = current.data(Qt::DisplayRole).toString();
                            if(name!="") {
                                auto it = makeparentsList.begin();
                                it = makeparentsList.insert(it, name.toStdString());
                            } else {
                                break;
                            }
                            current = current.parent();
                        }
                        parentsList = makeparentsList;

                        std::vector<std::string> sortOrder(teachSortOrder.begin(), teachSortOrder.begin()+parentsList.size()+1);
                        std::vector<std::pair <std::string, int>> newList =
                                teachdb->getCountTuple(yearStart, yearEnd, sortOrder, parentsList, getFilterStartChar(TEACH), getFilterEndChar(TEACH));

                        if (!newList.empty()){
                            for (int k=0; k<(int)newList.size();k++){
                                bool found = false;
                                for (int j=0;j<(int)chartList.size();j++){
                                    if (newList.at(k).first == chartList.at(j).first){
                                        chartList.at(j).second = chartList.at(j).second + newList.at(k).second;
                                        found = true;
                                        break;
                                    }
                                }
                                if (!found){
                                    chartList.insert(chartList.end(),newList.at(k));
                                }
                            }
                        }
                    }
                }
            }

            if (!chartList.empty()) {
                ui->teachBarChart->clearPlottables();
                setupBarChart(ui->teachBarChart, chartList);
                ui->teachBarChart->replot();

                setupPieChart(ui->teachPieChart, ui->teachPieList, chartList);

                //Line Graph
                ui->teachLineChart->clearPlottables();
                setupLineGraph(ui->teachLineChart, chartList);
                ui->teachLineChart->replot();

                //Scatter plot Graph
                ui->teachScatterChart->clearPlottables();
                setupScatterGraph(ui->teachScatterChart, chartList);
                ui->teachScatterChart->replot();
                if (clickedName == "Total"){
                    ui->teachGraphTitle->setText("Total " + clickedName + " Teaching by Total List");
                }
                else if (parentsList.size()>1) {
                    ui->teachGraphTitle->setText("Total " + clickedName + " Teaching by " +
                                                 QString::fromStdString(teachSortOrder[parentsList.size()]) + " for " + QString::fromStdString(parentsList[0]));
                } else{
                    ui->teachGraphTitle->setText("Total Teaching by " + QString::fromStdString(parentsList[0]));
                }
                ui->teach_graph_stackedWidget->show();
            }
        }
    }else {
        ui->teach_graph_stackedWidget->hide();
        ui->teachGraphTitle->clear();
        teachClickedName.clear();
    }
}

void MainWindow::on_pubTreeView_clicked(const QModelIndex &index) {
    QString clickedName = index.data(Qt::DisplayRole).toString();

    if (clickedName==pubClickedName || index.column()!=0) { return;}
    //Enable the ability to export a PDF and Print, since a value has now been selected
    ui->pubExportButton->setEnabled(true);
    ui->pubPrintButton->setEnabled(true);

    ui->pubAddIndex->setEnabled(true);

    std::vector<std::string> parentsList;
    QModelIndex current = index;
    currentPub = index;
    QString name;
    while (true) {
        name = current.data(Qt::DisplayRole).toString();
        if(name!="") {
            auto it = parentsList.begin();
            it = parentsList.insert(it, name.toStdString());
        } else {
            break;
        }
        current = current.parent();
    }
    if(!(parentsList.size()==pubSortOrder.size() && pubSortOrder.at((size_t)parentsList.size()-1) == "Title")){
        //if (parentsList.size()!=pubSortOrder.size()) {
        pubClickedName = clickedName;
        std::vector<std::string> sortOrder(pubSortOrder.begin(), pubSortOrder.begin()+parentsList.size()+1);
        std::vector<std::pair <std::string, int>> list =
                pubdb->getCountTuple(yearStart, yearEnd, sortOrder, parentsList, getFilterStartChar(PUBLICATIONS), getFilterEndChar(PUBLICATIONS));
        std::vector<std::pair <std::string, double>> chartList;
        for (int i = 0; i < (int) list.size(); i++) {
            chartList.emplace_back(list[i].first, static_cast<double>(list[i].second));
        }


        //check through the tree
        if (clickedName == "Total"){
            for (int i=0; i<pubTree->rowCount(index.parent());i++){
                QModelIndex nextline = pubTree->index(i,0,index.parent());
                if (!(nextline.data(Qt::DisplayRole).toString() == "Total")){
                    current = nextline;
                    QString name;
                    std::vector<std::string> makeparentsList;
                    while (true) {
                        name = current.data(Qt::DisplayRole).toString();
                        if(name!="") {
                            auto it = makeparentsList.begin();
                            it = makeparentsList.insert(it, name.toStdString());
                        } else {
                            break;
                        }
                        current = current.parent();
                    }
                    parentsList = makeparentsList;

                    std::vector<std::string> sortOrder(pubSortOrder.begin(), pubSortOrder.begin()+parentsList.size()+1);
                    std::vector<std::pair <std::string, int>> newList =
                            pubdb->getCountTuple(yearStart, yearEnd, sortOrder, parentsList, getFilterStartChar(PUBLICATIONS), getFilterEndChar(PUBLICATIONS));

                    if (!newList.empty()){
                        for (int k=0; k<(int)newList.size();k++){
                            bool found = false;
                            for (int j=0;j<(int)chartList.size();j++){
                                if (newList.at(k).first == chartList.at(j).first){
                                    chartList.at(j).second = chartList.at(j).second + newList.at(k).second;
                                    found = true;
                                    break;
                                }
                            }
                            if (!found){
                                chartList.insert(chartList.end(),newList.at(k));
                            }
                        }
                    }
                }
            }
        }


        if (!chartList.empty()) {
            ui->pubBarChart->clearPlottables();
            setupBarChart(ui->pubBarChart, chartList);
            ui->pubBarChart->replot();

            setupPieChart(ui->pubPieChart, ui->pubPieList, chartList);

            //Line Graph
            ui->pubLineChart->clearPlottables();
            setupLineGraph(ui->pubLineChart, chartList);
            ui->pubLineChart->replot();

            //Scatter plot Graph
            ui->pubScatterChart->clearPlottables();
            setupScatterGraph(ui->pubScatterChart, chartList);
            ui->pubScatterChart->replot();

            if (clickedName == "Total"){
                ui->teachGraphTitle->setText("Total " + clickedName + " by Total List");
            }
            else if (parentsList.size()>1) {
                ui->pubGraphTitle->setText("Total " + clickedName + " Publications by " +
                                           QString::fromStdString(pubSortOrder[parentsList.size()]) + " for " + QString::fromStdString(parentsList[0]));
            } else {
                ui->pubGraphTitle->setText("Total Publications by " + QString::fromStdString(parentsList[0]));
            }
            ui->pub_graph_stackedWidget->show();
        }
    } else {
        ui->pub_graph_stackedWidget->hide();
        ui->pubGraphTitle->clear();
        pubClickedName.clear();
    }
}

void MainWindow::on_presTreeView_clicked(const QModelIndex &index) {
    QString clickedName = index.data(Qt::DisplayRole).toString();
    if (clickedName==presClickedName || index.column()!=0) { return;}
    //Enable the ability to export a PDF and Print, since a value has now been selected
    ui->presExportButton->setEnabled(true);
    ui->presPrintButton->setEnabled(true);

    ui->presAddIndex->setEnabled(true);

    std::vector<std::string> parentsList;
    QModelIndex current = index;
    currentPres = index;
    QString name;
    while (true) {
        name = current.data(Qt::DisplayRole).toString();
        if(name!="") {
            auto it = parentsList.begin();
            it = parentsList.insert(it, name.toStdString());
        } else {
            break;
        }
        current = current.parent();
    }
    if(!(parentsList.size()==presSortOrder.size() && presSortOrder.at((size_t)parentsList.size()-1) == "Title")){
        //QModelIndex next = index.child(index.row(),index.column());
        //if (next.data(Qt::DisplayRole).toString() != ""){
        presClickedName = clickedName;
        std::vector<std::string> sortOrder(presSortOrder.begin(), presSortOrder.begin()+parentsList.size()+1);
        std::vector<std::pair <std::string, int>> list =
                presdb->getCountTuple(yearStart, yearEnd, sortOrder, parentsList, getFilterStartChar(PRESENTATIONS), getFilterEndChar(PRESENTATIONS));
        std::vector<std::pair <std::string, double>> chartList;
        for (int i = 0; i < (int) list.size(); i++) {
            chartList.emplace_back(list[i].first, static_cast<double>(list[i].second));
            }

            //check through the tree
            if (clickedName == "Total"){
                for (int i=0; i<presTree->rowCount(index.parent());i++){
                    QModelIndex nextline = presTree->index(i,0,index.parent());
                    if (!(nextline.data(Qt::DisplayRole).toString() == "Total")){
                        current = nextline;
                        QString name;
                        std::vector<std::string> makeparentsList;
                        while (true) {
                            name = current.data(Qt::DisplayRole).toString();
                            if(name!="") {
                                auto it = makeparentsList.begin();
                                it = makeparentsList.insert(it, name.toStdString());
                            } else {
                                break;
                            }
                            current = current.parent();
                        }
                        parentsList = makeparentsList;

                        std::vector<std::string> sortOrder(presSortOrder.begin(), presSortOrder.begin()+parentsList.size()+1);
                        std::vector<std::pair <std::string, int>> newList =
                                presdb->getCountTuple(yearStart, yearEnd, sortOrder, parentsList, getFilterStartChar(PRESENTATIONS), getFilterEndChar(PRESENTATIONS));

                        if (!newList.empty()){
                            for (int k=0; k<(int)newList.size();k++){
                                bool found = false;
                                for (int j=0;j<(int)chartList.size();j++){
                                    if (newList.at(k).first == chartList.at(j).first){
                                        chartList.at(j).second = chartList.at(j).second + newList.at(k).second;
                                        found = true;
                                        break;
                                    }
                                }
                                if (!found){
                                    chartList.insert(chartList.end(),newList.at(k));
                                }
                            }
                        }
                    }
                }
            }

            if (!chartList.empty()) {
                ui->presBarChart->clearPlottables();
                setupBarChart(ui->presBarChart, chartList);
                ui->presBarChart->replot();

                setupPieChart(ui->presPieChart, ui->presPieList, chartList);

                //Line Graph
                ui->presLineChart->clearPlottables();
                setupLineGraph(ui->presLineChart, chartList);
                ui->presLineChart->replot();

                //Scatter plot Graph
                ui->presScatterChart->clearPlottables();
                setupScatterGraph(ui->presScatterChart, chartList);
                ui->presScatterChart->replot();

                if (clickedName == "Total"){
                    ui->teachGraphTitle->setText("Total " + clickedName + " by Total List");
                }
                else if (parentsList.size()>1) {
                    ui->presGraphTitle->setText("Total " + clickedName + " Presentations by " +
                                                QString::fromStdString(presSortOrder[parentsList.size()]) + " for " + QString::fromStdString(parentsList[0]));
                } else {
                    ui->presGraphTitle->setText("Total Presentations by " + QString::fromStdString(parentsList[0]));
                }
                ui->pres_graph_stackedWidget->show();
            }
        //}
            } else {
                ui->pres_graph_stackedWidget->hide();
                ui->presGraphTitle->clear();
                presClickedName.clear();
    }
}

void MainWindow::on_fundTreeView_clicked(const QModelIndex &index) {
    QString clickedName = index.data(Qt::DisplayRole).toString();
    if (clickedName==fundClickedName || index.column()!=0) { return;}
    //Enable the ability to export a PDF and Print, since a value has now been selected
    ui->fundExportButton->setEnabled(true);
    ui->fundPrintButton->setEnabled(true);

    ui->fundsAddIndex->setEnabled(true);

    std::vector<std::string> parentsList;
    QModelIndex current = index;
    currentFund = index;
    QString name;
    while (true) {
        name = current.data(Qt::DisplayRole).toString();
        if(name!="") {
            auto it = parentsList.begin();
            it = parentsList.insert(it, name.toStdString());
        } else {
            break;
        }
        current = current.parent();
    }
    //if the header back is the last header in the file
    //std::string ret = fundSortOrder.at((size_t)parentsList.size()-1);
    //QString qstr = QString::fromStdString(ret);

    //if (parentsList.size()<fundSortOrder.size()){//|| (fundSortOrder.at(parentsList.size()) != "Title" && fundSortOrder.at(parentsList.size()) != "Start Date")){
    //|| (parentsList.size()==fundSortOrder.size() && fundSortOrder.at((int)fundSortOrder.size()) != "Title") ) {
    //if (fundSortOrder.at((size_t)parentsList.size()-1) != "Title" && fundSortOrder.at((size_t)parentsList.size()-1) != "Start Date"){
    if(!(parentsList.size()==fundSortOrder.size() && fundSortOrder.at((size_t)parentsList.size()-1) == "Title")){
        if (clickedName != fundClickedName) {

            fundClickedName = clickedName;
            std::vector<std::string> sortOrder(fundSortOrder.begin(), fundSortOrder.begin()+parentsList.size()+1);
            std::vector<std::pair <std::string, double>> chartList =
                    funddb->getTotalsTuple(yearStart, yearEnd, sortOrder, parentsList, "Total Amount", getFilterStartChar(FUNDING), getFilterEndChar(FUNDING));
            //check through the tree
            if (clickedName == "Total"){
                for (int i=0; i<fundTree->rowCount(index.parent());i++){
                    QModelIndex nextline = fundTree->index(i,0,index.parent());
                    if (!(nextline.data(Qt::DisplayRole).toString() == "Total")){
                        current = nextline;
                        QString name;
                        std::vector<std::string> makeparentsList;
                        while (true) {
                            name = current.data(Qt::DisplayRole).toString();
                            if(name!="") {
                                auto it = makeparentsList.begin();
                                it = makeparentsList.insert(it, name.toStdString());
                            } else {
                                break;
                            }
                            current = current.parent();
                        }
                        parentsList = makeparentsList;

                        std::vector<std::string> sortOrder(fundSortOrder.begin(), fundSortOrder.begin()+parentsList.size()+1);
                        std::vector<std::pair <std::string, int>> newList =
                                funddb->getCountTuple(yearStart, yearEnd, sortOrder, parentsList, getFilterStartChar(FUNDING), getFilterEndChar(FUNDING));
                        if (!newList.empty()){
                            for (int k=0; k<(int)newList.size();k++){
                                bool found = false;
                                for (int j=0;j<(int)chartList.size();j++){
                                    if (newList.at(k).first == chartList.at(j).first){
                                        chartList.at(j).second = chartList.at(j).second + newList.at(k).second;
                                        found = true;
                                        break;
                                    }
                                }
                                if (!found){
                                    chartList.insert(chartList.end(),newList.at(k));
                                }
                            }
                        }
                    }
                }
            }


            if (!chartList.empty()) {
                ui->fundBarChart->clearPlottables();
                setupBarChart(ui->fundBarChart, chartList);
                ui->fundBarChart->replot();

                setupPieChart(ui->fundPieChart, ui->fundPieList, chartList);

                //Line Graph
                ui->fundLineChart->clearPlottables();
                setupLineGraph(ui->fundLineChart, chartList);
                ui->fundLineChart->replot();

                //Scatter plot Graph
                ui->fundScatterChart->clearPlottables();
                setupScatterGraph(ui->fundScatterChart, chartList);
                ui->fundScatterChart->replot();

                if (clickedName == "Total"){
                    ui->teachGraphTitle->setText("Total " + clickedName + " by Total List");
                }
                else if (parentsList.size()>1) {
                    ui->fundGraphTitle->setText("Total " + clickedName + " Grants & Funding by " +
                                                QString::fromStdString(fundSortOrder[parentsList.size()]) + " for " + QString::fromStdString(parentsList[0]));
                } else {
                    ui->fundGraphTitle->setText("Total Grants & Funding by " + QString::fromStdString(parentsList[0]));
                }
                ui->fund_graph_stackedWidget->show();
           // }
            } else {
            ui->fund_graph_stackedWidget->hide();
            ui->fundGraphTitle->clear();
            fundClickedName.clear();
        }
    }

    //}

}
}

void MainWindow::on_teachPrintButton_clicked()
{
    QPrintDialog printDialog(printer, this);
    if (printDialog.exec() == QDialog::Accepted) {
        QCPPainter painter;
        painter.begin(printer);
        ui->teachChartFrame->render(&painter);
    }
}

void MainWindow::on_fundPrintButton_clicked()
{
    QPrintDialog printDialog(printer, this);
    if (printDialog.exec() == QDialog::Accepted) {
        QCPPainter painter;
        painter.begin(printer);
        ui->fundChartFrame->render(&painter);
    }
}

void MainWindow::on_presPrintButton_clicked()
{
    QPrintDialog printDialog(printer, this);
    if (printDialog.exec() == QDialog::Accepted) {
        QCPPainter painter;
        painter.begin(printer);
        ui->presChartFrame->render(&painter);
    }
}

void MainWindow::on_pubPrintButton_clicked()
{
    QPrintDialog printDialog(printer, this);
    if (printDialog.exec() == QDialog::Accepted) {
        QCPPainter painter;
        painter.begin(printer);
        ui->pubChartFrame->render(&painter);
    }
}

void MainWindow::on_teachExportButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Export File"),
                                                    QDir::homePath(),
                                                    tr("PDF (*.pdf)"));
    if (fileName.contains("") != 0) {
        QPdfWriter writer(fileName);
        writer.setPageOrientation(QPageLayout::Landscape);
        QPainter painter;
        painter.begin(&writer);
        painter.scale(10.0, 10.0);
        ui->teachChartFrame->render(&painter);
        /* Another option for bar chart since it is QCustom plot
        if (ui->teach_bar_button->isChecked()) {
            ui->teachBarChart->savePdf(fileName);
        } */
    }

}

void MainWindow::on_fundExportButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Export File"),
                                                    QDir::homePath(),
                                                    tr("PDF (*.pdf)"));
    if (fileName.contains("") != 0) {
        QPdfWriter writer(fileName);
        writer.setPageOrientation(QPageLayout::Landscape);
        QPainter painter;
        painter.begin(&writer);
        painter.scale(10.0, 10.0);
        ui->fundChartFrame->render(&painter);
    }
}

void MainWindow::on_presExportButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Export File"),
                                                    QDir::homePath(),
                                                    tr("PDF (*.pdf)"));
    if (fileName.contains("") != 0) {
        QPdfWriter writer(fileName);
        writer.setPageOrientation(QPageLayout::Landscape);
        QPainter painter;
        painter.begin(&writer);
        painter.scale(10.0, 10.0);
        ui->presChartFrame->render(&painter);
    }
}

void MainWindow::on_pubExportButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Export File"),
                                                    QDir::homePath(),
                                                    tr("PDF (*.pdf)"));
    if (fileName.contains("") != 0) {
        QPdfWriter writer(fileName);
        writer.setPageOrientation(QPageLayout::Landscape);
        QPainter painter;
        painter.begin(&writer);
        painter.scale(10.0, 10.0);
        ui->pubChartFrame->render(&painter);
    }
}


char MainWindow::getFilterStartChar(int type) {
    char charInField;

    // get char from the text field
    switch (type) {
    case FUNDING:
        charInField = ui->fund_filter_from->text().toStdString()[0];
        break;
    case PRESENTATIONS:
        charInField = ui->pres_filter_from->text().toStdString()[0];
        break;
    case PUBLICATIONS:
        charInField = ui->pub_filter_from->text().toStdString()[0];
        break;
    case TEACH:
        charInField = ui->teach_filter_from->text().toStdString()[0];
        break;
    }

    // convert the char to uppercase
    char uppercase = charInField & ~0x20;

    // if alphabetical, return that letter
    if ('A' <= uppercase && uppercase <= 'Z') {
        return uppercase;
    } else {
        // otherwise, default is '*'
        return '*';
    }
}

char MainWindow::getFilterEndChar(int type) {
    char charInField;

    // get char from the text field
    switch (type) {
    case FUNDING:
        charInField = ui->fund_filter_to->text().toStdString()[0];
        break;
    case PRESENTATIONS:
        charInField = ui->pres_filter_to->text().toStdString()[0];
        break;
    case PUBLICATIONS:
        charInField = ui->pub_filter_to->text().toStdString()[0];
        break;
    case TEACH:
        charInField = ui->teach_filter_to->text().toStdString()[0];
        break;
    }

    // convert the char to uppercase
    char uppercase = charInField & ~0x20;

    // if alphabetical, return that letter
    if ('A' <= uppercase && uppercase <= 'Z') {
        return uppercase;
    } else if (charInField == '*') {
        // otherwise, is it '*'?
        return charInField;
    } else {
        // otherwise, default is 'Z'
        return 'Z';
    }
}

void MainWindow::on_teach_filter_from_textChanged() { refresh(TEACH);}
void MainWindow::on_teach_filter_to_textChanged() { refresh(TEACH);}
void MainWindow::on_pub_filter_from_textChanged() { refresh(PUBLICATIONS);}
void MainWindow::on_pub_filter_to_textChanged() { refresh(PUBLICATIONS);}
void MainWindow::on_pres_filter_from_textChanged() { refresh(PRESENTATIONS);}
void MainWindow::on_pres_filter_to_textChanged() { refresh(PRESENTATIONS);}
void MainWindow::on_fund_filter_from_textChanged() { refresh(FUNDING);}
void MainWindow::on_fund_filter_to_textChanged() { refresh(FUNDING);}

//Line Chart Radio Button
void MainWindow::on_teach_line_button_toggled()
{
    ui->teach_graph_stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pub_line_button_toggled()
{
    ui->pub_graph_stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_fund_line_button_toggled()
{
    ui->fund_graph_stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pres_line_button_toggled()
{
    ui->pres_graph_stackedWidget->setCurrentIndex(2);
}



void MainWindow::on_fund_scatter_button_toggled()
{
    ui->fund_graph_stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pres_scatter_button_toggled()
{
    ui->pres_graph_stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pub_scatter_button_toggled()
{
    ui->pub_graph_stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_teach_scatter_button_toggled()
{
    ui->teach_graph_stackedWidget->setCurrentIndex(3);
}

/**
 * @brief MainWindow::on_teachingAddIndex_clicked
 * Stores the currently selected index into the userSelectedList for the Teaching Subject Area.
 */
void MainWindow::on_teachingAddIndex_clicked()
{
    QString clickedName = this->currentTeach.data(Qt::DisplayRole).toString();
    int checkDuplicateStorage = userTeachList.searchSelectedList(this->currentTeach);
    if(checkDuplicateStorage < 0){
        userTeachList.insertIndex(this->currentTeach);
    }
    ui->teachingListCounter->display(userTeachList.getUserSelectedList().size());

    if(this->userTeachList.getUserSelectedList().size() > 0){
        ui->teachingUndoIndex->setEnabled(true);
        ui->teachingClearList->setEnabled(true);
        ui->teachGraphList->setEnabled(true);
        ui->teachListContentView->setEnabled(true);
    }
}

/**
 * @brief MainWindow::on_teachingClearList_clicked
 * Slot that removes the last added index from the userSelectedList for the Teaching subject area.
 */
void MainWindow::on_teachingUndoIndex_clicked()
{
    this->userTeachList.undoLastAddedIndex();
    ui->teachingListCounter->display(userTeachList.getUserSelectedList().size());

    if(this->userTeachList.getUserSelectedList().size() == 0){
        ui->teachingUndoIndex->setEnabled(false);
        ui->teachingClearList->setEnabled(false);
        ui->teachGraphList->setEnabled(false);
        ui->teachListContentView->setEnabled(false);
    }
}

/**
 * @brief MainWindow::on_teachingClearList_clicked
 * Slot that clears the userSelectedList for the Teaching Subject Area
 */
void MainWindow::on_teachingClearList_clicked()
{
    this->userTeachList.clearSelectedList();
    ui->teachingListCounter->display(userTeachList.getUserSelectedList().size());

    ui->teachingUndoIndex->setEnabled(false);
    ui->teachingClearList->setEnabled(false);
    ui->teachGraphList->setEnabled(false);
    ui->teachListContentView->setEnabled(false);
}



void MainWindow::on_pubAddIndex_clicked()
{
    QString clickedName = this->currentPub.data(Qt::DisplayRole).toString();
    int checkDuplicateStorage = userPubList.searchSelectedList(this->currentPub);
    if(checkDuplicateStorage < 0){
        userPubList.insertIndex(this->currentPub);
    }
    ui->pubListCounter->display(userPubList.getUserSelectedList().size());

    if(this->userPubList.getUserSelectedList().size() > 0){
        ui->pubUndoIndex->setEnabled(true);
        ui->pubClearList->setEnabled(true);
        ui->pubGraphList->setEnabled(true);
        ui->pubListContentView->setEnabled(true);
    }
}

void MainWindow::on_pubUndoIndex_clicked()
{
    this->userPubList.undoLastAddedIndex();
    ui->pubListCounter->display(userPubList.getUserSelectedList().size());

    if(this->userPubList.getUserSelectedList().size() == 0){
        ui->pubUndoIndex->setEnabled(false);
        ui->pubClearList->setEnabled(false);
        ui->pubGraphList->setEnabled(false);
        ui->pubListContentView->setEnabled(false);
    }
}

void MainWindow::on_pubClearList_clicked()
{
    this->userPubList.clearSelectedList();
    ui->pubListCounter->display(userPubList.getUserSelectedList().size());

    ui->pubUndoIndex->setEnabled(false);
    ui->pubClearList->setEnabled(false);
    ui->pubGraphList->setEnabled(false);
    ui->pubListContentView->setEnabled(false);
}

void MainWindow::on_presAddIndex_clicked()
{
    QString clickedName = this->currentPres.data(Qt::DisplayRole).toString();
    int checkDuplicateStorage = userPresList.searchSelectedList(this->currentPres);
    if(checkDuplicateStorage < 0){
        userPresList.insertIndex(this->currentPres);
    }
    ui->presListCounter->display(userPresList.getUserSelectedList().size());

    if(this->userPresList.getUserSelectedList().size() > 0){
        ui->presUndoIndex->setEnabled(true);
        ui->presClearList->setEnabled(true);
        ui->presGraphList->setEnabled(true);
        ui->presListContentView->setEnabled(true);
    }
}

void MainWindow::on_presUndoIndex_clicked()
{
    this->userPresList.undoLastAddedIndex();
    ui->presListCounter->display(userPresList.getUserSelectedList().size());

    if(this->userPresList.getUserSelectedList().size() == 0){
        ui->presUndoIndex->setEnabled(false);
        ui->presClearList->setEnabled(false);
        ui->presGraphList->setEnabled(false);
        ui->presListContentView->setEnabled(false);
    }
}

void MainWindow::on_presClearList_clicked()
{
    this->userPresList.clearSelectedList();
    ui->presListCounter->display(userPresList.getUserSelectedList().size());

    ui->presUndoIndex->setEnabled(false);
    ui->presClearList->setEnabled(false);
    ui->presGraphList->setEnabled(false);
    ui->presListContentView->setEnabled(false);
}

void MainWindow::on_fundsAddIndex_clicked()
{
    QString clickedName = this->currentFund.data(Qt::DisplayRole).toString();
    int checkDuplicateStorage = userFundList.searchSelectedList(this->currentFund);
    if(checkDuplicateStorage < 0){
        userFundList.insertIndex(this->currentFund);
    }
    ui->fundsListCounter->display(userFundList.getUserSelectedList().size());

    if(this->userFundList.getUserSelectedList().size() > 0){
        ui->fundsUndoIndex->setEnabled(true);
        ui->fundsClearList->setEnabled(true);
        ui->fundGraphList->setEnabled(true);
        ui->fundListContentView->setEnabled(true);
    }
}

void MainWindow::on_fundsUndoIndex_clicked()
{
    this->userFundList.undoLastAddedIndex();
    ui->fundsListCounter->display(userFundList.getUserSelectedList().size());

    if(this->userFundList.getUserSelectedList().size() == 0){
        ui->fundsUndoIndex->setEnabled(false);
        ui->fundsClearList->setEnabled(false);
        ui->fundGraphList->setEnabled(false);
        ui->fundListContentView->setEnabled(true);
    }
}

void MainWindow::on_fundsClearList_clicked()
{
    this->userFundList.clearSelectedList();
    ui->fundsListCounter->display(userFundList.getUserSelectedList().size());

    ui->fundsUndoIndex->setEnabled(false);
    ui->fundsClearList->setEnabled(false);
    ui->fundGraphList->setEnabled(false);
    ui->fundListContentView->setEnabled(true);
}


void MainWindow::on_fundGraphList_clicked()
{
    std::vector<std::string> parentsList;
    QString clickedName;
    std::vector<std::pair <std::string, double>> chartList;

    if(!(parentsList.size()==fundSortOrder.size() && fundSortOrder.at((size_t)parentsList.size()-1) == "Title")){
        for(int i=0;i<userFundList.getUserSelectedList().size();i++){
            QModelIndex index = userFundList.getUserSelectedList().at(i);
            clickedName = index.data(Qt::DisplayRole).toString();
            QModelIndex current = index;
            QString name;
            std::vector<std::string> makeparentsList;
            while (true) {
                name = current.data(Qt::DisplayRole).toString();
                if(name!="") {
                    auto it = makeparentsList.begin();
                    it = makeparentsList.insert(it, name.toStdString());
                } else {
                    break;
                }
                current = current.parent();
            }
            parentsList = makeparentsList;
            std::vector<std::string> sortOrder(fundSortOrder.begin(), fundSortOrder.begin()+parentsList.size()+1);
            std::vector<std::pair <std::string, double>> newList = funddb->getTotalsTuple(yearStart, yearEnd, sortOrder, parentsList, "Total Amount", getFilterStartChar(FUNDING), getFilterEndChar(FUNDING));
            if (!chartList.empty()){
                for (int i=0; i<(int)newList.size();i++){
                    bool found = false;
                    for (int j=0;j<(int)chartList.size();j++){
                        if (newList.at(i).first == chartList.at(j).first){
                            chartList.at(j).second = chartList.at(j).second + newList.at(i).second;
                            found = true;
                            break;
                        }
                    }
                    if (!found){
                        chartList.insert(chartList.end(),newList.at(i));
                    }
                }
            } else {
                chartList = newList;
            }
        }
        if (!chartList.empty()) {
            ui->fundBarChart->clearPlottables();
            setupBarChart(ui->fundBarChart, chartList);
            ui->fundBarChart->replot();

            setupPieChart(ui->fundPieChart, ui->fundPieList, chartList);

            //Line Graph
            ui->fundLineChart->clearPlottables();
            setupLineGraph(ui->fundLineChart, chartList);
            ui->fundLineChart->replot();

            //Scatter plot Graph
            ui->fundScatterChart->clearPlottables();
            setupScatterGraph(ui->fundScatterChart, chartList);
            ui->fundScatterChart->replot();

            if (parentsList.size()>1) {
                ui->fundGraphTitle->setText("Total " + clickedName + " Grants & Funding by Custom List");
            } else {
                ui->fundGraphTitle->setText("Total Grants & Funding by Custom List");
            }
            ui->fund_graph_stackedWidget->show();
        }
    }
}
void MainWindow::on_pubGraphList_clicked()
{
    std::vector<std::string> parentsList;
    QString clickedName;
    std::vector<std::pair <std::string, double>> chartList;

    if(!(parentsList.size()==pubSortOrder.size() && pubSortOrder.at((size_t)parentsList.size()-1) == "Title")){
        for(int i=0;i<userPubList.getUserSelectedList().size();i++){
            QModelIndex index = userPubList.getUserSelectedList().at(i);
            clickedName = index.data(Qt::DisplayRole).toString();

            QModelIndex current = index;
            QString name;
            std::vector<std::string> makeparentsList;
            while (true) {
                name = current.data(Qt::DisplayRole).toString();
                if(name!="") {
                    auto it = makeparentsList.begin();
                    it = makeparentsList.insert(it, name.toStdString());
                } else {
                    break;
                }
                current = current.parent();
            }
            parentsList = makeparentsList;

            std::vector<std::string> sortOrder(pubSortOrder.begin(), pubSortOrder.begin()+parentsList.size()+1);
            std::vector<std::pair <std::string, int>> list =
                    pubdb->getCountTuple(yearStart, yearEnd, sortOrder, parentsList, getFilterStartChar(PUBLICATIONS), getFilterEndChar(PUBLICATIONS));
            std::vector<std::pair <std::string, double>> newList;
            for (int i = 0; i < (int) list.size(); i++) {
                newList.emplace_back(list[i].first, static_cast<double>(list[i].second));
            }

            if (!chartList.empty()){
                for (int i=0; i<(int)newList.size();i++){
                    bool found = false;
                    for (int j=0;j<(int)chartList.size();j++){
                        if (newList.at(i).first == chartList.at(j).first){
                            chartList.at(j).second = chartList.at(j).second + newList.at(i).second;
                            found = true;
                            break;
                        }
                    }
                    if (!found){
                        chartList.insert(chartList.end(),newList.at(i));
                    }
                }
            } else {
                chartList = newList;
            }
        }

        if (!chartList.empty()) {
            ui->pubBarChart->clearPlottables();
            setupBarChart(ui->pubBarChart, chartList);
            ui->pubBarChart->replot();

            setupPieChart(ui->pubPieChart, ui->pubPieList, chartList);

            //Line Graph
            ui->pubLineChart->clearPlottables();
            setupLineGraph(ui->pubLineChart, chartList);
            ui->pubLineChart->replot();

            //Scatter plot Graph
            ui->pubScatterChart->clearPlottables();
            setupScatterGraph(ui->pubScatterChart, chartList);
            ui->pubScatterChart->replot();

            if (parentsList.size()>1) {
                ui->pubGraphTitle->setText("Total " + clickedName + " Publications by Custom List");
            } else {
                ui->pubGraphTitle->setText("Total Publications by Total List");
            }
            ui->pub_graph_stackedWidget->show();
        }
    } else {
        ui->pub_graph_stackedWidget->hide();
        ui->pubGraphTitle->clear();
        pubClickedName.clear();
    }
}

void MainWindow::on_presGraphList_clicked()
{
    std::vector<std::string> parentsList;
    QString clickedName;
    std::vector<std::pair <std::string, double>> chartList;

    if(!(parentsList.size()==presSortOrder.size() && presSortOrder.at((size_t)parentsList.size()-1) == "Title")){
        for(int i=0;i<userPresList.getUserSelectedList().size();i++){
            QModelIndex index = userPresList.getUserSelectedList().at(i);
            clickedName = index.data(Qt::DisplayRole).toString();

            QModelIndex current = index;
            QString name;
            std::vector<std::string> makeparentsList;
            while (true) {
                name = current.data(Qt::DisplayRole).toString();
                if(name!="") {
                    auto it = makeparentsList.begin();
                    it = makeparentsList.insert(it, name.toStdString());
                } else {
                    break;
                }
                current = current.parent();
            }
            parentsList = makeparentsList;
            //QModelIndex next = index.child(index.row(),index.column());

            //if (next.data(Qt::DisplayRole).toString() != ""){


            std::vector<std::string> sortOrder(presSortOrder.begin(), presSortOrder.begin()+parentsList.size()+1);
            std::vector<std::pair <std::string, int>> list =
                    presdb->getCountTuple(yearStart, yearEnd, sortOrder, parentsList, getFilterStartChar(PRESENTATIONS), getFilterEndChar(PRESENTATIONS));
            std::vector<std::pair <std::string, double>> newList;
            for (int i = 0; i < (int) list.size(); i++) {
                newList.emplace_back(list[i].first, static_cast<double>(list[i].second));
                //}

                if (!chartList.empty()){
                    for (int i=0; i<(int)newList.size();i++){
                        bool found = false;
                        for (int j=0;j<(int)chartList.size();j++){
                            if (newList.at(i).first == chartList.at(j).first){
                                chartList.at(j).second = chartList.at(j).second + newList.at(i).second;
                                found = true;
                                break;
                            }
                        }
                        if (!found){
                            chartList.insert(chartList.end(),newList.at(i));
                        }
                    }
                } else {
                    chartList = newList;
                }
            }

            if (!chartList.empty()) {
                ui->presBarChart->clearPlottables();
                setupBarChart(ui->presBarChart, chartList);
                ui->presBarChart->replot();

                setupPieChart(ui->presPieChart, ui->presPieList, chartList);

                //Line Graph
                ui->presLineChart->clearPlottables();
                setupLineGraph(ui->presLineChart, chartList);
                ui->presLineChart->replot();

                //Scatter plot Graph
                ui->presScatterChart->clearPlottables();
                setupScatterGraph(ui->presScatterChart, chartList);
                ui->presScatterChart->replot();

                if (parentsList.size()>1) {
                    ui->presGraphTitle->setText("Total " + clickedName + " Presentations by Custom List");
                } else {
                    ui->presGraphTitle->setText("Total Presentations by Custom List");
                }
                ui->pres_graph_stackedWidget->show();
            }
        }
    }
}

void MainWindow::on_teachGraphList_clicked()
{
    std::vector<std::string> parentsList;
    QString clickedName;
    std::vector<std::pair <std::string, double>> chartList;

    if(!(parentsList.size()==teachSortOrder.size() && teachSortOrder.at((size_t)parentsList.size()-1) == "Program")){
        for(int i=0;i<userTeachList.getUserSelectedList().size();i++){
            QModelIndex index = userTeachList.getUserSelectedList().at(i);
            clickedName = index.data(Qt::DisplayRole).toString();

            QModelIndex current = index;
            QString name;
            std::vector<std::string> makeparentsList;
            while (true) {
                name = current.data(Qt::DisplayRole).toString();
                if(name!="") {
                    auto it = makeparentsList.begin();
                    it = makeparentsList.insert(it, name.toStdString());
                } else {
                    break;
                }
                current = current.parent();
            }
            parentsList = makeparentsList;

            std::vector<std::string> sortOrder(teachSortOrder.begin(), teachSortOrder.begin()+parentsList.size()+1);
            std::vector<std::pair <std::string, int>> list =
                    teachdb->getCountTuple(yearStart, yearEnd, sortOrder, parentsList, getFilterStartChar(TEACH), getFilterEndChar(TEACH));
            std::vector<std::pair <std::string, double>> newList;
            for (int i = 0; i < (int) list.size(); i++) {
                newList.emplace_back(list[i].first, static_cast<double>(list[i].second));
            }


            if (!chartList.empty()){
                for (int i=0; i<(int)newList.size();i++){
                    bool found = false;
                    for (int j=0;j<(int)chartList.size();j++){
                        if (newList.at(i).first == chartList.at(j).first){
                            chartList.at(j).second = chartList.at(j).second + newList.at(i).second;
                            found = true;
                            break;
                        }
                    }
                    if (!found){
                        chartList.insert(chartList.end(),newList.at(i));
                    }
                }
            } else {
                chartList = newList;
            }
        }


        if (!chartList.empty()) {
            ui->teachBarChart->clearPlottables();
            setupBarChart(ui->teachBarChart, chartList);
            ui->teachBarChart->replot();

            setupPieChart(ui->teachPieChart, ui->teachPieList, chartList);

            //Line Graph
            ui->teachLineChart->clearPlottables();
            setupLineGraph(ui->teachLineChart, chartList);
            ui->teachLineChart->replot();

            //Scatter plot Graph
            ui->teachScatterChart->clearPlottables();
            setupScatterGraph(ui->teachScatterChart, chartList);
            ui->teachScatterChart->replot();

            if (parentsList.size()>1) {
                ui->teachGraphTitle->setText("Total " + clickedName + " Teaching by Custom List");
            } else {
                ui->teachGraphTitle->setText("Total Teaching by Custom List");
            }
            ui->teach_graph_stackedWidget->show();
        }
    }
}

void MainWindow::on_teachListContentView_clicked()
{
    QModelIndex parentIndex;
    int rows = ui->teachTreeView->model()->rowCount();
        //Toggle to view the contents of the user selected list
        if(ui->teachListContentView->text() == "View Contents of List"){
            ui->teachListContentView->setText("View Original List");

            for(int rowPosition = 0; rowPosition < rows; rowPosition++){
                ui->teachTreeView->setRowHidden(rowPosition, parentIndex, true);
            }

            QVector<QModelIndex> referenceList = userTeachList.getUserSelectedList();
            for(int listIndex = 0; listIndex < referenceList.size(); listIndex++) {
                QModelIndex storedIndex = referenceList[listIndex];
                int storedRow = storedIndex.row();
                ui->teachTreeView->setRowHidden(storedRow, parentIndex, false);
            }
        }
        //Toggle to view the original List
        else{
            ui->teachListContentView->setText("View Contents of List");
            for(int rowPosition = 0; rowPosition < rows; rowPosition++){
                ui->teachTreeView->setRowHidden(rowPosition, parentIndex, false);
            }

        }
}

void MainWindow::on_pubListContentView_clicked()
{
    QModelIndex parentIndex;
    int rows = ui->pubTreeView->model()->rowCount();
        //Toggle to view the contents of the user selected list
        if(ui->pubListContentView->text() == "View Contents of List"){
            ui->pubListContentView->setText("View Original List");

            for(int rowPosition = 0; rowPosition < rows; rowPosition++){
                ui->pubTreeView->setRowHidden(rowPosition, parentIndex, true);
            }

            QVector<QModelIndex> referenceList = userPubList.getUserSelectedList();
            for(int listIndex = 0; listIndex < referenceList.size(); listIndex++) {
                QModelIndex storedIndex = referenceList[listIndex];
                int storedRow = storedIndex.row();
                ui->pubTreeView->setRowHidden(storedRow, parentIndex, false);
            }
        }
        //Toggle to view the original List
        else{
            ui->pubListContentView->setText("View Contents of List");
            for(int rowPosition = 0; rowPosition < rows; rowPosition++){
                ui->pubTreeView->setRowHidden(rowPosition, parentIndex, false);
            }

        }
}

void MainWindow::on_presListContentView_clicked()
{
    QModelIndex parentIndex;
    int rows = ui->presTreeView->model()->rowCount();
        //Toggle to view the contents of the user selected list
        if(ui->presListContentView->text() == "View Contents of List"){
            ui->presListContentView->setText("View Original List");

            for(int rowPosition = 0; rowPosition < rows; rowPosition++){
                ui->presTreeView->setRowHidden(rowPosition, parentIndex, true);
            }

            QVector<QModelIndex> referenceList = userPresList.getUserSelectedList();
            for(int listIndex = 0; listIndex < referenceList.size(); listIndex++) {
                QModelIndex storedIndex = referenceList[listIndex];
                int storedRow = storedIndex.row();
                ui->presTreeView->setRowHidden(storedRow, parentIndex, false);
            }
        }
        //Toggle to view the original List
        else{
            ui->presListContentView->setText("View Contents of List");
            for(int rowPosition = 0; rowPosition < rows; rowPosition++){
                ui->presTreeView->setRowHidden(rowPosition, parentIndex, false);
            }

        }
}

void MainWindow::on_fundListContentView_clicked()
{
    QModelIndex parentIndex;
    int rows = ui->fundTreeView->model()->rowCount();
        //Toggle to view the contents of the user selected list
        if(ui->fundListContentView->text() == "View Contents of List"){
            ui->fundListContentView->setText("View Original List");

            for(int rowPosition = 0; rowPosition < rows; rowPosition++){
                ui->fundTreeView->setRowHidden(rowPosition, parentIndex, true);
            }

            QVector<QModelIndex> referenceList = userFundList.getUserSelectedList();
            for(int listIndex = 0; listIndex < referenceList.size(); listIndex++) {
                QModelIndex storedIndex = referenceList[listIndex];
                int storedRow = storedIndex.row();
                ui->fundTreeView->setRowHidden(storedRow, parentIndex, false);
            }
        }
        //Toggle to view the original List
        else{
            ui->fundListContentView->setText("View Contents of List");
            for(int rowPosition = 0; rowPosition < rows; rowPosition++){
                ui->fundTreeView->setRowHidden(rowPosition, parentIndex, false);
            }
        }
}
