#include "MovieSeries.h"
#include "Movie.h"
void MovieSeries::init()
{
	this->count = 0;
}

void MovieSeries::add(Movie * obiectul1)
{
	list[count++] = obiectul1;
}

void MovieSeries::sort()
{
	int i, j;
	for (i = 0; i < count - 1; i++)
	{
		for (j = i + 1; j < count; j++)
		{
			if (list[i]->get_passed_years() < list[j]->get_passed_years())
			{
				Movie * aux;
				aux = list[i];
				list[i] = list[j];
				list[j] = aux;
			}
		}

	}
}

void MovieSeries::print()
{
	int i;
	for (i = 0; i < count; i++)
	{
		printf("Numele filmului este : %s\n", list[i]->get_name());
		printf("Anul aparitiei este : %d\n", list[i]->get_year());
		printf("Durata filmului este : %d\n", list[i]->get_length());
		printf("Scorul obtinut este : %lf\n", list[i]->get_score());
		printf("Numarul de ani al filmului este : %d\n", list[i]->get_passed_years());
		printf("\n\n");
	}
}
