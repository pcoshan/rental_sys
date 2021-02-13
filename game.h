#ifndef _GAME_H
#define _GAME_H
#include <iostream>
#include <string>
#include "rental.h"
using namespace std;
//Game is a subclass of rental
class Game : public Rental
{
private:
	int cost;
public:
	string console;
	int get_cost();
	Game(string gconsole, int gcost, string gtitle, int gnum_copies);
	void print_rental_type();
	
};

#endif