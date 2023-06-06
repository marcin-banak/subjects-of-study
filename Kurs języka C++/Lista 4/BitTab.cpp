#include "BitTab.h"

// Funkcja pomocnicza zliczająca bity.
int CountBits(int x)
{
    int count = 0;
    while (x > 0)
    {
        x /= 2;
        count++;
    }
    return count;
}
// Klasa Referencji na słowo.
class BitTab::Reference {
public:
    Word *word;
    int index;

    Reference(Word *word, int index) {
        this->word = word;
        this->index = index;
    }

    Word *operator=(bool val) {
        if (this->index >= 64)
            printf("Bledny index!\n");
        else if (val) {
            *this->word |= (1ull << this->index);
        } else {
            *this->word &= ~(1ull << this->index);
        }
        return this->word;
    }

    bool operator==(bool val) {
        int mask = 1 << this->index;
        int masked_n = *this->word & mask;
        bool bit = masked_n >> this->index;
        return bit == val;
    }
};

BitTab::BitTab(int size) {
    int WordQuantity = (size + this->WordsLength - 1) / this->WordsLength;
    this->BitWords = new Word[WordQuantity];
    this->BitsCount = 0;
    this->Size = size;
    for (int i = 0; i < WordQuantity; i++) {
        this->BitWords[i] = 0;
    }
}

BitTab::BitTab(Word word) {
    this->BitWords = new Word[1];
    *this->BitWords = word;
    this->BitsCount = CountBits(word);
    this->Size = this->WordsLength - 1;
}

BitTab::BitTab(const BitTab &tb) {
    this->BitWords = new Word[(tb.Size + this->WordsLength - 1) / this->WordsLength];
    this->BitsCount = 0;
    this->Size = tb.Size;
    for (int i = 0; i < (tb.Size + this->WordsLength - 1) / this->WordsLength; i++) {
        this->BitWords[i] = Word(tb.BitWords[i]);
    }
}

BitTab::BitTab(BitTab &&tb) {
    this->BitWords = tb.BitWords;
    tb.BitWords = nullptr;
    this->BitsCount = tb.BitsCount;
    this->Size = tb.Size;
}

BitTab::BitTab(std::initializer_list<bool> l) : BitTab((int)l.size())
{
    int i = 0;
    for (bool x : l)
    {
        ChangeBit(i++, x);
        this->BitsCount++;
    }
}

BitTab &BitTab::operator=(const BitTab &tb) {
    for (int i = 0; i < (tb.Size + this->WordsLength - 1) / this->WordsLength; i++) {
        this->BitWords[i] = Word(tb.BitWords[i]);
    }
    return *this;
}

BitTab &BitTab::operator=(BitTab &&tb) {
    this->BitWords = tb.BitWords;
    return *this;
}

BitTab::~BitTab() {
    delete[] this->BitWords;
}

bool BitTab::GetBit(int index) const {
    Word word = *(this->BitWords + (index / this->WordsLength));
    index %= this->WordsLength;
    word >>= index;

    return word & 1;
}

void BitTab::ChangeBit(int index, bool val) {
    BitTab::Reference *ref = new BitTab::Reference(this->BitWords + (index / this->WordsLength), index);
    *ref = val;
}

istream &operator>>(istream &inp, BitTab &bitwords) {
    if (bitwords.Size < bitwords.BitsCount)
        throw std::invalid_argument("Nie mozna wczytac wiecej bitow!\n");

    BitTab::Reference *ref = new BitTab::Reference(bitwords.BitWords + (bitwords.BitsCount / bitwords.WordsLength),
                                                   bitwords.BitsCount);

    int bit;
    inp >> bit;
    if (bit != 0)
        bit = 1;
    else
        bit = 0;

    *ref = bit;
    bitwords.BitsCount++;

    return inp;
}

ostream &operator<<(ostream &out, BitTab &bitwords) {
    bitwords.BitsCount--;
    if (bitwords.BitsCount < 0)
        throw std::invalid_argument("Brak bitow do wypisania!\n");
    out << bitwords.GetBit(bitwords.BitsCount);

    return out;
}

bool BitTab::operator[](int index) const {
    return this->GetBit(index);
}

/*BitTab::Reference BitTab::operator[] (int index)
{
    return BitTab::Reference(this->BitWords + (index / this->WordsLength), index);
}*/

int BitTab::size() const {
    return this->BitsCount;
}

BitTab &BitTab::operator|(const BitTab &tb) {
    BitTab aux = BitTab(*this);
    for (int i = 0; i < min(this->Size, tb.Size) / this->WordsLength; i++) {
        aux.BitWords[i] |= tb.BitWords[i];
    }
    return *new BitTab(aux);
}

BitTab &BitTab::operator|=(const BitTab &tb) {
    for (int i = 0; i < (min(this->Size, tb.Size) / this->WordsLength); i++) {
        this->BitWords[i] |= tb.BitWords[i];
    }
    return *this;
}

BitTab &BitTab::operator&(const BitTab &tb) {
    BitTab aux = BitTab(*this);
    for (int i = 0; i < min(this->Size, tb.Size) / this->WordsLength; i++) {
        aux.BitWords[i] &= tb.BitWords[i];
    }
    return *new BitTab(aux);
}

BitTab &BitTab::operator&=(const BitTab &tb) {
    for (int i = 0; i < min(this->Size, tb.Size) / this->WordsLength; i++) {
        this->BitWords[i] &= tb.BitWords[i];
    }
    return *this;
}

BitTab &BitTab::operator^(const BitTab &tb) {
    BitTab aux = BitTab(*this);
    for (int i = 0; i < min(this->Size, tb.Size) / this->WordsLength; i++) {
        aux.BitWords[i] ^= tb.BitWords[i];
    }
    return *new BitTab(aux);
}

BitTab &BitTab::operator^=(const BitTab &tb) {
    for (int i = 0; i < min(this->Size, tb.Size) / this->WordsLength; i++) {
        this->BitWords[i] ^= tb.BitWords[i];
    }
    return *this;
}

BitTab &BitTab::operator!() {
    for (int i = 0; i < this->Size / this->WordsLength; i++)
    {
        this->BitWords[i] = ~this->BitWords[i];
    }
    return *this;
}