#include "ui_ErrorEditDialog.h"
#include "ErrorEditDialog.h"

#include <QTableWidgetItem>
#include <QStringList>
#include <QDebug>
#include <QBrush>
#include <QColor>
#include <QAbstractButton>
#include <QMessageBox>

/* Load data contained in the errors vector into a QWidgetTable
 * Fields will be marked red and editable if they are a mandatory field
 * and editable.  Otherwise all other fields will not be editable.
 * Clicking Save in the dialog will return the corrected entries to the main
 * program through the errors parameter.  If not all marked fields are edited
 * then a warning message will be displayed.  If cancel is clicked all errors
 * are discarded.
 */
ErrorEditDialog::ErrorEditDialog(QWidget *parent,
                                 std::vector<std::vector<std::string>*>& errors,
                                 std::vector<std::string>& headers,
                                 std::vector<std::string>& mandatory) :
    QDialog(parent, Qt::WindowTitleHint | Qt::WindowCloseButtonHint),
    errorList(errors),
    headerList(headers),
    mandatoryList(mandatory),
    ui(new Ui::ErrorEditDialog)
{
    // Setup tableWidget to the size we need to display all the rows containing errors.
    ui->setupUi(this);
    ui->tableWidget->setRowCount((int) errors.size());
    ui->tableWidget->setColumnCount((int) headers.size());

    // Setup a prototypeItem for all of this QTableWidget items - thus to make them all selectable and editable.
    QTableWidgetItem* prototypeItem = new QTableWidgetItem();
    prototypeItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable);
    ui->tableWidget->setItemPrototype(prototypeItem);

    // Get headers
    QStringList listHeaders;
    for (int i = 0; i < (int) headers.size(); i++) {
        listHeaders << headers[i].c_str();
    }

     // Reserve the already known necessary size for the class private variable 'errorCells'
    errorCells.reserve(errors.size());

    ui->tableWidget->setHorizontalHeaderLabels(listHeaders); // Name table's columns headers
    QTableWidgetItem* item; // Table item recipiant
    QBrush brush(QColor(255, 0, 0, 100)); // Red bursh for empty mandatory cells
    std::vector<std::vector<std::string>*>::iterator it; // Iterator to loop over errors
    int row = 0;
    for (it = errors.begin(); it != errors.end(); it++) { // Loop over errors
        for (int col = 0; (col < (int) headers.size()) && (col < (int) (*it)->size()); col++) { // Loop over all the header, but restricted to a maximum range of the number of error (for this row ? or over all the row)

            item = new QTableWidgetItem();
            item->setText((*it)->at(col).c_str());

            for (int i = 0; i < (int) mandatory.size(); i++) {

                // If we find a ( mandatory && empty ) cell
                if (mandatory[i].compare(headers.at(col)) == 0
                        && (*it)->at(col).compare("") == 0) {

                    // Paint error cell in red
                    item->setBackground(brush);

                    // Increment the error counter
                    ui->ErrorCounter->display(ui->ErrorCounter->intValue() + 1);

                    // Store the error cell row and column for use in onPreviousError and onNextError.
                    errorCells.push_back(std::make_pair(row, col));
                }
            }
            ui->tableWidget->setItem(row, col, item);
        }
        row++;
    }

    // Attach the non built-in onCellChanged to the built-in cellChanged signal over the QTableWidget
    connect(ui->tableWidget,SIGNAL(cellChanged(int, int)), this, SLOT(onCellChanged(int, int)));

    // Just a security to set up properly the intial current selected cell.
    ui->tableWidget->setCurrentCell(errorCells[0].first, errorCells[0].second);
}

/* ErrorEditDialog destructor :
 * Clean up allocated memory for the table items used by the ErrorEditDialog
 * and clean up the allocated memory for the ErrorEditDialog ui
 */
ErrorEditDialog::~ErrorEditDialog()
{
    // Loop over all the table's cells.
    for (int i = 0; i < ui->tableWidget->rowCount(); i++) { // Loop over rows
        for (int j = 0; j < ui->tableWidget->columnCount(); j++) { // Loop over columns
            delete ui->tableWidget->item(i,j);
        }
    }
    delete ui;
}

