#include "base.h"

// Function to print colored shape
void printColoredShape(const string& color, const string& shape) {
    // Print colored shape with ANSI escape code for color
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
    cout << " " << shape << ANSI_COLOR_RESET;
}

// Function to clear the console screen
void clearScreen() {
    system("cls");
}

// Function to set the cursor position
void setCursorPosition(int x, int y) {
    COORD coord = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
