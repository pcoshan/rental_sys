#ifndef _MOVIE_H
#define _MOVIE_H
#include <iostream>
#include <string>
#include "rental.h"
using namespace std;
//movie is a subclass of rental
class Movie : public Rental 
{
private:
	int cost;
public:
	string format;
	int get_cost();
	Movie(string format, int mcost, string mtitle, int mnum_copies);
	void print_rental_type();
};
#endif

