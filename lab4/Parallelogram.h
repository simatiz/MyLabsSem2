#ifndef LAB_5_C___PARALLELOGRAM_H
#define LAB_5_C___PARALLELOGRAM_H
#include "TQuadrangle.h"

class Parallelogram : public TQuadrangle {
public:
    explicit Parallelogram(vector <int> coordinates) : TQuadrangle(coordinates) {}
    double get_perimeter() override { return 2 * (side_1 + side_2); }
    double get_area() override;
};
#endif