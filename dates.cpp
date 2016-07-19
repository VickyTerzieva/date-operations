#include <iostream>
#include <cstring>
#include <cmath>
#include "dates.h"

using namespace std;

Date :: Date() 
{
	message = new char[100];
	setMonth(1);
	setYear(1900);
	setDay(1);
	setWorkDay(false);
	setClosestWorkDay(false);
}

Date :: Date(int d, int m) 
{ 
	message = new char[100];
	setMonth(m);
	setYear(1900);
	setDay(d);
	setWorkDay(false);
	setClosestWorkDay(false);
}

Date :: Date(int d, int m, int y) 
{
	message = new char[100];
	setMonth(m);
	setYear(y);
	setDay(d);
	setWorkDay(false);
	setClosestWorkDay(false);
}

Date :: Date(Date const& date) 
{
	setDay(date.getDay());
	setMonth(date.getMonth());
	setYear(date.getYear());
	setWorkDay(date.getWorkDay());
	setClosestWorkDay(date.getClosestWorkDay());
	setMessage(date.getMessage());
}

Date :: ~Date()
{
	delete[] message;
}

void Date :: setDay(int d) 
{
	if (d >= 1 && d <= this->getLastDayOfTheMonth())
		day = d;
	else
	{
		day = 1;
		cerr << "Incorrect input of a day! Setting day to 1." << endl;
	}
}

void Date :: setMonth(int m) 
{
	if(m >= 1 && m <= 12)
		month = m;
	else
	{
		month = 1;
		cerr << "Incorrect input of a month! Setting month to 1." << endl;
	}
}

void Date :: setYear(int y) 
{
	if(y > 0 && y < 5000) 
		year = y;	
	else
	{
		year = 1900;
		cerr << "Incorrect input of a year! Setting year to 1900." << endl;
	}
}

void Date :: setWorkDay(bool w) 
{
	workDay = w;
}

void Date :: setClosestWorkDay(bool w)
{
	closestWorkDay = w;
}

void Date :: setMessage(char* m)
{
	message = new char[100];
	strcpy(message, m);
}

void Date :: setDate(Date& date)
{
	setMonth(date.getMonth());
	setYear(date.getYear());
	setDay(date.getDay());
}

int Date :: getDay() const 
{
	return day;
}

int Date :: getMonth() const 
{
	return month;
}

int Date :: getYear() const 
{
	return year;
}

char* Date :: getMessage() const
{
	return message;
}
	
bool Date :: getWorkDay() const 
{
	return workDay;
}

bool Date :: getClosestWorkDay() const 
{
	return closestWorkDay;
}

int Date :: getLastDayOfTheMonth() const 
{
	int max = 1;
	if (this->getMonth() == 2 && this->getYear() % 4 == 0)
		max = 29;
	if (this->getMonth() == 2 && this->getYear() % 4 != 0)
		max = 28;
	switch (this->getMonth())
	{
		case 2: break;
		case 4:
		case 6:
		case 9:
		case 11: max = 30; break;
		default: max = 31;
	}
	return max;
}

char* Date :: getDayOfTheWeek() const 
{
	Date date = *this;
	int m = date.getMonth(); 
	int l,n;
	l = (date.getYear()-12) % 28 / 4;  
	n = date.getYear() % 4;
	date.setYear(2*l - n);
	switch (date.getMonth()) 
	{
		case 1:
		case 10: date.setMonth(8); break; 
		case 2:
		case 3:
		case 11: date.setMonth(5); break;
		case 4:
		case 7: date.setMonth(9); break;
		case 5: date.setMonth(7); break;
		case 6: date.setMonth(4); break;
		case 8: date.setMonth(6); break;
		default: date.setMonth(3);
	}
	int newMonth = date.getMonth() + date.getYear();
	if (n == 0 && (m == 1 || m == 2)) 
		date.addMonth();

	char days[][10] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
	
	int difference = date.getDay() % 7 - newMonth % 7;
	strcpy(message, "The day is ");
	if(difference > 0)
	{
		strcat(message, days[difference]);
	}
	else
	{
		strcat(message, days[6 - abs(difference)]); 
	}
	return message;
}

