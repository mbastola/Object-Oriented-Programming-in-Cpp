//All defnition of class FiveCardDraw

#include "stdafx.h"
#include "Game.h"
#include "FiveCardDraw.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include "player.h"
#include <fstream>
#include <string>
#include <random>
#include <queue>

using namespace std;


/*The betting phase*/
int FiveCardDraw::betting_round()
{
	unsigned highest = 0;
	int all_matched = 0;
	int i = 0;
	unsigned raised = 0;
	int length = V_player_p.size();
	//cout << "Length--> " <<  length << endl;
	while (true)
	{
		if (V_player_p[i]->in_Round)
		{
			raised = match_or_raise(*(V_player_p[i]), highest);
			//cout << "Raised--> " << raised << endl;
			if (raised != highest) /*true when there is a raise*/
				all_matched = 0;
			else
				all_matched = 1;
		}
		if (V_player_p[i]->Round_bet > highest)
		{
			highest = V_player_p[i]->Round_bet;
		}
		//cout << "highest--> " << highest << endl;
		if (i == 0 && all_matched)
			break;
		i = (i + 1) % length;
	}
	for (size_t i = 0; i < V_player_p.size(); ++i){
		if (V_player_p[i]->in_Round)
		{
			V_player_p[i]->Num_chip -= highest;
			this->table_chip += highest;
		}
	}
	return success;
}


unsigned FiveCardDraw::match_or_raise(Player& P, unsigned highest)
{

	if (unBet) /*No bets made so far*/
	{
		cout << "\nPlayer: " << P.player_name << endl;      //print player's naame
		cout << "Cards in Hand: " << P.CardsinHand << endl;
		cout << "Hello " << P.player_name << "! There has been no bet so far" << endl;
		cout << "Please input \"C\" to check or \"B\" to bet " << endl;
		string input;
		while (true){
			cin >> input;
			if (input == "C" || input == "B"){
				break;
			}
			else{
				cout << "Wrong response, please input again [C/B]" << endl;
			}
		}
		if (input == "C"){
			cout << "Player: " << P.player_name << " has checked" << endl;
			return 0;
		}
		else if (input == "B"){
			cout << "How many chips do you want to bet? [1/2]" << endl;
			string input2;
			unsigned bet=0;
			while (true){
				cin >> input2;
				if (input2 == "1" && P.Num_chip >= 1)
				{
					bet = 1;
					cout << "Player: " << P.player_name << " made a bet of 1" << endl;
					break;
				}
				else if (input2 == "1" && P.Num_chip < 1)
				{
					cout << "You do not have enough chips to bet" << endl;
					break;
				}
				else if (input2 == "2" && P.Num_chip >= 2){
					bet = 2;
					cout << "Player: " << P.player_name << " made a raise of 2" << endl;
					break;
				}
				else if (input2 == "2" && P.Num_chip < 2)
				{
					cout << "You do not have enough chips to bet. Maybe lower the bet?" << endl;
				}
				else{
					cout << "Wrong response, please input again [1/2]" << endl;
				}
			}
			P.Round_bet = bet;
			unBet = 0;
			return bet;
		}
	}
	else
	{
		if (P.Round_bet == highest)
		{
			return highest;
		}
		else
		{
			cout << "\nPlayer: " << P.player_name << endl;      //print player's naame
			cout << "Cards in Hand: " << P.CardsinHand << endl;
			cout << "Hello " << P.player_name << "! The highest bet so far is " << highest << endl;
			if (P.Num_chip >= highest)
			{
				cout << "Please input \"C\" to call, \"R\" to raise or  \"F\" to fold  " << endl;
				string input;
				while (true){
					cin >> input;
					if (input == "C" || input == "R" || input == "F"){
						break;
					}
					else{
						cout << "Wrong response, please input again [C/R/F]" << endl;
					}
				}
				if (input == "C"){
					cout << "Player: " << P.player_name << " has matched the call" << endl;
					P.Round_bet = highest;
					return highest;
				}
				else if (input == "R"){
					cout << "How many chips do you want to raise? [1/2]" << endl;
					string input2;
					unsigned bet;
					while (true){
						cin >> input2;

						if (input2 == "1" && (P.Num_chip >= highest + 1))
						{
							bet = 1;
							cout << "Player: "<< P.player_name << " made a raise of 1" << endl;
							break;
						}
						else if (input2 == "1" && (P.Num_chip < highest + 1))
						{
							cout << "You do not have enough chips to bet" << endl;
						}
						else if (input2 == "2" && (P.Num_chip >= highest + 2)){
							bet = 2;
							cout << "Player: " << P.player_name << " made a raise of 2" << endl;
							break;
						}
						else if (input2 == "2" && (P.Num_chip < highest + 2))
						{
							cout << "You do not have enough chips to bet" << endl;
						}
						else{
							cout << "Wrong response, please input again [1/2]" << endl;
						}
					}				
					P.Round_bet = (bet + highest);
					return (bet + highest);
				}
				else if (input == "F")
				{
					P.Num_chip -= P.Round_bet;
					this->table_chip += P.Round_bet;
					P.in_Round = 0;
					cout << "Player: " << P.player_name << " has folded" << endl;
					return 0;
				}
			}
			else
			{
				cout << "You do not have enough chips to call or raise" << endl;
				return 0;
			}
		}
	}
}

