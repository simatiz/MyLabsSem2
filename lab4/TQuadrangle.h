#ifndef LAB_5_C___TQUADRANGLE_H
#define LAB_5_C___TQUADRANGLE_H
#include "Point.h"
#include <vector>
using namespace std;

class TQuadrangle {
protected:
    Point point_1, point_2, point_3, point_4;
    double side_1, side_2, side_3, side_4;
public:
    explicit TQuadrangle(vector <int>);
    virtual double get_perimeter() = 0;
    virtual double get_area() = 0;
};
#endif