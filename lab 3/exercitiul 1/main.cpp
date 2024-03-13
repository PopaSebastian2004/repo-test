#include "Math.h"
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
int main() {
    int a = 4,b = 5,c=6;
    double e = 5.7, f = 6.7 ,g=7.7;
    const char* s = { "1464" }, * t = { "100765000" };
    printf("%d\n", Math::Add(a, b));
    printf("%d\n", Math::Add(a, b,c));
    printf("%d\n", Math::Add(e, f));
    printf("%d\n", Math::Add(e, f, g));
    printf("%d\n", Math::Mul(a, b));
    printf("%d\n", Math::Mul(a, b, c));
    printf("%d\n", Math::Mul(a, b));
    printf("%d\n", Math::Mul(a, b, c));
    printf("%s\n", Math::Add(s, t));
    printf("%d\n", Math::Add(5,2,3,4,2,2));
    system("pause");
    return 0;
}