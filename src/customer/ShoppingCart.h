#pragma once
#include <iostream>
#include <list>
#include "ProductToPurchase.h"
#include "Payment.h"
#include "Customer.h"

using namespace std;

class ShoppingCart {
private:

	list<ProductToPurchase>productToPurchase;
	Payment* paymentMethod;
	Customer* customer;
	bool isBonusUsed=false;

public:

	ShoppingCart(Payment* payment,Customer* customer, bool willusebonus=false);
	~ShoppingCart();

	Payment* getPaymentMethod();
	void setPaymentMethod(Payment*);
	Customer* getCustomer();
	void setCustomer(Customer*);
	void setBonusUsed();
	void addProduct(Product*);
	void removeProduct(Product*);
	void placeOrder();
	void CanselOrder();
	void printProduct();
	void showInvoice();





};