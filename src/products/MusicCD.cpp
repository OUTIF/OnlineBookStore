
#include "MusicCD.h"
#include <iostream>

MusicCD::MusicCD(int id, string name, double price, string singer, string type)
    : Product(id, name, price) {
    this->singer = singer;
    this->type = type;
}

string MusicCD::getSinger() const {
    return singer;
}

void MusicCD::setSinger(string singer) {
    this->singer = singer;
}

string MusicCD::getType() const {
    return type;
}

void MusicCD::setType(string type) {
    this->type = type;
}

void MusicCD::printProperties() {
    cout << "--- music CD Detials ---" << endl;
    cout << "ID: " << getID() << endl;
    cout << "name: " << getName() << endl;
    cout << "price: " << getPrice() << " TL" << endl;
    cout << "singer: " << singer << endl;
    cout << "type: " << type << endl;
    cout << "--------------------------" << endl;
}