int FiveCardDraw::ask_discard(Player& P)
{
	while (true)
	{
		if (P.in_Round){
			int errFlag = 0;
			string S;
			cout << endl << P.player_name << "! Please input the number of cards you want to discard?" << endl;
			cin.clear();
			cin.sync();
			getline(cin, S);	//store a line from cin in the string S
			if (!S.empty()){	//if S is empty, the player does not want to discard any card, so exit
				int numDiscards;
				try {
					numDiscards = stoi(S);
				}
				catch (std::exception const & errormsg)
				{
					cout << "error : " << errormsg.what() << ". Try again " << endl;
					errFlag = 1;
				}
				if (!errFlag){
					if (numDiscards > 0 && numDiscards <= number_of_cards_in_a_hand)
					{
						cout << "Ok! We will discard " << numDiscards << " of your cards" << endl;
						while (true){
							cout << "Please enter positions of the " << numDiscards << " cards to discard separated by space" << endl;
							string discardPositions;
							getline(cin, discardPositions);
							if (discardPositions.empty()){     //if S is empty, the player does not want to discard any card, so exit 
								cout << "No poisitions to discard" << endl;
							}
							else {
								istringstream line_stream(discardPositions);
								string temp_string;
								queue<size_t> index_obtained;
								while (line_stream >> temp_string){//read substring in the S, push_back right index into the vector
									if (temp_string == "0"){
										index_obtained.push(0);
									}
									else if (temp_string == "1"){
										index_obtained.push(1);
									}
									else if (temp_string == "2"){
										index_obtained.push(2);
									}
									else if (temp_string == "3"){
										index_obtained.push(3);
									}
									else if (temp_string == "4"){
										index_obtained.push(4);
									}
								}
								if (index_obtained.size() == numDiscards){
									cout << endl << "Removing ";
									unsigned removed = 0;
									while (!index_obtained.empty()){
										auto popCard = index_obtained.front() - removed;
										FCD_Deck.add_card(P.CardsinHand[popCard]);//add choosen cards to the FCD_Deck(discard deck defined in FiveCardDraw class)
										cout << P.CardsinHand[popCard].toString() << " ";
										P.CardsinHand.remove_card(popCard);
										index_obtained.pop();
										++removed;
									}
									cout << endl << numDiscards << " cards discarded successfully" << endl;
									return success;
								}//remove choosen cards from the player's hand. I do not use try block here for remove_card method here since the index range is limited in the step above.
								else{	//the vector is empty when there is not any valid index, so do again
									cout << "Wrong input position, please try again" << endl;
								}
							}
						}
					}
					else if (numDiscards == 0){
						cout << "No card discarded" << endl;
						return success;
					}
					else if (numDiscards > number_of_cards_in_a_hand || numDiscards < 0){
						cout << numDiscards << "discards is not allowed. Please input in the range 1-5 inclusive" << endl;
					}
				}
			}
		}
	}
}

