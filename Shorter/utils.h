#ifndef UTILS_H
#define UTILS_H
#include "QTableWidget"
#include "node.h"
#include <list>
#include <vector>
#include <algorithm>
#include <QThread>
//#include <QList>

using namespace std;

class utils
{

public:
    utils();
    static const int ROW_SIZE=29;
    static const int COL_SIZE=34;
    static bool isSetWall;
    static bool isSetStart;
    static bool isSetFinish;
    static int startRow;
    static int startCol;
    static int finishRow;
    static int finishCol;

    static void initializeTable(QTableWidget* table, const int rowSize, const int colSize);

    static void clearPrevStartPoint(QTableWidget* table, const int rowSize, const int colSize);

    static void clearPrevFinishPoint(QTableWidget* table, const int rowSize, const int colSize);

    static void sortNodesByDistance(vector<Node> &unvisitedNodes, int n);

    static vector<Node> getAllNodesOnGrid(QTableWidget* table);

    static list<Node> getUnvisitedNeighbours(QTableWidget* table, Node node);

    static void updateUnvisitedNeighbours(QTableWidget* table, Node node, vector<Node> &unvisitedNodes);

    static int findNode(Node node, vector<Node> allNodes);

    static Node getTableNode(QTableWidget* table, int row, int col);

    static void setTableNode(QTableWidget* table, Node node);

    static list<Node> dijkastra(QTableWidget* table, Node start);

    static list<Node> getNodesInShortestPathOrder(QTableWidget* table, Node finish);

    static void animateShortestPath(QTableWidget* table, list<Node> nodesInShortestPathOrder);

    static void animateDijkstra(QTableWidget* table, list<Node> visitedNodesInOrder, list<Node> nodesInShortestPathOrder);

};

#endif // UTILS_H
