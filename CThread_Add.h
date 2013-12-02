#ifndef CTHREAD_ADD_H
#define CTHREAD_ADD_H

//standard includes
#include <iostream>

//3rd party library includes

//my includes
#include "CThread.h"

class CThread_Add:public CThread {
// parent must be marked public so that the static stays public!

	public:
		CThread_Add();
		~CThread_Add();	
		
	private:
		int execute(); // type and arguments MUST MATCH the parent's virtual
		
		int workingInt; // workingData becomes this for this type of thread
};

#endif //CTHREAD_ADD_H