int FiveCardDraw::before_turn(Player& P){
	cout << endl;

	if (P.robot_sign == no){
		cout << "Player: " << P.player_name << "'s Turn" << endl;      //print player's
		cout << "Card in hand: " << P.CardsinHand << endl;
		ask_discard(P);
	}
	else{   //if the player is robot
		rank_of_group Hand_rank = P.CardsinHand.H_Poker_Rank();

		if (Hand_rank == no_rank){
			if (P.CardsinHand.hasACE()){    //if the last card in the hand has a ace
				size_t i = 3;		//remove the other four cards
				while (true){
					FCD_Deck.add_card(P.CardsinHand[i]);
					P.CardsinHand.remove_card(i);
					if (i == 0){ break; }
					--i;
				}
			}
			else{   //if the hand does not have ace
				size_t i = 2;   //remove three cards
				while (true){
					FCD_Deck.add_card(P.CardsinHand[i]);
					P.CardsinHand.remove_card(i);
					if (i == 0){ break; }
					--i;
				}
			}
		}//end of no_rank situation
		else if (Hand_rank==one_pair){
			Card one_of_the_pair = P.CardsinHand.A_pair();
			size_t index = number_of_cards_in_a_hand-1;
			while (true){
				if (P.CardsinHand[index].Rank != one_of_the_pair.Rank){
					FCD_Deck.add_card(P.CardsinHand[index]);
					P.CardsinHand.remove_card(index);
				}
				if (index == 0){ break; }
				--index;
			}
		}//end of one_pair situation
		else if (Hand_rank==three_of_a_kind){
			Card one_of_three = P.CardsinHand[2];   //for three_of_a_kind, the center card must belong to the three same cards
			size_t index = number_of_cards_in_a_hand-1;
			while (true){
				if (P.CardsinHand[index].Rank != one_of_three.Rank){    //if the card's rank is not same as the central one, remove it
					FCD_Deck.add_card(P.CardsinHand[index]);
					P.CardsinHand.remove_card(index);
				}
				if (index == 0){ break; }
				--index;
			}
		}//end of the three_of_a_kind situation
		else if (Hand_rank==four_of_a_kind){
			Card one_of_four = P.CardsinHand[2];	//for four_of_a_kind, the center card must belong to the four same cards
			size_t index =0;
			while (true){
				if (P.CardsinHand[index].Rank != one_of_four.Rank){
					FCD_Deck.add_card(P.CardsinHand[index]);
					P.CardsinHand.remove_card(index);
					break;
				}
				++index;
			}
		}
		else if (Hand_rank == two_pairs){   
			card_ranks_t R1 = P.CardsinHand[1].Rank;  //if the hand's rank is two_pairs, the second and the fourth(with index 1 and 3) must belong to the two pairs
			card_ranks_t R3 = P.CardsinHand[3].Rank;
			size_t index = 0;
			while (true){
				if ((P.CardsinHand[index].Rank != R1) && (P.CardsinHand[index].Rank != R3)){
					FCD_Deck.add_card(P.CardsinHand[index]);
					P.CardsinHand.remove_card(index);
					break;
				}
				++index;
			}
		}
		std::cout << P.player_name << ends;
		cout << "has  " << P.CardsinHand << "  before turn" << endl;
	}
	return success;
}

