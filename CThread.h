#ifndef CTHREAD_H
#define CTHREAD_H

#include "SDL/SDL_thread.h"

// friend function declarations before the class
extern "C" int startThread(void* arg);

class CThread {
	public:
		CThread();
		~CThread();
		friend int startThread(void* arg);
		int start(void* inputData, uint8_t size); //feeds startThread to SDL_CreateThread		
		void update(void* outputData); // output the current workingData
		void stop(); // sets stopped = true so that the thread stops looping
		
		bool stopped;
		void* workingData; // this is the thing that we copy to to start and copy from as output		
		
		static int threadCount;
		
	
	private:

		virtual int execute(); //execute() is virtual so that all thread subclasses can be used like the parent
	
		SDL_Thread* thread;
		uint8_t workingSize;
		int updateCount; // number of times update() is called
		
		

};


#endif //CTHREAD_H
