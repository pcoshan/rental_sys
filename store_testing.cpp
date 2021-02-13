#include "store.h"
#include "store_creator.h"
#include "user.h"
//unit testing for the store class
//declare global test tracking variable
int tests_ran;
int tests_passed; 

//test that the returned manager name string is correct against the expected string
void test_get_manager_name(string test_man_name, Store* test_store){
	tests_ran++;
	if(test_man_name != test_store->get_manager_name()){
		cout << "get_manager_name test failed" << endl;
	}
	else{
			tests_passed++;
	}
}

//tests the address string returned by the function is correct 
void test_get_store_address(string test_address, Store* test_store){
	tests_ran++;
	if(test_address != test_store->get_store_address()){
		cout << "get_store_address test failed" << endl;
	}

	else{
			tests_passed++;
	}
}

//tests that customers are added to the customer data vector correctly
void test_add_customer(User* customer, Store* test_store){
	tests_ran++;
	vector <User> test_vec = test_store->view_customer_list();
	int start_val = test_vec.size();
	int end_val;
	test_store->add_customer(customer);
	test_vec = test_store->view_customer_list();
	end_val = test_vec.size();

	if(start_val == end_val){
		cout << "add customer test failed" << endl;
	}

	else{
			tests_passed++;
	}
}

//tests that the movies are added to the movie vector of the store
void test_add_movie(Movie* movie, Store* test_store){
	tests_ran++;
	vector <Movie> test_vec = test_store->view_movie_list();
	int start_val = test_vec.size();
	int end_val;
	test_store->add_movie(movie);
	test_vec = test_store->view_movie_list();
	end_val = test_vec.size();
	if(start_val == end_val){
			cout << "add movie test failed" << endl;
	}
	else{
		tests_passed++;
	}
}

//tests that the games are added to the games vector correctly 
void test_add_game(Game* game, Store* test_store){
	tests_ran++;
	vector <Game> test_vec = test_store->view_game_list();
	int start_val = test_vec.size();
	int end_val;
	test_store->add_game(game);
	test_vec = test_store->view_game_list();
	end_val = test_vec.size();
	if(start_val == end_val){
		cout << "add game test failed" << endl;
	}
	else{
		tests_passed++;
	}
}

//tests the movie rental function of the store to a chosen user 
void test_rent_out_movie(Movie* movie_ptr, User* user_ptr, Store* test_store){
	tests_ran++;
	test_store->rent_out_movie(movie_ptr, user_ptr);
	if(user_ptr->current_rentals[user_ptr->num_curr_rentals] == movie_ptr->title){
		cout << "Rent out movie test failed" << endl;
	}
	else{
		tests_passed++;
	}
}

//tests the game rental function of the store to the chosen user
void test_rent_out_game(Game* game_ptr, User* user_ptr, Store* test_store){
	tests_ran++;
	int start_val = user_ptr->num_curr_rentals;
	test_store->rent_out_game(game_ptr, user_ptr);
	int end_val = user_ptr->num_curr_rentals;

	if(start_val == end_val){
		cout << "Rent out game test failed" << endl;
	}
	else{
		tests_passed++;
	}
}
//test that the return all rentals function correctly returns the rentals of auser 
void test_return_all_rentals(User* user_ptr, Store* test_store){
	tests_ran++;
	int start_val = user_ptr->num_curr_rentals;
	test_store->return_all_rentals(user_ptr);
	int end_val = user_ptr->num_curr_rentals;
	if(start_val == end_val){	
		cout << "Return rentals test failed " << endl;
	}
	else{
		tests_passed++;
	}
}

//test movie returned by the search function against the expected result
void test_search_movie_vec(int search_id, Store* test_store){
	tests_ran++;
	Movie* movie = test_store->search_movie_vec(search_id);

	if(search_id != movie->id){
		cout << "search movie vec test failed" << endl;
	}
	else {
		tests_passed++;
	}
}
//tests the game returned by the search function agianst the expected result
void test_search_game_vec(int search_id, Store* test_store){
	tests_ran++;
	Game* game = test_store->search_game_vec(search_id);

	if(search_id != game->id){
		cout << "search game vec test failed " << endl;
	}
	else{
		tests_passed++;
	}
	 
}

//tests the user returned by the search function is correct against the expected result 
void test_search_user_vec(int search_id, Store* test_store){
	tests_ran++;
	User* user = test_store->search_user_vec(search_id);
	if(search_id != user->get_user_id()){
		cout << "search user vec failed" << endl;
	}
	else{
		tests_passed++;
	}
}

//main function to call the test functions of the store. 
int main(int argc, char** argv)
{
	//create a store with data to test the functions on
	Store_interface* interface;
	Store store = interface->initialise_store();
	Store* test_store = &store;
	//test search functions;
	test_search_user_vec(1,test_store); //this value will pass 
	//test_search_user_vec(99, test_store); // this value will fail
	test_search_game_vec(11, test_store); //this will pas
	//test_search_game_vec(99, test_store) ;// fail 
	test_search_movie_vec(1, test_store);
	//test_search_movie_vec(99, test_store);
	//test get manager name with the preset value and a false value. 
	test_get_manager_name("Patrick", test_store);
	//test_get_manager_name("Notpatrick", test_store);
	//check the store address
	test_get_store_address("324 Goodwood Rd", test_store);
	//test_get_store_address("12 lexo cres", test_store);
	//test the adding functions
	//create some rentals and a user to be added.
	User* test_user = new User("TU");
	Movie* test_movie = new Movie("mformat", 1, " test mtitle", 1);
	Game* test_game = new Game("gformat", 1, "test gtitle", 1);
	//test add functions 
	test_add_customer(test_user, test_store);
	test_add_game(test_game, test_store);
	test_add_movie(test_movie, test_store);
	//test rent out movie
	test_rent_out_movie(test_movie, test_user, test_store);
	//test rent out game 
	test_rent_out_game(test_game, test_user, test_store);
	//test return rentals
	test_return_all_rentals(test_user, test_store);

	cout << "Tests Ran: "<< tests_ran << " Tests passed: " << tests_passed << endl;
	//call destructors for news 
	delete test_user;
	delete test_movie;
	delete test_game;
	return 0; 
}