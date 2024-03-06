#include "NumberList.h"
#include <stdio.h>
void NumberList::Init()
{
	this->count = 0;
}

bool NumberList::Add(int x)
{
	if(count>=10 )
	  return false;
	else
	{
		numbers[count++] = x;
	}
}

void NumberList::Sort()
{
	int i, j;
	for (i = 0; i < count; i++)
	{
		for (j = i + 1; j < count; j++)
		{
			if (numbers[i] > numbers[j])
			{
				int aux = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = aux;
			}
		}
	}
}

void NumberList::Print()
{
	for (int i = 0; i < count; i++)
	{
		printf("%d ", numbers[i]);
	}
}
