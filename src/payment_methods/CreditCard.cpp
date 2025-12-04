#include "CreditCard.h"

void CreditCard::performPayment(){

	if (this->amount < 0) {
		cout << "There is no enough money to perform the payment;\n";
	}
	else {
		cout << "The payment performed using Credit card.\n";
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
