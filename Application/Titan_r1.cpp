/*******************************************************
* Creator: Martin Rudefelt
* Portability: non-native
*-------------------------------------------------------
* Contains lots of native code
*******************************************************/

#include <stdio.h>

#include "EMGlobals.h"

#include "Titan_r1.h"

#include "EMApplication.h"
#include "EMExceptionHandler.h"

#include "RapidDebug.h"

FILE* _ddfl = fopen("/boot/appserver-debug.txt", "w");

Titan_r1::Titan_r1() :
BApplication("application/x-vnd.Titan")
{
}

Titan_r1::~Titan_r1()
{
}

void Titan_r1::ReadyToRun()
{
	// Redirect bad_alloc exception handling
	set_new_handler(&(EMExceptionHandler::NewHandler));

	m_oInit.SetUpSystem();
}

int main()
{
	Titan_r1* opTitan = EM_new Titan_r1();
	try
	{
		opTitan -> Run();
	}
	catch(bad_alloc)
	{
		// Do stuff
		ERROR("bad_alloc!\n");

	}
	catch(...)
	{
		// Do stuff
		ERROR("uncaught exception!\n");
	}
	delete opTitan;
}

