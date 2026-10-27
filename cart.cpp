/*
 * cart.cpp
 * --------
 * Shopping cart operations: add, update, delete, and display.
 */

#include "cart.h"
#include "menu.h"
#include "ui.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Return the cart index for menu item `menuId`, or -1 if absent
int findCartIndex(const vector<CartItem>& cart, int menuId) {
    for (int i = 0; i < (int)cart.size(); i++) {
        if (cart[i].item.id == menuId) return i;
    }
    return -1;
}

void displayCart(const vector<CartItem>& cart) {
    if (cart.empty()) {
        cout << "\n  Your cart is empty.\n";
        return;
    }

    printHeader("YOUR CURRENT ORDER");
    cout << "  " << left
         << setw(5)  << "#"
         << setw(24) << "Drink"
         << setw(8)  << "Qty"
         << setw(10) << "Unit $"
         << right << setw(9) << "Subtotal"
         << "\n";
    printDivider();

    double orderTotal = 0.0;
    for (int i = 0; i < (int)cart.size(); i++) {
        const CartItem& c = cart[i];
        double sub = c.subtotal();
        orderTotal += sub;

        cout << "  " << left
             << setw(5)  << (i + 1)
             << setw(24) << c.item.name
             << setw(8)  << c.quantity
             << "$" << fixed << setprecision(2) << setw(9) << c.item.price
             << right << "$" << setw(8) << sub << "\n";

        if (!c.note.empty())
            cout << "         Note: " << c.note << "\n";
    }

    double tax   = orderTotal * TAX_RATE;
    double grand = orderTotal + tax;

    printDivider();
    cout << right << setw(56) << "Subtotal : $"
         << fixed << setprecision(2) << setw(7) << orderTotal << "\n";
    cout << right << setw(56) << "Tax (10%): $"
         << setw(7) << tax << "\n";
    printDivider();
    cout << right << setw(56) << "TOTAL    : $"
         << setw(7) << grand << "\n";
    printDivider('=');
}

void addToCart(vector<CartItem>& cart) {
    displayMenu();

    int id;
    cout << "\n  Enter drink ID to add (0 to cancel): ";
    while (!(cin >> id)) {
        clearInput();
        cout << "  Invalid input. Enter a number: ";
    }
    if (id == 0) return;

    const MenuItem* m = findMenuItem(id);
    if (!m) {
        cout << "\n  ✗ Drink ID " << id << " not found on menu.\n";
        pressEnterToContinue();
        return;
    }

    int qty;
    cout << "  Quantity: ";
    while (!(cin >> qty) || qty < 1) {
        clearInput();
        cout << "  Enter a positive number: ";
    }
    clearInput();

    cout << "  Special note (e.g. 'less sugar', leave blank for none): ";
    string note;
    getline(cin, note);

    // If item already in cart, increase quantity; otherwise append
    int idx = findCartIndex(cart, id);
    if (idx != -1) {
        cart[idx].quantity += qty;
        if (!note.empty()) cart[idx].note = note;
        cout << "\n  ✔ Updated: " << m->name
             << " x" << cart[idx].quantity << " in cart.\n";
    } else {
        cart.push_back({ *m, qty, note });
        cout << "\n  ✔ Added: " << m->name << " x" << qty << " to cart.\n";
    }
    pressEnterToContinue();
}

void updateOrder(vector<CartItem>& cart) {
    if (cart.empty()) {
        cout << "\n  Cart is empty, nothing to update.\n";
        pressEnterToContinue();
        return;
    }

    displayCart(cart);

    int lineNo;
    cout << "\n  Enter the line # to update (0 to cancel): ";
    while (!(cin >> lineNo)) {
        clearInput();
        cout << "  Enter a number: ";
    }
    if (lineNo == 0) return;
    if (lineNo < 1 || lineNo > (int)cart.size()) {
        cout << "\n  ✗ Invalid line number.\n";
        pressEnterToContinue();
        return;
    }

    CartItem& c = cart[lineNo - 1];
    cout << "\n  Updating: " << c.item.name << "\n";

    int qty;
    cout << "  New quantity (current: " << c.quantity << "): ";
    while (!(cin >> qty) || qty < 1) {
        clearInput();
        cout << "  Enter a positive number: ";
    }
    clearInput();

    cout << "  New note (current: \""
         << (c.note.empty() ? "none" : c.note)
         << "\", leave blank to keep): ";
    string note;
    getline(cin, note);

    c.quantity = qty;
    if (!note.empty()) c.note = note;

    cout << "\n  ✔ Order updated.\n";
    pressEnterToContinue();
}

void deleteOrder(vector<CartItem>& cart) {
    if (cart.empty()) {
        cout << "\n  Cart is empty, nothing to delete.\n";
        pressEnterToContinue();
        return;
    }

    displayCart(cart);

    int lineNo;
    cout << "\n  Enter the line # to remove (0 to cancel): ";
    while (!(cin >> lineNo)) {
        clearInput();
        cout << "  Enter a number: ";
    }
    if (lineNo == 0) return;
    if (lineNo < 1 || lineNo > (int)cart.size()) {
        cout << "\n  ✗ Invalid line number.\n";
        pressEnterToContinue();
        return;
    }

    string removedName = cart[lineNo - 1].item.name;
    cart.erase(cart.begin() + (lineNo - 1));
    cout << "\n  ✔ Removed \"" << removedName << "\" from your order.\n";
    pressEnterToContinue();
}
