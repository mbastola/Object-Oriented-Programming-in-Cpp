//Source file name: usage_message.cpp
//print usage_message

#include "stdafx.h"
#include "Lab3_general.h"
#include <iostream>

using namespace std;

int usage_message(){
	
	cout << "The name of this program is Lab3" << endl;
	
	cout << endl;
	cout << "acceptable formats" << endl;
	cout << "Lab3 <file_name> <play_name> <player_name> ....." << endl;
	cout << "You should give at least two player's name" << endl;
	cout << "append * as last character of playname to play automatically" << endl;
	cout << "example format: <ABC*> " << endl;

	return incorrect_arguments;
}
