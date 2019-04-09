//---------------------------------------------------------------------------
//--------------------------	inport.h	-----------------------
//---------------------------------------------------------------------------

#ifndef InportH
#define InportH
//---------------------------------------------------------------------------

#include <iostream>
#include <stdio.h>
#include "buffer.h"
#include "timer.h"

//WRONG!!!
//Inport receives TimerCalling() from class Proto object. 
//Inport from its TimerCalling() requests Get() method from class Proto object to read data (hich has type T) from its buffer
/*
lol deadlock!

Inport* inpOne<int, Outport>;
Outport* oupOne<int, Inport>;
oupOne = new Outport<int, Inport>(inpOne); ???
Outport must send data to Inport, Inport must not call any method from Outport
*/

//RIGHT!!!
//Outport's timer call TimerCalling() from self. 
//Outport's TimerCalling() read data (which has type T) from its buffer bfOutData and write it to Inport buffer, Inport must have got Put(T*) method

//WRONG!!!
//Any Dev read data (which has type T) from Inport's buffer, so Inport must have got void Get(T* DataChunckOut) method
//RIGHT!!!
//Inport by its timer write chuncks of data to Dev which connected to Inport's "output" (calling Dev->Put(T*)), 
//so all dev must have got int Put(T*) method
/*
how we can create an Dev?
Proto* Dev1 = new Proto(); //it's an "empty" Dev
Inport* inpOne<int, Proto33>;

Dev1 = new Proto33();
inpOne = new inpOne<int, Proto33>();
*/

/*
typedef UID int;

//lets create Sum proto 
class Cell<T>
{
	Cell();
	T Val;
	Put(T* ValN)
	{
		Val = ValN;
	}
	T Get()
	{
		retrun Val;
	}
};

class Sum<T, Proto>
{
		Sum(Proto* DevToOutN);
		int Put(T*, UID PortId);
		
	private:
		Proto* DevToOut;
		map<UID, Inport*>* InMap;
		map<UID, Outport*>* OutMap;
		Inport* inp1<T, cell<T>>, inp2<T, Sum>;
		Outport* oup1<T, Proto>;		
		T* Res;
};

Sum::Sum(Proto* DevToOutN)
{
	DevToOutN = DevToOutN;
	Cell* c1<T>;
	inp1 = new Inport<T, cell<T>>(c1);
	inp2 = new Inport<T, Sum>(this);
	oupOne = new Outport<int, Inport>(DevToOut);
	InMap->Insert(1, inp1);
	InMap->Insert(2, inp2);
	OutMap->Insert(1, oup1);
};

int Sum::Put(T* ValN, UID PortId = 2)
{
	if(PortId == 2)
	{
		*Res = *ValN * c1->Get();
		oupOne->Put(Res);
	}
	elseif(PortId == 1)
	{
		c1->Put(ValN);
	}
}

class Some
{
	private
		Outport* oup1<int, Proto>;
		Outport* oup2<int, Proto>;
		Sum* sum1<int, Outport>, sum2<int, Outport>;
};

Some::Process()
{
	int *a, *b, *c, *d, t, x, y, z;
	t = 1 , x = 10, y = 100, z = 1000;
	a = &t, b = &x, c = &y, d = *z;
	sum1->Put(a, 1);
	sum1->Put(b);
	sum2->Put(c, 1);
	sum2->Put(d);
};

*/
template <class T, class Dev> //T - type of data from Inport class
class Inport
{
	public:
		Inport(Dev* OutDevN, double dFrqTimerInnerN); // in Proto class must be public method T Get() to get values e.g. from buffer???
		int TimerCalling(void); 
		int Put(T* NewInputDataChunk);
		
	private:
		Buffer<T>* bfInternal;
		Timer<Inport>* tInternal;
		double dFrqTimerInner;
		Dev* OutDev;
		T* DataChunckOut;
};

template <class T, class Dev> 
Inport<T, Dev>::Inport(Dev* OutDevN, double dFrqTimerInnerN) 
{ 
	OutDev = OutDevN;
	bfInternal = new Buffer<T>();
	tInternal = new Timer<Inport>(this);
	tInternal->SetFrq(dFrqTimerInner);
	DataChunckOut = NULL;
	return;
}

template <class T, class Dev> 
int Inport<T, Dev>::TimerCalling(void) 
{ 
	bfInternal->Get(DataChunckOut);
	OutDev->Put(DataChunckOut);
	return 0;
}

template <class T, class Dev> 
int Inport<T, Dev>::Put(T* NewInputDataChunk)
{ 
	bfInternal->Put(*NewInputDataChunk);
	return 0;
}

/*
template <class T> 
T& Inport<T>::PutGet(void)
{ 
	bfInternal->Get();
	return 0;
}
*/
#endif