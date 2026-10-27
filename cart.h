/*
 * cart.h
 * ------
 * Declarations for shopping cart operations:
 * add, update, delete, view.
 */

#ifndef CART_H
#define CART_H

#include "types.h"
#include <vector>

const double TAX_RATE = 0.10; // 10% VAT

int findCartIndex(const std::vector<CartItem>& cart, int menuId);
void displayCart(const std::vector<CartItem>& cart);
void addToCart(std::vector<CartItem>& cart);
void updateOrder(std::vector<CartItem>& cart);
void deleteOrder(std::vector<CartItem>& cart);

#endif // CART_H
