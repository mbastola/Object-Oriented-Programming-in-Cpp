//define all methods and related funtion od class Deck

#include "stdafx.h"
#include "Lab3_general.h"
#include "MyDeck.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include <sstream>


using std::vector;
using namespace std;


Deck::Deck(void){  //default constructor

}

Deck::Deck(const char* file_name){
	Deck D = Deck();
	
	_Deck = D.Load(file_name);
}


bool Deck::String_is_Meaningless(const string& a_string){
	if (a_string.empty() == true){
		return true;
	}
	else{
		for (size_t i = 0; i < a_string.size(); ++i){
			if (a_string[i] != ' '){
				return false;
			}
		}
		
		return true;
	}
}

int Deck::erase_comments(string& S){
	
	for (size_t i = 1; i < S.size(); ++i){
		if (S[i - 1] == '/' && S[i] == '/'){
			S.erase(S.begin() + i-1, S.end());
		}
	}
	return success;
}


vector<Card> Deck::Load(const char* file_name){
	ifstream infile;
	vector<Card> A_deck;
	infile.open(file_name);
	if (!infile.is_open()){
		Card wrong_sign = Card();    //use a vector contain only one invalid card to represent open file failure
		vector<Card> V_wrong_sign;
		V_wrong_sign.push_back(wrong_sign);
		return V_wrong_sign;
	}
	else{
		string t_line;
		string temp_string;
		while (infile.good()){
			getline(infile, t_line);
			if (String_is_Meaningless(t_line) == false){
				erase_comments(t_line);     //cut the part of string that behind the comment sign
				istringstream line_stream(t_line);
				while (line_stream >> temp_string && temp_string != "\n"){
					if (temp_string.size() == 2 || temp_string.size() == 3){  //only transform strings with 2 or 3 elements
						Card temp_C = Card(temp_string);      //use strings (2 or 3 elements) to construct a object with type "Card"

						if (temp_C.Rank != r_undefined && temp_C.Suit != s_undefined)
						{
							A_deck.push_back(temp_C);  // only valid card repressentations can be stored in the vector
						}

						temp_C.~Card();
					}
					temp_string.clear();
				}
				t_line.clear();
				
			}
		} //end of while
		infile.close();
		
		return A_deck;
	}	
}



int Deck::detect_status() const{  
	if (_Deck.empty())
	{
		return none_valid_card;
	}
	else if (_Deck.size()==1 && (_Deck[0].Rank==r_undefined || _Deck[0].Suit==s_undefined))
	{
		return open_file_fail;
	}
	else
	{
		return success;
	}
}


Deck &Deck::shuffle_Deck(){
	random_device rng;
	mt19937 urng(rng());
	//auto engine = std::default_random_engine{};
	//random_shuffle(_Deck.begin(), _Deck.end());
	shuffle(_Deck.begin(), _Deck.end(),urng);
	return *this;
}


vector<Card> Deck::accessor() const{
	return _Deck;
}

unsigned int Deck::size() const{
	return _Deck.size();
}

void Deck::D_push_back(const Card& A_Card){
	_Deck.push_back(A_Card);
}

void Deck::D_pop_back(){
	_Deck.pop_back();
	return;
}

ostream & operator << (ostream& os, const Deck& A_Deck){
	if (!A_Deck._Deck.empty()){
	vector <Card> VV = A_Deck._Deck;
	
	for (size_t vi = 0; vi <= VV.size() - 1; ++vi){
		os << VV[vi].toString() << "\n";
	}
	}
	return os;
}

int Deck::add_card(const Card& C){
	if (C.Rank != r_undefined && C.Suit != s_undefined){
		_Deck.push_back(C);
		return success;
	}
	else{
		
		return none_valid_card;
	}
}

void Deck::fiftytwo_Cards(){
	vector<card_ranks_t> VCR;
	VCR.push_back(two);
	VCR.push_back(three);
	VCR.push_back(four);
	VCR.push_back(five);
	VCR.push_back(six);
	VCR.push_back(seven);
	VCR.push_back(eight);
	VCR.push_back(nine);
	VCR.push_back(ten);
	VCR.push_back(Jack);
	VCR.push_back(Queen);
	VCR.push_back(King);
	VCR.push_back(ace);
	_Deck.clear();
	for (size_t i = 0; i <= VCR.size() - 1; ++i){
		_Deck.push_back(Card(VCR[i], CLUB));
	}
	for (size_t i = 0; i <= VCR.size() - 1; ++i){
		_Deck.push_back(Card(VCR[i], DIAMOND));
	}
	for (size_t i = 0; i <= VCR.size() - 1; ++i){
		_Deck.push_back(Card(VCR[i], HEART));
	}
	for (size_t i = 0; i <= VCR.size() - 1; ++i){
		_Deck.push_back(Card(VCR[i], SPADES));
	}
	
	return;
}

void Deck::operator>>(Deck& mainDeck){
	for (size_t i = 0; i < _Deck.size() ; ++i){
		mainDeck.D_push_back(_Deck[i]);
	}
	_Deck.clear();
	return;
}
