/*
	EMBeOutputNode.h

	Copyright 1999, Be Incorporated.   All Rights Reserved.
	This file may be used under the terms of the Be Sample Code License.

	TODO: the original form of this file indicates that this was not Be
	sample code, need to investigate why the above copyright notice is
	here... perhaps someone really screwed up the formatting?
*/

#include "EMGlobals.h"

#ifndef __EM_BE_OUTPUT_NODE
#define __EM_BE_OUTPUT_NODE

#include "EMListenerRepository.h"
#include "EMMediaFormat.h"

#include <media/BufferProducer.h>
#include <media/MediaEventLooper.h>
#include <list>

class EMMediaFormat;

class EMBeOutputNode : public BBufferProducer,  public BMediaEventLooper,
	public EMListenerRepository
{
public:
	// BMediaNode methods
			BMediaAddOn* 	AddOn(int32* id) const;

	// BBufferProducer methods
			status_t 		FormatSuggestionRequested(media_type,
								int32 quality, media_format*);

			status_t 		FormatProposal(const media_source&,
								media_format*);

	/* If the format isn't good, put a good format into *io_format and return error */
	/* If format has wildcard, specialize to what you can do (and change). */
	/* If you can change the format, return OK. */
	/* The request comes from your destination sychronously, so you cannot ask it */
	/* whether it likes it -- you should assume it will since it asked. */
			status_t 		FormatChangeRequested(const media_source&,
								const media_destination&, media_format*,
								int32*);

			status_t 		GetNextOutput(int32* cookie, media_output*);
			status_t 		DisposeOutputCookie(int32);
			status_t 		SetBufferGroup(const media_source&, BBufferGroup*);

	/* Iterates over all outputs and maxes the latency found */
			status_t 		GetLatency(bigtime_t*);

			status_t 		PrepareToConnect(const media_source&,
								const media_destination&, media_format*,
								media_source*, char* name);

			void 			Connect(status_t, const media_source&,
								const media_destination&, const media_format&,
								char* io_name);

			void 			Disconnect(const media_source&,
								const media_destination&);

			void 			LateNoticeReceived(const media_source&,
								bigtime_t lateBy, bigtime_t performanceTime);

			void 			EnableOutput(const media_source&, bool, int32*);
							// last parameter is deprecated

			status_t 		SetPlayRate(int32 numer, int32 denom);

			status_t 		HandleMessage(int32, const void*, size_t);

			void 			AdditionalBufferRequested(const media_source&,
								media_buffer_id, bigtime_t,
								const media_seek_tag* = NULL);

			void 			LatencyChanged(const media_source&,
								const media_destination&, bigtime_t,
								uint32 flags);


// BMediaEventLooper methods

			void 			NodeRegistered();

			status_t 		AddTimer(bigtime_t, int32);

			void 			SetRunMode(run_mode);

			void 			HandleEvent(const media_timed_event*,
								bigtime_t lateness, bool realTime = false);

			void 			Start(bigtime_t performance_time);

			void 			Stop(bigtime_t performance_time, bool immediate);

			media_format 	GetConnectedFormat();
			EMMediaFormat* 	GetConnectedEMMediaFormat();

			bool 			CheckOutputFormat(media_format*) { return true; };

			void 			SetClockMaster(bool p_vFlag);
			bool 			IsClockMaster() const;
			bool 			IsRunning() const;

	virtual bool 			Initialize();

	virtual void 			InitializePreferredFormat(media_format*) = 0;
	virtual status_t 		CheckFinalFormat(media_format*) = 0;
	virtual int64 			GetBufferDuration() const = 0;

	virtual bool			Shutdown();

protected:
							EMBeOutputNode(media_type);
	virtual 				~EMBeOutputNode();
			status_t		DeleteHook(BMediaNode* node);

	// shared member variables
			media_output 	m_sOutput;
			EMMediaFormat* 	m_opConnectedEMMediaFormat;
			int64 			m_vNumberOfReceivedFrames;

private:
			media_format 	m_sPreferredOutputFormat;

			bigtime_t 		mLatency,
							mInternalLatency;

			media_output 	mOutput;
			bool 			mOutputEnabled;
			bool 			m_vIsClockMaster;

	unsigned short			vCount;

			bigtime_t 		m_vStartingTime;
			BBuffer* 		m_opBuffer;
			EMMediaFormat* 	m_opSystemAudioFormat;
};

#endif
