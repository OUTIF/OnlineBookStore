#include "ShoppingCart.h"
#include <iomanip>

using namespace std;


ShoppingCart::ShoppingCart(Payment* payment, Customer* customer, bool willusebonus) {
    this->paymentMethod = payment;
    this->customer = customer;
    this->isBonusUsed = willusebonus;
    this->sizeofcart = 0;
    this->total = 0.0;
}

ShoppingCart::~ShoppingCart() {
    if (paymentMethod != nullptr) {
        delete paymentMethod;
        paymentMethod = nullptr;
    }

}


Payment* ShoppingCart::getPaymentMethod() {
	return this->paymentMethod;
}
void ShoppingCart::setPaymentMethod(Payment* method) {
	this->paymentMethod = method;
}

Customer* ShoppingCart::getCustomer() {
	return this->customer;
}
void ShoppingCart::setCustomer(Customer* customer) {
	this->customer = customer;
}

void ShoppingCart::setBonusUsed() {
	this->isBonusUsed = true;
}
void ShoppingCart::setBonusNotUsed() {
    this->isBonusUsed = false;
}

bool ShoppingCart::getBonusactive() {
    return (this->isBonusUsed);
}

void ShoppingCart::addProduct(Product* product) {
	for (auto& item : this->productToPurchase) {
		if (item.getProduct()->getID() == product->getID()) {
			item.setQuantity(item.getQuantity() + 1);
            this->sizeofcart++;
            this->total+= item.getProduct()->getPrice();
			return;
		}
	}
    
    this->productToPurchase.push_back(ProductToPurchase(product, 1));
    this->sizeofcart++;
    this->total += product->getPrice();
}

void ShoppingCart::removeProduct(Product* product) {
	for (auto i = this->productToPurchase.begin(); i != productToPurchase.end(); ++i) {
		if (i->getProduct()->getID() == product->getID()) {
            this->total -= (i->getProduct()->getPrice() * i->getQuantity());
            this->sizeofcart -= i->getQuantity();

            productToPurchase.erase(i);
            return;
		}
	}
}

void ShoppingCart::placeOrder() {

	//checking the base casses of nullptr
	if (this->customer == nullptr || this->paymentMethod == nullptr || this->productToPurchase.empty()) {
		cout << "error , Something missing";
		return;
	}

    // calculating the total price of all products in the cart (Bonus not included)
	double Total=0;
	for (auto& item : this->productToPurchase) {
			Total += item.getProduct()->getPrice()*item.getQuantity();
	}

    // check if the customer have a bonus in his account and he wants to use it
	double discount=0;
	if ((this->customer->getBonus() > 0) && (this->isBonusUsed)) {
		discount = this->customer->getBonus()*0.1;
		if (discount > Total) { discount = Total; }
		Total -=discount;
	   	this->customer->useBonus();
	}

    // Checking if there is enough money to purchase if not brake the proccess
    if (Total > this->paymentMethod->getAmount()) { cout << "---->There is No enough money to purchase.<----\n"; return; }
    else {
        cout << "\n\n\n\n=========================  ORDER IS BING PROCESSED  ========================\n" << endl;
        this->paymentMethod->performPayment(Total);

        double newBonus = 0;
        newBonus = (Total * 0.01);
        customer->addBonus(newBonus);
        cout << "\nOrder placed successfully!" << endl;
        cout << "Discount applied: " << discount << " $" << endl;
        cout << "New bonus earned: " << newBonus << " $" << endl;
        cout << "\n============================================================================" << endl;

        this->showInvoice();
        productToPurchase.clear(); //clearing the cart from item that have been purchased
        isBonusUsed = false;

        
    }

    }




void ShoppingCart::CanselOrder() {
    if (this->productToPurchase.empty()) { cout << "the cart is empty , no need to cansel order"; return; }
    
    this->productToPurchase.clear();
    this->total = 0;
    this->sizeofcart = 0;
    this->setBonusNotUsed();
	
}
// improvedd

void ShoppingCart::printProduct() {
    if (productToPurchase.empty()) {
        cout << "\n";
        cout << "+===============================================================+\n";
        cout << "|                    SHOPPING CART IS EMPTY                     |\n";
        cout << "+===============================================================+\n";
        return;
    }

    cout << "\n";
    cout << "+====================================================================================+\n";
    cout << "|                              YOUR SHOPPING CART                                    |\n";
    cout << "+====================================================================================+\n";
    cout << "| #  | Product ID | Product Name              | Price    | Qty | Subtotal          |\n";
    cout << "+----+------------+---------------------------+----------+-----+-------------------+\n";

    double total = 0;
    int itemNumber = 1;

    for (auto& item : productToPurchase) {
        Product* prod = item.getProduct();
        int qty = item.getQuantity();
        double price = prod->getPrice();
        double subtotal = price * qty;

        // Format the output nicely
        cout << "| " << setw(2) << left << itemNumber++
            << " | " << setw(10) << left << prod->getID()
            << " | " << setw(25) << left << prod->getName().substr(0, 25)
            << " | $" << setw(7) << right << fixed << setprecision(2) << price
            << " | " << setw(3) << right << qty
            << " | $" << setw(16) << right << fixed << setprecision(2) << subtotal << " |\n";

        total += subtotal;
    }

    cout << "+----+------------+---------------------------+----------+-----+-------------------+\n";
    cout << "|                                                    CART TOTAL: $"
        << setw(16) << right << fixed << setprecision(2) << total << " |\n";
    cout << "+====================================================================================+\n";

    // Show bonus discount if applicable
    if (this->isBonusUsed && this->customer != nullptr && this->customer->getBonus() > 0) {
        double bonusDiscount = this->customer->getBonus() * 0.1;
        if (bonusDiscount > total) {
            bonusDiscount = total;
        }
        double finalTotal = total - bonusDiscount;

        cout << "|                                                 Bonus Discount: -$"
            << setw(15) << right << fixed << setprecision(2) << bonusDiscount << " |\n";
        cout << "|                                                    FINAL TOTAL: $"
            << setw(16) << right << fixed << setprecision(2) << finalTotal << " |\n";
        cout << "+====================================================================================+\n";
    }
}


