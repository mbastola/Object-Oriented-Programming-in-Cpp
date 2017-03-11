//declare all the contents related to class Deck

#ifndef MYHAND_H
#define MYHAND_H

#include <vector>
#include <string>

#include "Lab3_general.h"
#include "MyCard.h"
#include "MyDeck.h"

using namespace std;
using std::vector;
using std::string;

enum rank_of_group {
	straight_flush = 31, four_of_a_kind, full_house, is_flush, is_stright, three_of_a_kind,
	two_pairs, one_pair, no_rank, r_g_undefined
};

class Hand{  //all related definitions are in the MyHand.cpp
private:
	vector<Card> _Hand;

	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	//following 5 functions are used to help identifying poker rank. They will be called in function "H_Poker_Rank"
	bool isflush() const;
	bool isstraight() const;
	int pairs_num() const;
	bool Second_forth() const;
	int sameASmid() const;
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

public:
	Hand(void);  //default constructor
	Hand(const Hand&); //copy constructor
	//destrucotr
	Hand& operator=(const Hand& A_Hand); //assignment operator overloading
	unsigned int size() const;
	vector<Card> accessor_H(void) const;
	bool operator== (const Hand&) const;
	bool operator< (const Hand&) const;
	string as_string() const;
	rank_of_group H_Poker_Rank() const; //this method is used to indentify the poker rank of a hand of card

	friend ostream &operator << (ostream &, const Hand&); //insertion operator overloading for type Hand, its definition is in MyHand.cpp
	friend Hand &operator << (Hand&, Deck&);  //definition in MyHand.cpp.   This insertion operator is used to deal
	void operator>>(Deck&); //this is a member operator, used to give back all cards to a deck from a hand, i.e. after calling, the hand is empty (used in class FiveCardDraw, after_round)
	friend bool poker_rank(const Hand& Hand1, const Hand& Hand2);  // this function compare two hands of card. Return true when first hand ranks higher than the second

	

	//following two methods are used in function "poker_rank"
	Card A_pair() const; //This method is used to read a sorted vecotr containing cards. When it meets a pair, this function will return one card of that pair
	vector<Card> single_card() const; //This method is used to a sorted vecotr containing cards. Return  a vector containing all cards that only appear once

	Card operator[](size_t index) const;    //use index to access a Hand, remember to write exception
	int remove_card(size_t index);     //remove a card from a hand by using index, remember to write exception

	bool hasACE() const;  //if the rank of last card in this hand is ace, return true. used in FiveCardDraw class's before_turn method, to detect wheather a sorted hand containing a ace
};



#endif
