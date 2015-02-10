//Created by Nathan Gaffney with functions from class
#include <iostream>
#include <fstream>
#include "Employee.h"
void bubleSortEmployee(EmployeeData anArray[], int numElems);
void sinkSortEmployee(EmployeeData anArray[], int numElems);
void populateArray(std::ifstream &inFile, EmployeeData anArray[], int& numElems);
void outputArray(std::ofstream &outFile, EmployeeData anArray[], int numElems);
void addElement(EmployeeData anArray[], int numElems);
void deleteElement(EmployeeData anArray[], int& numElems);
int main()
{
	const int MAX_ARRAY = 25;
	int numElems, choice = 0;
	EmployeeData	empArray[MAX_ARRAY];
	bool cont = true;
	std::ifstream inFile("EmployeeInfo.txt");
	std::ofstream outFile("SortedArray.txt");
	populateArray(inFile, empArray, numElems);
	do
	{
		std::cout << "What would you like to do" << std::endl <<
			"1. Add an element." << std::endl <<
			"2. Delet an Element" << std::endl <<
			"3. Bubble Sort" << std::endl <<
			"4. Sink Sort" << std::endl <<
			"5. Output the Array" << std::endl <<
			"0. To Exit." << std::endl;
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			addElement(empArray, numElems);
			break;
		case 2:
			deleteElement(empArray, numElems);
			break;
		case 3:
			bubleSortEmployee(empArray, numElems);
			break;
		case 4:
			sinkSortEmployee(empArray, numElems);
			break;
		case 5:
			outputArray(outFile, empArray, numElems);
			break;
		default:
			cont = false;
			break;
		}
	} while (cont);
	std::system("pause");
	return 0;
}
void bubleSortEmployee(EmployeeData anArray[], int numElems)
{
	int            placePtr;    // Index for comparing adjacent elements
	int            endIndex;    // Index of stopping point for one pass
	EmployeeData    temp;        // Needed for swapping contents

	for (endIndex = numElems - 1; endIndex >= 0; endIndex--)
	{
		for (placePtr = 0; placePtr <= endIndex; placePtr++)
			if (anArray[placePtr].getHoursWorked() < anArray[placePtr + 1].getHoursWorked())
			{
			temp.setHoursWorked(anArray[placePtr + 1].getHoursWorked());
			temp.setPayPerHour(anArray[placePtr + 1].getPayPerHour());
			temp.setIdNumber(anArray[placePtr + 1].getIdNumber());
			anArray[placePtr + 1].setHoursWorked(anArray[placePtr].getHoursWorked());
			anArray[placePtr + 1].setPayPerHour(anArray[placePtr].getPayPerHour());
			anArray[placePtr + 1].setIdNumber(anArray[placePtr].getIdNumber());
			anArray[placePtr].setHoursWorked(temp.getHoursWorked());
			anArray[placePtr].setPayPerHour(temp.getPayPerHour());
			anArray[placePtr].setIdNumber(temp.getIdNumber());
			}
	}
}
void sinkSortEmployee(EmployeeData anArray[], int numElems)
{
	int            placePtr;    // Index for comparing adjacent elements
	int            endIndex;    // Index of stopping point for one pass
	EmployeeData    temp;        // Needed for swapping contents

	for (endIndex = 0; endIndex <= numElems; endIndex++)
	{
		for (placePtr = 0; placePtr <= endIndex; placePtr++)
			if (anArray[placePtr].getPayPerHour() > anArray[placePtr + 1].getPayPerHour())
			{
			temp.setHoursWorked(anArray[placePtr + 1].getHoursWorked());
			temp.setPayPerHour(anArray[placePtr + 1].getPayPerHour());
			temp.setIdNumber(anArray[placePtr + 1].getIdNumber());
			anArray[placePtr + 1].setHoursWorked(anArray[placePtr].getHoursWorked());
			anArray[placePtr + 1].setPayPerHour(anArray[placePtr].getPayPerHour());
			anArray[placePtr + 1].setIdNumber(anArray[placePtr].getIdNumber());
			anArray[placePtr].setHoursWorked(temp.getHoursWorked());
			anArray[placePtr].setPayPerHour(temp.getPayPerHour());
			anArray[placePtr].setIdNumber(temp.getIdNumber());
			}
	}
}
void populateArray(std::ifstream &inFile, EmployeeData anArray[], int& numElems)
{
	std::string id;
	double hours;
	double pay;
	int ptr = 0;
	inFile >> id >> hours >> pay;        // Priming read
	while (!inFile.eof())
	{
		// Store information from file in current array object
		anArray[ptr].setIdNumber(id);
		anArray[ptr].setHoursWorked(hours);
		anArray[ptr].setPayPerHour(pay);

		inFile >> id >> hours >> pay;    // Continuation read
		ptr++;
	}
	numElems = ptr;
}
void outputArray(std::ofstream &outFile, EmployeeData anArray[], int numElems)
{
	for (int i = 0; i < numElems; i++)
	{
		outFile << anArray[i].toString();

	}
}
void addElement(EmployeeData anArray[], int numElems)
{
	double hours, worked;
	std::string id;
	int place = numElems + 1;
	std::cout << "Enter the employee Id Number: ";
	std::cin >> id;
	std::cout << "Enter the number of hours worked: ";
	std::cin >> hours;
	std::cout << "Enter the amount paid per hour: " << std::endl;
	std::cin >> worked;
	anArray[place].setIdNumber(id);
	anArray[place].setHoursWorked(hours);
	anArray[place].setPayPerHour(worked);
}
void deleteElement(EmployeeData anArray[], int& numElems)
{
	double oldNum;
	int ptr;
	std::cout << "Enter the hours worked by the employee: ";
	std::cin >> oldNum;
	ptr = 0;                              // Scan list for deletion target
	while (oldNum != anArray[ptr].getPayPerHour() && ptr < numElems)
		ptr++;

	if (ptr < numElems)                       // If target found, then
	{
		anArray[ptr].setHoursWorked(anArray[numElems - 1].getHoursWorked());
		anArray[ptr].setPayPerHour(anArray[numElems - 1].getPayPerHour());
		anArray[ptr].setIdNumber(anArray[numElems - 1].getIdNumber());
		numElems--;                           // Decrement size of list
	}
	bubleSortEmployee(anArray, numElems);
}