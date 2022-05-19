#ifndef LAB_5_C___RECTANGLE_H
#define LAB_5_C___RECTANGLE_H
#include "Parallelogram.h"

class Rectangle : public Parallelogram {
public:
    explicit Rectangle(vector <int> coordinates) : Parallelogram(coordinates) {}
    double get_area() override { return side_1 * side_2; }
};
#endif