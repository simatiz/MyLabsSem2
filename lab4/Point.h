#ifndef LAB_5_C___POINT_H
#define LAB_5_C___POINT_H
#include <cmath>

class Point {
    int x, y;
public:
    Point() = default;
    Point(int x, int y) { this->x = x; this->y = y; }
    int get_x() const { return x; }
    int get_y() const { return y; }
    friend double get_distance(Point, Point);
};
#endif