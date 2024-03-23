#include "Sort.h"
#include <stdlib.h>
#include <iostream>
int main() {
	Sort c1(10, 10, 100);
	int v[5] = { 1, 2, 3, 4, 5 };
	Sort c2(v, 5);
	Sort c3(6, 1, 2, 3, 4, 5, 6);
	char c[] = "12,34,6,1008";
	Sort c4(c);
	Sort c5();
	c1.QuickSort();
	c1.Print();
	c1.InsertSort();
	c1.Print();
	c1.BubbleSort();
	c1.Print();
	printf("Suma elementelor este :%d ", c1.GetElementsCount());
	system("pause");
	return 0;
}