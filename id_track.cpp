//This file contains the global variables and related functions
//for tracking and implementing new rental ids.
int rent_id = 0;
int cust_id = 0;

int new_rental_id()
{
	rent_id++;
	return rent_id;
}

int new_customer_id()
{
	cust_id++;
	return cust_id;
}
