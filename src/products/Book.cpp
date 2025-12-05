/**
* İsim: İbrahim Kütük
* Tarih: 5/12/2025
* Dosya: Book.cpp
* Açıklama: Book sınıfının implementasyonu.
*/

#include "Book.h"
#include <iostream>

// Base class constructor'ını (Product) çağırarak başlatma listesi (initializer list) kullanıyoruz.
Book::Book(int id, string name, double price, string author, string publisher, int page)
    : Product(id, name, price) {
    this->author = author;
    this->publisher = publisher;
    this->page = page;
}

string Book::getAuthor() const {
    return author;
}

void Book::setAuthor(string author) {
    this->author = author;
}

string Book::getPublisher() const {
    return publisher;
}

void Book::setPublisher(string publisher) {
    this->publisher = publisher;
}

int Book::getPage() const {
    return page;
}

void Book::setPage(int page) {
    this->page = page;
}

// Kitap özelliklerini ekrana yazdırma
void Book::printProperties() const {
    cout << "--- Kitap Detaylari ---" << endl;
    cout << "ID: " << getID() << endl;
    cout << "Isim: " << getName() << endl;
    cout << "Fiyat: " << getPrice() << " TL" << endl;
    cout << "Yazar: " << author << endl;
    cout << "Yayinevi: " << publisher << endl;
    cout << "Sayfa Sayisi: " << page << endl;
    cout << "-----------------------" << endl;
}