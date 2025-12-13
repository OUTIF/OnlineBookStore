#include "MainMenu.h"
#include "Magazine.h"
#include "MusicCD.h"
#include "Book.h"

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
        case 3: { back = true;  cout << "\nReturning to Main Menu...\n"; break; }
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
            << "5. Back\n"
            << "Choose: ";

        int choice = readInt(1, 6);

        switch (choice) {
        case 1: loginLogout(); break;
        case 2: productOperations(); break;
        case 3: cartOperations(); break;
        case 4: bonusPaymentMenu(); break;
        case 5: back = true; break;
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
   
    cout << "\n-------------------------------------\n";
    cout << "|          Login-Logout             |\n";
    cout << "-------------------------------------\n";

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
            if (c.checkAccount(user,pass)) {
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

    bool back = false;

    while (!back) {
        cout << "\n=== PRODUCT CATEGORIES ===\n"
            << "1. Magazines \n"
            << "2. Music CDs \n"
            << "3. Books \n"
            << "4. View All Products\n"
            << "5. Back to Shopping Menu\n"
            << "Choose: ";

        int categoryChoice = readInt(1, 5);

        if (categoryChoice == 5) {
            cout << "Returning to Shopping Menu...\n";
            return;
        }

        // Display products by category
        switch (categoryChoice) {
        case 1: // Magazines (IDs starting with 1)
            cout << "\n--- MAGAZINES ---\n";
            for (auto& item : *this->products) {
                int id = item.getID();
                if (id >= 1000 && id < 2000) {  // IDs 1xxx
                    item.printProperties();
                }
            }
            break;

        case 2: // Music CDs (IDs starting with 2)
            cout << "\n--- MUSIC CDs ---\n";
            for (auto& item : *this->products) {
                int id = item.getID();
                if (id >= 2000 && id < 3000) {  // IDs 2xxx
                    item.printProperties();
                }
            }
            break;

        case 3: // Books (IDs starting with 3)
            cout << "\n--- BOOKS ---\n";
            for (auto& item : *this->products) {
                int id = item.getID();
                if (id >= 3000 && id < 4000) {  // IDs 3xxx                 
                    item.printProperties();
                }
            }
            break;

        case 4: // All Products
            cout << "---------------All Products---------------";
            for (auto& item : *this->products) {
                cout << endl;
                item.printProperties();
            }
            break;
        }

        cout << endl;

        // Add products to cart
        cout << "Enter product ID to add to cart (or -1 to go back):\n";

        while (true) {
            cout << "ID of product: ";
            int p;
            cin >> p;

            if (p == -1) {
                cout << "Returning to category menu...\n";
                break;
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
}

void ShoppingMenu::cartOperations() {
    if (this->activeCustomer == nullptr) {
        cout << "You have to log in first to view your cart.\n";
        return;
    }

    bool back = false;

    while (!back) {
        cout << "\n-------------------------------------\n";
        cout << "|          SHOPPING CART             |\n";
        cout << "-------------------------------------\n";

        // Display current cart contents
        cout << "\n--- Current Cart Items ---\n";
      
        if (this->cart == nullptr) {
            cout << "Your cart is empty.\n";
        }
        else {
            this->cart->printProduct();  // Display all products in cart
        }

        // Cart operations menu
        cout << "\n=== CART OPERATIONS ===\n"
            << "1. Add Product to Cart\n"
            << "2. View All Available Products\n"
            << "3. Remove Product from Cart\n"
            << "4. Clear Cart (Cancel Order)\n"
            << "5. Proceed to Bonus & Payment\n"
            << "6. Back to Shopping Menu\n"
            << "Choose: ";

        int choice = readInt(1, 6);

        switch (choice) {
        case 1: {
            productOperations();
        }

        case 2: {
            // View all products
            cout << "\n--- Available Products ---\n";
            for (auto& item : *this->products) {
                cout << endl;
                item.printProperties();
                cout << endl;
            }
            break;
            
        }

        case 3: {
            // Remove product from cart
            if (this->cart==nullptr) {
                cout << "Cart is empty. Nothing to remove.\n";
                break;
            }

            cout << "Enter product ID to remove from cart (or -1 to cancel): ";
            int productID;
            cin >> productID;

            if (productID == -1) {
                cout << "Cancelled.\n";
                break;
            }

            bool found = false;
            for (auto& item : *this->products) {
                if (productID == item.getID()) {
                    this->cart->removeProduct(&item);
                    cout << item.getName() << " has been removed from the cart.\n";
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Invalid product ID.\n";
            }
            break;
        }

        case 4: {
            // Clear entire cart - Cancel Order
            if (this->cart==nullptr) {
                cout << "Cart is already empty.\n";
            }
            else {
                cout << "Are you sure you want to clear the entire cart? (yes/no): ";
                string confirm;
                cin >> confirm;

                if (confirm == "yes" || confirm == "Yes" || confirm == "YES") {
                    this->cart->CanselOrder();
                    cout << "Cart has been cleared.\n";
                }
                else {
                    cout << "Cancelled.\n";
                }
            }
            break;
        }

        case 5: {
            // Proceed to Bonus & Payment
            if (this->cart==nullptr) {
                cout << "Your cart is empty. Add items before proceeding to payment.\n";
            }
            else {
                bonusPaymentMenu();
            }
            break;
        }

        case 6: {
            // Back to shopping menu
            back = true;
            cout << "Returning to Shopping Menu...\n";
            break;
        }

        default:
            cout << "Invalid choice.\n";
            break;
        }
    }
}


void ShoppingMenu::bonusPaymentMenu() {
    if (this->activeCustomer == nullptr) {
        cout << "You have to log in first.\n";
        return;
    }

    if (this->cart == nullptr || this->cart->empty()) {
        cout << "Your cart is empty. Add items before proceeding to payment.\n";
        return;
    }

    bool backToCart = false;

    while (!backToCart) {
        if (this->cart == nullptr || this->cart->empty()) {
            cout << "\nCart is empty. Returning to shopping menu.\n";
            return;
        }

        cout << "\n===============================================\n";
        cout << "|       BONUS & PAYMENT MENU                  |\n";
        cout << "===============================================\n";

        cout << "\n--- Cart Summary ---\n";
        this->cart->printProduct();
        cout << "\nTotal Amount: $" << this->cart->getTotal() << "\n";

        cout << "\n=== OPTIONS ===\n"
            << "1. Set/Change Payment Method\n"
            << "2. View Payment Details\n"
            << "3. Manage Bonus Points\n"
            << "4. Complete Purchase\n"
            << "5. Back to Cart\n"
            << "Choose: ";

        int choice = readInt(1, 5);

        switch (choice) {

        case 1: {
            cout << "\n--- Select Payment Method ---\n";
            cout << "1. Cash\n";
            cout << "2. Credit Card\n";
            cout << "3. Check\n";
            cout << "Choose: ";

            int paymentChoice = readInt(1, 3);

            Payment* oldPayment = this->cart->getPaymentMethod();
            Payment* newPayment = nullptr;
            bool paymentSet = false;

            switch (paymentChoice) {

            case 1: {
                double amount;
                cout << "Enter cash amount: $";
                cin >> amount;

                if (amount < this->cart->getTotal()) {
                    cout << "Insufficient cash amount! Need at least $" << this->cart->getTotal() << "\n";
                    break;
                }

                newPayment = new Cash(amount);
                paymentSet = true;
                cout << "Cash payment method set successfully.\n";
                break;
            }

            case 2: {
                double amount;
                long cardNumber;
                string expireDate;
                string cardType;

                cout << "Enter amount to charge: $";
                cin >> amount;

                if (amount < this->cart->getTotal()) {
                    cout << "Insufficient amount! Need at least $" << this->cart->getTotal() << "\n";
                    break;
                }

                cout << "Card Number: ";
                cin >> cardNumber;
                cin.ignore();

                cout << "Expiration Date (MM/YY): ";
                getline(cin, expireDate);

                cout << "Card Type (Visa/MasterCard/etc): ";
                getline(cin, cardType);

                newPayment = new CreditCard(amount, cardNumber, expireDate, cardType);
                paymentSet = true;
                cout << "Credit card payment method set successfully.\n";
                break;
            }

            case 3: {
                double amount;
                string bankID;

                cout << "Enter check amount: $";
                cin >> amount;

                if (amount < this->cart->getTotal()) {
                    cout << "Insufficient check amount! Need at least $" << this->cart->getTotal() << "\n";
                    break;
                }

                cin.ignore();
                cout << "Bank ID: ";
                getline(cin, bankID);

                newPayment = new Check(amount, this->activeCustomer->getName(), bankID);
                paymentSet = true;
                cout << "Check payment method set successfully.\n";
                break;
            }
            }

            if (paymentSet && newPayment != nullptr) {
                if (oldPayment != nullptr) {
                    delete oldPayment;
                }
                this->cart->setPaymentMethod(newPayment);
            }

            break;
        }

        case 2: {
            cout << "\n--- Payment Details ---\n";
            if (this->cart->getPaymentMethod() != nullptr) {
                this->cart->getPaymentMethod()->getInfo();
            }
            else {
                cout << "No payment method set yet.\n";
            }
            break;
        }

        case 3: {
            cout << "\n--- Bonus Points Management ---\n";

            cout << "Your Current Bonus Points: " << this->activeCustomer->getBonus() << "\n";
            cout << "Bonus Currently Active: " << (this->cart->getBonusactive() ? "Yes" : "No") << "\n";

            double potentialDiscount = this->activeCustomer->getBonus() * 0.1;
            if (potentialDiscount > this->cart->getTotal()) {
                potentialDiscount = this->cart->getTotal();
            }

            if (this->activeCustomer->getBonus() > 0) {
                cout << "Potential Discount: $" << potentialDiscount << "\n";
            }

            cout << "\nDo you want to use your bonus points for this purchase? (yes/no): ";
            string useBonusChoice;
            cin >> useBonusChoice;

            if (useBonusChoice == "yes" || useBonusChoice == "Yes" || useBonusChoice == "YES") {
                this->cart->setBonusUsed();
                cout << "Bonus points will be applied to this purchase.\n";
            }
            else {
                this->cart->setBonusNotUsed();
                cout << "Bonus points will not be used for this purchase.\n";
            }
            break;
        }

        case 4: {
            if (this->cart == nullptr || this->cart->empty()) {
                cout << "\nERROR: Cart is empty!\n";
                break;
            }

            if (this->cart->getPaymentMethod() == nullptr) {
                cout << "\nERROR: Please set a payment method before completing purchase.\n";
                break;
            }

            double subtotal = this->cart->getTotal();
            double bonusDiscount = 0;

            if (this->cart->getBonusactive() && this->activeCustomer->getBonus() > 0) {
                bonusDiscount = this->activeCustomer->getBonus() * 0.1;

                if (bonusDiscount > subtotal) {
                    bonusDiscount = subtotal;
                }
            }

            double finalTotal = subtotal - bonusDiscount;

            cout << "\n===============================================\n";
            cout << "|          PURCHASE SUMMARY                   |\n";
            cout << "===============================================\n";

            this->cart->printProduct();

            cout << "\n--- Price Breakdown ---\n";
            cout << "Subtotal:        $" << subtotal << "\n";

            if (bonusDiscount > 0) {
                int bonusUsed = (int)(bonusDiscount / 0.1);
                cout << "Bonus Discount:  -$" << bonusDiscount
                    << " (" << bonusUsed << " points used)\n";
                cout << "----------------------------\n";
                cout << "Final Total:     $" << finalTotal << "\n";
            }
            else {
                cout << "----------------------------\n";
                cout << "Final Total:     $" << finalTotal << "\n";
            }

            cout << "\n--- Payment Method ---\n";
            this->cart->getPaymentMethod()->getInfo();

            cout << "\nConfirm purchase? (yes/no): ";
            string confirm;
            cin >> confirm;

            if (confirm == "yes" || confirm == "Yes" || confirm == "YES") {

                if (this->cart->getPaymentMethod()->getAmount() < finalTotal) {
                    cout << "\nPayment failed! Insufficient funds.\n";
                    cout << "Required: $" << finalTotal << "\n";
                    cout << "Available: $" << this->cart->getPaymentMethod()->getAmount() << "\n";
                    break;
                }

                this->cart->getPaymentMethod()->performPayment(finalTotal);

                cout << "\nPayment successful!\n";

                if (this->cart->getBonusactive() && bonusDiscount > 0) {
                    int usedBonus = (int)(bonusDiscount / 0.1);
                    this->activeCustomer->setBonus(this->activeCustomer->getBonus() - usedBonus);
                    cout << usedBonus << " bonus points deducted\n";
                }

                int earnedBonus = (int)(subtotal / 10.0);
                this->activeCustomer->setBonus(this->activeCustomer->getBonus() + earnedBonus);
                cout << "You earned " << earnedBonus << " new bonus points!\n";
                cout << "New bonus balance: " << this->activeCustomer->getBonus() << " points\n";

                this->cart->showInvoice();

                this->cart->CanselOrder();

                cout << "\nThank you for your purchase!\n";

                if (this->cart->getPaymentMethod() != nullptr) {
                    cout << "Your payment method has been retained with remaining balance: $"
                        << this->cart->getPaymentMethod()->getAmount() << "\n";
                }

                backToCart = true;
            }
            else {
                cout << "Purchase cancelled.\n";
            }
            break;
        }

        case 5: {
            backToCart = true;
            cout << "Returning to cart...\n";
            break;
        }
        }
    }
}






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
            browseProducts();
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

void MainMenu::browseProducts() {
    bool back = false;

    while (!back) {
        cout << "\n=== PRODUCT CATEGORIES ===\n"
            << "1. Magazines\n"
            << "2. Music CDs\n"
            << "3. Books\n"
            << "4. View All Products\n"
            << "5. Back to Main Menu\n"
            << "Choose: ";

        int categoryChoice = readInt(1, 5);

        if (categoryChoice == 5) {
            cout << "Returning to Main Menu...\n";
            return;
        }

        // Display products by category
        switch (categoryChoice) {
        case 1: // Magazines (IDs starting with 1)
            cout << "\n--- MAGAZINES ---\n";
            for (auto& item : *this->products) {
                int id = item.getID();
                if (id >= 1000 && id < 2000) {  // IDs 1xxx
                    item.printProperties();
                }
            }
            break;

        case 2: // Music CDs (IDs starting with 2)
            cout << "\n--- MUSIC CDs ---\n";
            for (auto& item : *this->products) {
                int id = item.getID();
                if (id >= 2000 && id < 3000) {  // IDs 2xxx
                    item.printProperties();
                }
            }
            break;

        case 3: // Books (IDs starting with 3)
            cout << "\n--- BOOKS ---\n";
            for (auto& item : *this->products) {
                int id = item.getID();
                if (id >= 3000 && id < 4000) {  // IDs 3xxx
                    item.printProperties();
                }
            }
            break;

        case 4: // All Products
            cout << "---------------All Products---------------";
            for (auto& item : *this->products) {
                cout << endl;
                item.printProperties();
            }
            break;
        
        }

        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();
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
