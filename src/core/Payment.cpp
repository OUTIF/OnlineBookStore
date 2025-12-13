
#include "Payment.h"

using namespace std;

Payment::Payment(double Amount) {
	this->amount = Amount;
}

Payment::~Payment() {
}

double Payment::getAmount() {
	return this->amount;
}

void Payment::setAmount(double newamount) {
	if (newamount < 0) { this->amount = 0; }
	else {
		this->amount = newamount;
	}
}
 // add to the readme void to bool
bool Payment::performPayment(double paymentAmount) {
	if (this->amount < paymentAmount) {
		cout << "There is no enough money to perform the payment;\n";
		return false;
	}
	else {
		this->amount -= paymentAmount;
		cout << "The payment performed using nondefined method.\n";
		return true;
	}

}

void Payment::getInfo() {
	cout << "--- Payment details ---" << endl;
	cout << "Amount: " << getAmount() << endl;
	cout << "-----------------------" << endl;
 }

