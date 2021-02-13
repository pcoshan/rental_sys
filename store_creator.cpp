#include "store.h"
#include "movie.h"
#include "game.h"
#include "user.h"
#include "store_creator.h"
#include <sstream>
#include <iomanip>
//return to main function returns the value 0 to the main function
//when the user is done with the previous menu option they selected
int return_to_main(){
	int return_to_main;
	cout << "Enter 1 to view the menu again" << endl;
	cin >> return_to_main;
	while(cin.fail() || return_to_main != 1){
	 	cout << "Invalid Input Please try again: " << endl;
 		cin.clear();
	    cin.ignore(numeric_limits<streamsize>::max(), '\n');
	 	cin >> return_to_main;
	}
	return 0;
}
//this class function intialises a store with predetermined data to allow the system 
//to be demonstrated
Store Store_interface::initialise_store(){
	//create a store
	Store Block_buster = Store("Patrick", "324 Goodwood Rd");
	//create a 5 new users
	User* Pat = new User("PC");
	User* Bell = new User("BC");
	User* Nic = new User("NS");
	User* Jez = new User("JC");
	User* Sarah = new User("SC");
	//add the  customers to the database
	Block_buster.add_customer(Pat);
	Block_buster.add_customer(Bell);
	Block_buster.add_customer(Nic);
	Block_buster.add_customer(Jez);
	Block_buster.add_customer(Sarah);
	//create 10 new movies and add them to the list. 
	Movie* Batman = new Movie("VHS",5,"Batman Forever", 3);
	Block_buster.add_movie(Batman);
	Movie* Toy_story_2 = new Movie("VHS", 7, "Toy Story 2", 5);
	Block_buster.add_movie(Toy_story_2);
	Movie* The_mummy = new Movie("VHS", 5,"The Mummy", 10);
	Block_buster.add_movie(The_mummy);
	Movie* star_wars = new Movie("VHS", 9,"Star Wars: The Phantom Menace", 3);
	Block_buster.add_movie(star_wars);
	Movie* iron_giant = new Movie("VHS", 5,"The Iron Giant", 10);
	Block_buster.add_movie(iron_giant);
	Movie* fight_club = new Movie("VHS", 10,"Fight Club", 2);
	Block_buster.add_movie(fight_club);
	Movie* American_pie = new Movie("VHS", 5,"American Pie", 1);
	Block_buster.add_movie(American_pie);
	Movie* TBWP = new Movie("VHS", 5,"The Blair Witch Project", 6);
	Block_buster.add_movie(TBWP);
	Movie* Muppets = new Movie("VHS", 5,"Muppets from Space",3);
	Block_buster.add_movie(Muppets);
	Movie* Tarzan = new Movie("VHS", 5,"Tarzan", 10);
	Block_buster.add_movie(Tarzan);
	//create 5 new games and add them to the list. 
	Game* Mario = new Game("N64",8,"Super Mario Bro's", 5);
	Block_buster.add_game(Mario);
	Game* CBW = new Game("PlayStation",8,"Crash Bandicoot: Warped", 4);
	Block_buster.add_game(CBW);
	Game* Banjo = new Game("N64",8,"Banjo-Kazooie", 8);
	Block_buster.add_game(Banjo);
	Game* Zelda = new Game("N64",8,"Legend of Zelda: Ocarina of Time", 5);
	Block_buster.add_game(Zelda);
	Game* NFS = new Game("PlayStation",8,"Need for Speed 3: Hot Pursuit", 5);
	Block_buster.add_game(NFS);
	//rent out a couple of videos and games to a 2 users
	Block_buster.rent_out_movie(Batman, Pat);
	Block_buster.rent_out_movie(The_mummy, Pat);
	Block_buster.rent_out_movie(star_wars, Jez);
	Block_buster.rent_out_movie(fight_club, Jez);
	Block_buster.rent_out_movie(Tarzan, Nic);
	//add a couple of fees to the users accounts
	Pat->add_user_fees(10, Pat);
	Sarah->add_user_fees(5, Sarah);
	Nic->add_user_fees(10, Nic);
	//return the store created to the main program. 
	return Block_buster;
}

