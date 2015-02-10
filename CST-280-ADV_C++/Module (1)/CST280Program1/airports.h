using namespace std;
#include <string>
#include <iostream>
class Airport
{
public:
	string airCode;
	void setAirCode(string a);
	string getAirCode();

	double latitude;
	void setLatitude(double lat);
	double getLatitude();

	double longitude;
	void setLongitude(double lon);
	double getLongitude();

	char timeZone;
	void setTimeZone(char a);
	char getTimeZone();

	Airport();
	Airport(string a, double b ,double c,char d);
	
	string toString();

};
Airport::Airport()
{
	airCode = "";
	latitude = 0;
	longitude = 0;
	timeZone = 'z';
}
Airport::Airport(string a, double b,double c,char d)
{
	airCode = a;
	latitude = b;
	longitude = c;
	timeZone = d;

}
void Airport::setAirCode(string a)
{
	airCode = a;
}
void Airport::setLatitude(double lat)
{
	latitude = lat;
}
void Airport::setLongitude(double lon)
{
	longitude = lon;
}
void Airport::setTimeZone(char a)
{
	timeZone = a;
}
string Airport::getAirCode()
{
	return airCode;
}
double Airport::getLatitude()
{
	return latitude;
}
double Airport::getLongitude()
{
	return longitude;
}
char Airport::getTimeZone()
{
	return timeZone;
}
string Airport::toString()
{
	string output = "";
	output += airCode + " " + to_string(latitude) + " " + to_string(longitude) + " " + timeZone;
	return output;
}