#include "Number.h"
#include <algorithm>
#ifdef _MSC_VER
#pragma warning (disable: 4996) // 'This function or variable may be unsafe': strcpy, sscanf, strcat
#endif
Number::Number(const char* value, int base) : base(base) {
    size = strlen(value);
    this->value = new char[size + 1];
    strcpy(this->value, value);
}
Number& Number::operator=(int intValue) {
    // Convert the integer value to its string representation in the current base
    int index = 0,copie=intValue;
    while(intValue)
    {
        index++;
        intValue = intValue / base;
    }
    int r;
    char* newRez = new char[index];
    index = 0;
    while (copie)
    {
        r = copie % base;
        if (r >= 10)
            newRez[index] = r-'A'+10;
        else
            newRez[index] = r + '0';
        copie = copie / base;
        index++;
    }
    char aux;
    for (int i = 0; i < index/2; i++)
    {
        aux = newRez[i];
         newRez[i]= newRez[index - i - 1];
         newRez[index - i - 1] = aux;
    }
    newRez[index] = '\0';
    strcpy(value, newRez);
    return *this;
}
Number& Number::operator=(const char * newValue)
{
    int index = 0, i=0,nr=0;
    while (newValue[i])
    {
        index++;
        nr = nr * 10 + (newValue[i] - '0');
        i++;
    }
    int r;
    char* newRez = new char[index];
    index = 0;
    int copie = nr;
    while (copie)
    {
        r = copie % base;
        if (r >= 10)
            newRez[index] = r - 'A' + 10;
        else
            newRez[index] = r + '0';
        copie = copie / base;
        index++;
    }
    char aux;
    for (int i = 0; i < index / 2; i++)
    {
        aux = newRez[i];
        newRez[i] = newRez[index - i - 1];
        newRez[index - i - 1] = aux;
    }
    newRez[index] = '\0';
    strcpy(value, newRez);
    return *this;
}
Number::Number(const Number& other) : base(other.base), size(other.size) {
    value = new char[size + 1];
    strcpy(value, other.value);
}

Number::Number(Number&& other) noexcept : value(other.value), base(other.base), size(other.size) {
    other.value = nullptr;
    other.size = 0;
}

Number::~Number() {
    delete[] value;
}

Number& Number::operator=(const Number& other) {
    if (this != &other) {
        delete[] value;
        base = other.base;
        size = other.size;
        value = new char[size + 1];
        strcpy(value, other.value);
    }
    return *this;
}

