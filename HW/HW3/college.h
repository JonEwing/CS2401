/***********************************************************************8
	This class stores the three essential features of a completed 
	college course: the course number, the grade received, and the 
	credit hours for the course. The get_number_grade will return the 
	numeric equivalent of a letter grade as used in the standard 4 
	point system.
		John Dolan	School of EECS		Summer 2013
************************************************************************/

#include "course.h"
#include<iostream>
#include<string>
#ifndef COLLEGE_A
#define COLLEGE_A

class College{
    public:
        College();
    	College(std::string);
        College(const College &other);
        void operator =( College &other);
        ~College();

    	void load(std::istream& ins);
    	void add(course& c);
    	void display(std::ostream& outs);
    	void remove(std::string a);
    	double hours();
    	double gpa();
    	void save(std::ostream& outs);
	private:
        std::string name;
        node *head;
	};

    std::istream& operator >>(std::istream& ins, College& c);
    std::ostream& operator <<(std::ostream& outs, const College& c);

    #endif