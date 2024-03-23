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
    Shape* nextShape;



    Shape(); // to generate random shape
    Shape(string shapeName,string shapeColor);

    ~Shape();

    void printShape() const; // should print the shape colored 
    

};
