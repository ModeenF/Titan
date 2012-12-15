#include "EMMessageBox.h"

#include "EMWindow.h"

EMMessageBox* EMMessageBox::m_opInstance = NULL;

EMMessageBox::EMMessageBox()
{
}

EMMessageBox* EMMessageBox::Instance()
{
	if(m_opInstance != NULL)
		return m_opInstance;

	return m_opInstance;
}
