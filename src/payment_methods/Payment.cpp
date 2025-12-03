#include "Payment.h"

using namespace std;

Payment::Payment(double newamount) {
	if (newamount < 0) { this->amount = 0; }
	else{ this->amount = newamount; }
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

