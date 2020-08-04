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
int utils::startRow=INT_MAX;
int utils::startCol=INT_MAX;
int utils::finishRow=INT_MAX;
int utils::finishCol=INT_MAX;


Node utils::getTableNode(QTableWidget *table, int row, int col){
    QTableWidgetItem* item= table->item(row, col);
    QVariant varient=item->data(Qt::EditRole);
    Node node=varient.value<Node>();
    return node;
}

void utils::setTableNode(QTableWidget *table, Node node){
    QTableWidgetItem* item= table->item(node.getRow(), node.getColumn());
    QVariant varient = item->data(Qt::EditRole);
    varient.setValue(node);
   if(node.isEnd()) {
       qDebug()<<node.getRow()<<node.getColumn();
   }
    item->setData(Qt::EditRole,varient);
    //table->editItem(item);
}

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


vector<Node> utils::getAllNodesOnGrid(QTableWidget *table){
    vector<Node> nodes;
    for(int row=0; row<utils::ROW_SIZE;row++){
        for(int col=0; col<utils::COL_SIZE;col++){
            Node node=utils::getTableNode(table,row,col);
            nodes.push_back(node);
        }
     }
    return nodes;
}


void utils::sortNodesByDistance(vector<Node> &unvisitedNodes, int n){
    int i, j;
    Node key;
        for (i = 1; i < n; i++)
        {
            key = unvisitedNodes[i];
            j = i - 1;

            /* Move elements of arr[0..i-1], that are
            greater than key, to one position ahead
            of their current position */
            while (j >= 0 && unvisitedNodes[j].getDistance() > key.getDistance())
            {
                unvisitedNodes[j + 1] = unvisitedNodes[j];
                j = j - 1;
            }
            unvisitedNodes[j + 1] = key;
        }

}

list<Node> utils::getUnvisitedNeighbours(QTableWidget *table, Node node){
    list<Node> unvisited;
    unvisited.clear();
    int row=node.getRow();
     int col=node.getColumn();
    if(row > 0){
       Node node=utils::getTableNode(table, row-1, col);
       if(!node.isVisited()){
           unvisited.push_back(node);
       }
    }
    if(row < utils::ROW_SIZE-1){
        Node node=utils::getTableNode(table, row+1, col);
        if(!node.isVisited()){
            unvisited.push_back(node);
        }
    }
    if(col > 0){
        Node node=utils::getTableNode(table, row, col-1);
        if(!node.isVisited()){
            unvisited.push_back(node);
        }
    }
    if(col < utils::COL_SIZE-1){
        Node node=utils::getTableNode(table, row, col+1);
        if(!node.isVisited()){
            unvisited.push_back(node);
        }
    }

    return unvisited;
}

void utils::updateUnvisitedNeighbours(QTableWidget *table, Node node, vector<Node> &unvisitedNodes){
    list<Node> unvisitedNeighbours=utils::getUnvisitedNeighbours(table, node);
    for(Node neighbour: unvisitedNeighbours){
        int index= utils::findNode(neighbour,unvisitedNodes);
        if (index != -1){
            unvisitedNodes.at(index).setDistance(node.getDistance()+1);
            unvisitedNodes.at(index).setPreviousNodeRow(node.getRow());
            unvisitedNodes.at(index).setPreviousNodeCol(node.getColumn());
        }
        neighbour.setDistance(node.getDistance()+1);
        neighbour.setPreviousNodeRow(node.getRow());
        neighbour.setPreviousNodeCol(node.getColumn());
        if(neighbour.isEnd()){
            qDebug()<<"end:"<<neighbour.isEnd()<<"current nodes:"<<neighbour.getRow()<<neighbour.getColumn()<<"previous nodes"<<neighbour.getPreviousNodeRow()<<node.getPreviousNodeCol();
        }
        utils::setTableNode(table,neighbour);
    }
}

int utils::findNode(Node node, vector<Node> allNodes){
    int count=0;
    for(Node nodeInVector:allNodes){
        if(node.getRow()==nodeInVector.getRow() && node.getColumn()==nodeInVector.getColumn()){
            return count;
        }
        count++;
    }
   return -1;
}

list<Node> utils::dijkastra(QTableWidget *table, Node start){
    //qDebug()<<start->getRow()<<start->getColumn()<<(*start).getRow()<<(*start).getColumn();
    list<Node> visitedNodesInOrder;
    start.setDistance(0);
    utils::setTableNode(table, start);
    vector<Node> unvisitedNodes=utils::getAllNodesOnGrid(table);
    int numberOfNodes=unvisitedNodes.size();
    while(numberOfNodes > 0){
        //utils::sortNodesByDistance(unvisitedNodes, numberOfNodes);
        stable_sort(unvisitedNodes.begin(),unvisitedNodes.end());
        Node closestNode=unvisitedNodes.front();
        unvisitedNodes.erase(unvisitedNodes.begin());
        numberOfNodes--;
        if(closestNode.isWall()){
            continue;
        }
        if(closestNode.getDistance()==INT_MAX){
            return visitedNodesInOrder;
        }
        closestNode.setVisited(true);
        utils::setTableNode(table, closestNode);
        visitedNodesInOrder.push_back(closestNode);
        if(closestNode.isEnd()){
          return visitedNodesInOrder;
        }
        utils::updateUnvisitedNeighbours(table,closestNode, unvisitedNodes);
    }
 }



list<Node> utils::getNodesInShortestPathOrder(QTableWidget* table, Node finish){
    list<Node> nodesInShortestPathOrder;
    Node currentNode=finish;
    while(currentNode.getPreviousNodeRow()!=INT_MAX && currentNode.getPreviousNodeCol()!=INT_MAX){
        Node previousNode=utils::getTableNode(table, currentNode.getPreviousNodeRow(), currentNode.getPreviousNodeCol() );
        nodesInShortestPathOrder.push_front(currentNode);
        currentNode=previousNode;
    }
    return nodesInShortestPathOrder;
}

void utils::animateShortestPath(QTableWidget* table, list<Node> nodesInShortestPathOrder){
    int count=0;
    for(Node node: nodesInShortestPathOrder){
        count++;
        QTableWidgetItem* item= table->item(node.getRow(), node.getColumn());
        item->setBackground(Qt::yellow);
        //QThread::usleep(50);

    }
}

void utils::animateDijkstra(QTableWidget *table, list<Node> visitedNodesInOrder, list<Node> nodesInShortestPathOrder){
    int count=0;
    for(Node node: visitedNodesInOrder){
        count++;
        QTableWidgetItem* item= table->item(node.getRow(), node.getColumn());
        item->setBackground(Qt::blue);
        //QThread::usleep(50);
    }
    utils::animateShortestPath(table,nodesInShortestPathOrder);
}







