#include "Sort.h"
#include <stdio.h> 
#include <time.h>
#include <stdlib.h>
#include <stdarg.h>
#include <algorithm>


Sort::Sort(int numar_elemente, int min_element, int max_element) {
	this->nr_elem = numar_elemente;
	vector = new int[numar_elemente];
	time_t t;
	srand((unsigned)time(&t));
	for (int i = 0; i < numar_elemente; i++) {
		this->vector[i] = min_element + rand() % (min_element - max_element + 1);
	}

}
Sort::Sort(int* v, int numar_elemente) {
	this->nr_elem = numar_elemente;
	vector = new int[numar_elemente];
	for (int i = 0; i < numar_elemente; i++) {
		this->vector[i] = v[i];
	}
}

Sort::Sort(int count, ...) {
	vector = new int[count];
	va_list vl;
	va_start(vl, count);
	this->nr_elem = count;
	for (int i = 0; i < count; i++)
	{
		this->vector[i] = va_arg(vl, int);
	}
	va_end(vl);
}

Sort::Sort(char* c) {
	vector = new int[strlen(c)];
	int i = 0, nr = 0, cnt = 0;
	while (c[i] != NULL)
	{
		if (c[i] >= '0' && c[i] <= '9')
			nr = nr * 10 + c[i] - '0';
		else
			if (c[i] == ',')
			{
				vector[cnt++] = nr;
				nr = 0;
			}
		i++;
	}
	if (nr != 0)
		vector[cnt++] = nr;
	this->nr_elem = cnt;
}
Sort::Sort(): vector(new int[6] {1, 2, 3, 4, 5, 6})  {
	this->nr_elem = 6;
}
Sort::~Sort()
{
	delete this->vector;
}
void Sort::InsertSort(bool ascendent)
{
	int aux, j = 0, i;
	for (i = 1; i < this->nr_elem; i++)
	{
		j = i - 1;
		aux = this->vector[i];
		while (j >= 0 && this->vector[j] > aux)
		{
			this->vector[j + 1] = this->vector[j];
			j = j - 1;
		}
		this->vector[j + 1] = aux;
	}
}
void Sort::QuickSortHelper(int minim, int maxim)
{
	if (minim < maxim)
	{
		int pivot = Partitie(minim, maxim);
		QuickSortHelper(minim, pivot - 1);
		QuickSortHelper(pivot + 1, maxim);
	}
}
int Sort::Partitie(int minim, int maxim)
{
	int i = minim + 1, j = maxim, k;
	int x = this->vector[minim];
	while (i <= j)
	{
		if (this->vector[i] <= x)
			i++;
		if (this->vector[j] >= x)
			j--;
		if (i<j && this->vector[i]>x && this->vector[j] < x)
		{
			int aux = this->vector[i];
			this->vector[i] = this->vector[j];
			this->vector[j] = aux;
			i++;
			j--;
		}
	}
	k = i - 1;
	this->vector[minim] = this->vector[k];
	this->vector[k] = x;
	return k;
}
void Sort::QuickSort(bool ascendent)
{
	QuickSortHelper(0, this->nr_elem - 1);
}

void Sort::BubbleSort(bool ascendent)
{
	int i, j;
	for (i = 0; i < this->nr_elem; i++)
	{
		for (j = i + 1; j < this->nr_elem; j++)
			if (this->vector[i] > this->vector[j])
			{
				int aux = this->vector[i];
				this->vector[i] = this->vector[j];
				this->vector[j] = aux;
			}
	}
}

void Sort::Print()
{
	for (int i = 0; i < this->nr_elem; i++)
	{
		printf("%d ", this->vector[i]);
	}
	printf("\n\n");
}

int Sort::GetElementsCount()
{
	int sum = 0;
	for (int i = 0; i < this->nr_elem; i++)
	{
		sum += this->vector[i];
	}
	return sum;
}

int Sort::GetElementFromIndex(int index)
{
	if (index > this->nr_elem)
		return -1;
	return this->vector[index];
}