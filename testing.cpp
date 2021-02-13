#include <iostream>
#include <string>
#include <vector>
#include "rental.h"
#include "store.h"
#include "user.h"
using namespace std;

//write functions to test the functions

//testing user functions 

void user_test()
{
	//create a user to test
	string test_int = "PC"
	 User customer = User(test_int);
	 //check the user created has the expected attributes
	 if(test_int.compare(customer.user_initials) != 0 || customer.user_id != 1)
	 {
	 	cout << "User creation failed" << endl; 
	 }
	 else
	 {
	 	cout << "User creation passed!" << endl;
	 }
	 //testing getters
	 string x = customer.get_user_initials()
	 int y = customer.get_user_id();
	 if( x.compare(test_int) != 0)
	 {
	 	cout << "Function user_get_initials failed" << endl;
	 }
	 else
	 {
	 	cout << "Function user_get_intials passed!" << endl;
	 }
	 if( y != 1)
	 {
	 	cout << "Function get_user_id failed"  << endl;
	 }
	 else 
	 {
	 	cout << "Functionn get_user_id passed!" << endl;
	 }
	 //testing adding wkly 
	 Weekly_rental movie1 = Weekly_rental(string "test_movie", 3); 
	 customer.add_wkly_rental(Weekly_rental* movie1);
	 if(customer.wkly_rented[0].title.compare("test_movie") == 0 && customer.wkly_rented[0].num_copies ==3 )
	 {
	 	cout << "Fucntion add_wkly_rental passed!" << endl;
	 }
	 else
	 {
	 	cout << "Function add_wkly_rental failed" << endl;
	 }
	 //testing adding weekend
	 Weekend_rental movie2 = Weekend_rental(string "test_movie2", 1); 
	 customer.add_wknd_rental(Weekend_rental* movie2);
	 if(customer.wknd_rented[0].title.compare("test_movie") == 0 && customer.wknd_rented[0].num_copies ==3 )
	 {
	 	cout << "Fucntion add_wknd_rental passed!" << endl;
	 }
	 else
	 {
	 	cout << "Function add_wknd_rental failed" << endl;
	 }
	 //testing print user rentals
	 

}