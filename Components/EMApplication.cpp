#include "EMApplication.h"


EMApplication* EMApplication::m_opInstance = NULL;

#ifdef PLATFORM_BEOS
#include <Application.h>
#endif

EMApplication::EMApplication()
{
}

EMApplication::~EMApplication()
{
}

const char* EMApplication::GetApplicationVersionNumber()
{
	return EM_APPLICATION_VERSION_NUMBER;
}

EMApplication* EMApplication::Instance()
{
	if(m_opInstance == NULL)
		m_opInstance = EM_new EMApplication();

	return m_opInstance;
}

void EMApplication::InitiateQuitApplication()
{
}



