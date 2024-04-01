
#include <iostream>
#include <cstring>

class Number {
private:
    char* value;
    int base;
    int size;

public:
    Number(const char* value, int base);
    Number(const Number& other);
    Number(Number&& other) noexcept;
    Number(int intValue, int base = 10);
    ~Number();

    Number& operator=(const Number& other);
    Number& operator=(Number&& other) noexcept;


    Number operator+(const Number& other) const;
    Number operator-(const Number& other) const;
    Number& operator=(int intValue);
    Number& operator=(const char * newValue);
    char& operator[](int index);
    bool operator>(const Number& other) const;
    bool operator<(const Number& other) const;
    bool operator>=(const Number& other) const;
    bool operator<=(const Number& other) const;
    bool operator==(const Number& other) const;
    bool operator!=(const Number& other) const;
    Number& operator+=(const Number& other);
    Number& operator-=(const Number& other);
    Number& operator--(); // Prefix --
    Number operator--(int); // Postfix --

    void SwitchBase(int newBase);
    void Print() const;
    int GetDigitsCount() const;
    int GetBase() const;
};