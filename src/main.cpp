#include "SayilarListesi.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <limits>

int main() {
    SayilarListesi sayilarListesi;
    std::ifstream dosya("Sayilar.txt");

    if (!dosya) {
        std::cerr << "Sayilar.txt dosyasi acilamadi." << std::endl;
        return 1;
    }

    int sayi;
    while (dosya >> sayi) {
        sayilarListesi.ekleSayi(sayi);
    }

    std::cout << "Okunan Sayilar:" << std::endl;
    sayilarListesi.yazdir();

    int secim;
    bool devam = true;
    while (devam) {
        std::cout << "\nMenu" << std::endl;
        std::cout << "1. Tek basamaklari basa tasi" << std::endl;
        std::cout << "2. Sayilari ters cevir" << std::endl;
        std::cout << "3. En buyuk sayiyi cikar" << std::endl;
        std::cout << "4. Cikis" << std::endl;
        std::cout << "Seciminizi giriniz: ";
        std::cin >> secim;

        if (std::cin.fail()) {
        std::cin.clear(); // akışı temizle
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // hatalı girişi atla
        std::cout << "Gecersiz secim. Tekrar deneyiniz." << std::endl;
        continue; // Döngünün başına dön
        }

        switch (secim) {
            case 1:
                sayilarListesi.tekBasamaklariBasaTasi();
                sayilarListesi.yazdir();
                break;
            case 2:
                sayilarListesi.sayilariTersCevir();
                sayilarListesi.yazdir();
                break;
            case 3:
                sayilarListesi.enBuyukSayiyiCikar();
                sayilarListesi.yazdir();
                break;
            case 4:
                devam = false;
                break;
            default:
                std::cout << "Gecersiz secim. Tekrar deneyiniz." << std::endl;
        }
    }

    return 0;
}
