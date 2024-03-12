#include <string>
#include "Movie.h"
class MovieSeries
{
	int count;
	Movie * list[200];
  public:
	void init();
	void add(Movie  * obiectul1);
	void sort();
	void print();
};