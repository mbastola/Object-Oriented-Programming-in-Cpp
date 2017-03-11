// PlayPoker.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "general.h"
#include "MyCard.h"
#include "MyDeck.h"
#include "MyHand.h"
#include "player.h"
#include "Game.h"
#include "FiveCardDraw.h"

int main(int argc, char* argv[])
{
	if (argc < least_numberof_arguments){
		int errorsign = usage_message();
		return errorsign;
	}


	string Game_name(argv[1]);


	try{ Game::start_game(Game_name); }
	catch (runtime_error err){
		cout << err.what() << endl;
		return error_occur;
	}

	try{
		shared_ptr<Game> PG = Game::instance();

		for (int i = 2; i < argc; ++i){
			string Name_p(argv[i]);
			try{ PG->add_player(Name_p); }
			catch (runtime_error err){
				cout << Name_p << " " << err.what() << endl;  //just notify the the player is in game
			}												//if there are enough player, game continues
		}

		while (PG->Num_player() >= 2){   //at least 2 player
			PG->before_round();
			PG->round();
			PG->after_round();
		}
	}
	catch (runtime_error err){
		cout << err.what() << endl;
		Game::stop_game();
		return error_occur;
	}


	try{
		Game::stop_game();
		cout << "not enought player in game" << endl;
	}
	catch (runtime_error err){
		cout << err.what() << endl;
		return no_game_in_progress;
	}
	return success;
}


