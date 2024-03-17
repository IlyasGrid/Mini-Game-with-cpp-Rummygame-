#pragma once
#include <iostream>
#include <fcntl.h>
#include <io.h>
#include <string>
#include <conio.h>
#include <Windows.h> // For Sleep function
#include <vector>

using namespace std;

// Define ANSI escape codes for colors
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_RESET   "\x1b[0m"

// Define Unicode characters for shapes
#define TRIANGLE L"\u25b2"
#define CIRCLE  L"\u25cf"
#define LOSANGE  L"\u2666"
#define SQUARE  L"\u25a0"

enum class Color {
    RED,
    GREEN,
    BLUE,
    YELLOW,
    DEFAULT
};

// Function to print colored shape
void printColoredShape(const string& color, const wstring& shape);

// Function to clear the console screen
void clearScreen();

// Function to set the cursor position
void setCursorPosition(int x, int y);

