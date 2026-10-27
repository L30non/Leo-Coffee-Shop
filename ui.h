/*
 * ui.h
 * ----
 * Declaration of console UI helper functions:
 * dividers, headers, and user-input utilities.
 */

#ifndef UI_H
#define UI_H

#include <string>

void clearInput();
void pressEnterToContinue();
void printDivider(char ch = '-', int width = 60);
void printHeader(const std::string& title);

#endif // UI_H
