#include <iostream>
#include <string>
#include <vector>
#include "rental.h"
#include "user.h"
using namespace std;
extern int new_customer_id();

//constructor with arguement
User::User(string uinitials){	
	user_initials = uinitials;
	user_id = new_customer_id();
	fees_owing = 0;
	num_curr_rentals = 0;
}

//destructor
User::~User(){}

//returns the user initials
string User::get_user_initials(){
	return user_initials;
}

//returns the user id
int User::get_user_id(){
	return user_id;
}

//returns the fees owing of the user
int User::get_user_fees(){
	return fees_owing;
}

//prints the users current rentals 
void User::print_user_rentals( ){	
	for(int i = 0 ; i < num_curr_rentals; i++){
			cout << current_rentals[i] << endl; 
	}	
}

//add fees to the users account
void User::add_user_fees(int amount, User* ptr){
	ptr->fees_owing = ptr->fees_owing + amount;
}

//remove fees from the user account
void User::remove_user_fees(int amount, User* ptr){	
	ptr->fees_owing = ptr->fees_owing - amount;
}