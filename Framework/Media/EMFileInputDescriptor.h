/*******************************************************
* Creator: Richard Kronfalt
* Portability: Native
*-------------------------------------------------------
*
*******************************************************/

#ifndef __EM_FILE_INPUT_DESCRIPTOR
#define __EM_FILE_INPUT_DESCRIPTOR

#include "EMInputDescriptor.h"

#include <string>

class EMMediaDataBuffer;
class EMMediaFormat;

class EMFileInputDescriptor : public EMInputDescriptor
{
public:
	virtual 				~EMFileInputDescriptor();

			string			GetFileName() const;
			int64 			GetNumFrames() const;

	virtual EMMediaFormat* 	GetFormat() = 0;

	virtual bool 			InitCheckE() = 0;

	virtual bool 			ReadFrames(EMMediaDataBuffer** primaryBuffer,
								EMMediaDataBuffer** secondaryBuffer,
								int64 mediaFramePosition,
								int64 offsetFrames,
								int64 & numRead, bool seeking = false) = 0;

	virtual bool 			SeekAndDisplay(int64 mediaFrame) = 0;

	virtual bool 			SeekTo(int64 mediaFrame) = 0;

			int32			GetMediaPoolEntryID() const;
			void			SetMediaPoolEntryID(int32 p_vEntryID);

	virtual bool Open();
	virtual bool Close();

protected:
							EMFileInputDescriptor(string file, EMMediaType);

		// inheriting objects will fill these out on Open();
			string 			m_oFileName;
			int64 			m_vNumFrames;

		//LOONTODO: how do we get our MediaPoolEntryID?
			int32			m_vMediaPoolEntryID;
};

#endif
