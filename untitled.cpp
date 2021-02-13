Store_creator*  BB;
	Store Block_Buster = BB->initialise_store();

		Store Block_buster = Store("Patrick", "324 Goodwood Rd");
	cout << Block_buster.get_manager_name() << endl;
	cout << Block_buster.get_store_address() << endl;
	//create a new user
	User* Pat =  new User("PC");
	cout << Pat->get_user_initials() << endl;
	cout << Pat->get_user_id() << endl;
	//Print the customer list, should show empty message
	Block_buster.view_customer_list();
	//add a customer to the database
	Block_buster.add_customer(Pat);
	//print the list should display the customer created above.
	Block_buster.view_customer_list();

	//view fees - should be zero
	cout << Pat->get_user_fees() << endl;
	//add fees 
	Pat->add_user_fees(10, Pat);
	cout << Pat->get_user_fees();
	//remove fees
	Pat->remove_user_fees(5, Pat);
	cout << Pat->get_user_fees() << endl;

	//create a new movie and check the data stored. 
	Movie* Batman = new Movie("VHS",5,"Batman Forever", 3);
	cout <<Batman->get_num_copies() << endl;
	cout << Batman->get_cost() << endl;
	cout << Batman->title << endl;
	
	Block_buster.view_movie_list();
	Block_buster.add_movie(Batman);
	Block_buster.view_movie_list();


	Game* Mario = new Game("N64",8,"Super Mario Bro's", 5);
	cout << Mario->get_cost() << endl;
	cout << Mario->get_num_copies() << endl;
	cout << Mario->title << endl;
	cout << Mario->id << endl;

	Block_buster.view_game_list();
	Block_buster.add_game(Mario);
	Block_buster.view_game_list();

	Pat->print_user_rentals();
	Block_buster.rent_out_movie(Batman, Pat);
	Pat->print_user_rentals();
	Block_buster.rent_out_game(Mario, Pat);
	Pat->print_user_rentals();

	Block_buster.return_all_rentals(Pat);
	Pat->print_user_rentals();


	cout << "Enter the id of the customer: ";
			int cust_input;
			while(cust_input <0 && cust_input > 99)
 			{
 				cin >> cust_input;
		 			if(cin.fail())
		 			{
		    		cin.clear();
		    		cin.ignore();
		    		cout << "Invalid Input" << endl;
					}
			}
			for(int i = 0; i < Block_Buster.customer_data.size() < i++)
			{
				if(Block_Buster.customer_data[i].user_id == cust_input)
				{
					Block_Buster.current_user_ptr = Block_Buster.customer_data[i].user_id;
				}
			}
			return_all_rentals(Block_Buster.current_user_ptr);



//create a store with preset movies/games and users. 
	Store_interface*  interface;
	Store Block_Buster = interface->initialise_store();
	//create display menu with a swtich statement for options.
	cout << "TEST USER INTERFACE" << endl;
	cout << "1. View list of Movie Rentals" << endl;
	cout << "2. View list of Game Rentals" << endl;
	cout << "3. View list of User accounts" << endl;
	cout << "5. Rent Movie to customer" << endl;
	cout << "6. Rent Game to customer" << endl;
	cout << endl;
	cout << "Enter a number from the list and press return: " << endl;
	int user_choice;
	cin >> user_choice;
	while(user_choice <0 && user_choice > 6)
 	{
 		cin >> user_choice;
		 	if(cin.fail()) //stops strings i think
		 	{
		    	cin.clear();
		    	cin.ignore();
		    	cout << "Invalid Input Please try again: " << endl;
			}
	}
	switch(user_choice)
	{
		case 1:
		Block_Buster.view_movie_list();
		break;
		case 2:
		Block_Buster.view_game_list();
		break;
		case 3:
		Block_Buster.view_customer_list();
		break;
		case 5:
			cout << "Enter the id of the customer: " << endl;
			int cust_input_id;
			cin >> cust_input_id;
			while(cust_input_id <0 && cust_input_id > 99)
 			{
 				cin >> cust_input_id;
		 			if(cin.fail())
		 			{
		    		cin.clear();
		    		cin.ignore();
		    		cout << "Invalid Input" << endl;
					}
			}
			int cust_mov_id;
			cout << "Enter the rental id" << endl;
			cin >> cust_mov_id;
			while(cust_mov_id <0 && cust_mov_id > 99)
 			{
 				cin >> cust_mov_id;
		 			if(cin.fail())
		 			{
		    		cin.clear();
		    		cin.ignore();
		    		cout << "Invalid Input" << endl;
					}
			}
			User* user_ptr = Block_Buster.search_user_vec(cust_input_id);
			Movie* movie_ptr = Block_Buster.search_movie_vec(cust_mov_id);
			Block_Buster.rent_out_movie(movie_ptr, user_ptr);
			cout << "Customer: " << user_ptr->get_user_initials() << "		Has rented: " << movie_ptr->title << endl;