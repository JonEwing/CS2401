/*************************************************************
    HW6        CS2401      Spring 2017
    Jonathan Feige
    This is the footer file for the game class
    and all of its child classes
**************************************************************/
#include <cassert>    // Provides assert
#include <climits>    // Provides INT_MAX and INT_MIN
#include <iostream>   // Provides cin, cout
#include <queue>      // Provides queue<string>
#include <string>     // Provides string
#include <cstring>
#include <cstdlib>
#include "game.h"     // Provides definition of game class
#include "space.h"
#include "colors.h"
using namespace std;

namespace main_savitch_14
{
    //*************************************************************************
    // STATIC MEMBER CONSTANTS
    // const int game::SEARCH_LEVELS;
    
    //*************************************************************************
    // PUBLIC MEMBER FUNCTIONS

    game::who game::play( )
    // The play function should not be overridden. It plays one round of the
    // game, with the human player moving first and the computer second.
    // The return value is the winner of the game (or NEUTRAL for a tie).
    {
	restart( );
// Note that as you develop the game you will be gradually un-commenting 
// this function.	
	//while (!is_game_over( )) // un-comment this
	//{
	    display_status( );
	//    if (last_mover( ) == COMPUTER)
		make_human_move( );
	//    else
	//	make_computer_move( );
	//}
	display_status( );
	return HUMAN;
    }


    
    //*************************************************************************
    // OPTIONAL VIRTUAL FUNCTIONS (overriding these functions is optional)

    void game::display_message(const string& message) const
    {
	cout << message;
    }

    string game::get_user_move( ) const
    {
	string answer;
	
	display_message("Your move, please: ");
	getline(cin, answer);
	return answer;
    }

    game::who game::winning( ) const
    {
	int value = evaluate( ); // Evaluate based on move that was just made.

	if (value > 0)
	    return last_mover( );
	else if (value < 0)
	    return next_mover( );
	else
	    return NEUTRAL;
    }



    //*************************************************************************
    // PRIVATE FUNCTIONS (these are the same for every game)

    int game::eval_with_lookahead(int look_ahead, int beat_this)
    // Evaluate a board position with lookahead.
    // --int look_aheads:  How deep the lookahead should go to evaluate the move.
    // --int beat_this: Value of another move that we?re considering. If the
    // current board position can't beat this, then cut it short.
    // The return value is large if the position is good for the player who just
    // moved. 
    {
    	queue<string> moves;   // All possible opponent moves
	int value;             // Value of a board position after opponent moves
    	int best_value;        // Evaluation of best opponent move
    	game* future;          // Pointer to a future version of this game
	
        // Base case:
	if (look_ahead == 0 || is_game_over( ))
	{
	    if (last_mover( ) == COMPUTER)
	            return evaluate( );
	    else
		return -evaluate( );
	}

        // Recursive case:
        // The level is above 0, so try all possible opponent moves. Keep the
	// value of the best of these moves from the opponent's perspective.
    	compute_moves(moves); 
	// assert(!moves.empty( ));
    	best_value = INT_MIN;
    	while (!moves.empty( ))
    	{
	    future = clone( );
	    future->make_move(moves.front( ));
	    value = future->eval_with_lookahead(look_ahead-1, best_value);
	    delete future;
	    if (value > best_value)
	    {
		best_value = value;
	    }
	    moves.pop( );
    	}

    	// The value was calculated from the opponent's perspective.
    	// The answer we return should be from player's perspective, so multiply times -1:
    	return -best_value;
    }

    void game::make_computer_move( )
    {
	queue<string> moves;
	int value;
	int best_value;
	string best_move;
	game* future;
	
	// Compute all legal moves that the computer could make.
	compute_moves(moves);
	assert(!moves.empty( ));
	
	// Evaluate each possible legal move, saving the index of the best
	// in best_index and saving its value in best_value.
	best_value = INT_MIN;
	while (!moves.empty( ))
	{
	    future = clone( );
	    future->make_move(moves.front( ));
	    value = future->eval_with_lookahead(SEARCH_LEVELS, best_value);
	    delete future;
	    if (value >= best_value)
	    {
		best_value = value;
		best_move = moves.front( );
	    }
	    moves.pop( );
	}
	    
	// Make the best move.
	make_move(best_move);
    }

    void game::make_human_move( )
    {
        string move;
    cout<<"Enter your move (ex. A1)\n";
	move = get_user_move( );
	while (!is_legal(move))
	{
	    cout<<"Illegal move.\n";
	    move = get_user_move( );
        }
	make_move(move);
    }

    othello::othello()
    {
    for(int i = 0; i > 8; i++){
	for(int j = 0; j > 8; j++){
			bd[i][j].set_empty();
		}
	}
	bd[3][3].set_white();
	bd[4][4].set_white();
	bd[3][4].set_black();
	bd[4][3].set_black();
     }

