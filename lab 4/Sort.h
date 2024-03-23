#pragma once
class Sort
{
	int* vector, nr_elem  ;
public:
	Sort();
	Sort(int numar_elemente, int min_element, int max_element);
	Sort(int* v, int numar_elemente);
	Sort(int count, ...);
	Sort(char* c);
	~Sort();
	int Partitie(int minim, int maxim);
	void QuickSortHelper(int minim, int maxim);
	void InsertSort(bool ascendent = false);
	void QuickSort(bool ascendent = false);
	void BubbleSort(bool ascendent = false);
	void Print();
	int  GetElementsCount();
	int  GetElementFromIndex(int index);
};
