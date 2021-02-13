#ifndef _STORE_H
#define _STORE_H
#include <iostream>
#include <string>
#include <vector>
#include "rental.h"
#include "user.h"
#include "movie.h"
#include "game.h"
#include "snacks.h"

using namespace std;

class Store
{
private:
	//private data about the store.
	string manager_name;
	string address;
	vector <User> customer_data; 
	vector <Movie> movie_vec;
	vector <Game> game_vec;
	vector <Snacks> snacks_vec;
public:
	//unprotected data
	int max_cust_rentals;
	//ptrs for use in class functions
	User* current_user_ptr;
	Game* current_game_ptr;
	Movie* current_movie_ptr;
	//de/constructor
	Store(string man_name, string store_add);
	~Store();
	//methods of the class 
	string get_manager_name();
	string get_store_address();
	vector <User> view_customer_list();
	vector <Movie> view_movie_list();
	vector <Game> view_game_list();
	vector <Snacks> view_snacks_list();
	void add_customer(User* customer);
	void add_movie(Movie* movie);
	void add_game(Game* game);
	void add_snacks(Snacks* snack);
	void rent_out_movie(Movie* movie_ptr, User* user_ptr);
	void rent_out_game(Game* game_ptr, User* user_ptr);
	void return_all_rentals(User* user_ptr);
	Movie* search_movie_vec(int search_id);
	Game* search_game_vec(int search_id);
	User* search_user_vec(int search_id);

};

#endif