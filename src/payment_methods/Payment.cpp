#include "Payment.h"

using namespace std;

double Payment::getAmount() {
	return this->amount;
}

void Payment::setAmount(double newamount) {
	if (newamount < 0) { this->amount = 0; }
	else {
		this->amount = newamount;

	}
} 

void Payment::performPayment() {
	if (this->amount < 0) {
		cout << "There is no enough money to perform the payment;";
	}
	else {
		cout << "The payment performed using nondefined method.";
	}

}
