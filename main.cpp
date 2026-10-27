/*
 * ============================================================
 *   LEO COFFEE SHOP — Point of Sale (POS) System
 *   Course  : Computer Science I  (C++)
 *   Features: Menu display, cart, add/view/update/delete
 *             orders, payment with change, itemised receipt
 * ============================================================
 *
 *   File layout (Separation of Concerns):
 *     types.h / types (no .cpp) — Data structures
 *     ui.h / ui.cpp             — Console UI helpers
 *     menu.h / menu.cpp         — Menu catalog & display
 *     cart.h / cart.cpp          — Cart operations
 *     checkout.h / checkout.cpp — Payment & receipt
 *     main.cpp                  — Entry point & main loop
 */

#include "types.h"
#include "ui.h"
#include "menu.h"
#include "cart.h"
#include "checkout.h"
#include <iostream>
#include <vector>
using namespace std;

// ─── Main menu ────────────────────────────────────────────────

void printMainMenu() {
    printHeader("LEO COFFEE SHOP — POS");
    cout << "  1. View Menu\n";
    cout << "  2. Add Drink to Order\n";
    cout << "  3. View Current Order (Cart)\n";
    cout << "  4. Update Order Item\n";
    cout << "  5. Delete Order Item\n";
    cout << "  6. Checkout & Pay\n";
    cout << "  7. Exit\n";
    printDivider();
    cout << "  Enter choice: ";
}

// ─── Entry point ──────────────────────────────────────────────

int main() {
    vector<CartItem> cart;
    int choice;

    do {
        printMainMenu();

        while (!(cin >> choice)) {
            clearInput();
            cout << "  Invalid input. Enter a number 1-7: ";
        }

        switch (choice) {
            case 1:
                displayMenu();
                break;

            case 2:
                addToCart(cart);
                break;

            case 3:
                displayCart(cart);
                pressEnterToContinue();
                break;

            case 4:
                updateOrder(cart);
                break;

            case 5:
                deleteOrder(cart);
                break;

            case 6:
                checkout(cart);
                break;

            case 7:
                if (!cart.empty()) {
                    cout << "\n  ⚠ You have " << cart.size()
                         << " item(s) in your cart.\n";
                    cout << "  Exit anyway? (y/n): ";
                    char confirm;
                    cin >> confirm;
                    if (tolower(confirm) != 'y') {
                        choice = 0;  // don't exit
                        pressEnterToContinue();
                        break;
                    }
                }
                cout << "\n  Goodbye! Thanks for using Leo Coffee Shop POS.\n\n";
                break;

            default:
                cout << "\n  ✗ Please enter a number between 1 and 7.\n";
                pressEnterToContinue();
                break;
        }

    } while (choice != 7);

    return 0;
}
