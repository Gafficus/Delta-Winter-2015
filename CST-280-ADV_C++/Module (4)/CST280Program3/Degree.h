#include <string>
//Create an object to hold graduate's information
class GraduateDegree
{
public:
	GraduateDegree();
	~GraduateDegree();
	std::string toString();

private:
	std::string gradName;
	std::string universityName;
	std::string gradDate;
	std::string gradDegree;

};

GraduateDegree::GraduateDegree()
{
	gradName = "Default Constructed";
	universityName = "Default Name";

}

GraduateDegree::~GraduateDegree()
{
}
std::string GraduateDegree::toString()
{
}
//Try overloading the << operator?