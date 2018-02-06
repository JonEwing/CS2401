/*************************************************************
    HW5        CS2401      Spring 2017
    Jonathan Feige
    This is the header file for the animal class
    and all of its child classes
**************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <list>
#ifndef ANIMAL_A
#define ANIMAL_A

class animal{
    public:
    void virtual output(std::ostream& outs)=0;
    void virtual input(std::istream& ins)=0;
    void virtual foutput(std::ostream& outs)=0;
    void virtual finput(std::istream& ins)=0;
	protected:
        std::string name;
        double height;
        double width;
	};

class dog:public animal{
    public:
        dog();
    void output(std::ostream& outs);
    void input(std::istream& ins);
    void finput(std::istream& ins);
    void foutput(std::ostream& outs);
    private:
        std::string wood_type;
    };

    class cat:public animal{
    public:
        cat();
    void output(std::ostream& outs);
    void input(std::istream& ins);
    void finput(std::istream& ins);
    void foutput(std::ostream& outs);
    private:
        int levels;
        int campartments;
    };

     class shark:public animal{
    public:
        shark();
    void output(std::ostream& outs);
    void input(std::istream& ins);
    void finput(std::istream& ins);
    void foutput(std::ostream& outs);
    private:
        std::string glass_color;
        int rocks;
      };

    class honey_badger:public animal{
    public:
        honey_badger();
    void output(std::ostream& outs);
    void input(std::istream& ins);
    void finput(std::istream& ins);
    void foutput(std::ostream& outs);
    private:
        double depth;
        std::string leaf_type;
    };


    class goat:public animal{
     public:
        goat();
    void output(std::ostream& outs);
    void input(std::istream& ins);
    void finput(std::istream& ins);
    void foutput(std::ostream& outs);
    private:
        double straw;
        bool bed;
        std::string bed_color;
      };

    std::istream& operator >>(std::istream& ins, animal& a);
    std::ostream& operator <<(std::ostream& outs, animal& a);
    #endif