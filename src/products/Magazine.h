/*

student name:ibrahim kütük
student no:152120211162

*/

#pragma once

#include "Product.h"

class Magazine : public Product {
private:
    int issue;   
    string type; 

public:
    Magazine(int id, string name, double price, int issue, string type);

    int getIssue() const;
    void setIssue(int issue);

    string getType() const;
    void setType(string type);

    void printProperties() override;
};
