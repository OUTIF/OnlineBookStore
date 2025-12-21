/*

student name:alper güzel
student no:152120231116

*/

#include "Cash.h"

using namespace std;

Cash::Cash(int Amount) {
	this->amount = Amount;
}
Cash::~Cash() {

}

bool Cash::performPayment(double paymentAmount) {
    if (this->amount < paymentAmount) {
        cout << "There is no enough money to perform the payment;\n";
        return false;
    }
    else {
        this->amount -= paymentAmount; 
        cout << "The payment performed using cash.\n";
        cout << "Remaining cash: $" << this->amount << "\n";
        return true;
    }
}
void Cash::getInfo() {
	cout << "--- Payment details ---" << endl;
    cout << "Type:Cash\n";
	cout << "Amount: " << getAmount() << endl;
	cout << "-----------------------" << endl;
}
