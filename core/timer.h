//---------------------------------------------------------------------------
//--------------------------	timer.h	-----------------------
//---------------------------------------------------------------------------

#ifndef TimerH
#define TimerH
//---------------------------------------------------------------------------

#include <iostream>
#include <stdio.h>
#include <time.h>

const int NUM_SECONDS = 3;
//---------------------------------------------------------------------------

template <class T>
class Timer
{
  public:
    Timer(T* NewObjToBeTrig) : ObjToBeTrig(NewObjToBeTrig) {};
    void On(); // переводит таймер в состояние работы
	void Off(); // останавливает
	void SetFrq(double dFrqNew);

  private:
    T* ObjToBeTrig;
    /*
	Когда работает, то один раз в период вызывает метод TimerCalling объекта ObjToBeTrig типа T, 
	возвращет 0 в случае удачи, в противном случае код ошибки
    */
    int iTrig; // 1 - таймер в состоянии работы, 0 – остановлен
	double dFrq; /* значение частоты таймера в герцах, <0 – (условно) однократное событие */
	double dGrain; /* значение частоты таймера в герцах, 0 – (условно) однократное событие */
};

template <class T> 
void Timer<T>::SetFrq(double dFrqNew) 
{ 
  dFrq = dFrqNew;
  dGrain = (1/dFrq) * (double)(CLOCKS_PER_SEC);
}

template <class T>
void Timer<T>::On() 
{ 
  iTrig = 1;
  int count = 1;

  double time_counter = 0;

  clock_t this_time = clock();
  clock_t last_time = this_time;

  //printf("Gran = %ld\n", NUM_SECONDS * CLOCKS_PER_SEC);
  //std::cout << "Gran = " << (NUM_SECONDS * CLOCKS_PER_SEC) << std::endl;
  std::cout << "Gran = " << dGrain << std::endl;
  
  ObjToBeTrig->TimerCalling();
  std::cout << "count = " << count << std::endl;
  count++;
  
  if(dFrq < 0.0)
  {
	  Off();
  }
  else
  {
	  while(true)
	  {
			this_time = clock();

			time_counter += (double)(this_time - last_time);

			last_time = this_time;

			//if(time_counter > (double)(NUM_SECONDS * CLOCKS_PER_SEC))
			if(time_counter > dGrain)
			{
				ObjToBeTrig->TimerCalling();
				//time_counter -= (double)(NUM_SECONDS * CLOCKS_PER_SEC);
				time_counter -= dGrain;
				//printf("%d\n", count);
				std::cout << "count = " << count << std::endl;
				count++;
			}

			//printf("DebugTime = %f\n", time_counter);
			//std::cout << "DebugTime = " << time_counter << std::endl;
			if(count>=5)
			{
				break;
			}
			if(iTrig==0)
			{
				break;
			}
	  }
  }
  return;
}

template <class T> 
void Timer<T>::Off() 
{ 
  iTrig = 0;
}
  
#endif