void Date :: dateFormat(ostream& os) const 
{
	os << "Choose one of the following date formats for your date:" << endl;
	os << "Option 1 - dd.mm.yyyy." << endl;
	os << "Option 2 - mm.dd.yyyy." << endl;
	os << "Option 3 - yyyy.dd.mm." << endl;
	int option;
	cin >> option;
	char dateFormat[11];
	if (option == 1)
		os <<  "\"" << getDay() << '.' << getMonth() << '.' << getYear() << "\"" << endl;
	else if (option == 2)
		os <<  "\"" << getMonth() << '.' << getDay() << '.' << getYear() << "\""  << endl;
	else if (option == 3)
		os <<  "\"" << getYear() << '.' << getDay() << '.' << getMonth() << "\"" << endl;
	else
		os << "Wrong input of an option!" << endl;
}

void Date :: addDay()
{
	if(day < getLastDayOfTheMonth())
	{
		setDay(getDay() + 1);
	}
	else
	{
		setDay(1);
		addMonth();
	}
}

void Date :: subtractDay()
{
	if(day == 1)
	{
		subtractMonth();
		setDay(getLastDayOfTheMonth());
	}
	else
	{
		setDay(day - 1);
	}
}

void Date :: addMonth()
{
	if(month == 12)
	{
		setMonth(1);
		setYear(year + 1);
	}
	else
	{
		setMonth(month + 1);
	}
}

void Date :: subtractMonth()
{
	if(month == 1)
	{
		setMonth(12);
		setYear(year - 1);
	}
	else
	{
		setMonth(month - 1);
	}
}

ostream& operator << (ostream& os, Date const& date) 
{
	date.dateFormat(os);
	return os;
}

istream& operator >> (istream& is, Date& date) 
{
	int d, m, y;
	is >> d;
	if(!is)
	{
		is.clear();
		is.ignore();
		d = date.getDay();
		cerr << "Invalid input of a day!" << endl;
	}
	is.ignore();
	is >> m;
	if(!is)
	{
		is.clear();
		is.ignore();
		m = date.getMonth();
		cerr << "Invalid input of a month!" << endl;
	}
	is.ignore();
	is >> y;
	if(!is)
	{
		is.clear();
		is.ignore();
		y = date.getYear();
		cerr << "Invalid input of a year!" << endl;
	}
	date.setDay(d);
	date.setMonth(m);
	date.setYear(y);
	return is;
}

Date :: Date(char OrdNum[20], char dofw[20], char month[20], int Year) 
{
	int Num = 0, Day = 0, Month = 0;

	char months[][10] = {"January", "February", "March", "April", "May", "June", "July",
					"August", "September", "October", "November", "December"};
	char OrdNums[][11] = {"The first", "The second", "The third", "The fourth", "The last"};
	char days_of_the_week[][10] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

	for(int i = 0; i < 5; i++)
	{
		if(strcmp(OrdNums[i], OrdNum) == 0)
		{
			Num = i + 1;
			break;
		}
	}
	 
	for(int i = 0; i < 7; i++)
	{
		if (strcmp(dofw, days_of_the_week[i]) == 0)
		{
			Day = i + 1;
			break;
		}
	}

	for(int i = 0; i < 12; i++) 
	{
		if (strcmp(month,months[i]) == 0)
		{
			Month = i + 1;
			break;
		}
	}

	Date date(1, Month, Year);

	char week[][22] = {"The day is Monday", "The day is Tuesday", "The day is Wednesday", "The day is Thursday",
					   "The day is Friday", "The day is Saturday", "The day is Sunday"};

	int newDay;
	for(int i = 0; i < 7; i++)
	{
		if(!strcmp(date.getDayOfTheWeek(), week[i]) == 0)
			newDay = i + 1;
	}

	if(Num == 5 && (Num-1)*7 + Day - newDay + 1 > date.getLastDayOfTheMonth())
		Num = 4;
	if(Day < newDay && Num != 5)
		Day = Num*7 + Day - newDay + 1;
	else
		Day = (Num-1)*7 + Day - newDay + 1;

	setDay(Day);
	setMonth(Month); 
	setYear(Year); 
	setWorkDay(false);
	setClosestWorkDay(false);
}

