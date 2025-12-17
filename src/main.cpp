
#include <iostream>
#include <list>
#include <string>
#include "customer.h"
#include "Payment.h"
#include "CreditCard.h"
#include "Cash.h"
#include "Check.h"
#include "Product.h"
#include "MusicCD.h"
#include "Book.h"
#include "Magazine.h"
#include "ProductToPurchase.h"
#include "ShoppingCart.h"
#include "MainMenu.h"


using namespace std;

int main() {
    //products 
// Magazines: (id, title, price, issueNumber, genre)
    Magazine mag1(1000, "National Geographic", 25.50, 10, "Science");
    Magazine mag2(1001, "Uykusuz", 12.0, 750, "Humor");
    Magazine mag3(1002, "Vogue", 30.0, 5, "Fashion");

    // MusicCDs: (id, album_title, price, artist, genre)
    MusicCD cd1(2000, "Dark Side of the Moon", 120.0, "Pink Floyd", "Rock");
    MusicCD cd2(2001, "Metamorfoz", 85.50, "Tarkan", "Pop");
    MusicCD cd3(2002, "Random Access Memories", 110.0, "Daft Punk", "Electronic");

    // Books: (id, title, price, author, publisher, pages)
    Book book1(3000, "Nutuk", 55.00, "Mustafa Kemal Ataturk", "Yapi Kredi Yayinlari", 658);
    Book book2(3001, "1984", 28.90, "George Orwell", "Can Yayinlari", 328);
    Book book3(3002, "Madonna in a Fur Coat", 22.50, "Sabahattin Ali", "Yapi Kredi Yayinlari", 170);


    //customers: (id, name, address, phone, Bonus, email, username, password)
    Customer admin(0, "Yusuf", "Antalya/konyaali/hurma", "+964 7711839891", 0, "yusuf@gmail.com", "admin", "admin00"); // ADMIN
    Customer cutomer1(1, "ibrahim", "adana", "+90 5343414113", 50, "kutuk@gmail.com", "ibrahim01", "kutuk");
    Customer cutomer2(2, "alper", "malatya", "+90 5518325535", 50, "alper@gmail.com", "alper", "guzel");
    Customer customer3(3, "Asmaa", "kirkuk", "+90 65113511355", 100, "asmaa@gmail.com", "relktv", "1220");

    



    // Data structures
    vector<Customer> customers;
    vector<Product> products;

    customers.push_back(admin);
    customers.push_back(cutomer1);
    customers.push_back(cutomer2);
    customers.push_back(customer3);

    products.push_back(mag1);
    products.push_back(mag2);
    products.push_back(mag3);

    products.push_back(cd1);
    products.push_back(cd2);
    products.push_back(cd3);

    products.push_back(book1);
    products.push_back(book2);
    products.push_back(book3);




    Customer* activeCustomer = nullptr;
    ShoppingCart *cart=nullptr;

    // Create MainMenu object correctly
    MainMenu mymenu(&customers, &products, activeCustomer, cart);

    // Run it
    mymenu.run();

    return 0;
}
