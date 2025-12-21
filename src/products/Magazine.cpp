/*

student name:ibrahim kütük
student no:152120211162

*/
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
    cout << "--- Dergi Detaylari ---" << endl;
    cout << "ID: " << getID() << endl;
    cout << "Isim: " << getName() << endl;
    cout << "Fiyat: " << getPrice() << " TL" << endl;
    cout << "Sayi: " << issue << endl;
    cout << "Tur: " << type << endl;
    cout << "-----------------------" << endl;
}
