#include <iostream>
#include "Critical.h"

using namespace std;
using namespace ACES;

CriticalSectionObject::CriticalSectionObject() {

	cout << "Creating CriticalSectionObject ..." << endl;

}


CriticalSectionObject::~CriticalSectionObject() {

	cout << "Deleting CriticalSectionObject ..." << endl;

}
