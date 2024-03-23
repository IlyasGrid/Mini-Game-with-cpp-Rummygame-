#include "Shape.h"
#include "base.h"


Shape::Shape() {
	int randomcolor = rand() % 4; // 0 to 3 for colors

	int randomshape = rand() % 4; // 0 to 3 for shapes

	switch (randomcolor)
	{
	case 0:
		color = "red";
		break;
	case 1:
		color = "yellow";
		break;
	case 2:
		color = "blue";
		break;
	case 3:
		color = "green";
		break;

	default:
		break;
	}

	switch (randomshape)
	{
	case 0:
		name = "TRIANGLE";
		break;
	case 1:
		name = "LOSANGE";
		break;
	case 2:
		name = "CIRCLE";
		break;
	case 3:
		name = "SQUARE";
		break;

	default:
		break;
	}

	this->next = nullptr;
	this->previous = nullptr;

	this->nextColor = nullptr;
	this->nextShape = nullptr;

}

Shape::Shape(string shapeName, string shapeColor) {


	this->name = shapeName;
	this->color = shapeColor;

	this->next = nullptr;
	this->previous = nullptr;

	this->nextColor = nullptr;
	this->nextShape = nullptr;

}

Shape::~Shape() {};

void Shape::printShape() const {

	if (color == "red")
		cout << ANSI_COLOR_RED;
	else if (color == "green")
		cout << ANSI_COLOR_GREEN;
	else if (color == "blue")
		cout << ANSI_COLOR_BLUE;
	else if (color == "yellow")
		cout << ANSI_COLOR_YELLOW;
	else
		cout << ANSI_COLOR_RESET; // Default color

	// Print the shape
	cout << " " << name << ANSI_COLOR_RESET ;
}
