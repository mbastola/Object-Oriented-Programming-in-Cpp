//declare all the contents related to class Deck

#ifndef MYDECK_H
#define MYDECK_H

#include <vector>
#include <string>
#include <iostream>
#include "Lab3_general.h"
#include "MyCard.h"

using namespace std;
using std::vector;
using std::string;

class Deck{   //Methods and operator overloading definitions are in the MyDeck.cpp
private:
	vector<Card> _Deck;

	//following two methods are used in the "Load"
	bool String_is_Meaningless(const string&);
	int erase_comments(string&); //erase content after commentt symbol

public:
	Deck(void); //Default constructor
	Deck(const char* file_name);
	//a constructor takes file name. Since constructor has not return value, 
	//after each time of construting a new object, it must use method "detect_status" to make sure the deck object is valid

	
	vector<Card> Load(const char* file_name);
	int detect_status() const;   //this method is used to check the status of a object of Deck type. There are 3 kinds of return value: success, no_valid_card and open_file_fail
	Deck &shuffle_Deck(); //shuffle the cards in the Deck
	vector<Card> accessor() const; //This is the accessor of tthis class
	unsigned int size() const;
	void D_push_back(const Card&);
	void D_pop_back(); //this method is used to remove the last element of a Deck object
	void fiftytwo_Cards();   //filled a deck with 52 cards, there are whole combination of all 13 ranks and 4 suits

	friend ostream &operator << (ostream &, const Deck&); //this insertion is used to output objects with type Deck. Its definition also in MyDeck.cpp

	int add_card(const Card&);   //add a single card to the deck
	void operator>>(Deck&);   //used to return cards in discard Deck to main deck, called in FiveCardDraw class, after_round()
};


#endif
