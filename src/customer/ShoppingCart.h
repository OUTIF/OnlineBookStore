/*


STUDENT NAME: YOUSIF HUSSEIN JABBAR AL-GBURI
STUDENT NO  : 152120231144



*/



#pragma once
#include <iostream>
#include <list>
#include "ProductToPurchase.h"
#include "Payment.h"
#include "Customer.h"

using namespace std;

class ShoppingCart {
private:
	double total;
	list<ProductToPurchase>productToPurchase;
	Payment* paymentMethod;
	Customer* customer;
	bool isBonusUsed=false;
	int sizeofcart;

public:

	ShoppingCart(Payment* payment = nullptr, Customer* customer = nullptr, bool willusebonus = false);
	~ShoppingCart();

	Payment* getPaymentMethod();
	void setPaymentMethod(Payment*);
	Customer* getCustomer();
	void setCustomer(Customer*);
	void setBonusUsed();
	void setBonusNotUsed();
	bool getBonusactive();
	void addProduct(Product*);
	void removeProduct(Product*);
	void delete1Product(int);
	void placeOrder();
	void CanselOrder();
	void printProduct();
	void showInvoice();
	int size();
	bool empty();
	double getTotal();





};
