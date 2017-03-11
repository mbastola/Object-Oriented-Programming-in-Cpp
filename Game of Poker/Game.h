//written by JIFEI LI

#ifndef GAME_H
#define GAME_H

#include "MyDeck.h"
#include "player.h"
#include <vector>
#include <memory>
#include <string>

enum exception_in_Game
{
	instance_not_available=-10, gmae_already_started, unknow_game, no_game_in_progress, already_playing
};

class Game{
private:
	void storePlayerrecord() const;
 

protected:
	static shared_ptr<Game> P_game;
	Deck G_Deck;    //main deck
	vector< shared_ptr<Player> > V_player_p;
	

public:
	
	Game() {
	};
	static shared_ptr<Game> instance();
	static void start_game(const string S);
	static void stop_game();
	void add_player(const string& S);
	shared_ptr<Player> find_player(const string& S);
	

	virtual int before_turn(Player&) =0;
	virtual int turn(Player&) = 0;
	virtual int after_turn(Player&) = 0;
	virtual int before_round() = 0;
	virtual int round() = 0;
	virtual int after_round() = 0;

	size_t Num_player() const;
	
};





#endif