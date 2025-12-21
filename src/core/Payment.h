/*

student name:alper güzel
student no:152120231116

*/

#pragma once
#include <iostream>
#include< string>


using namespace std;

class Payment {
protected:
	double amount;
public:
	Payment(double Amount=0);
	~Payment();
	double getAmount();
	void setAmount(double);
	virtual bool performPayment(double);
	virtual void getInfo();
};
