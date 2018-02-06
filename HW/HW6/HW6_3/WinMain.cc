#include <cassert>    // Provides assert
#include <climits>    // Provides INT_MAX and INT_MIN
#include <iostream>   // Provides cin, cout
#include <queue>      // Provides queue<string>
#include <string>     // Provides string
#include "game.h"    // Provides definition of game class
#include "space.h"
#include "othello.h"
using namespace main_savitch_14;
    int main(){
    	    othello test;
    	    int players;
    		cout<<"\nHow many players? (1 or 2)\n";
    		cin>> players;

    		if(players == 2){
    			test.hplay();
    		}
    		else{
    			test.set_search();
            	test.play();
            }
        }