//this function dusplays the main menu options to the screen and returns void
void Store_interface :: print_main_menu(){
	cout << endl;
	cout << "MAIN MENU" << endl;
	cout << "2. View list of Movie Rentals" << endl;
	cout << "3. View list of Game Rentals" << endl;
	cout << "4. View list of User accounts" << endl;
	cout << "5. Rent Movie to customer" << endl;
	cout << "6. Rent Game to customer" << endl;
	cout << "7. Add user or Rental to system" << endl;
	cout << "8. Return a users rentals" << endl;
	//cout << "8. View a customers current rentals" << endl;
	cout << "9. Exit the program" << endl; 
	cout << endl;
	cout << "Enter a number from the list and press return: " << endl;
}
//this function takes the user input from main and uses a swtich to determine 
//which store function to call
int Store_interface :: print_lists(int user_choice, Store* store){
	switch (user_choice){
		case 2:{
			vector <Movie> print_vec = store->view_movie_list();

				if(print_vec.size() == 0){
					cout << "There are no movies in the system." << endl;
					return 1; 
				}

				else{	
					for(int i = 0;i < print_vec.size(); i++){
						cout << left << setw(30) << print_vec[i].title 
						<< " Movie Format: " << print_vec[i].format 
						<< "	Number of copies availble: "
						<< print_vec[i].get_num_copies() << "	Rental Id: " << print_vec[i].id << endl;
					}
				}
			break;
		}
		case 3:{
			vector <Game> print_vec_game = store->view_game_list();

				if(print_vec_game.size() == 0){
					cout << "There are no games in the system." << endl;
					return 1;
				}

				else{
					for(int i = 0;i < print_vec_game.size(); i++){
						cout << left << setw(40) << print_vec_game[i].title << 
						"For Console: " << left << setw(25) <<print_vec_game[i].console 
						<< left << setw(30) <<  "	Number of copies availble: "<< 
						print_vec_game[i].get_num_copies() 
						<< "	Rental Id: " << print_vec_game[i].id << endl;
					}
				}
			break;
		}
		case 4:{
			vector <User> print_user_vec = store->view_customer_list();
				for(int i = 0;i < print_user_vec.size(); i++)
				{
					cout << "Customer initials: "<< print_user_vec[i].get_user_initials() 
					<< "	Customer id: " << print_user_vec[i].get_user_id() << endl;
				}
			break; 
		}
	}
	cout << endl;
	return return_to_main();	
}

// this function takes the user input from main and uses a switch statement 
//to determine which store rental option to execute 
int Store_interface :: rental_options( int user_choice, Store* store){
	int temp;
	cout << "Enter the ID of the user: " << endl;
	cin >> temp;
	store->current_user_ptr = store->search_user_vec(temp);
	if(store->current_user_ptr == nullptr){
		cout << "Error user does not exist" << endl;
		return 1;
	}
	switch (user_choice){
		case 5:{
			int mov_choice;
			cout << "Enter the Id of the Movie: " << endl;
			cin >> mov_choice;
			store->current_movie_ptr = store->search_movie_vec(mov_choice);

			if(store->current_movie_ptr == nullptr) {
				cout << "This movie does not exist " << endl;
				return 1;
			}
			if(store->current_user_ptr->num_curr_rentals > store->max_cust_rentals) {
				cout << "Error this user already has maximum number of rentals permitted" << endl;
				return 1; 
			}

			if(store->current_movie_ptr->get_num_copies() == 0)
			{
				cout << "Error there are no copies availble." << endl;
				return 1 ;
			}

			else{
				store->rent_out_movie(store->current_movie_ptr,store->current_user_ptr);
				cout << "Customer: " << store->current_user_ptr->get_user_initials() 
				<< "	Rented: " << store->current_movie_ptr->title << endl;
			}
			break;
		}	
		case 6:{
			int gam_choice;
			cout << "Enter the Id of the Game: " << endl; 
			cin >> gam_choice;
			store->current_game_ptr = store->search_game_vec(gam_choice);
			
			if(store->current_game_ptr == nullptr){
				cout << "This game does not exist " << endl;
				return 1;
			}
			
			if(store->current_user_ptr->num_curr_rentals > store->max_cust_rentals){
				cout << "Error this user already has maximum number of rentals permitted" << endl;
				return 1;
			}
			
			if(store->current_game_ptr->get_num_copies() == 0){
				cout << "Error there are no copies availble." << endl;
				return 1;
			}
			else{	
				store->rent_out_game(store->current_game_ptr,store->current_user_ptr);
				cout << "Customer: " << store->current_user_ptr->get_user_initials() 
				<< "	Rented: " << store->current_game_ptr->title << endl;
			}

		}	
	}
	cout << endl;
	return return_to_main();
}

