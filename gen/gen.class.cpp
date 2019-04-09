#include <iostream>
#include "gen.class.h"

//---------------------------------------------------------------------------
ScoreGen1::ScoreGen1()
{
  NoteOn = 0;
  x = 1;
  iToTime = &x;
  //tInt = new Timer<int>(iToTime);
  Dev1 = new Proto<int>();
  dFrqTimerInner = 10.0;
  inpTrail = new Inport<int, Proto<int>>(Dev1, dFrqTimerInner);
}
//---------------------------------------------------------------------------
void ScoreGen1::ShowNoteOn(void)
{
  std::cout << "ScoreGen1->NoteOn = " << NoteOn << "\n";
  //tInt->On();
}
//---------------------------------------------------------------------------
int ScoreGen1::TimerCalling(void)
{
  std::cout << "ScoreGen1->TimerCalling :: x = " << ++x << "\n";
  inpTrail->TimerCalling();
  return 0;
}


//---------------------------------------------------------------------------
ScoreGen2::ScoreGen2()
{
  NoteOn = 0;
  NoteOff = 1;
}
//---------------------------------------------------------------------------
void ScoreGen2::ShowNoteOn(void)
{
  std::cout << "ScoreGen2->NoteOn = " << NoteOn << "\n";
}
//---------------------------------------------------------------------------
void ScoreGen2::ShowNoteOff(void)
{
  std::cout << "ScoreGen2->NoteOff = " << NoteOff << "\n";
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
int ScoreGen2::TimerCalling(void)
{
  std::cout << "ScoreGen2->TimerCalling\n";
  return 0;
}