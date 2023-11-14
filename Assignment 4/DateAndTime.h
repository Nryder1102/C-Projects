//Date And Time

#include <string>

// prevent multiple inclusions of header
#ifndef DATEANDTIME_H
#define DATEANDTIME_H

class DateAndTime{
public:
    explicit DateAndTime(int = 0, int = 0, int = 0, unsigned int = 1, unsigned int = 1, unsigned int = 2000);


    // set functions
	void setTime(int, int, int); // set hour, minute, second
	void setHour(int); // set hour (after validation)
	void setMinute(int); // set minute (after validation)
	void setSecond(int); // set second (after validation)
    void setDate(unsigned int, unsigned int, unsigned int); // set m/d/y
	void setMonth(int); // set month (after validation)
	void setDay(int); // set day (after validation)
	void setYear(int); // set year (after validation)

	// get functions
	unsigned int getHour() const; // return hour
	unsigned int getMinute() const; // return minute
	unsigned int getSecond() const; // return second
    unsigned int getMonth() const; // return month
	unsigned int getDay() const; // return day
	unsigned int getYear() const; // return year

	std::string toUniversalString() const; // 24-hour time format string
	std::string toStandardString() const; // 12-hour time format string

	//Extra Functions for the Assignment
	void tick();
    void nextDay();
	void displayTime();
	void displayTime(const std::string&);

private:
	unsigned int hour{ 0 }; // 0 - 23 (24-hour clock format)
	unsigned int minute{ 0 }; // 0 - 59
	unsigned int second{ 0 }; // 0 - 59
    unsigned int month; // 1-12
    unsigned int day; // 1-30 (Based on Month)
    unsigned int year; //Must be a number
};

#endif
