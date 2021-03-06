//This file contains all methods of class "Hand" and and 5 auxiliary functions that help to 
//identify a hand's rank
//friends of "Hand" also defined in this file



#include "stdafx.h"
#include "Lab3_general.h"
#include "MyHand.h"
#include <vector>
#include <string>
#include <algorithm>

using namespace std;



Hand::Hand(void){
}

Hand::Hand(const Hand& A_Hand){      //copy constructor
	//*this = A_Hand;
	this->_Hand = A_Hand.accessor_H();
}


Hand& Hand::operator=(const Hand& A_Hand){		//assgiment operator overloading
												//return value is also Hand type
	if (*this == A_Hand){
		return *this;
	}
	else{
	//*this = Hand(A_Hand);
	this->_Hand = A_Hand.accessor_H();
	return *this;  //using copy constructor 
	}
}

unsigned int Hand::size() const{
	return _Hand.size();
}

vector<Card> Hand::accessor_H(void) const{
	return this->_Hand;
}

bool Hand::operator== (const Hand& A_Hand) const{
	if (_Hand.size() != number_of_cards_in_a_hand || A_Hand.size() != number_of_cards_in_a_hand){
		return false;
	}

	for (size_t i = 0; i < _Hand.size(); ++i){
		if (_Hand[i] != A_Hand[i]){
			return false;
		}
	}
	return true;
	
}

