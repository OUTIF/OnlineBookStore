/**
* İsim: İbrahim Kütük
* Tarih: 5/12/2025
* Dosya: MusicCD.cpp
* Açıklama: MusicCD sınıfının implementasyonu.
*/

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

void MusicCD::printProperties() const {
    cout << "--- Muzik CD Detaylari ---" << endl;
    cout << "ID: " << getID() << endl;
    cout << "Isim: " << getName() << endl;
    cout << "Fiyat: " << getPrice() << " TL" << endl;
    cout << "Sarkici: " << singer << endl;
    cout << "Tur: " << type << endl;
    cout << "--------------------------" << endl;
}