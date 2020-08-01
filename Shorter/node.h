#ifndef NODE_H
#define NODE_H
#include <QMetaType>
class Node{
private:
    int row;
    int column;
    bool start=false;
    bool end=false;
    bool wall=false;

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
    bool isStart();
    bool isEnd();
    bool isWall();
    void setRow(int row);
    void setColumn(int col);
    void setStart(bool start);
    void setEnd(bool end);
    void setWall(bool wall);
  };

Q_DECLARE_METATYPE(Node);

#endif // NODE_H