bool Hand::operator< (const Hand& A_Hand) const{    //operator < overloading, compare two hands
	
		for (size_t i = 0; i <= _Hand.size()-1; ++i) //compare corresponding elements from first one
		{											//when "less than" detected, return true
			if (_Hand[i] != (A_Hand.accessor_H())[i]){  // if_Hand[i] == (A_Hand.accessor_H())[i]), proceed to next index
				if (_Hand[i] < (A_Hand.accessor_H())[i])
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}
		
		return false;  //all of their elements are same, A<B is not true, return false

}

string Hand::as_string() const{
	
	string S = _Hand[0].toString();

	for (size_t i = 1; i < _Hand.size(); ++i)
	{
		S = S + " "+_Hand[i].toString();
	}

	return S;
}


ostream &operator << (ostream & os, const Hand& A_Hand){
	if (A_Hand.size()>0){
	os << A_Hand.as_string();
	}
	return os;
}

Hand &operator << (Hand& V_Hand, Deck& V_Deck ){    //used to deal
	unsigned int last_index = V_Deck.size() - 1;
	V_Hand._Hand.push_back(V_Deck.accessor()[last_index]); //add a card from back of a Deck to a Hand
	V_Deck.D_pop_back();		//remove the last card from a Deck
	sort(V_Hand._Hand.begin(), V_Hand._Hand.end()); 
	return V_Hand;
}

void Hand::operator>>(Deck& A_Deck){
	for (size_t i=0; i < _Hand.size() ; ++i){
		A_Deck.D_push_back(_Hand[i]);
	}
	_Hand.clear();
	return;
}


bool Hand::isflush() const{   //test if sorted cards have same suit
	for (size_t i = 1; i <= _Hand.size() - 1; ++i)
	{
		if (_Hand[i].Suit != _Hand[0].Suit)
		{
			return false;
		}
	}
	return true;
}

bool Hand::isstraight() const{   //test if sorted cards have consecutive ranks
	for (size_t i = 1; i <= _Hand.size() - 1; ++i){
		if ((_Hand[i - 1].Rank + 1) != (_Hand[i].Rank)){
			return false;
		}
	}
	return true;
}

int Hand::pairs_num() const{      //check the possible pairs in a hand of card, the return value can be 0 1 2 3 4, 4 means all cards are same
	int num_pair = 0;
	for (size_t i = 0; i <= _Hand.size() - 2; i++)
	{
		if (_Hand[i].Rank == _Hand[i + 1].Rank)
		{
			num_pair = num_pair + 1;
		}
	}
	return num_pair;
}

bool Hand::Second_forth() const{   //test wheather the second card in a sorted hand is same as the forth card
	if (_Hand[1].Rank == _Hand[3].Rank){
		return true;
	}
	else{
		return false;
	}
}

int Hand::sameASmid() const{    //homw many cards are same as the middle one in a hand of card, return value can be 1 at least
	int num = 0;
	for (size_t i = 0; i <= _Hand.size() - 1; ++i)
	{
		if (_Hand[i].Rank == _Hand[2].Rank)
		{
			num = num + 1;
		}
	}
	return num;
}


rank_of_group Hand::H_Poker_Rank() const{

	if (_Hand.size() == number_of_cards_in_a_hand){

		//unnecessary to sort, every hand is sorted when dealing

		if (isstraight() == true){ //check wheather the hand is stright at first
			if (isflush() == true){  //cheak if it's flust
				return straight_flush;
			}
			else{
				return is_stright;
			}
		}
		else
		{
			if (isflush() == true)
			{
				return is_flush;
			}
			else{   //by so far, we can make sure it is not stright flust, flush or stright
				if (pairs_num() == 1)   //check how many pairs we can pick out from a hand of card
				{
					return one_pair;
				}
				else if (pairs_num() == 0){
					return no_rank;
				}
				else if (pairs_num() == 3){  //if there might be 3 pairs picked up, the hand can be "four of a kind" or "full house"
					if (Second_forth() == true) //check wheather the fourth and the second card are same
					{
						return four_of_a_kind;
					}
					else{
						return full_house;
					}
				}
				else if (pairs_num() == 2){  //if there might be 2 pairs picked up, the hand can be "three of a kind" or "2 pairs"
					if (sameASmid() == 3)    //check how many cards are same as the central card
					{
						return three_of_a_kind;	//since the hand is sorted, the central card must belong to the 3 cards with same rank.
					}
					else{
						return two_pairs;
					}
				}
				else{
					return r_g_undefined;
				}
			}
		}

	}
	else{
		return r_g_undefined;
	}
}



bool poker_rank(const Hand& Hand1, const Hand& Hand2){  //Return true only when first hand ranks higher than the second
	const rank_of_group R1 = Hand1.H_Poker_Rank();
	const rank_of_group R2 = Hand2.H_Poker_Rank();
	//unnecessary to sort the sub_V, every hand is sorted when dealing

	if(R1==R2){
		if (R1 == straight_flush){
			return (Hand2._Hand[4] < Hand1._Hand[4]); //compare  the highest card of two hands
		}
		else if (R1 == four_of_a_kind){  //if they are four of a kind, the card at center position must belong to the 4 with same rank
			return (Hand2._Hand[2] < Hand1._Hand[2]);
		}
		else if (R1 == full_house){
			if (Hand2._Hand[2] == Hand1._Hand[2]){   //if two cards at center same
				if ((Hand2._Hand[0] == Hand2._Hand[2]) && (Hand1._Hand[0]== Hand1._Hand[2])){ //compare if the first cards are same
					return Hand2._Hand[4] < Hand1._Hand[4];
				}
				else if ((Hand2._Hand[4] == Hand2._Hand[2]) && (Hand1._Hand[4] == Hand1._Hand[2])){
					return Hand2._Hand[0] < Hand1._Hand[0];
				}
				else{
					return Hand2._Hand[4] < Hand1._Hand[4];
				}

			}
			else{
				return (Hand2._Hand[2] < Hand1._Hand[2]); //if two hands are full house, the center must be one of the three
			}

		}
		else if (R1 == is_flush){
			for (size_t i = 4; i >= 0; i--)
			{
				if (Hand2._Hand[i].Rank != Hand1._Hand[i].Rank){
					return (Hand2._Hand[i] < Hand1._Hand[i]);
				}
			}
			return false; //if all elements are same, then first hand does not rank higher than the second
		}
		else if (R1 == is_stright){
			return Hand2._Hand[4] < Hand1._Hand[4]; //also compare the highest carda
		}
		else if (R1 == three_of_a_kind){
			return Hand2._Hand[2] < Hand1._Hand[2]; //when they are three of a kind, the center card must belong to the 3 ones
		}
		else if (R1 == two_pairs){
			if ((Hand2._Hand[3] == Hand1._Hand[3]) && (Hand2._Hand[1] == Hand1._Hand[1])){
				Card C1, C2;
				
				for (size_t i = 0; i < number_of_cards_in_a_hand; i++)
				{
					if (((Hand1._Hand[i] == Hand1._Hand[3]) == false) && (Hand1._Hand[i] != Hand1._Hand[1])){  //for hand1, if the element with index i is not equal to the second and fourth
						C1 = Hand1._Hand[i];
					}
				}

				for (size_t i = 0; i < number_of_cards_in_a_hand; i++)////for hand2, if the element with index i is not equal to the second and fourth
				{
					if (((Hand2._Hand[i] == Hand2._Hand[3]) == false) && (Hand2._Hand[i] != Hand2._Hand[1])){
						C1 = Hand2._Hand[i];
					}
				}

				return C2 < C1;

			}
			else if (Hand2._Hand[3] == Hand1._Hand[3]){
				return Hand2._Hand[1] < Hand1._Hand[1];
			}
			else{
				return Hand2._Hand[3] < Hand1._Hand[3];
			}


		}
		else if (R1 == one_pair){
			Card P1 = Hand1.A_pair();
			Card P2 = Hand2.A_pair();
			if (P1 == P2){
				vector<Card> V1 = Hand1.single_card();
				vector<Card> V2 = Hand2.single_card();
				for (size_t i =( V1.size()-1); i >= 0; i--)
				{
					if (V1[i] != V2[i]){
						return (V2[i] < V1[i]);
					}
				}
				return false; //if all elements are same, then first hand does not rank higher than the second
			}
			else{
				return (P2 < P1);
			}

		}
		else if (R1 == no_rank){
			for (size_t i = 4; i >= 0; i--)
			{
				if (Hand2._Hand[i] != Hand1._Hand[i]){ 
					return (Hand2._Hand[i] < Hand1._Hand[i]);
				}
			}
			return false; //if all elements are same, then first hand does not rank higher than the second
		}
	}
	else{
		    // if H_Poker_Rank different
			return (R1 < R2);  //when R1<R2, return true. This is according the declared enum 
		}

	return false;
}


Card Hand::A_pair() const{ //the object(a Hand) call this method must be a sorted Hand , and must be "one pair"
	
	for (size_t i = 1; i <= (this->size()-1); i++)   
	{
		if (_Hand[i - 1].Rank == _Hand[i].Rank){  //when a pair is found, immediately return 
			return _Hand[i];
		}
	}

	Card no_result_sign = Card();
	return no_result_sign;
}

vector<Card> Hand::single_card() const{  //the object(a Hand) call this method must be a sorted Hand , and must be "one pair"
	Card P = this->A_pair();
	vector<Card> V;
	for (size_t i = 0; i <= (this->size() - 1); i++)
	{
		if (_Hand[i] != P){
			V.push_back(_Hand[i]);
		}
	}
	return V;
}

Card Hand::operator[](size_t index) const{
	
		if (index >= 0 && index <= (_Hand.size() - 1)){
			return _Hand[index];
		}
		else
		{
			Card D;
			return D;  //return a undefined Card
		}
}

int Hand::remove_card(size_t index){
	if (index >= 0 && index <= (_Hand.size() - 1)){
		_Hand.erase(_Hand.begin() + index);
		return success;
	}
	else
	{
		throw runtime_error( "index_out_of_range");
	}
}

bool Hand::hasACE() const{
	size_t last_index = _Hand.size() - 1;
	return _Hand[last_index].Rank == ace;
}
