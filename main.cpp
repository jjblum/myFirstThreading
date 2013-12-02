//standard includes
#include <iostream>

//3rd party library includes

//my includes
#include "CThread_Add.h"

//any "using" statements
using namespace std;

//any global variables

int main(int argc, char* argv[]) {

	CThread_Add* CThread_Add_ptr;
	CThread_Add_ptr = new CThread_Add;
	
	/*
	cout << "\n---------------------------------------\n" << endl;
	cout << "There are " << CThread_Add_ptr->threadCount << " threads." << endl;
	cout << "\n---------------------------------------\n" << endl;	
	*/
	
	int* threadInt; //thread will operate on this
	int* mainInt; // main() will operate on this
	threadInt = new int;
	mainInt = new int;
	*threadInt = 0; // initial value before threads act
	*mainInt = 0;
	
	
	cout << "\n---------------------------------------\n" << endl;
	cout << "Thread's initial value is = " << *threadInt << endl;
	cout << "main() initial value is = " << *mainInt << endl;
	cout << "\n---------------------------------------\n" << endl;	
	
	
	CThread_Add_ptr->start(threadInt,sizeof(int));
	usleep(1000);
	
	for (int i = 0; i < 10; i++) {
		*mainInt += 1;		
		cout << "\nmain() current value is = " << *mainInt << endl;				
		usleep(100000); // the ratio of this number and the one in CThread_Add->execute() determine how many times the thread runs vs. this for-loop in main
		CThread_Add_ptr->update(threadInt);
		cout << "Thread's current value is = " << *threadInt << endl;		
	}
	
	CThread_Add_ptr->stop();
	CThread_Add_ptr->update(threadInt);		
	usleep(100000); // to make sure the thread's final value has enough time to compute
	
	
	cout << "\n---------------------------------------\n" << endl;
	cout << "Thread's final value is = " << *threadInt << endl;
	cout << "main() final value is = " << *mainInt << endl;	
	cout << "\n---------------------------------------\n" << endl;	
	
	
	delete CThread_Add_ptr;
	
	return 0;
}
