#pragma once
#include "Payment.h"
#include <iostream>
#include <string>

using namespace std;

class Check:public Payment {
private:
	string name;
	string bankID;
public:
	void performPayment() override;
	string getName();
	void setName(string);
	string getBankID();
	void setBankID(string);

};
