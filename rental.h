#ifndef _RENTAL_H
#define _RENTAL_H
#include <iostream>
#include <string>
#include "stock_item.h"
using namespace std;
// Rental class is the parent class to the two rental types of the store
//and a sub class of the stock item
class Rental : public Stock_item
{
public:
	//overloaded constructor, called by the subclasses
	Rental(string rtitle, int rnum_copies);
	//atttributes 
	string title;
	int id;
	int num_copies;
	//methods
	int get_num_copies();
	void decrease_num_copies();
	void increase_num_copies();	
	int generate_item_code();
	virtual void print_rental_type() =0;
	//constructor destructor 
	Rental() {};
	~Rental() {};
};

#endif 
