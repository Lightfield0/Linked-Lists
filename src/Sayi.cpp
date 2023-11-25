#include "Sayi.h"
#include <algorithm>
#include <sstream>
#include <iostream>

Sayi::Sayi() : bas(nullptr) {}

void Sayi::sayiyiOlustur(int sayi) {
    if (sayi == 0) {
        ekleBasamak(0);
        return;
    }

    while (sayi > 0) {
        int basamakDegeri = sayi % 10;
        ekleBasamak(basamakDegeri);
        sayi /= 10;
    }
}

void Sayi::ekleBasamak(int deger) {
    Basamak* yeniBasamak = new Basamak(deger);
    yeniBasamak->setSonraki(bas);
    bas = yeniBasamak;
}

void Sayi::yazdir() {
    std::stringstream ss;
    ss << this;
    std::string adres = ss.str().substr(ss.str().length() - 6);

    std::string sayiStr = sayiDegeriniAl();
    // size_t uzunluk = sayiStr.length();

    size_t basamakSayisi = 0;
    Basamak* gecici = bas;
    while (gecici != nullptr) {
        basamakSayisi++;
        gecici = gecici->getSonraki();
    }

    // size_t toplamUzunluk = std::max(uzunluk, basamakSayisi * 2 + 6);
    size_t genislik = std::max(adres.length() + 4, sayiStr.length() + 4);

    std::string sayiUstSinir = std::string(genislik, '#') + " ";
    std::string sayiAdresSatiri = "# " + adres + std::string(genislik - adres.length() - 3, ' ') + "# ";
    std::string sayiAyiriciCizgi = "#" + std::string(genislik - 2, '-') + "# ";
    std::string sayiDegerSatiri = "# " + sayiStr + std::string(genislik - sayiStr.length() - 3, ' ') + "# ";
    std::string sayiAltSinir = std::string(genislik, '#') + " ";

    std::string basamakUstSinir = "", basamakAdresSatiri = "", basamakAyiriciCizgi = "", basamakDegerSatiri = "", basamakAltSinir = "";

    gecici = bas;
    while (gecici != nullptr) {
        std::stringstream basamak_ss;
        basamak_ss << gecici;
        std::string basamakAdres = basamak_ss.str().substr(basamak_ss.str().length() - 3);

        std::string basamakDegerStr = std::to_string(gecici->getDeger());
        size_t basamakGenislik = std::max(basamakAdres.length() + 4, basamakDegerStr.length() + 4);

        basamakUstSinir += std::string(basamakGenislik, '*') + " ";
        basamakAdresSatiri += "* " + basamakAdres + std::string(basamakGenislik - basamakAdres.length() - 3, ' ') + "* ";
        basamakAyiriciCizgi += "*" + std::string(basamakGenislik - 2, '*') + "* ";
        basamakDegerSatiri += "* " + basamakDegerStr + std::string(basamakGenislik - basamakDegerStr.length() - 3, ' ') + "* ";
        basamakAltSinir += std::string(basamakGenislik, '*') + " ";

        gecici = gecici->getSonraki();
    }

    std::cout << sayiUstSinir << ' ' << basamakUstSinir << "\n";
    std::cout << sayiAdresSatiri << ' ' << basamakAdresSatiri << "\n";
    std::cout << sayiAyiriciCizgi << ' ' << basamakAyiriciCizgi << "\n";
    std::cout << sayiDegerSatiri << ' ' << basamakDegerSatiri << "\n";
    std::cout << sayiAltSinir << ' ' << basamakAltSinir << "\n\n";
}



std::string Sayi::sayiDegeriniAl() const {
    std::stringstream ss;
    Basamak* gecici = bas;
    while (gecici != nullptr) {
        ss << gecici->getDeger();
        gecici = gecici->getSonraki();
    }
    std::string sayi = ss.str();
    std::reverse(sayi.begin(), sayi.end());
    return sayi;
}

void Sayi::tekBasamaklariBasaTasi() {
    Basamak *mevcut = bas, *onceki = nullptr;
    while (mevcut != nullptr && mevcut->getDeger() % 2 == 1) {
        onceki = mevcut;
        mevcut = mevcut->getSonraki();
    }

    while (mevcut != nullptr) {
        if (mevcut->getDeger() % 2 == 1) {
            onceki->setSonraki(mevcut->getSonraki());
            mevcut->setSonraki(bas);
            bas = mevcut;
            mevcut = onceki->getSonraki();
        } else {
            onceki = mevcut;
            mevcut = mevcut->getSonraki();
        }
    }
}

void Sayi::sayiyiTersCevir() {
    Basamak *onceki = nullptr, *mevcut = bas, *sonraki = nullptr;
    while (mevcut != nullptr) {
        sonraki = mevcut->getSonraki();
        mevcut->setSonraki(onceki);
        onceki = mevcut;
        mevcut = sonraki;
    }
    bas = onceki;
}

int Sayi::getSayiDegeri() {
    int deger = 0;
    int basamakKatsayisi = 1;
    Basamak* gecici = bas;
    while (gecici != nullptr) {
        deger += gecici->getDeger() * basamakKatsayisi;
        basamakKatsayisi *= 10;
        gecici = gecici->getSonraki();
    }
    return deger;
}

Sayi::~Sayi() {
    Basamak* gecici;
    while (bas != nullptr) {
        gecici = bas;
        bas = bas->getSonraki();
        delete gecici;
    }
}
