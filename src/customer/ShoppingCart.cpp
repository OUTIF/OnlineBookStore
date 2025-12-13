#include "ShoppingCart.h"

using namespace std;


ShoppingCart::ShoppingCart(Payment* payment, Customer* customer, bool willusebonus) {
    this->paymentMethod = payment;
    this->customer = customer;
    this->isBonusUsed = willusebonus;
    this->sizeofcart = 0;
    this->total = 0.0;
}

ShoppingCart::~ShoppingCart() {
   
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
		discount = this->customer->getBonus();
		if (discount > Total) { discount = Total; }
		Total -=discount;
	   	this->customer->useBonus();
	}

    // Checking if there is enough money to purchase if not brake the proccess
    if (Total > this->paymentMethod->getAmount()) { cout << "---->There is No enough money to purchase.<----\n"; return; }
    else {
        cout << "\n\n\n\n=========================  ORDER IS BING PROCESSED  ========================\n" << endl;
        this->paymentMethod->performPayment(total);

        double newBonus = 0;
        newBonus = (Total * 0.01);
        customer->addBonus(newBonus);
        cout << "\nOrder placed successfully!" << endl;
        cout << "Discount applied: " << discount << " TL" << endl;
        cout << "New bonus earned: " << newBonus << " TL" << endl;
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
        cout << "Subtotal: " << subtotal << " TL" << endl<<endl;
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

    cout << "\n\n\n-------------------------------------------" << endl;
    cout << "|          ONLINE BOOKSTORE INVOICE        |" << endl;
    cout << "-------------------------------------------" << endl<<"\n";

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
