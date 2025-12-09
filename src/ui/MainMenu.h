#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "Customer.h"
#include "ShoppingCart.h"
#include "Product.h"

using namespace std;


//   CUSTOMER MENU
   
class CustomerMenu {
private:
    vector<Customer>* customers;

public:
    CustomerMenu(vector<Customer>* customers);

    void showMenu();

private:
    int readInt(int min, int max);
    void addCustomer();
    void listCustomers();
};



 //  SHOPPING MENU
 
class ShoppingMenu {
private:
    vector<Customer>* customers;
    vector<Product>* products;

    Customer* activeCustomer;
    ShoppingCart* cart;

public:
    ShoppingMenu(vector<Customer>* customers,
        vector<Product>* products,
        Customer* activeCustomer,
        ShoppingCart* cart);

    void showMenu();

private:
    int readInt(int min, int max);

    void loginLogout();
    void productOperations();
    void cartOperations();
    void bonusPaymentMenu();
    void invoiceMenu();
};



//   MAIN MENU

class MainMenu {
private:
    vector<Customer>* customers;
    vector<Product>* products;
    Customer* activeCustomer;
    ShoppingCart* cart;

    CustomerMenu customerMenu;
    ShoppingMenu shoppingMenu;

public:
    MainMenu(vector<Customer>* customers,
        vector<Product>* products,
        Customer* activeCustomer,
        ShoppingCart* cart);

    void run();

private:
    void showMainMenu();
    int readInt(int min, int max);
};
