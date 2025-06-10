
 // inspirado e alterado no do professor, colocar aquele blocão de comentário?

#include <iomanip>
#include <ctime>

#include "Date.h"

using namespace std;

Date::Date(){
	time_t now = time(NULL);
	tm *currentTime = localtime(&now);
	day = currentTime->tm_mday;
	month = currentTime->tm_mon; // talvez +1
	year = currentTime->tm_year; // talvez +1900
}

Date::Date(int day, int month, int year) {
	if (!isValidDate(day, month, year)) {
		throw std::invalid_argument("Data inválida.");
	}
	this->day = day;
	this->month = month;
	this->year = year;
}

Date::~Date(){}

int Date::getYear() { return this->year; }
int Date::getMonth() { return this->month; }
int Date::getDay() { return this->day; }

bool Date::isValidDate(int day, int month, int year) const {
	if (day < 1 || month < 1 || month > 12 || year < 2000) return false; // rever o < 2000

	int diasNoMes[] = { 31, 28, 31, 30, 31, 30, 
	                    31, 31, 30, 31, 30, 31 };

	// verifica se o dia fornecido está dentro do limite da qtd de dias de cada mes
	return day <= diasNoMes[month - 1]; 
}


// será q vai usar?
std::string Date::toString() const {
    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << day << '/';
    oss << std::setw(2) << std::setfill('0') << month << '/';
    oss << std::setw(4) << std::setfill('0') << year;
    return oss.str();
}