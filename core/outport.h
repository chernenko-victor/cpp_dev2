//---------------------------------------------------------------------------
//--------------------------	outport.h	-----------------------
//---------------------------------------------------------------------------

#ifndef OutportH
#define OutportH
//---------------------------------------------------------------------------

#include <iostream>
#include <stdio.h>
#include "buffer.h"
#include "timer.h"

//Outport's timer call TimerCalling() from self. 
//TimerCalling() read data (which has type T) from buffer bfOutData and write it to Inport buffer, Inport must have got Put(T*) method						
template <class T, class Proto> 
class Outport
{
	public:
		Outport(Proto* NewDevToSend);
		int TimerCalling(void);
		int Put(T* NewInputDataChunk);
	private:
		Proto* DevToSend;
		Buffer<T>* bfOutData;
		Timer<Proto>* tSendMsg;
		T DataChunk;
};

template <class T, class Proto> 
Outport<T, Proto>::Outport(Proto* NewDevToSend) 
{ 
	DevToSend = NewDevToSend;
	bfOutData = new Buffer<T>();
	tSendMsg = new Timer<Outport>(this);
	return;
}

template <class T, class Proto> 
int Outport<T, Proto>::TimerCalling(void) 
{
	DataChunk = bfOutData->Get();
	DevToSend->Put(&DataChunk);
	return 0;
}

template <class T, class Proto> 
int Outport<T, Proto>::Put(T* NewInputDataChunk)
{
	return bfOutData->Put(*NewInputDataChunk);
}
#endif