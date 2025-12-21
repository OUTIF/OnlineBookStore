/*


STUDENT NAME: YOUSIF HUSSEIN JABBAR AL-GBURI
STUDENT NO  : 152120231144



*/



#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "Customer.h"
#include "ShoppingCart.h"
#include "Product.h"
#include "Payment.h"
#include "Cash.h"
#include "Check.h"
#include "CreditCard.h"

using namespace std;


    //Customer MENU
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


//Shopping MENU
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
   // void invoiceMenu();
};


// Main Menu
class MainMenu {
private:
    double total;
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
    void browseProducts();

private:
    void showMainMenu();
    int readInt(int min, int max);
};
