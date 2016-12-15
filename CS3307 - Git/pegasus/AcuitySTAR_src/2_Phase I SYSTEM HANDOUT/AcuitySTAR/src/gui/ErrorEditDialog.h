#ifndef ERROREDITDIALOG_H
#define ERROREDITDIALOG_H

#include <QDialog>
#include <vector>
#include <string>

class QAbstractButton;

namespace Ui {
    class ErrorEditDialog;
}

class ErrorEditDialog : public QDialog
{
    Q_OBJECT

public:
     ErrorEditDialog(QWidget *parent,
                     std::vector<std::vector<std::string>*>& errors,
                     std::vector<std::string>& headers,
                     std::vector<std::string>& mandatory);
    ~ErrorEditDialog();

private slots:
     void on_save_clicked();
     void on_cancel_clicked();

     void on_PreviousError_clicked();
     void on_NextError_clicked();

public slots :
     void onCellChanged(int row, int column);
private:
    std::vector<std::vector<std::string>*> errorList;
    std::vector<std::string> headerList;
    std::vector<std::string> mandatoryList;
    Ui::ErrorEditDialog *ui;

    std::vector<std::pair<int, int>> errorCells;

    void saveData();

signals:
    void cellChanged(int row, int column);
};

#endif // ERROREDITDIALOG_H
