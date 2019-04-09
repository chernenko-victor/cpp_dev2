#include <iostream>
#include <thread>
#include <mutex>
#include "gen/gen.class.h"
#include "core/timer.h"
#include "core/buffer.h"
#include "core/inport.h"
#include "core/outport.h"

std::mutex g_display_mutex;

void thread_function3()
{
   double dFrqNeoromanticScore = 0.4;
	ScoreGen1* sg1Neoromantic = new ScoreGen1();
	Timer<ScoreGen1>* tNeoromanticScore;
	tNeoromanticScore = new Timer<ScoreGen1>(sg1Neoromantic);
	tNeoromanticScore->SetFrq(dFrqNeoromanticScore);
	
    g_display_mutex.lock();
	
    std::thread::id this_id = std::this_thread::get_id();
    std::cout << "My thread id is: " << this_id  << std::endl;
	
	tNeoromanticScore->On();
	
    g_display_mutex.unlock();
	return;
}

void thread_function()
{
    for(int i = 0; i < 5; i++);
        std::cout<<"thread function Executing"<<std::endl;
}

int main (int argc, char *argv[])
{
  ScoreGen1* sg1Neoromantic = new ScoreGen1();
  ScoreGen2* sg2Dodecaph = new ScoreGen2();
   
  //std::cout << "=== Dev2.4 started ===\n";
  
  sg1Neoromantic->ShowNoteOn();
  sg2Dodecaph->ShowNoteOff();
 
  //std::cout << "=== Dev2.4 finished ===\n";
/*  
  Buffer<int>* bfInt;
  bfInt = new Buffer<int>();
  bfInt->Put(11);
  std::cout << "bfInt Put 11" << std::endl;
  bfInt->Put(1122);
  std::cout << "bfInt Put 1122" << std::endl;
  
  std::cout << "bfInt = " << bfInt->Get() << std::endl;
  std::cout << "bfInt = " << bfInt->Get() << std::endl;
  std::cout << "bfInt = " << bfInt->Get() << std::endl;
  
  bfInt->Put(22);
  std::cout << "bfInt Put 22" << std::endl;
  bfInt->Put(2233);
  std::cout << "bfInt Put 2233" << std::endl;
  std::cout << "bfInt = " << bfInt->Get() << std::endl;
  
  std::cout << "bfInt = " << bfInt->Get() << std::endl;
  std::cout << "bfInt = " << bfInt->Get() << std::endl;
  std::cout << "bfInt = " << bfInt->Get() << std::endl;
  
  bfInt->Put(33);
  std::cout << "bfInt Put 22" << std::endl;
  bfInt->Put(3333);
  
  std::cout << "bfInt = " << bfInt->Get() << std::endl;
  std::cout << "bfInt = " << bfInt->Get() << std::endl;
  std::cout << "bfInt = " << bfInt->Get() << std::endl;
 */
  //int a = 135, *b;
  //b = &a;
  //std::cout << "a = " << a << "*b = " << *b << std::endl;
  
  double dFrqNeoromanticScore = 0.3;
  double dFrqDodecaphScore = -0.15;
  /*
  Timer<int>* tInt;
  tInt = new Timer<int>(b);
  tInt->SetFrq(dFrqNew);
  tInt->On();
  */
  Timer<ScoreGen1>* tNeoromanticScore;
  tNeoromanticScore = new Timer<ScoreGen1>(sg1Neoromantic);
  tNeoromanticScore->SetFrq(dFrqNeoromanticScore);
  tNeoromanticScore->On();
  
  Timer<ScoreGen2>* tDodecaphScore;
  tDodecaphScore = new Timer<ScoreGen2>(sg2Dodecaph);
  tDodecaphScore->SetFrq(dFrqDodecaphScore);
  tDodecaphScore->On();
  
  std::thread threadObj1(thread_function3);
  std::thread threadObj3(thread_function3);
  std::cout<<"Display From MainThread"<<std::endl;
  threadObj1.join();    
  threadObj3.join();    
  std::cout<<"Exit of Main function"<<std::endl;
}