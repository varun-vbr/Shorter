#ifndef NODE_H
#define NODE_H
#include <QMetaType>
class Node{
private:
    int row;
    int column;
    int distance=INT_MAX;
    int previousNodeRow=INT_MAX;
    int previousNodeCol=INT_MAX;
    bool start=false;
    bool end=false;
    bool wall=false;
    bool visited=false;

 public:
    Node() = default;
   ~Node() = default;
    Node(const Node &) = default;
    Node &operator=(const Node &) = default;

    Node(const int row,const int column){
        this->row=row;
        this->column=column;
    }
    int getRow();
    int getColumn();
    int getDistance() const;
    bool isStart();
    bool isEnd();
    bool isWall();
    bool isVisited();
    void setRow(int row);
    void setColumn(int col);
    void setStart(bool start);
    void setEnd(bool end);
    void setWall(bool wall);
    void setDistance(int distance);
    void setVisited(bool visited);
    int getPreviousNodeRow() const;
    void setPreviousNodeRow(int value);
    int getPreviousNodeCol() const;
    void setPreviousNodeCol(int value);

    bool operator <(const Node & node) const
        {
            return distance < node.getDistance();
        }

    bool operator -(const Node & node)
        {
            return distance - node.getDistance();
        }
};

Q_DECLARE_METATYPE(Node);

#endif // NODE_H
