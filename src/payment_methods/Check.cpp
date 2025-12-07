#include <string>
#include "Check.h"

using namespace std;

Check::Check(int Amount,string Name,string BankId) {
	this->amount = Amount;
	this->name = Name;
	this->bankID = BankId;
}

Check::~Check() {

}

void Check::performPayment() {

	if (this->amount < 0) {
		cout << "There is no enough money to perform the payment;\n";
	}

	else {
		cout << "The payment performed using check.\n";
	}
}

string Check::getName() {
	return this->name;
}

void Check::setName(string Name){
	this->name = Name;
}


string Check::getBankID() {
	return this->bankID;
}

void Check::setBankID(string bankid){
	this->bankID = bankid;
}


void Check::getInfo() {
	cout << "--- Payment details ---" << endl;
	cout << "Amount: " << getAmount() << endl;
	cout << "Name:" << getName() << endl;
	cout << "Bank ID:" << getBankID() << endl;
	cout << "-----------------------" << endl;
}