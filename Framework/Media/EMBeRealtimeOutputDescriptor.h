// created from inference by looncraz
#ifndef _EM_BE_REALTIME_OUTPUT_DESCRIPTOR_H
#define _EM_BE_REALTIME_OUTPUT_DESCRIPTOR_H

#include "EMGlobals.h"
#include "EMRealtimeOutputDescriptor.h"


class EMBeRealtimeOutputDescriptor : public EMRealtimeOutputDescriptor {
public:
							EMBeRealtimeOutputDescriptor(EMMediaType);
	virtual					~EMBeRealtimeOutputDescriptor();

	virtual EMMediaDataBuffer*
							ProcessBufferE(list<EMMediaDataBuffer*>*);

	virtual bool			PrepareToPlayE();

	virtual void 			StartE();
	virtual void 			StopE();

	virtual bool 			ClearData();

	virtual bool 			SaveData(EMProjectDataSaver*);
	virtual bool 			LoadData(EMProjectDataLoader*);

	virtual	bool			RegisterAsClockMaster();
	virtual	bool 			UnregisterAsClockMaster();


};

#endif

