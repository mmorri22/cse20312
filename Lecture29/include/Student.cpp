#include "Student.h"

Student::Student() : 
	stuID (),
	stuFirst (),
	stuLast (),
	stuEmail (),
	stuMajor () {}

Student::Student(unsigned int stuIDIn, std::string stuFirstIn, std::string stuLastIn,
	std::string stuEmailIn, std::string stuMajorIn) :
	stuID (stuIDIn),
	stuFirst (stuFirstIn),
	stuLast (stuLastIn),
	stuEmail (stuEmailIn),
	stuMajor (stuMajorIn) {}	
	
	
void Student::setID( unsigned int IDIn ){
	this->stuID = IDIn;
}

bool Student::operator<=(const Student& rhs){
	return this->stuID <= rhs.stuID;
}

bool Student::operator<(const Student& rhs){
	return this->stuID < rhs.stuID;
}

bool Student::operator>=(const Student& rhs){
	return this->stuID >= rhs.stuID;
}

bool Student::operator>(const Student& rhs){
	return this->stuID > rhs.stuID;
}

bool Student::operator==(const Student& rhs){
	return this->stuID == rhs.stuID;
}

std::ostream& operator<<(std::ostream& out, const Student& theStudent){
	
	out << theStudent.stuID << ": ";
	out << theStudent.stuLast << ", " << theStudent.stuFirst << ".";
	out << theStudent.stuEmail << ", " << theStudent.stuMajor << std::endl;
	
	return out;
}