Date Date :: operator + (int d) const 
{
	Date newDate = *this;
	if(d < 0)
		return newDate - (-d);
	while(newDate.getDay() + d > newDate.getLastDayOfTheMonth() && !newDate.getWorkDay())
	{ 
		d -= newDate.getLastDayOfTheMonth() - newDate.getDay();
		newDate.day = 0; 
		newDate.addMonth();
	}
	if(!newDate.getWorkDay())
	{
		newDate.setDay(newDate.getDay() + d);
		if(newDate.getClosestWorkDay())
		{
			newDate.setDate(newDate.setToClosestWorkDay());
		}
		return newDate;
	}
	else // за работни дни
	{
		while(d)
		{
			if(newDate.getDay() != newDate.getLastDayOfTheMonth())
					newDate.setDay(newDate.getDay() + 1);
			else
			{
				if(newDate.getMonth() != 12)
					newDate.setMonth(newDate.getMonth() + 1);
				else
				{
					newDate.setMonth(1);
					newDate.setYear(newDate.getYear() + 1);
				}
				newDate.setDay(1);
			}
			if(newDate.isWorkday())
					d--;
		}
		return newDate;
	}
}

Date operator + (int d, Date const& date) 
{
	return date + d;
}

Date& Date :: operator += (int d) 
{
	*this = *this + d;
	return *this;
}

Date Date :: operator ++ (int) 
{
	Date oldDate = *this;
	addDay();
	return oldDate;
}

Date& Date :: operator ++ () 
{
	addDay();
	return *this;
}

Date Date :: operator - (int d) const 
{
	Date newDate = *this;
	if(d < 0)
		return newDate + (-d);
	while(newDate.getDay() - d < 1 && !newDate.getWorkDay())
	{ 
		d -= newDate.getDay();
		newDate.subtractMonth();
		int newMax = newDate.getLastDayOfTheMonth();
		newDate.setDay(newMax); 
	}
	if(!newDate.getWorkDay())
	{
		newDate.setDay(newDate.getDay() - d);
		if(newDate.getClosestWorkDay())
		{
			newDate.setDate(newDate.setToClosestWorkDay());
		}
		return newDate;
	}
	else
		{
			while(d)
			{
				if(newDate.getDay() != 1)
						newDate.setDay(newDate.getDay() - 1);
				else
				{
					if(newDate.getMonth() != 1)
						newDate.setMonth(newDate.getMonth() - 1);
					else
					{
						newDate.setMonth(12);
						newDate.setYear(newDate.getYear() - 1);
					}
					newDate.setDay(newDate.getLastDayOfTheMonth());
				}
				if(newDate.isWorkday())
						d--;
			}
			return newDate;
		}
}

Date& Date :: operator -= (int d) 
{
	*this = *this - d;
	return *this;
}

Date Date :: operator -- (int) 
{
	Date oldDate = *this;
	subtractDay();
	return oldDate;
}

Date& Date :: operator -- () 
{
	subtractDay();
	return *this;
}

Date Date :: operator * (int m) const 
{
	Date newDate = *this;
	if(m < 0)
		return newDate / (-m);
	if(newDate.getMonth() + m % 12 <= 12)
	{
		newDate.setMonth(newDate.getMonth() + m % 12);
		newDate.setYear(newDate.getYear() + m / 12);
	}
	else
	{
		newDate.setMonth(m % 12 - (12 - newDate.getMonth()));
		newDate.setYear(newDate.getYear() + m / 12 + 1);
	}
	int max = newDate.getLastDayOfTheMonth();
	if(newDate.getDay() > max)
	{
		newDate.setDay(max);
	}
	if(newDate.getClosestWorkDay())
	{
		newDate.setDate(newDate.setToClosestWorkDay());
	}
	return newDate;
}

Date operator * (int m, Date const& date) 
{
	return date * m;
}

Date& Date :: operator *= (int m)
{
	*this = *this * m;
	return *this;
}

