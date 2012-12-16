/*******************************************************
* Creator: Martin Rudefelt
* Portability: native
*-------------------------------------------------------
*
*******************************************************/

#include "EMGlobals.h"

#ifndef __EM_BE_SCROLLBAR
#define __EM_BE_SCROLLBAR

#include <Rect.h>
#include <ScrollBar.h>

class EMBeScrollbarContainer;
class EMListener;

class EMBeScrollbar : public BScrollBar
{
public:
							EMBeScrollbar(EMBeScrollbarContainer*,
									BRect, float min, float max,
									orientation);

			void 			Draw(BRect);

			void 			MouseDown(BPoint);

			void			ValueChanged(float);

private:
	EMBeScrollbarContainer* m_opContainer;
};

#endif

