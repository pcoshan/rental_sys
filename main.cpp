#include <iostream>
#include <string>
#include <vector>
#include <ios>
#include <limits>
#include "rental.h"
#include "store.h"
#include "user.h"
#include "movie.h"
#include "game.h"
#include "store_creator.h"
using namespace std;
//main function of the program where the user interacts with the program through
//the the interface class. 
int main()
{
	//create a store with preset movies/games and users. 
	Store_interface* interface;
	Store Block_Buster = interface->initialise_store();
	//assign a ptr to for the store to interact with the interface class.
	Store* str_ptr = &Block_Buster;
	//display the initial menu
	interface->print_main_menu();
	//get the users initial choice. 
	int choice;
	cin >> choice;
	//keeps the program running until user wants to exit by entering 9.
	while(choice != 9){
		//this is the input validation loop
		while(cin.fail() || choice < 2 || choice > 9){
	 		cout << "Invalid Input Please try again: " << endl;
	 		cin.clear();
		    cin.ignore(numeric_limits<streamsize>::max(), '\n');
	 		cin >> choice;
		}

		if(choice == 2 || choice == 3 || choice ==4){
			interface->print_lists(choice, str_ptr);
			choice = 0;
		}

		if(choice == 5 || choice == 6){
			interface->rental_options(choice, str_ptr);
			choice = 0;
		}

		if(choice == 7){
			interface->add_options(choice, str_ptr);
			choice = 0;
		}
		
		if(choice == 8){
			interface->return_rentals(str_ptr);
			choice = 0;
		}
		
		//resest the store pointers
		Block_Buster.current_user_ptr = nullptr;
		Block_Buster.current_movie_ptr = nullptr;
		Block_Buster.current_game_ptr = nullptr; 
		//redisplay the menu
		interface->print_main_menu();
		cin >> choice;
	}
	
	//exit the program
	return 0; 
}
































