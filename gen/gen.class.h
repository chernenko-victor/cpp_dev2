//---------------------------------------------------------------------------

#ifndef GenClassH
#define GenClassH
//---------------------------------------------------------------------------
#include "../core/timer.h"
#include "../core/proto.h"
#include "../core/inport.h"
#include "../core/outport.h"

//---------------------------------------------------------------------------

//Proto is universal global class -> GUID
//Dev is universal global object -> GUID

//each Proto has got inrpots and outports (from 0 to inf) -> local unic ID
//Proto has got subproto (from 0 to inf)  -> local unic ID
//Proto has got subproto's ins and outs connections. subproto1.out1 -> subproto3.in1; subproto3.out5 -> subproto4.in1; etc
//echo Proto has got ports to net data exchange
/*
Proto

subprotos table
UID				type		ref_to_subproto		net port
Pr1(partit)		internal
Pr3(partit)		internal
Pr3(in)			in
Pr5(in)			in
Pr5(out)		out
Pr6(out)		out
Pr7(out)		net in							net port1
Pr8(out)		net out							
...

connections table
UIDsrc			UIDoutport		UIDdest			UIDinport

global table
GUID			

*/

class ScoreGen1
{
	private:	// User declarations
		int NoteOn;
		int x;
		int* iToTime;
		//Timer<int, int>* tInt;
		Proto<int>* Dev1;
		double dFrqTimerInner;
	public:		// User declarations
		ScoreGen1();
		void ShowNoteOn(void);
		int TimerCalling(void);
		Inport<int, Proto<int>>* inpTrail;
};

class ScoreGen2
{
	private:	// User declarations
		int NoteOn, NoteOff;
	public:		// User declarations
		ScoreGen2();
		void ShowNoteOn(void);
		void ShowNoteOff(void);
		int TimerCalling(void);
};
//---------------------------------------------------------------------------
#endif