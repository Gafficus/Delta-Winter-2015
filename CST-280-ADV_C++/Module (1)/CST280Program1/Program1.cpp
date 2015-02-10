#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "airports.h"
#include "datefun.h"
#include "sun.h"
/*
Created by Nathan Gaffney
CST 280 ADV C++
Program1
THis program displays the sunrise and
sunset of the week of a given date.
*/

using namespace std;
const int MAXARRAY = 100;
/*Function Prototypes*/
void buildLstAirports(Airport a[], int& numNumbers);
void validateData(int year, int month, int day, string airCode, Airport lstAirports[], int numElems);
bool isDST(char day[], int month, int weekdayValue, int dayNumber );
int main()
{
	/************/
	//For the Continue Loop
	char answer;
	bool cont = true;
	/************/
	int numElems = 0;
	int enteredDate, yearInt, monthInt, dayInt;
	string airCode;
	bool DST= false;
	int dayNum;
	char day[3];
	double latitude, longitude;
	char timeZone;
	TextTime sunRise, sunSet;
	Airport lstAirports[MAXARRAY];
	buildLstAirports(lstAirports, numElems);

	do
	{
		cout << "Enter a date in the format of yyyymmdd: ";
		cin >> enteredDate;
		yearInt = enteredDate / 10000;
		monthInt = enteredDate%10000/100;
		dayInt = enteredDate % 100;

		cout << "Enter an airport three character code: ";
		cin >> airCode;
		for (int i = 0; i < 3; i++)
		{
			airCode[i] = toupper(airCode[i]);
		}
		validateData(yearInt, monthInt, dayInt, airCode, lstAirports, numElems);
		dayNum = weekDay(monthInt, dayInt, yearInt);
		DST = isDST(day, monthInt, dayNum, dayInt);
		for (int i = 0; i < numElems ; i++)
		{
			if (airCode == lstAirports[i].getAirCode())
			{
				latitude = lstAirports[i].getLatitude();
				longitude = lstAirports[i].getLongitude();
				timeZone = lstAirports[i].getTimeZone();
			}
		}
		

		/******************Output******************/
		for (int i = dayNum; i > 0; i--)
		{

			if (dayInt - 1 == 0)
			{
				if (monthInt - 1 == 0)
				{
					yearInt--;
					monthInt = 12;
					dayInt = DaysInMonth(monthInt, yearInt) - 1;
				}
				else
				{
					monthInt--;
					dayInt = DaysInMonth(monthInt, yearInt) - 1;
				}
				
			}
			else
			{
				dayInt--;
			}
		}
		for (int i = 0; i <= 6; i++)
		{
			if (dayInt > DaysInMonth(monthInt, yearInt))
			{
				if (monthInt  >= 12)
				{
					yearInt++;
					monthInt = 1;
				}
				else
				{
					monthInt++;
				}
				dayInt = 1;
			}
			dayCode(weekDay(monthInt, dayInt, yearInt), day);
			cout << day << " ";
			cout << setw(2) << setfill('0') << dayInt; //Creates a 0 infront of single digits
			switch (monthInt)
			{
			case 1:
				cout << " JAN ";
				break;
			case 2:
				cout << " FEB ";
				break;
			case 3:
				cout << " MAR ";
				break;
			case 4:
				cout << " APR ";
				break;
			case 5:
				cout << " MAY ";
				break;
			case 6:
				cout << " JUN ";
				break;
			case 7:
				cout << " JUL ";
				break;
			case 8:
				cout << " AUG ";
				break;
			case 9:
				cout << " SEP ";
				break;
			case 10:
				cout << " OCT ";
				break;
			case 11:
				cout << " NOV ";
				break;
			case 12:
				cout << " DEC ";
				break;
			default:
				break;
			}
			Sun_Rise_Set(latitude, longitude, monthInt, dayInt, yearInt, timeZone, DST, sunRise, sunSet);
			cout << yearInt << "  ";
			cout << "Rise:  " << sunRise << " am" << "  ";
			cout << "Set:  " << sunSet << " pm" << endl;
			dayInt++;
		}
		/***********Continuation Loop****************/
		cout << "Do you want to continue? Y/N: ";
		cin >> answer;
		if (answer != 'Y' && answer != 'y')
		{
			if (answer == 'N' || answer== 'n'){ cont = false; }
			
			else
			{
				cout << "Incorrect character entered. Exiting." << endl;
				cont = false;
			}
		}
		
	} while (cont);
	system("pause");
   return 0;
}
void buildLstAirports(Airport a[], int& numNumbers)
{
	int i = 0;
	string string;
	char char1;
	double number1, number2;

	ifstream fileIn;
	fileIn.open("cityinfo.txt");

	if (fileIn.fail())
	{
		cout << "Problem opening file";
		exit(-1);
	}

	fileIn >> string >> number1 >> number2 >> char1;
	a[i].setAirCode(string);
	a[i].setLatitude(number1);
	a[i].setLongitude(number2);
	a[i].setTimeZone(char1);


	while (!fileIn.eof() && i < MAXARRAY)    // Test for end of file and array     
	{

		i++;
		fileIn >> string >> number1 >> number2 >> char1;
		a[i].setAirCode(string);
		a[i].setLatitude(number1);
		a[i].setLongitude(number2);
		a[i].setTimeZone(char1);
	}
	numNumbers = i;
}
void validateData(int year, int month, int day, string airCode, Airport list[], int numElems)
{
	bool found = false;
	if (!validDate(month, day, year))
	{
		cout << "Invalid date! Exiting.";
		system("pause");
		exit(1);
	}
	for (int i = 0; i < numElems && !found; i++)
	{
		if (airCode == list[i].getAirCode()){ found = true; }
	}
	if (!found)
	{
		cout << "Invalid Airport Code! Exiting.";
		system("pause");
		exit(1);
	}

}
bool isDST(char day[], int month, int weekdayValue, int dayNumber)
{
	bool isDST = false;

	if (month == 4 || month == 5 || month == 6 || month == 7 || month == 8)
	{
		isDST = true;
	}
	else
	{
		if (month == 3)
		{
			switch (weekdayValue)
			{
			case 0:   if (dayNumber >= 8)
				isDST = true;

				break;
			case 1:   if (dayNumber >= 14)
				isDST = true;

				break;
			case 2:   if (dayNumber >= 13)
				isDST = true;

				break;
			case 3:   if (dayNumber >= 12)
				isDST = true;

				break;
			case 4:   if (dayNumber >= 11)
				isDST = true;

				break;
			case 5:   if (dayNumber >= 10)
				isDST = true;

				break;
			case 6:   if (dayNumber >= 9)
				isDST = true;

				break;
			};
		}
		else
		{
			switch (weekdayValue)
			{
			case 0:   if (dayNumber <= 1)
				isDST = false;
				break;
			case 1:   if (dayNumber <= 7)
				isDST = true;

				break;
			case 2:   if (dayNumber <= 6)
				isDST = true;

				break;
			case 3:   if (dayNumber <= 5)
				isDST = true;

				break;
			case 4:   if (dayNumber <= 4)
				isDST = true;

				break;
			case 5:   if (dayNumber <= 3)
				isDST = true;

				break;
			case 6:   if (dayNumber <= 2)
				isDST = true;

				break;
			};
		}
	}
	return isDST;
}