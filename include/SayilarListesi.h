#ifndef SAYILARLISTESI_H
#define SAYILARLISTESI_H

#include "Sayi.h"

class Dugum {
public:
    Sayi* sayi;
    Dugum* sonraki;

    Dugum(Sayi* sayi); // Constructor
};

class SayilarListesi {
private:
    Dugum* bas;

public:
    SayilarListesi(); // Constructor
    void ekleSayi(int sayiDegeri);
    void yazdir();
    void tekBasamaklariBasaTasi();
    void sayilariTersCevir();
    void enBuyukSayiyiCikar();
    ~SayilarListesi(); // Destructor
};

#endif // SAYILARLISTESI_H
