# Inventory Management System

This is an Inventory Management System built in C++ to manage products, handle customer orders, and perform employee functions such as adding/editing products and displaying inventory.

## Features

- **Employee Menu**:
  - Add new products to the inventory.
  - Edit existing products (name, price, quantity).
  - Display inventory categorized by product types (Electronics, Clothing, Food, Furniture, Sports, Stationary).

- **Customer Menu**:
  - Display inventory categorized by product types.
  - Buy products from the inventory (adjust quantity accordingly).
  
- **Debit Card Information**:
  - A feature to collect debit card information for payment processing (though not connected to a payment gateway in this system).

## Code Structure

- **Enums**: Defines product categories (Electronics, Clothing, Food, Furniture, Sports, Stationary).
- **Structures**:
  - `Product`: Represents a product with attributes like `id`, `name`, `price`, `quantity`, and `category`.
  - `DebitCardInfo`: Holds debit card information (card number, expiry date, CVV).
- **Classes**:
  - `Inventory`: Manages product information and inventory actions (add, edit, buy, display).
- **Functions**:
  - Functions for getting debit card information from the customer.
  - Menus for both employees and customers.
