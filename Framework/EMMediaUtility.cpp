#include "EMMediaUtility.h"

#include "EMGlobals.h"
#include "Media/EMMediaFormat.h"

#include "Media/EMBeMediaUtility.h"

EMMediaUtility* EMMediaUtility::m_opInstance = NULL;

EMMediaUtility* EMMediaUtility::Instance()
{
	if(m_opInstance == NULL)
		m_opInstance = new EMBeMediaUtility();

	return m_opInstance;
}

void EMMediaUtility::Delete()
{
	if(EMMediaUtility::m_opInstance != NULL)
		delete EMMediaUtility::m_opInstance;

	EMMediaUtility::m_opInstance = NULL;
}

EMMediaUtility::EMMediaUtility()
{
}

EMMediaUtility::~EMMediaUtility()
{
}