Date Date :: operator / (int m) const 
{
	Date newDate = *this;
	if(newDate.getMonth() - m % 12 > 0)
	{
		newDate.setMonth(newDate.getMonth() - m % 12);
		newDate.setYear(newDate.getYear() - m / 12);
	}
	else
	{
		newDate.setMonth(12 - (m % 12 - newDate.getMonth()));
		newDate.setYear(newDate.getYear() - m / 12 - 1);
	}
	int max = newDate.getLastDayOfTheMonth();
	if(newDate.getDay() > max)
	{
		newDate.setDay(max);
	}
	if(newDate.getClosestWorkDay())
	{
		newDate.setDate(newDate.setToClosestWorkDay());
	}
	return newDate;
}		

Date& Date :: operator /= (int m) 
{
	*this = *this / m;
	return *this;
}

Date Date :: operator & (int y) const 
{
	Date newDate = *this;
	newDate.setYear(newDate.getYear() + y);
	int max = newDate.getLastDayOfTheMonth();
	if(newDate.getDay() > max)
	{
		newDate.setDay(max);
	}
	if(newDate.getClosestWorkDay())
	{
		newDate.setDate(newDate.setToClosestWorkDay());
	}
	return newDate;
}

Date operator & (int y, Date const& date) 
{
	return date & y;
}

Date& Date :: operator &= (int y) 
{
	*this = *this & y;
	return *this;
}

Date Date :: operator | (int y) const
{
	Date newDate = *this;
	newDate.setYear(newDate.getYear() - y);
	int max = newDate.getLastDayOfTheMonth();
	if(newDate.getDay() > max)
	{
		newDate.setDay(max);
	}
	if(newDate.getClosestWorkDay())
	{
		newDate.setDate(newDate.setToClosestWorkDay());
	}
	return newDate;
}

Date& Date :: operator |= (int y) 
{
	*this = *this | y;
	return *this;
}

Date Date :: operator ^ (int w) const 
{
	Date newDate = *this;
	newDate += 7*w;
	if(newDate.getClosestWorkDay())
	{
		newDate.setDate(newDate.setToClosestWorkDay());
	}
	return newDate;
}
 
Date operator ^ (int w, Date const& date) 
{
	return date ^ w;
}

Date& Date :: operator ^= (int w) 
{
	*this = *this ^ w;
	return *this;
}

Date Date :: operator % (int w) const 
{
	Date newDate = *this;
	newDate -= 7*w;
	if(newDate.getClosestWorkDay())
	{
		newDate.setDate(newDate.setToClosestWorkDay());
	}
	return newDate;
}

Date& Date :: operator %= (int w) 
{
	*this = *this % w;
	return *this;
}

bool Date :: findMinDate(Date const& date1, Date const& date2) const 
{
	if(date1.getYear() != date2.getYear())
		return date1.getYear() < date2.getYear();
	if(date1.getMonth() != date2.getMonth())
		return date1.getMonth() < date2.getMonth();
	return date1.getDay() < date2.getDay();
}

int Date :: howManyDays(Date const& date) const 
{
	int counter = 0, max;
	max = this->getLastDayOfTheMonth();
	if(date.getYear() > this->getYear())
	{
		counter += max - this->getDay();
		Date a = *this;
		a.setMonth(a.getMonth() + 1);
		for (Date i = a; i.getMonth() < 12; i.setMonth(i.getMonth() + 1))
			counter += i.getLastDayOfTheMonth();
		for (int i = 0; i < date.getYear() - this->getYear() - 1; i++) 
			counter += (i + this->getYear()) % 4 ? 365 : 366;
		Date b = date;
		b.setMonth(b.getMonth() - 1);
		for (Date i = b; i.getMonth() > 1; i.setMonth(i.getMonth() - 1))
			counter += i.getLastDayOfTheMonth();
		counter += date.getDay();
	}
	else
	{
		if(date.getMonth() > this->getMonth())
		{
			counter += max - this->getDay();
			Date a = *this;
			a.setMonth(a.getMonth() + 1);
			for (Date i = a; i.getMonth() < date.getMonth() - 1; i.setMonth(i.getMonth() + 1))
				counter += i.getLastDayOfTheMonth();
			counter += date.getDay();
		}
		else
			counter += date.getDay() - this->getDay();
	}
	return counter;
}

int Date :: operator - (Date const& date) const 
{
	if(findMinDate(*this, date))
		return howManyDays(date);
	else
		return date.howManyDays(*this);
}