int FiveCardDraw::turn(Player& P){
	while (P.CardsinHand.size() != number_of_cards_in_a_hand){
		if (G_Deck.size() == 0 && FCD_Deck.size()!= 0){  //when the main deck become, check its size every time when a while loop begin
			FCD_Deck.shuffle_Deck();  
			P.CardsinHand << FCD_Deck;
		}
		else if(G_Deck.size() != 0){
			P.CardsinHand << G_Deck;
		}
		else if (G_Deck.size() == 0 && FCD_Deck.size() == 0){
			throw runtime_error("not enough cards in two decks");
		}
			
	}
	return success;
}

int FiveCardDraw::after_turn(Player& P)
{	
	cout << P.player_name << ends;      //print player's
	cout <<"has  "<< P.CardsinHand << "  at the end of  turn"<<endl;		//print all cards in the hand now
	cout << endl;
	return success;
}

int FiveCardDraw::before_round(){
//	cout << "before_round"<<endl;

	G_Deck.shuffle_Deck();   //shuffle the main deck
	for (int dealing_times = 0; dealing_times < number_of_cards_in_a_hand; ++dealing_times){
		
		for (size_t i = whoisDealer + 1; i < V_player_p.size() ; ++i){   //the player behind the dealer to the last player
			if (G_Deck.size() == 0 ){
				throw runtime_error("not enough cards to deal");
			}
			V_player_p[i]->CardsinHand << G_Deck;
			V_player_p[i]->Round_bet = 0;
			V_player_p[i]->in_Round = 1;
			
		}
		for (size_t i = 0; i < whoisDealer; ++i){  //the first player to the one before dealer
			if (G_Deck.size() == 0){
				throw runtime_error("not enough cards in main deck");
			}
			V_player_p[i]->CardsinHand << G_Deck;
			V_player_p[i]->Round_bet = 0;
			V_player_p[i]->in_Round = 1;
		}
	}
	/*1st Betting round*/
	cout << "\nBetting Phase 1 begins!" << endl;
	int bet_status = betting_round();
	if (bet_status == success)
		cout << "Betting Phase 1 complete!\n" << endl;

	for (size_t i = whoisDealer + 1; i < V_player_p.size(); ++i){
		before_turn(*(V_player_p[i]));
		cout << endl;
		--(V_player_p[i]->Num_chip);
		++this->table_chip;
	}
	for (size_t i = 0; i < whoisDealer; ++i){
		before_turn(*(V_player_p[i]));
		cout << endl;
		--(V_player_p[i]->Num_chip);
		++this->table_chip;
		
	}
	//cout << "Before round complete" << this->table_chip << endl;	
	return success;
}

int FiveCardDraw::round(){
	
	for (size_t i = whoisDealer + 1; i < V_player_p.size(); ++i)
	{
		int sign = turn(*(V_player_p[i]));
		//cout <<"sign "<< sign << endl;
		if (sign != success){
			return sign;
		}
		after_turn(*(V_player_p[i]));
	}
	for	(size_t i = 0; i < whoisDealer; ++i)
	{
		int	sign = turn(*(V_player_p[i]));
		if (sign != success){
			return sign;
		}
		after_turn(*(V_player_p[i]));
	}
	return success;
}

