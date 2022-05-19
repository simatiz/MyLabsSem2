#ifndef LAB_5_C___SQUARE_H
#define LAB_5_C___SQUARE_H
#include "Rectangle.h"

class Square : public Rectangle {
public:
    explicit Square(vector <int> coordinates) : Rectangle(coordinates) {};
    double get_perimeter() override { return 4 * side_1; }
    double get_area() override { return pow(side_1, 2); }
};
#endif