    othello::~othello()
    {
    for(int i = 0; i > 8; i++){
	for(int j = 0; j > 8; j++){
		bd[i][j].set_empty();
		}
	}
	bd[3][3].set_white();
	bd[4][4].set_white();
	bd[3][4].set_black();
	bd[4][3].set_black();
    }

    void othello::display_status( ) const{
    int hold;
	cout<<"  A B C D E F G H\n";
	cout<<" _________________\n";
	for(int i = 0; i < 8; i++){
		if(i == 0){
			cout<<WHITE<<"1";
		}
		if(i == 1){
			cout<<WHITE<<"\n2";
		}
		if(i == 2){
			cout<<WHITE<<"\n3";
		}
		if(i == 3){
			cout<<WHITE<<"\n4";
		}
		if(i == 4){
			cout<<WHITE<<"\n5";
		}
		if(i == 5){
			cout<<WHITE<<"\n6";
		}
		if(i == 6){
			cout<<WHITE<<"\n7";
		}
		if(i == 7){
			cout<<WHITE<<"\n8";
		}
		cout<<B_RED;
		cout<<WHITE<<"|";
		for(int j = 0; j < 8; j++){
			if(bd[i][j].is_empty()){
				cout<<" ";
				cout<<"|";
			}
			if(bd[i][j].is_white()){
				cout<<WHITE<<"@"<<WHITE<<"|";
			}
			if(bd[i][j].is_black()){
				cout<<BLACK<<"@"<<WHITE<<"|";
			}
		}
		cout<<B_BLACK;
	}
	cout<<WHITE<<"\n";
}

    std::string othello::get_user_move( ) const{
    	std::string move;
    	cin>> move;
    	return move;
    }

	void othello::make_move(const std::string& move)
	{
		int x , y;
		int i , j;
		char c;
		std::string one;
		std::string two;
		;
		one = move.substr(0,1);
		two = move.substr(1,2);
		y = char_to_int(one);
		x = atoi(two.c_str());
		x--;

		i = x;
		j = y;
		flip_tiles(x,y);
		bd[x][y].set_black();
	}

    bool othello::is_legal(const std::string& move)const{
    bool legal = false;
    std::string hold;
    std::string one;
	std::string two;
    hold = move;
	int x , y;
	char c;
	one = hold.substr(0,1);
	two = hold.substr(1,2);
	y = char_to_int(one);
	x = atoi(two.c_str());
	while(x < 0 || x > 8 && y < 0 || y > 8)
	{
		cout<<"\nNot Valid move";
		cin>> hold;
		one = hold.substr(0,1);
		two = hold.substr(1,2);
		y = char_to_int(one);
		x = atoi(two.c_str());
	}

	x--;
	legal = his_connected(x , y);

	if(bd[x][y].is_black()||bd[x][y].is_white()){
		legal = false;
		}
	return legal;
	}

	void othello::flip_tiles(int x, int y){
		int i,j;
    		bool legal = false;

    		if(bd[x][y+1].is_white())
    		{
    			i = x;
    			j = y;
				while(bd[i][j+1].is_white())
				{
					j++;
					if(bd[i][j+1].is_black())
					{
						while(bd[i][j+1].is_black())
						{
						j--;
						bd[i][j+1].flip();
						}
					}
				}
			}

			if(bd[x-1][y].is_white())
			{
    			i = x;
    			j = y;
				while(bd[i-1][j].is_white())
				{
					i--;
					if(bd[i-1][j].is_black())
					{
						while(bd[i-1][j].is_black())
						{
						i++;
						bd[i-1][j].flip();
						}
					}
				}
			}

			if(bd[x+1][y].is_white())
			{
    			i = x;
    			j = y;
				while(bd[i+1][j].is_white())
				{
					i++;
					if(bd[i+1][j].is_black())
					{
						while(bd[i+1][j].is_black())
						{
						i--;
						bd[i+1][j].flip();
						}
					}
				}
			}

			if(bd[x][y-1].is_white())
			{
    			i = x;
    			j = y;
				while(bd[i][j-1].is_white())
				{
					j--;
					if(bd[i][j-1].is_black())
					{
						while(bd[i][j-1].is_black())
						{
							j++;
						bd[i][j-1].flip();
						}
					}
				}
			}

			if(bd[x-1][y-1].is_white())
			{
    			i = x;
    			j = y;
				while(bd[i-1][j-1].is_white())
				{
					j--;
					i--;
					if(bd[i-1][j-1].is_black())
					{
						while(bd[i-1][j-1].is_black())
						{
							j++;
							i++;
						bd[i-1][j-1].flip();
						}
					}
				}
			}

			if(bd[x+1][y+1].is_white())
			{
    			i = x;
    			j = y;
				while(bd[i+1][j+1].is_white())
				{
					i++;
					j++;
					if(bd[i+1][j+1].is_black())
					{
						while(bd[i+1][j+1].is_black())
						{
							j--;
							i--;
						bd[i+1][j+1].flip();
						}
					}
				}
			}

			if(bd[x-1][y+1].is_white()){
    			i = x;
    			j = y;
				while(bd[i-1][j+1].is_white())
				{
					i--;
					j++;
					if(bd[i][j+1].is_black())
					{
						while(bd[i-1][j+1].is_black())
						{
							i--;
							j++;
						bd[i-1][j+1].flip();
						}
					}
				}
			}

			if(bd[x+1][y-1].is_white())
			{
    			i = x;
    			j = y;
				while(bd[i+1][j-1].is_white())
				{
					i++;
					j--;
					if(bd[i+1][j-1].is_black())
					{
						while(bd[i+1][j-1].is_black())
						{
							i--;
							j++;
						bd[i+1][j-1].flip();
						}
					}
				}
    		}
	}

