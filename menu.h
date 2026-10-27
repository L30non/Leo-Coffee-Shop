/*
 * menu.h
 * ------
 * Declarations for menu items data and query functions.
 */

#ifndef MENU_H
#define MENU_H

#include "types.h"
#include <vector>

// Full drink/beverage catalog
const std::vector<MenuItem>& getMenu();

// Lookup functions
const MenuItem* findMenuItem(int id);
void displayMenu();

#endif // MENU_H
