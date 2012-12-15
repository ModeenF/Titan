/*******************************************************
* Creator: Martin Rudefelt
* Component: none
* Portability: native
*-------------------------------------------------------
*
*******************************************************/

#include "EMGlobals.h"

#ifdef PLATFORM_BEOS

#ifndef __EM_BE_FILE_PANEL_CONTAINER
#define __EM_BE_FILE_PANEL_CONTAINER

#include "EMFileWindow.h"
#include "EMListenerRepository.h"

#include <FilePanel.h>
#include <Looper.h>
#include <string>
#include <vector>

class EMBeFilePanelContainer : public EMFileWindow, public BLooper, public BRefFilter
{
public:
							EMBeFilePanelContainer(EMFilePanelMode,
								const char* title, bool multiSelect,
								const char* saveDefaultText,
								vector<string>* visibleExtensions = NULL,
								const char* startDirectory = NULL,
								uint32 message = 0);
							~EMBeFilePanelContainer();

			EMRect 			Frame() const;
			void			SetFrame(EMRect);

			void* 			GetNativeView() const;
			vector<string>* GetPaths();
			bool 			Filter(const entry_ref*, BNode*, struct stat*,
								const char* type);
			bool 			IsHidden();
			void 			Hide();
			void 			Show();

			void 			MessageReceived(BMessage*);

			bool			Filter(const entry_ref*, BNode*, stat_beos*,
								const char*);
private:
			vector<string> 	m_oFilenames;
			BFilePanel* 	m_opPanel;
			vector<string>* m_opVisibleExtensions;
};

#endif

#endif
