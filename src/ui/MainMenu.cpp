#include "MainMenu.h"

/* ============================================================
   CUSTOMER MENU IMPLEMENTATION
   ============================================================ */
CustomerMenu::CustomerMenu(vector<Customer>* customers)
    : customers(customers) {
}

void CustomerMenu::showMenu() {
    bool back = false;

    while (!back) {
        cout << "\n--- CUSTOMER MENU ---\n"
            << "1. Add Customer\n"
            << "2. List Customers\n"
            << "3. Back\n"
            << "Choose: ";

        int choice = readInt(1, 3);

        switch (choice) {
        case 1: addCustomer(); break;
        case 2: listCustomers(); break;
        case 3: back = true; break;
        }
    }
}

int CustomerMenu::readInt(int min, int max) {
    int x;
    while (true) {
        if (cin >> x && x >= min && x <= max) return x;
        cin.clear();
        cin.ignore(9999, '\n');
        cout << "Enter valid number: ";
    }
}

void CustomerMenu::addCustomer() {
    Customer c;
    string s;

    do {
        cout << "Name: ";
        getline(cin, s);

        // Remove leading/trailing spaces to check if input is valid
        string trimmed = s;
        trimmed.erase(0, trimmed.find_first_not_of(" \t\n\r"));
        trimmed.erase(trimmed.find_last_not_of(" \t\n\r") + 1);

        if (!trimmed.empty()) {
            c.setName(s);
            break;
        }

        cout << "Name cannot be empty or just spaces. Please try again.\n";

    } while (true);

    cout << "Address: ";
    getline(cin, s);
    c.setAddress(s);

    cout << "Phone: ";
    getline(cin, s);
    c.setPhone(s);



    do {
        cout << "Email: ";
        getline(cin, s);

        // Remove leading/trailing spaces to check if input is valid
        string trimmed = s;
        trimmed.erase(0, trimmed.find_first_not_of(" \t\n\r"));
        trimmed.erase(trimmed.find_last_not_of(" \t\n\r") + 1);

        if (!trimmed.empty()) {
            c.setEmail(s);
            break;
        }

        cout << "Email cannot be empty or just spaces. Please try again.\n";

    } while (true);


    do {
        cout << "Username: ";
        getline(cin, s);

        // Remove leading/trailing spaces to check if input is valid
        string trimmed = s;
        trimmed.erase(0, trimmed.find_first_not_of(" \t\n\r"));
        trimmed.erase(trimmed.find_last_not_of(" \t\n\r") + 1);

        if (!trimmed.empty()) {
            c.setUsername(s);
            break;
        }

        cout << "Username cannot be empty or just spaces. Please try again.\n";

    } while (true);

    do {
        cout << "Password: ";
        getline(cin, s);

        // Remove leading/trailing spaces to check if input is valid
        string trimmed = s;
        trimmed.erase(0, trimmed.find_first_not_of(" \t\n\r"));
        trimmed.erase(trimmed.find_last_not_of(" \t\n\r") + 1);

        if (!trimmed.empty()) {
            c.setPassword(s);
            break;
        }

        cout << "Password cannot be empty or just spaces. Please try again.\n";

    } while (true);



    c.setCustomerID(customers->size() + 1);
    c.setBonus(0);

    customers->push_back(c);

    cout << "Customer has been  added .\n";
}

void CustomerMenu::listCustomers() {
    cout << "\n--- CUSTOMER LIST ---\n";

    for (auto& c : *customers) {
        cout << "ID: " << c.getCustomerID()
            << " | Name: " << c.getName()
            << " | Username: " << c.getUsername()
            << " | Bonus: " << c.getBonus() << "\n";
    }
}

/* ============================================================
   SHOPPING MENU IMPLEMENTATION
   ============================================================ */
ShoppingMenu::ShoppingMenu(std::vector<Customer>* customers,
    vector<Product>* products,
    Customer* activeCustomer,
    ShoppingCart* cart)
    : customers(customers),
    products(products),
    activeCustomer(activeCustomer),
    cart(cart) {
}

