#include "test.h"
#include <iostream>

using namespace std;

int main(){

	myObject o1;

	cout << o1.public_int << endl;
//	cout << o1.private_int << endl;
//	cout << o1.protected_int << endl;
	o1.printPrivate();

	childObject c1;

	c1.printPrivate();
	c1.printProtected();

	c1.printParentProtected();

	return 0;

}
