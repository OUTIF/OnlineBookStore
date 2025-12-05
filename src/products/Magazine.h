/**
* İsim: İbrahim Kütük
* Tarih: 5/12/2025
* Dosya: Magazine.h
* Açıklama: Product sınıfından türetilen Dergi sınıfı.
*/

#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "Product.h"

class Magazine : public Product {
private:
    int issue;   // Sayı
    string type; // Tür (Bilim, Moda, Teknoloji vb.)

public:
    Magazine(int id, string name, double price, int issue, string type);

    int getIssue() const;
    void setIssue(int issue);

    string getType() const;
    void setType(string type);

    // Polymorphism
    void printProperties() const override;
};

#endif