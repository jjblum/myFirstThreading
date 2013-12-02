#include "CThread_Add.h"
#include <iostream>

using namespace std;

CThread_Add::CThread_Add() {
	// don't need to iterate threadCount because the parent class takes care of that
}

CThread_Add::~CThread_Add() {
}

int CThread_Add::execute() {

	cout << "\nCThread_Add.execute() is running now.\n" << endl;
	
	workingInt = *(static_cast<int*>(workingData)); // convert workingData to workingInt
	
	int threadIterations = 0;
	do {
		threadIterations++;
		//cout << " *** thread has iterated " << threadIterations << " times." << endl;
		workingInt += 1;
		workingData = static_cast<void*>(&workingInt); // convert workingInt to workingData
		//remember that update() uses workingData, so it must be immediately updated by recasting workingInt. Otherwise the update() function will not work.
		usleep(5000);
	} while (stopped == false);	

	return 1;
}
