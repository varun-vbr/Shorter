#include "node.h"
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
