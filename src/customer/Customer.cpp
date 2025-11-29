#include "Customer.h"

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


