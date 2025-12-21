/*

student name:alper güzel
student no:152120231116

*/

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
	Check(double Amount,string Name,string BankId);
	~Check();
	bool performPayment(double) override;
	string getName();
	void setName(string);
	string getBankID();
	void setBankID(string);
	void getInfo() override;

};
