#include "MediaCommandSetRenderToDiskOutputFileName.h"

#include "EMMediaEngine.h"
#include "EMMediaProject.h"

MediaCommandSetRenderToDiskOutputFileName::MediaCommandSetRenderToDiskOutputFileName()
{
}

void* MediaCommandSetRenderToDiskOutputFileName::ExecuteE(void* p_vName, void*, void*)
{
	EMWinMediaSingletonMuxer::Instance() -> SetRenderName(static_cast<char*>(p_vName));
	EMWinAudioDiskWriter::Instance() -> SetRenderName(static_cast<char*>(p_vName));
	EMWinQuickTimeWriterSuper::Instance() -> SetRenderName(static_cast<char*>(p_vName));

	EMMediaEngine::Instance() -> GetMediaProject() -> SetDirty(true);
	return NULL;
}

bool MediaCommandSetRenderToDiskOutputFileName::RequiresParameters()
{
	return true;
}

bool MediaCommandSetRenderToDiskOutputFileName::IsUndoable()
{
	return false;
}
