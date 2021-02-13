#include <iostream>
#include <string>
#include "rental.h"
#include "store.h"
#include "user.h"
using namespace std;

//constructor to initialise a new store
Store::Store(string man_name, string store_add){
	manager_name = man_name;
	address = store_add;
	User* current_user_ptr = nullptr;
	max_cust_rentals = 5;
}

//destructor
Store::~Store(){
}
//returns the managers name
string Store:: get_manager_name(){
	return manager_name;
}

//returns the address of the store
string Store:: get_store_address(){
	return address; 
}

//adds a customer to the customer data vector
void Store::add_customer(User* customer){
	customer_data.push_back(*customer);
}

//returns the vector of customer data
vector <User> Store::view_customer_list(){
		return customer_data;
}

//adds a movie to the stores movie vector
void Store::add_movie(Movie* movie){
	movie_vec.push_back(*movie);
}

//adds a game to the stores game vector 
void Store::add_game(Game* game){
	game_vec.push_back(*game);
}

//returns the movie vector
vector <Movie> Store::view_movie_list(){
	return movie_vec;
}

//returns the game vector 
vector <Game> Store::view_game_list(){
	return game_vec;
}

//rents out a specific movie to a specific customer
void Store::rent_out_movie(Movie* movie_ptr, User* user_ptr){
	
		user_ptr->current_rentals[user_ptr->num_curr_rentals] = movie_ptr->title; 
		user_ptr->num_curr_rentals++;
}

//rents out a specific game to a specific customer 
void Store::rent_out_game(Game* game_ptr, User* user_ptr){
		user_ptr->current_rentals[user_ptr->num_curr_rentals] = game_ptr->title; 
		user_ptr->num_curr_rentals++;
}

//returns all the rentals of both types of a chosen customer 
void Store::return_all_rentals(User* user_ptr){
	for(int i = 0; i < user_ptr->num_curr_rentals; i++){
		for(int j =0; j < movie_vec.size(); j++){
			if(user_ptr->current_rentals[i].compare(movie_vec[j].title) == 0){
				movie_vec[j].increase_num_copies();
			}
		}
		for(int k = 0; k < game_vec.size(); k++){
			if(user_ptr->current_rentals[i].compare(game_vec[k].title) == 0){
				game_vec[k].increase_num_copies();
			}
		}	
	user_ptr->current_rentals[i] = " "; //write over as blank
	}
	user_ptr->num_curr_rentals = 0;
}
//search the movie vector for a movie with the search id argument 
Movie* Store::search_movie_vec(int search_id){
	for(int i = 0; i < movie_vec.size(); i++){
		if(movie_vec[i].id == search_id){
			current_movie_ptr = &movie_vec[i];
		}
	}
	return current_movie_ptr;
}
//search the game vector for a game with the search id argument 
Game* Store::search_game_vec(int search_id){
	for(int i = 0; i < game_vec.size(); i++){
		if(game_vec[i].id == search_id){
			current_game_ptr = &game_vec[i];
		}
	}
	return current_game_ptr;
}

//search the user vector for a user with the user id same as the search id 
User* Store::search_user_vec(int search_id){
	for(int i = 0; i < customer_data.size(); i++){
		if(customer_data[i].get_user_id() == search_id){
			current_user_ptr = &customer_data[i];
		}
	}
	return current_user_ptr;
}

//add a snack to the snack vector of the store
void Store::add_snacks(Snacks* snack){
	snacks_vec.push_back(*snack);
}

//return the snack vector of the store
vector <Snacks> Store::view_snacks_list(){
	return snacks_vec;
}



