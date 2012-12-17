#include "EMGlobals.h"

#ifndef __EM_BE_ANALOG_REALTIME_VIDEO_INPUT_DESCRIPTOR
#define __EM_BE_ANALOG_REALTIME_VIDEO_INPUT_DESCRIPTOR

// Attempt to re-create missing (and unpublished) EMBeRealtimeInputDescriptor
// IF NEEDED

class EMBeRealtimeInputDescriptor {
public:
						EMBeRealtimeInputDescriptor(media_output*,
							uint32 type);
	virtual				~EMBeRealtimeInputDescriptor();



};

#endif
