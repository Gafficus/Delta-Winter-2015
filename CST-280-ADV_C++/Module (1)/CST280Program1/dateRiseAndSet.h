//DO I NEED THIS?!?!
using namespace std;
#include <string>
class Date 
{
private:
	int dayInt;
	int monthInt;
	int yearInt;
public:
	void setDayInt(int day);
	void setMonthInt(int month);
	void setYearInt(int year);
	int getDay();
	int getMonth();
	int getYear();
	Date(int day, int month, int year);


};
Date::Date(int day, int month, int year)
{
	
}
void Date::setDayInt(int day)
{
	dayInt = day;
}
void Date::setMonthInt(int month)
{
	monthInt = month;
}
void Date::setYearInt(int year)
{
	yearInt = year;
}
int Date::getDay()
{
	return dayInt;
}
int Date::getMonth()
{
	return monthInt;
}
int Date::getYear()
{
	return yearInt;
}