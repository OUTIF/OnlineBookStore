/*

student name:ibrahim kütük
student no:152120211162

*/

#include "Book.h"
#include <iostream>

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

void Book::printProperties()  {
    cout << "--- Kitap Detaylari ---" << endl;
    cout << "ID: " << getID() << endl;
    cout << "Name: " << getName() << endl;
    cout << "price: " << getPrice() << " TL" << endl;
    cout << "author: " << author << endl;
    cout << "publisher: " << publisher << endl;
    cout << "pages: " << page << endl;
    cout << "-----------------------" << endl;
}
