/* This program takes in user input on weather or not they tested positive for covid,
   Takes in date information to determine how long they need to stay in isolation.
   Taylor Boyles
   CPSC 1020
   Asignment 01
*/

#include <iostream>
#include <iomanip>
#include "Date.h"
#include "calcDays.h"

using namespace std;

int main(){

  // variable declarations
  string result, date, pos, vax;
  int month, day, year, month2, day2, year2;

  // Takes in user input on weather or not they tested positive
  cout << "Did you test positive or negative? ";
  cin >> result;

  // if user tested positive
  if(result == "positive" || result == "Positive"){

    cout << "What day did you test positive?" << endl;
    // Takes in input on the date they teted positive
    cout << "Month: ";
    cin >> month;
    cout << "Day: ";
    cin >> day;
    cout << "Year: ";
    cin >> year;
    cout << "\n\n";

    // creates an instance of Date class and passes user inputed date to it
    Date datePositive(day, month, year);

    // prints result
    cout << "Test result: positive" << endl;
    cout << "Date tested positive: " << datePositive.showDate() << endl;
    cout << "Length of isolation: 5 days" << endl;
  }
  // if user tested negative
  else if(result == "negative" || result == "Negative"){
    // checks if user was exposed to a positive case
    cout << "Were you exposed to a posative case? ";
    cin >> pos;

    if(pos == "No" || pos == "no"){

      cout << "\n";
      // if user was not exposed to a positive case, prints result
      cout << "Test result: negative" << endl;
      cout << "Exposed to positive case: No" << endl;
      cout << "Length of isolation: 0 days" << endl;
    }
    // if user was exposed to a positive case
    else if(pos == "Yes" || pos == "yes"){
      cout << "when were you exposed to the posative case? " << endl;

      // takes in user input for date expsoed to positive case
      cout << "Month: ";
      cin >> month;
      cout << "Day: ";
      cin >> day;
      cout << "Year: ";
      cin >> year;

      // makes instance of date class and passes date user was exposed to positive case to it
      Date dateExposed(day, month, year);

      // takes in user input on weather or not they recrived a second vaxination dose
      cout << "Did you recieve a second vactionation dose? ";
      cin >> vax;

      // if user has recrived their second vaxination dose
      if(vax == "Yes" || vax == "yes"){
        cout << "What date did you recieve your second dose? " << endl;

        // takes in input on what date they recrived their second vacination dose
        cout << "Month: ";
        cin >> month2;
        cout << "Day: ";
        cin >> day2;
        cout << "Year: ";
        cin >> year2;

        // creates an instance of Date class and passes the date the user recrived their secdon vax dose to it
        Date dateSecondDose(day2, month2, year2);

        // creates two strings of dates expsoed to positive case and date of second dose
        int Exposed[3] = {dateExposed.getMonth(), dateExposed.getDay(), dateExposed.getYear()};
        int secondDose[3] = {dateSecondDose.getMonth(), dateSecondDose.getDay(), dateSecondDose.getYear()};

        // passes both strings to calcDays function
        if(calcDays(Exposed, secondDose) < 14){
          // if calcDays is less than 14, user is not fully vaxinated and prints results
          cout << "\nTest result: negative" << endl;
          cout << "Exposed to positive case: Yes" << endl;
          cout << "Date exposed to positive case: " << dateExposed.showDate() << endl;
          cout << "Second vaccination does received: Yes" << endl;
          cout << "Date second vaccination soes received: " << dateSecondDose.showDate() << endl;
          cout << "Vaccination status at time of exposure: not fully vaccinated" << endl;
          cout << "Length of isolation: 10 days" << endl;
        }
        else{
          // if calcDays is greater than 14, user is fully vaxinated and prints results
          cout << "\nTest result: negative" << endl;
          cout << "Exposed to positive case: Yes" << endl;
          cout << "Date exposed to positive case: " << dateExposed.showDate() << endl;
          cout << "Second vaccination does received: Yes" << endl;
          cout << "Date second vaccination does received: " << dateSecondDose.showDate() << endl;
          cout << "Vaccination status at time of exposure: fully vaccinated" << endl;
          cout << "Length of isolation: 5 days" << endl;
        }
      }
      // if user has not received their second vaxination dose
      else if(vax == "No" || vax == "no"){
        // prints results
        cout << "\nTest result: negative" << endl;
        cout << "Exposed to positive case: Yes" << endl;
        cout << "Date exposed to positive case: " << dateExposed.showDate() << endl;
        cout << "Second vaccination does recived: No" << endl;
        cout << "vaccination status at time of exposure: not fully vaccinated" << endl;
        cout << "Length of isolation: 10 days" << endl;
      }
    }
  }

  return 0;
}
