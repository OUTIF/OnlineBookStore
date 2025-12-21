/*

student name:ibrahim kütük
student no:152120211162

*/

#include "Product.h"

Product::Product(int id, string name, double price) {
    this->id = id;
    this->name = name;
    this->price = price;
}

Product::~Product() {}



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

    if (price >= 0)
        this->price = price;
    else
        cout << "Error: price cant be negative!" << endl;
}

void Product::printProperties() {
    cout << "ID: " << getID() <<" | Name:"<<getName()<<" | Price:"<<getPrice()<<" ";

}
