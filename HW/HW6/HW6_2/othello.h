// File: game.h (part of the namespace main_savitch_14)


#ifndef MAIN_OTHELLO_GAME
#define MAIN_OTHELLO_GAME
#include <queue>   // Provides queue<string>
#include <string>  // Provides string
#include "space.h"
namespace main_savitch_14
{	class game;
    class othello: public game{
    public:
    othello();
    ~othello();
    void display_message(const std::string& message) const{;}
    std::string get_user_move( ) const;
    bool bis_connected(int x , int y)const;
    bool wis_connected(int x , int y)const;
    void bflip_tiles(int x, int y);
    void wflip_tiles(int x, int y);
    int char_to_int(std::string x)const;
    void make_move(const std::string& move);
    void check_score();

	//int moves_completed( ) const { return move_number; }
    //void restart( );

    game* clone() const;
    void compute_moves(std::queue<std::string>& moves) const;
    void display_status() const;
    int evaluate() const{;}
    bool is_game_over() const;
    bool is_legal(const std::string& move) const;
    void no_move_made_up(){no_move_made++;}

    //who next_mover( ) const{ return (move_number % 2 == 0 ? HUMAN : COMPUTER); }
	who opposite(who player) const { return (player == HUMAN) ? COMPUTER : HUMAN; }
    who winning( ) const{;}
   // who last_mover( ) const { return (move_number % 2 == 1 ? HUMAN : COMPUTER); }
    private:
    space bd[8][8];
    int amount_black;
    int amount_white;
    };
}

#endif
