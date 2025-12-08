#include "ShoppingCart.h"

using namespace std;


ShoppingCart::ShoppingCart(Payment* payment, Customer* customer, bool willusebonus) {
    this->paymentMethod = payment;
    this->customer = customer;
    this->isBonusUsed = willusebonus;
}

ShoppingCart::~ShoppingCart() {
    cout << "ShoppingCart Destructor";
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

void ShoppingCart::addProduct(Product* product) {
	for (auto& item : this->productToPurchase) {
		if (item.getProduct()->getID() == product->getID()) {
			item.setQuantity(item.getQuantity() + 1);
			return;
		}
	}
    this->productToPurchase.push_back(ProductToPurchase(product, 1));
}

void ShoppingCart::removeProduct(Product* product) {
	for (auto i = this->productToPurchase.begin(); i != productToPurchase.end(); ++i) {
		if (i->getProduct()->getID() == product->getID()) {
			productToPurchase.erase(i);
			return;
		}
	}
}

void ShoppingCart::placeOrder() {

	
	if (this->customer == nullptr || this->paymentMethod == nullptr || this->productToPurchase.empty()) {
		cout << "error , Something missing";
		return;
	}

	double Total=0;
	for (auto& item : this->productToPurchase) {
			Total += item.getProduct()->getPrice()*item.getQuantity();
	}
	double discount=0;
	if ((this->customer->getBonus() > 0) && (this->isBonusUsed)) {
		discount = this->customer->getBonus();
		if (discount > Total) { discount = Total; }

		Total -= discount;
		this->customer->useBonus();
	}

	this->paymentMethod->setAmount(Total);
	cout << "\n==========  ORDER IS BING PROCESSED  ==========" << endl;
	this->paymentMethod->performPayment();

	double newBonus = 0;
	customer->addBonus(Total * 0.05);
	cout << "\nOrder placed successfully!" << endl;
	cout << "Discount applied: " << discount << " TL" << endl;
	cout << "New bonus earned: " << newBonus << " TL" << endl;
	cout << "======================================" << endl;

	productToPurchase.clear(); //clearing the cart from item that have been purchased
	isBonusUsed = false; 
}


void ShoppingCart::CanselOrder() {
    if (this->productToPurchase.empty()) { cout << "the cart is empty , no need to cansel order"; return; }
    
    this->productToPurchase.clear();
    this->paymentMethod = nullptr;
	
}

void ShoppingCart::printProduct() {
    if (productToPurchase.empty()) {
        cout << "Shopping cart is empty!" << endl;
        return;
    }

    cout << "\n========== SHOPPING CART ==========" << endl;
    double total = 0;
    int itemNumber = 1;

    for (auto& item : productToPurchase) {
        cout << "\nItem #" << itemNumber++ << ":" << endl;
        item.getInfo();

        double subtotal = item.getProduct()->getPrice() * item.getQuantity();
        cout << "Subtotal: " << subtotal << " TL" << endl;
        total += subtotal;
    }

    cout << "\n====================================" << endl;
    cout << "TOTAL: " << total << " TL" << endl;
    cout << "====================================" << endl;
}

void ShoppingCart::showInvoice() {
    if (productToPurchase.empty()) {
        cout << "No invoice to show. Cart is empty! , cant show unvoice" << endl;
        return;
    }

    cout << "\n-------------------------------------------" << endl;
    cout << "|          ONLINE BOOKSTORE INVOICE        |" << endl;
    cout << "-------------------------------------------" << endl;

    // Customer details
    if (customer != nullptr) {
        cout << "\nCustomer Information:" << endl;
        cout << "Name: " << customer->getName() << endl;
        cout << "ID: " << customer->getCustomerID() << endl;
        cout << "Email: " << customer->getEmail() << endl;
        cout << "Phone: " << customer->getPhone() << endl;
    }

    // Product list
    cout << "\n--------------------------------------------" << endl;
    cout << "Items Purchased:" << endl;
    cout << "--------------------------------------------" << endl;

    double subtotal = 0;
    int itemNumber = 1;

    for (auto& item : productToPurchase) {
        Product* prod = item.getProduct();
        int qty = item.getQuantity();
        double price = prod->getPrice();
        double itemTotal = price * qty;

        cout << itemNumber++ << ". " << prod->getName() << endl;
        cout << "   ID: " << prod->getID() << endl;
        cout << "   Price: " << price << " TL x " << qty << " = " << itemTotal << " TL" << endl;

        subtotal += itemTotal;
    }

    // Calculations
    cout << "\n--------------------------------------------" << endl;
    cout << "Subtotal: " << subtotal << " TL" << endl;

    double discount = 0;
    if (isBonusUsed && customer != nullptr) {
        discount = customer->getBonus();
        if (discount > subtotal) {
            discount = subtotal;
        }
        cout << "Bonus Discount: -" << discount << " TL" << endl;
    }

    double total = subtotal - discount;
    cout << "--------------------------------------------" << endl;
    cout << "TOTAL AMOUNT: " << total << " TL" << endl;
    cout << "--------------------------------------------" << endl;

    // Payment info
    if (paymentMethod != nullptr) {
        cout << "\nPayment Method:" << endl;
        paymentMethod->getInfo();
    }

    cout << "\n********************************************" << endl;
    cout << "*     Thank you for your purchase!         *" << endl;
    cout << "********************************************\n" << endl;
}
