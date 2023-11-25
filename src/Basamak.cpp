#include "Basamak.h"
#include <sstream>
#include <iostream>
#include <iomanip>

Basamak::Basamak(int deger) : deger(deger), sonraki(nullptr) {}

int Basamak::getDeger() const {
    return deger;
}

void Basamak::setDeger(int deger) {
    this->deger = deger;
}

Basamak* Basamak::getSonraki() const {
    return sonraki;
}

void Basamak::setSonraki(Basamak* sonraki) {
    this->sonraki = sonraki;
}