Number& Number::operator=(Number&& other) noexcept {
    if (this != &other) {
        delete[] value;
        value = other.value;
        base = other.base;
        size = other.size;
        other.value = nullptr;
        other.size = 0;
    }
    return *this;
}
Number& Number::operator-=(const Number& other) {
    int newBase = std::max(base, other.base);
    int val1 = 0, i, putere = 1;
    int val2 = 0;
    int lg1 = strlen(value);
    int lg2 = strlen(other.value);
    for (i = lg1 - 1; i >= 0; i--)
    {
        if (value[i] > 'A' && value[i] < 'F')
            val1 += (value[i] - 'A' + 10) * putere;
        else
            val1 += (value[i] - '0') * putere;
        putere = putere * base;
    }
    putere = 1;
    for (i = lg2 - 1; i >= 0; i--)
    {
        if (other.value[i] > 'A' && other.value[i] < 'F')
            val2 += (other.value[i] - 'A' + 10) * putere;
        else
            val2 += (other.value[i] - '0') * putere;
        putere = putere * other.base;
    }
    val1 -= val2;
    int copie = val1;
    int index = 0, r;
    while (copie)
    {
        index++;
        copie = copie / newBase;
    }
    char* newRez = new char[index];
    index = 0;
    newRez[index] = '\0';
    while (val1)
    {
        r = val1 % newBase;
        if (r >= 10)
        {
            newRez[index] = (char)('A' + r - 10);
        }
        else
            newRez[index] = (char)('0' + r);
        index++;
        val1 = val1 / newBase;
    }
    newRez[index] = '\0';
    for (i = 0; i < index / 2; i++)
    {
        char aux;
        aux = newRez[i];
        newRez[i] = newRez[index - i - 1];
        newRez[index - i - 1] = aux;
    }
    base = newBase;
    strcpy(value, newRez);
    return (*this);
}
Number& Number::operator+=(const Number& other) {
    int newBase = std::max(base, other.base);
    int val1 = 0, i, putere = 1;
    int val2 = 0;
    int lg1 = strlen(value);
    int lg2 = strlen(other.value);
    for (i = lg1 - 1; i >= 0; i--)
    {
        if (value[i] > 'A' && value[i] < 'F')
            val1 += (value[i] - 'A' + 10) * putere;
        else
            val1 += (value[i] - '0') * putere;
        putere = putere * base;
    }
    putere = 1;
    for (i = lg2 - 1; i >= 0; i--)
    {
        if (other.value[i] > 'A' && other.value[i] < 'F')
            val2 += (other.value[i] - 'A' + 10) * putere;
        else
            val2 += (other.value[i] - '0') * putere;
        putere = putere * other.base;
    }
    val1 += val2;
    int copie = val1;
    int index = 0, r;
    while (copie)
    {
        index++;
        copie = copie / newBase;
    }
    char* newRez = new char[index];
    index = 0;
    newRez[index] = '\0';
    while (val1)
    {
        r = val1 % newBase;
        if (r >= 10)
        {
            newRez[index] = (char)('A' + r - 10);
        }
        else
            newRez[index] = (char)('0' + r);
        index++;
        val1 = val1 / newBase;
    }
    newRez[index] = '\0';
    for (i = 0; i < index / 2; i++)
    {
        char aux;
        aux = newRez[i];
        newRez[i] = newRez[index - i - 1];
        newRez[index - i - 1] = aux;
    }
    base = newBase;
    strcpy(value, newRez);
    return (*this);
}

Number Number::operator+(const Number& other) const {
    int newBase = std::max(base, other.base);
    int val1 = 0, i, putere = 1;
    int val2 = 0;
    int lg1 = strlen(value);
    int lg2 = strlen(other.value);
    for (i = lg1-1; i >= 0; i--)
    {
        if (value[i] > 'A' && value[i] < 'F')
            val1 += (value[i] - 'A' + 10) * putere;
        else
            val1 += (value[i] - '0') * putere;
        putere = putere * base;
    }
    putere = 1;
    for (i = lg2-1; i >= 0; i--)
    {
        if (other.value[i] > 'A' && other.value[i] < 'F')
            val2 += (other.value[i] - 'A' + 10) * putere;
        else
            val2 += (other.value[i] - '0') * putere;
        putere = putere * other.base;
    }
    val1 += val2;
    int copie = val1;
    int index = 0, r;
    while (copie)
    {
        index++;
        copie = copie / newBase;
    }
    char* newRez = new char[index];
    index = 0;
    newRez[index] = '\0';
    while (val1)
    {
        r = val1 % newBase;
        if (r >= 10)
        {
            newRez[index] = (char)('A' + r - 10);
        }
        else
            newRez[index] = (char)('0' + r);
        index++;
        val1 = val1 / newBase;
    }
    newRez[index] = '\0';
    for (i = 0; i < index / 2; i++)
    {
        char aux;
        aux = newRez[i];
        newRez[i] = newRez[index - i - 1];
        newRez[index - i - 1] = aux;
    }
    return Number(newRez, newBase);
}

