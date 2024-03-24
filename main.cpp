#include <iostream>
#include "ListShape.h"

using namespace std;

// Function to display game interface
static void displayGameInterface(int& score, bool& newShapeNeeded, Shape*& nextShape, Shape*& currentShape, ListShape& shapeList) {

	int userChoice;

	clearScreen();

	setCursorPosition(2, 2);
	cout << "Command:  " << endl;
	cout << "           a : insert in the start " << endl;
	cout << "           d : insert in the end " << endl;
	cout << "           w : to choose the wanted color shift " << endl;
	cout << "           s : to choose the wanted shape shift " << endl;

	setCursorPosition(2, 9);
	cout << "---------   Score: " << score << "    -------------";

	setCursorPosition(50, 10);
	cout << "Next Shape:  ";
	if (nextShape != nullptr)
		nextShape->printShape();

	setCursorPosition(2, 10);
	cout << "Current Shape: ";
	if (currentShape != nullptr)
		currentShape->printShape();

	// Display list of shapes
	setCursorPosition(2, 15);
	cout << "Shape List: (" << shapeList.shapeCount << ") " << endl;
	setCursorPosition(2, 17);
	shapeList.printList();

	// Prompt the user to choose the position
	setCursorPosition(2, 20);
	userChoice = _getch();
	userChoice = tolower(userChoice);

	switch (userChoice) {

	case 'a':
		shapeList.appendShape(currentShape, 's');
		newShapeNeeded = true;
		break;
	case 'd':
		shapeList.appendShape(currentShape, 'e');
		newShapeNeeded = true;
		break;
	case 's':
		shapeList.shiftColor("red");
		newShapeNeeded = false;
		break;
	case 'w':
		shapeList.shiftShapes("SQUARE");
		newShapeNeeded = false;
		break;
	default:
			newShapeNeeded = false;
			break;
	}



	shapeList.checkShapes(&score);

	if (newShapeNeeded) {
		currentShape = nextShape;
		nextShape = new Shape();
	}
}

int main() {
	srand(static_cast<unsigned int>(time(0)));
	ListShape shapeList;
	int score = 0;
	bool newShapeNeeded = true;


	// Create the next shape
	Shape* nextShape = new Shape();
	Shape* currentShape = new Shape();

	while (shapeList.shapeCount < 15) {
		displayGameInterface(score, newShapeNeeded, nextShape, currentShape, shapeList);
	}

	shapeList.printList();

	// Clean up dynamically allocated memory
	delete currentShape;
	delete nextShape;

	return 0;
}

