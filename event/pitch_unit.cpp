//---------------------------------------------------------------------------
//--------------------------	pitch_unit.cpp	-----------------------
//---------------------------------------------------------------------------
#include "pitch_unit.h"
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma package(smart_init)
Pitch Pitch::operator+(Pitch &P2)
{
   return Pitch(Num + P2.Num, Oct + P2.Oct);
}

Pitch Pitch::operator-(Pitch &P2)
{
   return Pitch(Num - P2.Num, Oct - P2.Oct);
}

int Pitch::GetNum()
{
  return Num;
}

int Pitch::GetOct()
{
  return Oct;
}