Number Number::operator-(const Number& other) const {
    int newBase = std::max(base, other.base);
    int val1 = 0, i, putere = 1;
    int val2 = 0;
    int lg1 = strlen(value);
    int lg2 = strlen(other.value);
    for (i = lg1 - 1; i >= 0; i--)
    {
        if (value[i] > 'A' && value[i] < 'F')
            val1 += (value[i] - 'A' + 10) * putere;
        else
            val1 += (value[i] - '0') * putere;
        putere = putere * base;
    }
    putere = 1;
    for (i = lg2 - 1; i >= 0; i--)
    {
        if (other.value[i] > 'A' && other.value[i] < 'F')
            val2 += (other.value[i] - 'A' + 10) * putere;
        else
            val2 += (other.value[i] - '0') * putere;
        putere = putere * other.base;
    }
    val1 -= val2;
    int copie = val1;
    int index = 0, r;
    while (copie)
    {
        index++;
        copie = copie / newBase;
    }
    char* newRez = new char[index];
    index = 0;
    newRez[index] = '\0';
    while (val1)
    {
        r = val1 % newBase;
        if (r >= 10)
        {
            newRez[index] = (char)('A' + r - 10);
        }
        else
            newRez[index] = (char)('0' + r);
        index++;
        val1 = val1 / newBase;
    }
    newRez[index] = '\0';
    for (i = 0; i < index / 2; i++)
    {
        char aux;
        aux = newRez[i];
        newRez[i] = newRez[index - i - 1];
        newRez[index - i - 1] = aux;
    }
    return Number(newRez, newBase);
}

char& Number::operator[](int index) {
    if (index >= 0 && index < size)
        return value[index];
    else
        throw std::out_of_range("Index out of range");
}

bool Number::operator>(const Number& other) const {
    int val1 = 0, i, putere = 1;
    int val2 = 0;
    int lg1 = strlen(value);
    int lg2 = strlen(other.value);
    for (i = lg1 - 1; i >= 0; i--)
    {
        if (value[i] > 'A' && value[i] < 'F')
            val1 += (value[i] - 'A' + 10) * putere;
        else
            val1 += (value[i] - '0') * putere;
        putere = putere * base;
    }
    putere = 1;
    for (i = lg2 - 1; i >= 0; i--)
    {
        if (other.value[i] > 'A' && other.value[i] < 'F')
            val2 += (other.value[i] - 'A' + 10) * putere;
        else
            val2 += (other.value[i] - '0') * putere;
        putere = putere * other.base;
    }
    return (val1>val2);
}

bool Number::operator<(const Number& other) const {
    
    int val1 = 0, i, putere = 1;
    int val2 = 0;
    int lg1 = strlen(value);
    int lg2 = strlen(other.value);
    for (i = lg1 - 1; i >= 0; i--)
    {
        if (value[i] > 'A' && value[i] < 'F')
            val1 += (value[i] - 'A' + 10) * putere;
        else
            val1 += (value[i] - '0') * putere;
        putere = putere * base;
    }
    putere = 1;
    for (i = lg2 - 1; i >= 0; i--)
    {
        if (other.value[i] > 'A' && other.value[i] < 'F')
            val2 += (other.value[i] - 'A' + 10) * putere;
        else
            val2 += (other.value[i] - '0') * putere;
        putere = putere * other.base;
    }
    return (val1 < val2);
}

bool Number::operator>=(const Number& other) const {
    int val1 = 0, i, putere = 1;
    int val2 = 0;
    int lg1 = strlen(value);
    int lg2 = strlen(other.value);
    for (i = lg1 - 1; i >= 0; i--)
    {
        if (value[i] > 'A' && value[i] < 'F')
            val1 += (value[i] - 'A' + 10) * putere;
        else
            val1 += (value[i] - '0') * putere;
        putere = putere * base;
    }
    putere = 1;
    for (i = lg2 - 1; i >= 0; i--)
    {
        if (other.value[i] > 'A' && other.value[i] < 'F')
            val2 += (other.value[i] - 'A' + 10) * putere;
        else
            val2 += (other.value[i] - '0') * putere;
        putere = putere * other.base;
    }
    return (val1 >= val2);
}

bool Number::operator<=(const Number& other) const {
    int val1 = 0, i, putere = 1;
    int val2 = 0;
    int lg1 = strlen(value);
    int lg2 = strlen(other.value);
    for (i = lg1 - 1; i >= 0; i--)
    {
        if (value[i] > 'A' && value[i] < 'F')
            val1 += (value[i] - 'A' + 10) * putere;
        else
            val1 += (value[i] - '0') * putere;
        putere = putere * base;
    }
    putere = 1;
    for (i = lg2 - 1; i >= 0; i--)
    {
        if (other.value[i] > 'A' && other.value[i] < 'F')
            val2 += (other.value[i] - 'A' + 10) * putere;
        else
            val2 += (other.value[i] - '0') * putere;
        putere = putere * other.base;
    }
    return (val1 <= val2);
}

