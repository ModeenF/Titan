/*******************************************************
* Creator: Martin Johansson
*	Modified by looncraz
* Portability: Non-Native
*-------------------------------------------------------
*
*******************************************************/

#include "EMGlobals.h"

#ifndef __EM_IMAGE_FILE_INPUT_DESCRIPTOR
#define __EM_IMAGE_FILE_INPUT_DESCRIPTOR

#include "EMFileInputDescriptor.h"
#include "EMMediaFormat.h"
#include "EMScalingUtils.h"


class EMImageFileInputDescriptor : public EMFileInputDescriptor
{
public:
							EMImageFileInputDescriptor(string p_oFileName);
	virtual					~EMImageFileInputDescriptor();

			EMMediaFormat* 	GetFormat();

	virtual EMImageFileInputDescriptor* Clone() = 0;

	virtual	bool 			ReadFrames(EMMediaDataBuffer** primaryBuffer,
								EMMediaDataBuffer** secondaryBuffer,
								int64 mediaFramePosition,
								int64 offsetFrames,
								int64 & numRead, bool seeking = false) = 0;

	virtual	bool 			ReadFrames(EMMediaDataBuffer* primaryBuffer) = 0;

	virtual	bool 			SeekTo(int64 newMediaFrame) = 0;
	virtual	bool 			SeekAndDisplay(int64 newMediaFrame) = 0;

protected:
			EMMediaFormat 	m_oFormat;
			EMMediaFormat 	m_oScaledFormat;
			unsigned char* 	m_vpOriginal;
			unsigned char* 	m_vpScaled;

			bool 			m_vSwapImage;

protected:
			EMScalingUtils	m_oScale;
};

#endif

