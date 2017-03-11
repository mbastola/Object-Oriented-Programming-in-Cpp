#ifndef FIVECARDDRAW_H
#define FIVECARDDRAW_H

#include "Game.h"
#include "MyCard.h"
#include "Lab3_general.h"

class FiveCardDraw :public Game{
private:
	int find_erasePlayer(const string&);  //give a string(name), find it in the vector holds pointers to Player
									// if found, erase it
	unsigned int table_chip; //common pot of chips
	int unBet;

protected:
	size_t whoisDealer;
	Deck FCD_Deck;   //discarded card deck

public:
	FiveCardDraw() :table_chip(0),unBet(1),whoisDealer(0){  //constructor
		G_Deck.fiftytwo_Cards();
	};
	virtual unsigned match_or_raise(Player& P, unsigned highest);
	virtual int betting_round();
	int ask_discard(Player& P);
	virtual int before_turn(Player&); //print out the player's cards in ahnd, and ask wheather discard cards
	virtual int turn(Player&);		//fill the hand to five cards
	virtual int after_turn(Player&);  //print out player name and cards in hand
	virtual int before_round();    //shuffle deck, deal cards to every player
	virtual int round();
	virtual int after_round();
};


#endif