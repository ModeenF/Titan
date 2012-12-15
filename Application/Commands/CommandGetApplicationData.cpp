#include "CommandGetApplicationData.h"

#include "EMApplication.h"


CommandGetApplicationData::CommandGetApplicationData()
{
}

void* CommandGetApplicationData::ExecuteE(void* p_upParameter, void* p_upParameterTwo, void* p_upParameterThree)
{
	int32 vDataType = *(static_cast<uint32*>(p_upParameter));
eo << "CommandGetApplicationData: " << (int32) EMWinWindow::GetMainWindowHandle() << ", " << (int32) EMApplication::GetApplicationInstance() << ef;
	if(vDataType == 1)

	if(vDataType == 2)
		return EMApplication::GetApplicationInstance();

	return NULL;
}

bool CommandGetApplicationData::IsUndoable()
{
	return false;
}

bool CommandGetApplicationData::RequiresParameters()
{
	return true;
}
