#pragma once
#include "Shape.h"

class ListShape {
public:
    
    Shape* start;
    Shape* end;
    int shapeCount;


    ListShape() : start(nullptr), end(nullptr), shapeCount(0){}

    ~ListShape() {
        Shape* current = start;
        while (current != nullptr) {
            Shape* temp = current;
            current = current->next;
            delete temp;
        }
    }

    bool isEmpty();

    void appendShape(Shape* shape, char where);

    int checkShapes(int* score) ;

    void removeShape(Shape* shapeToRemove);

    void printListShape() const;

    void shift();

    
    
};
