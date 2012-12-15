#include "EMMediaSystemInspector.h"

#include "EMWinMediaSystemInspector.h"
#include "EMBeMediaSystemInspector.h"
#include "EMGlobals.h"

EMMediaSystemInspector* EMMediaSystemInspector::m_opInstance = NULL;

void EMMediaSystemInspector::Create()
{
	if(m_opInstance == NULL)
		m_opInstance = EM_new EMBeMediaSystemInspector();
}

EMMediaSystemInspector* EMMediaSystemInspector::GetInstance()
{
	if(m_opInstance == NULL)
		EMDebugger("ERROR! Can't get system inspector when it's not created!");
	return m_opInstance;
}

void EMMediaSystemInspector::DeleteAndResetInstance()
{
	delete m_opInstance;
	m_opInstance = NULL;
}

EMMediaSystemInspector::EMMediaSystemInspector()
{
}

EMMediaSystemInspector::~EMMediaSystemInspector()
{
}
