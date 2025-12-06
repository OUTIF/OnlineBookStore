#pragma once

#include <string>
#include <iostream>

using namespace std;

class Product {
private:
    
    int id;
    string name;
    double price;

public:
    
    Product(int id, string name, double price);


    virtual ~Product();

 
    int getID() const;
    void setID(int id);

    string getName() const;
    void setName(string name);

    double getPrice() const;
    void setPrice(double price);

    virtual void printProperties();
};
