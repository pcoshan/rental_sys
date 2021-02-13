#include <iostream>
#include <string>
#include "rental.h"
#include "game.h"
using namespace std;
//constructor for a game 
Game::Game(string gconsole, int gcost, string gtitle, int gnum_copies) : Rental(gtitle, gnum_copies){
	cost = gcost;
	console = gconsole;
}
//returns the cost of the specific rental
int Game::get_cost(){
	return cost;
}
//virtual function displays the rental type
void Game::print_rental_type(){
	cout << "Game Rental" << endl;
}