#include "CThread.h"
#include <iostream>

using namespace std;

extern "C" {
	int startThread(void* arg) { // this friend allows me to treat any thread subclass the same
		CThread* genericThread = static_cast<CThread*>(arg);
		return genericThread->execute();		 
	}
}

CThread::CThread() {
	threadCount++;
	updateCount = 0;
	stopped = false;
}

CThread::~CThread(){
	//cout << "\n~CThread() is running now.\n" << endl;
	//cout << "	is workingData NULL? " << (workingData==NULL) << endl;
	//free(workingData); // --> causing *** glibc detected *** invalid pointer
}

int CThread::execute() { //virtual
	cout << "\nCThread.execute() is running now.\n" << endl;
	return 0;
}


int CThread::start(void* inputData,uint8_t size) {
	//cout << "\nCThread.start() is running now.\n" << endl;	
	workingSize = size;
	workingData = malloc(workingSize); // need this or workingData is NULL and that blows up memcpy
		
	// memcpy the working data
	/*
	// common segmentation fault is the pointers being NULL
	cout << "	is workingData NULL? " << (workingData==NULL) << endl;
	cout << "	is inputData NULL? " << (inputData==NULL) << endl;
	*/
	memcpy(workingData,inputData,workingSize);

	//cout << "	memcpy successful" << endl;
	
	thread = SDL_CreateThread(startThread,static_cast<void*>(this));
	//looks like SDL_CreateThread requires a function(void* arg) as input as its first argument:
	//extern DECLSPEC SDL_Thread * SDLCALL SDL_CreateThread(int (SDLCALL *fn)(void *), void *data);	
	return 0;
}

void CThread::stop() {
	stopped = true;
}

void CThread::update(void* outputData) {
	
	/*
	updateCount++;
	cout << "\nCThread.update() is running now." << endl;
	cout << "	update() has been called " << updateCount << " times." << endl;
	cout << "	outputData = " << *(static_cast<int*>(outputData)) << endl;
	cout << "	workingData = " << *(static_cast<int*>(workingData)) << endl;
	*/
	
	memcpy(outputData,workingData,workingSize);
	//cout << "	memcpy successful" << endl;
	
}

int CThread::threadCount = 0;
