#include "TQuadrangle.h"

TQuadrangle::TQuadrangle(vector<int> coordinates) {
    point_1 = Point(coordinates[0], coordinates[1]);
    point_2 = Point(coordinates[2], coordinates[3]);
    point_3 = Point(coordinates[4], coordinates[5]);
    point_4 = Point(coordinates[6], coordinates[7]);
    side_1 = get_distance(point_1, point_2);
    side_2 = get_distance(point_2, point_3);
    side_3 = get_distance(point_3, point_4);
    side_4 = get_distance(point_1, point_4);
}