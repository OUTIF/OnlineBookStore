#pragma once
#include <iostream>
#include< string>


using namespace std;

class Payment {
protected:
	double amount;
public:
	Payment(double=0);
	double getAmount();
	void setAmount(double);
	virtual void performPayment() = 0;
};
