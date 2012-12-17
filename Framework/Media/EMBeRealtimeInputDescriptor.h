// created from inference by looncraz
#ifndef _EM_BE_REALTIME_INPUT_DESCRIPTOR_H
#define _EM_BE_REALTIME_INPUT_DESCRIPTOR_H

#include "EMGlobals.h"
#include "EMRealtimeInputDescriptor.h"


class EMBeRealtimeInputDescriptor : public EMRealtimeInputDescriptor {
public:
							EMBeRealtimeInputDescriptor(EMMediaType);
	virtual					~EMBeRealtimeInputDescriptor();

	virtual bool 			InitCheckE();

	virtual bool 			PrepareToPlayE();

	virtual bool 			StartPreviewE();
	virtual bool 			StopPreviewE();

	virtual void 			StartE();
	virtual void 			StopE();

	virtual bool 			ClearData();

	virtual bool 			SaveData(EMProjectDataSaver*);
	virtual bool 			LoadData(EMProjectDataLoader*);

	virtual void 			SetArmed(bool);

};

#endif

