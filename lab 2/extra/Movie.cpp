#include "Movie.h"
#include <stdio.h>
#include <cstring>

void Movie::set_year(int x)
{
		this->year = x;
		this->p_years = 2024 - this->year;
}
int  Movie::get_year()
{
	return this->year;
}
void Movie::set_score(double x)
{
	if (x >= 1.0 && x <= 10.0)
		this->scor = x;
}
double Movie::get_score()
{
	return this->scor;
}
void Movie::set_length(int x)
{
		this->lg = x;
}
int Movie::get_length()
{
	return this->lg;
}
int Movie::get_passed_years()
{
	return this->p_years;
}
void Movie::set_name(const char* my_name)
{
	int length = std::strlen(my_name);
	name = new char[length + 1];
	name[length] = 0;
	for (int i = 0; i < length; i++)
		name[i] = my_name[i];
}
const char* Movie::get_name()
{
	return name;
}
Movie::Movie() {


}

Movie::~Movie() {

}