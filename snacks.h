#ifndef _SNACKS_H
#define _SNACKS_H
#include "stock_item.h"
using namespace std;
//A subclass of stock item, which can be created and kept
//track of within the snacks vector of the store class
class Snacks : public Stock_item
{
private:
	int cost;
	string name;
public:
	Snacks(int scost, string sname);
	int get_cost();
	string get_name;
};
#endif 