#include "utils.h"
#include "node.h"
#include <QVariant>
#include <QTableWidgetItem>
#include <QDebug>
utils::utils()
{

}
bool utils::isSetWall=false;
bool utils::isSetStart=false;
bool utils::isSetFinish=false;

void utils::initializeTable(QTableWidget* table,const int rowSize,const int colSize){
    for(int row=0; row<rowSize;row++){
        for(int col=0; col<colSize; col++){
          Node node(row,col);
          QVariant variant;
          variant.setValue(node);
          QTableWidgetItem* qItem=new QTableWidgetItem();
          qItem->setData( Qt::EditRole, variant);
          table->setItem(row,col,qItem);
        }
    }

}

void utils::clearPrevStartPoint(QTableWidget *table, const int rowSize, const int colSize){
    for(int row=0; row<rowSize;row++){
        for(int col=0; col<colSize; col++){
            QTableWidgetItem* item= table->item(row,col);
            QVariant varient=item->data(Qt::EditRole);
            Node node=varient.value<Node>();
            //qDebug()<<node.isEnd()<<node.isWall()<<node.isStart()<<QString::number( node.getRow()) << QString::number(node.getColumn());
            if(node.isStart()){
                item->setBackground(Qt::white);
                node.setStart(false);
                varient.setValue(node);
                item->setData(Qt::EditRole, varient);
                return;
            }
        }
     }
}

void utils::clearPrevFinishPoint(QTableWidget *table, const int rowSize, const int colSize){
    for(int row=0; row<rowSize;row++){
        for(int col=0; col<colSize; col++){
            QTableWidgetItem* item= table->item(row, col);
            QVariant varient=item->data(Qt::EditRole);
            Node node=varient.value<Node>();
            if(node.isEnd()){
                item->setBackground(Qt::white);
                node.setEnd(false);
                varient.setValue(node);
                item->setData(Qt::EditRole, varient);
                return;
            }
        }
     }
}
