#ifndef DATES_H
#define DATES_H

#include <iostream>

using namespace std; 

class Date
{
	int day;
	int month;
	int year;
	bool workDay;
	bool closestWorkDay;
	char* message; 
public:
	Date();
	Date(int, int);
	Date(int, int, int);
	Date(char*, char*, char*, int);
	Date(Date const&);
	~Date();
	void setDay(int);
	void setMonth(int);
	void setYear(int);
	void setWorkDay(bool);
	void setClosestWorkDay(bool);
	Date setToClosestWorkDay() const;
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	char* getDayOfTheWeek() const;
	friend istream& operator >> (istream&, Date&); 
	friend ostream& operator << (ostream&, Date const&);
	Date operator + (int) const;
	friend Date operator + (int, Date const&);
	Date& operator += (int);
	Date operator ++ (int);
	Date& operator ++ ();
	Date operator - (int) const;
	Date& operator -= (int);
	Date operator -- (int);
	Date& operator -- ();
	Date operator * (int) const;
	friend Date operator * (int, Date const&);
	Date& operator *= (int);
	Date operator / (int) const;
	Date& operator /= (int);
	Date operator & (int) const;
	friend Date operator & (int, Date const&);
	Date& operator &= (int);
	Date operator | (int) const;
	Date& operator |= (int);
	Date operator ^ (int) const;
	friend Date operator ^ (int, Date const&);
	Date& operator ^= (int);
	Date operator % (int) const;
	Date& operator %= (int);
	int operator - (Date const&) const;
	int operator / (Date const&) const;
	int operator | (Date const&) const;
	int operator % (Date const&) const;
	bool isWorkday() const;
private:
	void addDay();
	void subtractDay();
	void addMonth();
	void subtractMonth();
	void setDate(Date&);
	void setMessage(char*);
	char* getMessage() const;
	bool getWorkDay() const;
	bool getClosestWorkDay() const;
	bool operator == (Date const&) const; 
	Date isEaster() const;
	bool findMinDate(Date const&, Date const&) const;
	int howManyDays(Date const&) const;
	int howManyMonths(Date const&) const;
	int getLastDayOfTheMonth() const; 
	void dateFormat(ostream& = cout) const;
};

#endif