/*
 * ui.cpp
 * ------
 * Console UI helper implementations:
 * dividers, headers, and user-input utilities.
 */

#include "ui.h"
#include <iostream>
#include <limits>
#include <string>
using namespace std;

// Clear a bad cin state and discard the rest of the line
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Pause execution until the user presses ENTER
void pressEnterToContinue() {
    cout << "\n  Press ENTER to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Print a divider row of `ch` repeated `width` times
void printDivider(char ch, int width) {
    cout << "  " << string(width, ch) << "\n";
}

// Print a section header framed by '=' dividers
void printHeader(const string& title) {
    cout << "\n";
    printDivider('=');
    cout << "  " << title << "\n";
    printDivider('=');
}
