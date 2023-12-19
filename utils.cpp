#include "utils.h"
#include <iomanip>

using namespace std;

int dayNumber(int day, int month, int year)
{
 
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1,
                       4, 6, 2, 4 };
    year -= month < 3;
    return ( year + year/4 - year/100 +
             year/400 + t[month-1] + day) % 7;
}

// to get the month by it's index;
string getMonthName(int monthNumber)
{
    string months[] = {"January", "February", "March",
                       "April", "May", "June",
                       "July", "August", "September",
                       "October", "November", "December"
                      };
 
    return (months[monthNumber]);
}


int numberOfDays(int monthNumber, int year) {
    switch (monthNumber) {
        // January
        case 0:
            return 31;

        // February
        case 1:
            // If the year is leap then February has 29 days
            if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
                return 29;
            else
                return 28;

        // March
        case 2:
            return 31;

        // April
        case 3:
            return 30;

        // May
        case 4:
            return 31;

        // June
        case 5:
            return 30;

        // July
        case 6:
            return 31;

        // August
        case 7:
            return 31;

        // September
        case 8:
            return 30;

        // October
        case 9:
            return 31;

        // November
        case 10:
            return 30;

        // December
        case 11:
            return 31;

        default:
            return 0;
    }
}


void print_calendar(int& year){

  cout << endl;

  cout << "Calendar for " << year << endl;

  int days;
  
  int current = dayNumber(1,1,year)-1;

  for(int i = 0; i < 12; ++i){
    
    days = numberOfDays(i,year);
    cout << "--" + getMonthName(i) + "--" << endl;

    cout << "  Mon  Tue  Wed  Thu  Fri  Sat  Sun" << endl;

    int k;
    for(k = 0; k < current; ++k){
          cout << "     ";
    }
    for(int j = 1; j <= days; ++j){

      cout << setw(5) << j;
      if( ++k > 6){
        k = 0;
        cout << endl;
      }
    }
    if(k)
    cout << endl;

    current = k;
    cout << endl;
  }

  
}