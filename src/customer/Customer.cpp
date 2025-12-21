/*


STUDENT NAME: YOUSIF HUSSEIN JABBAR AL-GBURI
STUDENT NO  : 152120231144



*/



#include <iostream>
#include <stdexcept>
#include "Customer.h"

Customer::Customer(long Id, string Name, string Address, string Phone,
    double Bonus, string Email, string UserName, string Password) {
    if (Id < 0) {
        throw invalid_argument("Customer ID cannot be negative");
    }
    this->customerID = Id;

    this->name = Name;
    this->address = Address;
    this->phone = Phone;

    if (Bonus < 0) {
        throw invalid_argument("Bonus cannot be negative");
    }
    this->bonus = Bonus;

    this->email = Email;
    this->username = UserName;
    this->password = Password;
}

Customer::~Customer() {}

void Customer::setName(string iname) { this->name = iname; }
string Customer::getName() { return this->name; }


void Customer::setUsername(string iusername) { this->username = iusername; }
string Customer::getUsername() { return this->username; }

void Customer::setPassword(string ipassword) { this->password = ipassword; }
string Customer::getPassword() { return this->password; }

void Customer::setAddress(string iaddress) { this->address = iaddress; }
string Customer::getAddress() { return this->address; }

void Customer::setEmail(string iemail) { this->email = iemail; }
string Customer::getEmail() { return this->email; }

void Customer::setPhone(string iphone) { this->phone = iphone; }
string Customer::getPhone() { return this->phone; }

void Customer::setCustomerID(long id) { this->customerID = id; }
long Customer::getCustomerID() { return this->customerID; }


void Customer::setBonus(double amount) { this->bonus = amount; }
void Customer::addBonus(double amount) { this->bonus += amount; }
double Customer::getBonus() { return this->bonus; }
void Customer::useBonus() { this->bonus = 0; }

bool Customer::checkAccount(string username, string password) {
    return (this->username == username && this->password == password);
}

void Customer::getInfo() {
    cout << "\n->\n-------- Customer details --------\n" << endl;
    cout << "ID: " << getCustomerID() << endl;
    cout << "password:" << getPassword() << endl;
    cout << "name: " << getName() << endl;
    cout << "address: " << getAddress()<< endl;
    cout << "phone number:" << getPhone() << endl;
    cout << "bonus:" << getBonus() << endl;
    cout << "email:" << getEmail() << endl;
    cout << "username:" << getUsername() << endl;
    cout << "\n----------------------------------" << endl;
}


