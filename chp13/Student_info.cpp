// Student_info.cpp
#include <iostream>

#include "Core.h"
#include "Student_info.h"
#include "Grad.h"

using std::istream;

istream& Student_info::read(istream& is) {
	delete cp; // 이전 객체가 있으면 삭제

	char ch;
	is >> ch; // gkrtod wjdqhdml dbgud vkdkr 

	if (ch == 'U') cp = new Core(is);
	else cp = new Grad(is);

	return is;
}
Student_info::Student_info(const Student_info& s) : cp(0) {
	if (s.cp) cp = s.cp->clone();
}
Student_info& Student_info::operator=(const Student_info& s) {
	if (&s != this) {
		delete cp;

		if (s.cp) cp = s.cp->clone();
		else cp = 0;
	}
	return *this;
}