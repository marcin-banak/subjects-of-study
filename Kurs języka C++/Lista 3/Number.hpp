#ifndef NUMBER_HPP
#define NUMBER_HPP

class Number
{
private:
    // Pola
    static const int max_size = 5;
    double* base;
    double* current;
    double* first;
public:
    // Konstruktory
    Number();
    Number(double val);
    Number(Number* temp);
    Number(Number &&temp);

    // Destruktor
    ~Number();

    // Metody
    double Pop();
    void Push(double val);
    int GetMaxSize();
    double* GetBase();
    double* GetCurrent();

    // Operatory
    void operator =(Number &&);
};

#endif