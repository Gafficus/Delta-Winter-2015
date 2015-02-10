//Created by: Nathan Gaffney
//Attempting to make my own format
//This class holds information on an employee
#include <iostream>
#include <string>
class EmployeeData
{
private:
	double hoursWorked;
	double payPerHour;
	std::string idNumber;

public:
	/*************Basic Class Functions***************/
	//Constructor				 
	EmployeeData();
	//Getters and Setters for class attributs
	void     setHoursWorked(double a) { hoursWorked = a; }
	double   getHoursWorked()         { return hoursWorked; }

	void		  setPayPerHour(double a) { payPerHour = a; }
	double	  getPayPerHour()         { return payPerHour; }

	void	 setIdNumber(std::string a) { idNumber = a; }
	std::string getIdNumber()         { return idNumber; }

	std::string toString();

};
EmployeeData::EmployeeData()
{
	hoursWorked = -1;
	payPerHour = -1;
	idNumber = "IdNumber was not set";
}
std::string EmployeeData::toString()
{
	std::string output;
	std::string space = "   ";
	output = idNumber + space + std::to_string(hoursWorked) + space + std::to_string(payPerHour) + "\n";
	return output;
}