// Fig. 9.15: Date.cpp
// Date class member-function definitions.
#include <sstream>
#include <string>
#include "Enhanced Date.h" // include definition of class Date from Date.h
using namespace std;

// Date constructor (should do range checking)
Date::Date(unsigned int m, unsigned int d, unsigned int y) {
    setDate(m,d,y);
} 

void Date::setDate(unsigned int m, unsigned int d, unsigned int y){
    setMonth(m);
    setDay(d);
    setYear(y);
}

//Set the 'Month' field of a 'Date' object
//Must be between 1-12
void Date::setMonth(int m){
    if(m >= 1 && m <= 12){
        month = m;
    }else{
        throw invalid_argument("Month Must be Between 1-12");
    }
}

//Set the 'Day' field of a 'Date' object
//Must be between 1-31
void Date::setDay(int d){
    if(month == 2){
        if(d >= 1 && d <= 28){
            day = d;
        }else{
            throw invalid_argument("Must be Between 1-28");
        }
    }else{
        if(d >= 1 && d <= 31){
            day = d;
        }else{
            throw invalid_argument("Must be Between 1-31");
        }
    }
}

//Set the 'Year' field of a 'Date' object
void Date::setYear(int y){
    year = y;
}

// print Date in the format mm/dd/yyyy
string Date::toString() const {
   ostringstream output;
   output << month << '/' << day << '/' << year;
   return output.str();
}

void Date::nextDay() {

}



/**************************************************************************
 * (C) Copyright 1992-2017 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/