//this function takes the user choice and presents another menu with options
//to add the the 3 vectors which hold the store information 
int Store_interface:: add_options(int user_choice, Store* store){
	cout << "Enter a following option: " << endl;
	cout << "1. Add User to system" << endl;
	cout << "2. Add Movie to system" << endl;
	cout << "3. Add game to system" << endl;
	int sec_choice;
	cin >> sec_choice;

	//validates the input 
	while(cin.fail() || sec_choice < 1 || sec_choice >3){
	 	cout << "Invalid Input Please try again: " << endl;
	 	cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	 	cin >> sec_choice;
	}
	//switch statement executes depending on second choice 
	switch(sec_choice){
		case 1:{
			cout << "Enter the Initials of the new user" << endl;
			string n_user_init;
			cin >> n_user_init;
				while(n_user_init.size() > 2 && n_user_init.size() < 0){
					cout << "Invalid entry please try again" << endl;
					cin >> n_user_init;
				}
			User* new_user;
			new_user = new User(n_user_init);
			store->add_customer(new_user);
			cout << "New User: " << n_user_init << " has been created" << endl;
			break;
		}
		case 2:{
			cout << "Enter the title of the movie: " << endl;
			string new_movie_title;
			cin.ignore();
			getline(cin,new_movie_title);
			cout << "Enter the format of the new movie: " << endl;
			string new_mov_form;
			cin >> new_mov_form;
			cout << "Enter the number of copies of the new Movie: " << endl;
			int num_copies;
			cin >> num_copies;
			cout << "Enter the cost to rent the new movie: " << endl;
			int cost;
			cin >> cost;

			while(cin.fail() || cost < 0 || cost > 99){
		 		cout << "Invalid Input Please try again: " << endl;
		 		cin.clear();
			    cin.ignore(numeric_limits<streamsize>::max(), '\n');
		 		cin >> cost;
			}

			while(cin.fail() || num_copies < 0 || num_copies > 99){
		 		cout << "Invalid Input Please try again: " << endl;
		 		cin.clear();
			    cin.ignore(numeric_limits<streamsize>::max(), '\n');
		 		cin >> num_copies;
			}
			Movie* new_movie = new Movie(new_mov_form,cost,new_movie_title,num_copies);
			store->add_movie(new_movie);
			cout << "Movie : " << new_movie->title << " added to system" << endl;
			break;
		}
		case 3:{
			cout << "Enter the title of the game: " << endl;
			string new_game_title;
			cin.ignore();
			getline(cin,new_game_title);
			cout << "Enter the console the game is played on: " << endl;
			string new_game_form;
			cin >> new_game_form;
			cout << "Enter the number of copies of the new game: " << endl;
			int num_copies;
			cin >> num_copies;
			cout << "Enter the cost to rent the new game: " << endl;
			int cost;
			cin >> cost;
			while(cin.fail() || cost < 0 || cost > 99){
		 		cout << "Invalid Input Please try again: " << endl;
		 		cin.clear();
			    cin.ignore(numeric_limits<streamsize>::max(), '\n');
		 		cin >> cost;
			}
			while(cin.fail() || num_copies < 0 || num_copies > 99){
		 		cout << "Invalid Input Please try again: " << endl;
		 		cin.clear();
			    cin.ignore(numeric_limits<streamsize>::max(), '\n');
		 		cin >> num_copies;
			}
			Game* new_game = new Game(new_game_form,cost,new_game_title,num_copies);
			store->add_game(new_game);
			cout << "Movie : " << new_game->title << " added to system" << endl;
			break;
		}
	}	
	return return_to_main();
}

//this function allows the user to enter the id of a user whos rentals are being
//returned, it checks that the user exists before returning 
int Store_interface :: return_rentals(Store* store){
	cout << "Enter the Id of the User who is returing the rentals" << endl;
	int temp_id;
	cin >> temp_id;

	while(temp_id < 0 && temp_id>99){
		cout << "Invalid Input Please try again: " << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> temp_id;
	}	 		
	store->current_user_ptr = store->search_user_vec(temp_id);

	if(store->current_user_ptr == nullptr){
		cout << "Customer could not be found " << endl;
		return 1;
	}

	else {
		store->return_all_rentals(store->current_user_ptr);
		cout << "Customer: " << store->current_user_ptr->get_user_initials() << " has returned their rentals" << endl;
	}
	return return_to_main();
}


















