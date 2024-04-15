# Restaurant Ordering System

## Submitted by - [Gursimran Singh (2310997089)](www.github.com/Gursimrxn) on [15 April 2024]

### Introduction

This program simulates an ordering system for a restaurant where customers can place orders for different items such as samosas, pizzas, burgers, and noodles.

### Description

The program consists of the following classes:

- **Restaurant**: Abstract base class representing a restaurant. It defines two pure virtual functions: `order()` and `price()`.
  
- **Samosa**: Derived class from `Restaurant`. Represents a samosa item. Implements `order()` and `price()` functions specific to samosas.

- **Pizza**: Derived class from `Restaurant`. Represents a pizza item. Implements `order()` and `price()` functions specific to pizzas.

- **Burger**: Derived class from `Restaurant`. Represents a burger item. Implements `order()` and `price()` functions specific to burgers.

- **Noodles**: Derived class from `Restaurant`. Represents a noodles item. Implements `order()` and `price()` functions specific to noodles.

- **Customer**: Represents a customer who can place orders. It takes a pointer to a `Restaurant` object during construction and provides a method `order()` to place orders.

### Usage

1. Clone the repository to your local machine.
   
2. Navigate to the project directory.
   
3. Compile the program using a C++ compiler.
   
4. Run the compiled executable.
   
5. The program will create a `Customer` object for ordering samosas and display the order and price. You can create additional `Customer` objects for ordering other items by uncommenting the relevant code in `main()`.

### Example