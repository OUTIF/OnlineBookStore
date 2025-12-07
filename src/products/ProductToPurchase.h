#pragma once
#include "Product.h"


class ProductToPurchase {
private:

	Product* product;
	int Quantity;

public:
	ProductToPurchase(Product* product,int quantity);
	~ProductToPurchase();
	Product* getProduct();
	void setProduct(Product* product);
	int getQuantity();
	void setQuantity(int quantity);
	void getInfo();

};