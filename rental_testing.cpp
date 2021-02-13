#include "rental.h"
#include "movie.h"
//this file is the resting file for the Rental class
int tests_ran = 0;
int tests_passed = 0;

int rent_id = 0;
int new_rental_id(){
	rent_id++;
	return rent_id;
}
//Tests that the number of copies returned by the function is correct
void get_num_copies_test(int test_copies_val, Rental* test_rental){
	
	//fails if the value is not the expected value
	if(test_copies_val!= test_rental->get_num_copies()){
		cout << "get_num_copies test failed" << endl;
	}
	else{
		tests_ran++;
		tests_passed++;
	}
}

//tests that the decrease function reduces the number of copies correctly
//agianst the expected value
void decrease_num_copies_test(int expected_val, Rental* test_rental){
	test_rental->decrease_num_copies();
	if (test_rental->get_num_copies() != expected_val){
		cout << "decrease_num_copies_test failed" << endl;
	}
	else{
		tests_ran++;
		tests_passed++;
	}
}

//check that the increase function increase number of copies correctly 
void increase_num_copies_test(int expected_val, Rental* test_rental)
{
	test_rental->increase_num_copies();
	if(test_rental->get_num_copies() != expected_val){
		cout << "decrease_num_copies_test failed" << endl;
	}
	else{
		tests_ran++;
		tests_passed++;
	}
}
//main function to call the test functions
int main(int argc, char** argv){
	//initialise a new rental to test. 
	Movie* test_rental = new Movie("test format", 1, "test title",  1);
	Movie* test_rental2 = new Movie("test format", 1, "test title",  1000);
	//get the number of copies tests 
	get_num_copies_test(1, test_rental);
	get_num_copies_test(1000, test_rental2);
	//decrease test
	decrease_num_copies_test(0, test_rental);
	decrease_num_copies_test(999, test_rental2);
	//check the edge case for -1, value should remain 0
	decrease_num_copies_test(0, test_rental);
	//increase test
	increase_num_copies_test(1, test_rental);
	increase_num_copies_test(1000, test_rental2);
	//test results print.
	cout << "Tests ran: " << tests_ran << " Tests passed: " << tests_passed << endl; 
	//delete dynamic memory 
	delete test_rental;
	delete test_rental2;
}


















