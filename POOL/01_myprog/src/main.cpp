#include "../../00_lib/libBaseType/CObject.h"
#include "CStudent.h"

using namespace ACES;
using namespace std;

int main() {
	// Creating object
	CObject o1;

	// who are you ? identity
	cout << "I am " << o1.to_string() << endl;

	// assign identity
	o1.string_to("foo");

	// who are you ? identity
	cout << "I am " << o1.to_string() << endl;

	// << operator-based display myself
	cout << o1 << endl;

	// copy
	CObject o2 = o1;
	if( o1.is_kind_of("CObject") )
		cout << "I am one of CObject" << endl;

	// access member
	string str = o2.get_cid();

	// creating student
	CStudent s1("2014222", "Jihun Kim");
	CStudent s2("2014222", "Daejin Park");

	// drived function from parent
	cout << s1.to_string() << endl;

	// improve myself
	cout << s1.to_string() << endl;

	// morphism
	CObject* os1 = &s1;  // available
	cout << os1->to_string() << endl;
	if( os1->is_kind_of("CStudent") )
		cout << "I am one of CStudent" << endl;

	// operator abstraction
	if( s1 == s2 )
		cout << "tow student id are same" << endl;

	cout << s1 << endl;
	// output : I am I am .....
	// 상속 및 오버라이딩 생각 

	return 0;
}
