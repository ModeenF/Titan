/*******************************************************
* Creator: Richard Kronfalt
* Portability: Native
*-------------------------------------------------------
*
* This class is a repository of all the clips that exist
* within a song/project. To find out which track a clip
* belongs to one has to ask the clip, since it has a
* pointer to the owning EMMediaTrack.
*
* This class supplies a way of accessing the data in
* the clips, through the GetNextBuffers method.
* It returns a number of EMMediaDataBuffers (through adding
* them to a list which is sent in). The buffers returned
* correspond to the media data that should be played
* at a certain point in songtime, namely the time given
* by EMBeMediaTimer's method ThenFrame and/or ThenTime.
* See EMBeMediaTimer for information about the concepts
* of Now-time and Then-time.
* The buffers returned are read from all the clips active
* at that time.
*
* When asking GetNextBuffers for the next set of buffers
* one has to supply a filtering-flag, for deciding which
* clip-types to read buffers from, e.g. EM_TYPE_RAW_VIDEO,
* EM_TYPE_ANY, EM_TYPE_ANY_AUDIO, etc.
*
* If there are no active clips at "this" point in songtime
* (as reported by ThenTime - see above), the method
* just returns the sent in list unchanged, i.e., naturally,
* without adding any EMMediaDataBuffers to it.
*
* This class also contains methods for investigating the
* "song" as a whole, e.g. HasAudio and HasVideo returns
* true if there are any audio or video clips respectively
* in the song/project.
*
* FramesToNextClip returns the number of audio frames
* (calculated using the global audio format) to the start
* of the next clip, from a certain point in time.
*
* TODO: Make sure that FramesToNextClip only includes
* audio clips or video clips in the search, when needed.
*
* Richard Kronfält, 00-11-28
*******************************************************/

#ifndef __EM_MEDIA_CLIP_REPOSITORY
#define __EM_MEDIA_CLIP_REPOSITORY

#include "EMMediaGlobals.h"
#include "EMMediaClip.h"
#include "EMMediaItemContainer.h"
#include "EMMediaDataBuffer.h"

#include <list>
#include <ObjectList.h>

class EMMediaTrack;
class EMProjectDataLoader;
class EMProjectDataSaver;

class EMMediaClipRepository : public EMMediaItemContainer<EMMediaClip>
{
public:
	virtual 				~EMMediaClipRepository();
			int64			CountClipsForTrack(const EMMediaTrack*,
								EMMediaType = EM_TYPE_ANY);

			int64			CountActiveClips();

			int32 			GetID() const;

	// TODO:  use PROPER overriding of new...
	static					EMMediaClipRepository* New(EMMediaType);

	virtual	void 			GetNextBuffers(BObjectList<EMMediaDataBuffer>*,
								EMMediaType, int64 timeNow,
								bool seeking = false) = 0;

	virtual bool			InitCheckE() = 0;

			void 			OnItemAdd();
			void 			OnItemRemove();

			bool 			ClearData();
			bool 			SaveData(EMProjectDataSaver*);
			bool 			LoadData(EMProjectDataLoader*);

	virtual bool 			GetClipsInTimeslot(list<EMMediaClip*>*, int64 time)
								{return false;};

protected:
							EMMediaClipRepository(EMMediaType);

private:
			int32			m_vID;
};

#endif

