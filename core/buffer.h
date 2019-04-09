//---------------------------------------------------------------------------
//--------------------------	buffer.h	-----------------------
//---------------------------------------------------------------------------

#ifndef BufferH
#define BufferH
//---------------------------------------------------------------------------

#include <iostream>
#include <stdio.h>

//const int MAX_SIZE = 1024;
const int MAX_SIZE = 4;
//---------------------------------------------------------------------------

/*
Ѕуфер
 
Ћинейный участок пам€ти фиксированного размера (массив с Ђповоротомї вполне подойдет). 
≈сли с выхода считываетс€ медленнее, чем происходит обсчет, значени€ будут выдаватьс€ из буфера, если быстрее, то будет выдаватьс€ значение которое последнее в буфере.
≈сть указатель записи и указатель чтени€. 
”казатель записи указывает на позицию, в которую будет записано значение при следующем обсчете. ѕосле записи указатель передвигаетс€ на одну позицию вперед.  огда указатель доходит до конца буфера, он переходит на начало. 
”казатель чтени€ укзавает на позицию с которой будет считано значение при следующем оьращении, после обращени€ он переводитс€ на позицию вперед, если на ней не находитс€ указатель записи. ¬ противном случае указатель чтени€ остаетс€ на месте.
*/

/*
Buffer
 
A linear portion of memory of fixed size (an array with a "rotation" is quite suitable).
If the output is read slower than the count, the values will be output from the buffer, if faster, then the last value in the buffer will be output.
There is a record pointer and a read pointer.
The record pointer indicates the position to which the value will be written at the next count. After recording, the pointer moves one position forward. When the pointer reaches the end of the buffer, it goes to the beginning.
The read pointer points to the position from which the value is read the next time it is moved, after the call it is moved to the forward position, if there is no record pointer on it. Otherwise, the read pointer remains in place.
*/

template <class T>
class Buffer
{
public:
  Buffer();
  T Get();
  void Get(T* DataChunckOut);
  void Put(T);
private:
  T aCarry[MAX_SIZE];
  int iReadPointer;
  int iWritePointer;
};
//---------------------------------------------------------------------------

template <class T>
Buffer<T>::Buffer()
{
  iReadPointer = 0;
  iWritePointer = 0;
}
//---------------------------------------------------------------------------

template <class T>
T Buffer<T>::Get()
{
  T tCurrVal = aCarry[iReadPointer];
  std::cout << "iReadPointer = " << iReadPointer << std::endl;
  if((iReadPointer+1)!=iWritePointer)
  {
    if(iReadPointer<MAX_SIZE-1)
	{
	  iReadPointer++;
	}
	else
	{
	  iReadPointer = 0;
	}
  }
  std::cout << "iReadPointer Increment" << std::endl;
  std::cout << "iReadPointer = " << iReadPointer << std::endl;
  return tCurrVal;
}

//---------------------------------------------------------------------------
template <class T>
void Buffer<T>::Get(T* DataChunckOut)
{
  DataChunckOut = &(aCarry[iReadPointer]);
  std::cout << "iReadPointer = " << iReadPointer << std::endl;
  if((iReadPointer+1)!=iWritePointer)
  {
    if(iReadPointer<MAX_SIZE-1)
	{
	  iReadPointer++;
	}
	else
	{
	  iReadPointer = 0;
	}
  }
  std::cout << "iReadPointer Increment" << std::endl;
  std::cout << "iReadPointer = " << iReadPointer << std::endl;
  return;
}
//---------------------------------------------------------------------------

template <class T>
void Buffer<T>::Put(T NewVal)
{
  aCarry[iWritePointer] = NewVal;
  std::cout << "iWritePointer = " << iWritePointer << std::endl;
  if(iWritePointer<MAX_SIZE-1)
  {
    iWritePointer++;
  }
  else
  {
    iWritePointer = 0;
  }
  std::cout << "iWritePointer Increment" << std::endl;
  std::cout << "iWritePointer = " << iWritePointer << std::endl;
}
//---------------------------------------------------------------------------
#endif