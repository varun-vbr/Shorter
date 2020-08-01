#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "utils.h"
#include "node.h"
#include <QVariant>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->tableWidget->setRowCount(29);
    ui->tableWidget->setColumnCount(34);
    ui->tableWidget->horizontalHeader()->hide();
    ui->tableWidget->verticalHeader()->hide();
    ui->tableWidget->horizontalHeader()->setDefaultSectionSize(10);    // width
    ui->tableWidget->verticalHeader()->setDefaultSectionSize(10);      // height
    utils::initializeTable(ui->tableWidget,29,34);



}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_tableWidget_cellClicked(int row, int column)
{
    QTableWidgetItem* item= ui->tableWidget->currentItem();
    QVariant varient=item->data(Qt::EditRole);
    Node node=varient.value<Node>();
    qDebug()<<node.isEnd()<<node.isWall()<<node.isStart()<<QString::number( node.getRow()) << QString::number(node.getColumn()) << QString::number(row) << QString::number(column);
    if(utils::isSetWall){
        if(!node.isStart() && !node.isEnd()){
           item->setBackground(Qt::black);
           node.setWall(true);
        }
      }
    else if(utils::isSetStart){
       if(!node.isWall() && !node.isEnd()){
            utils::clearPrevStartPoint(ui->tableWidget, 29,34);
            item->setBackground(Qt::green);
            node.setStart(true);
       }
    }
    else if(utils::isSetFinish){
        if(!node.isWall() && !node.isStart()){
            utils::clearPrevFinishPoint(ui->tableWidget,29,34);
            item->setBackground(Qt::red);
            node.setEnd(true);
        }
    }
    else{
        return;
    }

    varient.setValue(node);
    item->setData(Qt::EditRole, varient);
    qDebug()<<"Text:"<<item->text();
}

void MainWindow::on_actionAdd_Walls_triggered()
{
    utils::isSetWall=true;
    utils::isSetStart=false;
    utils::isSetFinish=false;
}

void MainWindow::on_actionAdd_Start_triggered()
{
    utils::isSetWall=false;
    utils::isSetStart=true;
    utils::isSetFinish=false;
}

void MainWindow::on_actionAdd_End_triggered()
{
    utils::isSetWall=false;
    utils::isSetStart=false;
    utils::isSetFinish=true;
}

void MainWindow::on_actionCancel_Current_Action_triggered()
{
    utils::isSetWall=false;
    utils::isSetStart=false;
    utils::isSetFinish=false;
}

void MainWindow::on_actionClear_grid_triggered()
{
    utils::initializeTable(ui->tableWidget, 29, 34);
}
