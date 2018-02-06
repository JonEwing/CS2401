// File: game.h (part of the namespace main_savitch_14)


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

