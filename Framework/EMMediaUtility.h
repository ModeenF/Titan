#ifndef __EM_MEDIA_UTILITY
#define __EM_MEDIA_UTILITY

#include "EMGlobals.h"
#include "EMMediaGlobals.h"

class EMMediaFormat;

class __declspec(dllexport) EMMediaUtility
{
public:

	virtual int64 BytesPerFrame(const EMMediaFormat* p_opFormat) = 0;
	virtual int64 BytesToFrames(int64 p_vBytes, const EMMediaFormat* p_opFormat) = 0;
	virtual float FramesPerSecond(const EMMediaFormat* p_opFormat) = 0;
	virtual int64 FramesToBytes(int64 p_vFrames, const EMMediaFormat* p_opFormat) = 0;
	virtual int64 FramesToTime(int64 p_vFrames, const EMMediaFormat* p_opFormat) = 0;
	virtual int64 FramesPerBuffer(const EMMediaFormat* p_opFormat) = 0;
//	virtual int64 FramesInBuffer(void* p_opBuffer, const EMMediaFormat* p_opFormat, EMMediaType p_eReturnType) = 0;
	virtual int64 TimeToFrames(int64 p_vTime, const EMMediaFormat* p_opFormat) = 0;
//	virtual BMediaRoster* GetRosterE() = 0;
//	virtual void DisplayBuffer(BBuffer* opBuffer) = 0;
	virtual int64 FindMaxNum(signed short* array, int64 length, int64 num) = 0;

	virtual string ParseFullPath(string p_vpFileName, uint32 p_vDirectoryID) = 0;
	virtual string GetFileName(string p_vpFullPath) = 0;
	virtual string GetPathName(string p_vpFullPath) = 0;
	virtual string GetStringAfterLast(string p_vpSourceString, char p_vDelimiter) = 0;
	virtual string GetStringBeforeLast(string p_vpSourceString, char p_vDelimiter) = 0;
	virtual string MakePeaksFileName(string p_vpSourceFileName) = 0;
	virtual string MakeExtractFileName(string p_vpSourceFileName) = 0;
	virtual string MakeConvertFileName(string p_vpSourceFileName) = 0;
	virtual string MakeRenderFileName(uint32 p_vSequenceNumber) = 0;
	virtual string MakeAudioRecordingFileName(uint32 p_vSequenceNumber, int32 p_vUniqueID) = 0;
	virtual string MakeVideoRecordingFileName(uint32 p_vSequenceNumber, int32 p_vUniqueID) = 0;

	virtual EMMediaFormat* GetSystemAudioFormat() = 0;
	virtual EMMediaFormat* GetSystemVideoFormat() = 0;

protected:
	EMMediaUtility();
	~EMMediaUtility();
	EMMediaUtility* m_opInstance;
};

extern "C" EMMediaUtility*	gMediaUtility;

#endif
