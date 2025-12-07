#include "Cash.h"

using namespace std;

Cash::Cash(int Amount) {
	this->amount = Amount;
}

void Cash::performPayment() {

	if (this->amount < 0) {
		cout << "There is no enough money to perform the payment;\n";
	}

	else{
		cout << "The payment performed using cash.\n";
	}
}
void Cash::getInfo() {
	cout << "--- Payment details ---" << endl;
	cout << "Amount: " << getAmount() << endl;
	cout << "-----------------------" << endl;
}