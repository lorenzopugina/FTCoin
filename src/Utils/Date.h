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

		// valida se é uma data possível
		bool isValidDate(int day, int month, int year) const;

	public:
		Date(); // para data atual
		Date(int day, int month, int year);
		virtual ~Date();

		int getYear();
		int getMonth();
		int getDay();

		void setDate(int day, int month, int year);

		bool operator==(const Date &other) const;
		bool operator!=(const Date &other) const;
		bool operator>(const Date &other) const;
		bool operator>=(const Date &other) const;
		bool operator<(const Date &other) const;
		bool operator<=(const Date &other) const;

		friend std::ostream& operator<<(std::ostream &os, const Date &date);
		friend std::istream& operator>>(std::istream &is, Date &date);
	};

#endif /* DATE_H_ */