void ShoppingCart::showInvoice() {
    if (productToPurchase.empty()) {
        cout << "\n+===============================================================+\n";
        cout << "|              NO INVOICE - CART IS EMPTY                       |\n";
        cout << "+===============================================================+\n";
        return;
    }

    cout << "\n\n";
    cout << "+====================================================================================+\n";
    cout << "|                                                                                    |\n";
    cout << "|                          ONLINE BOOKSTORE INVOICE                                  |\n";
    cout << "|                                                                                    |\n";
    cout << "+====================================================================================+\n";

    // Customer Information
    if (customer != nullptr) {
        cout << "|                                                                                    |\n";
        cout << "|  CUSTOMER INFORMATION:                                                             |\n";
        cout << "|  " << setw(82) << left << ("Name: " + customer->getName()) << "|\n";
        cout << "|  " << setw(82) << left << ("Customer ID: " + to_string(customer->getCustomerID())) << "|\n";
        cout << "|  " << setw(82) << left << ("Email: " + customer->getEmail()) << "|\n";
        cout << "|  " << setw(82) << left << ("Phone: " + customer->getPhone()) << "|\n";
        cout << "|                                                                                    |\n";
    }

    cout << "+====================================================================================+\n";
    cout << "| #  | Product ID | Product Name              | Price    | Qty | Total             |\n";
    cout << "+----+------------+---------------------------+----------+-----+-------------------+\n";

    double subtotal = 0;
    int itemNumber = 1;

    for (auto& item : productToPurchase) {
        Product* prod = item.getProduct();
        int qty = item.getQuantity();
        double price = prod->getPrice();
        double itemTotal = price * qty;

        cout << "| " << setw(2) << left << itemNumber++
            << " | " << setw(10) << left << prod->getID()
            << " | " << setw(25) << left << prod->getName().substr(0, 25)
            << " | $" << setw(7) << right << fixed << setprecision(2) << price
            << " | " << setw(3) << right << qty
            << " | $" << setw(16) << right << fixed << setprecision(2) << itemTotal << " |\n";

        subtotal += itemTotal;
    }

    cout << "+----+------------+---------------------------+----------+-----+-------------------+\n";
    cout << "|                                                                                    |\n";
    cout << "|  " << setw(70) << right << "Subtotal: "
        << "$" << setw(8) << right << fixed << setprecision(2) << subtotal << "  |\n";

    // Bonus discount
    double discount = 0;
    if (isBonusUsed && customer != nullptr && customer->getBonus() > 0) {
        discount = customer->getBonus() * 0.1;
        if (discount > subtotal) {
            discount = subtotal;
        }
        cout << "|  " << setw(70) << right << "Bonus Discount: "
            << "-$" << setw(7) << right << fixed << setprecision(2) << discount << "  |\n";
    }

    double finalTotal = subtotal - discount;
    cout << "|  " << setw(82) << right << string(84, '-') << "|\n";
    cout << "|  " << setw(70) << right << "FINAL TOTAL: "
        << "$" << setw(8) << right << fixed << setprecision(2) << finalTotal << "  |\n";
    cout << "|                                                                                    |\n";

    // Payment information
    if (paymentMethod != nullptr) {
        cout << "+====================================================================================+\n";
        cout << "|  PAYMENT INFORMATION:                                                              |\n";
        cout << "|  " << setw(82) << left << ("Payment Amount: $" + to_string(paymentMethod->getAmount())) << "|\n";
        cout << "|  Payment Status: COMPLETED                                                         |\n";
    }

    // Bonus earned
    if (customer != nullptr) {
        int earnedBonus = (int)(subtotal * 0.01);
        cout << "|                                                                                    |\n";
        cout << "|  " << setw(82) << left << ("Bonus Points Earned: " + to_string(earnedBonus)) << "|\n";
        cout << "|  " << setw(82) << left << ("New Bonus Balance: " + to_string(customer->getBonus()) + " points") << "|\n";
    }

    cout << "|                                                                                    |\n";
    cout << "+====================================================================================+\n";
    cout << "|                                                                                    |\n";
    cout << "|                       THANK YOU FOR YOUR PURCHASE!                                |\n";
    cout << "|                     Visit us again at www.onlinebookstore.com                      |\n";
    cout << "|                                                                                    |\n";
    cout << "+====================================================================================+\n\n";
}


int ShoppingCart::size() {
    return this->sizeofcart;
}
bool ShoppingCart::empty() {
    if (this->sizeofcart < 1) { return true; }
    else { return false; }
}
double ShoppingCart::getTotal() {
    return this->total;
}
