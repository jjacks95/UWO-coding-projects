/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "gui/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[85];
    char stringdata0[2238];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 9), // "load_file"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 25), // "on_pres_load_file_clicked"
QT_MOC_LITERAL(4, 48, 24), // "on_pub_load_file_clicked"
QT_MOC_LITERAL(5, 73, 25), // "on_fund_load_file_clicked"
QT_MOC_LITERAL(6, 99, 26), // "on_teach_load_file_clicked"
QT_MOC_LITERAL(7, 126, 25), // "on_teach_new_sort_clicked"
QT_MOC_LITERAL(8, 152, 23), // "on_pub_new_sort_clicked"
QT_MOC_LITERAL(9, 176, 24), // "on_pres_new_sort_clicked"
QT_MOC_LITERAL(10, 201, 24), // "on_fund_new_sort_clicked"
QT_MOC_LITERAL(11, 226, 28), // "on_actionLoad_file_triggered"
QT_MOC_LITERAL(12, 255, 45), // "on_actionClear_Session_for_Ne..."
QT_MOC_LITERAL(13, 301, 40), // "on_actionClear_All_Sort_Order..."
QT_MOC_LITERAL(14, 342, 23), // "on_FromDate_dateChanged"
QT_MOC_LITERAL(15, 366, 4), // "date"
QT_MOC_LITERAL(16, 371, 21), // "on_ToDate_dateChanged"
QT_MOC_LITERAL(17, 393, 7), // "refresh"
QT_MOC_LITERAL(18, 401, 8), // "tabIndex"
QT_MOC_LITERAL(19, 410, 33), // "on_teach_sort_currentIndexCha..."
QT_MOC_LITERAL(20, 444, 5), // "index"
QT_MOC_LITERAL(21, 450, 31), // "on_pub_sort_currentIndexChanged"
QT_MOC_LITERAL(22, 482, 32), // "on_pres_sort_currentIndexChanged"
QT_MOC_LITERAL(23, 515, 32), // "on_fund_sort_currentIndexChanged"
QT_MOC_LITERAL(24, 548, 28), // "on_teach_delete_sort_clicked"
QT_MOC_LITERAL(25, 577, 26), // "on_pub_delete_sort_clicked"
QT_MOC_LITERAL(26, 604, 27), // "on_pres_delete_sort_clicked"
QT_MOC_LITERAL(27, 632, 27), // "on_fund_delete_sort_clicked"
QT_MOC_LITERAL(28, 660, 27), // "on_teach_pie_button_toggled"
QT_MOC_LITERAL(29, 688, 27), // "on_teach_bar_button_toggled"
QT_MOC_LITERAL(30, 716, 25), // "on_pub_pie_button_toggled"
QT_MOC_LITERAL(31, 742, 25), // "on_pub_bar_button_toggled"
QT_MOC_LITERAL(32, 768, 26), // "on_pres_pie_button_toggled"
QT_MOC_LITERAL(33, 795, 26), // "on_pres_bar_button_toggled"
QT_MOC_LITERAL(34, 822, 26), // "on_fund_pie_button_toggled"
QT_MOC_LITERAL(35, 849, 26), // "on_fund_bar_button_toggled"
QT_MOC_LITERAL(36, 876, 24), // "on_teachTreeView_clicked"
QT_MOC_LITERAL(37, 901, 22), // "on_pubTreeView_clicked"
QT_MOC_LITERAL(38, 924, 23), // "on_presTreeView_clicked"
QT_MOC_LITERAL(39, 948, 23), // "on_fundTreeView_clicked"
QT_MOC_LITERAL(40, 972, 29), // "on_categoryTab_currentChanged"
QT_MOC_LITERAL(41, 1002, 32), // "on_teach_filter_from_textChanged"
QT_MOC_LITERAL(42, 1035, 30), // "on_teach_filter_to_textChanged"
QT_MOC_LITERAL(43, 1066, 30), // "on_pub_filter_from_textChanged"
QT_MOC_LITERAL(44, 1097, 28), // "on_pub_filter_to_textChanged"
QT_MOC_LITERAL(45, 1126, 31), // "on_pres_filter_from_textChanged"
QT_MOC_LITERAL(46, 1158, 29), // "on_pres_filter_to_textChanged"
QT_MOC_LITERAL(47, 1188, 31), // "on_fund_filter_from_textChanged"
QT_MOC_LITERAL(48, 1220, 29), // "on_fund_filter_to_textChanged"
QT_MOC_LITERAL(49, 1250, 27), // "on_teachPrintButton_clicked"
QT_MOC_LITERAL(50, 1278, 26), // "on_fundPrintButton_clicked"
QT_MOC_LITERAL(51, 1305, 26), // "on_presPrintButton_clicked"
QT_MOC_LITERAL(52, 1332, 25), // "on_pubPrintButton_clicked"
QT_MOC_LITERAL(53, 1358, 28), // "on_teachExportButton_clicked"
QT_MOC_LITERAL(54, 1387, 27), // "on_fundExportButton_clicked"
QT_MOC_LITERAL(55, 1415, 27), // "on_presExportButton_clicked"
QT_MOC_LITERAL(56, 1443, 26), // "on_pubExportButton_clicked"
QT_MOC_LITERAL(57, 1470, 28), // "on_teach_line_button_toggled"
QT_MOC_LITERAL(58, 1499, 26), // "on_pub_line_button_toggled"
QT_MOC_LITERAL(59, 1526, 27), // "on_pres_line_button_toggled"
QT_MOC_LITERAL(60, 1554, 27), // "on_fund_line_button_toggled"
QT_MOC_LITERAL(61, 1582, 30), // "on_fund_scatter_button_toggled"
QT_MOC_LITERAL(62, 1613, 30), // "on_pres_scatter_button_toggled"
QT_MOC_LITERAL(63, 1644, 29), // "on_pub_scatter_button_toggled"
QT_MOC_LITERAL(64, 1674, 31), // "on_teach_scatter_button_toggled"
QT_MOC_LITERAL(65, 1706, 27), // "on_teachingAddIndex_clicked"
QT_MOC_LITERAL(66, 1734, 28), // "on_teachingUndoIndex_clicked"
QT_MOC_LITERAL(67, 1763, 28), // "on_teachingClearList_clicked"
QT_MOC_LITERAL(68, 1792, 22), // "on_pubAddIndex_clicked"
QT_MOC_LITERAL(69, 1815, 23), // "on_pubUndoIndex_clicked"
QT_MOC_LITERAL(70, 1839, 23), // "on_pubClearList_clicked"
QT_MOC_LITERAL(71, 1863, 23), // "on_presAddIndex_clicked"
QT_MOC_LITERAL(72, 1887, 24), // "on_presUndoIndex_clicked"
QT_MOC_LITERAL(73, 1912, 24), // "on_presClearList_clicked"
QT_MOC_LITERAL(74, 1937, 24), // "on_fundsAddIndex_clicked"
QT_MOC_LITERAL(75, 1962, 25), // "on_fundsUndoIndex_clicked"
QT_MOC_LITERAL(76, 1988, 25), // "on_fundsClearList_clicked"
QT_MOC_LITERAL(77, 2014, 25), // "on_teachGraphList_clicked"
QT_MOC_LITERAL(78, 2040, 23), // "on_pubGraphList_clicked"
QT_MOC_LITERAL(79, 2064, 24), // "on_presGraphList_clicked"
QT_MOC_LITERAL(80, 2089, 24), // "on_fundGraphList_clicked"
QT_MOC_LITERAL(81, 2114, 31), // "on_teachListContentView_clicked"
QT_MOC_LITERAL(82, 2146, 29), // "on_pubListContentView_clicked"
QT_MOC_LITERAL(83, 2176, 30), // "on_presListContentView_clicked"
QT_MOC_LITERAL(84, 2207, 30) // "on_fundListContentView_clicked"

    },
    "MainWindow\0load_file\0\0on_pres_load_file_clicked\0"
    "on_pub_load_file_clicked\0"
    "on_fund_load_file_clicked\0"
    "on_teach_load_file_clicked\0"
    "on_teach_new_sort_clicked\0"
    "on_pub_new_sort_clicked\0"
    "on_pres_new_sort_clicked\0"
    "on_fund_new_sort_clicked\0"
    "on_actionLoad_file_triggered\0"
    "on_actionClear_Session_for_Next_Run_triggered\0"
    "on_actionClear_All_Sort_Orders_triggered\0"
    "on_FromDate_dateChanged\0date\0"
    "on_ToDate_dateChanged\0refresh\0tabIndex\0"
    "on_teach_sort_currentIndexChanged\0"
    "index\0on_pub_sort_currentIndexChanged\0"
    "on_pres_sort_currentIndexChanged\0"
    "on_fund_sort_currentIndexChanged\0"
    "on_teach_delete_sort_clicked\0"
    "on_pub_delete_sort_clicked\0"
    "on_pres_delete_sort_clicked\0"
    "on_fund_delete_sort_clicked\0"
    "on_teach_pie_button_toggled\0"
    "on_teach_bar_button_toggled\0"
    "on_pub_pie_button_toggled\0"
    "on_pub_bar_button_toggled\0"
    "on_pres_pie_button_toggled\0"
    "on_pres_bar_button_toggled\0"
    "on_fund_pie_button_toggled\0"
    "on_fund_bar_button_toggled\0"
    "on_teachTreeView_clicked\0"
    "on_pubTreeView_clicked\0on_presTreeView_clicked\0"
    "on_fundTreeView_clicked\0"
    "on_categoryTab_currentChanged\0"
    "on_teach_filter_from_textChanged\0"
    "on_teach_filter_to_textChanged\0"
    "on_pub_filter_from_textChanged\0"
    "on_pub_filter_to_textChanged\0"
    "on_pres_filter_from_textChanged\0"
    "on_pres_filter_to_textChanged\0"
    "on_fund_filter_from_textChanged\0"
    "on_fund_filter_to_textChanged\0"
    "on_teachPrintButton_clicked\0"
    "on_fundPrintButton_clicked\0"
    "on_presPrintButton_clicked\0"
    "on_pubPrintButton_clicked\0"
    "on_teachExportButton_clicked\0"
    "on_fundExportButton_clicked\0"
    "on_presExportButton_clicked\0"
    "on_pubExportButton_clicked\0"
    "on_teach_line_button_toggled\0"
    "on_pub_line_button_toggled\0"
    "on_pres_line_button_toggled\0"
    "on_fund_line_button_toggled\0"
    "on_fund_scatter_button_toggled\0"
    "on_pres_scatter_button_toggled\0"
    "on_pub_scatter_button_toggled\0"
    "on_teach_scatter_button_toggled\0"
    "on_teachingAddIndex_clicked\0"
    "on_teachingUndoIndex_clicked\0"
    "on_teachingClearList_clicked\0"
    "on_pubAddIndex_clicked\0on_pubUndoIndex_clicked\0"
    "on_pubClearList_clicked\0on_presAddIndex_clicked\0"
    "on_presUndoIndex_clicked\0"
    "on_presClearList_clicked\0"
    "on_fundsAddIndex_clicked\0"
    "on_fundsUndoIndex_clicked\0"
    "on_fundsClearList_clicked\0"
    "on_teachGraphList_clicked\0"
    "on_pubGraphList_clicked\0"
    "on_presGraphList_clicked\0"
    "on_fundGraphList_clicked\0"
    "on_teachListContentView_clicked\0"
    "on_pubListContentView_clicked\0"
    "on_presListContentView_clicked\0"
    "on_fundListContentView_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      80,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  414,    2, 0x08 /* Private */,
       3,    0,  415,    2, 0x08 /* Private */,
       4,    0,  416,    2, 0x08 /* Private */,
       5,    0,  417,    2, 0x08 /* Private */,
       6,    0,  418,    2, 0x08 /* Private */,
       7,    0,  419,    2, 0x08 /* Private */,
       8,    0,  420,    2, 0x08 /* Private */,
       9,    0,  421,    2, 0x08 /* Private */,
      10,    0,  422,    2, 0x08 /* Private */,
      11,    0,  423,    2, 0x08 /* Private */,
      12,    0,  424,    2, 0x08 /* Private */,
      13,    0,  425,    2, 0x08 /* Private */,
      14,    1,  426,    2, 0x08 /* Private */,
      16,    1,  429,    2, 0x08 /* Private */,
      17,    1,  432,    2, 0x08 /* Private */,
      19,    1,  435,    2, 0x08 /* Private */,
      21,    1,  438,    2, 0x08 /* Private */,
      22,    1,  441,    2, 0x08 /* Private */,
      23,    1,  444,    2, 0x08 /* Private */,
      24,    0,  447,    2, 0x08 /* Private */,
      25,    0,  448,    2, 0x08 /* Private */,
      26,    0,  449,    2, 0x08 /* Private */,
      27,    0,  450,    2, 0x08 /* Private */,
      28,    0,  451,    2, 0x08 /* Private */,
      29,    0,  452,    2, 0x08 /* Private */,
      30,    0,  453,    2, 0x08 /* Private */,
      31,    0,  454,    2, 0x08 /* Private */,
      32,    0,  455,    2, 0x08 /* Private */,
      33,    0,  456,    2, 0x08 /* Private */,
      34,    0,  457,    2, 0x08 /* Private */,
      35,    0,  458,    2, 0x08 /* Private */,
      36,    1,  459,    2, 0x08 /* Private */,
      37,    1,  462,    2, 0x08 /* Private */,
      38,    1,  465,    2, 0x08 /* Private */,
      39,    1,  468,    2, 0x08 /* Private */,
      40,    0,  471,    2, 0x08 /* Private */,
      41,    0,  472,    2, 0x08 /* Private */,
      42,    0,  473,    2, 0x08 /* Private */,
      43,    0,  474,    2, 0x08 /* Private */,
      44,    0,  475,    2, 0x08 /* Private */,
      45,    0,  476,    2, 0x08 /* Private */,
      46,    0,  477,    2, 0x08 /* Private */,
      47,    0,  478,    2, 0x08 /* Private */,
      48,    0,  479,    2, 0x08 /* Private */,
      49,    0,  480,    2, 0x08 /* Private */,
      50,    0,  481,    2, 0x08 /* Private */,
      51,    0,  482,    2, 0x08 /* Private */,
      52,    0,  483,    2, 0x08 /* Private */,
      53,    0,  484,    2, 0x08 /* Private */,
      54,    0,  485,    2, 0x08 /* Private */,
      55,    0,  486,    2, 0x08 /* Private */,
      56,    0,  487,    2, 0x08 /* Private */,
      57,    0,  488,    2, 0x08 /* Private */,
      58,    0,  489,    2, 0x08 /* Private */,
      59,    0,  490,    2, 0x08 /* Private */,
      60,    0,  491,    2, 0x08 /* Private */,
      61,    0,  492,    2, 0x08 /* Private */,
      62,    0,  493,    2, 0x08 /* Private */,
      63,    0,  494,    2, 0x08 /* Private */,
      64,    0,  495,    2, 0x08 /* Private */,
      65,    0,  496,    2, 0x08 /* Private */,
      66,    0,  497,    2, 0x08 /* Private */,
      67,    0,  498,    2, 0x08 /* Private */,
      68,    0,  499,    2, 0x08 /* Private */,
      69,    0,  500,    2, 0x08 /* Private */,
      70,    0,  501,    2, 0x08 /* Private */,
      71,    0,  502,    2, 0x08 /* Private */,
      72,    0,  503,    2, 0x08 /* Private */,
      73,    0,  504,    2, 0x08 /* Private */,
      74,    0,  505,    2, 0x08 /* Private */,
      75,    0,  506,    2, 0x08 /* Private */,
      76,    0,  507,    2, 0x08 /* Private */,
      77,    0,  508,    2, 0x08 /* Private */,
      78,    0,  509,    2, 0x08 /* Private */,
      79,    0,  510,    2, 0x08 /* Private */,
      80,    0,  511,    2, 0x08 /* Private */,
      81,    0,  512,    2, 0x08 /* Private */,
      82,    0,  513,    2, 0x08 /* Private */,
      83,    0,  514,    2, 0x08 /* Private */,
      84,    0,  515,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::QString,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDate,   15,
    QMetaType::Void, QMetaType::QDate,   15,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,   20,
    QMetaType::Void, QMetaType::QModelIndex,   20,
    QMetaType::Void, QMetaType::QModelIndex,   20,
    QMetaType::Void, QMetaType::QModelIndex,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QString _r = _t->load_file();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 1: _t->on_pres_load_file_clicked(); break;
        case 2: _t->on_pub_load_file_clicked(); break;
        case 3: _t->on_fund_load_file_clicked(); break;
        case 4: _t->on_teach_load_file_clicked(); break;
        case 5: _t->on_teach_new_sort_clicked(); break;
        case 6: _t->on_pub_new_sort_clicked(); break;
        case 7: _t->on_pres_new_sort_clicked(); break;
        case 8: _t->on_fund_new_sort_clicked(); break;
        case 9: _t->on_actionLoad_file_triggered(); break;
        case 10: _t->on_actionClear_Session_for_Next_Run_triggered(); break;
        case 11: _t->on_actionClear_All_Sort_Orders_triggered(); break;
        case 12: _t->on_FromDate_dateChanged((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        case 13: _t->on_ToDate_dateChanged((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        case 14: _t->refresh((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->on_teach_sort_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->on_pub_sort_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->on_pres_sort_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->on_fund_sort_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->on_teach_delete_sort_clicked(); break;
        case 20: _t->on_pub_delete_sort_clicked(); break;
        case 21: _t->on_pres_delete_sort_clicked(); break;
        case 22: _t->on_fund_delete_sort_clicked(); break;
        case 23: _t->on_teach_pie_button_toggled(); break;
        case 24: _t->on_teach_bar_button_toggled(); break;
        case 25: _t->on_pub_pie_button_toggled(); break;
        case 26: _t->on_pub_bar_button_toggled(); break;
        case 27: _t->on_pres_pie_button_toggled(); break;
        case 28: _t->on_pres_bar_button_toggled(); break;
        case 29: _t->on_fund_pie_button_toggled(); break;
        case 30: _t->on_fund_bar_button_toggled(); break;
        case 31: _t->on_teachTreeView_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 32: _t->on_pubTreeView_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 33: _t->on_presTreeView_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 34: _t->on_fundTreeView_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 35: _t->on_categoryTab_currentChanged(); break;
        case 36: _t->on_teach_filter_from_textChanged(); break;
        case 37: _t->on_teach_filter_to_textChanged(); break;
        case 38: _t->on_pub_filter_from_textChanged(); break;
        case 39: _t->on_pub_filter_to_textChanged(); break;
        case 40: _t->on_pres_filter_from_textChanged(); break;
        case 41: _t->on_pres_filter_to_textChanged(); break;
        case 42: _t->on_fund_filter_from_textChanged(); break;
        case 43: _t->on_fund_filter_to_textChanged(); break;
        case 44: _t->on_teachPrintButton_clicked(); break;
        case 45: _t->on_fundPrintButton_clicked(); break;
        case 46: _t->on_presPrintButton_clicked(); break;
        case 47: _t->on_pubPrintButton_clicked(); break;
        case 48: _t->on_teachExportButton_clicked(); break;
        case 49: _t->on_fundExportButton_clicked(); break;
        case 50: _t->on_presExportButton_clicked(); break;
        case 51: _t->on_pubExportButton_clicked(); break;
        case 52: _t->on_teach_line_button_toggled(); break;
        case 53: _t->on_pub_line_button_toggled(); break;
        case 54: _t->on_pres_line_button_toggled(); break;
        case 55: _t->on_fund_line_button_toggled(); break;
        case 56: _t->on_fund_scatter_button_toggled(); break;
        case 57: _t->on_pres_scatter_button_toggled(); break;
        case 58: _t->on_pub_scatter_button_toggled(); break;
        case 59: _t->on_teach_scatter_button_toggled(); break;
        case 60: _t->on_teachingAddIndex_clicked(); break;
        case 61: _t->on_teachingUndoIndex_clicked(); break;
        case 62: _t->on_teachingClearList_clicked(); break;
        case 63: _t->on_pubAddIndex_clicked(); break;
        case 64: _t->on_pubUndoIndex_clicked(); break;
        case 65: _t->on_pubClearList_clicked(); break;
        case 66: _t->on_presAddIndex_clicked(); break;
        case 67: _t->on_presUndoIndex_clicked(); break;
        case 68: _t->on_presClearList_clicked(); break;
        case 69: _t->on_fundsAddIndex_clicked(); break;
        case 70: _t->on_fundsUndoIndex_clicked(); break;
        case 71: _t->on_fundsClearList_clicked(); break;
        case 72: _t->on_teachGraphList_clicked(); break;
        case 73: _t->on_pubGraphList_clicked(); break;
        case 74: _t->on_presGraphList_clicked(); break;
        case 75: _t->on_fundGraphList_clicked(); break;
        case 76: _t->on_teachListContentView_clicked(); break;
        case 77: _t->on_pubListContentView_clicked(); break;
        case 78: _t->on_presListContentView_clicked(); break;
        case 79: _t->on_fundListContentView_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 80)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 80;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 80)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 80;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