/* This method deals with saving the the changes made by the user
 * to the CSV file (filling empty mandatory cells) without checking
 * anything about data correctness.
 * This method will save only the cells that had errors.
 */
void ErrorEditDialog::saveData() {
    for (int row = 0; row < ui->tableWidget->rowCount(); row++) { // Loop over all rows
        for (int col = 0; col < (ui->tableWidget->columnCount()) && (col < (int) errorList[row]->size()); col++) { // Loop over a number of column restricted to a maximum range of the number error columns for this row

            /* N.B : errorList a copy of a part of the QTableWidget containing all the rows,
             * but its column only up the the last mandatory column (to reduce size a little).
             *
             * The user modified the cells in the QTableWidget.
             * After modifications, we compare the mandatory cells of the QTableWidget to
             * the errorList (that kept track of the QTableWidget before any modifications)
             * and only rewrite the errorList mandatory empty cells according to the changes made
             * in the QTableWidget table.
             */

            // Setup an iterator that contains the error for this row and this col
            std::vector<std::string>::iterator it = errorList[row]->begin() + col;

            // If the cell at row,col in errorList is an error cell
            if (errorList[row]->at(col).compare("") == 0) {
                it = errorList[row]->erase(it); // Empty the cell at row,col in errorList
                errorList[row]->insert(it, ui->tableWidget->item(row, col)->text().toStdString()); // And fill it with the text of the modified cell in the QTableWidget at row,col
            }
        }
    }
    accept();
}

/* This method deals with accepting or rejecting to save a CSV file after
 * the user filled the empty cells of mandatory fields.
 * The method won't allow the user to save the changes until all the empty
 * cells of mandatory fields.
 */
void ErrorEditDialog::on_save_clicked() // Improved Version // Checked
{
    // Check if mandatory fields have been filled
    for (int row = 0; row < ui->tableWidget->rowCount(); row++) { // Loop over rows
        for (int j = 0; j < (int) mandatoryList.size(); j++) { // Loop over mandatory columns

            // Setup an iterator that loops only over the mandatory fields of the file
            std::vector<std::string>::iterator it = std::find(headerList.begin(), headerList.end(), mandatoryList[j]);
            int col = it - headerList.begin();
            QTableWidgetItem* item = ui->tableWidget->item(row, col);

            // If any (mandatory) cell is empty
            if (item && (item->text().compare("") == 0)) { // if (item->text().compare("") == 0) {
                QMessageBox::critical(this, "Error", "Mandatory fields are still empty.");
                return; // Cut the loop and exit the method.
                // N.B: Because of the return, the saveData() won't be executed if this case is accountered.
            }
        }
    }
    saveData(); // Save the changes
}

/* This method deals with closing the CSV file editing window if the user
 * doesn't want to edit the empty mandatory cells ANYMORE.
 */
void ErrorEditDialog::on_cancel_clicked()
{
    reject();
}

/* This method find the previous non-fixed error cell (= red cell) before the current selected cell.
 * If there is a non-fixed error cell (= red cell) before the current selected cell, it changes the current selected cell to this previous non-fixed error cell.
 * If there is NOT a non-fixed error cell (= red cell) before the current selected cell, it triggers a pop-up notification to inform the user.
 */
