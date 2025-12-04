#include "Cash.h"

using namespace std;

void Cash::performPayment() {

	if (this->amount < 0) {
		cout << "There is no enough money to perform the payment;\n";
	}

	else{
		cout << "The payment performed using cash.\n";
	}
}
