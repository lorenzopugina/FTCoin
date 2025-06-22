#ifndef DATE_H_
#define DATE_H_

#include <iostream>
#include <ctime>

class Date
	{
	private:
		int day;
		int month;
		int year;

		bool isValidDate(int day, int month, int year) const;

	public:
		Date(); // para data atual
		Date(int day, int month, int year);
		virtual ~Date();

		int getYear();
		int getMonth();
		int getDay();

		std::string toString() const; // sera q vai usar?
	};

#endif /* DATE_H_ */
