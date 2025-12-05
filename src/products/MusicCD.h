/**
* İsim: İbrahim Kütük
* Tarih: 5/12/2025
* Dosya: MusicCD.h
* Açıklama: Product sınıfından türetilen Müzik CD sınıfı.
*/

#ifndef MUSICCD_H
#define MUSICCD_H

#include "Product.h"

class MusicCD : public Product {
private:
    string singer; // Şarkıcı
    string type;   // Tür (Pop, Rock, Caz vb.)

public:
    MusicCD(int id, string name, double price, string singer, string type);

    string getSinger() const;
    void setSinger(string singer);

    string getType() const;
    void setType(string type);

    // Polymorphism
    void printProperties() const override;
};

#endif