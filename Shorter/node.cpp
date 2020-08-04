#include "node.h"
int Node::getPreviousNodeRow() const
{
    return previousNodeRow;
}

void Node::setPreviousNodeRow(int value)
{
    previousNodeRow = value;
}

int Node::getPreviousNodeCol() const
{
    return previousNodeCol;
}

void Node::setPreviousNodeCol(int value)
{
    previousNodeCol = value;
}

int Node::getRow(){
    return Node::row;
}

int Node::getColumn(){
    return Node::column;
}

bool Node::isStart(){
    return Node::start;
}

bool Node::isEnd(){
    return Node::end;
}

bool Node::isWall(){
    return Node::wall;
}

int Node::getDistance() const{
    return Node::distance;
}



bool Node::isVisited(){
    return Node::visited;
}

void Node::setRow(int row){
    Node::row=row;
}
void Node::setColumn(int col){
    Node::column=col;
}
void Node::setStart(bool start){
    Node::start=start;
}
void Node::setEnd(bool end){
    Node::end=end;
}
void Node::setWall(bool wall){
    Node::wall=wall;
}

void Node::setDistance(int distance){
    Node::distance=distance;
}


void Node::setVisited(bool visited){
    Node::visited=visited;
}
