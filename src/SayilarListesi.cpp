#include "SayilarListesi.h"
#include <iostream>

SayilarListesi::SayilarListesi() : bas(nullptr) {}

Dugum::Dugum(Sayi* sayi) : sayi(sayi), sonraki(nullptr) {}

void SayilarListesi::ekleSayi(int sayiDegeri) {
    Sayi* yeniSayi = new Sayi();
    yeniSayi->sayiyiOlustur(sayiDegeri);

    Dugum* yeniDugum = new Dugum(yeniSayi);
    yeniDugum->sonraki = bas;
    bas = yeniDugum;
}

void SayilarListesi::yazdir() {
    Dugum* gecici = bas;
    while (gecici != nullptr) {
        gecici->sayi->yazdir();
        gecici = gecici->sonraki;
    }
}

void SayilarListesi::tekBasamaklariBasaTasi() {
    Dugum* gecici = bas;
    while (gecici != nullptr) {
        gecici->sayi->tekBasamaklariBasaTasi();
        gecici = gecici->sonraki;
    }
}

void SayilarListesi::sayilariTersCevir() {
    Dugum* gecici = bas;
    while (gecici != nullptr) {
        gecici->sayi->sayiyiTersCevir();
        gecici = gecici->sonraki;
    }
}

void SayilarListesi::enBuyukSayiyiCikar() {
    if (bas == nullptr) return; // Liste boşsa çık

    Dugum* gecici = bas;
    Dugum* enBuyukOnceki = nullptr;
    Dugum* enBuyuk = bas;
    int enBuyukDeger = bas->sayi->getSayiDegeri();

    while (gecici->sonraki != nullptr) {
        if (gecici->sonraki->sayi->getSayiDegeri() > enBuyukDeger) {
            enBuyukDeger = gecici->sonraki->sayi->getSayiDegeri();
            enBuyukOnceki = gecici;
            enBuyuk = gecici->sonraki;
        }
        gecici = gecici->sonraki;
    }

    if (enBuyukOnceki != nullptr) {
        enBuyukOnceki->sonraki = enBuyuk->sonraki;
    } else {
        bas = enBuyuk->sonraki;
    }

    delete enBuyuk->sayi;
    delete enBuyuk;
}

SayilarListesi::~SayilarListesi() {
    Dugum* gecici;
    while (bas != nullptr) {
        gecici = bas;
        bas = bas->sonraki;
        delete gecici->sayi;
        delete gecici;
    }
}
