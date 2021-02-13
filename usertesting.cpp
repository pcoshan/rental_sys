#include "user.h"
//declare golbal variable and id function
int tests_ran =0;
int tests_passed = 0;
int cust_id = 0;
int new_customer_id(){
	cust_id++;
	return cust_id;
}

//tests that the user intials returned are correct agaisnt known value
void get_user_initials_test(string name_comparison, User* test_user){

	if(name_comparison.compare(test_user->get_user_initials()) != 0){
		cout << "get_user_initials test failed" << endl;
	}

	else{
		tests_ran++;
		tests_passed++;
	}
}

//tests that the user id is correct against the known value
void get_user_id_test(int test_id, User* test_user){

	if(test_id != test_user->get_user_id()){
		cout << "get_user_id test failed" << endl;
	}
	else{
		tests_ran++;
		tests_passed++;
	}
}

//tests the user fees returned are correct
void get_fees_owing_test(int test_fees_amount, User* test_user){

	if(test_fees_amount!= test_user->get_user_fees()){
		cout << "get_user_fees test failed" << endl;
	}
	else{
		tests_ran++;
		tests_passed++;
	}
}

//checks that that the print function exectures correctly against an array of strings 
void print_user_rentals_test(string test_rental_titles[], User* test_user){
	
	int flag = 0;
	for(int i = 0 ; i < test_user->num_curr_rentals; i++){

		if(test_user->current_rentals[i].compare(test_rental_titles[i]) != 0){
			cout << "printing user rentals failed" << endl;
			flag = 1;
		}	
	}

	if(flag == 0){
		tests_ran++;
		tests_passed++;
	}	
}

//tests that the user fees are added correctly to the user account
void add_user_fees_test(int test_amount, User* test_user){	
	int starting_fees = test_user->get_user_fees();
	//add the fees
	test_user->add_user_fees(test_amount, test_user);
	//compare
	if((starting_fees + test_amount) != test_user->get_user_fees()){
		cout << "add_user_fees test failed" << endl;
	}
	else{
		tests_ran++;
		tests_passed++;
	}
}

//tests that the user fees are removed correctly from the user account 
void remove_user_fees_test(int test_remove_val, User* test_user){
	int start_val = test_user->get_user_fees();
	int end_val = start_val - test_remove_val;
	test_user->remove_user_fees(test_remove_val, test_user);

	if(end_val != test_user->get_user_fees()){
		cout << "remove_user_fees test failed" << endl;
	}
	else{
		tests_ran++;
		tests_passed++;
	}
}

//main function to call the test functions above 
int main(int argc, char** argv)
{
	//create a new user to test the test functions with
	User* test_user = new User("PC");
	//basic get functions test
	//value should be equal to intials put in constructor
	get_user_initials_test("PC", test_user);
	//value should be eqaul to 1 as it is the first user created. 
	get_user_id_test(1,test_user);
	//test 0 as no fees added
	get_fees_owing_test(0, test_user);
	//add fees and rentals to the user to test the next function
	test_user->add_user_fees(10, test_user);
	add_user_fees_test(5, test_user);
	remove_user_fees_test(5, test_user);
	cout << "Tests ran: " << tests_ran << " Tests passed: " << tests_passed << endl; 
	//call the destructor
	test_user->~User();
}
