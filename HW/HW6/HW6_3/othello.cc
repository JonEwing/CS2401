// File: game.cxx

#include <cassert>    // Provides assert
#include <climits>    // Provides INT_MAX and INT_MIN
#include <iostream>   // Provides cin, cout
#include <queue>      // Provides queue<string>
#include <string>     // Provides string
#include <cstring>
#include <cstdlib>
#include <queue>
#include "game.h"     // Provides definition of game class
#include "space.h"
#include "colors.h"
#include "othello.h"

using namespace std;

namespace main_savitch_14
{
    othello::othello(){
    for(int i = 0; i > 8; i++){
	for(int j = 0; j > 8; j++){
			bd[i][j].set_empty();
		}
	}
	bd[3][3].set_white();
	bd[4][4].set_white();
	bd[3][4].set_black();
	bd[4][3].set_black();
	no_move_made = 0;
	amount_black = 2;
	amount_white = 2;
     }

    void othello::display_status( ) const{
    int hold;
    std::queue<std::string> moves;
    compute_moves(moves);
    cout<<"Legal moves:";
    while(!moves.empty())
    {
    	cout<<moves.front();
    	moves.pop();
    	cout<<" ";
    }
    cout<<"\n";
	cout<<"   A    B    C    D    E    F    G    H\n";
	cout<<" "<<B_RED<<"+---------------------------------------+"<<B_BLACK<<" \n";
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
				cout<<"    ";
				cout<<"|";
			}
			if(bd[i][j].is_white()){
				cout<<" "<<B_WHITE<<"  "<<WHITE<<B_RED<<" |";
			}
			if(bd[i][j].is_black()){
				cout<<" "<<B_BLACK<<"  "<<WHITE<<B_RED<<" |";
			}
		}
		cout<<B_BLACK;
		cout<<"\n "<<B_RED<<"+---------------------------------------+";
		cout<<B_BLACK<<" ";
	}
	cout<<"\n BLACK "<<amount_black<<"   WHITE "<<amount_white<<"\n";
	cout<<WHITE<<"\n";
}

    std::string othello::get_user_move( ) const{
    	std::string move;
    	cin>> move;
    	return move;
    }

	void othello::make_move(const std::string& move){
		int x , y;
		int i , j, hold;
		char c;
		std::string one;
		std::string two;
		;
		one = move.substr(0,1);
		two = move.substr(1,2);
		y = char_to_int(one);
		x = atoi(two.c_str());
		x--;

		hold = game::moves_completed();

		if(hold %2 == 0){
		bflip_tiles(x,y);
		bd[x][y].set_black();
		amount_black++;
		no_move_made = 0;
		}
		if(hold %2 == 1){
		wflip_tiles(x,y);
		bd[x][y].set_white();
		amount_white++;
		no_move_made = 0;
		}
		check_score();
	}

	void othello::compute_moves(std::queue<std::string>& moves) const{
		std::string str1, str2;
		while(!moves.empty())
		{
			moves.pop();
		}
		for (char i = 'A'; i <= 'H'; i++)
       		{
        	for (char j = '1'; j <= '8'; j++)
                {
                str1 = i;
                str2 = j;
                str1 += str2;
                if (is_legal(str1))
                        moves.push(str1);
                }
        }
	}

    bool othello::is_legal(const std::string& move)const{
    	bool legal = false;
    	std::string one;
		std::string two;
		int x , y, h;
		char c;
		one = move.substr(0,1);
		two = move.substr(1,2);
		y = char_to_int(one);
		x = atoi(two.c_str());
		x--;

		while(x < 0 || x > 7 || y < 0 || y > 7)
		{
			legal = false;
			return legal;
		}
		
		if(bd[x][y].is_black()||bd[x][y].is_white()){
			legal = false;
			return legal;
			}

		h = game::moves_completed();

			if(h %2 == 0){
			legal = bis_connected(x , y);
			}
			if(h %2 == 1){
			legal = wis_connected(x , y);
			}
	return legal;
	}

	bool othello::is_game_over( ) const{
		int hold;
		bool game_end;
		hold = amount_black + amount_white;
		if(hold>=64){
			game_end = true;
		}
		else{
			game_end = false;
		}

		if(amount_black == 0 || amount_white == 0)
		{
			game_end = true;
		}

		return game_end;
	}

	void othello::check_score(){
		amount_white = 0;
		amount_black = 0;
		for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			if(bd[i][j].is_white()){
				amount_white++;
			}
			if(bd[i][j].is_black()){
				amount_black++;
				}
			}
		}
	}

	int othello::evaluate() const{ 	
		int count = 0, x, y;
		std::string move, tmp;
		for (char i = 'A'; i <= 'H'; i++)
        	{
       		for (char j = '1'; j <= '8'; j++)
                {
                move = i;
                tmp = j;
                move += tmp;
                x = int(toupper(i)-'A');
                y = int(j-'1');
                
                if (move == "A1" || move == "H1" || move == "A8" || move == "H8$")
                        {
                        if (bd[x][y].is_white())
                                count += 2;
                        else
                                count -= 2;
                        }
                else
                        {
                        if (bd[x][y].is_white())
                                count += 1;
                        else
                                count -= 1;
                        }
                }
        }
	return count;
	}

	void othello::bflip_tiles(int x, int y){
		int i, j , m, n;

    		if(bd[x][y+1].is_white() && y!=7)
    		{
    			i = x;
    			j = y;
				while(bd[i][j+1].is_white() && y<7)
				{
					j++;
				}
				if(bd[i][j+1].is_black())
					{
						while(j>y)
						{
						bd[i][j].set_black();
   						j--;
						}
					}
			}

			if(bd[x-1][y].is_white() && x!=0)
			{
    			i = x;
    			j = y;
				while(bd[i-1][j].is_white()  && x>0)
				{
					i--;
				}
				if(bd[i-1][j].is_black())
					{
						while(i<x)
						{
						bd[i][j].set_black();
   						i++;
						}
					}
			}

			if(bd[x+1][y].is_white() && x!=7)
			{
    			i = x;
    			j = y;
				while(bd[i+1][j].is_white()  && x<7)
				{
					i++;
				}
				if(bd[i+1][j].is_black())
					{
						while(i>x)
						{
						bd[i][j].set_black();
   						i--;
						}
					}
			}

			if(bd[x][y-1].is_white() && y!=0)
			{
    			i = x;
    			j = y;
				while(bd[i][j-1].is_white()  && y>0)
				{
					j--;
				}
				if(bd[i][j-1].is_black())
					{
						while(j<y)
						{
						bd[i][j].set_black();
   						j++;
						}
					}
			}

			if(bd[x-1][y-1].is_white() && y!=0 && x!=0)
			{
    			i = x;
    			j = y;
				while(bd[i-1][j-1].is_white() && y>0 && x>0)
				{
					j--;
					i--;
				}
				if(bd[i-1][j-1].is_black())
					{
						while(j<y)
						{
						bd[i][j].set_black();
   						i++;
   						j++;
						}
					}
			}

			if(bd[x+1][y+1].is_white() && y!=7 && x!=7)
			{
    			i = x;
    			j = y;
				while(bd[i+1][j+1].is_white() && y<7 && x<7)
				{
					i++;
					j++;
				}
				if(bd[i+1][j+1].is_black())
					{
						while(j>y)
						{
						bd[i][j].set_black();
   						i--;
   						j--;
						}
					}
			}

			if(bd[x-1][y+1].is_white() && y!=7 && x!=0){
    			i = x;
    			j = y;
				while(bd[i-1][j+1].is_white() && y<7 && x>0)
				{
					i--;
					j++;
				}
				if(bd[i-1][j+1].is_black())
					{
						while(j>y)
						{
						bd[i][j].set_black();
   						i++;
   						j--;
						}
					}
			}

			if(bd[x+1][y-1].is_white() && y!=0 && x!=7)
			{
    			i = x;
    			j = y;
				while(bd[i+1][j-1].is_white() && y>0 && x<7)
				{
					i++;
					j--;
				}
				if(bd[i+1][j-1].is_black())
					{
						while(j< y)
						{
						bd[i][j].set_black();
   						i--;
   						j++;
						}
					}
    		}
	}

	void othello::wflip_tiles(int x, int y){
		int i,j;

    		if(bd[x][y+1].is_black() && y!=7)
    		{
    			i = x;
    			j = y;
				while(bd[i][j+1].is_black() && y<7)
				{
					j++;
				}
				if(bd[i][j+1].is_white())
					{
						while(j>y)
						{
						bd[i][j].set_white();
   						j--;
						}
					}
			}

			if(bd[x-1][y].is_black() && x!=0)
			{
    			i = x;
    			j = y;
				while(bd[i-1][j].is_black()  && x>0)
				{
					i--;
				}
				if(bd[i-1][j].is_white())
					{
						while(i<x)
						{
						bd[i][j].set_white();
   						i++;
						}
					}
			}

			if(bd[x+1][y].is_black() && x!=7)
			{
    			i = x;
    			j = y;
				while(bd[i+1][j].is_black()  && x<7)
				{
					i++;
				}
				if(bd[i+1][j].is_white())
					{
						while(i>x)
						{
						bd[i][j].set_white();
   						i--;
						}
					}
			}

			if(bd[x][y-1].is_black() && y!=0)
			{
    			i = x;
    			j = y;
				while(bd[i][j-1].is_black()  && y>0)
				{
					j--;
				}
				if(bd[i][j-1].is_white())
					{
						while(j<y)
						{
						bd[i][j].set_white();
   						j++;
						}
					}
			}

			if(bd[x-1][y-1].is_black() && x!=0 && y!=0)
			{
    			i = x;
    			j = y;
				while(bd[i-1][j-1].is_black()  && x>0 && y>0)
				{
					j--;
					i--;
				}
				if(bd[i-1][j-1].is_white())
					{
						while(j<y)
						{
						bd[i][j].set_white();
   						i++;
   						j++;
						}
					}
			}

			if(bd[x+1][y+1].is_black() && x!=7 && y!=7)
			{
    			i = x;
    			j = y;
				while(bd[i+1][j+1].is_black()  && x<7 && y<7)
				{
					i++;
					j++;
				}
				if(bd[i+1][j+1].is_white())
					{
						while(j>y)
						{
						bd[i][j].set_white();
   						i--;
   						j--;
						}
					}
			}

			if(bd[x-1][y+1].is_black() && x!=0 && y!=7){
    			i = x;
    			j = y;
				while(bd[i-1][j+1].is_black()  && x>0 && y<7)
				{
					i--;
					j++;
				}
				if(bd[i-1][j+1].is_white())
					{
						while(j>y)
						{
						bd[i][j].set_white();
   						i++;
   						j--;
						}
					}
			}

			if(bd[x+1][y-1].is_black() && x!=7 && y!=0)
			{
    			i = x;
    			j = y;
				while(bd[i+1][j-1].is_black()  && x<7 && y>0)
				{
					i++;
					j--;
				}
				if(bd[i+1][j-1].is_white())
					{
						while(j< y)
						{
						bd[i][j].set_white();
   						i--;
   						j++;
						}
					}
    		}
	}

	bool othello::bis_connected(int x , int y)const{
		int i,j;
    		bool legal = false;

    		if(bd[x][y+1].is_white() && y != 7){
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

			if(bd[x-1][y].is_white() && x != 0){
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

			if(bd[x+1][y].is_white()&& x != 7){
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

			if(bd[x][y-1].is_white()&& y != 0){
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

			if(bd[x-1][y-1].is_white()&& x != 0 && y != 0){
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

			if(bd[x+1][y+1].is_white()&& x != 7 && y != 7){
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

			if(bd[x-1][y+1].is_white()&& x != 0 && y != 7){
    			i = x;
    			j = y;
				while(bd[i-1][j+1].is_white())
				{
					i--;
					j++;
					if(bd[i-1][j+1].is_black())
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

			if(bd[x+1][y-1].is_white()&& x != 7 && y != 0){
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

    bool othello::wis_connected(int x , int y)const{
		int i,j;
    		bool legal = false;

    		if(bd[x][y+1].is_black()&& y != 7){
    			i = x;
    			j = y;
				while(bd[i][j+1].is_black())
				{
					j++;
					if(bd[i][j+1].is_white())
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

			if(bd[x-1][y].is_black()&& x != 0){
    			i = x;
    			j = y;
				while(bd[i-1][j].is_black())
				{
					i--;
					if(bd[i-1][j].is_white())
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

			if(bd[x+1][y].is_black()&& x != 7){
    			i = x;
    			j = y;
				while(bd[i+1][j].is_black())
				{
					i++;
					if(bd[i+1][j].is_white())
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

			if(bd[x][y-1].is_black()&& y != 0){
    			i = x;
    			j = y;
				while(bd[i][j-1].is_black())
				{
					j--;
					if(bd[i][j-1].is_white())
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

			if(bd[x-1][y-1].is_black()&& x != 0 && y != 0){
    			i = x;
    			j = y;
				while(bd[i-1][j-1].is_black())
				{
					j--;
					i--;
					if(bd[i-1][j-1].is_white())
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

			if(bd[x+1][y+1].is_black()&& x != 7 && y != 7){
    			i = x;
    			j = y;
				while(bd[i+1][j+1].is_black())
				{
					i++;
					j++;
					if(bd[i+1][j+1].is_white())
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

			if(bd[x-1][y+1].is_black()&& x != 0 && y != 7){
    			i = x;
    			j = y;
				while(bd[i-1][j+1].is_black())
				{
					i--;
					j++;
					if(bd[i-1][j+1].is_white())
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

			if(bd[x+1][y-1].is_black()&& x != 7 && y != 0){
    			i = x;
    			j = y;
				while(bd[i+1][j-1].is_black())
				{
					i++;
					j--;
					if(bd[i+1][j-1].is_white())
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
		hold = 80;
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