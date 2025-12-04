#pragma once
#include <iostream>
#include< string>


using namespace std;

class Payment {
protected:
	double amount;
public:
	
	double getAmount();
	void setAmount(double);
	virtual void performPayment();
};
