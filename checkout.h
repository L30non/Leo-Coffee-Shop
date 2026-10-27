/*
 * checkout.h
 * ----------
 * Declaration for the checkout / payment / receipt flow.
 */

#ifndef CHECKOUT_H
#define CHECKOUT_H

#include "types.h"
#include <vector>

void checkout(std::vector<CartItem>& cart);

#endif // CHECKOUT_H
