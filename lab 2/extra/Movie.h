#pragma once
#include <string>

class Movie
{
	int year,p_years;
	double scor;
	int lg;
	char* name;

public:
	Movie();
	~Movie();
	void set_year(int x);
	int get_year();

	void set_score(double x);
	double get_score();

	void set_length(int x);
	int get_length();

	int get_passed_years();

	void set_name(const char* my_name);
	const char* get_name();

};
