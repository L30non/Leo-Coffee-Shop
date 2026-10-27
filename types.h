/*
 * types.h
 * -------
 * Shared data structures for the Leo Coffee Shop POS system.
 * No logic lives here — pure data definitions only.
 */

#ifndef TYPES_H
#define TYPES_H

#include <string>

// ─── Menu item as it appears on the board ─────────────────────
struct MenuItem {
    int    id;
    std::string name;
    std::string category;
    double price;       // USD
};

// ─── A line inside the customer's cart ────────────────────────
struct CartItem {
    MenuItem    item;
    int         quantity;
    std::string note;      // e.g. "less sugar", "no ice"

    double subtotal() const { return item.price * quantity; }
};

#endif // TYPES_H
