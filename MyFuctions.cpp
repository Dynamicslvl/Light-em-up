#include "MyFunctions.h"
#include <cmath>

float point_distance(float x1, float y1, float x2, float y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

float point_direction(float x1, float y1, float x2, float y2) {
    if (x1 == x2 && y1 == y2) {
        return 0;
    }
    else {
        float top = x2 - x1;
        float down = point_distance(x1, y1, x2, y2);
        float sign = 1.0;
        float rad_angle = (float)acos(top / down);
        if (y2 > y1) sign = -1.0;
        return sign * rad_angle;
    }
}

float lengthdir_x(float length, float angle) {
    return length * cos(angle);
}

float lengthdir_y(float length, float angle) {
    return length * sin(angle);
}

bool isBoxCollision(float x1, float y1, float r1, float x2, float y2, float r2) {
    if (abs(x1 - x2) < r1 + r2 && abs(y1 - y2) < r1 + r2) {
        return 1;
    }
    return 0;
}