//header file for struct player

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "MyHand.h"
#include <iostream>
#include <memory>
#include <fstream>

enum robot{no, yes};

using std::string;
using namespace std;

struct Player{
	string player_name;
	Hand CardsinHand;
	unsigned int Num_won;
	unsigned int Num_lost;
	unsigned int Num_chip;
	unsigned int Round_bet;
	unsigned int in_Round;
	robot robot_sign;

	Player(const char* name)   //constructor
		: player_name(name), Num_won(0), Num_lost(0), Num_chip(20), Round_bet(0),in_Round(0), robot_sign(no){
		ifstream infile;
		string name_P(name);		
		infile.open(name_P+".txt");
		if (infile.is_open()){
			string S1,S2,S3,S4;
			infile >> S1;
			infile >> S2;
			infile >> S3;
			infile >> S4;
			player_name = S1;
			Num_won = stoi(S2, nullptr, 10);
			Num_lost = stoi(S3, nullptr, 10);
			Num_chip = stoi(S4, nullptr, 10);
		}
		infile.close();
	};  

	Player(const string& name, const robot& sign)   //constructor, when the player is robot
		: player_name(name), Num_won(0), Num_lost(0), robot_sign(sign){
		ifstream infile;
		infile.open(name + ".txt");
		if (infile.is_open()){
			string S1, S2, S3,S4;
			infile >> S1;
			infile >> S2;
			infile >> S3;
			infile >> S4;
			player_name = S1;
			Num_won = stoi(S2, nullptr, 10);
			Num_lost = stoi(S3, nullptr, 10);
			Num_chip = stoi(S4, nullptr, 10);
		}
		infile.close();
	};
};

ostream& operator<<(ostream& os, const Player& A_player);

bool pointer_poker_rank(const shared_ptr<Player> P1, const shared_ptr<Player> P2) ;

#endif
