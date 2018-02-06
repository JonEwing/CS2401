/*************************************************************
    HW6        CS2401      Spring 2017
    Jonathan Feige
    This is the header file for the space class
**************************************************************/

#ifndef MAIN_SPACE
#define MAIN_SPACE
#include <queue>   // Provides queue<string>
#include <string>  // Provides string

using namespace std;
    class space
    {
    public:
    	space();
    	bool is_black()const;
    	bool is_white()const;
    	bool is_empty()const;
    	int get_value(){return value;}
    	void set_black();
    	void set_white();
    	void set_empty();
    	void flip();
    
    private:
    	int value;
    
    };

#endif

