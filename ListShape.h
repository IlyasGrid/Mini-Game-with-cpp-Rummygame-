#pragma once
#include "Shape.h"

class ListShape {
public:

	Shape* start;
	Shape* end;
	int shapeCount;


	ListShape() : start(nullptr), end(nullptr), shapeCount(0) {} // initialise all

	~ListShape() {
		Shape* current = start;
		while (current != nullptr) {
			Shape* temp = current;
			current = current->next;
			delete temp;
		}
	}

	bool isEmpty() const;

	void appendShapeAtStart(Shape* shape); // add the shape for the list , the color list and the shape list

	void appendShapeAtEnd(Shape* shape); // add the shape for the list , the color list and the shape list

	void appendShape(Shape* shape, char where); // add the shape for the list , the color list and the shape list

	void checkShapes(int* score);// if we have three shapes with same color or same shape :+3pts + remove all the shape from the lists ,if we got three shapes with same color and same shape :+10pts + remove all the shape from the lists  

	void removeShape(Shape* shape);

	void printList() const;

	void shiftList(); // it shift the shape with all its pointer




};
