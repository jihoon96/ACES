#include "CStudent.h"

using namespace ACES;

string const CStudent::to_string() const {
	string me;
	me = "I am " + m_name;
	me += "(" ;
	me += m_id;
	me += ")";

	return me;
}
