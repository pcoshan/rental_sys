#ifndef _IDTRACK_H
#define _IDTRACK_H
#include <iostream>

using namespace std;

int rent_id = 0;
int cust_id = 0;

int new_rental_id()
{
	rent_id++;
	return rent_id ;
}

int new_customer_id()
{
	cust_id++
	return cust_id;
}

#endif