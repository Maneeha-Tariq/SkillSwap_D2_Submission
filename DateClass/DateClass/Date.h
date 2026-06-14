#ifndef DATE_H
#define DATE_H
#include<iostream>
using namespace std;
class Date
{
	int day;
	int month;
	int year;
	void incrementMonth()
	{
		month++;
		if (month > 12)
		{
			month = 1;
			year++;
		}
	}
	bool isLeapYear(int y)
	{
		return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);

	}
	void addInMonth31(int  d)
	{
		while (d > 31)
		{
			d = d - 31;
			incrementMonth();
		}
		day = d;
		
	}
	void addInMonth30(int d)
	{
		while (d > 30)
		{
			d = d - 30;
			incrementMonth();
		}
		day = d;
		
	}
	void addInMonthFeb(int d)
	{
		int limit = isLeapYear(year) ? 29 : 28;
		while(d > limit)
		{
			d = d - limit;
			incrementMonth();
			limit = isLeapYear(year) ? 29 : 28;
		}
			
		day = d;
	}
	void decrementMonth()
	{
		month--;
		while (month < 1)
		{
			month = 12;
			year--;
		}
	}
	
public:
	void setDay(int d)
	{
		day = d;
	}
	void setMonth(int m)
	{
		month = m;
	}
	void setYear(int y)
	{
		year = y;
	}
	int getDay() const
	{
		return day;
	}
	int getMonth() const
	{
		return month;
	}
	int getYear() const
	{
		return year;
	}
	void displayDate()
	{
		if (day < 10)
			cout << "0" << day;
		else
			cout << day;

		cout << "/";
		if (month < 10)
			cout << "0" << month;
		else
			cout << month;

		cout << "/" << year;
	}
	void addDays(int days)
	{
		int d = day + days;
		
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10|| month == 12)
		{
			addInMonth31(d);
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			addInMonth30(d);
		}
		else 
		{
			addInMonthFeb(d);
			
		}
	}
	void subtractD(int days)
	{
		int d = day - days;

		while (d < 1)
		{
			decrementMonth();

			int limit;
			if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
				limit = 31;
			else if (month == 4 || month == 6 || month == 9 || month == 11)
				limit = 30;
			else
				limit = isLeapYear(year) ? 29 : 28;

			d += limit; 
		}

		day = d;
	}
	void input()
	{
		cin >> day;
		cin >> month;
		cin >> year;
	}

};
#endif