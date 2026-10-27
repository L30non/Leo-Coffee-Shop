/*
 * checkout.cpp
 * ------------
 * Handles the checkout flow: payment method selection,
 * cash handling, and itemised receipt printing.
 */

#include "checkout.h"
#include "cart.h"
#include "ui.h"
#include <iostream>
#include <iomanip>
using namespace std;

void checkout(vector<CartItem>& cart) {
    if (cart.empty()) {
        cout << "\n  Nothing in cart to checkout!\n";
        pressEnterToContinue();
        return;
    }

    displayCart(cart);

    // Calculate totals
    double subtotal = 0.0;
    for (const auto& c : cart) subtotal += c.subtotal();
    double tax   = subtotal * TAX_RATE;
    double total = subtotal + tax;

    // Select payment method
    cout << "\n  Payment Method:\n";
    cout << "    1. Cash\n";
    cout << "    2. Card (exact charge, no change)\n";
    cout << "    3. Mobile Pay (exact charge, no change)\n";
    cout << "  Choice: ";

    int payChoice;
    while (!(cin >> payChoice) || payChoice < 1 || payChoice > 3) {
        clearInput();
        cout << "  Enter 1, 2, or 3: ";
    }

    double paid   = 0.0;
    double change = 0.0;
    string method;

    if (payChoice == 1) {
        method = "Cash";
        cout << "\n  Amount due : $" << fixed << setprecision(2) << total << "\n";
        cout << "  Cash given : $";
        while (!(cin >> paid) || paid < total) {
            clearInput();
            cout << "  Must be >= $" << fixed << setprecision(2)
                 << total << ". Try again: $";
        }
        change = paid - total;
    } else {
        method = (payChoice == 2) ? "Card" : "Mobile Pay";
        paid   = total;
    }

    // ── Print receipt ──────────────────────────────────────────
    printHeader("*** LEO COFFEE SHOP — RECEIPT ***");
    cout << "  123 Cafe Street, Phnom Penh\n";
    cout << "  Tel: 012-345-678  |  @leocoffeeshop\n";
    printDivider();

    for (const auto& c : cart) {
        cout << "  " << left << setw(24) << c.item.name
             << " x" << setw(3) << c.quantity
             << right << "$" << fixed << setprecision(2)
             << setw(7) << c.subtotal() << "\n";
        if (!c.note.empty())
            cout << "    (" << c.note << ")\n";
    }

    printDivider();
    cout << right << setw(46) << "Subtotal : $" << setw(7) << subtotal << "\n";
    cout << right << setw(46) << "Tax 10%  : $" << setw(7) << tax      << "\n";
    printDivider();
    cout << right << setw(46) << "TOTAL    : $" << setw(7) << total    << "\n";
    cout << right << setw(46) << "Paid (" + method + "): $" << setw(7) << paid << "\n";
    if (payChoice == 1)
        cout << right << setw(46) << "Change   : $" << setw(7) << change << "\n";
    printDivider('=');
    cout << "\n     Thank you for visiting Leo Coffee Shop!\n";
    cout << "          Have a wonderful day ☕\n";
    printDivider('=');

    // Clear cart after successful payment
    cart.clear();
    cout << "\n  ✔ Order completed. Cart cleared.\n";
    pressEnterToContinue();
}
