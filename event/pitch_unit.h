//---------------------------------------------------------------------------
//--------------------------	pitch_unit.h	-----------------------
//---------------------------------------------------------------------------

#ifndef PitchUnitH
#define PitchUnitH
//---------------------------------------------------------------------------
class Pitch
{
  public:
	Pitch(int N, int O) : Num(N), Oct(O) {}
	Pitch operator+(Pitch &P2);
	Pitch operator-(Pitch &P2);
	int GetNum();
	int GetOct();
  private:
	int Num, Oct;
};
#endif
