//This source file is used to define methods and operators in struct Card
//JIFEI LI wrote

#include "stdafx.h"
#include "MyCard.h"
#include <string>



bool Card::operator< (const Card &compare_card) const{
	return (Rank < compare_card.Rank) || ((Rank == compare_card.Rank) && (Suit < compare_card.Suit));   //compare the rank firstly, if rank is same, compare suit
}



bool Card::operator== (const Card &compare_card) const{
	return (Rank == compare_card.Rank) && (Suit ==compare_card.Suit);   //rank and suit are same
}


bool Card::operator!= (const Card &compare_card) const{
	return (Rank != compare_card.Rank) || (Suit != compare_card.Suit);   //rank or suit different => cards are different
}

Card::Card(void){
	Suit = s_undefined;
	Rank = r_undefined;
	faceUp = true;	
}

Card::Card(const string& S){   //a constructor, take a string, and construct a Card onject. Invalid card will be transfered to "undefined" for further processing 
	
	if (S.size() == 2){       //when the string has two character
		if (S[1] == 'D' || S[1] == 'd'){
			Suit = DIAMOND;
		}
		else if (S[1] == 'C' || S[1] == 'c'){
			Suit = CLUB;
		}
		else if (S[1] == 'S' || S[1] == 's'){
			Suit = SPADES;
		}
		else if (S[1] == 'h' || S[1] == 'H'){
			Suit = HEART;
		}
		else{
			Suit = s_undefined;
		};

		if (S[0] == 'a' || S[0] == 'A'){
			Rank = ace;
		}
		else if (S[0] == '3'){
			Rank = three;
		}
		else if (S[0] == '2'){
			Rank = two;
		}
		else if (S[0] == '4'){
			Rank = four;
		}
		else if (S[0] == '5'){
			Rank = five;
		}
		else if (S[0] == '6'){
			Rank = six;
		}
		else if (S[0] == '7'){
			Rank = seven;
		}
		else if (S[0] == '8'){
			Rank = eight;
		}
		else if (S[0] == '9'){
			Rank = nine;
		}
		else if (S[0] == 'j' || S[0] == 'J'){
			Rank = Jack;
		}
		else if (S[0] == 'q' || S[0] == 'Q'){
			Rank = Queen;
		}
		else if (S[0] == 'k' || S[0] == 'K'){
			Rank = King;
		}

		else{
			Rank = r_undefined;

		};

	}
	else if (S.size() == 3){ //when the sting has three character
		if (S[0] == '1' && S[1] == '0'){
			Rank = ten;

			if (S[2] == 'D' || S[2] == 'd'){
				Suit = DIAMOND;
			}
			else if (S[2] == 'C' || S[2] == 'c'){
				Suit = CLUB;
			}
			else if (S[2] == 'S' || S[2] == 's'){
				Suit = SPADES;
			}
			else if (S[2] == 'h' || S[2] == 'H'){
				Suit = HEART;
			}
			else{

				Suit = s_undefined;     // if a card object's Suit==s_undefined or its Rank==r_undefined, then it must be invalid
			};

		}
		else
		{

			Rank = r_undefined;
			Suit = s_undefined;
		}


	}
	else{
		Rank = r_undefined;
		Suit = s_undefined;
	}

	
}

//this method return the corresponding string of the Card which calls it
string Card::toString() const
{   
	if (!faceUp){
		return "*";
	}
	string S_rank, S_suit;
	if (Suit == DIAMOND){
		S_suit = { "D" };
	}
	else if (Suit == SPADES){
		S_suit = { "S" };
	}
	else if (Suit == CLUB){
		S_suit = { "C" };
	}
	else if (Suit == HEART){
		S_suit = { "H" };
	}

	if (Rank == ace){
		S_rank = { "A" };
	}
	else if (Rank == two){
		S_rank = { "2" };
	}
	else if (Rank == three){
		S_rank = { "3" };
	}
	else if (Rank == four){
		S_rank = { "4" };
	}
	else if (Rank == five){
		S_rank = { "5" };
	}
	else if (Rank == six){
		S_rank = { "6" };
	}
	else if (Rank == seven){
		S_rank = { "7" };
	}
	else if (Rank == eight){
		S_rank = { "8" };
	}
	else if (Rank == nine){
		S_rank = { "9" };
	}
	else if (Rank == ten){
		S_rank = { "10" };
	}
	else if (Rank == Jack){
		S_rank = { "J" };
	}
	else if (Rank == Queen){
		S_rank = { "Q" };
	}
	else if (Rank == King){
		S_rank = { "K" };
	}

	return S_rank + S_suit;
}

Card::Card(const card_ranks_t& R, const card_suits_t& S){
	Rank = R;
	Suit = S;
}
