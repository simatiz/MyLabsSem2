#include "Point.h"

double get_distance(Point point_1, Point point_2) {
    return sqrt(pow(point_2.x - point_1.x, 2) + pow(point_2.y - point_1.y, 2));
}