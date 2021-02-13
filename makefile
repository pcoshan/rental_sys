all: main.cpp 
	g++ main.cpp user.cpp rental.cpp store.cpp id_track.cpp movie.cpp game.cpp store_creator.cpp -omain

test: user_test rental_test store_test
	./user_test
	./rental_test
	./store_test

user_test: usertesting.cpp
	g++ usertesting.cpp user.cpp -o user_test

rental_test: rental_testing.cpp
	g++ rental_testing.cpp rental.cpp movie.cpp -o rental_test 

store_test: store_testing.cpp
	g++ store_testing.cpp store_creator.cpp store.cpp rental.cpp user.cpp movie.cpp game.cpp id_track.cpp -o store_test