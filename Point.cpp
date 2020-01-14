//
// Created by orit on 14/01/2020.
//

#include "Point.h"

Point::Point(int x_set, int y_set) {
    this->x = x_set;
    this->y = y_set;
}

int Point::get_x() {
    return this->x;
}

int Point::get_y() {
    return this->y;
}