#include <iostream>
#include "rental.h"
using namespace std;
extern int new_rental_id();//ID tracking function

//constructor which is called by the subclass
Rental::Rental(string rtitle, int rnum_copies){
	title = rtitle;
	id = new_rental_id();
	num_copies = rnum_copies;
}

//returns the number of copies of the rentals
int Rental:: get_num_copies(){
	return num_copies;
}

//decreases the number of copies of a rental
void Rental::decrease_num_copies(){
	
	if(num_copies != 0){
		num_copies--;
	}
}

//increases the number of copies of a rental
void Rental::increase_num_copies(){
	num_copies++;
}