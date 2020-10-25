#pragma once
#include<cmath>

float point_distance(float x1, float y1, float x2, float y2);

float point_direction(float x1, float y1, float x2, float y2);

float lengthdir_x(float length, float angle);

float lengthdir_y(float length, float angle);

bool isBoxCollision(float x1, float y1, float r1, float x2, float y2, float r2);