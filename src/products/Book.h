/*

student name:ibrahim kütük
student no:152120211162

*/

#pragma once
#include "Product.h"

class Book : public Product {
private:
    string author;
    string publisher;
    int page;

public:
    
    Book(int id, string name, double price, string author, string publisher, int page);

    string getAuthor() const;
    void setAuthor(string author);

    string getPublisher() const;
    void setPublisher(string publisher);

    int getPage() const;
    void setPage(int page);

    void printProperties() override;
};
