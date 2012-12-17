/*******************************************************
* Creator: Martin Rudefelt
* Portability: native
*-------------------------------------------------------
*
*******************************************************/

#include "EMGlobals.h"

#ifndef __EM_BE_WINDOW
#define __EM_BE_WINDOW

#include <Window.h>

class EMBeWindowContainer;
class EMListener;

class BMessage;

class EMBeWindow : public BWindow
{
public:
							EMBeWindow(EMBeWindowContainer*, BRect,
								 const char*, window_type, uint32 flags);

							EMBeWindow(EMBeWindowContainer*, BRect,
								const char*, window_look, window_feel,
								uint32 flags);

							~EMBeWindow();

			void			MessageReceived(BMessage*);

			bool			QuitRequested();

private:
			EMBeWindowContainer* m_opContainer;
};

#endif

