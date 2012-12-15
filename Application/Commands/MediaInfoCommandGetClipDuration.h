/*******************************************************
* Creator: Richard Kronfält
* Portability: non-native
*-------------------------------------------------------
* 
*******************************************************/

#include "EMGlobals.h"
#include "EMMediaGlobals.h"

#ifndef __MEDIA_INFO_COMMAND_GET_CLIP_DURATION
#define __MEDIA_INFO_COMMAND_GET_CLIP_DURATION

#include "EMCommand.h"

class MediaInfoCommandGetClipDuration : public EMCommand
{
public:
	MediaInfoCommandGetClipDuration();
	void ExecuteE() {};
	void* ExecuteE(void* p_upMediaClipID, void*, void*);
	bool RequiresParameters();
	bool IsUndoable();

private:
	int64 m_vReturnValue;

};

#endif
