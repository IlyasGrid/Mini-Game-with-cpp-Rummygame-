#include <iostream>
#include "ListShape.h"

using namespace std;



// Function to display game interface
void displayGameInterface(int *score,bool *isShift, Shape* nextShape, Shape* currentShape, ListShape& shapeList) {
    char userchoice;

    clearScreen();

    setCursorPosition(2, 2);
    cout << "Command:  "<<endl;
    cout << "           left arrow : insert in the start " << endl;
    cout << "           right arrow : insert in the end " << endl;
    cout << "           up arrow : to choose the wanted color for shift " << endl;
    cout << "           down arrow : to choose the wanted shape for shift " << endl;


    setCursorPosition(30, 5);
    cout << "Score: " << *score;


    setCursorPosition(50, 10);
    cout << "Next Shape:  ??????";
    //nextShape->printShape();

    setCursorPosition(2, 10);
    cout << "Current Shape: ";
    currentShape->printShape();

    // Display list of shapes
    setCursorPosition(2, 15);
    cout << "Shape List: (" << shapeList.shapeCount << ") " << endl;
    setCursorPosition(2, 17);

    shapeList.printListShape();

    // Prompt the user to choose the position
    setCursorPosition(2, 20);
    userchoice = _getch();

    if (userchoice == 's' || userchoice == 'S')
    {
        *isShift = true;
        shapeList.shift();
    }

    else if (userchoice == 'a' || userchoice == 'A')
    {
        shapeList.start->printShapeWithSameColor();
    }

    else if (userchoice == 'r' || userchoice == 'R' || userchoice == 'l' || userchoice == 'L')
        shapeList.appendShape(currentShape, userchoice);
    shapeList.checkShapes(score);

}


int main() {
    srand(static_cast<unsigned int>(time(0)));
    ListShape shapeList;
    int score = 0000;
    bool isShift = false;

    // Create the next shape
    Shape* nextShape = nullptr;
    Shape* currentShape = new Shape();

    while (shapeList.shapeCount < 15) {
       

        displayGameInterface(&score , &isShift,nextShape, currentShape, shapeList);

        //nextShape = currentShape;
        if(!isShift)
            currentShape = new Shape();


    }

    shapeList.printListShape();

    return 0;
}
