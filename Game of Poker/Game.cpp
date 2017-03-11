//written by JIFEI LI 
//All defnition of class Game

#include "stdafx.h"
#include "Game.h"
#include <string>
#include <memory>
#include "FiveCardDraw.h"

shared_ptr<Game> Game::P_game = nullptr;  //P_game initialized to singular

shared_ptr<Game> Game::instance(){
	if (P_game == nullptr){
		throw runtime_error("instance_not_available ");
	}
	else{
		
		return P_game;
	}
}

void Game::start_game(const string S){
	if (P_game != nullptr){
		throw runtime_error("gmae_already_started");
	}
	else if (S.find("FiveCardDraw")==string::npos){
		throw runtime_error("unknow_game");
	}
	else{
		P_game = make_shared<FiveCardDraw> ();
	}
	return;
}

void Game::stop_game(){
	if (P_game == nullptr){
		throw runtime_error("no_game_in_progress");
	}
	else{
		P_game->storePlayerrecord();
		P_game = nullptr;
	}
}

void Game::add_player(const string& S){
	if (S[S.size() - 1] == '*'){
		string actual_name(S);
		actual_name.erase(actual_name.size() - 1);  //erase the *
		if (V_player_p.empty() == false){
			for (size_t i = 0; i < V_player_p.size(); ++i){
				if (V_player_p[i]->player_name == actual_name){   //player_name is a string
					throw runtime_error("already_playing");
				}
			}
		}

		shared_ptr< Player > P_new_player = std::make_shared<Player>(actual_name,yes);   //allocate a new player, set its robot_state to yes
		(this->V_player_p).push_back(P_new_player);


	}
	else{
		if (V_player_p.empty() == false){
			for (size_t i = 0; i < V_player_p.size(); ++i){
				if (V_player_p[i]->player_name == S){   //player_name is a string
					throw runtime_error("already_playing");
				}
			}
		}

		shared_ptr< Player > P_new_player = std::make_shared<Player>(S.c_str());
		(this->V_player_p).push_back(P_new_player);
	}
	return;
}

shared_ptr<Player> Game::find_player(const string& S){
	if (V_player_p.empty() == false){
		for (size_t i = 0; i <= V_player_p.size() - 1; ++i){
			if (V_player_p[i]->player_name == S){
				return V_player_p[i];
			}
		}
	}
	return nullptr;
}

size_t Game::Num_player() const{
	return V_player_p.size();
}


void Game::storePlayerrecord() const{
	if (!V_player_p.empty()){
		for (size_t i = 0; i < V_player_p.size(); ++i){
			ofstream outfile;
			outfile.open(V_player_p[i]->player_name + ".txt");
			outfile << *(V_player_p[i]);
			outfile.close();
		}
	
	
	}

}
