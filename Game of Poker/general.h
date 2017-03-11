//declare general content, such as enum

#ifndef GENERAL_H
#define GENERAL_H

enum error_state { success, open_file_fail, none_valid_card, error_occur,  not_enought_cards, index_out_of_range, not_found_the_player };

enum constant_used { number_of_cards_in_a_hand = 5, least_numberof_arguments=4};

enum error_for_argument{ incorrect_arguments };

//usage_message function
int usage_message();


#endif
