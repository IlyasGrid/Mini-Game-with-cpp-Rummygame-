#include <iostream>
#include "ListShape.h"

using namespace std;

void chooseColorForShift(ListShape& shapeList) {
	cout << "	choose : \n		1-red\n		2-blue\n		3-green\n		4-yellow" << endl;
	Sleep(1000);
	char choise = getchar();
	switch (choise)
	{
	case '1':

		shapeList.shiftColor("red");
		break;
	case '2':
		shapeList.shiftColor("blue");
		break;
	case '3':
		shapeList.shiftColor("green");
		break;
	case '4':
		shapeList.shiftColor("yellow");
		break;
	default:
		chooseColorForShift(shapeList);
		break;
	}
}


void chooseNameForShift(ListShape& shapeList) {
	cout << "	choose : \n		1-SQUARE\n		2-TRIANGLE\n		3-CIRCLE\n		4-LOSANGE" << endl;
	Sleep(1000);
	char choise = getchar();
	switch (choise)
	{
	case '1':
		shapeList.shiftShapes("SQUARE");
		break;
	case '2':
		shapeList.shiftShapes("TRIANGLE");
		break;
	case '3':
		shapeList.shiftShapes("CIRCLE");
		break;
	case '4':
		shapeList.shiftShapes("LOSANGE");
		break;
	default:
		chooseNameForShift(shapeList);
		break;
	}
}


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

		chooseColorForShift(shapeList);
		newShapeNeeded = false;
		break;
	case 'w':
		chooseNameForShift(shapeList);
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

