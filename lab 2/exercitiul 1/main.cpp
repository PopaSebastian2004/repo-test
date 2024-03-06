#include "NumberList.h"
#include <stdio.h>
#include <iostream>
int main() {
    NumberList c1;
    c1.Init();
    c1.Add(5);
    c1.Add(8);
    c1.Add(9);
    c1.Add(1);
    c1.Sort();
    c1.Print();
    return 0;
}