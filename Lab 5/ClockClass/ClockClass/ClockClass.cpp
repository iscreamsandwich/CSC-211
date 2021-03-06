// ClockClass.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class clockType {
public:
	void setTime(int, int, int);	//sets time for clock object
	void getTime(int&, int&, int&) const;	//returns time that is set on clock object
	void printTime() const;		//outputs time on clock
	//increment s, m, h by 1
	void incrementSeconds();	
	void incrementMinutes();
	void incrementHours();

	bool equalTime(const clockType&) const;		//checks if two clocks have the same time
	clockType();		//default constructor
	clockType(int);		//constructor that sets hour only to 0
	clockType(int, int, int);	//constructor that sets hour, minute and second to 0

private:
	int hr;		//hour value
	int min;	//minute value
	int sec;	//second value
};

int main()
{
	//declare two clocks
	clockType clockOne, clockTwo;

	//create variables for 2:15:25
	int hours = 2, minutes = 15, seconds = 25;

	cout << "Setting time for clock 1 to 02:15:25.\n";
	clockOne.setTime(hours, minutes, seconds);	//sets time on clockOne to 2:15:25
	clockOne.printTime();					//output time
	cout << "\nIncrementing seconds, minutes, and hours.\n";		//increment all values
	clockOne.incrementSeconds();
	clockOne.incrementMinutes();
	clockOne.incrementHours();
	clockOne.printTime();				//output time again
	clockOne.getTime(hours, minutes, seconds); 

	cout << endl;

	hours = 15, minutes = 35, seconds = 0;	
	cout << "\nSetting time for clock 2 to 15:35:0.\n";
	clockTwo.setTime(hours, minutes, seconds);		//sets time on clockTwo to 15:35:00
	clockTwo.printTime();		//output time
	cout << "\nIncrementing seconds, minutes, and hours.\n";		//increment all values
	clockTwo.incrementSeconds();
	clockTwo.incrementMinutes();
	clockTwo.incrementHours();		
	clockTwo.printTime();			//output time again
	clockTwo.getTime(hours, minutes, seconds);

	cout << "\nInvoking method to check if they're equal: ";
	cout << clockOne.equalTime(clockTwo);	//check if clockOne and clockTwo are equal and output 0 for false

	system("pause");

    return 0;
}

void clockType::setTime(int hours, int minutes, int seconds)
{
	if (0 <= hours && hours <= 23)
		hr = hours;
	else hr = 0;
	if (0 <= minutes && minutes <= 23)
		min = minutes;
	else min = 0;
	if (0 <= seconds && seconds <= 23)
		sec = seconds;
	else sec = 0;
}

void clockType::getTime(int & hours, int & minutes, int & seconds) const
{
	hours = hr;
	minutes = min;
	seconds = sec;
}

void clockType::printTime() const
{
	if (hr < 10)
		cout << "0";
	cout << hr << ":";
	if (min < 10)
		cout << "0";
	cout << min << ":";
	if (sec < 10)
		cout << "0";
	cout << sec;
}

void clockType::incrementSeconds()
{
	sec++;
	if (sec > 59)
		sec = 0;
}

void clockType::incrementMinutes()
{
	min++;
	if (min > 59)
		min = 0;
}

void clockType::incrementHours()
{
	hr++;
	if (hr > 23)
		hr = 0;
}

bool clockType::equalTime(const clockType & otherClock) const
{
	return (hr == otherClock.hr 
		&& min == otherClock.min 
		&& sec == otherClock.sec);
}

clockType::clockType()
{
	hr = 0;
	min = 0;
	sec = 0;
}

clockType::clockType(int hours)
{
	hr = hours;
}

clockType::clockType(int hours, int minutes, int seconds)
{
	setTime(hours, minutes, seconds);
}