void ErrorEditDialog::on_PreviousError_clicked()
{
    if (ui->ErrorCounter->intValue() > 0) { // If there are errors left to fix

        QBrush redBrush(QColor(255, 0, 0, 100)); // Red brush for fixed cell

        // Get the current selected cell
        int currentRow = ui->tableWidget->currentRow();
        int currentColumn = ui->tableWidget->currentColumn();

        // Setup an iterator to iterate over the errorCells
        std::vector<std::pair<int,int>>::iterator it ;

        // 1) FORWARD SEARCH until current selected error cell, or closest cell to current selected cell --------

        // Loop over the errorCells iterator to find the current (row, col) error cell index pair
        for (it = errorCells.begin() ; it != errorCells.end() ; it++) {

            // Keep going until we find and error cell that 'is', or 'is after' the current cell
            if ((it->first > currentRow) || // Greater Row
                    ((it->first == currentRow) && (it->second >= currentColumn))) { // Same row and same or greater column
                break;
            }
        }

        if (it == errorCells.end()) { // If there is no error cell before the current cell, we reach the end of the iterator
            it--;
        }

        if (it == errorCells.begin()) { // if the first error cell is after the current selection

            QMessageBox::critical(this, "Notification", "There is no error cell previous to the current selected cell.");
            return;

        } else {

            // If the current selected cell was an error cell and we advanced to it
            if ((it->first == currentRow) && (it->first < currentColumn)) { // Important
                it--;  // Put the cell asside from the search
            }

            // 2) BACKWARD SEARCH the previous non-fixed error cell ---------------------------------------------

            // Setup a 'current item' recipiant to test the cell background color.
            QTableWidgetItem* item = ui->tableWidget->item(it->first, it->second);

            // Backtrack to the closest previous error cell, until we reach the first error cell.
            while (it != errorCells.begin()) {

                if (((it->first < currentRow) || // Lesser row
                     ((it->first == currentRow) && (it->second < currentColumn))) && // or Same row, lesser column
                        (item->background() == redBrush)) { // And is red (= non-fixed error cell)

                    ui->tableWidget->setCurrentCell(it->first, it->second);
                    ui->tableWidget->setCurrentItem(ui->tableWidget->item(it->first, it->second));
                    return;

                } else { // Else keep backtracking
                    it--;
                    item = ui->tableWidget->item(it->first, it->second);
                }
            }

            // --------------------------------------------------------------------------------------------------

            // 3) SEARCH TERMINATION CHECK ----------------------------------------------------------------------

            if (it == errorCells.begin()) { // If reached the first error cell while backtracking

                // Update item
                item = ui->tableWidget->item(it->first, it->second);

                if (item->background() == redBrush) { // If this error cell is non-fixed, then ok

                    ui->tableWidget->setCurrentCell(it->first, it->second);
                    ui->tableWidget->setCurrentItem(ui->tableWidget->item(it->first, it->second));

                } else { // Else, there is no non-fixed error cells previous the to current error cell.
                    QMessageBox::critical(this, "Notification", "There is no non-fixed error cell previous to the current selected cell.");
                    return;
                }
            }
            // --------------------------------------------------------------------------------------------------
        }
    }
}

/* This method find the next non-fixed error cell (= red cell) after the current selected cell.
 * If there is a non-fixed error cell (= red cell) after the current selected cell, it changes the current selected cell to the next non-fixed error cell.
 * If there is NOT a non-fixed error cell (= red cell) after the current selected cell, it triggers a pop-up notification to inform the user.
 */
void ErrorEditDialog::on_NextError_clicked()
{
    if (ui->ErrorCounter->intValue() > 0) { // If there are mistakes left to fix

        QBrush redBrush(QColor(255, 0, 0, 100)); // Red brush for fixed cell

        // 1) FORWARD SEARCH until current selected error cell, or closest cell to current selected cell -----

        // Get the current selected cell
        int currentRow = ui->tableWidget->currentRow();
        int currentColumn = ui->tableWidget->currentColumn();

        // Setup an iterator to iterate over the errorCells
        std::vector<std::pair<int,int>>::iterator it ;

        // Loop over the errorCells iterator to find the current selected error cell or the closest error cell before the current selected error cell.
        for (it = errorCells.begin() ; it != errorCells.end() ; it++) {

            // Keep going until we find and error cell that 'is', or 'is after' the current cell
            if ((it->first > currentRow) || // Greater Row
                    ((it->first == currentRow) && (it->second > currentColumn))) { // Same row and same or greater column
                break;
            }
        }

        // If there is no error cell after the current cell, we reach the end of the iterator
        if (it == errorCells.end()) {

            QMessageBox::critical(this, "Notification", "There is no error cell next to the current selected cell.");
            return;

        } else {

            // If the current selected cell was an error cell and we advanced to it
            if ((it->first == currentRow) && (it->first == currentColumn)) { // Important

                it++; // Put the cell asside from the search

                if (it == errorCells.end()) { // If current cell was the last error cell
                    QMessageBox::critical(this, "Notification", "There is no error cellnext to the current selected cell.");
                    return;
                }
            }

            // 2) FORWARD SEARCH the next non-fixed error cell --------------------------------------------------

            // Setup a 'current item' recipiant to test the cell background color.
            QTableWidgetItem* item = ui->tableWidget->item(it->first, it->second);

            // Backtrack to the closest previous error cell, until we reach the first error cell.
            while (it != errorCells.end()) {

                if (((it->first > currentRow) || // Lesser row
                     ((it->first == currentRow) && (it->first > currentColumn))) && // or Same row, lesser column
                        (item->background() == redBrush)) { // And is red (= non-fixed error cell)

                    ui->tableWidget->setCurrentCell(it->first, it->second);
                    ui->tableWidget->setCurrentItem(ui->tableWidget->item(it->first, it->second));
                    return;

                } else { // Else keep backtracking
                    it++;
                    item = ui->tableWidget->item(it->first, it->second);
                }
            }
            // --------------------------------------------------------------------------------------------------

            // 3) SEARCH TERMINATION CHECK ----------------------------------------------------------------------

            if (it == errorCells.end()) { // If reached the end of the interator
                QMessageBox::critical(this, "Notification", "There is no non-fixed error cell next to the current selected cell.");
                return;
            }
            // --------------------------------------------------------------------------------------------------
        }
    }
}

