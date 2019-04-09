//---------------------------------------------------------------------------
//--------------------------	duration_unit.h	-----------------------
//---------------------------------------------------------------------------

#ifndef DurationUnitH
#define DurationUnitH
//---------------------------------------------------------------------------
class Duration
{
  public:
	Duration(int N, int O) : Num(N), Oct(O) {}
	Duration operator+(Duration &P2);
	Duration operator-(Duration &P2);
	int GetNum();
	int GetOct();
  private:
	int Num, Oct;
};
#endif
