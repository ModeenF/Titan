/*******************************************************
* Creator: Richard Kronfalt
* Portability: Non-Native
*-------------------------------------------------------
*
*******************************************************/

#include "EMGlobals.h"

#ifndef __EM_MEDIA_FILE_MANAGER
#define __EM_MEDIA_FILE_MANAGER

#include <string>

class EMMediaFormat;
class EMMediaFile;
class EMWaveFile;
class EMSemaphore;

class EMMediaFileManager
{
public:
	virtual 				~EMMediaFileManager();

	static	EMMediaFileManager* Instance();

	static	void 			Delete();

			int32		 	GetID() const;
	virtual int32 			GetFileTypeForE(const string* fileName) = 0;

	virtual string			CreatePeaksFileE(const string* fileName) = 0;
	virtual string 			ExtractAudioE(const string* fileName) = 0;
	virtual bool 			CheckFileForVideoFormat(const string* fileName) = 0;
	virtual bool 			FormatsMatch(const string* fileName,
								const EMMediaFormat*) = 0;

	virtual string 			ConvertAudio(const string* sourceFileName,
								const EMMediaFormat* targetFormat) = 0;

	virtual string 			CopyTo(const string* sourceFile,
								const string* targetDirectory) = 0;

	static	void			Lock();
	static	void 			Unlock();

protected:
							EMMediaFileManager();

private:
	static	EMMediaFileManager* m_opInstance;
			int32			m_vID;
	static 	EMSemaphore* 	m_opSemaphore;

};

#endif
