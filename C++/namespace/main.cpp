#include "test.h"
#include <iostream>

using namespace std;

void printNameSpace(){
	cout << "I'm main space!" << endl;
}

int main(){
	
	ACES::printNameSpace();
	mySpace::printNameSpace();
	printNameSpace();

	return 0;
}
