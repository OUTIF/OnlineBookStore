/*

student name:alper güzel
student no:152120231116

*/

#include <string>
#include "Check.h"

using namespace std;

Check::Check(double Amount,string Name,string BankId) {
	this->amount = Amount;
	this->name = Name;
	this->bankID = BankId;
}

Check::~Check() {

}

bool Check::performPayment(double paymentAmount) {
	if (this->amount < paymentAmount) {
		cout << "There is no enough money to perform the payment;\n";
		return false;
	}
	else {
		this->amount -= paymentAmount;
		cout << "The payment performed using check.\n";
		cout << "Remaining balance: $" << this->amount << "\n";
		return true;
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
	cout << "Type:Check\n";
	cout << "Amount: " << getAmount() << endl;
	cout << "Name:" << getName() << endl;
	cout << "Bank ID:" << getBankID() << endl;
	cout << "-----------------------" << endl;
}
