#include <iostream>
#include <stdexcept>
#include  "ProductToPurchase.h"

using namespace std;


ProductToPurchase::ProductToPurchase(Product* prodcut,int quantity) {
	if (quantity < 1) { throw invalid_argument("Customer ID cannot be negative"); }
	else { this->Quantity = quantity; }
	this->product = prodcut;
}

ProductToPurchase::~ProductToPurchase() {

}

Product* ProductToPurchase::getProduct() {
	return this->product;
}
void ProductToPurchase::setProduct(Product* product) {
	this->product = product;
}

void ProductToPurchase::setQuantity(int quantity){
	this->Quantity = quantity;
}

int ProductToPurchase::getQuantity() {
	return this->Quantity;
}

void ProductToPurchase::getInfo() {
	cout << "--- product to purchase details ---" << endl<<endl;
	this->product->printProperties();
	cout << "Quantity:" << getQuantity()<<endl;
	cout << "-----------------------" << endl<<endl;
}