void ErrorEditDialog::onCellChanged(int row, int column) {

    /* N.B: This method is a callback function for the signal cellChanged that is triggered anytime that any cell in the QTableWidget is changed.
     * We want to use this callback to paint in blue and disable editing on the cell once the user changed it.
     * The problem to consider here is that by painting in blue and disable editing on the cell we will (obviously) have to change this cell,
     * But this induce a new call of this callback method ! This is why we introduce a if statment to check weither we already changed the cell or not.
     * (e.g if it is already blue and not editable) If we don't do that, an infinite loop of onCellChanged callback will be trigger an any cell changed.
     */

    if ((row != -1) && (column != -1)) { // To avoid QT internal calls on cellChanged(-1,-1) for what ever reason.

        QBrush redBrush(QColor(255, 0, 0, 100)); // Red brush for error cell
        QBrush greenBrush(QColor(0, 255, 0, 100)); // Green brush for modified non-error cells
        QBrush blueBrush(QColor(0, 0, 255, 100)); // Blue brush for fixed cell

        QTableWidgetItem* item = ui->tableWidget->item(row, column); // Get the changed cell
        QString new_input_string = item->text(); // The new string input to the cell

        // If this callback is not due to this callback's job
        if ((item->background() == redBrush) && // the background is not blue
                !(new_input_string.isEmpty())) { // And the new input string is not empty

            // Decrement Error Counter value
            ui->ErrorCounter->display(std::max(0, ui->ErrorCounter->intValue() - 1));

            // If there is no more errors, disable buttons.
            if (ui->ErrorCounter->intValue() <= 0) {
                ui->PreviousError->setEnabled(false);
                ui->NextError->setEnabled(false);
            }

            // Paint the cell in blue to show that it has been fixed and is no more accessible.
            item->setBackground(blueBrush); // Triggers one cellChanged event

        // If a already fixed cell has been RE-modified with an empty value
        } else if ((item->background() == blueBrush) &&
                   new_input_string.isEmpty()) {

            // Increment Error Counter value to restoring an error cell
            ui->ErrorCounter->display(ui->ErrorCounter->intValue() + 1);

            // If there is newly remaining errors again, enable buttons.
            if (ui->ErrorCounter->intValue() >= 1) {
                ui->PreviousError->setEnabled(true);
                ui->NextError->setEnabled(true);
            }

            // Re-paint the cell in red to show that the modification made is not valide.
            item->setBackground(redBrush); // Triggers one cellChanged event

        // If the cell was not painted - the user changed a non-error cell - Let him do whatever, just paint the cell in green to highlight the one he changed.
        } else if ((item->background() != blueBrush) && (item->background() != redBrush) && !(new_input_string.isEmpty())) {

            // Paint the cell in green to show that the non-error cell has been re-edited.
            item->setBackground(greenBrush); // Triggers one cellChanged event

        } else { // White cell

            // Else ignore
        }
    }
}
