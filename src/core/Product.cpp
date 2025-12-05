/**
* İsim: İbrahim Kütük
* Tarih: 5/12/2025
* Dosya: Product.cpp
* Açıklama: Product sınıfının metod gövdeleri.
*/

#include "Product.h"

// Yapıcı metod: Temel değişkenleri başlatır
Product::Product(int id, string name, double price) {
    this->id = id;
    this->name = name;
    this->price = price;
}

// Yıkıcı metod
Product::~Product() {}

// --- Getter ve Setter Implementasyonları ---

int Product::getID() const {
    return id;
}

void Product::setID(int id) {
    this->id = id;
}

string Product::getName() const {
    return name;
}

void Product::setName(string name) {
    this->name = name;
}

double Product::getPrice() const {
    return price;
}

void Product::setPrice(double price) {
    // Fiyat negatif olamaz kontrolü eklenebilir
    if(price >= 0)
        this->price = price;
    else
        cout << "Hata: Fiyat negatif olamaz!" << endl;
}