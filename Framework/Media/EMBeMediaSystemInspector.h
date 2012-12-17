/*******************************************************
* Creator: Richard Kronfalt
* Portability: Native
*-------------------------------------------------------
*
*******************************************************/

#include "EMGlobals.h"


#ifndef __EM_BE_MEDIA_SYSTEM_INSPECTOR
#define __EM_BE_MEDIA_SYSTEM_INSPECTOR

#include "EMMediaGlobals.h"
#include "EMRealtimeInputDescriptor.h"
#include "EMBeRealtimeAudioInputDescriptor.h"
#include "EMBeRealtimeVideoInputDescriptor.h"
#include "EMRealtimeOutputDescriptor.h"

#include "EMMediaSystemInspector.h"

#include "EMBeRealtimeAudioOutputDescriptor.h"
#include "EMBeRealtimeVideoOutputDescriptor.h"

#include <list>

class BMediaRoster;
class EMBeVideoConsumerNode;
class EMBeMediaRenderingNode;

struct Connection
{
	media_node producer, consumer;
	media_source source;
	media_destination destination;
	media_format format;
};

typedef list<EMRealtimeInputDescriptor*>	EMRIDList;
typedef list<EMRealtimeOutputDescriptor*>	EMRODList;


class EMBeMediaSystemInspector : public EMMediaSystemInspector
{

public:
						~EMBeMediaSystemInspector();

			list<EMCodecFormat*>* GetCodecs();

			EMRIDList*		GetRealtimeAudioInputs();
			EMRIDList*		GetRealtimeVideoInputs();

			EMRODList* 		GetRealtimeAudioOutputs();
			EMRODList* 		GetRealtimeVideoOutputs();

			void 			InspectCodecs();

protected:
							EMBeMediaSystemInspector();
	friend	class			EMMediaSystemInspector;

private:
			EMRIDList* 		GetInputs(EMMediaType p_eType);
			EMRODList* 		GetOutputs(EMMediaType p_eType);

			BMediaRoster* 	m_opRoster;
			int32			m_vID;
			EMBeVideoConsumerNode*
							m_opConsumer;

			Connection		mConnection;

			list<EMCodecFormat*>
							m_oFormats;

			EMBeMediaRenderingNode*
							m_opRenderNode;
};

#endif

