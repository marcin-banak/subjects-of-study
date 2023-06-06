#ifndef INC_4_LISTA_CPP_BITTAB_H
#define INC_4_LISTA_CPP_BITTAB_H

#include <iostream>

using namespace std;

class BitTab {
    typedef uint64_t Word; // komorka w tablicy
    static const int WordsLength = 64; // rozmiar slowa w bitach
    int Size; // maksymalna ilość przechowywanych bitów
    class Reference; // klasa pomocnicza do adresowania bitów
protected:
    int BitsCount; // liczba bitów
    Word *BitWords; // tablica bitów
public:
    explicit BitTab(int size); // wyzerowana tablica bitow [0...rozm]
    explicit BitTab(Word word); // tablica bitów [0...rozmiarSlowa] zainicjalizowana wzorcem
    BitTab(const BitTab &tb); // konstruktor kopiujący
    BitTab(BitTab &&tb); // konstruktor przenoszący
    BitTab(std::initializer_list<bool> l);
    BitTab &operator=(const BitTab &tb); // przypisanie kopiujące
    BitTab &operator=(BitTab &&tb); // przypisanie przenoszące
    ~BitTab(); // destruktor
private:
    bool GetBit(int index) const; // metoda pomocnicza do odczytu bitu
    void ChangeBit(int index, bool val); // metoda pomocnicza do zapisu bitu
public:
    bool operator[](int index) const; // indeksowanie dla stałych tablic bitowych
    //Reference operator[] (int index); // indeksowanie dla zwykłych tablic bitowych
    int size() const; // rozmiar tablicy w bitach
public:
// operatory bitowe: ^ i ^= oraz !
    BitTab &operator|(const BitTab &tb);
    BitTab &operator|=(const BitTab &tb);
    BitTab &operator&(const BitTab &tb);
    BitTab &operator&=(const BitTab &tb);
    BitTab &operator^(const BitTab &tb);
    BitTab &operator^=(const BitTab &tb);
    BitTab &operator!();

public:
// zaprzyjaźnione operatory strumieniowe: << i >>
    friend istream &operator>>(istream &inp, BitTab &tb);
    friend ostream &operator<<(ostream &out, BitTab &tb);
};

#endif
