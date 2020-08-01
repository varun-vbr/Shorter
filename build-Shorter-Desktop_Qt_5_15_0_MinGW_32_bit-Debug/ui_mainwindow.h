/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAdd_Walls;
    QAction *actionAdd_Start;
    QAction *actionAdd_End;
    QAction *actionCancel_Current_Action;
    QAction *actionRun;
    QAction *actionClear_grid;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QMenuBar *menubar;
    QMenu *menuOptions;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setDockNestingEnabled(false);
        actionAdd_Walls = new QAction(MainWindow);
        actionAdd_Walls->setObjectName(QString::fromUtf8("actionAdd_Walls"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/Wall.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd_Walls->setIcon(icon);
        actionAdd_Start = new QAction(MainWindow);
        actionAdd_Start->setObjectName(QString::fromUtf8("actionAdd_Start"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/Start.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd_Start->setIcon(icon1);
        actionAdd_End = new QAction(MainWindow);
        actionAdd_End->setObjectName(QString::fromUtf8("actionAdd_End"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/End.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd_End->setIcon(icon2);
        actionCancel_Current_Action = new QAction(MainWindow);
        actionCancel_Current_Action->setObjectName(QString::fromUtf8("actionCancel_Current_Action"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/Cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCancel_Current_Action->setIcon(icon3);
        actionRun = new QAction(MainWindow);
        actionRun->setObjectName(QString::fromUtf8("actionRun"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/Run.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRun->setIcon(icon4);
        actionClear_grid = new QAction(MainWindow);
        actionClear_grid->setObjectName(QString::fromUtf8("actionClear_grid"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        if (tableWidget->rowCount() < 5)
            tableWidget->setRowCount(5);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem9);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout->addWidget(tableWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuOptions = new QMenu(menubar);
        menuOptions->setObjectName(QString::fromUtf8("menuOptions"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuOptions->menuAction());
        menuOptions->addAction(actionAdd_Walls);
        menuOptions->addAction(actionAdd_Start);
        menuOptions->addAction(actionAdd_End);
        menuOptions->addAction(actionCancel_Current_Action);
        menuOptions->addAction(actionRun);
        menuOptions->addAction(actionClear_grid);
        toolBar->addAction(actionAdd_Walls);
        toolBar->addAction(actionAdd_Start);
        toolBar->addAction(actionAdd_End);
        toolBar->addAction(actionCancel_Current_Action);
        toolBar->addAction(actionRun);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionAdd_Walls->setText(QCoreApplication::translate("MainWindow", "Add Walls", nullptr));
        actionAdd_Start->setText(QCoreApplication::translate("MainWindow", "Add Start", nullptr));
        actionAdd_End->setText(QCoreApplication::translate("MainWindow", "Add End", nullptr));
        actionCancel_Current_Action->setText(QCoreApplication::translate("MainWindow", "Cancel Current Action", nullptr));
        actionRun->setText(QCoreApplication::translate("MainWindow", "Run", nullptr));
        actionClear_grid->setText(QCoreApplication::translate("MainWindow", "Clear grid", nullptr));
        menuOptions->setTitle(QCoreApplication::translate("MainWindow", "Options", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
