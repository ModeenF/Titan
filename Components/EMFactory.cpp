#include "EMFactory.h"

#include "EMWindow.h"

#include "EMBeFactory.h"

EMFactory* EMFactory::m_opInstance = NULL;

EMFactory::EMFactory()
{
}

EMFactory::~EMFactory()
{
}

EMFactory* EMFactory::Instance()
{
	if(m_opInstance != NULL)
		return m_opInstance;
	m_opInstance = new EMBeFactory();
	return m_opInstance;
}
