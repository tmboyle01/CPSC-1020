#ifndef DATE_H_
#define DATE_H_

#include <iostream>
#include <string>
using namespace std;

// Date class
class Date{

// private access specifier
private:
  // private member variables
  int day {01};
  int month {01};
  int year{2021};

// public access specifier
public:
  // public member functions
  Date() = default;// default constructor
  Date(int d, int m, int y); // initialized constructor

  // setter functions
  bool setDay(int d);
  bool setMonth(int m);
  bool setYear(int y);

  // getter functions
  int getDay();
  int getMonth();
  int getYear();

  // show date function
  string showDate();
};

#endif

//-std=c++11
