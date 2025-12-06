
#include "Magazine.h"
#include <iostream>

Magazine::Magazine(int id, string name, double price, int issue, string type)
    : Product(id, name, price) {
    this->issue = issue;
    this->type = type;
}

int Magazine::getIssue() const {
    return issue;
}

void Magazine::setIssue(int issue) {
    this->issue = issue;
}

string Magazine::getType() const {
    return type;
}

void Magazine::setType(string type) {
    this->type = type;
}

void Magazine::printProperties(){
    cout << "--- Magazine Details ---" << endl;
    cout << "ID: " << getID() << endl;
    cout << "name: " << getName() << endl;
    cout << "price: " << getPrice() << " TL" << endl;
    cout << "issue: " << issue << endl;
    cout << "type: " << type << endl;
    cout << "-----------------------" << endl;
}