#include "Date.h"
#include <string>
#include <iomanip>
using namespace std;


// date initialized constructor
Date::Date(int d, int m, int y) : day{d}, month{m}, year{y} {
  // calls setter functions to check if date is valid
  setMonth(m);
  setDay(d);
  setYear(y);
  // if one of the dates is not valid then it sets everything to the default
  if(setMonth(m) == false || setDay(d) == false || setYear(y) == false){
    day = 1;
    month = 1;
    year = 2021;
  }
}


bool Date::setDay(int d){
  bool numDays = false;
  // if month is january, march, may, july, august, october, or december
  if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
    if(d <=31 && d > 0){// checks to see if day is between 1 and 31
      numDays = true;
       day = d;
    }
  }
  // if mohth is april, june, september, november
  else if(month == 4 || month == 6 || month == 9 || month == 11){
    if(d <= 30 && d > 0){// checks to see if day is between 1 and 30
      numDays = true;
      day = d;
    }
  }
  else if(month == 2){ // if month is february
    if(d <= 28 && d > 0){// checks if day is between 1 and 28
      numDays = true;
      day = d;
    }
  }
  return numDays;
}
// setter function for month
bool Date::setMonth(int m){
  bool numMonth = false;
  if(m >= 1 && m <= 12){// checks if month is between 1 and 12
    numMonth = true;
    month = m;// sets month to user provided input
  }
  return numMonth;
}

// setter function for year
bool Date::setYear(int y){
  bool numYear = false;
  if(y == 2021 || y == 2022){// checks if year is 2021 or 2022
    numYear = true;
    year = y;// sets year to user provided input
  }
  return numYear;
}

// getter function for day
int Date::getDay(){
  return day;
}
// getter function for month
int Date::getMonth(){
  return month;
}
// getter function for year
int Date::getYear(){
  return year;
}


// function to return date
string Date::showDate(){

  string date;
  // converts int day into a string
  string day0 = to_string(day);
    // checks if day is 1-9 and makes it output a zero in front of it
    if(day0 == "1" || day0 == "2" || day0 == "3" || day0 == "4" || day0 == "5" || day0 == "6" || day0 == "7" || day0 == "8" || day0 == "9"){
      day0 = "0" + day0;
    }
  // converts int month into a string
  string month0 = to_string(month);
    // chicks if month is 1-9 and makes it output a zero in front of it
    if(month0 == "1" || month0 == "2" || month0 == "3" || month0 == "4" || month0 == "5" || month0 == "6" || month0 == "7" || month0 == "8" || month0 == "9"){
      month0 = "0" + month0;
    }
  // convert int year into a string
  string year0 = to_string(year);


  date = month0 + "/" + day0 + "/" + year0;

  return date;
}
