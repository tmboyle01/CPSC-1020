#include <iostream>
#include <math.h>
#include "calcDays.h"
using namespace std;

int calcDays(const int (&date1)[3],const int (&date2)[3]){
  // holds the number of days added up in each month
  int monthDays[13] = { 0, 31, 59, 90, 120, 151, 181, 212, 243,
  273, 304, 334, 365 };

  //converts 01/01/2021 to days
  long int setDate = (2021 * 365);
  setDate = setDate + monthDays[1];
  setDate = setDate + 1;

   //converts date exposed into days
   long int firstDate = (date1[2] * 365);
   firstDate = firstDate + monthDays[date1[0]];
   firstDate = firstDate + date1[1];

   // calculates the number of days between 01/01/2021 and date exposed
   long int daysDiff1 = (firstDate - setDate);

   // converts second dose date into days
   long int secondDate = (date2[2] * 365);
   secondDate = secondDate + monthDays[date2[0]];
   secondDate = secondDate + date2[1];

   // calculates the number of days between 01/01/2021 and date of second vactionation date
   long int daysDiff2 = (secondDate - setDate);

   // subtracts the two different days to find the difference between them
   int days = (daysDiff1 - daysDiff2);

   return days;
}
