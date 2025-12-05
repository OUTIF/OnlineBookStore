/**
* İsim: İbrahim Kütük
* Tarih: 5/12/2025
* Dosya: Product.h
* Açıklama: Tüm ürünlerin türetileceği soyut temel sınıf (Abstract Base Class).
*/

#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <iostream>

using namespace std;

class Product {
private:
    // UML diyagramındaki temel özellikler
    int id;
    string name;
    double price;

public:
    // Yapıcı (Constructor)
    Product(int id, string name, double price);
    
    // Sanal Yıkıcı (Virtual Destructor) - Kalıtım için gereklidir
    virtual ~Product();

    // Getter ve Setter Metodları
    int getID() const;
    void setID(int id);

    string getName() const;
    void setName(string name);

    double getPrice() const;
    void setPrice(double price);

    // Saf Sanal Fonksiyon (Pure Virtual Function)
    // Bu sınıfı soyut (abstract) yapar. Alt sınıflar bunu ezmek (override) zorundadır.
    virtual void printProperties() const = 0;
};

#endif