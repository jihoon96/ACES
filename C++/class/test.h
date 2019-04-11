#include <iostream>

using namespace std;

class myObject{
	public:
		int public_int = 0;
		void printPrivate(){ cout << private_int << endl; }
		void printProtected(){ cout << protected_int << endl; }
	private:
		int private_int = 1;
	protected:
		int protected_int = 2;
};

class childObject : public myObject {
	public:
		void printParentProtected(){ cout << protected_int << endl; }
//		void printParentPrivate(){ cout << private_int << endl; }
	private:
	protected:
};
