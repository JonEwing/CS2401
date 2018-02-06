/*************************************************************
    HW6        CS2401      Spring 2017
    Jonathan Feige
    This is the footer file for the space class
**************************************************************/
#include <cassert>    // Provides assert
#include <climits>    // Provides INT_MAX and INT_MIN
#include <iostream>   // Provides cin, cout
#include <queue>      // Provides queue<string>
#include <string>     // Provides string
#include "space.h"
using namespace std;

		space::space()
		{
			value = 0;
		}

  		bool space::is_black()const
  		{
  			if(value == 1){
  				return true;
  			}
  			else{
  				return false;
  			}
  		}

    	bool space::is_white()const
    	{

  			if(value == 2){
  				return true;
  			}
  			else{
  				return false;
  			}
    	}

    	bool space::is_empty()const
    	{

  			if(value == 0){
  				return true;
  			}
  			else{
  				return false;
  			}
    	}

    	void space::set_black()
    	{

  			value = 1;
    	}

    	void space::set_white()
    	{
			value = 2;
    	}

		void space::set_empty()
		{
			value = 0;
		}

    	void space::flip()
    	{
    		if(value == 1){
  				value = 2;
  			}
  			if(value == 2){
  				value = 1;
  			}
    	}