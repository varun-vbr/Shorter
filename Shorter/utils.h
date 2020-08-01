#ifndef UTILS_H
#define UTILS_H
#include "QTableWidget"

class utils
{

public:
    utils();
    static bool isSetWall;
    static bool isSetStart;
    static bool isSetFinish;
    static void initializeTable(QTableWidget* table, const int rowSize, const int colSize);
    static void clearPrevStartPoint(QTableWidget* table, const int rowSize, const int colSize);
    static void clearPrevFinishPoint(QTableWidget* table, const int rowSize, const int colSize);
};

#endif // UTILS_H
