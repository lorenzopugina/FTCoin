#include <iomanip>
#include <ctime>

#include "Date.h"

using namespace std;

Date::Date(){
	time_t now = time(NULL);
	tm *currentTime = localtime(&now);
	day = currentTime->tm_mday;
	month = currentTime->tm_mon+1; 
	year = currentTime->tm_year+1900; 
}

Date::Date(int day, int month, int year) {
	if (!isValidDate(day, month, year)) {
		throw std::invalid_argument("Invalid date.");
	}
	this->day = day;
	this->month = month;
	this->year = year;
}

Date::~Date(){}

int Date::getYear() { return this->year; }
int Date::getMonth() { return this->month; }
int Date::getDay() { return this->day; }

void Date::setDate(int day, int month, int year){
	
	if(isValidDate(day, month, year)){
		this->day = day;
		this->month = month;
		this->year = year;
	}
}

// Checks if the given day is within the limit of the number of days in each month and the date is valid
bool Date::isValidDate(int day, int month, int year) const {
	if (day < 1 || month < 1 || month > 12 || year < 2000) return false;

	int monthDays[] = { 31, 28, 31, 30, 31, 30, 
	                    31, 31, 30, 31, 30, 31 };

	return day <= monthDays[month - 1]; 
}

bool Date::operator==(const Date &other) const{
	return year == other.year && month == other.month && day == other.day;
}

bool Date::operator!=(const Date &other) const{
	return !(*this == other);
}

bool Date::operator>(const Date &other) const{
	if (year != other.year)
		return year > other.year;
	if (month != other.month)
		return month > other.month;
	return day > other.day;
}

bool Date::operator>=(const Date &other) const{
	return (*this == other) || (*this > other);
}

bool Date::operator<(const Date &other) const{
	return !(*this >= other);
}

bool Date::operator<=(const Date &other) const{
	return !(*this > other);
}

ostream& operator<<(ostream &os, const Date &date){
	os << setfill('0') << setw(2) << date.day<< ".";
	os << setfill('0') << setw(2) << date.month << ".";
	os << setfill('0') << setw(4) << date.year ;
	return os;
}

istream& operator>>(std::istream &is, Date &date){
	char separator;
	is >> date.day >> separator >> date.month >> separator >> date.year;
	return is;
}