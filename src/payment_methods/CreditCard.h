#pragma once
#include "Payment.h"
#include<string>
#include <iostream>

using namespace std;

class CreditCard : public Payment{
private:
	long number;
	string type;
	string expData;
public:
	CreditCard(int Amount,long Number, string Expdata, string Type = "Not specified");
	~CreditCard();
	void performPayment() override;
	long getNumber();
	void setNumber(long);
	string getType();
	void setTyoe(string);
	string getExpData();
	void setExpData(string);
	void getInfo() override;

};