# Leo Coffee Shop — Point of Sale System

A console-based POS system for a coffee shop, written in C++ for Computer Science I coursework.

## Features

- Menu display with categorized drinks (Hot Coffee, Cold Coffee, Tea, Blended, Non-Coffee)
- Shopping cart operations (add, view, update, delete)
- Payment methods: Cash (with change calculation), Card, Mobile Pay
- Itemized receipt printing
- 10% VAT calculation
- Special notes for each order item (e.g., "less sugar", "no ice")

## Project Structure (Separation of Concerns)

Each file has a single, well-defined responsibility:

```
Leo-Coffee-Shop/
├── types.h              # Data structures (MenuItem, CartItem)
├── ui.h / ui.cpp        # Console UI helpers (dividers, headers, input)
├── menu.h / menu.cpp    # Menu catalog & display functions
├── cart.h / cart.cpp    # Cart operations (add/update/delete/view)
├── checkout.h / checkout.cpp  # Payment & receipt generation
├── main.cpp             # Entry point & main menu loop
└── Makefile             # Build automation
```

### Responsibilities

| File | Responsibility |
|------|----------------|
| `types.h` | Pure data structures with no logic |
| `ui.*` | Console formatting and user input utilities |
| `menu.*` | Menu items catalog and display |
| `cart.*` | Shopping cart state management |
| `checkout.*` | Payment processing and receipt printing |
| `main.cpp` | Program flow and main menu loop |

## Building & Running

### Using Make (recommended)

```bash
make        # Build the project
./main      # Run the program
make clean  # Remove compiled files
```

### Manual Compilation

```bash
g++ -std=c++17 -Wall -Wextra -o main main.cpp ui.cpp menu.cpp cart.cpp checkout.cpp
./main
```

## Usage

1. **View Menu** — Display all available drinks with prices
2. **Add Drink to Order** — Add items to cart with quantity and special notes
3. **View Current Order** — See cart contents with subtotal, tax, and total
4. **Update Order Item** — Change quantity or notes for an existing cart item
5. **Delete Order Item** — Remove an item from the cart
6. **Checkout & Pay** — Complete the order with payment and print receipt
7. **Exit** — Close the application (warns if cart is not empty)

## Payment Methods

- **Cash** — Enter amount given; system calculates change
- **Card** — Exact charge, no change returned
- **Mobile Pay** — Exact charge, no change returned

## Tax Information

- Tax rate: 10% VAT applied to subtotal
- Displayed separately on cart view and receipt

## Design Principles

This project follows **Separation of Concerns**:
- Each module handles one aspect of the system
- Changes to UI don't affect business logic
- Menu items can be updated without touching cart code
- Clear dependencies between modules (types → ui → menu → cart → checkout → main)

---

**Course**: Computer Science I (C++)  
**Institution**: American University of Phnom Penh
