//definitions relared to struct player

#include "stdafx.h"
#include "player.h"
#include <fstream>
#include <iostream>
#include "MyHand.h"
#include <memory>

using namespace std;

ostream& operator<<(ostream& os, const Player& A_player){
	os << A_player.player_name << " "
		<< A_player.Num_won << " " << A_player.Num_lost << " " << A_player.Num_chip;
	return os;
}

bool pointer_poker_rank(const shared_ptr<Player> P1, const shared_ptr<Player> P2) {
	if (P1 == nullptr){   //returns false if the first pointer is singular
		return false;
	}
	else if ((P1!=nullptr) && (P2 == nullptr)){   // if first is non-singular returns true if the second pointer is singular
		return true;
	}
	else{
		return poker_rank(P1->CardsinHand, P2->CardsinHand);
	}
}