bool Number::operator==(const Number& other) const {
    int val1 = 0, i, putere = 1;
    int val2 = 0;
    int lg1 = strlen(value);
    int lg2 = strlen(other.value);
    for (i = lg1 - 1; i >= 0; i--)
    {
        if (value[i] > 'A' && value[i] < 'F')
            val1 += (value[i] - 'A' + 10) * putere;
        else
            val1 += (value[i] - '0') * putere;
        putere = putere * base;
    }
    putere = 1;
    for (i = lg2 - 1; i >= 0; i--)
    {
        if (other.value[i] > 'A' && other.value[i] < 'F')
            val2 += (other.value[i] - 'A' + 10) * putere;
        else
            val2 += (other.value[i] - '0') * putere;
        putere = putere * other.base;
    }
    return (val1 == val2);
}
bool Number::operator!=(const Number& other) const {
    int val1 = 0, i, putere = 1;
    int val2 = 0;
    int lg1 = strlen(value);
    int lg2 = strlen(other.value);
    for (i = lg1 - 1; i >= 0; i--)
    {
        if (value[i] > 'A' && value[i] < 'F')
            val1 += (value[i] - 'A' + 10) * putere;
        else
            val1 += (value[i] - '0') * putere;
        putere = putere * base;
    }
    putere = 1;
    for (i = lg2 - 1; i >= 0; i--)
    {
        if (other.value[i] > 'A' && other.value[i] < 'F')
            val2 += (other.value[i] - 'A' + 10) * putere;
        else
            val2 += (other.value[i] - '0') * putere;
        putere = putere * other.base;
    }
    return (val1 != val2);
}


Number& Number::operator--() {
    int i = 0,aux=0;
    char * newValue = new char[10];
    for (i = 1; value[i]!='\0'; i++)
    {
        newValue[aux++] = value[i];
    }
    newValue[aux] = '\0';
    strcpy(value, newValue);
    return (*this);
}

Number Number::operator--(int) {
    value[strlen(value) - 1] = '\0';
    return (*this);
}

void Number::SwitchBase(int newBase) {
    int i,sum=0,putere=1;
    for (i = this->size - 1; i >= 0; i--)
    {
        if (value[i] >= 'A' && value[i] <= 'F')
            sum += (value[i] - 'A' + 10) * putere;
        else
            sum += (value[i] - '0') * putere;
        putere=putere*this->base;
    }
    int copie = sum,index=0,r;
    while (sum)
    {
        index++;
        sum = sum / newBase;
    }
    delete[] value;
    value = new char[index];
   sum = copie;
   index=0;
   while (sum)
   {
       r = sum % newBase;
       if (r >= 10)
           value[index] = 'A' + r - 10;
       else
           value[index] = '0' + r;
       index++;
       sum = sum / newBase;
   }
   for (i = 0; i < index / 2; i++)
   {
       char aux;
       aux = value[i];
       value[i] = value[index - i - 1];
       value[index - i - 1] = aux;
   }
   value[index] = '\0';
   base = newBase;
}
Number::Number(int intValue, int base) : base(base) {
    
    int index = 0,copie=intValue;
    while (intValue)
    {
        index++;
        intValue = intValue / 10;
    }
    char* newRez = new char[index];
    index = 0;
    while (copie>0) {
        newRez[index] = copie % 10 + '0';
        copie = copie / 10;
        index++;
    }
   
    size = index;
    value = new char[index];
    strcpy(value,newRez);
}
void Number::Print() const {
    std::cout << value << " (Base " << base << ")" << std::endl;
}

int Number::GetDigitsCount() const {
    int index = 0;
    while (value[index])
          index++;
    return index;
}

int Number::GetBase() const {
    return base;
}