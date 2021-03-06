//declare all the contents related to struct Card

#ifndef MYCARD_H
#define MYCARD_H

#include "Lab3_general.h"
#include <string>

using std::string;

//declare enum 
enum card_ranks_t { two = 2, three, four, five, six, seven, eight, nine, ten, Jack, Queen, King, ace, r_undefined = 15 };

enum  card_suits_t { CLUB = 20, DIAMOND, HEART, SPADES, s_undefined };         //r_undefined and s_undefined are used to label invalid card definition string

//declare a struct to represent a single card
struct Card {   //The definition of this struct's methods are in the MyCard.cpp

	//2 member varibles
	card_ranks_t Rank;
	card_suits_t Suit;
	bool faceUp;
	Card(void);   //default empty constructor
	Card(const string& S);   //a constructor that read a string to initialize a Card
	Card(const card_ranks_t&, const card_suits_t&);
	~Card() {};  //destructor
	bool operator< (const Card&) const;  //declaration of operator<, in header file white bool operator<`````, not Card::operator< `````
	bool operator== (const Card&) const;
	bool operator!=(const Card&) const;
	string toString() const;  //this method is used to transform a single Card object to a corresponding string
	

};



#endif
