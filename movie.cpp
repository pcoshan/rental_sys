#include <iostream>
#include <string>
#include "rental.h"
#include "movie.h"
using namespace std;
//constructor of movie to create a new movie rental 
Movie::Movie(string mformat, int mcost, string mtitle, int mnum_copies) : Rental(mtitle, mnum_copies){
	format = mformat;
	cost = mcost;
}
//returns the cost of the movie rental
int Movie::get_cost(){
	return cost;
}
//virtual function prints the subclass specific rental type
void Movie::print_rental_type(){
	cout << "Movie Rental" << endl;
}