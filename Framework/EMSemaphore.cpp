#include "EMGlobals.h"
#include "EMSemaphore.h"

#include "EMBeSemaphore.h"

EMSemaphore::EMSemaphore()
{
}

EMSemaphore::~EMSemaphore()
{
}

EMSemaphore* EMSemaphore::CreateEMSemaphore()
{
	return EM_new EMBeSemaphore("EMBeSemaphore");
	return 0;
}

EMSemaphore* EMSemaphore::CreateEMSemaphore(const char* p_vName, uint32 p_vInitialCount, uint32 p_vMaxCount)
{
	return EM_new EMBeSemaphore(p_vName);
	return 0;
}

