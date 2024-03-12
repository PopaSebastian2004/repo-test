#include "Globals.h"
#include <stdio.h>
#include <cstring>
//daca avem *, folosim ->
//daca avem normal, folosim .

int MyCompareName(Movie* obiectul1, Movie* obiectul2) {
	const char* name1;
	const char* name2;
	name1 = obiectul1->get_name();
	name2 = obiectul2->get_name();
	int i;
	int length = strlen(name1);
	for (i = 0; name1[i] - 'A' == name2[i] - 'A' && i < length; i++);
	if (name1[i] - 'A' > name2[i] - 'A')
		return 1;
	else if (name1[i] - 'A' < name2[i] - 'A')
		return -1;
	else
		return 0;
}

int MyCompareYear(Movie* obiectul1, Movie* obiectul2)
{
	if (obiectul1->get_year() > obiectul2->get_year())
		return 1;
	if (obiectul1->get_year() == obiectul2->get_year())
		return 0;
	if (obiectul1->get_year() < obiectul2->get_year())
		return -1;
}
int MyCompareScore(Movie* obiectul1, Movie* obiectul2)
{
	if (obiectul1->get_score() > obiectul2->get_score())
		return 1;
	if (obiectul1->get_score() == obiectul2->get_score())
		return 0;
	if (obiectul1->get_score() < obiectul2->get_score())
		return -1;
}
int MyCompareLength(Movie* obiectul1, Movie* obiectul2)
{
	if (obiectul1->get_length() > obiectul2->get_length())
		return 1;
	if (obiectul1->get_length() == obiectul2->get_length())
		return 0;
	if (obiectul1->get_length() < obiectul2->get_length())
		return -1;
}

int MyCompareP_years(Movie* obiectul1, Movie* obiectul2)
{
	if (obiectul1->get_passed_years() > obiectul2->get_passed_years())
		return 1;
	if (obiectul1->get_passed_years() == obiectul2->get_passed_years())
		return 0;
	if (obiectul1->get_passed_years() < obiectul2->get_passed_years())
		return -1;
	
}
