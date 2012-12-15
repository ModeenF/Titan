#include "EMDragDrop.h"


EMDragDrop* EMDragDrop::m_opInstance = NULL;

EMDragDrop::EMDragDrop()
{
}

EMDragDrop::~EMDragDrop()
{
}

EMDragDrop* EMDragDrop::Instance()
{
	if(m_opInstance == NULL)
	{
	}
	return m_opInstance;
}
