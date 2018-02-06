// Jonathan Feige
// CS2401
// Lab 1 header
// 08/31/17

#include <iostream>
    
class MyTime
{   
  public:

    MyTime();
    MyTime(int h, int m);   
   
      
    void Reset(int h, int m);    
   
    MyTime operator + (const MyTime& t2)const;
 
    MyTime operator - (const MyTime& t2)const;
 
    MyTime operator * (int num) const;

    MyTime operator / (int num) const;

    friend std::istream& operator >>(std::istream& fin, MyTime& t);
    
    friend std::ostream& operator <<(std::ostream& fout, const MyTime& t);

    const bool operator == (const MyTime& t2);

    const bool operator < (const MyTime& t2);

    const bool operator <= (const MyTime& t2);

    void input(std::istream& ins);            

    void output(std::ostream& outs);

    int get_hours() const{return hours;}

    int get_minutes() const{return minutes;}
   
  private:
      void simplify();
      int hours;      // hours can be > 24
      int minutes;   // 0 <= minutes <= 59
 };
   
 
