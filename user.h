#ifndef _USER_H
#define _USER_H

#include <iostream>
#include <string>
#include <vector>
#include "rental.h"

using namespace std;

class User
{
private:
	//the private infomation of the users
	string user_initials;
	int user_id;
	
public:
	//constructor
	User(string initials);
	//other data of the user 
	int fees_owing;
	int num_curr_rentals;
	string get_user_initials();
	string current_rentals[5]; //string array fixed size which stores the title of the rentals 
	//Methods 
	void print_user_rentals();
	void add_user_fees(int amount, User* ptr);
	void remove_user_fees(int amount, User* ptr);
	int get_user_fees();
	int get_user_id();
	//destructor
	~User();
};

#endif