#ifndef SAYI_H
#define SAYI_H

#include "Basamak.h"
#include <string>

class Sayi {
private:
    Basamak* bas; // Listenin başını gösteren pointer

public:
    Sayi(); // Boş constructor
    void sayiyiOlustur(int sayi);
    void ekleBasamak(int deger);
    void yazdir();
    std::string sayiDegeriniAl() const;
    void tekBasamaklariBasaTasi();
    void sayiyiTersCevir();
    int getSayiDegeri();
    ~Sayi(); // Destructor
};

#endif // SAYI_H
