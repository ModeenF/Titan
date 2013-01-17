#include "EMGlobals.h"

#include "EMImageFileInputDescriptor.h"
#include "EMMediaUtility.h"
#include "EMMediaDataBuffer.h"
#include "EMMediaFormat.h"
#include "EMReadFrameInterface.h"
#include "EMMediaEngineUIDs.h"
#include "EMScalingUtils.h"

EMImageFileInputDescriptor::EMImageFileInputDescriptor(string p_oFileName)
	:	EMFileInputDescriptor(p_oFileName, EM_TYPE_ANY_IMAGE),
	m_oFormat(EM_TYPE_ANY_IMAGE),
	m_oScaledFormat(EM_TYPE_ANY_IMAGE),
	m_vpOriginal(NULL),
	m_vpScaled(NULL),
	m_vSwapImage(false)
{
	m_vNumFrames = 1;
}

EMImageFileInputDescriptor::~EMImageFileInputDescriptor()
{
	delete m_vpOriginal;
	delete m_vpScaled;
}

EMMediaFormat* EMImageFileInputDescriptor::GetFormat()
{
	return &m_oFormat;
}

