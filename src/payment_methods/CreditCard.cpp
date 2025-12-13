#include "CreditCard.h"

CreditCard::CreditCard(int Amount,long Number, string Expdata, string Type) {
	this->amount = Amount;
	this->number = Number;
	this->expData = Expdata;
	this->type = Type;
}

CreditCard::~CreditCard() {
}

bool CreditCard::performPayment(double paymentAmount){
		if (this->amount < paymentAmount) {
			cout << "There is no enough money to perform the payment;\n";
			return false;
		}
		else {
			this->amount -= paymentAmount;  // DEDUCT THE MONEY
			cout << "The payment performed using Credit card.\n";
			cout << "Remaining balance: $" << this->amount << "\n";
			return true;
		}
	
}

long CreditCard::getNumber() {
	return this->number;
}

void CreditCard::setNumber(long Number){
	this->number = Number;
}

string CreditCard::getType() {
	return this->type;
}

void CreditCard::setTyoe(string Type) {
	this->type = Type;
}

string CreditCard::getExpData() {
	return this->expData;
}

void CreditCard::setExpData(string expdata) {
	this->expData = expdata;
}

void CreditCard::getInfo() {
	cout << "--- Payment details ---" << endl;
	cout << "Amount: " << getAmount() << endl;
	cout << "Number:" << getNumber() << endl;
	cout << "Expire Date:" << getExpData() << endl;
	cout << "Type of card:" << getType() << endl;
	cout << "-----------------------" << endl;
}
