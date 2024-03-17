#pragma once
#include "base.h"
#include <ctime>
#include <random>

class Shape {
public:
    string color;
    string name;
    Shape* next;
    Shape* previous;
    Shape* nextColor;
    Shape* previousColor;
    Shape* nextshape;
    Shape* previousshape;


    Shape(); // to generate random shape

    ~Shape();

    void printShape() const;
    void printShapeWithSameColor();
    void printShapeWithSameShape();

    void swapShapes(Shape* other);
};
