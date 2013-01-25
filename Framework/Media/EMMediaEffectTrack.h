/*******************************************************
* Creator: Richard Kronfalt
* Portability: Non-Native
*-------------------------------------------------------
*
* This class is the "effect track", that holds a number
* of effects (i e plugins) that are connected in a chain.
* It has an output (e g Layla24 Analog Out 1/2) and a
* start plugin in the chain. As plugins are added to the
* track, the destinations of the respective plugins
* (the plugins inherit from EMBufferDestination, so they
* have a destination) need to be updated to keep the
* chain valid.
*
*******************************************************/

#ifndef __EM_MEDIA_EFFECT_TRACK
#define __EM_MEDIA_EFFECT_TRACK

#include "EMBufferDestination.h"
#include "EMMediaGlobals.h"
#include "EMMediaItemContainer.h"
#include "EMMediaDataBuffer.h"

class EMBufferDestination;
class EMMediaTrack;
class EMPlugin;
class EMSemaphore;

class EMMediaEffectTrack : public EMBufferDestination
{
public:
							EMMediaEffectTrack(EMMediaType);
							EMMediaEffectTrack(EMMediaEffectTrack&);

							~EMMediaEffectTrack();

			string 			GetName() const;
			bool 			InitCheckE();
			bool 			PrepareToPlayE();

			EMMediaDataBuffer* ProcessBufferE(list<EMMediaDataBuffer*>*);
			EMMediaDataBuffer* ProcessBufferE(BObjectList<EMMediaDataBuffer>*);

			void 			SetName(string p_oName);

	//Processing management
			bool 			SetOutput(EMBufferDestination* p_opOutput);
			EMBufferDestination* GetOutput() const;

	//Slot management
			bool 			InsertEffect(EMPlugin*, uint32 slotNumber);
			bool 			SetEffect(EMPlugin*, uint32 slotNumber);

			bool 			DeleteEffect(uint32 slotNumber);
			bool 			IsSlotEmpty(uint32 slotNumber);

			uint32 			GetNumberOfSlots() const;
			int32 			GetLastEffect();
			uint32 			CountEffects();
			void 			DisplaySlots();

			EMPlugin* 		FindEffect(int32 id);

			EMPlugin* 		GetSlot(uint32 index);
			int32 			GetSlotFor(EMPlugin*);

			bool 			SaveData(EMProjectDataSaver* p_opSaver);
			bool 			LoadData(EMProjectDataLoader* p_opLoader);

			bool 			RestoreAfterLoad();

			bool 			IsObjectDeleted();
			void 			SetDeleted(bool p_vState);

private:
			bool 			MakeRoom(uint32 p_vSlotNumber);
			EMBufferDestination* GetNextDestination(uint32 currentSlot);
			EMBufferDestination* GetPreviousDestination(uint32 currentSlot);

			string 			m_oName;
			EMPlugin** 		m_opSlots;
			uint32 			m_vNumSlots;
			EMBufferDestination* m_opOutput;
			EMMediaTrack* 	m_opSourceMediaTrack;
			EMSemaphore* 	m_opSemaphore;
			int32 			m_vOutputId;
			bool 			m_vIsDeleted;
};

#endif

