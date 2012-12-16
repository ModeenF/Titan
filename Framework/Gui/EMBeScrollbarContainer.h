/*******************************************************
* Creator: Martin Rudefelt
* Portability: native
*-------------------------------------------------------
* The BScrollbar seems to draw outside its bounds and
* this class corrects that error
*******************************************************/

#include "EMGlobals.h"

#ifndef __EM_BE_SCROLLBAR_CONTAINER
#define __EM_BE_SCROLLBAR_CONTAINER

#include "EMBeScrollbar.h"
#include "EMGUIGlobals.h"
#include "EMRect.h"
#include "EMScrollbar.h"

class EMBeScrollbarContainer : public EMScrollbar
{
public:
							EMBeScrollbarContainer(EMRect, float min,
									float max, EMOrientation);

							~EMBeScrollbarContainer();

	virtual EMRect 			Frame() const;
	virtual void* 			GetNativeView() const;

			void 			Hide();
			void 			Show();

			void			GetRange(int32& min, int32& max);
			void 			GetSteps(int32& small, int32& big);
			int32			GetValue();

			EMOrientation 	Orientation();
			void 			SetFrame(EMRect);
			void			SetProportion(float);
			void			SetRange(float min, float max);
			void			SetSteps(int32 small, int32 big);
			void			SetValue(int32);

			void			SetPageAndRange(uint32, uint32, uint32);


			bool			IsEnabled();
			void			Enable(bool);

private:
			EMBeScrollbar* 	fScrollbar;
};

#endif
