/*******************************************************
* Creator: Martin Rudefelt
* Portability: native
*-------------------------------------------------------
* Contains some native code
*******************************************************/

#include "EMGlobals.h"

#ifndef __TITAN_R1
#define __TITAN_R1

#include "ApplicationInit.h"

#include <Application.h>

class Titan_r1 : public BApplication
{
public:
	Titan_r1();
	virtual ~Titan_r1();
	void ReadyToRun();

private:
	ApplicationInit m_oInit;
};

#endif