int FiveCardDraw::after_round()
{
	/*Betting Round 2*/
	
	cout << "\nBetting Phase 2 begins!" << endl;
	int bet_status = betting_round();
	if (bet_status == success)
		cout << "Betting Phase 2 complete!\n" << endl;
		
	cout << "This round ends" << endl;
	cout << "Results: \n" << endl;
	vector< shared_ptr<Player> > temp_V;

	/*~~~~~deal with the robot quit/stay~~~~~~*/
	vector< shared_ptr<Player> > robot_heighest;
	vector< shared_ptr<Player> > robot_medium;
	vector< shared_ptr<Player> > robot_lowest;
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	for (size_t i = 0; i <= V_player_p.size() - 1; ++i)
	{
		if (V_player_p[i]->in_Round)
			temp_V.push_back(V_player_p[i]);
		else
			V_player_p[i]->Num_lost++;
	}
	if (temp_V.size() == 1)
	{
		temp_V[0]->Num_won++;
		temp_V[0]->Num_chip += this->table_chip;
	}
	else
	{
		sort(temp_V.begin(), temp_V.end(), pointer_poker_rank);
		unsigned i;
		for (i = 0; i < temp_V.size(); ++i)
		{
			if (temp_V[i]->CardsinHand == temp_V[0]->CardsinHand){
				temp_V[i]->Num_won++;
				if (temp_V[i]->robot_sign == yes){      //deal with robot
					robot_heighest.push_back(temp_V[i]);
				}
			}
			else{
				break;
			}
		}
		int shared_Win = this->table_chip / i;
		//cout << "Table Chip" << this->table_chip << endl;
		//cout << "Shared Win" << shared_Win << endl;
		for (size_t j = 0; j < temp_V.size(); ++j)
		{
			if (j < i)
			{
				temp_V[j]->Num_chip += shared_Win;
			}
			else
			{
				temp_V[j]->Num_lost++;
				if ((temp_V[j]->robot_sign == yes) && (temp_V[j]->CardsinHand.size() != 0)){  //deal with robot, if the robot player is dealer, do not take it into quir/stay consideration.
					if (temp_V[j]->CardsinHand == temp_V[temp_V.size() - 2]->CardsinHand){   //the last player in the temp_V must be the dealer, since its hand is empty
						robot_lowest.push_back(temp_V[j]);									//so the actual lower hand is the player with index size-2
					}
					else{
						robot_medium.push_back(temp_V[j]);
					}
				}
			}
		}
	}
	for (size_t i = 0; i < V_player_p.size(); ++i)
	{
		cout << V_player_p[i]->player_name << endl;
		cout << "Number of wins: " << V_player_p[i]->Num_won << ends;
		cout << "  Number of loses: " << V_player_p[i]->Num_lost << ends;
		cout << "  Number of chips: " << V_player_p[i]->Num_chip << endl;
		if (i == whoisDealer){
			cout << V_player_p[i]->player_name << " is dealer of this round" << endl;
		}
		else{
			cout << V_player_p[i]->CardsinHand << endl;
			if (V_player_p[i]->in_Round)
			{
				cout << "Player stayed till the end of the round" << endl;
			}
			else
			{
				cout << "Player did not stay till the end of the round" << endl;
			}
		}
		(V_player_p[i]->CardsinHand) >> G_Deck;   //give cards back to main deck
		cout << endl;
	}
	for (size_t i = 0; i < V_player_p.size(); ++i)
	{
		if (V_player_p[i]->Num_chip == 0)
		{
			cout << V_player_p[i]->player_name << "! You have 0 chips to bet. Do you want to reset your chips?  [Y/N]" << endl;
			cout << "Note: response \"N\" will remove you from this game" << endl;
			string input;
			while (true){
				cin >> input;
				if (input == "Y" || input == "N"){
					break;
				}
				else{
					cout << "Wrong response, please input again [Y/N]" << endl;
				}
			}
			if (input == "Y"){
				V_player_p[i]->Num_chip = 20;
				cout << V_player_p[i]->player_name << "'s chip count was successfully reset" << endl;
			}
			else if (input == "N"){
				int sign = find_erasePlayer(V_player_p[i]->player_name);
				if (sign == success){
					cout << V_player_p[i]->player_name << " left" << endl;
				}
			}
		}  //player leaving completed
	}
	FCD_Deck >> G_Deck;

	
	if ( (!robot_heighest.empty()) || (!robot_lowest.empty()) || (!robot_medium.empty()) ){
		uniform_int_distribution<unsigned> uni(1, 100);
		default_random_engine DE;
		mt19937 urng(DE);
		if (!robot_heighest.empty()){
			for (size_t i = 0; i < robot_heighest.size(); ++i){
				if (uni(urng)>90){
					int sign = find_erasePlayer(robot_heighest[i]->player_name);
					if (sign == success){
						cout <<"Robot player "<< robot_heighest[i]->player_name << " left" << endl;
					}
					else if (sign == not_found_the_player){
						cout << robot_heighest[i]->player_name << " is not in game now" << endl;
					}
				}
				else{
					cout << "Robot player " << robot_heighest[i]->player_name << " will stay in game" << endl;
				}
			}
			robot_heighest.clear();
		}

		if (!robot_lowest.empty()){
			for (size_t i = 0; i < robot_lowest.size(); ++i){
				if (uni(urng)>10){
					int sign = find_erasePlayer(robot_lowest[i]->player_name);
					if (sign == success){
						cout <<"Robot player "<< robot_lowest[i]->player_name << " left" << endl;
					}
					else if (sign == not_found_the_player){
						cout << robot_lowest[i]->player_name << " is not in game now" << endl;
					}
				}
				else{
					cout << "Robot player " << robot_lowest[i]->player_name << " will stay in game" << endl;
				}

			}
			robot_lowest.clear();
		}
		if (!robot_medium.empty()){
			for (size_t i = 0; i < robot_medium.size(); ++i){
				if (uni(urng)>50){
					int sign = find_erasePlayer(robot_medium[i]->player_name);
					if (sign == success){
						cout <<"Robot player "<< robot_medium[i]->player_name << " left" << endl;
					}
					else if (sign == not_found_the_player){
						cout << robot_medium[i]->player_name << " is not in game now" << endl;
					}
				}
				else{
					cout << "Robot player " << robot_medium[i]->player_name << " will stay in game" << endl;
				}
			}
			robot_medium.clear();
		}

	}
	
	while (true)
	{
		
		cout << "Does someone want to leave game?  [Y/N]" << endl;
		string input;
		while (true){
			cin >> input;
			if (input == "Y" || input == "N"){
				break;
			}
			else{
				cout << "Wrong response, please input again [Y/N]" << endl;
			}
		}

		if (input == "N"){
			break; //no one wants to leave, leap out the while
		}else{
			cout << "Please input the name of player who wants to leave" << endl;
			string A_player;
			cin >> A_player;
			int sign=find_erasePlayer(A_player);
			if (sign == success){
				cout << A_player << " left" << endl;
			}
			else if (sign == not_found_the_player){
				cout << A_player << " is not in game now" << endl;
			}
		}
	}   //player leaving completed
	
	while (true){
		cout << "Does someone want to join in game?  [Y/N]" << endl;
		string input;
		while (true){
			cin >> input;
			if (input == "Y" || input == "N"){
				break;
			}
			else{
				cout << "Wrong response, please input again [Y/N]" << endl;
			}
		}

		if (input == "N"){
			break;
		}
		else{
			cout << "Please input the name of player who wants to join in" << endl;
			string new_player;
			cin >> new_player;
			try{
				add_player(new_player);
				cout << V_player_p[V_player_p.size()-1]->player_name << " joins in" << endl;
			}
			catch (runtime_error err){
				cout << err.what() << endl;
			}
		}
	}
	
//	cout << whoisDealer << endl;
//	cout << V_player_p.size() << endl;
	if (whoisDealer >= V_player_p.size() - 1){
		whoisDealer = 0;
	}
	else{
		++whoisDealer;
	}
	
	return success;
}

int FiveCardDraw::find_erasePlayer(const string& name){
	for (size_t i = 0; i <= V_player_p.size() - 1; ++i){
		if (V_player_p[i]->player_name == name){
			ofstream outfile;
			outfile.open(name+".txt");
			outfile << *(V_player_p[i]);
			outfile.close();
			V_player_p.erase(V_player_p.begin() + i);
			return success;
		}
	}
	return not_found_the_player;
}



