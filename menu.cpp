/*
 * menu.cpp
 * --------
 * Menu catalog items and display functions.
 */

#include "menu.h"
#include "ui.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Static catalog of all drinks/beverages
static const vector<MenuItem> MENU_ITEMS = {
    // Hot Coffee
    { 1, "Espresso",          "Hot Coffee",  2.50 },
    { 2, "Americano",         "Hot Coffee",  3.00 },
    { 3, "Cappuccino",        "Hot Coffee",  3.50 },
    { 4, "Cafe Latte",        "Hot Coffee",  3.75 },
    { 5, "Flat White",        "Hot Coffee",  3.75 },
    // Cold Coffee
    { 6, "Iced Americano",    "Cold Coffee", 3.50 },
    { 7, "Iced Latte",        "Cold Coffee", 4.00 },
    { 8, "Cold Brew",         "Cold Coffee", 4.50 },
    { 9, "Iced Mocha",        "Cold Coffee", 4.25 },
    // Tea
    {10, "Green Tea",         "Tea",         2.50 },
    {11, "Chamomile Tea",     "Tea",         2.50 },
    {12, "Iced Milk Tea",     "Tea",         3.25 },
    // Blended
    {13, "Mocha Frappuccino", "Blended",     5.00 },
    {14, "Caramel Blended",   "Blended",     5.00 },
    {15, "Matcha Frappuccino","Blended",     5.25 },
    // Non-Coffee
    {16, "Hot Chocolate",     "Non-Coffee",  3.50 },
    {17, "Strawberry Smoothie","Non-Coffee", 4.50 },
    {18, "Mango Smoothie",    "Non-Coffee",  4.50 },
    {19, "Fresh Orange Juice","Non-Coffee",  3.75 },
    {20, "Sparkling Water",   "Non-Coffee",  2.00 },
};

const vector<MenuItem>& getMenu() {
    return MENU_ITEMS;
}

const MenuItem* findMenuItem(int id) {
    for (const auto& m : MENU_ITEMS) {
        if (m.id == id) return &m;
    }
    return nullptr;
}

void displayMenu() {
    printHeader("LEO COFFEE SHOP — MENU");

    string currentCat = "";
    cout << "  " << left
         << setw(5)  << "ID"
         << setw(24) << "Drink"
         << setw(16) << "Category"
         << right << setw(8) << "Price"
         << "\n";
    printDivider('-');

    for (const auto& m : MENU_ITEMS) {
        if (m.category != currentCat) {
            currentCat = m.category;
            cout << "\n  ▸ " << currentCat << "\n";
        }
        cout << "  " << left
             << setw(5)  << m.id
             << setw(24) << m.name
             << setw(16) << m.category
             << right << "$" << fixed << setprecision(2)
             << setw(7)  << m.price << "\n";
    }
    printDivider('-');

}
