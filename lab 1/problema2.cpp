//#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct cuv
{
	char nume[25];
	int lg;
};

cuv cuvant[200];
void QuickSort(cuv v[], int st, int dr);
int comparare(cuv a, cuv b);
int main()
{
	printf("Introduceti numarul de cuvinte din propozitie: ");
	int numarCuvinte;
	scanf_s("%d", &numarCuvinte, 4);
	printf("Introduceti o propozitie: ");
	int cnt = 0;
	while (scanf_s("%19s", cuvant[cnt].nume, 19))
	{
		int i = 0;
		while (cuvant[cnt].nume[i] >= 'A' && cuvant[cnt].nume[i] <= 'z')
		{
			cuvant[cnt].lg++;
			i++;
		}
		cnt++;
		if (cnt >= numarCuvinte)
		{
			QuickSort(cuvant, 0, cnt - 1);
			for (int j = cnt-1; j >=0; j--)
			{
				int k = j-1;
				while (cuvant[j].lg == cuvant[k].lg && k >= 0)
				{
					int rez=comparare(cuvant[j], cuvant[k]);
					if (rez == 1)
						swap(cuvant[j], cuvant[k]);
					k--;
				}
				printf("%s", cuvant[j].nume);
				printf("\n");
			}
			break;
		}
	}
	system("pause");
	return 0;
}
void QuickSort(cuv v[], int st, int dr)
{
	if (st < dr)
	{
		int m = (st + dr) / 2;
		cuv aux = v[st];
		v[st] = v[m];
		v[m] = aux;
		int i = st, j = dr, d = 0;
		while (i < j)
		{
			if (v[i].lg > v[j].lg)
			{
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;
				d = 1 - d;
			}
			i += d;
			j -= 1 - d;
		}
		QuickSort(v, st, i - 1);
		QuickSort(v, i + 1, dr);
	}
}
int comparare(cuv a, cuv b)
{
	int i = 0;
	while (a.nume[i] == b.nume[i] && a.nume[i] >= 'A' && a.nume[i] <= 'z')
	{
		i++;
	}
	if (a.nume[i] != b.nume[i])
	{
		if (a.nume[i] - 'A' > b.nume[i] - 'A')
			return 1;
		else
			return 0;
	}
	return 0;
}