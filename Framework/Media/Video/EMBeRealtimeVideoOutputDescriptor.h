/*******************************************************
* Creator: Richard Kronfalt
* Portability: Native
*-------------------------------------------------------
*
*******************************************************/

#include "EMGlobals.h"

#ifdef PLATFORM_BEOS

#ifndef __EM_BE_REALTIME_VIDEO_OUTPUT_DESCRIPTOR
#define __EM_BE_REALTIME_VIDEO_OUTPUT_DESCRIPTOR

#include "EMBeRealtimeOutputDescriptor.h"
#include "EMMediaDataBuffer.h"
#include "EMListener.h"

#include <list>

class EMListenerRepository;
class EMProjectDataSaver;
class EMProjectDataLoader;

class EMBeRealtimeVideoOutputDescriptor : public EMBeRealtimeOutputDescriptor,
			public EMListener
{
public:
							EMBeRealtimeVideoOutputDescriptor(media_input*);
	virtual 				~EMBeRealtimeVideoOutputDescriptor();

			bool 			InitCheckE();

			bool			MessageReceived(EMListenerRepository* sender,
								uint32 message);

			bool 			PrepareToPlayE();

			EMMediaDataBuffer* ProcessBufferE(list<EMMediaDataBuffer*>*);
			EMMediaDataBuffer* ProcessBufferE(BObjectList<EMMediaDataBuffer>*);

			void 			StartE();
			void 			StopE();
			bool 			ClearData();

			bool 			SaveData(EMProjectDataSaver*);
			bool 			LoadData(EMProjectDataLoader*);

private:
			bool m_vAwaitingNewBufferFormat;
			bool m_ReadyForFormatChange;
			BBufferGroup* m_opBufferGroup;
			BBufferGroup* m_opBufferGroupRclm;
			BBuffer* m_opBuffer;
			BBufferProducer* m_opNode;
};

#endif

#endif
