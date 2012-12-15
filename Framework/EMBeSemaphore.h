/*******************************************************
* Creator: Richard Kronfält
* Component: none
* Portability: native
*-------------------------------------------------------
*
*******************************************************/

#include "EMGlobals.h"

#ifndef __EM_BE_SEMAPHORE
#define __EM_BE_SEMAPHORE

#include "EMSemaphore.h"

#include <string> // Debug

#include <OS.h>

class EMBeSemaphore : public EMSemaphore
{
public:
						EMBeSemaphore(char* p_vName);
						~EMBeSemaphore();

		bool 			Acquire();
		bool			NonBlockingAcquire();

		void 			Release();

		string			GetSemaphoreName();

private:
	sem_id m_vSemaphore;
	string m_oSemaphoreName; // Debug
};

#endif
