/**
* İsim: İbrahim Kütük
* Tarih: 5/12/2025
* Dosya: Book.h
* Açıklama: Product sınıfından türetilen Kitap sınıfı.
*/

#ifndef BOOK_H
#define BOOK_H

#include "Product.h"

// Inheritance (Kalıtım): Book bir Product'tır.
class Book : public Product {
private:
    string author;
    string publisher;
    int page;

public:
    // Yapıcı metod
    Book(int id, string name, double price, string author, string publisher, int page);

    // Getter ve Setterlar
    string getAuthor() const;
    void setAuthor(string author);

    string getPublisher() const;
    void setPublisher(string publisher);

    int getPage() const;
    void setPage(int page);

    // Polymorphism (Çok Biçimlilik): Üst sınıftaki metodu eziyoruz (override)
    void printProperties() const override;
};

#endif