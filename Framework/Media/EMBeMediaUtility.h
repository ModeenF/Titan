/*******************************************************
* Creator: Richard Kronfalt
* Portability: Native
*-------------------------------------------------------
*
*******************************************************/

#include "EMGlobals.h"

#ifndef __EM_BE_MEDIA_UTILITY
#define __EM_BE_MEDIA_UTILITY

#include "EMMediaUtility.h"
#include "EMMediaGlobals.h"
#include "EMMediaFormat.h"

#include <MediaKit.h>
#include <list>
#include <map>

class BMediaRoster;

class EMBeMediaUtility : public EMMediaUtility
{
public:
	~EMBeMediaUtility();

	int64 BytesPerFrame(const EMMediaFormat* p_opFormat);
	int64 BytesToFrames(int64 p_vBytes, const EMMediaFormat* p_opFormat);
	float FramesPerSecond(const EMMediaFormat* p_opFormat);
	int64 FramesToBytes(int64 p_vFrames, const EMMediaFormat* p_opFormat);
	int64 FramesToTime(int64 p_vFrames, const EMMediaFormat* p_opFormat);
	int64 FramesPerBuffer(const EMMediaFormat* p_opFormat);
	int64 FramesInBuffer(BBuffer* p_opBuffer, const EMMediaFormat* p_opFormat, EMMediaType p_eReturnType);
	int64 TimeToFrames(int64 p_vTime, const EMMediaFormat* p_opFormat);
	BMediaRoster* GetRosterE();
	void DisplayBuffer(BBuffer* opBuffer);
	int64 FindMaxNum(signed short* array, int64 length, int64 num);

	string ParseFullPath(string p_oFileName, uint32 p_vDirectoryID);
	string GetFileName(string p_oFullPath);
	string GetPathName(string p_oFullPath);
	string GetStringAfterLast(string p_oSourceString, char p_vDelimiter);
	string GetStringBeforeLast(string p_oSourceString, char p_vDelimiter);
	string MakePeaksFileName(string p_oSourceFileName);
	string MakeExtractFileName(string p_oSourceFileName);
	string MakeConvertFileName(string p_oSourceFileName);
	string MakeRenderFileName(uint32 p_vSequenceNumber);
	string MakeAudioRecordingFileName(uint32 p_vSequenceNumber, int32 p_vUniqueID);
	string MakeVideoRecordingFileName(uint32 p_vSequenceNumber, int32 p_vUniqueID);

	EMMediaFormat* GetSystemAudioFormat();
	EMMediaFormat* GetSystemVideoFormat();

	void ClearData();

	//For debugging
	list<char*>* classes;
	list<int64>* num;
	list<map<int64, string> >* instances;
	void			push(const void* ptr, char* name);
	void 			pop(char* name);
	void show();

	EMBeMediaUtility();

protected:
	sem_id vSem;
	EMMediaFormat* m_opSystemAudioFormat;
	EMMediaFormat* m_opSystemVideoFormat;
};

extern "C" EMBeMediaUtility* gBeMediaUtility;

#endif
