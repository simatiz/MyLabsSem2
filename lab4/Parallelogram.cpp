#include "Parallelogram.h"

double Parallelogram::get_area() {
    auto vector_1 = Point(point_2.get_x() - point_1.get_x(), point_2.get_y() - point_1.get_y());
    auto vector_2 = Point(point_4.get_x() - point_1.get_x(), point_4.get_y() - point_1.get_y());
    return abs(vector_1.get_x() * vector_2.get_y() - vector_1.get_y() * vector_2.get_x());
}