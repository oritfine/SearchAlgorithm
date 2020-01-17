//
// Created by orit on 14/01/2020.
//

#ifndef EX4_POINT_H
#define EX4_POINT_H

#include <string>
using namespace std;
class Point {
int x;
int y;
public:
    Point(int x_set, int y_set);
    int get_x();
    int get_y();
    bool operator==(const Point& p);
    bool operator!=(const Point& p);
    string to_string();
};


#endif //EX4_POINT_H
