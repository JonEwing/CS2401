/*************************************************************
    HW6        CS2401      Spring 2017
    Jonathan Feige
    This is the header file for the game class
    and all of its child classes
**************************************************************/

#ifndef MAIN_SAVITCH_GAME
#define MAIN_SAVITCH_GAME
#include <queue>   // Provides queue<string>
#include <string>  // Provides string
#include "space.h"
namespace main_savitch_14
{
    class game
    {
    public:
    	// ENUM TYPE
	enum who { HUMAN, NEUTRAL, COMPUTER }; // Possible game outcomes
	
	// CONSTRUCTOR and DESTRUCTOR
	game( ) { move_number = 0; }
	virtual ~game( ) { }
	
	// PUBLIC MEMBER FUNCTIONS
	// The play function should not be overridden. It plays one game,
	// with the human player moving first and the computer second.
	// The computer uses an alpha-beta look ahead algorithm to select its
	// moves. The return value is the winner of the game (or NEUTRAL for
	// a tie).
	who play( );

    protected:
	// *******************************************************************
	// OPTIONAL VIRTUAL FUNCTIONS (overriding these is optional)
	// *******************************************************************
	virtual void display_message(const std::string& message) const;
    	virtual std::string get_user_move( ) const;
	virtual who last_mover( ) const 
	    { return (move_number % 2 == 1 ? HUMAN : COMPUTER); }
	virtual int moves_completed( ) const { return move_number; }
	virtual who next_mover( ) const
	    { return (move_number % 2 == 0 ? HUMAN : COMPUTER); }
	virtual who opposite(who player) const
	    { return (player == HUMAN) ? COMPUTER : HUMAN; }
    	virtual who winning( ) const;

	// *******************************************************************
	// VIRTUAL FUNCTIONS THAT MUST BE OVERRIDDEND:
	// The overriding function should call the original when it finishes.
	// *******************************************************************
	// Have the next player make a specified move:
    	virtual void make_move(const std::string& move) { ++move_number; }
        // Restart the game from the beginning:
    	virtual void restart( ) { move_number = 0; }

	// *******************************************************************
        // PURE VIRTUAL FUNCTIONS
	// *******************************************************************
	// (these must be provided for each derived class)
        // Return a pointer to a copy of myself:
    	virtual game* clone( ) const = 0;
        // Compute all the moves that the next player can make:
    	virtual void compute_moves(std::queue<std::string>& moves) const = 0;
    	// Display the status of the current game:
    	virtual void display_status( ) const = 0;
    	// Evaluate a board position:
	// NOTE: positive values are good for the computer.
    	virtual int evaluate( ) const = 0;
    	// Return true if the current game is finished:
    	virtual bool is_game_over( ) const = 0;
    	// Return true if the given move is legal for the next player:
    	virtual bool is_legal(const std::string& move) const = 0;

    private:
        // MEMBER VARIABLES
	int move_number;                     // Number of moves made so far

	// STATIC MEMBER CONSTANT
	static const int SEARCH_LEVELS = 4;  // Levels for look-ahead evaluation
	
        // PRIVATE FUNCTIONS (these are the same for every game)
	int eval_with_lookahead(int look_ahead, int beat_this);
	void make_computer_move( );
	void make_human_move( );
    };


    class othello: public game{
    public:
    othello();
    ~othello();
    void display_message(const std::string& message) const{;}
    std::string get_user_move( ) const;
    bool his_connected(int x , int y)const;
    void flip_tiles(int x, int y);
    int char_to_int(std::string x)const;
    void make_move(const std::string& move);

	//int moves_completed( ) const { return move_number; }
    //void restart( );

    game* clone( ) const{;}
    void compute_moves(std::queue<std::string>& moves) const{;}
    void display_status( ) const;
    int evaluate( ) const{;}
    bool is_game_over( ) const{;}
    bool is_legal(const std::string& move) const;

    //who next_mover( ) const{ return (move_number % 2 == 0 ? HUMAN : COMPUTER); }
	who opposite(who player) const { return (player == HUMAN) ? COMPUTER : HUMAN; }
    who winning( ) const{;}
   // who last_mover( ) const { return (move_number % 2 == 1 ? HUMAN : COMPUTER); }
    private:
    space bd[8][8];
    };
}

#endif
