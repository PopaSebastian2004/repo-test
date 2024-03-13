#include "Math.h"
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <stdarg.h>
int Math::Add(int a, int b)
{
	return a + b;
}

int Math::Add(int a, int b, int c)
{
	return a + b + c;
}

int Math::Add(double a, double b)
{
	return (int)  (a + b);
}

int Math::Add(double a, double b , double c)
{
	return (int) (a+b+c);
}

int Math::Mul(int a, int b)
{
	return a*b;
}

int Math::Mul(int a, int b, int c)
{
	return a*b*c;
}

int Math::Mul(double a, double b)
{
	return  (int) (a*b);
}

int Math::Mul(double a, double b, double c)
{
	return (int) (a*b*c);
}

int Math::Add(int count, ...)
{
	int rez = 0,i;
	va_list Nums;
	va_start(Nums, count);
	for (i = 0; i < count; i++)
	{
		int x = va_arg(Nums, int);
		rez += x;
	}
	va_end(Nums);
	return rez;
}



char* Math::Add(const char* a, const char* b)
{
	int lga = 0, lgb = 0, lgc = 0,i,aux;
	for (i = 0; a[i]; i++)
		lga++;
	for (i = 0; b[i]; i++)
		lgb++;
	if (lga > lgb)
		lgc = lga ;
	else
	{
		lgc = lgb ;
	}
	char* s = new char[lgc + 1];
	int t = 0;
	int k, j;
	i = lga-1;
	j = lgb - 1;
	int cnt=0;
	for (k = 0; k<lgc ;k++)
	{
		aux = 0;
		if (i>=0)
		{
			aux += a[i] - '0';
			i--;
		}
		if (j>=0)
		{
			aux += b[j] - '0';
			j--;
		}
		aux += t;
		s[cnt++] = (aux % 10) + '0';
		t = aux /10;
	}
	if (t)
	{
		s[cnt++] = t;
	}
	for (i = 0; i < cnt/ 2; i++)
	{
		char help = s[i];
		s[i] = s[cnt - i - 1];
		s[cnt - i - 1] = help;
	
	}
	s[cnt] = 0;
	return s;
}