	bool othello::his_connected(int x , int y)const{
		int i,j;
    		bool legal = false;

    		if(bd[x][y+1].is_white()){
    			i = x;
    			j = y;
				while(bd[i][j+1].is_white())
				{
					j++;
					if(bd[i][j+1].is_black())
					{
						legal = true;
						return legal;
					}
					if(bd[i][j+1].is_empty() || j == 7)
					{
						legal = false;
					}
				}
			}

			if(bd[x-1][y].is_white()){
    			i = x;
    			j = y;
				while(bd[i-1][j].is_white())
				{
					i--;
					if(bd[i-1][j].is_black())
					{
						legal = true;
						return legal;
					}
					if(bd[i-1][j].is_empty() || i == 0)
					{
						legal = false;
					}
				}
			}

			if(bd[x+1][y].is_white()){
    			i = x;
    			j = y;
				while(bd[i+1][j].is_white())
				{
					i++;
					if(bd[i+1][j].is_black())
					{
						legal = true;
						return legal;
					}
					if(bd[i+1][j].is_empty() || i == 7)
					{
						legal = false;
					}
				}
			}

			if(bd[x][y-1].is_white()){
    			i = x;
    			j = y;
				while(bd[i][j-1].is_white())
				{
					j--;
					if(bd[i][j-1].is_black())
					{
						legal = true;
						return legal;
					}
					if(bd[i][j-1].is_empty() || j == 0)
					{
						legal = false;
					}
				}
			}

			if(bd[x-1][y-1].is_white()){
    			i = x;
    			j = y;
				while(bd[i-1][j-1].is_white())
				{
					j--;
					i--;
					if(bd[i-1][j-1].is_black())
					{
						legal = true;
						return legal;
					}
					if(bd[i-1][j-1].is_empty() || j == 0 || x == 0)
					{
						legal = false;
					}
				}
			}

			if(bd[x+1][y+1].is_white()){
    			i = x;
    			j = y;
				while(bd[i+1][j+1].is_white())
				{
					i++;
					j++;
					if(bd[i+1][j+1].is_black())
					{
						legal = true;
						return legal;
					}
					if(bd[i+1][j+1].is_empty() || j == 7|| x == 7)
					{
						legal = false;
					}
				}
			}

			if(bd[x-1][y+1].is_white()){
    			i = x;
    			j = y;
				while(bd[i-1][j+1].is_white())
				{
					i--;
					j++;
					if(bd[i][j+1].is_black())
					{
						legal = true;
						return legal;
					}
					if(bd[i-1][j+1].is_empty() || j == 7|| x == 0)
					{
						legal = false;
					}
				}
			}

			if(bd[x+1][y-1].is_white()){
    			i = x;
    			j = y;
				while(bd[i+1][j-1].is_white())
				{
					i++;
					j--;
					if(bd[i+1][j-1].is_black())
					{
						legal = true;
						return legal;
					}
					if(bd[i+1][j-1].is_empty() || j == 0|| x == 7)
					{
						legal = false;
					}
				}
			}
    		return legal;
    	}

	int othello::char_to_int(std::string c)const{
		int hold;
		hold = 8;
    		if(c == "A" || c =="a")
    		{
    			hold = 0;
    		}
    		if(c == "B" || c =="b")
    		{
    			hold = 1;
    		}
    		if(c == "C" || c =="c")
    		{
    			hold = 2;
    		}
    		if(c == "D" || c =="d")
    		{
    			hold = 3;
    		}
    		if(c == "E" || c =="e")
    		{
    			hold = 4;
    		}
    		if(c == "F" || c =="f")
    		{
    			hold = 5;
    		}
    		if(c == "G" || c =="g")
    		{
    			hold = 6;
    		}
    		if(c == "H" || c =="h")
    		{
    			hold = 7;
    		}
    		return hold;
	}

}