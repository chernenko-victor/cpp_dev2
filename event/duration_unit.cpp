//---------------------------------------------------------------------------
//--------------------------	duration_unit.cpp	-----------------------
//---------------------------------------------------------------------------
#include "duration_unit.h"
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma package(smart_init)
Duration Duration::operator+(Duration &P2)
{
   return Duration(Num + P2.Num, Oct + P2.Oct);
}

Duration Duration::operator-(Duration &P2)
{
   return Duration(Num - P2.Num, Oct - P2.Oct);
}

int Duration::GetNum()
{
  return Num;
}

int Duration::GetOct()
{
  return Oct;
}	
