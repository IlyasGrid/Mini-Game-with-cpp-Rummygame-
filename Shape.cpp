#include "Shape.h"
#include "base.h"


Shape::Shape (){
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
    this->previousColor =  nullptr;
     
    this->nextshape = nullptr;
    this->previousshape = nullptr;

    }

Shape::~Shape() {};

void Shape::printShape() const{

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
    cout << " " << name << ANSI_COLOR_RESET;
}

void Shape::printShapeWithSameColor() {
    Shape* current = this;

    while (current != nullptr) {
        current->printShape();
        current = current->nextColor;
    }
}

void Shape::printShapeWithSameShape() {

    Shape* current = this;

    while (current != nullptr) {
        current->printShape();
        current = current->nextshape;
    }
}

void Shape::swapShapes(Shape* other) {

    // Swap colors
    std::swap(this->color, other->color);

    // Swap names
    std::swap(this->name, other->name);

    // Update pointers for the doubly linked list
    if (this->previous != nullptr) {
        this->previous->next = other;
    }
    if (other->previous != nullptr) {
        other->previous->next = this;
    }
    if (this->next != nullptr) {
        this->next->previous = other;
    }
    if (other->next != nullptr) {
        other->next->previous = this;
    }
    std::swap(this->previous, other->previous);
    std::swap(this->next, other->next);

    // Update pointers for the color-linked list
    if (this->previousColor != nullptr) {
        this->previousColor->nextColor = other;
    }
    if (other->previousColor != nullptr) {
        other->previousColor->nextColor = this;
    }
    if (this->nextColor != nullptr) {
        this->nextColor->previousColor = other;
    }
    if (other->nextColor != nullptr) {
        other->nextColor->previousColor = this;
    }
    std::swap(this->previousColor, other->previousColor);
    std::swap(this->nextColor, other->nextColor);

    // Update pointers for the shape-linked list
    if (this->previousshape != nullptr) {
        this->previousshape->nextshape = other;
    }
    if (other->previousshape != nullptr) {
        other->previousshape->nextshape = this;
    }
    if (this->nextshape != nullptr) {
        this->nextshape->previousshape = other;
    }
    if (other->nextshape != nullptr) {
        other->nextshape->previousshape = this;
    }
    std::swap(this->previousshape, other->previousshape);
    std::swap(this->nextshape, other->nextshape);
}