void ShoppingMenu::showMenu() {
    bool back = false;

    while (!back) {
        cout << "\n=== SHOPPING MENU ===\n"
            << "1. Login / Logout\n"
            << "2. Product Operations\n"
            << "3. Cart\n"
            << "4. Bonus & Payment\n"
            << "5. Invoice\n"
            << "6. Back\n"
            << "Choose: ";

        int choice = readInt(1, 6);

        switch (choice) {
        case 1: loginLogout(); break;
        case 2: productOperations(); break;
        case 3: cartOperations(); break;
        case 4: bonusPaymentMenu(); break;
        case 5: invoiceMenu(); break;
        case 6: back = true; break;
        }
    }
}

int ShoppingMenu::readInt(int min, int max) {
    int x;
    while (true) {
        if (cin >> x && x >= min && x <= max) return x;
        cin.clear();
        cin.ignore(9999, '\n');
        cout << "Enter valid number: ";
    }
}

void ShoppingMenu::loginLogout() {
    if (this->activeCustomer != nullptr) {
        // Logout
        this->activeCustomer = nullptr;
        cout << "\n------>>Logged out successfully<<------\n";

        // Clean up the cart
        if (this->cart != nullptr) {
            delete this->cart;
            this->cart = nullptr;
        }
    }
    else { 
        cout << "\n------>>Login<<------\n";
        string user;
        string pass;
        cout << "UserName:";
        cin >> user;
        cout << "Password:";
        cin >> pass;

        for (auto& c : *this->customers) {
            if (user == c.getUsername() && pass == c.getPassword()) {
                this->activeCustomer = &c;
                cout << "Welcom '" << user <<"' You have Loged in successfully\n" << endl;
                this->cart = new ShoppingCart(nullptr, this->activeCustomer);
                return;  
            }   
            
        }
        if (this->activeCustomer == nullptr) { cout << "No such a user or your password or username is wrong!\n"; }
    }

}

void ShoppingMenu::productOperations() {
    if (this->activeCustomer == nullptr) {
        cout << "You are not logged in. Please login first.\n";
        return;
    }

    cout << "\n--- PRODUCTS ---\n";
    for (auto& item : *this->products) {
        cout << endl;
        item.printProperties();
        cout << endl;
    }

    cout << "Enter product ID to add to cart (or -1 to go back):\n";

    while (true) {
        cout << "ID of product: ";
        int p;
        cin >> p;

        if (p == -1) {
            cout << "Returning to menu...\n";
            break;  // Exit the loop
        }

        bool found = false;
        for (auto& item : *this->products) {
            if (p == item.getID()) {
                cout << item.getName() << " has been added to the cart\n";
                this->cart->addProduct(&item);
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Invalid ID. Please try again.\n";
        }
    }
}

void ShoppingMenu::cartOperations() {
    cout << "(TODO: modify/view cart using ShoppingCart class)\n";
}

void ShoppingMenu::bonusPaymentMenu() {
    cout << "(TODO: bonus and payment actions)\n";
}

void ShoppingMenu::invoiceMenu() {
    cout << "(TODO: invoice actions)\n";
}

/* ============================================================
   MAIN MENU IMPLEMENTATION
   ============================================================ */
MainMenu::MainMenu(std::vector<Customer>* customers,
    vector<Product>* products,
    Customer* activeCustomer,
    ShoppingCart* cart)
    : customers(customers),
    products(products),
    activeCustomer(activeCustomer),
    cart(cart),
    customerMenu(customers),
    shoppingMenu(customers, products, activeCustomer, cart) {
}

void MainMenu::run() {
    bool quit = false;

    while (!quit) {
        showMainMenu();
        int choice = readInt(1, 4);

        switch (choice) {
        case 1:
            customerMenu.showMenu();
            break;

        case 2:
            cout << "\n--- PRODUCTS ---\n";
            for (auto& item : *this->products) {
                item.printProperties();
            }
            break;

        case 3:
            shoppingMenu.showMenu();
            break;

        case 4:
            quit = true;
            break;
        }
    }
}

void MainMenu::showMainMenu() {
    cout << "\n=== MAIN MENU ===\n"
        << "1. Customer\n"
        << "2. Products\n"
        << "3. Shopping\n"
        << "4. Quit\n"
        << "Choose: ";
}

int MainMenu::readInt(int min, int max) {
    int x;
    while (true) {
        if (cin >> x && x >= min && x <= max) return x;
        cin.clear();
        cin.ignore(9999, '\n');
        cout << "Enter valid number: ";
    }
}
