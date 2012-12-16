/*******************************************************
* Creator: Martin Rudefelt
* Portability: native
*-------------------------------------------------------
*
*******************************************************/

#include "EMGlobals.h"

#ifndef __EM_BE_WINDOW_CONTAINER
#define __EM_BE_WINDOW_CONTAINER

#include "EMGUIGlobals.h"
#include "EMRect.h"
#include "EMWindow.h"

class EMBeWindow;
class EMListener;
class EMView;

class EMBeWindowContainer : public EMWindow
{
public:
							EMBeWindowContainer(EMRect, const char* name,
									EMWindowType);
	virtual 				~EMBeWindowContainer();

			void			ConvertFromWorkAreaToWindow(EMRect &);

			void 			AddChild(EMGUIComponent*);

			EMRect 			Bounds() const;
			EMRect 			Frame() const;
			void* 			GetNativeView() const;

			void 			Hide();
			void 			Show();
			bool 			IsHidden();

			bool 			Lock();
			void 			Unlock();

			bool			IsMaximized();
			void			SetMaximized(bool);

			void			MoveTo(int32, int32);
			void			SetCurrentFocus();

			void 			SetBounds(EMRect);
			void 			SetFrame(EMRect);
			void 			SetFrame(EMRect, bool);

			void 			SetSizeLimits(int32 minW, int32 maxW, int32 minH,
									int32 maxH);

			void 			SetTitle(const char*);

private:
			EMBeWindow* 	m_opWindow;
};

#endif
