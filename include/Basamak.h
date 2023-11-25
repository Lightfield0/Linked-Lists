#ifndef BASAMAK_H
#define BASAMAK_H

class Basamak {
private:
    int deger; // Basamağın değeri
    Basamak* sonraki; // Sonraki basamağa işaret eden pointer

public:
    Basamak(int deger);
    int getDeger() const;
    void setDeger(int deger);
    Basamak* getSonraki() const;
    void setSonraki(Basamak* sonraki);
};

#endif // BASAMAK_H
