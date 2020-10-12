#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>

class Student{
	
	private:
	
		unsigned int stuID;
		std::string stuFirst;
		std::string stuLast;
		std::string stuEmail;
		std::string stuMajor;

	public:
	
		Student();
		
		Student(unsigned int stuIDIn, std::string stuFirstIn, std::string stuLastIn,
			std::string stuEmailIn, std::string stuMajorIn);
			
		void setID( unsigned int IDIn );
		
		bool operator<=(const Student& rhs);

		bool operator<(const Student& rhs);

		bool operator>=(const Student& rhs);

		bool operator>(const Student& rhs);
		
		bool operator==(const Student& rhs);
		
		friend std::ostream& operator<<(std::ostream& out, const Student& theStudent);
};

#endif