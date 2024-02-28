#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
	FILE* fp;
	int sum = 0;
	if (fopen_s(&fp, "in.txt", "r") != 0)
	{
		printf("Eroare. Nu am putut deschide fisierul\n");
	}
	else {
		printf("Am deschis fisierul cu success!\n");
		char sir[200];
		while (fgets(sir, 200, fp))
		{
			sir[strlen(sir)] = '\0';
			int lg = strlen(sir)-1;
			int nr = 0;
			for(int i=0;i<=lg;i++)
			{
				if (sir[i] - '0' >= 0 && sir[i] - '0' <= 9)
					nr = nr * 10 + sir[i] - '0';
			}
			sum += nr;
		}
	}
	printf("Suma numerelor este: %d\n", sum);
	printf("\n\n");
	system("pause");
	return 0;
}