int Date :: howManyMonths(Date const& date) const 
{
	int counter = 0;
	if(this->getYear() < date.getYear())
	{
		for(int i = this->getMonth(); i < 12; i++)
			counter ++;
		for(int i = this->getYear() + 1; i < date.getYear(); i++)
			counter += 12;
		counter += date.getMonth();
	}
	else
		counter += date.getMonth() - this->getMonth();
	if(date.getDay() < this->getDay())
		counter --;
	return counter;
}


int Date :: operator / (Date const& date) const 
{
	int counter = 0;
	if(findMinDate(*this, date))
		return howManyMonths(date);
	else
		return date.howManyMonths(*this);
}

int Date :: operator | (Date const& date) const 
{
	int result = abs(this->getYear() - date.getYear());
	Date max, min;
	if(this->getYear() > date.getYear())
	{
		max = *this;
		min = date;
	}
	else
	{
		max = date;
		min = *this;
	}
	if( (max.getMonth() < min.getMonth() || (max.getMonth() == min.getMonth() 
		&& max.getDay() < min.getDay())) && (max.getYear() != min.getYear()) )
		result --;
	return result;
}

int Date :: operator % (Date const& date) const 
{
	int result = (*this - date)/7;
	return result;
}

Date Date :: isEaster() const 
{
	Date Easter = *this;
	int a, b, c, d, e;
	a = this->getYear() % 19;
	b = this->getYear() % 4;
	c = this->getYear() % 7;
	d = (19 * a + 15) % 30;
	e = (2 * b + 4 * c + 6 * d + 6) % 7;
	if ((d+e) > 10){
		int x = d + e + 4;
		Easter.setMonth(4);
		if (x > 30)
		{
			Easter.setDay(x % 30);
			Easter.setMonth(5);
		}
		else
			Easter.setDay(x);
	}
	else {
		int z = 35 + d + e;
		Easter.setMonth(4);
		Easter.setDay(z % 31);
	}
	return Easter;
}

bool Date :: operator == (Date const& date) const 
{
	if(this->getDay() == date.getDay() && this->getMonth() == date.getMonth())
		return 1;
	else
		return 0;
}

bool Date :: isWorkday() const 
{
	Date date, date1(3,3), date2(1,5), date3(6,5), date4(24,5), date5(6,9), date6(22,9), date7(1,11), date8(24,12),
		date9(25,12), date10(26,12), date11 = isEaster(), date12 = date11, date13 = date11, date14 = date11;

	date12.subtractDay(); 
	date13.subtractDay();
	date13.subtractDay();
	date14.addDay();

	Date arr[] = {date, date1, date2, date3, date4, date5, date6, date7, date8,
		date9, date10, date11, date12, date13, date14};

	for(int i = 0; i < 14; i++)
	{
		if(*this == arr[i])
		{
			return 0;
		}
	}
	if(!strcmp(this->getDayOfTheWeek(), "The day is Saturday") ||
		!strcmp(this->getDayOfTheWeek(), "The day is Sunday"))
			return 0;
	else 
		return 1;
}

Date Date :: setToClosestWorkDay() const 
{
	int s;
	Date newDate = *this, newDate2 = *this; 
	int newDay1 = newDate.getDay(), newDay2 = newDate.getDay(); 
	cout << "Choose 1 to find the closest work day after the current one." << endl;
	cout << "Choose 2 to find the closest work day before the current one." << endl;
	cout << "Choose 3 to find the closest work day no matter before or after the current one." << endl;
	cin >> s;
	if(newDate.isWorkday())
		return *this;
	else
	{
		if(s == 1 || s == 3)
		{
			while(!newDate.isWorkday())
			{
				newDate++;
				newDay1++;
			}
			newDate.setDay(newDay1);
		}
		if(s == 2 || s == 3)
		{
			while(!newDate2.isWorkday())
			{
				newDate2--;
				newDay2--;
			}
			newDate.setDay(newDay2);
		}
		if(s == 3)
		{
			if(abs(this->getDay() - newDay1) > abs(this->getDay() - newDay2))
				newDate.setDay(newDay2);
			else
				newDate.setDay(newDay1);
		}
	}
	return newDate;
}