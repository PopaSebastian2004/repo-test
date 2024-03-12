#include "Movie.h"
#include "Globals.h"
#include "MovieSeries.h"
#include <stdlib.h>
#include <stdio.h>


int main() {
    Movie ep5;
    ep5.set_name("Star Wars: Episode V - The Empire Strikes Back");
    ep5.set_score(8.7);
    ep5.set_year(1980);
    ep5.set_length(124);

    Movie ep4;
    ep4.set_name("Star Wars: Episode IV - A New Hope");
    ep4.set_score(8.6);
    ep4.set_year(1977);
    ep4.set_length(121);

    Movie ep6;
    ep6.set_name("Star Wars: Episode VI - Return of the Jedi");
    ep6.set_score(8.3);
    ep6.set_year(1983);
    ep6.set_length(131);


        printf("%d\n", MyCompareName(&ep4, &ep5));
        printf("%d\n", MyCompareYear(&ep4, &ep5));
        printf("%d\n", MyCompareScore(&ep4, &ep5));
        printf("%d\n", MyCompareLength(&ep4, &ep5));
        printf("%d\n" ,MyCompareP_years (& ep4, & ep5));

      MovieSeries series;
      series.init();
      series.add(&ep5);
      series.add(&ep4);
      series.add(&ep6);
      series.sort();
      series.print();
    system("pause");
    return 0;
}