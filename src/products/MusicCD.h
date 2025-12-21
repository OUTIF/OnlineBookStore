/*

student name:ibrahim kütük
student no:152120211162

*/

#pragma once

#include "Product.h"

class MusicCD : public Product {
private:
    string singer; 
    string type;   

public:
    MusicCD(int id, string name, double price, string singer, string type);

    string getSinger() const;
    void setSinger(string singer);

    string getType() const;
    void setType(string type);

    void printProperties() override;
};

