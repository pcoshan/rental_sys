#ifndef _STORECREATE_H
#define _STORECREATE_H
#include "store.h"
#include "movie.h"
#include "game.h"
#include "user.h"
using namespace std;

//This class exists to allow the user to interact with a pre built store
//the functions allow user input to intialise new rentals and accounts. 

class Store_interface
{	
public:
	//User create_new_user();
	Store initialise_store();
	//Methods that allow the user to interact with the store functions
	void print_main_menu();
	int print_lists(int user_choice, Store* store);
	int rental_options(int user_choice, Store* store);
	int add_options(int user_choice, Store* store);
	int return_rentals(Store* store);
	int view_cust_rentals(Store* store);
	//destructor
	~Store_interface(){};
};

#endif