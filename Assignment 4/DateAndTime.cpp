#include <iomanip>
#include <stdexcept>
#include <sstream>
#include <iostream>
#include "DateAndTime.h"

using namespace std;

DateAndTime::DateAndTime(int hr, int min, int sec, unsigned int mth, unsigned int day, unsigned int yr){
    setTime(hr,min,sec);
    setDate(mth,day,yr);
}

void DateAndTime::setDate(unsigned int m, unsigned int d, unsigned int y){
    setMonth(m);
    setDay(d);
    setYear(y);
}

void DateAndTime::setTime(int h, int m, int s) {
    setHour(h); // set private field hour
    setMinute(m); // set private field minute
    setSecond(s); // set private field second
}

// set hour value
void DateAndTime::setHour(int h) {
    if (h >= 0 && h < 24) {
        hour = h;
    }
    else {
        throw invalid_argument("hour must be 0-23");
    }
}

// set minute value
void DateAndTime::setMinute(int m) {
    if (m >= 0 && m < 60) {
        minute = m;
    }
    else {
        throw invalid_argument("minute must be 0-59");
    }
}

// set second value
void DateAndTime::setSecond(int s) {
    if (s >= 0 && s < 60) {
        second = s;
    }
    else {
        throw invalid_argument("second must be 0-59");
    }
}

//Set the month value
//Must be between 1-12
void DateAndTime::setMonth(int m){
    if(m >= 1 && m <= 12){
        month = m;
    }else{
        throw invalid_argument("Month Must be Between 1-12");
    }
}

//Set the day value
//Must be between 1-31
void DateAndTime::setDay(int d){
    switch(month){
        case 2: {
            if(d >= 1 && d <= 28){
                day = d;
            }else{
                throw invalid_argument("Day must be between 1-28 for Month 2");
            }
            break; 
        }
        case 4:
        case 6:
        case 9:
        case 11: {
            if(d >= 1 && d <= 30){
                day = d;
            }else{
                throw invalid_argument("Day must be between 1-30 for Months 4,6,9,11");
            }
            break;
        }
        default: {
            if(d >= 1 && d <= 31){
                day = d;
            }else{
                throw invalid_argument("Day must be between 1-31 for Months 1,3,5,7,8,10,12");
            }
            break;
        }
    }
}

//Set the year value
void DateAndTime::setYear(int y){
    year = y;
}

// return hour value
unsigned int DateAndTime::getHour() const { return hour; }

// return minute value
unsigned DateAndTime::getMinute() const { return minute; }

// return second value
unsigned DateAndTime::getSecond() const { return second; }

// return Time as a string in universal-time format (HH:MM:SS) | MM/DD/YY
string DateAndTime::toUniversalString() const {
    ostringstream output;
    output << setfill('0') << setw(2) << getHour() << ":" << setw(2) << getMinute() << ":" << setw(2) << getSecond() << " | " << month << "/" << day << "/" << year;
    return output.str();
}

// return Time as string in standard-time format (HH:MM:SS AM or PM) | MM/DD/YYY
string DateAndTime::toStandardString() const {
    ostringstream output;
    output << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12) << ":" << setfill('0') << setw(2) << getMinute() << ":" << setw(2) << getSecond() << (hour < 12 ? " AM" : " PM") << " | " << month << "/" << day << "/" << year;
    return output.str();
}

void DateAndTime::tick() {
    //If getSecond + 1 doesn't equal 60, add a second
    if(getSecond()+1 != 60){
        setSecond(getSecond()+1);
    //Else, if getMinute + 1 doesn't equal 60, add a minute and set seconds to 0
    }else{
        if(getMinute()+1 != 60){
            setMinute(getMinute()+1);
            setSecond(0);
        //If getMinute + 1 equals 60, increase hour by one and set minutes to 0
        }else{
            //As long as getHour + 1 doesn't equal 24, increment by 1, then set minutes to 0, as well as set seconds to 0 if applicable
            if(getHour()+1 != 24){
                setHour(getHour()+1);
                setMinute(0);
                if(getSecond()+1 == 60){
                    setSecond(0);
                }
            //If hour == 24, set everything to 0, and increment day
            }else{
                setHour(0);
                setMinute(0);
                setSecond(0);
                nextDay();
            }
        }
    }
}

void DateAndTime::nextDay() {
    switch(month){
        case 2: {
            if(day+1 != 29){
                day += 1;
            }else{
                if(month+1 == 13){
                    year += 1;
                    month = 1;
                    day = 1;
                }else{
                    month += 1;
                    day = 1;
                }
            }
            break; 
        }
        case 4:
        case 6:
        case 9:
        case 11: {
            if(day+1 != 31){
                day += 1;
            }else{
                if(month+1 == 13){
                    year += 1;
                    month = 1;
                    day = 1;
                }else{
                    month += 1;
                    day = 1;
                }
            }
            break;
        }
        default: {
            if(day+1 != 32){
                day += 1;
            }else{
                if(month+1 == 13){
                    year += 1;
                    month = 1;
                    day = 1;
                }else{
                    month += 1;
                    day = 1;
                }
            }
            break;
        }
    } 
}

//Function to display time in standard and universal format, taken from fig09_07.cpp
void DateAndTime::displayTime() {
    cout << "\nUniversal time: " << toUniversalString()
      << "\nStandard time: " << toStandardString() << "\n\n";
}

//Add a message too
void DateAndTime::displayTime(const string& message){
    cout << message << "\nUniversal time: " << toUniversalString()
      << "\nStandard time: " << toStandardString() << "\n\n";
}

