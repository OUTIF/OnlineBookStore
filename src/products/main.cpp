/**
* İsim: İbrahim Kütük
* Tarih: 5/12/2025
* Dosya: main.cpp
* Açıklama: Yazılan sınıfları test etmek için oluşturulan test programı.
* Proje isterlerinde 3'er adet ürün olması gerektiği belirtilmiştir.
*/

#include <iostream>
#include <vector>
#include "Product.h"
#include "Book.h"
#include "Magazine.h"
#include "MusicCD.h"

using namespace std;

int main() {
    // Polymorphism Örneği:
    // Farklı türdeki ürünleri tek bir Product pointer listesinde tutabiliriz.
    vector<Product*> products;

    cout << "--- Urunler Olusturuluyor ---" << endl;

    // 3 Adet Kitap Ekleme
    products.push_back(new Book(101, "Sefiller", 250.0, "Victor Hugo", "Is Bankasi", 1724));
    products.push_back(new Book(102, "1984", 120.5, "George Orwell", "Can Yayinlari", 352));
    products.push_back(new Book(103, "Nutuk", 150.0, "Mustafa Kemal Ataturk", "Alfa", 600));

    // 3 Adet Dergi Ekleme
    products.push_back(new Magazine(201, "Bilim ve Teknik", 50.0, 650, "Bilim"));
    products.push_back(new Magazine(202, "Vogue", 150.0, 120, "Moda"));
    products.push_back(new Magazine(203, "National Geographic", 80.0, 400, "Doga"));

    // 3 Adet Müzik CD Ekleme
    products.push_back(new MusicCD(301, "Thriller", 300.0, "Michael Jackson", "Pop"));
    products.push_back(new MusicCD(302, "Back in Black", 280.0, "AC/DC", "Rock"));
    products.push_back(new MusicCD(303, "Best of Sezen Aksu", 200.0, "Sezen Aksu", "Pop"));

    // Listeyi dolaşıp polymorphism ile yazdirma
    cout << "\n--- Urun Listesi ---" << endl;
    for (const auto& product : products) {
        // Hangi nesne tipindeyse onun printProperties fonksiyonu çağrılır.
        product->printProperties();
    }

    // Bellek Temizliği (Memory Cleanup)
    for (auto& product : products) {
        delete product;
    }
    products.clear();

    return 0;
}